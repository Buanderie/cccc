#include <cccc.h>
#include <catch.hpp>

#include <iostream>

using namespace std;

namespace cccc
{
class TestNode1 : public cccc::Node
{
public:

    int s_cpt;
    int r_cpt;

    TestNode1()
    {
        s_cpt = 0;
        r_cpt = 0;
    }

    virtual ~TestNode1()
    {

    }

    virtual void setup()
    {
        Pin * i = new Pin();
        Pin * o = new Pin();
        addInputPin(i);
        addOutputPin(o);
    }

    virtual void tick(){

        Pin* pi = getInput(0);
        cccc::objects::Number* n = pi->read<cccc::objects::Number>();
        if( n != nullptr )
        {
            // cout << "received number: " << n->value() << endl;
            r_cpt++;
        }

        cccc::objects::Number* outNumber = new cccc::objects::Number();
        outNumber->value() = s_cpt;

        s_cpt++;

        getOutput(0)->write(outNumber);
    }
};
}

namespace cccc
{
TEST_CASE("Node", "[core]") {
    SECTION("BasicTest1")
    {
        Node* a = new TestNode1();
        Node* b = new TestNode1();
        a->setup();
        b->setup();

        Link* l = new Link( a->getOutput(0), b->getInput(0), 1 );

        int iter = 10;
        for( size_t k = 0; k < iter; ++k )
        {
            a->tick();
            b->tick();
        }

        REQUIRE( ((TestNode1*)(a))->s_cpt == iter );
        REQUIRE( ((TestNode1*)(b))->r_cpt == iter );

    }
}
}
