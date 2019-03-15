#include <vector>
#include <map>
#include <iostream>

#include <Neon/Renderer/Device.hpp>
#include <Neon/Renderer/Renderer.hpp>

namespace Ne
{
	Device::Device()
	{
		FindPhysicalDevice();
	}

	//-----------------Private methods-------------------

	void Device::FindPhysicalDevice()
	{
		uint32_t physicalDeviceCount;
		vezEnumeratePhysicalDevices(ModuleManager::GetInstance().Get<Renderer>()->GetVulkanInstance(), &physicalDeviceCount, nullptr);
		
		std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
		vezEnumeratePhysicalDevices(ModuleManager::GetInstance().Get<Renderer>()->GetVulkanInstance(), &physicalDeviceCount, physicalDevices.data());
		
		std::map<int, VkPhysicalDevice> mapDevice;

		for (auto physicalDevice : physicalDevices)
		{
			int score = 0;

			VkPhysicalDeviceProperties properties;
			vezGetPhysicalDeviceProperties(physicalDevice, &properties);
		
			VkPhysicalDeviceFeatures features;
			vezGetPhysicalDeviceFeatures(physicalDevice, &features);

			// Dedicated GPU
			if (properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
				score += 1000;

			// La taille maximale possibles des textures affecte la qualité graphique
			score += properties.limits.maxImageDimension2D;

			if (features.geometryShader == 0)
				score = 0;

			mapDevice.emplace(score, physicalDevice);
		}

		if (mapDevice.rbegin()->first > 0)
			m_physicalDevice = mapDevice.rbegin()->second;
		else
			std::cout << "Failed to found a suitable GPU" << std::endl;
	}
}
