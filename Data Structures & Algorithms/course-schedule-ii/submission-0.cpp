class Solution {
public:

    unordered_map<int, vector<int>> preMap;

    unordered_set<int> visiting;

    vector<int> res;
    unordered_set<int> exist;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++){
            if(!dfs(c)){
                return {};
            }
        }

        return res;
    }

     bool dfs(int val) {
        if(visiting.count(val)) {
            return false;
        }

        if (preMap[val].empty()) {
            if (exist.count(val) == 0) {
                res.push_back(val);
                exist.insert(val);
            }
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
        if (exist.count(val) == 0) {
            res.push_back(val);
            exist.insert(val);
        }
        return true;
    }


};
