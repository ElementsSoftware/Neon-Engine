#ifndef MODULE_MANAGER_HPP
#define MODULE_MANAGER_HPP

#include <map>
#include <memory>

#include <Neon/Renderer/Module.hpp>

namespace Ne
{
	class NEON_API ModuleManager
	{
	public:
		ModuleManager() = default;

	    void Add(ModuleList moduleName, Module* module);
		void Remove(ModuleList moduleName);

		Module* GetModule(ModuleList moduleName);

		bool Contains(ModuleList moduleName);

	private:
		std::map<ModuleList, Module*> m_moduleManager;
	};
}

#endif