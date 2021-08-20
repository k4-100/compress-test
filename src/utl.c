#include "include/utl.h"




     char *CMPS_read_from_file( const char *path )
    {
        FILE *reader;

        char *buffer =  (char *) malloc( (200 * MIL) * sizeof( char ) );
        reader = fopen( path, "r" );
        

        fread( buffer,  sizeof(char), 200 * MIL, reader);
        fclose( reader );
        size_t len = strlen(buffer);
        printf("%ld\n", len);

        buffer[  strlen( buffer )  + 1] = '\0';

        return buffer;
    }

   void CMPS_write_to_file( const char *path, const char *buffer )
    {
        FILE *writer;
        writer = fopen(path,"w");
        fwrite( buffer, sizeof(char), strlen(buffer) , writer);
        fclose( writer );
      
    }

    // std::string CMPS_compress( const std::string source )
    // {   

    //     /// compresses current buffer
    //     /// \param buffer buffer to be compress
    //     /// \param compressedStr string concatenated by compressed buffer
    //     auto compressBuffer = [](const std::string buffer, std::string compressedStr )
    //     {
    //          if( buffer.size() > 4)
    //                 compressedStr += std::to_string( buffer.length() ) + 'x' + buffer[0] + ';';
    //             else
    //                 compressedStr += buffer + ';';
                
    //     };
    //     std::string compressedStr = "";
    //     std::string buffer = { source[ 0 ] };

        

    //     for( uint32_t i=1; i<source.size(); i++ )
    //     {
    //         if( source[ i ] == buffer[ buffer.length() - 1 ] )
    //             buffer += source[ i ];
    //         else
    //         {
    //             compressBuffer( buffer, compressedStr );
    //             // loop is at the end of iteration
    //             if ( i == source.size() -1 )
    //                 compressedStr += std::string( 1,source [ i ]) + ";" ;
    //             else 
    //                 buffer = source[ i ];
    //         }
            
    //         // std::cout<< buffer << '\n';
    //     }

    //     compressBuffer( buffer, compressedStr );

    //     return compressedStr;
    // }


    // std::string CMPS_decompress( const std::string source )
    // { 
    //     /// decompresses current buffer
    //     /// \param buffer buffer to be decompressed
    //     /// \param compressedStr string concatenated by decompressed buffer
    //     auto decompressBuffer = []( std::string buffer, std::string decompressedStr )
    //     {   
    //         uint32_t multiplicator = 0;
    //         std::string sign = "";
    //         std::size_t crossPos = buffer.find( 'x' );

    //         if( crossPos != std::string::npos )
    //         {
    //             multiplicator = std::stoi(  buffer.substr(0, crossPos )  );
    //             sign = buffer.substr( crossPos+1, 1 );

    //             for(uint32_t i=0; i<multiplicator; i++)
    //                 decompressedStr += sign;
    //         }
    //         else    
    //             decompressedStr += buffer;
    //         buffer = "";

    //     };
               
           


    //     std::string decompressedStr = "";
    //     std::string buffer = "";

    //     for( uint32_t i=0; i<source.size(); i++ )
    //     {
    //         if(source[ i ] != ';' ) 
    //             buffer += source[ i ];
    //         else
    //         {      
    //             decompressBuffer( buffer, decompressedStr );
    //         }
    //     }

    //     if(decompressedStr != "")
    //         decompressBuffer( buffer, decompressedStr );

    //     return decompressedStr;
    // }



    // void CMPS_GEN_generate_test_file( const uint32_t size )
    // {   

    // #pragma region random number generator
    //     std::mt19937 generator;
    //     generator.seed( std::time( 0 ) );
    //     std::uniform_int_distribution<uint32_t> charDice(65,77);
    //     std::uniform_int_distribution<uint32_t> lengthDice(1,10);
    // #pragma endregion // !random number generator


    // #pragma region buffer generation
    //     std::string buffer = "";
    //     for( uint32_t x=0; x<size;  x++)
    //     {   
    //         for(uint32_t y=0; y<18; y++)
    //         {
    //             int currentChar = (char)charDice( generator );
    //             uint32_t currentLength = lengthDice( generator );
    //             for( uint32_t z=0; z<currentLength; z++ )
    //             {
    //                 buffer.push_back( currentChar );
    //             }

                
    //         }
    //         if(x+1 < size)
    //             buffer += '\n';
    //     }
    // #pragma endregion  // !buffer generation 

    
    // #pragma region write to a file
    //     std::ofstream writer("./release/generated.txt");
    //     writer << buffer;
    //     writer.close();
    // #pragma endregion // !write to a file
    
    // }

    
