import java.util.*;
import java.io.*;
import java.lang.Character;

class Solution {

    private final static int ISBN_10_DIGIT = 10;
    private final static int ISBN_13_DIGIT = 13;
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        if (in.hasNextLine()) {
            in.nextLine();
        }
        
        ArrayList<String> invalidISBN = new ArrayList<String>();
        int numOfInvalids = 0;
        
        for (int i = 0; i < N; i++) {
            String ISBN = in.nextLine();
            
            if(!checkISBNValidity(ISBN)){
                numOfInvalids++;
                invalidISBN.add(ISBN);
            }   
        }

        
        System.out.println(numOfInvalids + " invalid:");
        int i=0;
        while(numOfInvalids > 0){
            System.out.println(invalidISBN.get(i));
            i++;
            numOfInvalids--;
        }
    }
    
    
    
    public static boolean checkISBNValidity(String ISBN){
            //check on length 
            if(ISBN.length()!=ISBN_10_DIGIT && ISBN.length()!=ISBN_13_DIGIT) return false;
            //check if it contains invalid chars    
            if(ISBN.length()==ISBN_10_DIGIT && ISBN.charAt(ISBN_10_DIGIT-1) != 'X' && (ISBN.charAt(ISBN_10_DIGIT-1) < '0' || ISBN.charAt(ISBN_10_DIGIT-1) > '9')) return false; 
            if(ISBN.length()==ISBN_13_DIGIT && ISBN.charAt(ISBN_13_DIGIT-1) != 'X' && (ISBN.charAt(ISBN_13_DIGIT-1) < '0' || ISBN.charAt(ISBN_13_DIGIT-1) > '9')) return false;
              
            if(ISBN.length()==ISBN_10_DIGIT){              
             
                int sum = 0;
                for(int i=0;i<9;++i){
                    //check if it contains invalid chars in the middle
                    if(Character.isLetter(ISBN.charAt(i)))
                        return false;
                    
                    sum += (ISBN.charAt(i)-'0')*(ISBN.length()-i);
                }
            
                int added = 0;                
                while(sum%11!=0){
                   sum++;
                   added++;
                }
                
                char addedChar = added>9 ? 'X' : (char)(added+'0');
                
                return (addedChar!=ISBN.charAt(ISBN.length()-1)) ? false : true;
            }else{
                
                int sum = 0;
                for(int i=0;i<12;++i){
                    //check if it contains invalid chars in the middle
                    if(Character.isLetter(ISBN.charAt(i)))
                        return false;
                
                    int mul = (i+1)%2==0 ? 3:1;
                   
                    sum += (ISBN.charAt(i)-'0')*mul;
                 }
            
                int added = 0;                
                while(sum%10!=0){
                   sum++;
                   added++;
                }
                
                char addedChar = (char)(added+'0');
            
                return (addedChar!=ISBN.charAt(ISBN.length()-1))? false : true;
            }
        }
     
    }
