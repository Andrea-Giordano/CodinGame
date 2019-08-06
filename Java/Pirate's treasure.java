import java.util.*;
import java.io.*;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int W = in.nextInt();
        int H = in.nextInt();
        int[][] mat = new int[H+2][W+2];
        
        // Matrix population
        for (int i = 0; i <= H+1; i++) {
            for (int j = 0; j <= W+1; j++) {
                if(i==0 || j==0 || i==H || j==W){
                    mat[i][j]=1;
                }else{
                    int v = in.nextInt();
                    mat[i][j]=v;
                }
            }
        }
        
        
       for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if(mat[i][j]==0){
                    int sum = 0;
                    //explore neighborhood
                    goOn:
                    for(int k=-1;k<2;++k){
                        for(int z=-1;z<2;++z){
                            if(k!=0 || z!=0)
                                if(mat[i+k][j+z]==0)
                                    break goOn;
                                else
                                    sum += mat[i+k][j+z];
                        }     
                    }
                    if(sum == 8){
                        System.out.println((j-1)+" "+(i-1));
                        System.exit(0);
                    }
                }
            }
        }
    }
}
