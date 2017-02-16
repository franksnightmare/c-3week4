#include "main.ih"

Writer::Writer(string const &path)
:
	d_path(path),
	d_tempPath(path)
{
	d_tempPath += ".tmp";
	{
		size_t idx = path.find_last_of('.');
		if (idx == string::npos)
			d_gslPath = path + ".gsl";
		else
			d_gslPath = path.substr(0, path.find_last_of('.')) + ".gsl";
	}
	
	if ((d_tempFD = open(d_tempPath.c_str(), O_CREAT | O_WRONLY)) < 0)
		cerr << "Couldn't open file " << d_tempPath << '\n';
	
	if ((d_gslFD = open(d_gslPath.c_str(), O_CREAT | O_WRONLY)) < 0)
		cerr << "Couldn't open file " << d_gslPath << '\n';
}
