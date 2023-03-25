#include <bits/stdc++.h> 
using namespace std;

class NQueue
{
private:
    int *arr;
    int *front;
    int *rear;
    int *next;

    int n , s , freespot;

public:
    // Initialize your data structure.
    NQueue(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];

        // Initialize front and rear
        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        // Initialize next
        for(int i=0 ; i<s ; i++)
        {
            next[i] = i+1;
        }
        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    void push(int x, int m)
    {
        // check for overflow
        if(freespot == -1)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }

        // find first free index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // check whether first element
        if(front[m-1] == -1)
        {
            front[m-1] = index;
        } 
        else
        {
            // link new element with previous one
            next[rear[m-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[m-1] = index;

        // push element
        arr[index] = x;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow 
        if(front[m-1] == -1)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        // find index to pop
        int index = front[m-1];

        // front ko aage badhao
        front[m-1] = next[index];

        // free slots ko manage kro
        next[index] = freespot;
        freespot = index; 
        return arr[index];
    }
};

int main()
{
    NQueue queues(3,6);
    
    queues.push(10,1);
    queues.push(15,1);

    queues.push(20,2);
    queues.push(25,2);
    
    queues.push(30,3);
    queues.push(35,3);
    queues.push(40,3);

    cout<<queues.pop(3)<<endl;
    cout<<queues.pop(2)<<endl;
    cout<<queues.pop(1)<<endl;
    cout<<queues.pop(3)<<endl;
    cout<<queues.pop(3)<<endl;

}