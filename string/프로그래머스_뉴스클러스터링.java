import java.util.*;

class Solution {
    
    static HashSet<String> s = new HashSet<>();
    static HashMap<String, Integer> aClusterMap = new HashMap<>();
    static HashMap<String, Integer> bClusterMap = new HashMap<>();
    
    static public boolean alphaCheck(char c) {
        if(c >= 97 && c <= 122)
            return true;
        
        return false;
    }
    
    public int solution(String str1, String str2) {
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        String word = "";
        int aClusterCnt = 0;
        for(int i = 0; i < str1.length(); i++) {
            char c = str1.charAt(i);
            if(alphaCheck(c) == false) {
                word = "";
                continue;
            }
               
            word += c;
            if(word.length() == 2) {       
                if(aClusterMap.containsKey(word)) { 
                    int num = aClusterMap.get(word);
                    aClusterMap.put(word, ++num);          
                } else {
                    s.add(word);
                    aClusterMap.put(word, 1);
                }
                aClusterCnt++;
                word = "";
                i--;
            }        
        }
        
        word = "";
        int bClusterCnt = 0;
        for(int i = 0; i < str2.length(); i++) {
            char c = str2.charAt(i);
            if(alphaCheck(c) == false) {
                word = "";
                continue;
            }
               
            word += c;
            if(word.length() == 2) {
                if(s.contains(word)) {
                    if(bClusterMap.containsKey(word)) {
                        int num = bClusterMap.get(word);
                        bClusterMap.put(word, ++num);
                    } else {
                        bClusterMap.put(word, 1);
                    }
                }
        
                bClusterCnt++;
                word = "";
                i--;
            }        
        }
        
        double unionCnt = 0;       
        for (Map.Entry<String, Integer> entry : bClusterMap.entrySet()) {
            unionCnt += Math.min(aClusterMap.get(entry.getKey()), entry.getValue());
        }

        double answer = 0;
        double intersectionCnt = (double)(aClusterCnt + bClusterCnt - unionCnt);
        
        if(intersectionCnt == 0) {
            answer = 65536;
        }
        else if (unionCnt == 0) {
            answer = 0;   
        }
        else {
            answer = (unionCnt / intersectionCnt) * 65536;
        }
         
        return (int)answer;
    }
}