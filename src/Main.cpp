#include <iostream>
#include <memory>

#include <Neon/Utils.hpp>
#include <Neon/Renderer/ModuleManager.hpp>
#include <Neon/Renderer/Module.hpp>
#include <Neon/Renderer/Window.hpp>

// Pas très propre mais utile pour les tests
using namespace Ne;

int main(void)
{
	std::unique_ptr<Window> window = std::make_unique<Window>(500, 500, "Test");
	
	ModuleManager mm = ModuleManager::GetInstance();

	mm.Add(ModuleList::WINDOW, window.get());

	mm.Get<Window>()->Create(500, 500, "Test");

	system("PAUSE");

	return 0;
}
