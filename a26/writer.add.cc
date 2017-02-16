#include "main.ih"

void Writer::add(string const &str)
{
	auto location = find(d_literals.begin(), d_literals.end(), str);
	
	size_t index;
	if (location != d_literals.end())
	{
		index = location - d_literals.begin();
		transform(str, index);
	}
	else
	{
		d_literals.push_back(str);
		string temp = str + '\n';
		write(d_gslFD, temp.c_str(), sizeof(char) * temp.size());
		index = d_literals.size();
		transform(str, index);
	}
}
