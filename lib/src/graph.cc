
#include "graph.h"


cccc::Graph::Graph()
{

}

cccc::Graph::~Graph()
{

}

void cccc::Graph::setup()
{
    updatePins();
}

void cccc::Graph::addNode(cccc::Node *node)
{

}

void cccc::Graph::addLink(cccc::Link *link)
{

}

void cccc::Graph::updatePins()
{

    clearPins();

    // For each available input pins in the graph nodes, add an input pin
    for( Node* n : _nodes )
    {
        for( Pin* p : inputPins() )
        {
            if( !p->isConnected() )
            {
                addInputPin(p);
            }
        }
    }

}
