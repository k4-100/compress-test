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
        std::string compressedStr = "";
        std::string buffer = { source[ 0 ] };
        for( uint32_t i=1; i<source.size(); i++ )
        {   
            std::cout<< "source [ i ] "<< source[ i ] << '\n';
            std::cout<< "buffer: "<< buffer << '\n';
            if( source[ i ] == buffer[ buffer.length() - 1 ] )
            {   
                std::cout<< "if( source[ i ] == buffer[ i-1 ] ): "<< buffer[ i-1 ] << '\n';
               
                buffer += source[ i ];
            }
            else
            {   
                std::cout<< "buffer: "<< buffer << '\n';
                if( buffer.size() > 4)
                    compressedStr += std::to_string( buffer.length() ) + 'x' + buffer[0] + ';';
                else
                    compressedStr += buffer + ';';

                if ( i == source.size() -1 )
                    compressedStr += std::string( 1,source [ i ]) + ";" ;
                else 
                    buffer = source[ i ];
            }
            
        }

        return compressedStr;
    }

} // !namespace CMPS