#pragma once


#include "graph.h"

namespace cccc
{
    class Backend
    {
    public:
        Backend(){}
        virtual ~Backend(){}

        virtual void runOnce( cccc::Graph* g )=0;

    private:

    protected:

    };
}
