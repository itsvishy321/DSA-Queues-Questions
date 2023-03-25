// Given an integer K and a queue of integers,
// we need to reverse the order of the first K elements of the queue, 
// leaving the other elements in the same relative order.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.


// APPROACH USING STACK
//      TIME COMPLEXITY : O(N)
//      SPACE COMPLEXITY : O(K)

queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int> st;
    
    // Add firt k elements in stack
    for(int i=0 ; i<k ; i++)
    {
        st.push(q.front());
        q.pop();
    }
    
    // Pop elements from stack and push into queue
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // Pop the n-k elements from q push at the back of the queue
    for(int i=0 ; i<q.size()-k ; i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    return q;
}