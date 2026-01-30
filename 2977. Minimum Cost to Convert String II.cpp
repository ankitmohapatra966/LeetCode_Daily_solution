class Solution {
public:
  using ll = long long;
  ll minimumCost(string &s, string &t, vector<string> &orig,
                 vector<string> &changed, vector<int> &cost) {
    unordered_map<string, int> id;
    using ull = unsigned long long;
    unordered_map<ull, int> mp;
    static constexpr ull P = 131;
    auto hash = [&](string& s) {
      ull h = 0;
      for (char ch : s)
        h = h * P + ch;
      return h;
    };
    vector<int> lens;
    int idx = 0;
    for (auto &s : orig)
      if (id.emplace(s, idx).second) {
        mp[hash(s)] = idx;
        idx++;
        lens.push_back(s.size());
      }
    for (auto &s : changed)
      if (id.emplace(s, idx).second) {
        mp[hash(s)] = idx;
        idx++;
        lens.push_back(s.size());
      }
    sort(lens.begin(), lens.end());
    lens.erase(unique(lens.begin(), lens.end()), lens.end());
    int n = orig.size();
    static constexpr ll INF = 4e18;
    vector<vector<ll>> dist(idx, vector<ll>(idx, INF));
    for (int i = 0; i < n; i++) {
      int u = id[orig[i]], v = id[changed[i]];
      dist[u][v] = min(dist[u][v], (ll)cost[i]);
    }
    n = idx;
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int k = 0; k < n ; k++)
      for (int i = 0; i < n; i++) {
        if (dist[i][k] == INF) continue;
        for (int j = 0; j < n; j++) {
          if (dist[k][j] == INF) continue;
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    int m = s.size();
    vector<ull> h1(m + 1), h2(m + 1), pow(m + 1);
    pow[0] = 1;
    for (int i = 0; i < m; i++)
      h1[i + 1] = h1[i] * P + s[i], h2[i + 1] = h2[i] * P + t[i], pow[i + 1] = pow[i] * P;
    auto hash_s = [&](int l, int r) {
      return h1[r + 1] - h1[l] * pow[r - l + 1];
    };
    auto hash_t = [&](int l, int r) {
      return h2[r + 1] - h2[l] * pow[r - l + 1];
    };

    vector<ll> f(m + 1, INF);
    f[m] = 0;
    for (int i = m - 1; i >= 0; i--) {
      if (s[i] == t[i]) f[i] = min(f[i], f[i + 1]);
      for (int len : lens) {
        if (i + len > m) break;
        if (auto ito = mp.find(hash_s(i, i + len - 1)), itc = mp.find(hash_t(i, i + len - 1));
            ito != mp.end() && itc != mp.end())
          f[i] = min(f[i], dist[ito->second][itc->second] + f[i + len]);
      }
    }
    return f[0] == INF ? -1 : f[0];
  }
};
