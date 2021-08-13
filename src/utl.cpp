#include "include/utl.hpp"


std::string CMPS::read_from_file( const std::string &path )
{
    std::ifstream reader( path );
    std::string buffer( std::istreambuf_iterator< char > ( reader ),{} );
    reader.close();
    std::cout<< "stream closed\n";
    return buffer;
}