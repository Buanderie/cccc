#pragma once

#include <iostream>
#include <vector>

#include "object.h"

namespace cccc
{
    class Link;
    class Pin
    {

        friend class cccc::Link;

    public:
        Pin();
        virtual ~Pin(){}

        bool write( Object* object );
        template< typename T> T* read()
        {
            Packet p;
            T* ret = nullptr;
            if( readPacket( p ) )
            {
                ret = new T();
                ret->fromPacket(p);
            }
            return ret;
        }

        bool isConnected();

    private:
        Link* _incomingLink;
        std::vector<Link*> _outcomingLinks;

        void setIncomingLink( Link* link );
        void addOutcomingLink( Link* link );
        bool readPacket(Packet &p);

    };
}
