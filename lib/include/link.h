#pragma once

#include "pin.h"
#include "bipbuffer.h"

#include "packet.h"

namespace cccc
{
    class Link
    {
    public:
        Link( cccc::Pin* start, cccc::Pin* end, size_t capacity );
        virtual ~Link();

        bool write( const cccc::Packet& packet );
        bool read( cccc::Packet& packet );

    private:
        cccc::Pin* _start;
        cccc::Pin* _end;

        cccc::BipBuffer * _buffer;
        size_t _capacity;

        void init();
        void destroy();

    protected:

    };
}
