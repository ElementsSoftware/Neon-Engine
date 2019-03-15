#ifndef MODULE_HPP
#define MODULE_HPP

#include <Neon/Utils.hpp>
#include <VEZ.h>

namespace Ne
{
	enum ModuleList
	{
		WINDOW,
		RENDERER,
		DEVICE
	};

	class NEON_API Module
	{
	public:
		Module() = default;
		virtual ~Module() = default;

		Module(const Module&) = delete;
		Module& operator=(const Module&) = delete;
	};
}

#endif