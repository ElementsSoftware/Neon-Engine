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
		ModuleManager();

	    void Add(ModuleList moduleName, Module* module);

		void Remove(ModuleList moduleName);

		bool Contains(ModuleList moduleName);

		inline static ModuleManager& GetInstance();

		template <typename T>
		inline T* Get() const;

	private:
		template <typename T>
		inline void Add(ModuleList moduleName);

	private:
		std::map<ModuleList, Module*> m_moduleManager;
	};
}

#include "ModuleManager.inl"

#endif