#include <bits/stdc++.h>

using namespace std;


//declaration of structure
struct Node
{
    int y;
    int x;
    Node *next;
};
struct Node* head = NULL;
//Adding given element at first
void AddFirst(int x , int y)
{
    Node* new_node = new Node;

    new_node->x  = x;
    new_node->y  = y;

    new_node->next = head;

    head = new_node;
}
//deleting the element at first
void DelFirst()
{
    if (head == NULL)
        {
            cout<<"-1";
            return ;
        }

    Node* temp = head;
    head = head->next;

    free(temp);

}
//deleting element with parameters x and y
void Del( int x,int y)
{

   if (head == NULL)
      {
        cout<<"-1";
        return ;
      }


   Node* temp = head;

   Node* previous = NULL;

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
             previous = temp;
             temp = temp->next;
         }

    if (temp == NULL )
      {
        cout<<"-1";
        return;
    }

    struct Node *next = temp->next;

    free(temp);

    previous->next = next;
}
//seacrh elements withing the distance d
void Search(int d)
{
    struct Node* temp = head;
    int x1,y1;
    int count = 0;
    while (temp!= NULL) {
        x1 = temp->x;
        y1 = temp->y;
        if(x1*x1+y1*y1<=d*d)
        {
            count++;
        }
        temp=temp->next;
    }
    if(count==0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<count;
    }    
}
//search element with x and y parameters
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
//find length of the list
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
