const std = @import("std");
const rand = std.crypto.random;

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();
    const number = rand.intRangeLessThan(u8, 0, 255);

    while (true) {
        try stdout.writeAll("Guess a number between 0 and 254: ");

        const bare_line = try stdin.readUntilDelimiterAlloc(std.heap.page_allocator, '\n', 8000);
        defer std.heap.page_allocator.free(bare_line);
        const line = std.mem.trim(u8, bare_line, &[_]u8{'\r'});

        const guess = std.fmt.parseInt(u8, line, 10) catch |err| switch (err) {
            error.Overflow => {
                try stdout.writeAll("Please enter a small positive integer\n");
                continue;
            },
            error.InvalidCharacter => {
                try stdout.writeAll("Please enter a valid number\n");
                continue;
            },
        };

        if (guess < number) {
            try stdout.writeAll("Too small\n");
        } else if (guess > number) {
            try stdout.writeAll("Too big\n");
        } else {
            try stdout.writeAll("Correct!\n");
            break;
        }
    }
}
