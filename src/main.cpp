#include "include/utl.hpp"

int main( int argc, char *argv[] )
{   
    const std::string uncompressed_path =  "./release/generated.txt";
    const std::string compressed_path =  "./release/generated.cmps";

    std::string buffer = "";


    // compress .txt file
    if( argv[1][1] == 'c' )
    {   
        buffer = CMPS::read_from_file( uncompressed_path );
        CMPS::write_to_file( 
            compressed_path,  
            CMPS::compress( buffer )
        );
    }
    // decompress .cmps file
    if( argv[1][1] == 'd' )
    {
        
    }
    // generate test .txt file 
    if( argv[1][1] == 'g' )
         CMPS::GEN::generate_test_file( atoi( argv[2] ) );
    


    
    // std::cout << "compiled\n";

    // std::string str = CMPS::read_from_file( PATH );

    // // CMPS::write_to_file( PATH, ( str + str ) );
    // // const std::string source = "aaaaaabbccccccc21421521125";
    // const std::string comppressed = CMPS::compress( str );
    

    // std::cout << "str: " << ": " << str.size() << '\n';
    // std::cout<< "\n#####################\n\n";
    // std::cout << comppressed << ": " << comppressed.size() << '\n';
    
    // std::cout<< "\n#####################\n\n";
    // const std::string decompressed =  CMPS::decompress( comppressed );
    // std::cout << decompressed << ": " << decompressed.size() << '\n';
}
