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
#include <time.h>

#define MIL 1000000

    /// reads data from file into char*
    /// \param path path to a file
    /// \return file content in form of 
    char *CMPS_read_from_file( const char *path );

    /// writes data from char *buffer into a file
    /// \param path path to a file
    /// \param buffer buffer to write into file 
    void CMPS_write_to_file( const char *path, const char *buffer );
    
    // writes data from char **bufferArr into a file
    /// \param path path to a file
    /// \param bufferArr 2d pointer containing char pointers
    /// \param ba_size bufferArr size 
    void CMPS_write_to_file_from_2d_pointer( const char *path, char **bufferArr, const size_t ba_size );

    /// compresses current buffer
    /// \param buf buffer to be compress
    /// \param str_arr 2d pointer storing compressed strings
    void CMPS_compressBuffer( char *buf, char **str_arr );

    /// compresses string 
    /// \param source string which has to be compressed
    /// \return compressed 2d char pointer containing compressed lines of text
    char **CMPS_compress( const char *source );
    

    void CMPS_decompressBuffer( char *buf, char **str_arr );
    
    /// decompresses string
    /// \param source string which has to be decompressed
    /// \return decompressed file in a form 2d char pointer
     char **CMPS_decompress( const char *source );
    // std::string CMPS_decompress( const std::string source );


    // /// generate test text file to test other functions
    // /// \param size amount of line to write into a file
    // void CMPS_GEN_generate_test_file( const uint32_t size = 10000 );

    /// generate number using random()
    /// \param min minimal value that can be returned
    /// \param max maximal value that can be returned
    int CMPS_GEN_generate_number( const u_int8_t min, const u_int8_t max );
    /// generate test text file to test other functions
    /// \param size amount of line to write into a file
    void CMPS_GEN_generate_test_file( const u_int32_t size );


#endif // !UTL_H
