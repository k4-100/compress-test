#include <iostream>
#include <bitset>
#include <fstream>


#include "include/utl.hpp"


int main()
{   
    std::cout << "compiled\n";

    std::string str = CMPS::read_from_file( "./release/test.cmps" );
    // std::bitset < gibValue( 10 ) >bSet("A");
    std::cout<< str << '\n';
    // return 0;
}
