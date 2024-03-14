#include "smartcgms_sources/scgms.h"
#include "unistd.h"
#include "stdlib.h"

extern "C" {
   void __cxa_allocate_exception(void* ptr) {
      //abort();
   }

void __cxa_throw(void* ptr, void* type, void* destructor) {
  //abort();
}
}


int main()
{
    build_filter_chain(nullptr);
    for(int i = 15; i < 45; i++)
    {
        create_level_event(i);
        sleep(1);
    }
    create_shutdown_event();
}