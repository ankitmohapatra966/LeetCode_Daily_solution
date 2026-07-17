constexpr int Mx=5e4+1;

int Div[Mx];
long long GCD[Mx];
class Solution {
public:
    static vector<int> gcdValues(vector<int>& nums, vector<long long>& q) {
        const int n=nums.size();
        int M=0;
        for (int x : nums){
            M=max(M, x);
            Div[x]++;
        } 
        for(int x=1; x<=M; x++){
            for(int y=2*x; y<=M; y+=x)
                Div[x]+=Div[y];
        }

        for (int x=M; x>=1; x--) {
            long long cnt=Div[x];
            GCD[x]=cnt*(cnt-1LL)>>1; 
            for (int y=2*x; y<=M; y+=x) 
                GCD[x]-=GCD[y]; 
        }

        partial_sum(GCD, GCD+(M+1), GCD);
     
        int qz=q.size();
        vector<int> ans(qz);
        for (int i=0; i<qz; i++) {
            ans[i]=upper_bound(GCD, GCD+M+1, q[i])-GCD; 
        }
        memset(Div, 0, (M+1)*sizeof(int));
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
