//implementing stack using linked list
#include <iostream>
using namespace std;

typedef struct Node {
int data;
Node* next;
}node;

class stack {
private:
node *top=NULL;
public:
void push(int a);
void pop();
int peek();
void display();
};

void stack::push(int a)
{
  node *newnode=new node;
  if (!newnode)
  {
    cout<<"Stack Overflow!\n";
    return;
  }
  newnode->data=a;
  newnode->next=top;
  top=newnode;
}

void stack::pop()
{
 if (top)
 {
   node *temp=top;
   top=top->next;
   delete temp;
 }
  else
   cout<<"Stack Underflow!\n";
}

int stack::peek()
{
  if (top)
    return top->data;
  else
  {
    cout<<"Stack is empty!\n";
    return -1;
  }
}

void stack::display() 
{
  node *temp=top;
  if(top)
  {
    while(temp!=NULL)
    {
      cout<<temp->data<<" => ";
      temp=temp->next;
    }
  cout<<"NULL\n";
  }
  else
    cout<<"Stack is empty!\n";
}

int main() {
  stack s;
  //Test cases
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.display();
  s.pop();
  s.display();
  cout<<"\nTop Element: "<<s.peek();
  cout << "\n";
  return 0;
}
