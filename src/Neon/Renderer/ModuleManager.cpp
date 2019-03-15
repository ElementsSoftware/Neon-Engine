#include <Neon/Renderer/ModuleManager.hpp>

#include <iostream>

namespace Ne
{
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
	@brief : Get a pointer to a module
	@param : The module name to get
	@return : A pointer to the module
	@note : If the module is not in the list this functions return nullptr
	*/
	Module* ModuleManager::GetModule(ModuleList name)
	{
		for (auto it = m_moduleManager.begin(); it != m_moduleManager.end(); it++)
			if (it->first == name)
				return (it->second);

		return nullptr;
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