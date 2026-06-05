class Solution {
public:
    long long solve(long long x) {
        long long ans = 0;
        for (long long left = x / 10, right = x % 10, p10 = 1; left >= 10;) {
            int d = left % 10, dl = left / 10 % 10, dr = right / p10;
            left /= 10;
     
            bool peak = d > dl && d > dr, valley = d < dl && d < dr;
            if (valley) {
                ans += right - p10 * (d+1);
            }
            if (peak) {
                ans += right;
            }
            if (d > dl && d <= dr) {
                ans += p10 * d;
            }
          
            int up = 9-min(d, dl);
            ans += (45 - up*(up+1)/2) * p10;
            if (d > dl)
                ans += (d*(d-1)/2 - dl*(dl+1)/2) * p10;
         
            int upl = 9-dl;
            ans += (dl*90 - dl*(dl+1)*(dl-1)/6 - 9*10*11/6 + upl*(upl+1)*(upl+2)/6)
            * p10;
            if (left < 10)
                ans -= 45 * p10;

            ans += (900 - 9*10*11/3) * (left/10) * p10;
            if (left >= 10)
                ans -= 45 * p10;
            p10 *= 10, right += d * p10;
        }
        return ans;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2+1) - solve(num1);
    }
};
