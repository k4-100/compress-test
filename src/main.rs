// use std::fs;
// use rand::Rng;
use std::fs::OpenOptions;
use std::io::Write;
mod utl;

fn main() {
    let big_string : Vec<String> = utl::generate_file( 1000000 );
    
    println!("{}",big_string[big_string.len()-1]);
    println!("{}",big_string.len());
    // utl::generate_file( 100 )
    
    // fs::write("res/test.txt", "CUM").expect("Shit broke");
    // fs::write("res/test.txt", "more cum").expect("Shit broke");
    let mut file = OpenOptions::new().append(true).open("res/test.txt").expect("Stuff to break");

    for _x in 0..big_string.len(){
        &file.write_all( big_string[_x].as_bytes());
    }

}
