#include "include/utl.hpp"

int main()
{   
    const std::string PATH =  "./release/test.cmps";
    std::cout << "compiled\n";

    // std::string str = CMPS::read_from_file( PATH );

    // CMPS::write_to_file( PATH, ( str + str ) );
    const std::string source = "111223";
    std::cout << CMPS::compress( source ) << '\n';
}
