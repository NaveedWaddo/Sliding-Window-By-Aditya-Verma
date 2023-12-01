//Link : https://leetcode.com/problems/minimum-window-substring/description/

// Optimale Approach : Sliding Window

class Solution{
public:
    string minWindow(string s, string t){
        int m = s.size();
        int n = t.size();

        unordered_map<char,int>mp;
        for(int i=0; i<n; i++){
            mp[t[i]]++;
        }

        int i=0;
        int j=0;
        int count = mp.size();
        int mini = INT_MAX;
        string res = "";
        int start = 0;

        while(j < m){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count--;
                }
            }

            if(count == 0){
                while(count==0){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                            if(j-i+1 < mini){
                                mini = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }

        if(mini == INT_MAX) return "";

        return s.substr(start,mini);
    }
};
