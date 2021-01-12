#pragma once
#include <exception>
#include <string>

namespace myengine
{
	/// <summary>
	/// struct used to throw exception in case of errors
	/// </summary>
	struct Exception : public std::exception
	{
		/// <summary>
		/// struct construct
		/// </summary>
		/// <param name="message"></param>
		Exception(const std::string& message);
		/// <summary>
		/// struct deconstruct
		/// </summary>
		/// <returns></returns>
		virtual ~Exception() throw();
		/// <summary>
		/// function used to identify the issue
		/// </summary>
		/// <returns></returns>
		virtual const char* what() const throw();

	private:
		/// <summary>
		/// the error message
		/// </summary>
		std::string message;

	};

}