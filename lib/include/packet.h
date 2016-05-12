#pragma once

#include <cstddef>

namespace cccc {

    class Packet
    {
    public:
        Packet(){}
        virtual ~Packet(){}

        size_t size(){ return 0; }
        void* data(){ return nullptr; }

    private:

    protected:

    };
}
