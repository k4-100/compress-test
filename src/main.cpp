#include "include/utl.hpp"

int main()
{
    std::cout << "compiled\n";

    std::string str = CMPS::read_from_file( "./release/test.cmps" );
}
