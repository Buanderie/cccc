
#include "pin.h"
#include "link.h"

bool cccc::Pin::write(cccc::Object *object)
{
    bool ret = true;
    for( Link* l : _outcomingLinks )
    {
        if( !l->write( object->toPacket() ) )
            ret = false;
    }
    return ret;
}

void cccc::Pin::setIncomingLink(cccc::Link *link)
{
    _incomingLink = link;
}

void cccc::Pin::addOutcomingLink(cccc::Link *link)
{
    _outcomingLinks.push_back( link );
}

bool cccc::Pin::readPacket( cccc::Packet& p )
{
    return _incomingLink->read(p);
}
