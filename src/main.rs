// use rand::Rng;
// use std::fs;
// use std::fs::OpenOptions;
// use std::io::Write;
mod utl;

fn main() {
    // let mut big_string : Vec<String> = utl::generate_file( 1000000 );
    
    let mut big_string : Vec<String>;
    // utl::write_into_file("res/test.txt", big_string);

    big_string  = utl::read_from_file_to_vector( "res/test.txt" );

    let compressed  = utl::compress_file( big_string );
    // "res/test.txt"


    utl::write_into_file( "res/test.cmps", compressed );

}
