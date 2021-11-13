use std::fs;

mod utl;

fn main() {
    // let mut input = String::new();
    // std::io::stdin().read_line( &mut input ).unwrap();

    let text : String = fs::read_to_string("test.txt").expect("shit broke");

    println!("{}",text);
}
