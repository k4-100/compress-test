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

        /// compresses current buffer
        /// \param buffer buffer to be compress
        /// \param compressedStr string concatenated by compressed buffer
        auto compressBuffer = [](const std::string &buffer, std::string &compressedStr )
        {
             if( buffer.size() > 4)
                    compressedStr += std::to_string( buffer.length() ) + 'x' + buffer[0] + ';';
                else
                    compressedStr += buffer + ';';
                
        };
        std::string compressedStr = "";
        std::string buffer = { source[ 0 ] };

        

        for( uint32_t i=1; i<source.size(); i++ )
        {
            if( source[ i ] == buffer[ buffer.length() - 1 ] )
                buffer += source[ i ];
            else
            {
                compressBuffer( buffer, compressedStr );
                // loop is at the end of iteration
                if ( i == source.size() -1 )
                    compressedStr += std::string( 1,source [ i ]) + ";" ;
                else 
                    buffer = source[ i ];
            }
            
            // std::cout<< buffer << '\n';
        }

        compressBuffer( buffer, compressedStr );

        return compressedStr;
    }


    std::string decompress( const std::string &source )
    {
        std::string decompressedStr = "";
        std::string buffer = "";

        for( uint32_t i=0; i<source.size(); i++ )
        {
            if(source[ i ] != ';' ) 
                buffer += source[ i ];
            else
            {
                decompressedStr += buffer;
                buffer = "";
            }
        }

        if(decompressedStr != "")
            decompressedStr += buffer;

        return decompressedStr;
    }

} // !namespace CMPS