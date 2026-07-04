class Solution {
public:
struct DSU {
 
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]); 
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        p[b] = a;
        sz[a] += sz[b];
    }
};
    static bool cmp(vector<int>&a, vector<int> &b) {
        return a[2] <= b[2];
    }
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);
        for(auto &e : roads) dsu.unite(e[0], e[1]); 

        int comp = dsu.find(1); 
        int ans = INT_MAX; 

        for(auto &e : roads) { 
            if(dsu.find(e[0]) == comp) ans = min(ans, e[2]);
        }

        return ans;


    }
};
