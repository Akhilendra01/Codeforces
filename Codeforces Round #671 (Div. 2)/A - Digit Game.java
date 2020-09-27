import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-- > 0)
        {
            int n = scanner.nextInt();
            char[] nums = scanner.next().toCharArray();
            int ans = 1+(n%2);
            for(int i=1-(n%2);i<n;i+=2)
            {
                if(nums[i]%2 == n%2)
                {
                    ans = 2-(n%2);
                    break;
                }
            }
            System.out.println(ans);
        }
    }
}
