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
    // const char* decompressed_path =  "./release/generated.dcmps";

    // std::string buffer = "";

    
    // CMPS_GEN_generate_test_file( MIL );


    const char *buffer = CMPS_read_from_file( default_path );
    char **b = CMPS_compress( buffer );

    free( buffer );
    free( b );
    // CMPS_write_to_file( compressed_path, b );

    // char *buffer = CMPS_read_from_file( default_path );
    // CMPS_write_to_file( compressed_path, buffer );
    // free ( buffer );

    // char *buff = CMPS_read_from_file( compressed_path );
    // CMPS_write_to_file( decompressed_path, buff );
    // free( buff );

   

    // printf( "result: %d\n", CMPS_GEN_generate_number(10,20) );
    

    // // compress .txt file
    // if( argv[1][1] == 'c' )`
    // {   
    //     buffer = CMPS_read_from_file( default_path );
    //     CMPS_write_to_file( 
    //         compressed_path,  
    //         CMPS_compress( buffer )
    //     );
    // }
    // // decompress .cmps file
    // if( argv[1][1] == 'd' )
    // {
    //     buffer = CMPS_read_from_file( compressed_path );
    //     CMPS_write_to_file( 
    //         uncompressed_path,  
    //         CMPS_decompress( buffer )
    //     );
    // }
    // // generate test .txt file 
    // if( argv[1][1] == 'g' )
    //      CMPS_GEN_generate_test_file( atoi( argv[2] ) );
}
