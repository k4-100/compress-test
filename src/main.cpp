#include "include/utl.hpp"

int main( int argc, char *argv[] )
{   
    const std::string default_path = "./release/generated.txt";
    const std::string uncompressed_path =  "./release/generated.dcmps";
    const std::string compressed_path =  "./release/generated.cmps";

    std::string buffer = "";


    // compress .txt file
    if( argv[1][1] == 'c' )
    {   
        buffer = CMPS::read_from_file( default_path );
        CMPS::write_to_file( 
            compressed_path,  
            CMPS::compress( buffer )
        );
    }
    // decompress .cmps file
    if( argv[1][1] == 'd' )
    {
        buffer = CMPS::read_from_file( compressed_path );
        CMPS::write_to_file( 
            uncompressed_path,  
            CMPS::decompress( buffer )
        );
    }
    // generate test .txt file 
    if( argv[1][1] == 'g' )
         CMPS::GEN::generate_test_file( atoi( argv[2] ) );
}
