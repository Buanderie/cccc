#pragma once

#include "object.h"
#include "packet.h"

namespace cccc
{
namespace objects
{
class Number : public cccc::Object
{
public:

    virtual Packet toPacket()
    {
        unsigned char * buffer = new unsigned char[ sizeof(float) ];
        unsigned char * ptr2 = (unsigned char*)(&_value);
        memcpy( buffer, ptr2, sizeof(float) );
        Packet p(buffer, sizeof(float) );
        delete[] buffer;
        return p;
    }

    virtual void fromPacket(const Packet &packet)
    {
        // unsigned char * buffer = new unsigned char[ sizeof(float) ];
        unsigned char * ptr2 = (unsigned char*)(&_value);
        // memcpy( buffer, ptr2, sizeof(float) );
        // Packet p(buffer, sizeof(float) );

        memcpy( ptr2, packet.data(), sizeof(float) );
        // delete[] buffer;
        // return p;
    }

    float& value()
    {
        return _value;
    }

private:
    float _value;

};
}
}
