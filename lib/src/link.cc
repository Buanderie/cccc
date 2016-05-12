
#include "link.h"
#include "packet.h"

#include <iostream>

using namespace std;

cccc::Link::Link(cccc::Pin *start, cccc::Pin *end, size_t capacity)
    :_start(start), _end(end), _capacity(capacity), _buffer(nullptr)
{
    init();
}

cccc::Link::~Link()
{
    destroy();
}

bool cccc::Link::write(const cccc::Packet &packet)
{
    return true;
}

bool cccc::Link::read(cccc::Packet &packet)
{
    return true;
}

void cccc::Link::init()
{
    _buffer = new BipBuffer( _capacity );
}

void cccc::Link::destroy()
{
    if( _buffer != nullptr )
        delete _buffer;
}
