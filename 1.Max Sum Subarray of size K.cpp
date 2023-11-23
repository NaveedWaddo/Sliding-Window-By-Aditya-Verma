// Link : https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// // 1.Better Approach : Prefix Sum
// class Solution{   
// public:
//     long maximumSumSubarray(int K, vector<int> &Arr , int N){
//         // code here 
//         int n=Arr.size();
//         long currentSum=0;
        
        
//         for(int i= 0; i<K; i++){
//             currentSum+=Arr[i];
//         }
//         long maxSum = currentSum;
        
//         for(int i=K; i<n; i++){
//             currentSum = currentSum - Arr[i-K] + Arr[i];
//             maxSum = max(maxSum,currentSum);
//         }
//         return maxSum;
//     }
// };


// 2.Optimale Approach : Sliding window
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxi = 0;
        int i = 0;
        int j = 0;
        long sum = 0;
        
        while(j < N){
            sum += Arr[j];
            
            if(j-i+1 < K){
                j++;
            }
            else if(j-i+1 == K){
                maxi = max(maxi , sum);
                sum -= Arr[i];
                i++;
                j++;
            }
        }
        
        return maxi;
    }
};
