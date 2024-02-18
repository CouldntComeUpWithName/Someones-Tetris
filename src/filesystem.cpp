#include"pch.h"
#include "filesystem.h"

std::string get_cwd()
{
    std::string cwd; //current_working_directory
    char* temp_ptr;

#ifdef _WIN32 // if OS Windows
	temp_ptr = _getcwd(nullptr, SHRT_MAX);
#else// if Unix-like systems
    temp_ptr = getcwd(nullptr, SHRT_MAX);
#endif /*__WIN64__*/

    if (temp_ptr)
        cwd = temp_ptr;

#ifdef RELEASE_PRODUCT //
    std::size_t index = cwd.rfind("bin");

    if (index != cwd.length())
    {
        cwd.erase(index);
    }
#endif /*RELEASE_PRODUCT*/

    return cwd;

}

std::string get_absolute_path(const std::string& relative_path)
{
    return CWD + relative_path;
}


extern const std::string CWD = get_cwd();
