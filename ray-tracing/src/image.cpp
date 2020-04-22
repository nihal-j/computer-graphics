#include "image.hpp"

Image::Image(const int width, const int height)
{
    this -> width = width;
    this -> height = height;
    red.resize(width, std::vector<unsigned char>(height, 0));
    blue.resize(width, std::vector<unsigned char>(height, 0));
    green.resize(width, std::vector<unsigned char>(height, 0));
}

int Image::set_pixel(int x, int y, unsigned char red, unsigned char blue, unsigned char green)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        this -> red[x][y] = red;
        this -> blue[x][y] = blue;
        this -> green[x][y] = green;
        return 0;
    }
    return -1;
}

void Image::to_file(std::string path)
{
    std::ofstream file(path, std::ios::out | std::ios::binary);

	int padSize = (4 - (width*3) % 4) % 4;
	int dataSize = width*height*3 + height*padSize;
	int headSize = 54;
	int totalSize = dataSize + headSize;
	int pixelsPerMeter = 1;

	// Form the header.
	char head[54] = 
    {
		'B', 'M', // Bitmap file.
		static_cast<char>(totalSize),
		static_cast<char>(totalSize >> 8),
		static_cast<char>(totalSize >> 16),
		static_cast<char>(totalSize >> 24),
		0, 0,
		0, 0,
		static_cast<char>(headSize), 0, 0, 0,
		40, 0, 0, 0,
		static_cast<char>(width),
		static_cast<char>(width >> 8),
		static_cast<char>(width >> 16),
		static_cast<char>(width >> 24),
		static_cast<char>(height),
		static_cast<char>(height >> 8),
		static_cast<char>(height >> 16),
		static_cast<char>(height >> 24),
		1, 0, // Number of color planes
		24, 0, // Bits per pixel
		0, 0, 0, 0, // Compression. We don't use any.
		static_cast<char>(dataSize),
		static_cast<char>(dataSize >> 8),
		static_cast<char>(dataSize >> 16), 
		static_cast<char>(dataSize >> 24),
		//1, 0, 0, 0, // X resolution (pixels per meter),
		//1, 0, 0, 0, // Y resolution (pixels per meter),
		static_cast<char>(pixelsPerMeter),			// X resolution (pixels per meter)
		static_cast<char>(pixelsPerMeter >> 8),
		static_cast<char>(pixelsPerMeter >> 16),
		static_cast<char>(pixelsPerMeter >> 24),
		static_cast<char>(pixelsPerMeter),			// Y resolution (pixels per meter)
		static_cast<char>(pixelsPerMeter >> 8),
		static_cast<char>(pixelsPerMeter >> 16),
		static_cast<char>(pixelsPerMeter >> 24),		
		0, 0, 0, 0, // Colours in colour table.
		0, 0, 0, 0 // Important colours.
	};

	file.write(head, sizeof(head));

	char pad[3] = {0,0,0};
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			char red = static_cast<char>(this -> red[x][y]);
			char green = static_cast<char>(this -> green[x][y]);
			char blue = static_cast<char>(this -> blue[x][y]);

			file.write(&blue, 1);
			file.write(&green, 1);
			file.write(&red, 1);
		}
		file.write(pad, padSize);
	}

	file.close();
}