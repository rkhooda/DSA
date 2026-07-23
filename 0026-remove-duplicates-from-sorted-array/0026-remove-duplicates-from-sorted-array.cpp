class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        int unq = 1;
        int counter = 1;

        int n = nums.size();

        while (counter < n) {
            if (nums[counter] == nums[counter - 1]) {
                counter ++;
                continue;
            }

            nums[curr + 1] = nums[counter];
            curr++;
            counter++;
            unq++;
        }

        return unq;
    }
};