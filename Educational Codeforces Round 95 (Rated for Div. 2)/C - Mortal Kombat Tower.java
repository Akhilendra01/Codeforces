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
            boolean[] hard = new boolean[n];
            for(int i=0;i<n;i++)
            {
                hard[i] = scanner.nextInt() == 1;
            }
            
            int ans = hard[0]?1:0;
            for(int i=1;i<n;i++)
            {
                if(!hard[i])continue;
                int k;
                for(k=0;i+k<n&&hard[i+k];k++);
                ans += k/3;
                i += k-1;
            }
            System.out.println(ans);
        }
    }
}
