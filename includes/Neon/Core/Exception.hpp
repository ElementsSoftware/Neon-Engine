#pragma once

#ifndef ZEXCEPTION_HPP
#define ZEXCEPTION_HPP

#include <iostream>

#include <Neon/Utils.hpp>
#include <Neon/Core/String.hpp>

namespace Ne
{
	class NEON_API Exception : public std::exception
	{
	public : 
		Exception(const String& message = "");

		virtual ~Exception() noexcept = default;

	protected :
		String m_message;
	};

	struct ZAssertException : public Exception
	{
		ZAssertException(const String& file, int line, const String& message);
	};

	struct ZOperationFailed : public Exception
	{
		ZOperationFailed(const String& file, const String& message);
	};

	struct WindowException : public Exception
	{
		WindowException(const String& windowName, const String& message);
	};
}

#endif //ZEXCEPTION_HPP