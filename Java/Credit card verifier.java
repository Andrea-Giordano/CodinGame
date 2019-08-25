import java.util.*;
import java.util.stream.IntStream;
import java.io.*;

class Solution {

    private static final int CARD_NUM_LENGTH_WITH_SPACES = 19;
    private static final int CARD_NUM_LENGTH = 16;

    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (in.hasNextLine()) { in.nextLine(); }
        
        IntStream.range(0, n).forEach(i -> System.out.println(validate(in.nextLine())));
    }
    
    
    public static String validate(String card){
        
        if(card.trim().length()!=CARD_NUM_LENGTH_WITH_SPACES)
            return "NO";
            
        card = card.trim().replaceAll("\\s+","");
        
        ArrayList<Integer> evenNumbers = new ArrayList<Integer>();
        ArrayList<Integer> oddNumbers = new ArrayList<Integer>();

        for(int i=CARD_NUM_LENGTH-1; i>=0 ;--i){
            if(i%2==0){
               evenNumbers.add(card.charAt(i) - '0');
            }else{
               oddNumbers.add(card.charAt(i) - '0');
            }
        }
                 
        int step1Sum = evenNumbers.parallelStream().map(x->x*2).mapToInt(x-> (x>9) ? x-=9:x).sum();
        int step2Sum = oddNumbers.parallelStream().reduce(0, Integer::sum);
        
        return ( (step1Sum+step2Sum) % 10 == 0 ) ? "YES" : "NO";
    }
}
