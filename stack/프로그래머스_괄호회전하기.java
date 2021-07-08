import java.util.*;

class Solution {

    static public boolean right(String str) {
        Stack<Character> s = new Stack<>(); 
        char c1, c2;
        for(int i = 0; i < str.length(); i++) {
            c1 = str.charAt(i);        
            if(c1 == '{' || c1 == '(' || c1 == '[') {
                s.add(c1);
                continue;
            } 
           
            if(s.empty())
                return false;
            
            c2 = s.peek();
            if(c2 == '{' && c1 == '}') {
                s.pop();    
            } else if(c2 == '(' && c1 == ')') {
                s.pop();    
            } else if(c2 == '[' && c1 == ']') {
                s.pop(); 
            } else {
                return false;
            }                         
        }
             
        return s.empty();
    }
    
    public int solution(String s) {
        int answer = 0;
        
        StringBuilder tempStr = new StringBuilder(s);
        for(int i = 0; i < s.length(); i++) {
            tempStr.append(tempStr.charAt(0)).deleteCharAt(0);         
            if(right(tempStr.toString()))
                answer++;
        }
      
        return answer;
    }
}