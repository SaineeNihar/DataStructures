#include<bits/stdc++.h>
using namespace std;
class q
{
    public:
    stack<int>s1,s2;
    void enqueue(int);
    int dequeue();
};
void q::enqueue(int x)
{
    s1.push(x);
}
int q::dequeue()
{
    int x;
    if(!s2.empty())
    {
        x=s2.top();
        s2.pop();
        return x;
    }
    else if(!s1.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        x=s2.top();
        s2.pop();
        return x;
    }
    else
    {
        cout<<"Queue is empty";
        return 0;
    }
}
int main()
{
    stack<int>s1,s2;
    q qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.enqueue(50);
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    qu.enqueue(60);
    qu.enqueue(70);
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    cout<<qu.dequeue()<<endl;
    return 0;
}