import java.util.*;

public class test {
    static long go(int num)
    {
        long ans = 0;
        int len = 1;
        for(int start = 1; start <= num; start *= 10)
        {
            int end = start * 10 - 1;
            if(end > num)
                end = num;
            ans += (long)(end - start + 1) * len;
            len++;
        }

        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();

        if(go(n) < k)
        {
            System.out.println(-1);
            System.exit(0);
        }

        int left = 1;
        int right = n;
        int ans = 0;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(go(mid) < k)
            {
                left = mid + 1;
            }
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }

        String s = Integer.toString(ans);
        long l = go(ans);
        System.out.println(s.charAt(s.length()-(int)(l-k)-1));
    }
}