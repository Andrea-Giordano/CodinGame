import java.util.*;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;


class Solution {
    
    private final static int ON = 1;
    private final static int OFF = 0;

    public static void main(String args[]) {
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int c = in.nextInt();
        int sum = 0;
        int maxSum = 0;
	    ArrayList<Integer> associatedCurrents = new ArrayList<Integer>();
	    HashMap<Integer, Integer> deviceStatus = new HashMap<Integer, Integer>();
	        
	    for (int i = 1; i <= n; i++) {
	        int nx = in.nextInt();
	        associatedCurrents.add(nx);
	        deviceStatus.put(i, OFF);
	    }
	        
	       
	    for (int i = 0; i < m; i++) {
	           
	      	int mx = in.nextInt();
	      	
	        if(deviceStatus.containsKey(mx)) {	
	           	int status = deviceStatus.get(mx) == ON? OFF:ON;
              	deviceStatus.put(mx, status);
              	
              	if(status==ON){
              	    sum += associatedCurrents.get(mx-1);
              	    if(sum > c){
              	        System.out.println("Fuse was blown.");
              	        System.exit(0);
              	    }
              	    maxSum = sum > maxSum?  sum : maxSum;
              	}else{
              	   sum -= associatedCurrents.get(mx-1);
              	}
	        }            
	     }
	        
		System.out.println("Fuse was not blown.");
        System.out.println("Maximal consumed current was "+maxSum+" A.");
    }
}
