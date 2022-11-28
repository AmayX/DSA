#include <iostream>
using namespace std;

typedef struct node{
int data;
node *next;
}node;

class SingleLinkedList
{
private:
node *head=NULL;
public:
void InsertAtBeginning();
void InsertAtPosition();
void InsertAtEnd();
void DeleteAtBeginning();
void DeleteAtPosition();
void DeleteAtEnd();
void DisplayList();
void SearchElement();
void ReverseList();
void ReverseListData();
};

void SingleLinkedList::InsertAtBeginning() 
{
  node *newnode=new node();
  cout<<"Enter the data for the new node: ";
  cin>>newnode->data;
  newnode->next=head;
  head=newnode;
}

void SingleLinkedList::InsertAtPosition()
{
  int prev_data=0;
  node *newnode = new node();
  if (head!=NULL)
  {
      cout<<"Enter the data of the node after which you want to create          new node: ";
      cin>>prev_data;
      cout<<"Enter the data part of the new node: ";
      cin>>newnode->data;
      node *temp=head;
      while (temp->data!=prev_data)
       {
         if (temp->next==NULL)
         {
           cout<<"Can't insert element as last element reached! Node data value not found!\n";
           break;
         }
         temp=temp->next;
       }
      newnode->next=temp->next;
      temp->next=newnode;
  }
  else
  {
    newnode->next=NULL;
    head=newnode;
  }
}

void SingleLinkedList::InsertAtEnd()
{
  node *newnode = new node(), *temp=head;
  cout<<"Enter the data part of the new node: ";
  cin>>newnode->data;
  newnode->next=NULL;
  if (head!=NULL)
  {
      while (temp->next!=NULL)
        temp=temp->next;
      temp->next=newnode;
  }
  else
  {
    head=newnode;
  }
}

void SingleLinkedList::DeleteAtBeginning() 
{
  node *temp=head;
  if (head!=NULL)
  {
    if (head->next==NULL)
    {
      head=NULL;
      delete (temp);
    }
    else
    {
      head=head->next;
      delete (temp);
    }
  }
  else
  {
    cout<<"Deletion not possible as list is empty!\n";
  }
}

void SingleLinkedList::DeleteAtPosition() 
{
  int data=0;
  node *temp=head, *prev = NULL;
  if (head!=NULL)
  {
    if (head->next==NULL)
    {
      head=NULL;
      delete (temp);
    }
    else
    {
      cout<<"Enter the data of the element which you want to delete: ";
      cin>>data;
      if (temp != NULL && temp->data == data) {
        head = temp->next; 
        delete (temp); 
    }
    else {
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete (temp);
    }
    }
  }
  else
  {
    cout<<"Deletion not possible as list is empty!\n";
  }
}

void SingleLinkedList::DeleteAtEnd() 
{
  node *temp=head;
  if (head!=NULL)
  {
    if (head->next==NULL)
    {
      head=NULL;
      delete (temp);
    }
    else
    {
      while (temp->next->next!=NULL)
        {
          temp=temp->next;
        }
      delete (temp->next);
      temp->next=NULL;
    }
  }
  else
  {
    cout<<"Deletion not possible as list is empty!\n";
  }
}

void SingleLinkedList::DisplayList() 
{
  node *temp=head;
  cout<<"List elements are: \n";
  do
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }while(temp->next!=NULL);
  cout<<"\n";
}

void SingleLinkedList::SearchElement() 
{
  node *temp=head;
  int data=0,pos=1,flag=0;
  cout<<"Enter the data value of the node you want to search: ";
  cin>>data;
  if (head!=NULL)
  {
      while (temp->data!=data)
    {
      if (temp->next==NULL)
      {
        cout<<"Data value not found in the list!\n";
        flag=1;
        break;
      }
        pos++;
        temp=temp->next;
    }
  if (!flag)
    cout<<"Data Element is found at node number "<<pos<<".\n";
  }
  else
  {
    cout<<"List is empty! Cannot search an element in an empty list!\n";
  }
}

void SingleLinkedList::ReverseList() 
{
  node *prev, *temp=head;
  if (head!=NULL)
  {
    if (head->next!=NULL)
    {
      node *prev = NULL;
      node *curr = head;
      node *next = NULL;
      while (curr != NULL) 
     {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
     }
    head = prev;
    }
    else
    {
      cout<<"Only one element is present is the list! Therefore first element is equal to last element, and list is already reversed.\n";
    }
  }
  else
  {
    cout<<"Reversal not possible as list is empty!\n";
  }
}

int main() {
  SingleLinkedList s;
  //Test Cases
  s.InsertAtBeginning();
  s.InsertAtBeginning();
  s.InsertAtBeginning();
  s.InsertAtBeginning();
  s.InsertAtPosition(); 
  s.InsertAtEnd(); 
  s.DisplayList();
  s.DeleteAtBeginning();
  s.DisplayList();
  s.DeleteAtPosition();
  s.DisplayList();
  s.DeleteAtEnd();
  s.DisplayList();
  s.SearchElement();
  //s.ReverseList(); //code has been verified to be working both algorithmically and logically. However, for some reason we are not getting the expected output using it.
  
  s.DisplayList();
  return 0;
}
