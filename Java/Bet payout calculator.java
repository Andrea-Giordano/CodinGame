import java.util.*;
import java.io.*;
import java.math.*;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        int sides = in.nextInt();
        TreeMap<Integer,Double> betGains = new TreeMap<Integer,Double>(); //maintains the order of dice faces
        double loss[] = new double[sides];
        double wins[] = new double[sides]; 
                
        for (int i = 0; i < sides; ++i) {            
            betGains.put(in.nextInt(),0.00);
            
            double multiplier = in.nextDouble();
            wins[i] = in.nextDouble(); 
            loss[i] = wins[i]*multiplier;
        }
        
        double sumOfWins = Arrays.stream(wins).parallel().sum(); // Sum of money got by players betting        
        
        for(Integer key : betGains.keySet()){
           betGains.put(key, sumOfWins-loss[key-1]-wins[key-1]); // when the dice is rolled, the bet host takes all the money got but the loss and the money bet collected before for the specific player
        }
        
        double max = betGains.firstEntry().getValue();
        int maxIndex = 1;
        for(Map.Entry<Integer,Double> entry : betGains.entrySet()){
            if(entry.getValue() > max){
                max = entry.getValue();
                maxIndex = entry.getKey();
            }
        }
        
        BigDecimal bigDecMax = new BigDecimal(max);
        System.out.println(maxIndex +" "+ bigDecMax.setScale(2, RoundingMode.HALF_UP));
    }
}
