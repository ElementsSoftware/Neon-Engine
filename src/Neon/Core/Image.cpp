#include <Neon/Core/String.hpp>
#include <Neon/Core/File.hpp>
#include <Neon/Core/Image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Ne
{
	/*
	@brief : Takes differents data about image (texture)
	@param : The file name of the image
	@param : A pointer to the image width
	@param : A pointer to the image height
	@param : A pointer to 
	*/
	std::vector<char> Image::GetImageData(const String& fileName, uint32_t *width, uint32_t *height, uint32_t *components, int *dataSize, int requestComponents)
	{
		File file(fileName);
		std::vector<char> data = file.GetBinaryFileContent();
		
		if (data.size() == 0)
			return std::vector<char>();

		int bufferWidth = 0, bufferHeight = 0, bufferComponents = 0;
		unsigned char* imageData = stbi_load_from_memory(reinterpret_cast<unsigned char*>(&data[0]), static_cast<int>(data.size()), &bufferWidth, &bufferHeight, &bufferComponents, requestComponents);
	
		if ((imageData == nullptr) || (bufferWidth <= 0) || (bufferHeight <= 0) || (bufferComponents <= 0))
		{
			std::cout << "Failed to load image data from memory" << std::endl;
			return std::vector<char>();
		}

		int size = (bufferWidth) * (bufferHeight) * (requestComponents <= 0 ? bufferComponents : requestComponents);

		if (dataSize)
			*dataSize = size;
		if (width)
			*width = bufferWidth;
		if (height)
			*height = bufferHeight;
		if (components)
			*components = bufferComponents;

		std::vector<char> fileData(size);
		std::memcpy(&fileData[0], imageData, size);

		stbi_image_free(imageData);

		return fileData;
	}
}