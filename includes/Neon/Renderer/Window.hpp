#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

#include <Neon/Renderer/Module.hpp>
#include <Neon/Core/String.hpp>
#include <GLFW/glfw3.h>

namespace Ne
{
	class NEON_API Window : public Module
	{
	public :

		Window() = default;
		Window(int width, int height, const String& title);

		~Window();

		bool Create(int width, int height, const String& title);

	private:
		bool CreateSurface();
	
	private:
		int m_width;
		int m_height;
		String m_title;

		GLFWwindow * m_window;
		VkSurfaceKHR m_surface;
	};
}

#endif