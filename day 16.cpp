#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i >= 0) {  
        int j = n - 1;

        while (j >= 0 && nums[j] <= nums[i]) {
            --j;
        }

        swap(nums[i], nums[j]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    nextPermutation(nums1);
    cout << "Output (Example 1): ";
    for (int num : nums1) cout << num << " "; 
    cout << endl;

    vector<int> nums2 = {3, 2, 1};
    nextPermutation(nums2);
    cout << "Output (Example 2): ";
    for (int num : nums2) cout << num << " "; 
    cout << endl;

    vector<int> nums3 = {1, 1, 5};
    nextPermutation(nums3);
    cout << "Output (Example 3): ";
    for (int num : nums3) cout << num << " "; 
    cout << endl;

    return 0;
}
