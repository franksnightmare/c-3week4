#include "main.ih"

void Writer::transform(string const &str, size_t index)
{
	string output("grabbed(");
	output += index;
	output += ", ";
	output += d_tempPath;
	output += ")";
	write(d_tempFD, output.c_str(), sizeof(char) * output.size());
}
