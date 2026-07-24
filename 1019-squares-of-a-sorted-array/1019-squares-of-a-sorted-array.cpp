class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        vector<int> pos;
        int j = 0;
        vector<int> neg;

        int id = 0;
        vector<int> res(nums.size());


        for (int i = 0; i < nums.size(); i++) {   // separating +ves and -ves
            if (nums[i] >= 0) {    // positive
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);  // negatives
            }
        }

        if (neg.size() == 0) {   // all postives
            for (int i = 0; i < pos.size(); i++) {
                pos[i] *= pos[i];

            }
            return pos;
        }

        if (pos.size() == 0) {   // all negatives

            for (int i = 0; i < neg.size(); i++) {
                neg[i] *= neg[i];

            }
            reverse(neg.begin(), neg.end());
            return neg;
        }

        
        for (int i = 0; i < pos.size(); i++) {   // for mixed array of both + and -
            pos[i] *= pos[i];
        }

        for (int i = 0; i < neg.size(); i++) {
            neg[i] *= neg[i];
        }
        reverse(neg.begin(), neg.end());


        while (i < pos.size() && j < neg.size()) {
            if (pos[i] <= neg[j]) {
                res[id] = pos[i];
                id++;
                i++;
            } else {
                res[id] = neg[j];
                id++;
                j++;
            }
        }

        while (i < pos.size()) {
            res[id] = pos[i];
            id++;
            i++;
        }

        while (j < neg.size()) {
            res[id] = neg[j];
            id++;
            j++;
        }

        return res;

    }
};