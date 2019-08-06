import java.util.*;
import java.io.*;
import java.util.Stack;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String expression = in.next();
        
		Stack<String> stack = new Stack<String>();
		String result = "false";
		
		for(int i=0;i<expression.length();++i) {
			switch(expression.charAt(i)) {
			
			case '(':
				stack.add(")");
				break;
			case '[':
				stack.add("]");
				break;
			case '{':
				stack.add("}");
				break;
			case ')':
			case ']':
			case '}':
				if(stack.isEmpty() || stack.peek().charAt(0)!=expression.charAt(i)) break;
				stack.pop();
			}
		}
		
		if(stack.isEmpty()) result = "true";
		
		System.out.println(result);
	
	}
}
