#pragma once

#include <iostream>
#include <sstream>
#include <mutex>

/** Thread safe cout class
* Exemple of use:
*    xostream{} << "Hello world!" << std::endl;
*/

class xostream : public std::ostringstream
{
public:
	xostream() = default;

	~xostream()
	{
		std::lock_guard<std::mutex> guard(__xcout);
		std::cout << this->str();
	}

private:
	static std::mutex __xcout;
};

#define xcout xostream{}