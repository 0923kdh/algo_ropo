class Solution {
    
    static int[][][][] arr = new int[11][11][11][11];
    static int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int solution(String dirs) {
        
        int answer = 0;
        int y = 5, x = 5, ny = 0, nx = 0, index = 0;
        for(int i = 0; i < dirs.length(); i++) {
            if(dirs.charAt(i) == 'U') { 
                index = 0;
            } else if (dirs.charAt(i) == 'D') {
                index = 1;
            } else if (dirs.charAt(i) == 'R') {
                index = 2;
            } else {
                index = 3;
            }
            
            ny = dir[index][0];
            nx = dir[index][1];
            
            if(y + ny < 0 || y + ny > 10 || x + nx < 0 || x + nx > 10 ) {
                continue;
            }
            
            if(arr[x][y][x + nx][y + ny] == 0){
                arr[x][y][x + nx][y + ny] = 1;
                arr[x + nx][y + ny][x][y] = 1;
                answer++;
            }
            y += ny;
            x += nx;   
        }
        return answer;
    }
}