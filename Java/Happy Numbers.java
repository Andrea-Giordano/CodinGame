import java.util.*;
import java.io.*;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        if (in.hasNextLine()) {
            in.nextLine();
        }
                
        HashSet<String> unhappy_set = new HashSet<String>();        
        for (int i = 0; i < N; ++i) {
            HashSet<String> set = new HashSet<String>();  
            String x = in.nextLine().trim();
            String der_x = x;
            int res = 0;
            
            while(!unhappy_set.contains(der_x) && !set.contains(der_x) && res!=1){
                set.add(der_x);
                res = Arrays.stream(der_x.split("")).map(Integer::parseInt).mapToInt((y)->(y*y)).sum();
                der_x = String.valueOf(res);
            }
            
            if(res!=1) unhappy_set.add(x);
            System.out.println(x+" :"+( (res==1) ? ")" : "("));            
            
        }        
    }
}
