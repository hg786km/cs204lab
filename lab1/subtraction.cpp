#include<bits/stdc++.h>
using namespace std;

bool is_small(string first, string second)
{
	int n1 = first.length(), n2 = second.length();

	if (n1 < n2)
	return true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (first[i] < second[i])
		return true;
	else if (first[i] > second[i])
		return false;

	return false;
}
string subtract(string first, string second)
{
	if (is_small(first, second))
		swap(first, second);
	string final = "";
	int n1 = first.length(), n2 = second.length();
	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	int carry = 0;
	for (int i=0; i<n2; i++)
	{
		int sub = ((first[i]-'0')-(second[i]-'0')-carry);
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		final.push_back(sub + '0');
	}
	for (int i=n2; i<n1; i++)
	{
		int sub = ((first[i]-'0') - carry);
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;
		final.push_back(sub + '0');
	}
	reverse(final.begin(), final.end());
	return final;
}

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		string c = subtract(a,b);
		cout<<c<<"\n";
	}

	return 0;
}
