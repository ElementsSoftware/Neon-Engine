#ifndef MODULE_HPP
#define MODULE_HPP

#include <Neon/Utils.hpp>

namespace Ne
{
	enum ModuleList
	{
		WINDOW,
		RENDERER,
		LOGICAL,
		PHYSICAL
	};

	class NEON_API Module
	{
	public:
		Module() = default;
		virtual ~Module() = default;

		Module(const Module&) = delete;
		Module& operator=(const Module&) = delete;

		virtual void Update() = 0;
	};
}

#endif