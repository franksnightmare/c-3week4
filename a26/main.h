#ifndef MAIN_H
#define MAIN_H

#include "Scanner.h"
#include <vector>
#include <algorithm>

std::string dequote(std::string const &str);

char getRawChar(char rawChar);
void makeRaw(string &str);

class Writer
{
	std::vector<std::string> d_literals;
	int d_targetFD;
	int d_gslFD;
	
	public:
		Writer(std::string const &path);
		
		void add(std::string &str);
	private:
		void write(std::string &str, std::size_t index);
};

#endif
