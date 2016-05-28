
#include "node.h"


void cccc::Node::addInputPin(cccc::Pin *p)
{
    _inputPins.push_back(p);
}

void cccc::Node::addOutputPin(cccc::Pin *p)
{
    _outputPins.push_back(p);
}

cccc::Pin *cccc::Node::getInput(size_t idx)
{
    return _inputPins[ idx ];
}

cccc::Pin *cccc::Node::getOutput(size_t idx)
{
    return _outputPins[idx];
}

std::vector<cccc::Pin *> &cccc::Node::inputPins()
{
    return _inputPins;
}

std::vector<cccc::Pin *> &cccc::Node::outputPins()
{
    return _outputPins;
}

void cccc::Node::clearPins()
{
    _inputPins.clear();
    _outputPins.clear();
}
