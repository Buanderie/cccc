
#include <cccc.h>
#include <catch.hpp>

namespace cccc
{
TEST_CASE("Link", "[dag]") {
    SECTION("Constructor")
    {
        Pin* a = new Pin();
        Pin* b = new Pin();
        Link* l = new Link(a,b, 1024 );
    }

    SECTION("read")
    {
        Pin* a = new Pin();
        Pin* b = new Pin();
        Link* l = new Link(a,b,1024);
        Packet p1, p2;
        bool ret1 = l->write(p1);
        bool ret2 = l->read(p2);
        bool retfinal = ret1 && ret2;
        REQUIRE( ret2 == true );
    }

    SECTION("write")
    {
        Pin* a = new Pin();
        Pin* b = new Pin();
        Link* l = new Link(a,b,1024);
        Packet p1, p2;
        bool ret1 = l->write(p1);
        bool ret2 = l->read(p2);
        bool retfinal = ret1 && ret2;
        REQUIRE( ret1 == true );
    }
}
}
