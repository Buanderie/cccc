#pragma once

#include "pin.h"
#include "packetbuffer.h"
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
        size_t size();

    private:
        cccc::Pin* _start;
        cccc::Pin* _end;

        cccc::PacketBuffer * _buffer;
        size_t _capacity;

        void init();
        void destroy();

    protected:

    };
}
