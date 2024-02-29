#include "sources/scgms.h"
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
void push_event(int l)
{
    create_level_event(l);
}

int main()
{
    build_filter_chain(nullptr);
}