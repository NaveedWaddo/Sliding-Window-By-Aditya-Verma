// Link : https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// // 1.Brute Approach
// class Solution{
// public:
//     int longestKSubstr(string s, int k){
//         int n = s.size();
//         int maxi = -1;
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 unordered_set<char>distinct(s.begin()+i , s.begin()+j);
//                 if(distinct.size() == k){
//                     maxi = max(maxi , j-i+1);
//                 }
//             }
//         }
        
//         return maxi;
//     } 
// };


// 2.Optimale Approach  : Sliding Window
class Solution{
public:
    int longestKSubstr(string s, int k){
        int n = s.size();
        int maxi = -1;
        
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        
        while(j<n){
            mp[s[j]]++;
            
            if(mp.size() < k){
                j++;
            }
            else if(mp.size() == k){
                maxi = max(maxi , j-i+1);
                j++;
            }
            else if(mp.size() > k){
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    } 
};
