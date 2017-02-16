#include "main.ih"

void Writer::grab(string const &str, size_t index)
{
	string output("grabbed(");
	output += '0' + index;
	output += ", \"";
	output += d_gslPath;
	output += "\")";
	writeCode(output);
}
