/*
 * 该题很容易联想到database里常用的几个join operator:
 * Nested loop join
 * Hash join
 * Sort join
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> ret;
        vector<int>* small;
        vector<int>* big;
        if (size1 < size2) {
            small = &nums1;
            big = &nums2;
        } else {
            small = &nums2;
            big = &nums1;
        }
        for (int i = 0; i < small->size(); ++i) {
            for (int j = 0; j < big->size(); ++j) {
                if ((*small)[i] == (*big)[j]) {
                    ret.push_back((*small)[i]);
                    break;
                }
            }
        }
        return ret;
    }
};
