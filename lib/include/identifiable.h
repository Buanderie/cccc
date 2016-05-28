#pragma once

#include "shortid.h"

namespace cccc
{
    class Identifiable
    {
    public:
        Identifiable()
        {

        }

        virtual ~Identifiable()
        {

        }

        cccc::ShortId id()
        {
            return _id;
        }

    private:
        ShortId _id;

    protected:

    };
}
