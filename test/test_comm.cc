
#include <cccc.h>
#include <catch.hpp>

class DummyNode : public cccc::Node
{

};

namespace cccc
{
TEST_CASE("Communication", "[core][comm]") {

    SECTION("nyan")
    {
        Pin* a = new Pin();
        Pin* b = new Pin();
        Link* l = new Link(a,b,1024);
        cccc::objects::Number* n = new cccc::objects::Number();
        n->value() = 777.0f;
        bool ret1 = a->write( n );
        cccc::objects::Number* n2 = b->read<cccc::objects::Number>();
        REQUIRE( n->value() == n2->value() );
    }
}
}
