#ifndef UTL_HPP
#define UTL_HPP

#include <iostream>
#include <bitset>
#include <fstream>



/// stores program utilities
namespace CMPS 
{

    /// reads data from file into std::string buffer
    /// \param path path to a file
    /// \return file content in form of std::string
    std::string read_from_file( const std::string &path );

    /// writes data from std::string buffer into a file
    /// \param path path to a file
    /// \param buffer buffer to write into file 
    void write_to_file( const std::string &path, const std::string &buffer );

    /// compresses string 
    /// \param source source string which has to be compressed
    /// \return compressed string
    std::string compress( const std::string &source );
    
    /// decompresses string 
    /// \param source source string which has to be decompressed
    /// \return decompressed string
    std::string decompress( const std::string &source );


    /// namespace for generator
    namespace GEN
    {   
        /// generate test text file to test other functions
        /// \param size amount of line to write into a file
        void generate_test_file( const uint32_t &size );

    } // !namespace GEN

} // !namespace CMPS


#endif // !UTL_HPP
