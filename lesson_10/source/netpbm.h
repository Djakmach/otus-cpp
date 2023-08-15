#pragma once

#include <ostream>

namespace graphics {

	void write_header(
		std::ostream &output,
		unsigned int width,
		unsigned height
	);

	void write_pixel(
		std::ostream &output,
		unsigned char red,
		unsigned char green,
		unsigned char blue
	);

	void dump_to_file(std::ostream& file, char *image, int width, int height);

	void clear(char *image, int width, int height);

	void put_pixel(char *image, int width, int height, int green, int x, int y);











	struct Image {
		char* buffer;
		int width;
		int height;
	};

	void dump_to_file(std::ostream& file, Image& image);

	void clear(Image& image);

	void put_pixel(Image& image, int green, int x, int y);



} // namespace graphics
