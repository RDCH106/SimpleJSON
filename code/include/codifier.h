#pragma once

#include <string>

namespace simplejson
{
	class Codifier
	{
	public:
		// Functions
		/**
		 * \brief Description
		 * \description long description
		 * \param[in] value
		 * \return value
		 */

		// codify
		static std::string toSHA1(std::string data);
		static std::string toBase64(unsigned char const* , unsigned int len);

		// Uncodify
		// SHA1 is not possible :-D
    static std::string fromBase64(std::string const& s);

    static void base64_test();
	};
}
