#include "functions.h"

bool IsPathExist(const fs::path& p, fs::file_status s) {
	if (fs::status_known(s) ? fs::exists(s) : fs::exists(p))
		return true;

	return false;
}
