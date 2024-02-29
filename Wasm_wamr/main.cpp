#include "sources/scgms.h"
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
    sleep(1);
    create_level_event(12);
    create_level_event(13);
    create_level_event(15);
}