class Solution {
public:

    unordered_map<int , vector<int>> adjList;
    unordered_set<int> visiting;
    
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() > n - 1) {
            return false;
        }

        for(int i=0; i < n; i++) {
            adjList[i] = {};
        }

        for (int i=0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        if(!dfs(0, -1, visiting, adjList)){
            return false;
        }

        return visiting.size() == n;

        
    }

    bool dfs(int node, int parent, unordered_set<int>& visiting, unordered_map<int , vector<int>>& adjList) {
        if(visiting.count(node)) {
            return false;
        }

        visiting.insert(node);

        for(int adj : adjList[node]) {
            if (adj == parent) {continue;}
            
            if(!dfs(adj, node, visiting, adjList)){
                return false;
            }
        }

        return true;
    }
};
