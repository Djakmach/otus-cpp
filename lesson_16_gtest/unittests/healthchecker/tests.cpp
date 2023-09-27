#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <memory>

#include "HTTPClient.h"
#include "healthchecker_di.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Throw;

class MockHTTPClient : public HTTPClient {
  public:
    MOCK_METHOD(void, connect, (const std::string_view &), (override));
    MOCK_METHOD(HTTPResponse, request, (const HTTPRequest &), (override));
};

TEST(healthcheck, positive) {
    std::string_view host = "example.com";
    HTTPResponse response;
    response.status_code = 200;

    auto client = std::make_shared<MockHTTPClient>();
    EXPECT_CALL(*client, connect(host))
        .Times(1);

    EXPECT_CALL(*client, request(_))
        .Times(1)
        .WillOnce(Return(response));

    Healthchecker checker{client};
    ASSERT_TRUE(checker.check(host));
}


