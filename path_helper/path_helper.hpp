#pragma once

#include <string>
#define STRING(s) #s
#define XSTRING(s) STRING(s)
#ifdef LOCAL_PATH
#define SLOCAL_PATH XSTRING(LOCAL_PATH)
#endif // LOCAL_PATH

namespace path_helper
{

const static std::string prename{SLOCAL_PATH};

}
