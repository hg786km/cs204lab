#include <bits/stdc++.h>
using namespace std;
// 10 ^ 8
#define fi(nn) for(int i = 0;i<nn;i++)
#define fir(nn) for(int i = nn-1;i>=0;i--)
#define fi1(nn,aa) for(int i = 0; i< nn; i+=aa)
#define fir1(nn,en) for(int i = nn-1;i>=en;i--)
#define fi2(init,nn,aa) for(int i = init; i< nn; i+=aa)
#define fir2(nn,en,aa) for(int i = nn-1;i>=en;i-=aa)
#define fj(nn) for(int j = 0;j<nn;j++)
#define fj1(nn,aa) for(int j = 0; j< nn; j+=aa)
#define fj2(init,nn,aa) for(int j = init; j< nn; j+=aa)
#define lli long long int  
#define line cout<<endl
#define vc vector<char>
#define vi vector<int>
#define vlli vector<lli>
#define vs vector<string>
// function to check if paranthesis are balanced 

/*bool comparestring(string s1, string s2)
{
	if(s1.size()==s2.size())
	{
		if(s1>s2)
		{
			return true;
		}
		else{
			return false;
		}
	}
	else if(s1.size()>s2.size())
	{
		string r = s1.substr(0,s2.size());
		if(r<=s2)
		{
			return false;
		}
		else{
			return true;
		}

	}
	else if(s1.size()<s2.size())
	{
		string r = s2.substr(0,s1.size());
		if(r<=s1)
		{
			return true;
		}
		else{
			return false;
		}

	}
	return true;
} */

string giveThirty()
{
	string s="";
	fi(30)
	{
		s+=to_string(rand()%10);
	}
	return s;
}
bool comparestring(string s1, string s2)
{
	string s = s1+s2;
	string g = s2+s1;
	return s>g;
}
int main () 
{ 
//	string s1,s2;
//	cin>>s1>>s2;
//	cout<<comparestring(s1,s2);
	lli q;
	cin>>q;
	while(q--)
	{
		lli t;
		cin>>t;
		vs vstr;
		string s;
		while(t--)
		{
			//s =giveThirty();
			//cout<<s; line;
			cin>>s;
			vstr.push_back(s);
		}
		sort(vstr.begin(), vstr.end(), comparestring);
		fi(vstr.size())
		{
			cout<<vstr[i];
		}
		line;
	}


/*	cin>>t;
	vs vstr(t);
	fi(t)
	{
		cin>>vstr[i];
	}
	*/	
    return 0; 
}
