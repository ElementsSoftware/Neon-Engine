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
	std::unique_ptr<ModuleManager> mm = std::make_unique<ModuleManager>();
	std::unique_ptr<Window> window = std::make_unique<Window>();

	mm->Add(ModuleList::WINDOW, window.get());

	mm->GetModule(ModuleList::WINDOW)->Update();

	system("PAUSE");

	return 0;
}
