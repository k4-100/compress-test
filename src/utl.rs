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
    // let sda = String::new();
    // let mut compressed_vec : Vec<String> = vec![ sda.clone() ; 10 ];
    let mut compressed_vec : Vec<String> = vec![  ];
    compressed_vec.resize(lines_vec.len() , String::new() );
    println!("{}", lines_vec.len());


    
    
    
    let mut index: usize = 0;
    
    let mut compress_buffer = | buffer_string_ref: &String, index : usize| {
        let first_char: char = buffer_string_ref.chars().nth(0).unwrap();
        
        if buffer_string_ref.len() > 4  {
            let bsc_len: usize = buffer_string_ref.len();
            compressed_vec[index].push_str(
                format!("{}x{};", first_char,bsc_len).as_str()
            );
        } else {
            // if first_char != '\n'{
                compressed_vec[index].push_str( format!("{};",buffer_string_ref.as_str() ).as_str() );
            // }
        }
        
    }
    ;
    
    let mut  buffer_string = String::new();
    
    for x in 0..lines_vec.len(){
        println!("{}",lines_vec.len());
        for y in 0..lines_vec[index].chars().count() {
            let current_char : char = lines_vec[index].chars().nth(y).unwrap();
            // if buffer string isn't empty:
            if !buffer_string.is_empty(){
                // if the first char of buffer string is the same as current_char
                if  buffer_string.chars().nth(0).unwrap() != current_char {
                    compress_buffer( &buffer_string,index );
                    buffer_string = String::from(format!("{}", current_char ));
                }
                else {
                    buffer_string.push( lines_vec[index].chars().nth(y).unwrap() );
                }
            } else {
                buffer_string = String::from( format!("{}",current_char) );
            }
            
        }
        
        

        // if !buffer_string.is_empty(){
        //     compress_buffer(  &buffer_string.clone(),index );
        // }
    }

    return compressed_vec;
}


// if !buffer_string.is_empty() && buffer_string.chars().nth(0).unwrap() != '\n' {
//     compress_buffer(  &buffer_string.clone(),index );
// }