
#include <cccc.h>
#include <catch.hpp>

namespace cccc
{
TEST_CASE( "BipBuffer", "[core]" )
{
    SECTION("Constructor") {
        BipBuffer * bb = new BipBuffer( 1024 );
        delete bb;
    }

    SECTION("write")
    {
        BipBuffer bb(1024);
        const unsigned char * buffer = new unsigned char[ 1 ];
        for( size_t k = 0; k < 1024; ++k )
        {
            bb.push( (void*)(buffer), 1 );
        }
        REQUIRE( bb.available() == 0 );
        delete[] buffer;
    }

    // NOT IMPLEMENTED YET
    /*
    SECTION("resize")
    {
        BipBuffer bb(1024);
        const unsigned char * buffer = new unsigned char[ 1 ];
        for( size_t k = 0; k < 1024; ++k )
        {
            bb.push( (void*)(buffer), 1 );
        }
        bb.resize(2048);
        REQUIRE( bb.available() == 1024 );
        delete[] buffer;
    }
	*/
	
    SECTION("read")
    {
        BipBuffer bb(128);
        unsigned char * buffer = new unsigned char[ 1 ];
        for( size_t k = 0; k < 128; ++k )
        {
            buffer[0] = (unsigned char)k;
            bb.push( (void*)(buffer), 1 );
        }
        int diff = 0;
        for( size_t k = 0; k < 128; ++k )
        {
            if( bb.pop( buffer ) )
            {
                if( buffer[0] != (unsigned char)k )
                    diff++;
            }
            else
            {
                diff++;
            }
        }
        REQUIRE( diff == 0 );
        delete[] buffer;
    }

    SECTION("overwrite")
    {
        int diff = 0;
        BipBuffer bb(128);
        unsigned char * buffer = new unsigned char[ 1 ];
        for( size_t k = 0; k < 128; ++k )
        {
            buffer[0] = (unsigned char)k;
            if( !bb.push( (void*)(buffer), 1 ) )
                diff++;
        }
        REQUIRE( diff == 1 );
        delete[] buffer;
    }

    SECTION("overread")
    {
        int diff = 0;
        BipBuffer bb(128);
        unsigned char * buffer = new unsigned char[ 1 ];
        for( size_t k = 0; k < 127; ++k )
        {
            buffer[0] = (unsigned char)k;
            bb.push( (void*)(buffer), 1 );
        }

        for( size_t k = 0; k < 128; ++k )
        {
            if( !bb.pop( (void*)(buffer) ) )
                diff++;
        }

        REQUIRE( diff == 1 );

        delete[] buffer;
    }
}
}
