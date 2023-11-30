// Pick toys -----> same as -----> Fruit into baskets

// Link : https://leetcode.com/problems/fruit-into-baskets/description/

//Optimale Approach : Sliding Window
class Solution {
public:
    int totalFruit(vector<int>& fruits){
        int n = fruits.size();
        int maxi = 0;

        unordered_map<int,int>mp;
        int i=0;
        int j=0; 

        while(j < n){
            mp[fruits[j]]++;

            if(mp.size() <= 2){
                maxi = max(maxi , j-i+1);
                j++;
            }
            else{
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }

        return maxi;
    }
};
