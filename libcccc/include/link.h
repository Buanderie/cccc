#pragma once

#include "pin.h"

namespace cccc
{
    class Link
    {
    public:
        Link( cccc::Pin* start, cccc::Pin* end );
        virtual ~Link();

    private:
        cccc::Pin* _start;
        cccc::Pin* _end;

    protected:

    };
}
