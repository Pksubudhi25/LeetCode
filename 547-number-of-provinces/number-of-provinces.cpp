class Solution {
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &vis) {
        vis[node] = 1;
        for (auto neighbor : adjList[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjList(v);  // Initialize adjacency list

        // Build the adjacency list from the matrix
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> vis(v, 0);  // Visited array
        int provinces = 0;

        // Count connected components
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, adjList, vis);
            }
        }

        return provinces;
    }
};
