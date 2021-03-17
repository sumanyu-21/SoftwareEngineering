# include <iostream>
# include <stdio.h>
# include<bits/stdc++.h>
using namespace std;

class Queue{
    vector<int>data;
    int front;
    int size;
    public:
    Queue()
    {
        data.resize(5);
        front = 0;
        size=0;
    }

    bool isEmpty()
    {
        return size==0;
    }
    bool isFull()
    {
        return size==data.size();
    }
    void enqueue(int item)
    {
        if(isFull())
            return;
        
        data[(front+size++)%data.size()] = item;
    }

    int deque()
    {
        if(isEmpty())
            return -1;
        int temp = data[front];
        front = (front+1)%data.size();
        size--;
        return temp;
    }

    int getFront()
    {
        if(isEmpty())
        {
            cout<<"noElement";
            return -1;
        }
        return data[front];
    }

    void display()
    {
        for(int i=front;i<front+size;i++)
            cout<<data[i%data.size()]<<" ";
        cout<<endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.display();
    q.enqueue(20);
    q.display();
    q.enqueue(30);
    q.display();
    q.enqueue(40);
    q.display();
    q.deque();
    q.display();
    q.deque();
    q.display();
    q.deque();
    q.display();
    q.enqueue(50);
    q.display();
    q.enqueue(60);
    q.display();
    cout<<q.getFront()<<endl;
    return 0;
}
