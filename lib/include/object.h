#pragma once

#include "packet.h"

namespace cccc
{
    class Object
    {
    public:

        virtual Packet toPacket() = 0;
        virtual void fromPacket( const Packet& packet ) = 0;
    };
}
