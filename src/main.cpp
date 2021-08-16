#include "include/utl.h"

int main( int argc, char *argv[] )
{   
    const std::string default_path = "./release/generated.txt";
    const std::string uncompressed_path =  "./release/generated.dcmps";
    const std::string compressed_path =  "./release/generated.cmps";

    std::string buffer = "";


    // compress .txt file
    if( argv[1][1] == 'c' )
    {   
        buffer = CMPS_read_from_file( default_path );
        
        CMPS_write_to_file( 
            compressed_path,  
            CMPS_compress( &buffer )
        );
    }
    // decompress .cmps file
    if( argv[1][1] == 'd' )
    {
        buffer = CMPS_read_from_file( compressed_path );
        CMPS_write_to_file( 
            uncompressed_path,  
            CMPS_decompress( buffer )
        );
    }
    // generate test .txt file 
    if( argv[1][1] == 'g' )
         CMPS_GEN_generate_test_file( atoi( argv[2] ) );
}
