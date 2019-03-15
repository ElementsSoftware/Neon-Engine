#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <Neon/Renderer/Module.hpp>
#include <Neon/Renderer/ModuleManager.hpp>

namespace Ne
{
	class NEON_API Renderer : public Module
	{
	public:
		Renderer();
		~Renderer();

		static Renderer * GetInstance() { return ModuleManager::GetInstance().Get<Renderer>(); }

		VkInstance& GetVulkanInstance() { return m_instance; }

	private:
		bool Initialize();

	private:
		VkInstance m_instance;
	};
}

#endif