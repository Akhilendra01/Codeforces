import java.util.Scanner;
import java.util.*;
public class Main {
    private static int n,min,leaf,centroid1,centroid2;
    private static int[] size = new int[100005];
    private static int[] parents = new int[100005];
    private static ArrayList<Integer>[] neighbors = new ArrayList[100005];

    private static void dfs(int node,int parent){
        parents[node]=parent;
        size[node]=1;
        int max=0;
        for(int neighbor:neighbors[node]){
            if(neighbor==parent)continue;
            dfs(neighbor,node);
            size[node]+=size[neighbor];
            max=Math.max(max,size[neighbor]);
        }
        max=Math.max(max,n-size[node]);
        if(max<min)
        {
            min=max;
            centroid1=node;
            centroid2=0;
        }
        else if(max==min)
            centroid2=node;
    }
    private static void dfs2(int node,int parent){
        if(neighbors[node].size()==1){
            leaf=node;
            return ;
        }
        for(int neighbor:neighbors[node]){
            if(neighbor==parent)continue;
            dfs2(neighbor,node);
        }
    }

   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int t = sc.nextInt();
       while(t-- > 0)
       {
            n = sc.nextInt();
            centroid1=centroid2=0;
            min=Integer.MAX_VALUE;
            for(int i=1;i<=n;i++)
            {
                neighbors[i] = new ArrayList<Integer>();
                parents[i] = 0;
            }
            for(int i=1;i<n;i++){
                int x = sc.nextInt(),y = sc.nextInt();
                neighbors[x].add(y);
                neighbors[y].add(x);
            }
            dfs(1,0);
            if(centroid2 == 0){
                System.out.println("1 "+neighbors[1].get(0));
                System.out.println("1 "+neighbors[1].get(0));
                continue;
            }
            if(parents[centroid1]!=centroid2)
            {
                int temp = centroid1;
                centroid1 = centroid2;
                centroid2 = temp;
            }
            dfs2(centroid1,centroid2);
            System.out.println(leaf+" "+parents[leaf]);
            System.out.println(leaf+" "+centroid2);
       }
   }
}
