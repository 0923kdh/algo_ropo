import java.util.*;

public class Main {

    static boolean check(int mid, int c, int[] arr)
    {
        int cnt = 1;
        int last = arr[0];
        for(int house : arr)
        {
            if(house - last >= mid)
            {
                cnt+=1;
                last = house;
            }
        }
        return cnt >= c;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
        {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);

        int ans = 0, lo = 1, hi = a[n-1] - a[0];
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(check(mid, c, a.clone()))
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