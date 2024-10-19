#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, sum = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];  

        while (sum >= target) {
            minLength = min(minLength, right - left + 1);  
            sum -= nums[left];  
            ++left;
        }
    }

    return minLength == INT_MAX ? 0 : minLength;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Output (Example 1): " << minSubArrayLen(target1, nums1) << endl; 

    // Example 2
    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    cout << "Output (Example 2): " << minSubArrayLen(target2, nums2) << endl; 

    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    cout << "Output (Example 3): " << minSubArrayLen(target3, nums3) << endl;  

    return 0;
}
