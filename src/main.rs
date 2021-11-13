// use std::fs;

use rand::Rng;
mod utl;

fn main() {
    // let mut input = String::new();
    // std::io::stdin().read_line( &mut input ).unwrap();

    // let text : String = fs::read_to_string("res/test.txt").expect("shit broke");
    // fs::write("test2.txt", &text).expect("writing broke");
    // println!("{}", &text);

    let mut v: Vec< &str > = vec![];

    v.push( "char ain't here" );



    (0..30).for_each( |_|  println!("{:?}", &rand::thread_rng().gen_range(15..(30+1)) ) );
        
    
    
}
