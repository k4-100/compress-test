#include "include/utl.hpp"

int main()
{   
    const std::string PATH =  "./release/test.cmps";
    std::cout << "compiled\n";

    std::string str = CMPS::read_from_file( PATH );

    // CMPS::write_to_file( PATH, ( str + str ) );
    const std::string source = "aaabbc";
    const std::string comppressed = CMPS::compress( str );
    std::cout << "source: " << ": " << str.size() << '\n';
    std::cout << "comppressed: " << ": " << comppressed.size() << '\n';
}
