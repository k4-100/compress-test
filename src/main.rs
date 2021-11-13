use std::fs;

mod utl;

fn main() {
    // let mut input = String::new();
    // std::io::stdin().read_line( &mut input ).unwrap();

    let text : String = fs::read_to_string("res/test.txt").expect("shit broke");
    fs::write("test2.txt", &text).expect("writing broke");
    println!("{}", &text);
}
