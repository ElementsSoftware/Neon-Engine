#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <functional>
#include <iostream>
#include <optional>
#include <vector>

namespace Ne
{
	class String;

	class Image
	{
	public:
		static std::vector<char> GetImageData(const String& fileName, uint32_t* width, uint32_t *height, uint32_t *components, int *dataSize, int requestComponents);

	private:
	};
}

#endif //IMAGE_HPP