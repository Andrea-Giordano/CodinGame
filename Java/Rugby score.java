https://www.codingame.com/training/easy/rugby-score

import java.util.*;
import java.io.*;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int score = in.nextInt();
                
        // Calculate combination for each try number
        int maxIterations = (int) score/5;
        for(int tries=0; tries<=maxIterations; ++tries){
                        
            int unsuccessfulKicks = score-(5*tries);                                
            for(int tKicks=0; tKicks <= tries && unsuccessfulKicks>=0; ++tKicks){                
                
                int leftPoints = unsuccessfulKicks-(2*tKicks);
                if( leftPoints%3 == 0 && leftPoints >= 0){
                    System.out.println(tries+" "+tKicks+" "+ (int) leftPoints/3);
                }
            }           
        }
    }    
}
