#include "structures/inttostring.hpp"

std::string IntToString::IntToString ( int Number ) {
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}