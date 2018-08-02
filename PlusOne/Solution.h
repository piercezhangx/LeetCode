/*Solution 1*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int size = digits.size();
        bool increase = true;
        for (int i = size - 1; i >= 0; --i) {
            if (increase) {
                if (digits[i] == 9) {
                    ret.push_back(0);
                    if (i == 0) {
                        ret.push_back(1);
                    }
                } else {
                    ret.push_back(digits[i] + 1);
                    increase = false;
                }
            } else {
                ret.push_back(digits[i]);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/*
Solution 2
usage stack
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        stack<int> st;
        int size = digits.size();
        bool inc = true;
        for (int i = size - 1; i >= 0; --i) {
            if (inc) {
                if (digits[i] == 9) {
                    st.push(0);
                    if (i == 0) st.push(1);
                } else {
                    st.push(digits[i] + 1);
                    inc = false;
                }
            } else {
                st.push(digits[i]);
            }
        }
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
    }
};

/*
Solution 3
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for (int i = size - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits[0] == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};
