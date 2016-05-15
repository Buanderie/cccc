#pragma

#include <cstddef>
#include <queue>

#include "packet.h"

namespace cccc
{
    class PacketBuffer
    {
    public:
        PacketBuffer( size_t capacity )
            :_capacity(capacity)
        {

        }

        bool pop( Packet& packet )
        {
            bool ret = false;
            if( _packets.size() > 0 )
            {
                packet = _packets.front();
                _packets.pop();
                ret = true;
            }
            return ret;
        }

        bool push( const Packet& packet )
        {
            bool ret = false;
            if( _packets.size() < _capacity )
            {
                _packets.push( packet );
                ret = true;
            }
            return ret;
        }

        size_t size()
        {
            return _packets.size();
        }

    private:
        size_t              _capacity;
        std::queue<Packet> _packets;

    protected:

    };
}
