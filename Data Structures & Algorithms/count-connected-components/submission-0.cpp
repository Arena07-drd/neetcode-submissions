class Solution {
public:

    unordered_map<int , vector<int>> adjList;
    unordered_set<int> visiting;
    
    int countComponents(int n, vector<vector<int>>& edges) {

        for(int i=0; i < n; i++) {
            adjList[i] = {};
        }

        for (int i=0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        int count = 0;
        for(int i=0; i < n; i++) {
            if (visiting.count(i)) {
                continue;
            }

            count++;
            dfs(i, -1, visiting, adjList);
        }

        return count;

        
    }

    void dfs(int node, int parent, unordered_set<int>& visiting, unordered_map<int , vector<int>>& adjList) {
        if(visiting.count(node)) {
            return;
        }

        visiting.insert(node);

        for(int adj : adjList[node]) {
            if (adj == parent) {continue;}
            
            dfs(adj, node, visiting, adjList);
        }

        return;
    }
};
