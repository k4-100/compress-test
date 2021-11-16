use rand::Rng;

pub fn generate_file( lines : u32 ) -> String {
    let mut  v : Vec<String> = vec![]; 


    let mut buf : String = String::with_capacity(200);

    // for _x in 0..lines{
        for _y in 0..18
        {
            let current_len : u8 = rand::thread_rng().gen_range(1..(10+1)) as u8;
            for _z in 0..current_len
            {
                buf.push( rand::thread_rng().gen_range(65..(77+1)) as u8 as char );
            }
        }
    // }

    

    return buf;
}