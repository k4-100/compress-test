mod utl;

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line( &mut input ).unwrap();

    utl::read_from_file( &input );
}
