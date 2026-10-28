class Solution {
public:

    unordered_map<int, vector<int>> preMap;

    unordered_set<int> visiting;


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++){
            if(!dfs(c)){
                return false;
            }
        }

        return true;
    }

    bool dfs(int val) {
        if(visiting.count(val)) {
            return false;
        }

        if (preMap[val].empty()) {
            return true;
        }

        visiting.insert(val);

        for(int pre : preMap[val]) {
            if(!dfs(pre)){
                return false;
            }
        }

        visiting.erase(val);
        preMap[val].clear();
        return true;
    }
};
