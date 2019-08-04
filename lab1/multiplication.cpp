#include<bits/stdc++.h>
using namespace std;

string Add_strings(string first, string second)
{

	if (first.length() > second.length())
		swap(first, second);
	string final = "";
	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	int carry = 0;
	for (int i=0; i<first.length(); i++)
	{
		int sum = ((first[i]-'0')+(second[i]-'0')+carry);
		final.push_back(sum%10 + '0');
		carry = sum/10;
	}
	for (int i=first.length(); i<second.length(); i++)
	{
		int sum = ((second[i]-'0')+carry);
		final.push_back(sum%10 + '0');
		carry = sum/10;
	}
	if (carry)
		final.push_back(carry+'0');
	reverse(final.begin(), final.end());
	return final;
}

string multiplication(string first, string second)
{
	string str="0",step2="";

	if (first.length() > second.length())
		swap(first, second);
	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	for(int i=0;i<first.length();i++)
	{
	    step2="";
		for(int j=0;j<i;j++)
			step2.push_back('0');
		int carry=0;
		for(int j=0;j<second.length();j++)
		{
			int product = ((first[i]-'0')*(second[j]-'0')+carry);
			step2.push_back(product%10 + '0');
			carry = product/10;
		}
		if (carry)
			step2.push_back(carry+'0');

        reverse(step2.begin(), step2.end());
		str=Add_strings(str,step2);
	}

	return str;

}

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		string c = multiplication(a,b);
		cout<<c<<"\n";
	}
	return 0;
}
