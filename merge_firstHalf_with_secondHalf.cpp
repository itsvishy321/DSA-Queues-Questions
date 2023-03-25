#include <bits/stdc++.h>
using namespace std;

// FUNCTION TO MERGE 1ST HALF OF QUEUE WITH SECOND HALF

// APPROACH 1 USING EXTRA QUEUE
//      TIME COMPLEXITY : O(N)
//      SPACE COMPLEXITY : O(N)

queue<int> mergeFirstWithSecondHalf(queue<int> q , int n)
{
    queue<int> first;

    // adding the first n/2 elements to "first" queue
    for(int i=0 ; i<n/2 ; i++)
    {
        first.push(q.front());
        q.pop();
    }

    // Adding front element of "first" then front element of "q" to the back of "q"
    while(!first.empty())
    {
        q.push(first.front());
        first.pop();

        q.push(q.front());
        q.pop();
    }

    // edge case for odd no. of elements
    if(n%2)
    {
        q.push(q.front());
        q.pop();
    }

    return q;

}

int main()
{
    queue<int> q;
    int n;
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    q = mergeFirstWithSecondHalf(q , n);

    for(int i=0 ; i<n ; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;

    return 0;
}