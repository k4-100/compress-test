#include "include/utl.h"




    char *CMPS_read_from_file( const char *path )
    {
        char *buffer =  (char *) malloc( (200 * MIL) * sizeof( char ) );
        
        FILE *reader = fopen( path, "r" );
            fread( buffer,  sizeof(char), 200 * MIL, reader );
        fclose( reader );
        return buffer;
    }

   
    void CMPS_write_to_file( const char *path, const char *buffer )
    {   
        // printf("buffer: %s\n", buffer);
        // printf("path: %s\n", path);
        FILE *writer = fopen( path, "w" );
            fwrite( buffer, sizeof(char), strlen(buffer), writer );
        fclose( writer );
    }

    void CMPS_write_to_file_from_2d_pointer( const char *path, const char **buffer )
    {   
        FILE *writer = fopen( path, "w" );
            fwrite( buffer, sizeof(char), strlen(buffer), writer );
        fclose( writer );
    }


    int CMPS_GEN_generate_number( const u_int16_t min, const u_int16_t max  )
    {
        // srand( time(0) );
        u_int16_t num = 0;
        // determines if value is correct (in range)
        int isCorrect = 0;

        while( !isCorrect )
        {   
            num = rand() % (max+1);
            if( num < min || num > max )
                isCorrect = 0;
            else
                isCorrect = 1;
        }

        return num;
    }


    void CMPS_GEN_generate_test_file( const u_int32_t size )
    {
        
        srand( time(0) );

        // array pointer storing char pointers 
        char **bufferArr = (char**) malloc( MIL * 200 * sizeof( char* ) );
        size_t bufferArr_index = 0;
        // char **bufferArr = (char**) calloc( MIL * 200, sizeof(char*) );
        if( bufferArr == NULL )
            puts("ALLOCATION ERROR");
        // temporary, stack allocated buffer passing data to **bufferArr
        char buffer[200];
        
        // char* bufferPtr = &buffer;
        // printf("bufferPtr: %ld\n", bufferPtr);


        // FILE *writer = fopen( "./release/generated.txt", "wb" );
        //     fwrite( "", 0, 0, writer );
        // fclose( writer );

        // whole file 
        for( u_int32_t x=0; x<size; x++)
        {   
            // whole line 
            for(u_int8_t y=0; y<18; y++)
            {  
                char currentChar = (char)CMPS_GEN_generate_number(65,77);
                u_int8_t currentLength = CMPS_GEN_generate_number(1,10);
                // partial sequence 
                for( u_int8_t z=0; z<currentLength; z++ )
                    // add char to 
                    strcat(buffer,  (char[2]) {  currentChar, '\0' }); 

                
            }
            // condition ensures that there will be no new line character at the end of file
            // causing empty line to generate
            if(x+1 < size)
            {
                // allocate memory for pointer at given index
                // copy buffer to said pointer
                bufferArr[ bufferArr_index ] = (char*) malloc( strlen(buffer) + 1 );
                strcpy( bufferArr[ bufferArr_index ], buffer );
                // clears out buffer for next iteration
                strcpy( buffer, "" );
            }

            // writer = fopen( "./release/generated.txt", "ab" );
            //     fwrite( buffer, sizeof(char), strlen(buffer), writer );
            // fclose( writer );
            // clears out buffer
            
        }

    }

    /// compresses current buffer
    /// \param buffer buffer to be compress
    /// \param compressedStr string concatenated by compressed buffer
    void CMPS_compressBuffer( char *buffer, char *compressedStr )
    {
        if( strlen( buffer ) > 4)
        {   
            char ending[100] = "";
            // puts("if( strlen( buffer ) > 4)");
            sprintf(ending, "%ldx%c;", strlen( buffer ),buffer[0] );
            strcat( compressedStr, ending );
        }
        else
        {
            strcat( compressedStr, buffer );
            strcat( compressedStr, (char[2]){ ';', '\0'} );
        }
    }

    char *CMPS_compress( const char *source )
    {   

        printf("%ld\n", strlen(source) );

        // char pointer containing pointers to char pointer string which have been compressed
        char **compressed_str_arr = (char**) malloc( ( MIL + 1 ) * sizeof( char* ) ); 
        printf( "compressed_str_arr: %ld\n", sizeof(compressed_str_arr) );


        char *compressedStr =  (char *) malloc( 200 );
        char buffer[10];
        strcat(buffer,  (char[2]) {  source[0], '\0' } );

        

        for( u_int32_t i=1; i< strlen( source ); i++ )
        {
            if( buffer[ strlen( buffer ) - 1 ] == source[ i ]   )
                // buffer += source[ i ];
                strcat(buffer, (char[2]){ source[i], '\0' } );
            else
            {   
                // printf("buffer: %ld\n", strlen(buffer) );
                // printf("compressedStr: %ld\n", strlen(compressedStr) );
                CMPS_compressBuffer( buffer, compressedStr );
                // loop is at the end of iteration
                if ( i ==  strlen( source ) -1 )
                    strcat( compressedStr, (char[3]){ source[i], ';', '\0' }  );
                    // compressedStr += std::string( 1,source [ i ]) + ";" ;
                else 
                    strcpy( buffer, (char[2]){source[i], '\0' } );
                    // buffer = source[ i ];
            }
            // printf("buffer: %s\n", buffer );
            // std::cout<< buffer << '\n';
        }

        CMPS_compressBuffer( buffer, compressedStr );

        
        

        return compressedStr;
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

    
