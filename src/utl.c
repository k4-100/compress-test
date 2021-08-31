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
        FILE *writer = fopen( path, "w" );
            fwrite( buffer, sizeof(char), strlen(buffer), writer );
        fclose( writer );
    }

     void CMPS_write_to_file_from_2d_pointer( const char *path, char **bufferArr, const size_t ba_size )
    {   
        // clears out whole file
        FILE *writer = fopen( path, "w" );
            fwrite( "", 0, 0, writer );
        fclose( writer );

        // appends data to the same file 
        writer = fopen( path, "a" );
        for( size_t i=0; i< ba_size; i++ )
            fwrite( bufferArr[i], sizeof(char), strlen( bufferArr[i] ) , writer );
        fclose( writer );

        puts( bufferArr[MIL - 2] );
    }


    int CMPS_GEN_generate_number( const u_int8_t min, const u_int8_t max )
    {
        u_int8_t num = 0;
        // determines if value is correct (in range)
        u_int8_t isCorrect = 0;

        while( !isCorrect )
        {   
            num = rand() % (max+1);
            if(num < min)
                isCorrect = 0;
            else
                isCorrect = 1;
        }

        return num;
    }


    void CMPS_GEN_generate_test_file( const u_int32_t size )
    {
        // set rand seed for use by CMPS_GEN_generate_number
        srand( time(0) );

        // array pointer storing char pointers 
        char **bufferArr = (char**) malloc( MIL * 200 * sizeof( char* ) );
        size_t bufferArr_index = 0;
        // char **bufferArr = (char**) calloc( MIL * 200, sizeof(char*) );
        if( bufferArr == NULL )
            puts("ALLOCATION ERROR");
        // temporary, stack allocated buffer passing data to **bufferArr
        char buffer[200];

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
            // adds new line at the of buffer if this isn't the last line with text (
            // prevents creation of additional empty line at the end)
            if(x+1 < size)
                strcat(buffer, (char*) "\n" ); 
          
            // allocate memory for pointer at given index
            // copy buffer to said pointer
            bufferArr[ bufferArr_index ] = (char*) malloc( strlen(buffer) + 1 );
            strcpy( bufferArr[ bufferArr_index ], buffer );
            // clears out buffer for next iteration
            strcpy( buffer, "" );
            // increment index
            bufferArr_index++;
        }
        printf( "%ld\n", bufferArr_index );
        CMPS_write_to_file_from_2d_pointer( "./release/generated.txt", bufferArr, bufferArr_index );
    }


    void CMPS_compressBuffer( char *buf, char **str_arr )
    {     
        static size_t index = 0;
        const int buflen = strlen( buf );
        // added at the end
        char ending[200];
        if( buflen > 4 )
        {
            
            sprintf( ending, "%cx%d%c", buf[0], buflen, ';' );
            strcat( str_arr[ index ], ending );
        }
        else 
        {
            sprintf(ending, "%s%c", buf, ';' );
            strcat( str_arr[ index ], ending );
        }

        // when there is a new line character, increment index variable to load data into the next 
        // str_arr index
        if( buf[0] == '\n' )
            index++;
    }

    char **CMPS_compress( const char *source )
    {   
        // 2d char pointer storing lines of text (1d char pointers )
        char **str_arr = (char**) malloc( MIL * sizeof( char* ) );

        // allocate space for every single char pointer
        for( size_t i=0; i< MIL; i++)
            str_arr[i] = malloc( 200 * sizeof(char*) );

        // stores temporary data
        char buf[200] = {source[0], '\0'};

        // length of source char pointer
        const size_t srclen = strlen( source );

        // loop iterating from second to last non-null character of source argument
        for( size_t i=1; i< srclen + 1; i++  )
        {   
            // checks if current source's character is the same as buf's last non-null character
            if( source[ i ] == buf[ strlen(buf) - 1  ] )
                strcat( buf, (char[2]){source[i],'\0'} );
            else 
            {   
                // compresses buf
                CMPS_compressBuffer( buf, str_arr );
                // replace buf content with current source char
                strcpy( buf, (char[2]){source[i],'\0'} );
            }

        }
        // compresses the final buf
        // CMPS_compressBuffer( buf, str_arr );

        // return str_arr
        return str_arr;
    }



    void CMPS_decompressBuffer( char *buf, char **str_arr )
    {   
        // current index of str_arr 2d pointer
        static size_t index = 0;
        // stores result of decompressing current buf
        char ending[200] = "";
        
        // position of semicolon in buf
        int semicolon_pos = (int) ( strchr(buf, ';') - buf );
        // substring beginning with 'x'
        char *x_char_substr = strchr(buf, 'x');

        // if x_char_substr doesn't store NULL:
        if( x_char_substr != NULL )
        {

        }
        else
        {
            // for(size_t i=0; i<semicolon_pos; i++)
            //     ending[i] = buf[i];
            
            // ending[semicolon_pos] = '\0';


            // strcat()
            // concatenate whole buf, except for ';' at the end
            strncat( ending, buf, semicolon_pos );
            // puts( ending );
        }



        // printf( "semicolon_pos: %d\n", semicolon_pos );

        // concatenate ending to str_arr at current index
        strcat( str_arr[ index ], ending );

        printf( "ending: %s\n", ending );
        printf( "str_arr[ index ]: %s\n", str_arr[ index ] );


        if( buf[0] == '\n' )
            index++;
    }

    char **CMPS_decompress( const char *source )
    {   
        // 2d char pointer storing lines of text (1d char pointers )
        char **str_arr = (char**) malloc( MIL * sizeof( char* ) );

        // allocate space for every single char pointer
        for( size_t i=0; i< MIL; i++)
            str_arr[i] = malloc( 200 * sizeof(char*) );

        // stores temporary data
        char buf[200] = "";

        // length of source
        const size_t srclen = strlen( source );

        // iterate through each charcter in source
        for( size_t i=0; i < srclen + 1; i++)
        {   
            // concatenate char to buf
            strcat( buf, (char[2]){source[i], '\0'} );
            if( source[i] == ';' )
            {   
                CMPS_decompressBuffer( buf, str_arr );
                strcpy( buf, (char[1]){'\0'} );
            }
        }

        // CMPS_decompressBuffer( buf, str_arr );


        // return str_arr
        return str_arr;
    }




    // char **CMPS_compress( const char *source )
    // {   

    //     printf("%ld\n", strlen(source) );

    //     // char pointer containing pointers to char pointer string which have been compressed
    //     char **compressed_str_arr = (char**) malloc( ( MIL + 1 ) * sizeof( char* ) ); 
    //     char compressed_str[200];
    //     char buffer[10];
        
    //     strcat(buffer,  (char[2]) {  source[0], '\0' } );

    //     for( u_int32_t i=1; i< strlen( source ); i++ )
    //     {
    //         if( buffer[ strlen( buffer ) - 1 ] == source[ i ]   )
    //             // buffer += source[ i ];
    //             strcat(buffer, (char[2]){ source[i], '\0' } );
    //         else
    //         {   
    //             CMPS_compressBuffer( buffer, compressed_str, compressed_str_arr );
    //             // loop is at the end of iteration
    //             if ( i ==  strlen( source ) -1 )
    //                 // compressed_str += std::string( 1,source [ i ]) + ";" ;
    //                 strcat( compressed_str, (char[3]){ source[i], ';', '\0' }  );
    //             else 
    //                 // buffer = source[ i ];
    //                 strcpy( buffer, (char[2]){source[i], '\0' } );
    //         }
    //     }

    //     CMPS_compressBuffer( buffer, compressed_str, compressed_str_arr );

    //     return compressed_str_arr;
    // }


 // std::string CMPS_compress( const std::string source )
    // {   

    //     /// compresses current buffer
    //     /// \param buffer buffer to be compress
    //     /// \param compressed_str string concatenated by compressed buffer
    //     auto compressBuffer = [](const std::string buffer, std::string compressed_str )
    //     {
    //          if( buffer.size() > 4)
    //                 compressed_str += std::to_string( buffer.length() ) + 'x' + buffer[0] + ';';
    //             else
    //                 compressed_str += buffer + ';';
                
    //     };
    //     std::string compressed_str = "";
    //     std::string buffer = { source[ 0 ] };

        

    //     for( uint32_t i=1; i<source.size(); i++ )
    //     {
    //         if( source[ i ] == buffer[ buffer.length() - 1 ] )
    //             buffer += source[ i ];
    //         else
    //         {
    //             compressBuffer( buffer, compressed_str );
    //             // loop is at the end of iteration
    //             if ( i == source.size() -1 )
    //                 compressed_str += std::string( 1,source [ i ]) + ";" ;
    //             else 
    //                 buffer = source[ i ];
    //         }
            
    //         // std::cout<< buffer << '\n';
    //     }

    //     compressBuffer( buffer, compressed_str );

    //     return compressed_str;
    // }




    // std::string CMPS_decompress( const std::string source )
    // { 
    //     /// decompresses current buffer
    //     /// \param buffer buffer to be decompressed
    //     /// \param compressed_str string concatenated by decompressed buffer
    //     auto decompressBuffer = []( std::string buffer, std::string decompressed_str )
    //     {   
    //         uint32_t multiplicator = 0;
    //         std::string sign = "";
    //         std::size_t crossPos = buffer.find( 'x' );

    //         if( crossPos != std::string::npos )
    //         {
    //             multiplicator = std::stoi(  buffer.substr(0, crossPos )  );
    //             sign = buffer.substr( crossPos+1, 1 );

    //             for(uint32_t i=0; i<multiplicator; i++)
    //                 decompressed_str += sign;
    //         }
    //         else    
    //             decompressed_str += buffer;
    //         buffer = "";

    //     };
               
           


    //     std::string decompressed_str = "";
    //     std::string buffer = "";

    //     for( uint32_t i=0; i<source.size(); i++ )
    //     {
    //         if(source[ i ] != ';' ) 
    //             buffer += source[ i ];
    //         else
    //         {      
    //             decompressBuffer( buffer, decompressed_str );
    //         }
    //     }

    //     if(decompressed_str != "")
    //         decompressBuffer( buffer, decompressed_str );

    //     return decompressed_str;
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

    
