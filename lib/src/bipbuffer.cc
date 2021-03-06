
// C
#include <cstdlib>
#include <cstring>

// STL
#include <iostream>
#include <algorithm>

// INTERNAL
#include "bipbuffer.h"

using namespace std;

#define INITIAL_CAPACITY 1024

cccc::BipBuffer::BipBuffer(size_t capacity, BipBufferStrategy strategy)
    :_capacity(INITIAL_CAPACITY)
    ,_blobsCapacity(capacity)
    ,_size(0)
    ,_beg_index(0)
    ,_end_index(0)
    ,_strategy(strategy)
{
    _data = 0;
    if( _capacity )
        _data = (unsigned char*)(malloc(_capacity));
}

cccc::BipBuffer::~BipBuffer()
{
    if( _data )
        free((void*)_data);
}

void cccc::BipBuffer::resize(size_t size)
{
    // realloc somehow... careful about that

    // Now that's ugly.
    BipBuffer tmp( 1.5f * size, this->_strategy );

    // Pop every item to a temp resized bipbuffer
    int nBlobs = _blobs.size();
    for( size_t k = 0; k < nBlobs; ++k )
    {
        int curSize = peekSize();
        unsigned char * buffer = new unsigned char[ curSize ];
        pop( buffer );
        tmp.push( buffer, curSize );
        delete[] buffer;
    }

    //
    _capacity = size;
    _data = (unsigned char*)realloc( _data, size );
    _size = 0;
    _beg_index = 0;
    _end_index = 0;

    // re-push every piece of shit
    for( size_t k = 0; k < nBlobs; ++k )
    {
        int curSize = tmp.peekSize();
        unsigned char * buffer = new unsigned char[ curSize ];
        tmp.pop( buffer );
        push( buffer, curSize );
    }
}

size_t cccc::BipBuffer::size()
{
    return _size;
}

size_t cccc::BipBuffer::capacity()
{
    return _capacity;
}

size_t cccc::BipBuffer::blobs()
{
    return _blobs.size();
}

size_t cccc::BipBuffer::available()
{
    return (capacity() - size());
}

bool cccc::BipBuffer::push( const void *data, size_t length)
{
    if( length >= _capacity )
        return false;

    // This code assumes read and write are working
    if( length >= ( _capacity - _size ) )
    {
        switch( _strategy )
        {
            case BIPBUFFER_OVERWRITE:
            {
                //cout << "fuck it's full" << endl;
                while( (_capacity - _size) < length )
                {
                    read(NULL, peekSize(), false);
                    _blobs.erase( _blobs.begin() + 0 );
                }
                write( (const unsigned char*)data, length );
                _blobs.push_back( length );
                break;
            }

            case BIPBUFFER_SKIP:
            {
                return false;
                break;
            }

        default:
            break;
        }

        return false;
    }
    else
    {
        _blobs.push_back( length );
        write( (const unsigned char*)data, length );
        return true;
    }

    return false;

}

size_t cccc::BipBuffer::peekSize()
{
    if( size() != 0 )
    {
        return _blobs[ 0 ];
    }
    else
        return 0;
}

bool cccc::BipBuffer::pop( const void *dst )
{
    // If there is a blob in the buffer
    if( size() != 0 )
    {
        size_t blobSize = peekSize();
        read( (const unsigned char*)dst, blobSize, true );
        _blobs.erase( _blobs.begin() + 0 );
        return true;
    }
    else
    {
        //do nothing and get over it
        return false;
    }
}

size_t cccc::BipBuffer::write(const unsigned char *data, size_t bytes)
{
    if( !_data )
        return 0;

    size_t capacity = _capacity;
    size_t bytes_to_write = std::min(bytes, capacity - _size );

    // Write in single step
    if( bytes_to_write <= capacity - _end_index )
    {
        memcpy( _data + _end_index, data, bytes_to_write );
        _end_index += bytes_to_write;
        if( _end_index == _capacity )
            _end_index = 0;
    }
    // Write in two steps
    else
    {
        size_t size_1 = _capacity - _end_index;
        memcpy( _data + _end_index, data, size_1 );
        size_t size_2 = bytes_to_write - size_1;
        memcpy( _data, data+size_1, size_2 );
        _end_index = size_2;
    }

    _size += bytes_to_write;

    return bytes_to_write;
}

size_t cccc::BipBuffer::read(const unsigned char *data, size_t bytes, bool executeOperation )
{
    if( executeOperation && !_data )
        return 0;

    size_t capacity = _capacity;
    size_t bytes_to_read = std::min(bytes, _size);

    // Read in a single step
    if( bytes_to_read <= capacity - _beg_index )
    {
        if( executeOperation )
            memcpy( (void*)data, (const void*)(_data + _beg_index), bytes_to_read );
        _beg_index += bytes_to_read;
        if( _beg_index == _capacity )
            _beg_index = 0;
    }
    // Read in two steps
    else
    {
        size_t size_1 = capacity - _beg_index;
        if( executeOperation )
            memcpy( (void*)data, (const void*)(_data + _beg_index), size_1 );
        size_t size_2 = bytes_to_read - size_1;
        if( executeOperation )
            memcpy( (void*)(data + size_1), (const void*)_data, size_2 );
        _beg_index = size_2;
    }

    _size -= bytes_to_read;
    return bytes_to_read;
}
