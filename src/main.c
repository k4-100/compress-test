#include "include/utl.h"

// char *getString( )
// {
//     char *str = (char*) malloc( MIL * sizeof(char) );
//     str = "WORDS";

//     return str;
// }


int main( int argc, char *argv[] )
{   
    const char* default_path = "./release/generated.txt";
    const char* compressed_path =  "./release/generated.cmps";
    const char* decompressed_path =  "./release/generated.dcmps";
    char *buffer;

    // compress .txt file
    if( argv[1][1] == 'c' )
    {   
        buffer = CMPS_read_from_file( default_path );
        CMPS_write_to_file_from_2d_pointer( 
            compressed_path,  
            CMPS_compress( buffer ),
            MIL
        );
    }
    // decompress .cmps file
    if( argv[1][1] == 'd' )
    {
        buffer = CMPS_read_from_file( compressed_path );
        CMPS_write_to_file_from_2d_pointer( 
            decompressed_path,  
            CMPS_decompress( buffer ),
            MIL
        );
    }
    // generate test .txt file 
    if( argv[1][1] == 'g' )
        CMPS_GEN_generate_test_file( atoi( argv[2] ) );
}
