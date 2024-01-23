#include "file_util.h"
#include <fstream>
#include <sstream>

std::string read_file(const std::string& path) {
	std::stringstream ss;
	std::ifstream file(path);
	ss << file.rdbuf();
	file.close();
	return ss.str();
}
