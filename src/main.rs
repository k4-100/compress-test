// use rand::Rng;
// use std::fs;
// use std::fs::OpenOptions;
// use std::io::Write;
mod utl;

fn main() {
    // let big_string : Vec<String> = utl::generate_file( 1000 );
    

    // utl::write_into_file( big_string );


    let big_string : Vec<String> = utl::read_from_file_to_vector();

    utl::compress_file( big_string );

    // println!("{:?}",big_string);

    // utl::write_into_file( big_string );

    // let s  = "a".to_string() + "sda" + "sa";
   
    // println!("{}", s);

    // let read_vec = utl::read_from_file_to_vector();

    // println!("{}", read_vec.len());
   
    

    // .split("a").collect::<Vec<&str>>();

    // println!("{:?}", content);
}
