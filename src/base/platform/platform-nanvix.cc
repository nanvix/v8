// src/base/platform/platform-nanvix.cc
#include <pthread.h>
#include <unistd.h>

#include <cstdio>

#include "src/base/platform/platform-posix-time.h"
#include "src/base/platform/platform-posix.h"
#include "src/base/platform/platform.h"
#include "src/base/timezone-cache.h"

/* FIXME: Remove the following import once it is available from NewLib headers.
 */
extern "C" {
extern int pthread_getattr_np(pthread_t thread, pthread_attr_t* attr);
}

namespace v8 {
namespace base {

int GetCurrentThreadId() { return static_cast<int>(pthread_self()); }

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
  pthread_attr_t attr = {
      0,
  };
  int error = pthread_getattr_np(pthread_self(), &attr);
  if (!error) {
    void* base;
    size_t size;
    error = pthread_attr_getstack(&attr, &base, &size);
    CHECK(!error);
    pthread_attr_destroy(&attr);
    return reinterpret_cast<uint8_t*>(base) + size;
  }
  return nullptr;
}

}  // namespace base
}  // namespace v8
