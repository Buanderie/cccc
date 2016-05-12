#pragma once

#include <cstddef>
#include <cstring>

#define CCCC_PACKET_HEADER_SIZE 24

namespace cccc {

    class Packet
    {
    public:
        Packet( const void* data=nullptr, size_t payloadSize=0 )
            :_payloadSize(payloadSize)
        {
            init();
            if( data != nullptr && payloadSize > 0 )
            {

            }
        }

        virtual ~Packet()
        {
            destroy();
        }

        size_t size(){ return _payloadSize + CCCC_PACKET_HEADER_SIZE; }
        size_t payloadSize(){ return _payloadSize; }
        void* data(){ return _packetData; }

    private:
        void*   _packetData;
        size_t  _payloadSize;

        void init()
        {
            _packetData = malloc( _payloadSize + CCCC_PACKET_HEADER_SIZE );
        }

        void destroy()
        {
            if( _packetData != nullptr )
            {
                free( _packetData );
            }
        }

    protected:

    };
}
