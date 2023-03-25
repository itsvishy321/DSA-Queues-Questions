//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Functions to reverse the queue.

// APPROACH 1 USING STACKS
queue<int> rev(queue<int> q)
{
    stack<int> st;
    
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    
    return q;
}

// APPROACH 2 USING RECURSION
// queue<int> rev(queue<int> q)
// {
//     // Base Case
//     if(q.empty())
//         return q;
    
//     int temp = q.front();
//     q.pop();
//     q = rev(q);
//     q.push(temp);
//     return q;
// }