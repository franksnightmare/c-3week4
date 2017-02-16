#include "main.ih"

string dequote(string const &str)
{
	size_t start = str.find('\"') + 1;
	return str.substr(start, str.length() - (start + 1));
}
