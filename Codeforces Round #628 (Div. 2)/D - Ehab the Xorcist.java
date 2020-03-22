import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Main {

    private static final Scanner sc = new Scanner(System.in);
    private static Long u,v,x;
    public static void main(String[] args){
        u = sc.nextLong();
        v = sc.nextLong();
        if(u > v || u%2 != v%2)
            System.out.println(-1);
        else if(v == 0)
            System.out.println(0);
        else if(u.equals(v))
            System.out.println("1\n"+v);
        else{
            x = (v - u) / 2;
            if(u == 0)
                System.out.println("2\n"+x+" "+x);
            else if((u&x) != 0)
                System.out.println("3\n"+u+" "+x+" "+x);
            else
                System.out.println("2\n"+(u+x)+" "+x);
        }
    }
}
