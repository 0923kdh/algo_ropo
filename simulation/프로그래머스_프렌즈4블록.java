import java.util.*;

class Solution {
    
    static public char[][] map;
    
    static class Pos {
        int y, x;
        Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    public int solution(int m, int n, String[] board) {
 
        map = new char[m][n];
        Queue<Pos> q = new LinkedList<>();
        for(int i = 0; i < m; i++){
            map[i] = board[i].toCharArray();
        }
        
        while(true) {
            for(int i = 0; i < m - 1; i++) {
                for(int j = 0; j < n - 1; j++) {
                    if(map[i][j] == '0')
                		continue;
                    
                    char c1 = map[i][j];
                    char c2 = map[i][j+1];
                    char c3 = map[i+1][j];
                    char c4 = map[i+1][j+1];
                    
                    if((c1 == c2) && (c1 == c3) && (c1 == c4)) {
                        q.add(new Pos(i, j));
                        q.add(new Pos(i, j+1));
                        q.add(new Pos(i+1, j));
                        q.add(new Pos(i+1, j+1));            
                    }             
                }
            }
            
            if(q.size() == 0)
                break;
            
            while(q.size() != 0) {
                Pos pos = q.poll();
                map[pos.y][pos.x] = '0';
            }
            
            for(int j = 0; j < n; j++) {
                int cnt = 0;
                String temp = "";
                for(int i = m - 1; i >= 0; i--) {
                    if(map[i][j] == '0') {
                        cnt++;
                    } else {
                        temp += map[i][j];
                    }
                }
                
                while(cnt > 0) {
                    temp += '0';
                    cnt--;
                }
 
                for(int k = 0; k < temp.length(); k++) {
                    map[temp.length()-k-1][j] = temp.charAt(k);
                }
            }
        }

        int answer = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == '0')
                    answer++;
            }
        }
       
        return answer;
    }
}