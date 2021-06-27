import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n+1];
		int[] dp = new int[n+1];
		
		Arrays.fill(dp, Integer.MAX_VALUE);
		
		for(int i = 1; i <=n; i++) {
			a[i] = sc.nextInt();
		}
		dp[0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
				dp[i] = Math.min(dp[i], dp[i-j]+a[j]);
			}
		}
		System.out.println(dp[n]);
	}
}