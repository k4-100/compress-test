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

    void write_to_file( const std::string &path, const std::string &buffer )
    {
        std::ofstream writer( path );
        writer << buffer;
        writer.close();
    }

    std::string compress( const std::string &source )
    {   
        std::string compressedStr = "compressed";
        std::string buffer = { source[ 0 ] };
        for( uint32_t i=1; i<source.size(); i++ )
        {
            if( source[ i ] == buffer[ i-1 ] )
                buffer += source[ i ];
            else
            {   
                std::cout<<  buffer << '\n';
                compressedStr += std::to_string( buffer.length() ) + 'x' +  buffer[0] + ';';
                if( i + 1 < source.size() )
                    buffer = source[ i+1 ];
            }
            
        }

        return compressedStr;
    }

} // !namespace CMPS