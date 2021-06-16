import java.util.*;

public class Main {
    static int n;
    static int m;
    static long[] a;
    static boolean check(long mid)
    {
        int cnt = 0;
        for(int i = 0; i < a.length; i++)
        {
            cnt += a[i]/mid;
        }
        
        return cnt >= m;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        a = new long[n];
        long hi = 0;
        for(int i = 0; i < n; i++)
        {
            a[i] = sc.nextLong();
            hi = Math.max(hi, a[i]);
        }

        long ans = 0;
        long lo = 1;
        while(lo <= hi)
        {
            long mid = (lo + hi) / 2;
            if(check(mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        System.out.println(ans);
    }
}