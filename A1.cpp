//Consider an employee database of n employees. Make use of Hash Table implementation to quickly look up, the employee's ID Number
#include <iostream>
#include <cstring>
using namespace std;

class emp
{
private:
  int id;
  char name[50];
  int sal;
  int probe_count;
public:
  void input();
  bool check();
  void display();
  friend int checkid(emp e[] ,int key, int n);
  friend bool printcheck(emp e[], int contestedkey);
  friend int Hash(emp e, int n);
  friend int Probe(emp e[], int n, int u);
  emp ()
  {
    probe_count=0;
    id=-1;
    sal=0;
  }
};

inline int Hash(emp e, int n)
{
  return (2*e.id+3)%n;  
}

inline int Hash_check(int n, int size)
{
  return (2*n+3)%size;
}

inline bool emp::check()
{
  if (id==-1)
    return true;
  return false;
}

inline int probef(int u, int i, int n)
{
  return (u+i*i)%n;
}

int Probe(emp e[], int n, int u)
{
  for (int i=1;i<n;i++,++e[i].probe_count)
    {
      if(e[probef(u,i,n)].id==-1)
        return i;
    }
}

inline bool printcheck(emp e[], int contestedkey)
{
  if (e[contestedkey].probe_count==0)
    return true;
  return false;
}

int checkid(emp e[] ,int key, int n)
{
      for (int i=0;i<n;i++)
      {
        if(key==e[probef(Hash_check(key,n),i,n)].id)
          return i;
      }
  return -1;
}

inline void emp::input()
{
  cout<<"Enter Employee ID: ";
  cin>>id;
  cout<<"Enter Name: ";
  cin>>name;
  cout<<"Enter Salary: ";
  cin>>sal;
}

inline void emp::display()
{
  cout<<"ID: "<<id<<endl;
  cout<<"Name: "<<name<<endl;
  cout<<"Salary: "<<sal<<endl;
}

inline bool isPrime(int n)
{
    if (n <= 1)
        return false; 
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
  int n,key=0;
  cout<<"Enter the size of employee database you want to create: ";
  cin>>n;
  int size=isPrime((int)((float)n*1.3)) ? (int)((float)n*1.3) : (int)((float)(n+1)*1.3);
  emp table[size],temp;
  for (int i=0;i<n;i++)
    {
      cout<<"Enter the data for Employee "<<i+1<<endl;
      temp.input();
      if(table[i].check())
        table[Hash(temp,size)]=temp;
      else
        table[Probe(table,size,Hash(temp,size))]=temp;
    }
  cout<<"\nEnter the ID of the Employee for searching: ";
  cin>>key;
  int contestedkey=Hash_check(key,size);
  cout<<"\n";
  if (printcheck(table, contestedkey))
    table[contestedkey].display();
  else
  {
    table[checkid(table ,key, size)].display();  
  }
  return 0;
  }
