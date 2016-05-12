#pragma once

#include <cstddef>
#include <cstring>

#include <iostream>

using namespace std;

namespace cccc {

    class Packet
    {
    public:
        Packet( const void* data=nullptr, size_t payloadSize=0 )
            :_payloadSize(payloadSize), _payload(nullptr)
        {
            init();
            if( data != nullptr && payloadSize > 0 )
            {
                memcpy( _payload, data, payloadSize );
            }
        }

        Packet( const Packet& other )
            :_payloadSize(other._payloadSize), _payload(nullptr)
        {
            (*this) = other;
        }

        Packet& operator =( const Packet& other )
        {
            destroy();
            _payloadSize = other._payloadSize;
            init();
            memcpy( _payload, other._payload, _payloadSize );
            return (*this);
        }

        virtual ~Packet()
        {
            destroy();
        }

        size_t size(){ return _payloadSize; }
        void* data(){ return _payload; }

    private:
        void*   _payload;
        size_t  _payloadSize;

        void init()
        {
            _payload = malloc( _payloadSize );
        }

        void destroy()
        {
            if( _payload != nullptr )
            {
                free( _payload );
            }
        }

    protected:

    };
}
