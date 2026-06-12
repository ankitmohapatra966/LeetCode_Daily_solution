const int MX = 100001;
const int MOD = 1e9 + 7;

long long fac[MX], inv_fac[MX];

void precompute() {
    if (fac[0] == 1) return;
    fac[0] = 1;
    for (int i = 1; i < MX; i++) fac[i] = fac[i-1] * i % MOD;
    inv_fac[MX-1] = 1;
    long long base = fac[MX-1], exp = MOD - 2, result = 1, mod = MOD;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    inv_fac[MX-1] = result;
    for (int i = MX - 2; i >= 0; i--) inv_fac[i] = inv_fac[i+1] * (i+1) % MOD;
}

class Solution {
    int n;
    vector<vector<int>> g;
    vector<vector<pair<int,int>>> q;
    vector<int> lca_ans, deep, uf;
    vector<bool> vis;

    int find(int x) {
        while (uf[x] != x) {
            uf[x] = uf[uf[x]];
            x = uf[x];
        }
        return x;
    }

    void tarjan(int u, int parent) {
        vis[u] = true;
        for (int v : g[u]) {
            if (v == parent) continue;
            tarjan(v, u);
            uf[v] = u;
        }
        for (auto [node, idx] : q[u]) {
            if (vis[node]) lca_ans[idx] = find(node);
        }
    }

    void dfs(int u, int fa, int d) {
        deep[u] = d;
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs(v, u, d + 1);
        }
    }

    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        precompute();

        n = edges.size() + 1;
        g.assign(n + 1, {});
        q.assign(n + 1, {});
        lca_ans.assign(queries.size(), 0);
        deep.assign(n + 1, 0);
        uf.resize(n + 1);
        iota(uf.begin(), uf.end(), 0);
        vis.assign(n + 1, false);

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < (int)queries.size(); i++) {
            q[queries[i][0]].emplace_back(queries[i][1], i);
            q[queries[i][1]].emplace_back(queries[i][0], i);
        }

        tarjan(1, 0);
        dfs(1, 0, 0);

        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int x = deep[queries[i][0]] + deep[queries[i][1]] - 2 * deep[lca_ans[i]];
            ans[i] = (x == 0) ? 0 : (int)power(2, x - 1, MOD);
        }
        return ans;
    }
};

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[200 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}
