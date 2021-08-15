#include "include/utl.hpp"

int main( int argc, char *argv[] )
{   


 

    if( argv[1][1] == 'g' )
         CMPS::GEN::generate_test_file( atoi( argv[2] ) );


    // const std::string PATH =  "./release/test.txt";
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
