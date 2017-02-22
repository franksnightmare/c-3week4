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

void makeRaw(std::string &str);
char escapeChar(char rawChar);
bool isEscape(char rawChar);
void deEscape(std::string &str);

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

bool checkDelimeter(std::string const &delim,
	std::string const &str);
void processString(std::string &str, Writer &writer,
	void (*func)(std::string &) = [](std::string &){});

#endif
