
#include "pin.h"
#include "link.h"

cccc::Pin::Pin()
    :_incomingLink(nullptr)
{

}

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

bool cccc::Pin::isConnected()
{
    bool cond1 = _incomingLink != nullptr;
    bool cond2 = _outcomingLinks.size() > 0;
    return cond1 & cond2;
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
    if( _incomingLink != nullptr )
    {
        return _incomingLink->read(p);
    }
    else
    {
        return false;
    }
}
