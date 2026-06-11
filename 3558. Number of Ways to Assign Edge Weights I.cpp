struct Solution {
    static constexpr unsigned assignEdgeWeights(const std::vector<std::vector<int>>& edges) {
        static constexpr unsigned modulo = 1'000'000'007;

        unsigned n = edges.size() + 1u;
        auto storage = std::make_unique<unsigned[]>(n*3u);
        unsigned* const neighbour_count = storage.get();
        unsigned* const neighbour_xorsum = neighbour_count + n;
        unsigned* q_end = neighbour_xorsum + n;
        const unsigned* q_begin = q_end;

        for (std::span<const int> edge : edges) {
            unsigned u = edge[0]-1;
            unsigned v = edge[1]-1;
            ++neighbour_count[u];
            ++neighbour_count[v];
            neighbour_xorsum[u] ^= v;
            neighbour_xorsum[v] ^= u;
        }

        for (unsigned v = 1; v != n; ++v) {
            if (neighbour_count[v] == 1u)
                *q_end++ = v;
        }
        unsigned result = 1;

        while (q_begin != q_end) {
            std::span<const unsigned> frontier(q_begin, q_end);
            q_begin = q_end;
            for (unsigned v : frontier) {
                unsigned parent = neighbour_xorsum[v];
                if (parent) {
                    neighbour_xorsum[parent] ^= v;
                    if (--neighbour_count[parent] == 1u)
                        *q_end++ = parent;
                }
            }

            result %= modulo;
            result *= 2u;
        }
        return result / 2u;
    }
};
