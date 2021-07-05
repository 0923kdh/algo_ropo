import java.util.*;

class Solution {

	static int[] ans;
	static int[][] queries;
	static int[][] arr;
	
	public static int rotate(int y1, int x1, int y2, int x2) {
		Queue<Integer> q = new LinkedList<>();
        
		//1번째 구간
		for(int i = x1; i < x2; i++) {
			q.add(arr[y1][i]);
		} 
					
		//2번째 구간
		for(int i = y1; i < y2; i++) {
			q.add(arr[i][x2]);
		}

		//3번째 구간
		for(int i = x2; i > x1; i--) {
			q.add(arr[y2][i]);
		}
		
		//4번째 구간
		for(int i = y2; i > y1; i--) {
			q.add(arr[i][x1]);
		}
		
		int minValue = Integer.MAX_VALUE;
		while(q.size() > 0) {
			for(int i = x1; i < x2; i++) {
				minValue = Math.min(minValue, q.peek());
				arr[y1][i+1] = q.poll();
			}
							
			for(int i = y1; i < y2; i++) {
				minValue = Math.min(minValue, q.peek());
				arr[i+1][x2] = q.poll();
			} 
						
			for(int i = x2; i > x1; i--) {
				minValue = Math.min(minValue, q.peek());
				arr[y2][i-1] = q.poll();
			}
					
			for(int i = y2; i > y1; i--) {
				minValue = Math.min(minValue, q.peek());
				arr[i-1][x1] = q.poll();
			}
		}
        
		return minValue;
	}
    
    public int[] solution(int rows, int columns, int[][] queries) {
        ans = new int[queries.length];
		arr = new int[rows][columns];
        
        int num = 1;
        for(int i = 0; i < rows; i++) {
			for(int j = 0; j < columns; j++) {
				arr[i][j] = num++;
			}
		}
		
		for(int i = 0; i < queries.length; i++) {		
			ans[i] = rotate(queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
		}
		
        return ans;
    }
}