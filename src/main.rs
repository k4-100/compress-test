mod utl;
use std::env;


fn main() {
    let args: Vec<String> = env::args().collect();
    println!("args: {:?}", args);
    
    let mut big_string: Vec<String>;

    match args[1].as_str(){
        "g" => {
            let mut lines: u32 = 1000;
            
            if args.len() > 2 {
                lines = args[2].parse().expect("Failed parsing");
            }
            
            big_string = utl::generate_file(lines);
            utl::write_into_file("res/test.txt", big_string);
        },
        "c" => {
            big_string = utl::read_from_file_to_vector("res/test.txt");
            big_string = utl::compress_file( big_string );
            utl::write_into_file("res/test.cmps", big_string);
        },
        "d" => {
            big_string = utl::read_from_file_to_vector("res/test.cmps");
            big_string = utl::decompress_file( big_string );
            utl::write_into_file("res/test.dcmps", big_string);
        },
        
        _ => println!("Broke")
    }
}


  // let mut big_string : Vec<String> = utl::generate_file( 1000000 );
    // utl::write_into_file("res/test.txt", big_string);
    
    // let mut  big_string : Vec<String>;

    // // big_string  = utl::read_from_file_to_vector( "res/test.txt" );
    // // let compressed  = utl::compress_file( big_string.clone() );

    // // utl::write_into_file("res/test.cmps", compressed);

    // big_string = utl::read_from_file_to_vector( "res/test.cmps" ); 

    // let decompressed = utl::decompress_file( big_string );
    
    // utl::write_into_file("res/test.dcmps", decompressed);