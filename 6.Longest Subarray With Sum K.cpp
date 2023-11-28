

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    int n = nums.size();
    int maxi = INT_MIN;
    int sum = 0;

    int i=0;
    int j=0;
    
    while(j<n){
        sum += nums[j];

        if(sum < k){
            j++;
        }
        else if(sum == k){
            maxi = max(maxi , (j-i+1));
            j++;
        }
        else if(sum > k){
            while(sum > k){
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    return maxi==INT_MIN ? 0:maxi;
}
