#include "main.ih"

void Writer::add(string const &str)
{
	auto location = find(d_literals.begin(), d_literals.end(), str);
	size_t index;
	if (location != d_literals.end())
	{
		index = location - d_literals.begin();
		write(str, index);
	}
	else
	{
		d_literals.push_back(str);
		index = d_literals.size();
		write(str, index);
	}
}
