import java.util.*;

public class Main {
	
	public static int[] dp;
	
	public static int go(int n) {
		//기저사례 
		if(n == 1)
			return 0;
		
		//메모이제이션
		if(dp[n] > 0)
			return dp[n];
		
		//로직
		dp[n] = go(n-1) + 1;
		if(n % 2 == 0) {
            int temp = go(n/2) + 1;
            if(dp[n] > temp)
                dp[n] = temp;
		}
		
		if(n % 3 == 0) {
			int temp = go(n/3) + 1;
            if(dp[n] > temp)
                dp[n] = temp;
		}
		
		return dp[n];
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		dp = new int[n+1];
		System.out.println(go(n));	
	}
}