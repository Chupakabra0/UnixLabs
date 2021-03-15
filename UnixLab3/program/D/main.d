import std.stdio, std.conv;

double Sum(immutable double first, immutable double second) {
    return first + second;
}

int main(string[] args) {
    if (args.length < 3) {
        stdout.writeln("Not enough args to complete the program!");
        return 0;
    }

    try {
        immutable first  = parse!double(args[1]);
        immutable second = parse!double(args[2]);

        stdout.writefln!"%s + %s = %s"(first, second, Sum(first, second));
    }
    catch(Exception) {
        stdout.writeln("Parse error...");
    }

    return 0;
}
