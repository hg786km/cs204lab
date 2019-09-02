#include <bits/stdc++.h>
#define lli long long int
#define f(a, b, c) for (lli a = b; a < c; a++)
using namespace std;
//map<string, string> mp;

vector<string> subvector(vector<string> const &v, int m) {
   auto first = v.begin() + m;
   auto last = v.end();
   vector<string> vector(first, last);
   return vector;
}


void print(vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	}
}

vector<string> sTv(string s)
{
    vector<string> vectoreq;

    int len = s.length();
    for(int i = 0; i<len;i++)
    {
        string temp="";
        if((s[i] >= '0' && s[i] <= '9')||isalpha(s[i]))
        {
           while(i!=s.size()&&s[i]>='0'&&s[i]<='9'||isalpha(s[i]))
           {
            temp+=s[i];
            i++;
           }
           i--;
        }
        else
        {
            temp+=s[i];
        }
        vectoreq.push_back(temp);

    }

    return vectoreq;
}

bool isoperator(char c)
{
  if(c=='+'||c=='-'||c=='^'||c=='*'||c=='/'||c=='$')
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
    st.push("Null");
    int l = s.size();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i][0] >= '0' && s[i][0] <= '9'))
            ns.push_back(s[i]);

        else if(isalpha(s[i][0]))
        {
          ns.push_back(s[i]);
        }

        else if(s[i] == "(")
            st.push("(");

        else if(s[i] == ")")
        {
            while(st.top() != "Null" && st.top() != "(")
            {
                string c = st.top();
                st.pop();
                ns.push_back(c);
            }
            if(st.top() == "(")
            {
                //string c = st.top();
                st.pop();
            }
        }
        else{
            while(st.top() != "Null" &&( precedence(s[i]) <= precedence(st.top()) )&& s[i]!="$")
            {
                if(s[i]=="^"&&st.top()=="^") break;
                string c = st.top();
                st.pop();
                ns.push_back(c);
            }
            st.push(s[i]);
        }

    }
    while(st.top() != "Null")
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

mynode* ct(vector <string> &PFIX, vector <string> &strv2, vector <string> &strv3)
{
       mynode *root=NULL;
       vector <mynode*> stack1;
       int i=0;
       while(i!=PFIX.size())
       {
               if(PFIX[i]!="+" && PFIX[i]!="-" && PFIX[i]!="*" && PFIX[i]!="/" && PFIX[i]!="^" && PFIX[i]!="$")
                 {

                       mynode *temp=(mynode *)malloc(sizeof(mynode));
                       if(isalpha(PFIX[i][0]))
                      {
                         int pos=lower_bound(strv2.begin(),strv2.end(),PFIX[i])-strv2.begin();
                         if(pos==strv2.size())return NULL;
                           if(strv2[pos]!=PFIX[i])
                              return NULL;
                           else
                           {
                             if(strv3[pos]=="")
                               return NULL;
                             else
                             {
                               temp->s=PFIX[i];
                               stack1.push_back(temp);
                             } 
                           }
                      }
                       else
                     {
                       temp->s=PFIX[i];
                        stack1.push_back(temp);
                    }
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
                if(stack1.size()<1)
                  return NULL;


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

lli evaluate(mynode *root,vector <string> &strv2, vector <string> &strv3)
{
   string s=root->s;
   //cout<<s<<"\n";
   lli answer=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^" && s!="$")
   {
      int pos=lower_bound(strv2.begin(),strv2.end(),s)-strv2.begin();
     if(pos==strv2.size())
      return stoi(s);
     if(strv2[pos]!=s)
      return stoi(s);
    return stoi(strv3[pos]);
   }
   else
   {
     lli lanswer=evaluate(root->myleft,strv2,strv3),ranswer=0;
     if(root->myright!=NULL)ranswer=evaluate(root->myright,strv2,strv3);
     /*if(s!="$")
      ranswer = evaluate(root->myright);*/

     if(s=="+")
       answer=lanswer+ranswer;
     else if(s=="-")
       answer=lanswer-ranswer;
     else if(s=="*")
       answer=lanswer*ranswer;
     else if(s=="/")
       {
           answer=lanswer/ranswer;
        } 
     else if(s=="^")
     {
       answer=1;
       if(ranswer<0) answer=0;
       f(i,0,ranswer)answer*=lanswer;
     }
     else
     {
       answer=-evaluate(root->myleft,strv2,strv3);
     }
   }
   return answer;
}

int main() 
{
  int q;
  cin>>q;
  while(q--)
  {
    int n;
    cin>>n;
    vector <string> strv;
    vector <pair<vector <string>,string>> relate(n);
    for (lli k = 0; k < n; k++)
      {
          string s,s1;
          cin>>s;
          bool flag=false;

          for (lli j = 0; j < s.size(); j++)
            if(s[j]=='=') flag=true;

          int j=0;

          string temp="";

          if(flag)
          {
            while(s[j]!='=')
            {
              temp.push_back(s[j]);
              j++;
            }
            
            j++;
          }

          for (lli i = j; i < s.size(); i++)
          {
            if(s[i]=='-')
            {
              if(i==j||s[i-1]=='('|| s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='^'||s[i-1]=='*'||s[i-1]=='/')
              {
                s1.push_back('$');
                continue;
              }
            }
            s1.push_back(s[i]);
          }

          vector <string> postfix=sTv(s1);

          postfix=I2P(postfix);

          relate[k].first=postfix;

          relate[k].second=temp;

          if(j)
          {
            strv.push_back(temp);
          }

      }

      sort(strv.begin(),strv.end());
      vector <string> strv2;
      for(int i=0;i<(int)strv.size()-1;i++)
      {
        if(strv[i]!=strv[i+1])
          strv2.push_back(strv[i]);
      }

      if(strv.size()>0)
            strv2.push_back(strv.back());

      vector <string> strv3(strv2.size(),"");

      for(lli k=0;k<n;k++)
      {
          if(relate[k].second=="")
          {
            mynode *root=ct(relate[k].first,strv2,strv3);
            if(root==NULL)
                cout<<"CAN'T BE EVALUATED\n";
            else
                cout<<evaluate(root,strv2,strv3)<<"\n";  
          }
          else
          {
            int pos = lower_bound(strv2.begin(),strv2.end(),relate[k].second)-strv2.begin();
            
            mynode *root=ct(relate[k].first,strv2,strv3);
            
            if(root!=NULL)
             strv3[pos]=to_string(evaluate(root,strv2,strv3));
          }
      }
  }
  return 0;   
}
