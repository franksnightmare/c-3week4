#include "main.ih"

Writer::Writer(string const &path)
{
	string tempPath = path + ".tmp";
	if ((d_targetFD = open(tempPath)) < 0)
		cerr << "Couldn't open file " << tempPath << '\n';
	
	string gslPath(path.substr(0, path.find_last_of('.')));
	gslPath += "gsl";
	
	if ((d_gslFD = open(gslPath)) < 0)
		cerr << "Couldn't open file " << gslPath << '\n';
}
