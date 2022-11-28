#include <bits/stdc++.h> //include everything
using namespace std;

class InfixtoPostfix 
{
private:
stack<char> s;
public:
int precedence(char c);
void convert(string exp);
};

int InfixtoPostfix::precedence(char c)
{
  if (c=='^')
    return 3;
  else if (c=='*' || c=='/')
    return 2;
  else if (c=='+' || c=='-')
    return 1;
  return 0;
}

void InfixtoPostfix::convert(string exp)
{
  string res;
  for (int i=0;i<exp.length();i++)
    {
      if (exp[i]=='(')
        s.push('(');
        
      else if ((exp[i]>='A' && exp[i]<='Z') || (exp[i]>='a' && exp[i]<='z') || (exp[i]>='0' && exp[i]<='9'))
        res+=exp[i];
        
      else if (exp[i]==')')
      {
        while (s.top()!='(')
          {
            res+=s.top();
            s.pop();
          }
        s.pop();
      }
        
      else { //operator is scanned
        while (!s.empty() && (precedence(exp[i]) <= precedence(s.top())))
          {
            res+=s.top();
            s.pop();
          }
        s.push(exp[i]);
      }
    }
  while (!s.empty())
    {
      res+=s.top();
      s.pop();
    }
  
  cout<<"\nOutput Postfix Expression: "<<res<<"\n";
}

int main() {
  InfixtoPostfix t;
  //string exp="K+L-M*N+(O^P)*W/U/V*T+Q";
string exp="(a+(b*c/d)-e)";
  cout<<"Input Infix Expression: "<<exp;
  t.convert(exp);
  return 0;
}
