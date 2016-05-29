
#include "singlethreadbackend.h"

void cccc::SingleThreadedBackend::runOnce( cccc::Graph* g )
{
    // Very simple shit
    std::vector< Node* > nodes;
    std::vector< Link* > links;

    g->flatten(nodes, links);

    for( Node* n : nodes )
    {
        n->tick();
    }
}
