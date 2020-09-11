import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        double n = scanner.nextDouble();
        double m = scanner.nextDouble();
        double a = scanner.nextDouble();
        
        long w = (long)Math.ceil(n/a);
        long l = (long)Math.ceil(m/a);
        
        System.out.println(w*l);
    }
}
