// use rand::Rng;
use std::fs;
use std::fs::OpenOptions;
use std::io::Write;
mod utl;

fn main() {
    let big_string : Vec<String> = utl::generate_file( 1000000 );
    
    println!("{}",big_string[big_string.len()-1]);
    println!("{}",big_string.len());
    
    fs::write("res/test.txt","").expect("clean-up failed");
    let mut file = OpenOptions::new()
        .create(true)
        .append(true)
        .open("res/test.txt")
        .expect("Stuff to break");

    
    for x in 0..big_string.len(){
        // append data a file
        &file.write_all( big_string[x].as_bytes());
    }

}
