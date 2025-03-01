/// Determine the length of the collatz sequence beginning at `n`.
fn collatz_length(mut n: i32) -> u32 {
    if n <= 0 {
        println!("Input n must be greater tha zero");
        return 0;
    }

    let mut len = 1;

    while n != 1 {
        if n % 2 == 0 {
            // n is even
            n /= 2;
        } else {
            // n is odd
            n *= 3;
            n += 1;
        }
        len += 1;
    }
    len
}

fn main() {
    println!("Length: {}", collatz_length(11)); // should be 15
}
