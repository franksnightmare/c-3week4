#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <algorithm>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>

#include "Scanner.h"

std::string dequote(std::string const &str);

char getRawChar(char rawChar);
void makeRaw(std::string &str);

class Writer
{
	std::vector<std::string> d_literals;
	
	std::string d_path;
	std::string d_tempPath;
	std::string d_gslPath; 
	
	int d_tempFD;
	int d_gslFD;
	
	public:
		Writer(std::string const &path);
		~Writer();
		
		void addString(std::string const &str);
		void writeCode(std::string const &str);
	
	private:
		void grab(std::string const &str,
			std::size_t index);
};

#endif
