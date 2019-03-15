#include <iostream>

#include <Neon/Renderer/ModuleManager.hpp>
#include <Neon/Renderer/Window.hpp>
#include <Neon/Renderer/Renderer.hpp>
#include <Neon/Renderer/Device.hpp>

namespace Ne
{
	ModuleManager::ModuleManager()
	{
		Add<Window>(ModuleList::WINDOW);
		Add<Renderer>(ModuleList::RENDERER);
		Add<Device>(ModuleList::DEVICE);
	}

	/*
	  @brief : Add a module to the list of module
	  @param : The name of module
	  @param : A pointer to the module
	*/
	void ModuleManager::Add(ModuleList moduleName, Module* module)
	{
		if (Contains(moduleName))
			Remove(moduleName);
	
		m_moduleManager.emplace(moduleName, module);
	}

	/*
	  @brief : Remove a module from the list of module
	  @param : The name of module to remove
	*/
	void ModuleManager::Remove(ModuleList moduleName)
	{
		for (auto it = m_moduleManager.begin(); it != m_moduleManager.end(); it++)
			if (it->first == moduleName)
			{
				m_moduleManager.erase(it->first);
				break;
			}	
	}

	/*
	@brief : Checks if a module is contains in the list
	@param : The module name
	@return : Return true if the module is contains, false otherwise
	*/
	bool ModuleManager::Contains(ModuleList moduleName)
	{
		for (auto it = m_moduleManager.begin(); it != m_moduleManager.end(); it++)
		{		
			if (it->first == moduleName)
				return true;
		}

		return false;
	}
}