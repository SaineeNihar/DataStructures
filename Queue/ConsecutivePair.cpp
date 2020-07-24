#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    s.push(7);s.push(6);s.push(-2);s.push(-3);s.push(11);s.push(10);s.push(5);s.push(6);s.push(20);
    if(s.size()%2!=0)
        s.pop();
    int a,b;
    while(!s.empty())
    {
        a=s.top();
        s.pop();
        b=s.top();
        s.pop();
        if(abs(a-b)!=1)
        {
            cout<<"Failed";
            break;
        }
    }
    return 0;
}