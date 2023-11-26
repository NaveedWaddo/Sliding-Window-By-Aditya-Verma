// Link : 

// // 1.Brute Approach:
// class Solution {
//   public:
//     vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
//         vector<int>ans;
//         for(int i=0; i<n-k+1; i++){
//             int maxi = INT_MIN;
//             for(int j=0; j<k; j++){
//                 maxi = max(maxi , arr[i+j]);
//             }
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
// };

// 2.Better Approach: Heap 
// class Solution {
// public:
//     vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
//         priority_queue<pair<int,int>>pq;
//         vector<int> ans;
        
//         for(int i=0;i<k-1;i++){
//             pq.push({arr[i],i});
//         }
//         for(int i=k-1;i<n;i++){
//             pq.push({arr[i],i});
//             while(!pq.empty() && pq.top().second < i-k+1) pq.pop();
//             ans.push_back(pq.top().first);
//         }
//         return ans;
//     }
// };

// 3.Optimale Approach: Sliding Window 
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int>q;
        int i=0,j=0;
        vector<int>res;
        
        while(j<n){
            while(!q.empty() && q.back()<arr[j]) q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) q.pop_front();
                i++;
                j++;
            }
        }
        return res;
    }
};



   

