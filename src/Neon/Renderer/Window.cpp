#include <Neon/Renderer/Window.hpp>
#include <Neon/Renderer/ModuleManager.hpp>
#include <Neon/Renderer/Renderer.hpp>

namespace Ne
{
	/*
	@brief : Creates a window
	@param : The width of the window
	@param : The height of the window
	@param : The title of the window
	*/
	Window::Window(int width, int height, const String& title) : m_width(width), m_height(height), m_title(title)
	{
		if (!Create(width, height, title))
		{
			std::cout << "Failed to create window" << std::endl;
		}
	}

	/*
	@brief : The destructor of the window
	*/
	Window::~Window()
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}

	/*
	@brief : Creates a window
	@param : The width of the window
	@param : The height of the window
	@param : The title of the window
	*/
	bool Window::Create(int width, int height, const String& title)
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		if ((m_window = glfwCreateWindow(width, height, title.GetPtr(), nullptr, nullptr)) == nullptr)
		{
			glfwTerminate();
			std::cout << "Failed to create window" << std::endl;
			return false;
		}

		return true;
	}

	/*
	@brief : Creates a window surface
	*/
	bool Window::CreateSurface()
	{
		if (!glfwVulkanSupported())
		{
			std::cout << "Vulkan it isn't support on this device" << std::endl;
			return false;
		}

		if (glfwCreateWindowSurface(ModuleManager::GetInstance().Get<Renderer>()->GetVulkanInstance(), m_window, nullptr, &m_surface) != VK_SUCCESS)
		{
			std::cout << "Failed to create window surface" << std::endl;
			return false;
		}

		return true;
	}
}