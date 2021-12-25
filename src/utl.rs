use rand::Rng;
use std::fs;
use std::fs::OpenOptions;
use std::io::Write;



pub fn read_from_file_to_vector( path : &str ) -> Vec<String>{
    let  text : String = fs::read_to_string(path).unwrap();
    let content : Vec<String> = text.split("\n").map( |x| String::from( format!("{}\n",x) ) ).collect();

    return content;
}


pub fn write_into_file( path : &str, string_vec : Vec<String> ){
    // clears out file 
    // creates it if doesn't exist
    fs::write(path,"").expect("clean-up failed");
    
    // opens file with appending 
    let mut file = OpenOptions::new()
        .append(true)
        .open(path)
        .expect("Stuff to break");

    for x in 0..string_vec.len(){
        // append data to a file
        &file.write_all( string_vec[x].as_bytes());
    }

}

#[allow(dead_code)]
pub fn generate_file( lines : u32 ) -> Vec<String> {
    let mut  v : Vec<String> = vec![]; 
    let mut buf : String = String::with_capacity(200);

    for x in 0..lines{
        for _y in 0..18
        {   
            let chr : char = rand::thread_rng().gen_range(65..(77+1)) as u8 as char;
            for _z in 0..rand::thread_rng().gen_range(1..(10+1))
            {   
                buf.push( chr );
            }
        }
        if x < lines-1{
            buf.push('\n');
        }
        
        v.push( buf.clone() );
        buf.clear();
    }

    return v;
}


#[allow(unused_mut,dead_code)]
pub fn compress_file( lines_vec : Vec<String> ) -> Vec<String>{
    let lines_vec_len: usize  = lines_vec.len();
    let mut compressed_vec : Vec<String> = vec![ String::new() ; lines_vec_len  ];

    let mut compress_buffer = | buffer_string_ref: &String, index : usize| {
        let bsc_len: usize = buffer_string_ref.len();
        if bsc_len > 4  {
            compressed_vec[index].push_str(
                format!("{}x{};", &buffer_string_ref[0..1],bsc_len).as_str()
            );
        } else {
            compressed_vec[index].push_str( format!("{};",buffer_string_ref ).as_str() );
        }
        
    }
    ;

    for x in 0..lines_vec_len{
        let mut buffer_string =  String::from( &lines_vec[x][0..1] );
        for y in 1..lines_vec[x].chars().count() {
            let current_char = &lines_vec[x][y..y+1];
            
            // if the first char of buffer string is the same as current_char:
            if  &buffer_string[0..1] != current_char {
                compress_buffer( &buffer_string,x );
                buffer_string = String::from(format!("{}", current_char ));
                if current_char == "\n" && x < lines_vec_len-1{
                    compress_buffer( &buffer_string,x );
                }
            }
            else {
                buffer_string.push_str( current_char );
            }

        }
        
    }

    return compressed_vec;
}

pub fn decompress_file( lines_vec : Vec<String> ) -> Vec<String> {
    let lines_vec_len: usize  = lines_vec.len();
    let mut decompressed_vec: Vec<String> = vec![ String::new() ; lines_vec_len];


    for x in 0..lines_vec_len{
        let mut buffer_string : String = String::new();
        lines_vec[x].split(";").collect::<Vec<&str>>().iter().for_each(
            |segment| {
                if segment.contains("x"){
                    let segment_parts = (
                        &segment[0..1],
                        (&segment[
                            segment.chars()
                            .position( |ch| ch == 'x').unwrap()+1..segment.chars().count()
                        ])
                        .parse::<u8>().unwrap()
                    );
                    println!("{:?}",segment_parts);
                    for _ in 0..segment_parts.1{
                        buffer_string.push_str( segment_parts.0 );
                    }
                }
                else{
                    buffer_string.push_str( &segment);
                }
            }
        );
        decompressed_vec.push( buffer_string);
    }
    
    
    
    

    return decompressed_vec;
}