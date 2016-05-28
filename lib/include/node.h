#pragma once

#include <vector>

#include "pin.h"
#include "identifiable.h"

namespace cccc
{
    class Node : public Identifiable
    {
    public:
        Node(){}
        virtual ~Node(){}

        virtual void setup() = 0;
        virtual void tick() = 0;

        Pin* getInput(size_t idx);
        Pin* getOutput(size_t idx);

    private:
        std::vector< Pin* > _inputPins;
        std::vector< Pin* > _outputPins;

    protected:
        std::vector<Pin*>& inputPins();
        std::vector<Pin*>& outputPins();

        void clearPins();
        void addInputPin( Pin* p );
        void addOutputPin( Pin* p );

    };
}
