
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
int main() 
{ 
	string first,second;
	cin>>first>>second; 
	cout <<Add_strings(first, second); 
	return 0; 
} 
