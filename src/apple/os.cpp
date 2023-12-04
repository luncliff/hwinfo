// Copyright (c) Leon Freist <freist@informatik.uni-freiburg.de>
// This software is part of HWBenchmark

#include "hwinfo/platform.h"

#ifdef HWINFO_APPLE

#include <sys/sysctl.h>
#include <sys/utsname.h>

#include <sstream>
#include <string>

#include "hwinfo/os.h"

namespace hwinfo {

// _____________________________________________________________________________________________________________________
OS::OS() {}

// _____________________________________________________________________________________________________________________
std::string OS::name() const {
  size_t size = 1024;
  std::string os_name;
  os_name.resize(size);
  if (sysctlbyname("kern.os", (void*)(os_name.data()), &size, nullptr, 0) == 0) {
    os_name.resize(size);  // trim the string to the actual size
    return os_name;
  }
  return "macOS <unknown version>";
}

// _____________________________________________________________________________________________________________________
std::string OS::version() const {
  size_t size = 1024;
  std::string os_version;
  os_version.resize(size);
  if (sysctlbyname("kern.osrelease", (void*)(os_version.data()), &size, nullptr, 0) == 0) {
    os_version.resize(size);  // trim the string to the actual size
    return os_version;
  }
  return "<unknown version>";
}

// _____________________________________________________________________________________________________________________
std::string OS::kernel() const {
  // TODO: implement
  utsname uts{};
  if (uname(&uts) != 0) return "<unknown>";  // check errno
  size_t len = strnlen(uts.release, 256);
  return {uts.release, len};
}

// _____________________________________________________________________________________________________________________
bool OS::is64bit() const { return true; }
bool OS::is32bit() const { return !is64bit(); }

bool OS::isBigEndian() const { return false; }
bool OS::isLittleEndian() const { return false; }

}  // namespace hwinfo

#endif  // HWINFO_APPLE
