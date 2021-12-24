// use rand::Rng;
// use std::fs;
// use std::fs::OpenOptions;
// use std::io::Write;
mod utl;

fn main() {
    // let mut big_string : Vec<String> = utl::generate_file( 100 );
    // utl::write_into_file("res/test.txt", big_string);
    
    let mut  big_string : Vec<String>;

    // big_string  = utl::read_from_file_to_vector( "res/test.txt" );
    // let compressed  = utl::compress_file( big_string.clone() );

    // utl::write_into_file("res/test.cmps", compressed);

    big_string = utl::read_from_file_to_vector( "res/test.cmps" ); 

    let decompressed = utl::decompress_file( big_string );
    
    utl::write_into_file("res/test.dcmps", decompressed);
}
