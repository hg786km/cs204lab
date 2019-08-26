#include <bits/stdc++.h>
#define lli long long int
#define f(a, b, c) for (lli a = b; a < c; a++)
using namespace std;
void print(vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	}
}

vector<string> sTv(string s)
{
    vector<string> stv;

    int len = s.length();
    for(int i = 0; i<len;i++)
    {
        string temp="";
        if((s[i] >= '0' && s[i] <= '9')||isalpha(s[i]))
        {
            int j = i;
            for(;(s[j] >= '0' && s[j] <= '9')||isalpha(s[j]);j++)
            {
                temp+=s[j];
            }
            i = j-1;
        }
/*        else if(s[i]=='-' and (s[i-1]=='('||i==0))
        {
            temp+=s[i];
            int j = i+1;
            for(;(s[j] >= '0' && s[j] <= '9');j++)
            {
                temp+=s[j];
            }
            i = j-1;
        }  */
        else
        {
            temp+=s[i];
        }
        stv.push_back(temp);

    }

    return stv;
}

bool isoperator(char c)
{
  if(c=='+'||c=='-'||c=='^'||c=='*'||c=='/')
  {
    return true;
  }
  return false;
}

int precedence(string c)
{
    if(c=="$")
      return 4;
    else if(c == "^")
    return 3;
    else if(c == "*" || c == "/")
    return 2;
    else if(c == "+" || c == "-")
    return 1;
    else
    return -1;
}



vector<string> I2P(vector<string> s)
{
    stack<string> st;
    st.push("N");
    int l = s.size();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i][0] >= '0' && s[i][0] <= '9')||isalpha(s[i][0]))
            ns.push_back(s[i]);
        else if(s[i] == "(")
            st.push("(");
        else if(s[i] == ")")
        {
            while(st.top() != "N" && st.top() != "(")
            {
                string c = st.top();
                st.pop();
                ns.push_back(c);
            }
            if(st.top() == "(")
            {
                string c = st.top();
                st.pop();
            }
        }
        else{
            while(st.top() != "N" && precedence(s[i]) <= precedence(st.top()))
            {
                if(s[i]=="^"&&st.top()=="^") break;
                string c = st.top();
                st.pop();
                ns.push_back(c);
            }
            st.push(s[i]);
        }

    }
    while(st.top() != "N")
    {
        string c = st.top();
        st.pop();
        ns.push_back(c);
    }

    return ns;

}

struct mynode
{
  string s;
  mynode* myleft=NULL,*myright=NULL;
};

mynode* ct(vector <string> PFIX)
{
       mynode *root=NULL;
       vector <mynode*> stack1;
       int i=0;
       while(i!=PFIX.size())
       {
         if(PFIX[i]!="+" && PFIX[i]!="-" && PFIX[i]!="*" && PFIX[i]!="/" && PFIX[i]!="^" && PFIX[i]!="$")
           {

                 mynode *temp=(mynode *)malloc(sizeof(mynode));

                 temp->s=PFIX[i];

                 //f(j,0,PFIX[i].size())

                 //if(PFIX[i][j]<'0' || PFIX[i][j]>'9')return NULL;

                 stack1.push_back(temp);
           }
         else if(PFIX[i]!="$")
         {
               if(stack1.size()<2)return NULL;

               mynode *s1=stack1.back();

               stack1.pop_back();

               mynode *s2=stack1.back();

               stack1.pop_back();

               mynode *temp=(mynode *)malloc(sizeof(mynode));

               temp->s=PFIX[i];

               temp->myleft=s2;

               temp->myright=s1;

               stack1.push_back(temp);
         }
         else
         {
                if(stack1.size()<1)return NULL;
                mynode *s1=stack1.back();
                stack1.pop_back();
                mynode *temp=(mynode *)malloc(sizeof(mynode));
                temp->myleft=s1;
                temp->s="$";
                stack1.push_back(temp);
         }
         i++;
       }
    if(stack1.size()!=1)
          return NULL;
    return stack1.back();
}


/*lli evaluate(mynode *root)
{
   string s=root->s;
   //cout<<s<<"\n";
   lli answer=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^" && s!="$")
//   return stoi(s);
   else
   {
     lli lanswer=evaluate(root->myleft),ranswer=0;
     if(s!="$")
      ranswer = evaluate(root->myright);

     if(s=="+")
       answer=lanswer+ranswer;
     else if(s=="-")
       answer=lanswer-ranswer;
     else if(s=="*")
       answer=lanswer*ranswer;
     else if(s=="/")
       {
          if(ranswer==0)
          {
            answer = std::numeric_limits<lli>::max();
          }
          else answer=lanswer/ranswer;
        }
     else if(s=="^")
     {
       answer=1;
       if(ranswer<0) answer=0;
       else f(i,0,ranswer)answer*=lanswer;
     }
     else
     {
       answer=-evaluate(root->myleft);
     }
   }
   return answer;
}*/
int main()
{
  int q;
  cin>>q;
  while(q--)
  {
    int n;
    cin>>n;
    for(lli i = 0;i<n;i++)
    {
      string s,s1;


      cin>>s;


     for(int i = 0; i<s.size() ; i++)
      {
        if(s[i]=='-')
        {
          if(i==0||s[i-1]=='('||isoperator(s[i-1]))
          {
            s1.push_back('$');
            continue;
          }
        }
        s1.push_back(s[i]);
      }


      vector <string> newv=sTv(s1);
  //    std::vector<string> v = {"-3","+","5"};
		print(newv);
		cout<<endl;
        newv=I2P(newv);
        print(newv);
  //    v = I2P(v);
  /*    mynode* root=ct(newv);
      //cout<<root->s<<"\n";
      if(root!=NULL)
        {
          if(evaluate(root)==std::numeric_limits<lli>::max())
            cout<<"CANT BE EVALUATED\n";
          else
              cout<<evaluate(root)<<"\n";
        }
      else
      {
        cout<<"CANT BE EVALUATED\n";
      }
*/
    }
  }


//  cout<<stoi("-3");
  return 0;
}
