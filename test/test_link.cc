
#include <cccc.h>
#include <catch.hpp>

namespace cccc
{
TEST_CASE("Link", "[dag]") {
    SECTION("Constructor")
    {
        Pin* a = new Pin();
        Pin* b = new Pin();
        Link* l = new Link(a,b);
    }
}
}
