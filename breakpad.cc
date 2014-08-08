#include "third_party/lss/linux_syscall_support.h"
#include "client/linux/handler/exception_handler.h"
#include "breakpad.h"
static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                         void* context,
                         bool succeeded)
{
  printf("Dump path: %s\n", descriptor.path());
  return succeeded;
}


void dump(char * path)
{
  google_breakpad::MinidumpDescriptor descriptor(path);
  google_breakpad::ExceptionHandler eh(descriptor,
                                       NULL,
                                       dumpCallback,
                                       NULL,
                                       true,
                                       -1);

  return 0;
}
