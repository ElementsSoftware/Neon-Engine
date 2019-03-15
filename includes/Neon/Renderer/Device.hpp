#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <Neon/Renderer/Module.hpp>
#include <Neon/Renderer/ModuleManager.hpp>


namespace Ne
{
	class NEON_API Device : public Module
	{
	public:
		Device();

		static Device * GetInstance() { return ModuleManager::GetInstance().Get<Device>(); }

		VkDevice& GetDevice() const;
		VkPhysicalDevice& GetPhysicalDevice() const;
	
	private:
		void FindPhysicalDevice();

	private:
		VkDevice m_device;
		VkPhysicalDevice m_physicalDevice;
	};
}

#endif