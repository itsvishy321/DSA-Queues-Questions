// Suppose there is a circle. There are N petrol pumps on that circle. 
// You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete
// circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int balance = 0;
        int deficit = 0;
        int start = 0;

        for(int rear = 0 ; rear<n ; rear++)
        {
            // Calculating balance 
            balance += p[rear].petrol - p[rear].distance;
            
            // When balance is -ve
            if(balance < 0)
            {
                // storing the negative value which was required
                deficit += balance;
                start = rear + 1;
                balance = 0;
            }
        }
        
        // After travelling from point "start" to n-1
        // if sum of balance and deficit value commes out to be +ve then possible 
        if(balance + deficit >= 0)
            return start;
        
        // Not possible
        else
            return -1;
       
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol;

        for(int i=0;i<n;i++)
            cin>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends