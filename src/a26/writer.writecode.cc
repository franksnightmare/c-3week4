#include "main.ih"
#include <errno.h>

void Writer::writeCode(string const &str)
{
	write(d_tempFD, str.c_str(), sizeof(char) * str.size());
}
