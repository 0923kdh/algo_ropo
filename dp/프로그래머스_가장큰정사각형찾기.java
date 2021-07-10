import java.util.*;

class Solution
{   
    public int solution(int [][]board) {
        int answer = 0, row = board.length, col = board[0].length;     
        int[][] arr = new int [row+1][col+1];
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                arr[i+1][j+1] = board[i][j];
            }
        }
        
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(arr[i][j] != 0) {
                    arr[i][j] = Math.min(Math.min(arr[i][j-1], arr[i-1][j]), arr[i-1][j-1]) + 1;
                    answer = Math.max(answer, arr[i][j]);
                }
            }
        }
        
        return answer * answer;
    }   
}