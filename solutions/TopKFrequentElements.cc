class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        vector<int> res(k, 0);
        for (auto i:nums) counter[i]++;
        priority_queue<pair<int, int>> temp;
        for (auto i:counter) temp.push(make_pair(i.second, i.first));
        for (int i=0; i<k; i++, temp.pop()) res[i] = temp.top().second;
        return res;
    }
};