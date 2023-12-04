// Copyright Leon Freist
// Author Leon Freist <freist@informatik.uni-freiburg.de>

#include "hwinfo/platform.h"

#ifdef HWINFO_APPLE
#ifndef USE_OCL

#include <regex>
#include <string>
#include <vector>

#include "hwinfo/gpu.h"

namespace hwinfo {

std::vector<GPU> getAllGPUs(){
    return {};
}

}  // namespace hwinfo

#endif  // USE_OCL
#endif  // HWINFO_APPLE
