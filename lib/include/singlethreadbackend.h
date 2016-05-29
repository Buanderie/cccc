#pragma once

#include "backend.h"

namespace cccc
{
    class SingleThreadedBackend : cccc::Backend
    {
    public:
        SingleThreadedBackend(){}
        virtual ~SingleThreadedBackend(){}

        virtual void runOnce(cccc::Graph *g);

    };
}
