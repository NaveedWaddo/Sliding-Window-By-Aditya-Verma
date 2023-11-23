// Link : https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

// Optimale Approach : Sliding window
class Solution{
public:
	int search(string pat, string txt){
	    int n = txt.size();
	    
	    unordered_map<int,int>hashPat;
	    for(auto &x : pat){
	        hashPat[x]++;
	    }
	    
	    int i=0;
	    int j=0;
	    int k = pat.size(); // window size
	    int count = hashPat.size();
	    int ans = 0;
	    
	    while(j < n){
	        //calculation part
	        if(hashPat.find(txt[j]) != hashPat.end()){
	            hashPat[txt[j]]--;
	            if(hashPat[txt[j]] == 0)
	                count--;
	        }
	        
	        //window length not achived yet
	        if(j-i+1 < k){
	            j++;
	        }
	        //window length achived, find ans and slide the window
	        else if(j-i+1 == k){
	            if(count == 0){
	                ans++;
	            }
	            if(hashPat.find(txt[i]) != hashPat.end()){
	                hashPat[txt[i]]++;
	                if(hashPat[txt[i]] == 1){
	                    count++;
	                }
	            }
	            //slide the window
	            i++;
	            j++;
	        }
	    }
	    
	    
	    return ans;
	}

};
