#ifndef _FILEREADER_HPP_
#define _FILEREADER_HPP_

#include <string>

class FileReader{
public:
	virtual void readFile(std::string fileName) = 0;
};

#endif