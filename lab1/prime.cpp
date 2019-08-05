#include <bits/stdc++.h>
using namespace std;
string increment_one(string str){

	reverse(str.begin(),str.end());

	int n=str.size();

	int carry=0;

	int sum=(str[0]-'0')+1;

	carry=sum/10;

	str[0]=(sum%10+'0');

	for(int i=1;i<n;i++){
		if(carry==0) 
			{
				reverse(str.begin(),str.end()); 
				return str;
			}
		else{
			sum=(str[i]-'0')+carry;
			str[i]=(sum%10+'0');
			carry=sum/10;
		}
	}
	if(carry)
		 str+=(carry+'0');
	reverse(str.begin(),str.end());
	return str;
}
bool is_small(string str1, string str2)
{
	int n1 = str1.length(), n2 = str2.length(); 

	if (n1 < n2) 
	return true; 
	if (n2 < n1) 
	return false; 

	for (int i=0; i<n1; i++) 
	if (str1[i] < str2[i]) 
		return true; 
	else if (str1[i] > str2[i]) 
		return false; 

	return false; 
}
bool is_small_or_equal(string str1, string str2) 
{ 
	int n1 = str1.length(), n2 = str2.length(); 

	if (n1 < n2) 
	return true; 
	if (n2 < n1) 
	return false; 

	for (int i=0; i<n1; i++) 
	if (str1[i] < str2[i]) 
		return true; 
	else if (str1[i] > str2[i]) 
		return false; 

	return true; 
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



string division(string a , string b){
	string ans="";
	string zero="0";


	if(is_small(a,b)) {
		return zero;
	}


	string r=a.substr(0,b.size());

	if(is_small(r,b)) {
		r=r+a[b.size()];
	}


	int size1=r.size();

	while(is_small_or_equal(b,r))
	{

		int i=0;

		while(is_small_or_equal(b,r)){
			
			r=subtract(b,r);
			
			int count=0;
			
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') 
					break;
				else 
					count++;
			}
			
			if(count<r.size()) 
				{r=r.substr(count,r.size()-count);}
			else
				{ r="";}
			i++;
		}

		ans+=(i+'0');

		if(size1>=a.size()) 
			break;

		r+=a[size1];

		size1+=1;

		int count=0;

    	for(int j=0;j<r.size();j++){
			if(r[j]!='0') 
				break;
			else 
				count++;
		}


		if(count<r.size()) 
			r=r.substr(count,r.size()-count);
		else 
			r="";


		while(is_small(r,b)&&size1<a.size()){
			r+=a[size1];
			size1++;
			ans+='0';
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) r=r.substr(count,r.size()-count);
			else r="";
		}
		if(is_small(r,b)) ans+='0';
	}
	
	if(r.size()==0) r="0";
	return r;
}

bool prime_or_not(string a){
	int n=a.size();

	n=n/2+1;

	string two="2";

	while(two.size()<=(n/2+1)&&is_small(two,a)){

		string r=division(a,two);

		if(r=="0") 
			return false;

		two=increment_one(two);

	}
	return true;
}


int main(){
	int q;
	cin>>q;
	while(q--){

		string str;
		
		cin>>str;


		if(prime_or_not(str)) 
			cout<<"Prime"<<endl;
		else 
			cout<<"Not a Prime"<<endl;
	}
	return 0;
}
