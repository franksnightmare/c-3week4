#include "main.ih"

bool checkDelimeter(string const &delim,
	string const &str)
{
	string temp(str.substr(
		str.find_last_of(')') + 1,
		str.length()));
	temp = temp.substr(0,
		str.find_last_of('"'));
	return temp == delim;
}
