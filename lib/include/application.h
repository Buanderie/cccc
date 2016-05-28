#pragma once

#include "graph.h"
#include "backend.h"

namespace cccc
{
    class Application
    {
    public:
        Application( cccc::Backend* backend, cccc::Graph rootGraph );
        Application( const std::string applicationFile );
        virtual ~Application(){}

        template< class B > static Application* create( cccc::Graph rootGraph = nullptr )
        {
            Backend* b = new B();
            Application* app = new Application(b, rootGraph);
            return app;
        }

    private:
        cccc::Graph*    _rootGraph;
        cccc::Backend*  _backend;

    protected:

    };
}
