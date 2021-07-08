import java.util.*;

class Solution {
    
    boolean solution(String s) {
        
        Stack<Character> stack = new Stack<>();
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(') {
                stack.add('(');
            } else {
                if(stack.empty()) {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
        
        return stack.empty();
    }
}