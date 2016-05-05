
#include "link.h"

#include <iostream>

using namespace std;

cccc::Link::Link(cccc::Pin *start, cccc::Pin *end, size_t capacity)
    :_start(start), _end(end), _capacity(capacity), _buffer(nullptr)
{

}

cccc::Link::~Link()
{

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
