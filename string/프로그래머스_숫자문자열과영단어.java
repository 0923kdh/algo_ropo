class Solution {
    public int solution(String s) {
        String[] alpha = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
 
        for(int i = 0; i <= 9; i++) {
            s = s.replaceAll(alpha[i], String.valueOf(i));
        }
        return Integer.parseInt(s);
    }
}