
#include "graph.h"

// RTTI
#include <typeinfo>

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

void cccc::Graph::flatten(std::vector<cccc::Node *> &nodes, std::vector<cccc::Link *> &links)
{
    // Ok, so clearly this is meant to be recursive
    for( Node* n : _nodes )
    {
        if( typeid(*n) == typeid(cccc::Graph) )
        {
            Graph* subgraph = (Graph*)(n);
            subgraph->flatten( nodes, links );
        }
        nodes.push_back(n);
    }

    for( Link* l : _links )
    {
        links.push_back(l);
    }
}

void cccc::Graph::updatePins()
{

    clearPins();

    // For each available input pins in the graph nodes, add an input pin
    // Should that be refined to only add "root" pins as input and "leaf" pins as outputs ?
    for( Node* n : _nodes )
    {
        for( Pin* p : inputPins() )
        {
            if( !p->isConnected() )
            {
                addInputPin(p);
            }
        }

        for( Pin* p : outputPins() )
        {
            if( !p->isConnected() )
            {
                addOutputPin(p);
            }
        }

    }

}
