#include "netpbm.h"

namespace graphics {

	void write_header(std::ostream &stream, unsigned int width, unsigned int height) {
		stream << "P3\n"; // P3 - colored RGB image
		stream << width << ' ' << height << '\n';
		stream << 255 << '\n';
	}

	void write_pixel(std::ostream &stream, unsigned char red, unsigned char green, unsigned char blue) {
		stream << static_cast<int>(red) << ' ' << static_cast<int>(green) << ' ' << static_cast<int>(blue) << '\n';
	}

	void dump_to_file(std::ostream& file, char *image, int width, int height) {
		write_header(file, width, height);
		for (int row = 0; row < height; ++row) {
			for (int col = 0; col < width; ++col) {
				int index = row * width + col;
				write_pixel(file, 128, image[index], 128);
			}
		}
	}

	void clear(char *image, int width, int height) {
		for (int row = 0; row < height; ++row) {
			for (int col = 0; col < width; ++col) {
				int index = row * width + col;
				image[index] = 0;
			}
		}
	}

	void put_pixel(char *image, int width, int height, int green, int x, int y) {
		int index = y * width + x;
		image[index] = green;
	}





	void dump_to_file(std::ostream& file, Image& image) {
		dump_to_file(file, image.buffer, image.width, image.height);
	}

	void clear(Image& image) {
		clear(image.buffer, image.width, image.height);
	}

	void put_pixel(Image& image, int green, int x, int y) {
		put_pixel(image.buffer, image.width, image.height, green, x, y);
	}


} // namespace graphics
