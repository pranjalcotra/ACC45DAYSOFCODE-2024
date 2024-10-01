#include<bits/stdc++.h>

using namespace std;


    vector<int> twoSum(vector<int>& nums, int target) {
                vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int first = i;
            int j = i + 1;

            while(j < nums.size()){
                if(nums[first] + nums[j] == target){
                    ans.push_back(first);
                    ans.push_back(j);
                    return ans;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
        
    }

int main(){
    vector<int> v={2,7,11,15};
    int target = 9;

    vector<int> res = twoSum(v,target);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<",";
    }

return 0;
}