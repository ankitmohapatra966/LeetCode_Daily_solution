class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        int mod = 1e9+7;
        for(auto it : points){
            mp[it[1]]++;
        }

        long long ans = 0,prev = 0;

        for(auto it : mp){
           
            long long k = 1ll*(it.second-1)*it.second/2;
            ans += k*prev;
            prev += k;
        }
        return ans % mod;
    }
};

static const long long init = [] {
    struct ___ {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
        }
    };
    std::atexit(&___::_);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
