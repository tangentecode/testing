// Own implementation of the Fibonnaci sequence using zig
const std = @import("std");

fn fibonaci(n: u32) u32 {
    // The base case
    if (n == 1 or n == 0) {
        return n;
    }

    var previous: u32 = 0;
    var current: u32 = 1;
    var next: u32 = 0;

    // Recursive case
    var i: u8 = 2;
    while (i <= n) : (i += 1) {
        next = previous + current;
        previous = current;
        current = next;
    }
    return next;
}

pub fn main() void {
    const n: u32 = 10;
    std.debug.print("The {d}nth Fibonnaci number is {d}\n", .{ n, fibonaci(n) });
}
