#include "include/utl.hpp"

int main()
{   
    const std::string PATH =  "./release/test.txt";
    std::cout << "compiled\n";

    std::string str = CMPS::read_from_file( PATH );

    // CMPS::write_to_file( PATH, ( str + str ) );
    const std::string source = "aaaaaabbccccccc21421521125";
    const std::string comppressed = CMPS::compress( source );
    std::cout << "source: " << ": " << source.size() << '\n';
    std::cout << comppressed << ": " << comppressed.size() << '\n';
}
