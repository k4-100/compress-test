use rand::Rng;
use std::fs;
use std::fs::OpenOptions;
use std::io::Write;



pub fn read_from_file_to_vector() -> Vec<String>{
    let  text : String = fs::read_to_string("./res/test.txt").unwrap();
    let content : Vec<String> = text.split("\n").map( |x| String::from(x) ).collect();

    return content;
}


pub fn write_into_file( string_vec : Vec<String> ){
    // clears out file 
    // creates it if doesn't exist
    fs::write("res/test.txt","").expect("clean-up failed");
    
    // opens file with appending 
    let mut file = OpenOptions::new()
        .append(true)
        .open("res/test.txt")
        .expect("Stuff to break");

    for x in 0..string_vec.len(){
        // append data to a file
        &file.write_all( string_vec[x].as_bytes());
    }

}

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



pub fn compress_file( lines_vec : Vec<String> ){
    let mut compressed_vec : Vec<String> = vec![];
    let mut compressed_vec_index : usize = 0;
    
   
    
}