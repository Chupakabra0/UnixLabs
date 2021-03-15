using System;
using System.Globalization;

namespace Main {
    internal static class Operations {
	internal static double Sum(double first, double second) {
            return first + second;
        }
    }

    internal class Program {
        internal static int Main(string[] args) {
            if (args.Length < 2) {
                Console.WriteLine("Not enough args to complete the program");
                return 0;
            }

            try {
                var first  = Convert.ToDouble(args[0], CultureInfo.InvariantCulture);
                var second = Convert.ToDouble(args[1], CultureInfo.InvariantCulture);

                Console.WriteLine($"{first} + {second} = {Operations.Sum(first, second)}");
            }
            catch (Exception) {
                Console.WriteLine("Parse error...");
            }

            return 0;
	}
    }
}
