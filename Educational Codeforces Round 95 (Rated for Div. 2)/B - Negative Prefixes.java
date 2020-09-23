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
            int[] nums = new int[n];
            for(int i=0;i<n;i++)
            {
                nums[i] = scanner.nextInt();
            }
            boolean[] locked = new boolean[n];
            for(int i=0;i<n;i++)
            {
                locked[i] = scanner.nextInt() == 1;
            }
            
            PriorityQueue<Integer> unlocked = new PriorityQueue<Integer>(); 
            for(int i=0;i<n;i++)
            {
                if(!locked[i])
                {
                    unlocked.add(nums[i]);
                }
            }
            for(int i=n-1;i>=0;i--)
            {
                if(!locked[i])
                {
                    nums[i] = unlocked.poll();
                }
            }
            for(int i=0;i<n;i++)
            {
                System.out.print(nums[i]+" ");
            }
            System.out.println();
        }
    }
}
