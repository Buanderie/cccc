#pragma once

#include <cccc.h>

namespace cccc
{
    TEST(link, constructor) {
        Pin* a = new Pin();
        Pin* b = new Pin();
        Link* l = new Link(a,b);
    }
}
