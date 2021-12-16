// use rand::Rng;
// use std::fs;
// use std::fs::OpenOptions;
// use std::io::Write;
mod utl;

fn main() {
    // let big_string : Vec<String> = utl::generate_file( 1 );
    
    let big_string : Vec<String> = utl::read_from_file_to_vector( "res/test.txt" );

    let compressed : Vec<String> = utl::compress_file( big_string );
    // "res/test.txt"


    utl::write_into_file( "res/test.cmps", compressed );

}
