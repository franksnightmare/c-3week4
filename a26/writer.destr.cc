#include "main.ih"

Writer::~Writer()
{
	struct stat stats;
	stat(d_path.c_str(), &stats);
	fchmod(d_tempFD, stats.st_mode);
	remove(d_path.c_str());
	rename(d_tempPath.c_str(), d_path.c_str());
	close(d_tempFD);
	close(d_gslFD);
}
