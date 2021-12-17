use rand::Rng;
use std::fs;
use std::fs::OpenOptions;
use std::io::Write;



pub fn read_from_file_to_vector( path : &str ) -> Vec<String>{
    let  text : String = fs::read_to_string(path).unwrap();
    let content : Vec<String> = text.split("\n").map( |x| String::from(x) ).collect();

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


#[allow(unused_mut)]
pub fn compress_file( lines_vec : Vec<String> ) -> Vec<String>{
    let mut compressed_vec : Vec<String> = vec![ ];
    compressed_vec.resize(100, String::new() );


    let mut  buffer_string = String::from( 
        lines_vec[0].chars().nth(0).unwrap() 
    );
    
    

    let mut compress_buffer = | buffer_string_ref: &String, index : usize| {
        if buffer_string_ref.len() > 4  {
            let first_char: char = buffer_string_ref.chars().nth(0).unwrap();
            let bsc_len: usize = buffer_string_ref.len();
            compressed_vec[0].push_str(
                 format!("{}x{};", first_char,bsc_len).as_str()
            );
        } else {
            compressed_vec[0].push_str( format!("{};",buffer_string_ref.as_str() ).as_str() );
        }
    }
    ;


    for y in 1..lines_vec[0].chars().count() {
        let current_char : char = lines_vec[0].chars().nth(y).unwrap();

        if buffer_string.chars().nth(0).unwrap() != current_char {
            compress_buffer( &buffer_string, y );
            buffer_string = String::from(format!("{}", current_char ));
        }
        else {
            buffer_string.push( lines_vec[0].chars().nth(y).unwrap() );
            
        }
    }

    if !buffer_string.is_empty(){
        compress_buffer(  &buffer_string.clone(), 1 );
    }

    return compressed_vec;
}