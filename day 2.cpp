#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int j = 1; 

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    int k1 = removeDuplicates(nums1);
    cout << "k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << (i < k1 - 1 ? ", " : "");
    }
    cout << "]" << endl;

   

    return 0;
}