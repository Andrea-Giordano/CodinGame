import java.util.*;
import java.io.*;
import java.math.*;
import java.util.stream.*;

class Solution {
    
    private static final int MIN_T = 5;
    private static final int MAX_T = 30;
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int M = in.nextInt();
        if (in.hasNextLine()) {
            in.nextLine();
        }
        
        float estimationN60 = 0;
        float estimationN8 = 0;
                       
        String concatLine = "";
        for (int i = 0; i < M; i++) {
            String LINE = in.nextLine();
            estimationN60 += getTemperaturesN60(LINE);
            concatLine += LINE+" ";
        }
       
        estimationN60 = estimationN60/M;
        System.out.println(String.format(java.util.Locale.US,"%.1f", estimationN60));
        
        if(estimationN60 >= MIN_T && estimationN60 <= MAX_T){            
            estimationN8 = getTemperaturesN8(concatLine);
            System.out.println(String.format(java.util.Locale.US,"%.1f", estimationN8));
        }
        
    }
    
    
    public static float getTemperaturesN60(String LINE){
        String[] splittedLINE = LINE.split("\\s+");
        
        float sum = Stream.of(splittedLINE).map(Integer::valueOf).reduce(Integer::sum).get().intValue();
        
        return (10+(sum-40)/7); // N60 formula
    }
    
    public static float getTemperaturesN8(String LINE){
        String[] splittedLINE = LINE.split("\\s+");       
        
        int numOfGroups = (int)(Math.floor(splittedLINE.length/2));        
        splittedLINE = splittedLINE.length%2==0 ? splittedLINE : Arrays.copyOfRange(splittedLINE, 0, splittedLINE.length-1);
        
        float sum = Stream.of(splittedLINE).map(Integer::valueOf).reduce(Integer::sum).get().intValue();
            
        return (sum+(5*numOfGroups))/numOfGroups; //N8 formula
    }

    
}
