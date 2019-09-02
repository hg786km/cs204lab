#include <bits/stdc++.h>
#define lli long long int
#define f(a, b, c) for (lli a = b; a < c; a++)
using namespace std;

int main()
{
	lli n,q,q1;
	lli a,b;
	cin>>n;
	vector<int> users(n+1, 0);
	//cout << "capacity: " << (lli) users.capacity() << '\n';
	lli maxval = 0;
	lli maxuser = 0;
	cin>>q;
	while(q--)
	{
		int c;
		cin>>c;
		if(c==2)
		{
			//check whether an element or not
			//if yes accesss the data structure to get the element
			if(maxuser==0)
			{
				cout<<"No data available\n";
			}
			else cout<<maxuser<<endl;
		}
		else{
			cin>>a>>b;
			//insert a and b to the DS
			users[a]=users[a]+b;
			if(users[a]>maxval)
			{
				maxval = users[a];
				maxuser=a;
			}

		}
	}
}
