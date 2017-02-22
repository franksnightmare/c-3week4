#include "main.ih"

void processString(string &str, Writer &writer,
	void (*func)(std::string &))
{
	string temp(dequote(str));
	func(temp);
	deEscape(temp);
	writer.addString(temp);
	str = string{};
}
