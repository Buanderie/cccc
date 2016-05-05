#pragma once

#include "pin.h"
#include "bipbuffer.h"

namespace cccc
{
    class Link
    {
    public:
        Link( cccc::Pin* start, cccc::Pin* end, size_t capacity );
        virtual ~Link();

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
