import java.util.*;
import java.util.stream.*;
import java.math.*;

class Solution {
    private static final int RESULT_POS = 0;
    private static final int CALL_POS = 1;
    private static final int BET_POS = 2;
    
    private static final int PLAIN_WIN_FACTOR = 35;
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int ROUNDS = in.nextInt();
        int CASH = in.nextInt();
        
        if (in.hasNextLine()) {
            in.nextLine();
        }
        
        for (int i = 0; i < ROUNDS; ++i) {
            String PLAY = in.nextLine();
            
            String[] splitted = Arrays.stream(PLAY.split("\\s+")).map(String::trim).toArray(String[]::new);
            int result = Integer.parseInt(splitted[RESULT_POS]);
            int betCall = (int) Math.ceil(CASH/4.0);

            switch(splitted[CALL_POS].charAt(0)){
            
            case 'E':
                CASH += (result%2==0 && result!=0) ? betCall : -betCall; 
                break;
            case 'O':
                CASH += (result%2!=0 || result==0) ? betCall : -betCall; 
                break;
            case 'P':
                CASH += (result==Integer.parseInt(splitted[BET_POS])) ? betCall*PLAIN_WIN_FACTOR : -betCall; 
                break;
            default:
                continue;
            }
        }
  
        System.out.println(CASH);
    }
}
