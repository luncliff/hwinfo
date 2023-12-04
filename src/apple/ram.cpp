// Copyright (c) Leon Freist <freist@informatik.uni-freiburg.de>
// This software is part of HWBenchmark

#include "hwinfo/platform.h"

#ifdef HWINFO_APPLE

#include <sys/sysctl.h>

#include <string>
#include <vector>

#include "hwinfo/ram.h"

namespace hwinfo {

// _____________________________________________________________________________________________________________________
Memory::Memory() {}

// _____________________________________________________________________________________________________________________
const std::vector<Memory::Module>& Memory::modules() const { return _modules; }

// _____________________________________________________________________________________________________________________
int64_t Memory::total_Bytes() const {
  int64_t memsize = 0;
  size_t size = sizeof(memsize);
  if (sysctlbyname("hw.memsize", &memsize, &size, nullptr, 0) == 0) {
    return memsize;
  }
  return -1;
}

int64_t Memory::free_Bytes() const { return -1; }

int64_t Memory::available_Bytes() const { return -1; }

}  // namespace hwinfo

#endif  // HWINFO_APPLE
