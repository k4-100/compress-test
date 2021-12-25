mod utl;
use std::env;


fn main() {
    let args: Vec<String> = env::args().collect();
    println!("args: {:?}", args);
    
    


    match args[1].as_str(){
        "g" => println!("generating..."),
        "c" => println!("compressing..."),
        "d" => println!("decompressing..."),
        
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