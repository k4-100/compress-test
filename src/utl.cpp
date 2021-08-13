#include "include/utl.hpp"

namespace CMPS
{

std::string read_from_file( const std::string &path )
{
    std::ifstream reader( path );
    std::string buffer( std::istreambuf_iterator< char > ( reader ),{} );
    reader.close();

    return buffer;
}

} // !namespace CMPS