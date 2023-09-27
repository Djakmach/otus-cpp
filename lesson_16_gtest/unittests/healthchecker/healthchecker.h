#pragma once

#include "HTTPClient.h"
#include <stdexcept>
#include <iostream>

class Healthchecker {
  public:
    Healthchecker()
        : client_{} {
    }

    bool check(const std::string_view &host) {
        HTTPRequest request;
        request.method = "GET";
        request.path = "/";
        request.headers.emplace("Host", host);
        request.headers.emplace("Connection", "Close");

        try {
            client_.connect(host);
            HTTPResponse response = client_.request(request);
            return response.status_code / 100 == 2;
        } catch (...) {
            return false;
        }
    }

  private:
    HTTPClient client_;
};
