#include <bits/stdc++.h>

using namespace std;

bool canJump(const vector<int>& nums) {
    int maxReach = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        if (i > maxReach) {
            return false;
        }
        maxReach = max(maxReach, i + nums[i]);
        if (maxReach >= n - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    
    cout << boolalpha; 
    cout << "Can jump to last index (nums1): " << canJump(nums1) << endl;
 
    
    return 0;
}
