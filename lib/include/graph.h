#pragma once

#include "node.h"
#include "link.h"

namespace cccc
{
    // A graph is a node and be used as such
    class Graph : public Node
    {
    public:
        Graph();
        virtual ~Graph();

        virtual void setup();

        void addNode( cccc::Node* node );
        void addLink( cccc::Link* link );

        void flatten( std::vector<Node*>& nodes, std::vector<Link*>& links );

    private:
        std::vector< Node* > _nodes;
        std::vector< Link* > _links;
        void updatePins();

    protected:

    };
}
