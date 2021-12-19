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


#[allow(unused_mut)]
pub fn compress_file( lines_vec : Vec<String> ) -> Vec<String>{
    let lines_vec_len: usize  = lines_vec.len();
    let mut compressed_vec : Vec<String> = vec![ String::new() ; lines_vec_len  ];
    
    let mut index: usize = 0;
    
    let mut compress_buffer = | buffer_string_ref: &String, index : usize| {
        let first_char: char = buffer_string_ref.chars().nth(0).unwrap();
        let bsc_len: usize = buffer_string_ref.len();
        if bsc_len > 4  {
            compressed_vec[index].push_str(
                format!("{}x{};", first_char,bsc_len).as_str()
            );
        } else {
            // if first_char != '\n'{
                compressed_vec[index].push_str( format!("{};",buffer_string_ref ).as_str() );
            // }
        }
        
    }
    ;
    
    let mut  buffer_string = String::new();
    buffer_string =  String::from( &lines_vec[0][0..1] );

    // let buffer_string_chars = buffer_string.chars();
    for x in 0..lines_vec_len{
        for y in 0..lines_vec[index].chars().count() {
            let current_char = String::from(&lines_vec[index][y..y+1]);
            
            // if buffer string isn't empty:
            // if !buffer_string.is_empty(){
                // if the first char of buffer string is the same as current_char
                if  &buffer_string[0..1] != current_char {
                    compress_buffer( &buffer_string,index );
                    buffer_string = String::from(format!("{}", current_char ));
                    if current_char == "\n"{
                        index += 1;
                    }
                }
                else {
                    buffer_string.push( lines_vec[index].chars().nth(y).unwrap() );
                    
                }
        }
        
        

      
    }

    return compressed_vec;
}
