namespace Ne 
{
	inline ModuleManager& ModuleManager::GetInstance()
	{
		static ModuleManager instance;
		return instance;
	}

	//------------------------------------------------

	template <typename T>
	inline T* ModuleManager::Get() const
	{
		for (auto it = m_moduleManager.begin(); it != m_moduleManager.end(); it++)
		{
			T* ptr = dynamic_cast<T*>(it->second);

			if (ptr != nullptr)
				return ptr;
		}

		return nullptr;
	}

	//------------------------------------------------

	template <typename T>
	void ModuleManager::Add(ModuleList moduleName)
	{
		std::unique_ptr<T> m = std::make_unique<T>();

		Add(moduleName, m.get());
	}
}