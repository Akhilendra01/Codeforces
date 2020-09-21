import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-- > 0)
        {
            long x = scanner.nextLong();
            long y = scanner.nextLong();
            long k = scanner.nextLong();
            long sticksNeeded = (y+1) * k - 1;
            long rem = sticksNeeded % (x-1) != 0 ?1:0;
            long trades = sticksNeeded / (x-1) + rem + k;
            System.out.println(trades);
        }
    }
}
