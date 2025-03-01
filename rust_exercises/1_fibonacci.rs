fn fib(n: u32) -> u32 {
    if n < 2 {
        // The base case.
        n
    } else {
        // The recursive case.
        let mut previous: u32 = 0;
        let mut current: u32 = 1;

        for _ in 2..=n {
            let new = previous + current;
            previous = current;
            current = new;
        }
        current
    }
}
fn main() {
    let n = 20;
    println!("fib({n}) = {}", fib(n));
}

