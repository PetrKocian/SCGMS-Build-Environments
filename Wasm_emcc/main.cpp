#include "smartcgms_sources/scgms.h"
#include <emscripten.h>

extern "C" {
EMSCRIPTEN_KEEPALIVE
void push_event(int l)
{
    create_level_event(l);
}
}

extern "C" {
EMSCRIPTEN_KEEPALIVE
const char* get_config()
{
    return get_config_data();
}
}


char conf[10000];

extern "C" {
EMSCRIPTEN_KEEPALIVE
void build_chain(const char* s)
{
    if(strcmp(s,"") == 0)
    {
        build_filter_chain(nullptr);
    }
    else
    {
        std::memcpy(conf, s, 10000);
        build_filter_chain(conf);
    }
}
}

int main()
{
}