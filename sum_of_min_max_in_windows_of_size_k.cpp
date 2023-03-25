// Given an array of both positive and negative integers, 
// the task is to compute sum of minimum and maximum elements of all sub-array of size k

#include <bits/stdc++.h>
using namespace std;

// FUNCTION TO SOLVE THE MAIN PROBLEM
int solve(vector<int> arr , int k)
{
    deque<int> maxi;
    deque<int> mini;

    // Processing the first window
    for(int i=0 ; i<k ; i++)
    {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // Ptocessing for remaining windows

    
    for(int i=k ; i<arr.size() ; i++)
    {

        // removal
        while(!maxi.empty() && i-maxi.front() >= k)
            maxi.pop_front();

        while(!mini.empty() && i-mini.front() >= k)
            mini.pop_front();

        // addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
        ans += arr[maxi.front()] + arr[mini.front()];

    }

    return ans;
}


int main()
{
    vector<int> arr = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    cout<<solve(arr , k)<<endl;



    return 0;
}