#ifndef UTL_HPP
#define UTL_HPP

#include <iostream>
#include <bitset>
#include <fstream>



/// stores program utilities
namespace CMPS 
{

    /// read data from file into std::string buffer
    /// \param path path to a file
    /// \return file content in form of std::string
    std::string read_from_file( const std::string &path );

    /// write data from std::string buffer into a file
    /// \param path path to a file
    /// \param buffer buffer to write into file 
    void read_to_file( const std::string &path, std::string &buffer );

} // !namespace UTL


#endif // !UTL_HPP
