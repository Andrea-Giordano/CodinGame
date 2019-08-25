import java.util.*;
import java.util.stream.*;
import java.io.*;
import java.math.*;


class Solution {

    private static final int FIRST_PART_POSSIBILITIES = 10;
    private static final int SECOND_PART_POSSIBILITIES = 5;

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int robbers = in.nextInt();
        int vaults = in.nextInt();
        int[] secondsRequired = new int[vaults];
        int heistTime = -1;
        
        for (int i = 0; i < vaults; ++i) {
            int C = in.nextInt();
            int N = in.nextInt();
            
            secondsRequired[i] = (int) (Math.pow(FIRST_PART_POSSIBILITIES, N) * Math.pow(SECOND_PART_POSSIBILITIES, C-N));                          
            if(secondsRequired[i] > heistTime) heistTime = secondsRequired[i];
        }
                
        if(robbers < vaults) {
            int nextFree = robbers;

            ArrayList<Integer> busySafeboxes = new ArrayList<Integer>(Arrays.stream(secondsRequired).boxed().limit(robbers).collect(Collectors.toList()));              
            Integer min = busySafeboxes.parallelStream().min(Integer::compare).get();            
            Integer max = busySafeboxes.parallelStream().max(Integer::compare).get();
            
            while(nextFree < vaults){                
                busySafeboxes.set(busySafeboxes.indexOf(min), min + secondsRequired[nextFree]);

                if(min + secondsRequired[nextFree] > max){
                    max = min + secondsRequired[nextFree];                   
                }
                     
                nextFree++;   
                min = busySafeboxes.parallelStream().min(Integer::compare).get();
            }
            
            heistTime = max;
        }

        System.out.println(heistTime);
    }
}
