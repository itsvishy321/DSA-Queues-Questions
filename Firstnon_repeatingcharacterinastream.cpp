// Given an input stream of A of n characters consisting only of lower case alphabets. 
// The task is to find the first non repeating character, each time a character is 
// inserted to the stream. If there is no such character then append '#' to the answer.

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:

        // APPROACH USING A MAP AND A QUEUE
        //      TIME COMPLEXITY : O(N)
        //      SPACE COMPLEXITY : O(N)
		string FirstNonRepeating(string A){
		    
		    map<char,int> count;
		    queue<char> q;
		    string ans;
		    
		    for(int i=0 ; i<A.length() ; i++)
		    {
		        char ch = A[i];
		        
		        count[ch]++;
		        
		        q.push(ch);
		        
		        while(!q.empty() && count[q.front()] > 1)
		        {
		            q.pop();
		        }
		        
                if(q.empty())
                {
                    ans.push_back('#');
                }
		        else
		        {
		            ans.push_back(q.front());
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends