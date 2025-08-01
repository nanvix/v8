// src/base/debug/stack_trace_nanvix.cc
#include "src/base/debug/stack_trace.h"
#include <cstdio>

namespace v8 {
namespace base {
namespace debug {

// Dummy implementation
bool EnableInProcessStackDumping() {
  return true;
}

// Dummy implementation
void DisableSignalStackDump() {}

// Dummy implementation
StackTrace::StackTrace() {
  count_ = 0;
}

// Dummy implementation
void StackTrace::Print() const {
  fprintf(stdout, "Stack trace not available on Nanvix\n");
}

}  // namespace debug
}  // namespace base
}  // namespace v8