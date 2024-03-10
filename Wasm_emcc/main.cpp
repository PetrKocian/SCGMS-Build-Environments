#include "smartcgms_sources/scgms.h"
#include <emscripten.h>

extern "C" {
EMSCRIPTEN_KEEPALIVE
void push_event(int level)
{
    create_level_event(level);
}
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
const char* get_config()
{
    return get_config_data();
}
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
void build_chain(const char* conf)
{
    if(strcmp(conf,"") == 0)
    {
        build_filter_chain(nullptr);
    }
    else
    {
        build_filter_chain(conf);
    }
}
}

int main()
{
}