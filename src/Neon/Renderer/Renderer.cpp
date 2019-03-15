#include <iostream>
#include <vector>

#include <Neon/Renderer/Renderer.hpp>

namespace Ne
{
	Renderer::Renderer()
	{
		if (!Initialize())
			std::cout << "Failed to initialize vulkan" << std::endl;
	}

	Renderer::~Renderer()
	{
		vezDestroyInstance(m_instance);
	}

	bool Renderer::Initialize()
	{
		VezApplicationInfo appInfo = {};
		appInfo.pApplicationName = "Neon Engine";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "Neon Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		
		std::vector<const char*> enabledLayers = { "VK_LAYER_LUNARG_standard_validation" };

		VezInstanceCreateInfo createInfo = {};
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledLayerCount = static_cast<uint32_t>(enabledLayers.size());
		createInfo.ppEnabledLayerNames = enabledLayers.data();
		
		if (vezCreateInstance(&createInfo, &m_instance) != VK_SUCCESS)
		{
			std::cout << "Failed to create vulkan instance" << std::endl;
			return false;
		}

		return true;
	}
}