//implementing queue using linked list 
#include <iostream>
using namespace std;

typedef struct Node 
{
int data;
Node *next;
}node;

class queue 
{
private:
node *front=NULL;
node *rear=NULL;
public:
void enqueue(int a);
void dequeue();
void display();
void peek();
};

void queue::enqueue(int a)
{
  node *newnode=new node;
  newnode->data=a;
  newnode->next=NULL;
  if (rear!=NULL)
  {
    rear->next=newnode;
    rear=newnode;
  }
  else
  {
    front=rear=newnode;
  } 
}

void queue::dequeue()
{
  if (front!=NULL)
  {
    node *temp=front;
    front=front->next;
    delete temp;
  }
  else
  {
    cout<<"Queue is empty!\n";
  }
}

void queue::peek()
{
  if (front!=NULL)
  {
    cout<<"\nFront element is: "<<front->data<<"\n";
  }
  else
  {
    cout<<"Queue is empty!\n";
  }
}

void queue::display()
{
  node *temp=front;
  while (temp!=NULL)
    {
      cout<<temp->data<<" => ";
      temp=temp->next;
    }
  cout<<"NULL\n";
}

int main() {
  queue q;
  q.enqueue(1);
  q.display();
  q.enqueue(2);
  q.display();
  q.enqueue(3);
  q.display();
  q.enqueue(4);
  q.display();
  q.enqueue(5);
  q.display();
  q.dequeue();
  q.display();
  q.dequeue();
  q.display();
  q.peek();
  return 0;
}
