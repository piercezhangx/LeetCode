/*
1. 很自然想到遍历每个元素并查找是否存在一个值相加等于target
但该方法时间复杂度为O(n^2) 肯定不是最优解
2. 哈希表以空间换时间.
把数组每个元素和索引添加到哈希表中, 然后对每个元素在哈希表里查找target-sums[i]值是否存在即可
但要注意比较数组下标是否一样
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> m;
        map<int, int>::iterator itr;
        for (int i = 0; i < nums.size(); ++i) {
            int a = target - nums[i];
            itr = m.find(a);
            if (itr != m.end() && itr->second != i) {
                ret.push_back(itr->second);
                ret.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return ret;
    }
};
