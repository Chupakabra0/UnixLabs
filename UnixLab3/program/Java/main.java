public class main {
    public static double Sum(double first, double second) {
        return first + second;
    }
    
    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Not enough args to complete the program!");
            return;
        }

        try {
            Double first  = Double.parseDouble(args[0]);
            Double second = Double.parseDouble(args[1]);

            System.out.format("%s + %s = %s\n", first, second, main.Sum(first, second));
        }
        catch (Exception exception) {
            System.out.println("Parse error...");
        }
    }
}
