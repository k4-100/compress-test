#ifndef UTL_H
#define UTL_H

// #include <iostream>
// #include <bitset>
// #include <fstream>
// #include <random>
// #include <ctime>
// #include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIL 1000000

    /// reads data from file into char*
    /// \param path path to a file
    /// \return file content in form of 
    char *CMPS_read_from_file( const char *path );

    /// writes data from char *buffer into a file
    /// \param path path to a file
    /// \param buffer buffer to write into file 
    void CMPS_write_to_file( const char *path, const char *buffer );

    // /// compresses string 
    // /// \param source source string which has to be compressed
    // /// \return compressed string
    // std::string CMPS_compress( const std::string source );
    
    // /// decompresses string 
    // /// \param source source string which has to be decompressed
    // /// \return decompressed string
    // std::string CMPS_decompress( const std::string source );


    // /// generate test text file to test other functions
    // /// \param size amount of line to write into a file
    // void CMPS_GEN_generate_test_file( const uint32_t size = 10000 );



#endif // !UTL_H
