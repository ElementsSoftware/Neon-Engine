#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

#include <Neon/Renderer/Module.hpp>

namespace Ne
{
	class Window : public Module
	{
	public :
		void Create()
		{
			std::cout << "Create" << std::endl;
		}

		void Update() override
		{
			std::cout << "Update" << std::endl;
		}
	};
}

#endif