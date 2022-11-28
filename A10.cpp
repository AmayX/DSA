#include <iostream>
using namespace std;

typedef class node{
public:
int data;
node *prev;
node *next;
~node()
{
  data=0;
  prev=next=NULL;
}
}node;

class DoubleLinkedList
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
int SearchElement(int data);
};

void DoubleLinkedList::InsertAtBeginning()
{
  node *newnode=new node;
  cout<<"Enter the data part of the node: ";
  cin>>newnode->data;
  newnode->prev=NULL;
  if(head!=NULL)
  {
    newnode->next=head;
    head=newnode;
  }
  else
  {
    newnode->next=NULL;
    head=newnode;
  }
}

void DoubleLinkedList::InsertAtPosition()
{
  int data;
  node *newnode=new node, *prevnode=head, *temp=new node;
  cout<<"Enter the data part of the node: ";
  cin>>newnode->data;
  if (head!=NULL)
  {
      cout<<"Enter the data before insertion position: ";
      cin>>data;
      while (prevnode->data!=data)
        {
          if (prevnode->next==NULL)
          {
            cout<<"Insertion not possible as entered data value is not present in the list!\n";
            break;
          }
          prevnode=prevnode->next;
        }
      prevnode->next=temp;
    
      newnode->next=temp;
      prevnode->next=newnode;
      newnode->prev=prevnode;
      temp->prev=newnode;
  }
  else
  {
    newnode->next=newnode->prev=NULL;
    head=newnode;
  }
}

void DoubleLinkedList::InsertAtEnd()
{
  node *newnode=new node, *lastnode=head;
  cout<<"Enter the data part of the node: ";
  cin>>newnode->data;
  newnode->next=NULL;
  if(head==NULL)
  {
    newnode->prev=NULL;
    head=newnode;
  }
  else
  {
    while (lastnode->next!=NULL)
      lastnode=lastnode->next;
  
  lastnode->next=newnode;
  newnode->prev=lastnode;
  }
}

void DoubleLinkedList::DeleteAtBeginning()
{
  if(head!=NULL)
  {
    /*head=head->next;
    head->next->prev=NULL;
    delete(head->prev);*/ //will this work?
    node *temp=head;
    if (temp->prev==temp->next)
    {
      head=NULL;
      delete(temp);
    }
    else
    {
      head=temp->next;
      head->prev=NULL;
      delete(temp);
    }
  }
  else
  {
    cout<<"Deletion not possible as list is empty";
    return;
  }
}

void DoubleLinkedList::DeleteAtPosition()
{
  node *delnode=head;
  int data;
  cout<<"Enter the data part of the node you want to delete: ";
  cin>>data;
  while (delnode->data!=data)
    delnode=delnode->next;
  if (head!=NULL)
  {
    node *temp=head;
    while (temp!=delnode)
      {
        if (temp->next==NULL)
        {
          cout<<"Deletion not possible as element not found in list!\n";
          break;
        }
        temp=temp->next;
      }
    if (temp->next==NULL && temp->prev==NULL)
    {
      head=NULL;
      delete(temp);
    }
    else
    {
      if (temp==head)
      {
        head=head->next;
        head->prev=NULL;
        delete(temp);
      }
      else if (temp->next==NULL)
      {
        temp->prev->next=NULL;
        delete(temp);
      }
      else
      {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        delete(temp);
      }
    }
  }
  else
  {
    cout<<"Deletion not possible as list is empty";
    return;
  }
}

void DoubleLinkedList::DeleteAtEnd()
{
  if (head!=NULL)
  {
    node *temp=head;
    if (temp->next==NULL && temp->prev==NULL)
    {
      head=NULL;
      delete temp;
      return;
    }
    else
    {
      while (temp->next!=NULL)
        temp=temp->next;
      temp->prev->next=NULL;
      delete temp;
    }
  }
  else
    cout<<"Deletion not possible as list is empty";
}

void DoubleLinkedList::DisplayList()
{
  node *temp=head;
  cout<<"\n";
  while (temp!=NULL)
    {
      cout<<temp->data<<" <=> ";
      temp=temp->next;
    }
  cout<<"NULL\n\n";
}

int DoubleLinkedList::SearchElement(int data){
  int pos=0;
  node *temp=head;
  while(temp!=NULL)
    {
      pos++;
      if(temp->data==data)
        return pos;
      temp=temp->next;
    }
  return -1;
}

int main() {
  int data=0;
  DoubleLinkedList list;
  cout<<"Inserting at end:\n";
  list.InsertAtEnd();
  list.InsertAtEnd();
  list.InsertAtEnd();
  cout<<"Inserting at beginning:\n";
  list.InsertAtBeginning();
  list.DisplayList();
  cout<<"Enter data: ";
  cin>>data;
  cout<<list.SearchElement(data)<<"\n\n";
  cout<<"Deleting at Position:\n";
  list.DeleteAtPosition();
  cout<<"Deleting at End:\n";
  list.DeleteAtEnd();
  cout<<"Deleting at Beginning:\n";
  list.DeleteAtBeginning();;
  cout<<"Deleting at End:\n";
  list.DeleteAtEnd();
  list.DisplayList();
  return 0;
}
