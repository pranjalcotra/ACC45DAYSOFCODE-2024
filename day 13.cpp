#include <iostream>
#include <vector>

using namespace std;

int minJumps(vector<int>& nums) {
    int n = nums.size();
    
    int jumps = 0, current_end = 0, farthest = 0;
    
    for (int i = 0; i < n - 1; ++i) {

        farthest = max(farthest, i + nums[i]);

        if (i == current_end) {
            jumps++;
            current_end = farthest;  
            
            if (current_end >= n - 1) {
                break;
            }
        }
    }
    
    return jumps;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Minimum jumps for nums1: " << minJumps(nums1) << endl;

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Minimum jumps for nums2: " << minJumps(nums2) << endl;

    return 0;
}
