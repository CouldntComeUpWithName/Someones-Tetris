#pragma once

//Current Working Directory
extern const std::string CWD;

std::string get_cwd();

////////////////////////////////////////////////////////////////
// Returns an absolute path. 
//	Input Example: /folder/internal folder/..more../file.extension
//	or: \\folder\\internal folder\\..more..\\file.extension
////////////////////////////////////////////////////////////////
std::string get_absolute_path(const std::string& relative_path);


