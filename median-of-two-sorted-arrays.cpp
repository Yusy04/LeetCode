class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i;
        vector <int> nums;
        for (i = 0; i < nums1.size(); i++)
            nums.push_back(nums1[i]);
        for (i = 0; i < nums2.size(); i++)
            nums.push_back(nums2[i]);

        sort(nums.begin(), nums.end());
        
        if (nums.size() % 2 == 1)
            return nums[nums.size() / 2];
        else
            return (double)(nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;

    }
};
