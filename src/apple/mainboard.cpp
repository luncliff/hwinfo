// Copyright (c) Leon Freist <freist@informatik.uni-freiburg.de>
// This software is part of HWBenchmark

#include "hwinfo/platform.h"

#ifdef HWINFO_APPLE

#include "hwinfo/mainboard.h"

namespace hwinfo {

// _____________________________________________________________________________________________________________________
MainBoard::MainBoard() {}

// _____________________________________________________________________________________________________________________
std::string MainBoard::vendor() const {
  // TODO: implement
  return "<unknown>";
}

// _____________________________________________________________________________________________________________________
std::string MainBoard::name() const {
  // TODO: implement
  return "<unknown>";
}

// _____________________________________________________________________________________________________________________
std::string MainBoard::version() const {
  // TODO: implement
  return "<unknown>";
}

// _____________________________________________________________________________________________________________________
std::string MainBoard::serialNumber() const {
  // TODO: implement
  return "<unknown>";
}

}  // namespace hwinfo

#endif  // HWINFO_APPLE
