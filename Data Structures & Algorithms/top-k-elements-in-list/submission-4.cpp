class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(int i=0; i<nums.size(); i++) {
            counts[nums[i]] += 1;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto& p: counts) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> result;
        for(int i=buckets.size()-1; i>=0; i--) {
            for(int num: buckets[i]) {
                if(k == 0) {
                    return result;
                }
                result.push_back(num);
                k--;
            }
        }
        return result;
    }
};
