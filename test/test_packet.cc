
#include <cccc.h>
#include <catch.hpp>

#define PBS 128

namespace cccc
{
TEST_CASE("Packet", "[protocol]") {
    SECTION("Constructor/Destructor")
    {
        unsigned char * buffer = new unsigned char[PBS];
        Packet p(buffer, PBS);
        REQUIRE( p.data() != nullptr );
        REQUIRE( p.data() != (void*)(buffer) );
        REQUIRE( p.size() == PBS )
        delete[] buffer;
    }

    SECTION("Copy Constructor")
    {
        unsigned char * buffer = new unsigned char[PBS];
        for( size_t k = 0; k < PBS; ++k )
        {
        	buffer[k] = (unsigned char)(k);
        }
        Packet p1(buffer, PBS);
        Packet p2 = p1;
        bool dataOk = true;
        unsigned char * ptr1 = (unsigned char*)(p1.data());
        unsigned char * ptr2 = (unsigned char*)(p2.data());
        for( size_t k = 0; k < PBS; ++k )
        {
        	if( ptr1[k] != ptr2[k] )
        		dataOk = false;
        }
        REQUIRE( p2.data() != nullptr );
        REQUIRE( p1.data() != p2.data() );
        REQUIRE( dataOk == true );
        delete[] buffer;
    }
}
}
