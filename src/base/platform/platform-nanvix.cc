// src/base/platform/platform-nanvix.cc
#include "src/base/platform/platform.h"
#include "src/base/platform/platform-posix.h"
#include "src/base/platform/platform-posix-time.h"
#include "src/base/timezone-cache.h"
#include <unistd.h>
#include <pthread.h>

namespace v8 {
namespace base {

int GetCurrentThreadId() {
  return static_cast<int>(pthread_self());
}

// Dummy implementation
void OS::AdjustSchedulingParams() {}

std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
  return std::vector<SharedLibraryAddress>();
}

// Dummy implementation
void OS::SignalCodeMovingGC() {}

TimezoneCache* OS::CreateTimezoneCache() {
  return new PosixDefaultTimezoneCache();
}

// Dummy implementation
Stack::StackSlot Stack::ObtainCurrentThreadStackStart() {
  void* stack_start = reinterpret_cast<uint8_t*>(0xefd00000);
  return stack_start;
}

}  // namespace base
}  // namespace v8