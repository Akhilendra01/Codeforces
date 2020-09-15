import java.util.Scanner;
public class Main {
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int t = sc.nextInt();
       while(t-- > 0)
       {
           int n = sc.nextInt();
           int[] arr = new int[105];
           for(int i=0;i<n;i++)
           {
               arr[i] = sc.nextInt();
           }

           int[] cnt = new int[105];
           for(int i=0;i<n;i++)
           {
               cnt[arr[i]]++;
           }
           int ans = 0;
           for(int i=0;i<=100;i++)
           {
               if(cnt[i] == 0)
               {
                   ans += i;
                   break;
               }
               cnt[i]--;
           }
           for(int i=0;i<=100;i++)
           {
               if(cnt[i] == 0)
               {
                   ans += i;
                   break;
               }
               cnt[i]--;
           }
           System.out.println(ans);
       }
   }
}
