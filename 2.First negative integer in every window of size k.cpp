// Link : https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// // 1.Brute Approach
// vector<long long> printFirstNegativeInteger(long long int A[],
//                                              long long int N, long long int K){
                    
//         vector<long long>ans;

        
//         for(int i=0; i<N-K+1; i++){
//             bool flag = false;
//             for(int j=i; j<i+K; j++){
//                 if(A[j] < 0){
//                     ans.push_back(A[j]);
//                     flag = true;
//                     break;
//                 }
//             }
//             if(flag == false){
//                 ans.push_back(0);
//             }
//         }
        
//         return ans;
                                                 
//  }

// 2.Optimize code: Sliding Window
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                            
        
        vector<long long>ans;
        int i=0;
        int j=0;
        queue<long long>neg;
        
        while(j < N){
            if(A[j] < 0){
                neg.push(A[j]);
            }
            
            
            if(j-i+1 < K){
                j++;
            }
            else{
                if(neg.empty()) ans.push_back(0);
                else{
                    ans.push_back(neg.front());
                    if(A[i]<0) 
                        neg.pop();
                }
                i++;
                j++;
            }
        }
        
        return ans;
 }
 
 
//  3.without using queue

// vector<long long> printFirstNegativeInteger(long long int A[],
//                                              long long int N, long long int K) {
//               int i=0;
//               int j=0;
//               vector<long long>ans;
//              while(i+K<=N){
//                  if(j-i+1<=K&&A[j]<0){
//                      ans.push_back(A[j]);
//                  if(i==j)
//                  j++;
//                  i++;
//                  }
//                  else if(j-i+1<K&&A[j]>=0){
//                      j++;
//                  }
//                  else if(j-i+1==K&&A[j]>=0){
//                      ans.push_back(0);
//                      i++;
//                      j++;
//                  }
//              }
//              return ans;
                                                 
//  }

