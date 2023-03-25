// Given an array A[] of size N and a positive integer K, 
// find the first negative integer for each and every
//  window(contiguous subarray) of size K.



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends



// APPROACH 1 USING DEQUEUE
//      TIME COMPLEXITY : O(N)
//      SPACE COMPLEXITY : O(K)


// vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
                                                 
                                                 
//         deque<long long int> dq;
//         vector<long long> ans;
        
//         // Process for first k indexes
//         for(int i=0 ; i<K ; i++)
//         {
//             if(A[i] < 0)
//             {
//                 dq.push_back(i);
//             }    
//         }
        
//         // store ans for first k elements
//         if(dq.size() == 0)
//             ans.push_back(0);
        
//         else
//             ans.push_back(A[dq.front()]);
            
//         // process for remaining windows
//         for(int i = K ; i<N ; i++)
//         {
//             // Removal
//             if(!dq.empty() && i - dq.front() >= K)
//                 dq.pop_front();
                
//             // Addition
//             if(A[i] < 0)
//                 dq.push_back(i);
            
//             if(dq.empty())
//                 ans.push_back(0);
//             else
//                 ans.push_back(A[dq.front()]);  
//         }
//         return ans;                                               
//  }


//  OTIMAL APPROACH
//      TIME COMPLEXITY : O(N)
//      SPACE COMPLEXITY : O(1)

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {

        vector<long long> ans;
        long long int firstNegativeIndex = 0;
        // int firstNegativeElement;

        for (int i = K-1; i < N; i++)
        {
            // Finding the index of first -ve no. in current window
            while (firstNegativeIndex < i && (firstNegativeIndex <= i-K || A[firstNegativeIndex] >= 0))
            {
                firstNegativeIndex++;
            }

            // Adding to ans if firstNegativeElement exists
            if(A[firstNegativeIndex] < 0)
            {
                ans.push_back(A[firstNegativeIndex]);
            }

            else
            {
                ans.push_back(0);
            }
        }

        return ans;                              
 }