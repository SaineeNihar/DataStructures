#include <bits/stdc++.h>
using namespace std; 
class Node
{
    public:
    int data;
    Node *next;
    Node *random;
};
void printxx(Node* n) 
{
    Node *tmp=n;
    cout<<"next pointers"<<endl;
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
    
    cout<<endl<<"random pointers"<<endl;
    
    while (tmp != NULL) { 
        cout << tmp->data << " "; 
        tmp = tmp->random; 
    } 
}
void print(Node *ptr)
{
	//Node *ptr=head;
	if(ptr==NULL)
	cout<<"Empty List\n";
	while(ptr!=NULL)
	{
		cout<<"{"<<ptr->data<<","<<ptr->random->data<<"}"<<"--";
		ptr=ptr->next;
	}
	cout<<"X"<<endl;
} 
Node *clone(Node *head)
{
    
    map<Node*, Node*> mp;
    Node *x=head,*y;
   
    while(x!=NULL)
    {
       
        y=new Node();
        y->data=x->data;
        y->next=NULL;
        y->random=NULL;
        //cout<<"ALL ok";
        mp.insert({x,y});
        x=x->next;
    }
//    for (auto itr = mp.begin(); itr != mp.end(); itr++) 
//       cout << itr->first->data << '\t' << itr->second->data<< '\n'; 
    cout<<"insertion sucessful"<<endl;   
    x=head;
    while(x!=NULL)
    {
        
        y=mp.find(x)->second;
        y->next=mp.find(x->next)->second;
        y->random=mp.find(x->random)->second;     
//      cout<<"Y="<<y->data<<y->next->data<<y->random->data<<endl;
        x=x->next;   
    }
    //cout<<"Head "<< mp.find(head)->second->data<<endl;
    auto itr=mp.find(head);
    auto h2=itr->second;
    //cout<<head2->data;
    print(h2);
    return h2;
}
int main()
{  
    Node *head = new Node(); 
    Node *second = new Node(); 
    Node *third = new Node();
    Node *fourth = new Node(); 
    Node *fifth = new Node();
    
    head->data = 1; 
    head->next = second; // Link first node with second
    head->random=fourth;

    second->data = 2; // assign data to second node 
    second->next = third; 
    second->random=fifth;

    third->data = 3; // assign data to third node 
    third->next = fourth;
    third->random=head;
    
    fourth->data = 4; // assign data to third node 
    fourth->next = fifth;
    fourth->random=second;
    
    fifth->data = 5; // assign data to third node 
    fifth->next = NULL;
    fifth->random=third;
    cout<<endl<<"Original   list"<<endl;    

    print(head);

    cout<<endl<<"Cloned list"<<endl;
    Node *head1=clone(head);
    cout<<endl<<"After return"<<endl;
//    print(head1);
    return 0;
}