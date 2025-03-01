const std = @import("std");

fn addition(a: i32, b: i32) i32 {
    return a + b;
}

fn subtraction(a: i32, b: i32) i32 {
    return a - b;
}

fn multiplication(a: i32, b: i32) i32 {
    return a * b;
}

fn division(a: i32, b: i32) i32 {
    // Use @divTrunc to match C "/" behaviour
    return @divTrunc(a, b);
}

pub fn main() void {
    std.debug.print("10 + 90 = {}\n", .{addition(10, 90)});
    std.debug.print("10 - 90 = {}\n", .{subtraction(10, 90)});
    std.debug.print("10 * 90 = {}\n", .{multiplication(10, 90)});
    std.debug.print("10 : 90 = {}\n", .{division(10, 90)});
}
