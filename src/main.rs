// use rand::Rng;
// use std::fs;
// use std::fs::OpenOptions;
// use std::io::Write;
mod utl;

fn main() {
    let big_string : Vec<String> = utl::generate_file( 1000000 );

    utl::write_into_file( big_string );
}
