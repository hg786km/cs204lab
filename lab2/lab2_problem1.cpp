#include <bits/stdc++.h>
using namespace std;

struct Node* head = NULL;

struct Node  
{  
    int y; 
    int x;  
    Node *next;  
}; 

void AddFirst(int x , int y) 
{ 
    Node* new_node = new Node; 
   
    new_node->x  = x; 
    new_node->y  = y; 
   
    new_node->next = head; 
   
    head = new_node; 
} 

void DelFirst() 
{ 
    if (head == NULL) 
        {
            cout<<"empty linked list";
            return ;
        } 

    Node* temp = head; 
    head = head->next; 
  
    free(temp); 

} 

void Del( int x,int y) 
{ 
   
   if (head == NULL) 
      {cout<<"empty linked list";return ;} 
  
    
   Node* temp = head; 
   Node* prev = NULL;
     
    if ((head->x)==x&&(head->y)==y) 
    { 
        head = temp->next;    
        free(temp);              
        return; 
    } 
  
  
    for (int i=0; temp!=NULL; i++) 
         {
             if(temp->x==x&&temp->y==y)
             {
                 break;
             }
             prev = temp;
             temp = temp->next; 
         }

    if (temp == NULL ) 
      {cout<<"not found";return ;} 
  
    struct Node *next = temp->next; 
    free(temp);
  
    prev->next = next;
} 

void Search(int d) 
{ 
    struct Node* temp = head; 
    while (temp!= NULL) { 
        if((temp->x)*(temp->x)+(temp->y)*(temp->y)<=d*d)
        {
            cout<<"("<<(temp->x)<<","<<(temp->y)<<")";
        }
        temp=temp->next;
    } 
} 

string Search(int x,int y) 
{ 
    struct Node* temp = head; 
    while (temp!= NULL) { 
        if((temp->x)==x&&(temp->y)==y)
        {
            return "True";
        }
        temp=temp->next;
    } 
    return "False";
}

int Length() 
{ 
    struct Node* temp = head; 
    int l=0;
    while (temp!= NULL) { 
        l++;
        temp=temp->next;
    } 
    return l;
}
int main()
{
    long long int q;
    cin>>q;
 
    while(q--)
    {
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int x,y;
            cin>>x>>y;
            AddFirst(x,y);
        }
        else if(choice==2)
        {
            DelFirst();
        }
        else if(choice==3)
        {
            int x,y;
            cin>>x>>y;
            Del(x,y);
        }
        else if(choice==4)
        {
            int d;
            cin>>d;
            Search(d);
            cout<<endl;
            
        }
        else if(choice==5)
        {
            int x,y;
            cin>>x>>y;
            cout<<Search(x,y)<<endl;
        }
        else if(choice==6)
        {
            cout<<Length()<<endl;
        }
    }
}