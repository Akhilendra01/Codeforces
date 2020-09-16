import java.util.Scanner;
import java.util.Arrays;
public class Main {
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int t = sc.nextInt();
       while(t-- > 0)
       {
            int n = sc.nextInt();
            int[] arr = new int[n];
            Long max = 1L;
            for(int i=0;i<n;i++)
            {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);
            Long two = new Long(arr[0] * arr[1]);
            Long four = two * new Long(arr[2] * arr[3]);
            Long one = new Long(arr[n-1]);
            Long three = new Long(arr[n-3] * arr[n-2]) * one;
            Long five = new Long(arr[n-5] * arr[n-4]) * three;
            max = Math.max(
                Math.max(five,one*four),
                two*three
            );
            System.out.println(max);
       }
   }
}
