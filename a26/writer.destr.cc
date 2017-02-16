#include "main.ih"

Writer::~Writer()
{
	struct stat stats;
	stat(d_path.c_str(), &stats);
	fchmod(d_tempFD, stats.st_mode);
	//remove(d_path);
	//rename(d_path, d_tempPath);
	close(d_tempFD);
	close(d_gslFD);
}
