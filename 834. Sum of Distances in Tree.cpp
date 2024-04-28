class Solution {
private:
    // Dp on Trees ReRooting Technique (CSES - Tree Distances II)

    int ans[30000];// ans(i) : overall ans which we want
    int subtreeAns[30000]; // subtreeAns(i) : ans for node i considering only the subtree rooted at node i
    int nodes[30000]; //  nodes(i) : no. of nodes in subtree rooted at node i
    void preProcessing(int src,int par,vector<int> *adj) {
        subtreeAns[src] = 0;
        nodes[src] = 1;
        for(int &child :adj[src]) {
            if(child == par) continue;
            preProcessing(child,src,adj);
            subtreeAns[src] += subtreeAns[child] + nodes[child];
            nodes[src] += nodes[child];
        }
    }

    // partialAns(src) : ans for tree rooted at par after not considering the subtree rooted at src 
    void dfs(int src,int par,int partialAns,int totalNodes,vector<int> *adj) {
        ans[src] = subtreeAns[src] + partialAns + totalNodes - nodes[src];
        for(int &child :adj[src]) {
            if(child == par) continue;
            dfs(child,src,ans[src] - (subtreeAns[child] +  nodes[child]),totalNodes,adj);
        } 
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for(vector<int> &edge :edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        preProcessing(0,-1,adj);
        dfs(0,-1,0,n,adj); 
        
        vector<int> v(n);
        for(int i=0;i<n;++i) v[i]=ans[i];
        return v;
    }
};
