
#include<bits/stdc++.h>
using namespace std;
string addition(string first, string second) 
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
bool is_small(string first, string second)
{
	int n1 = first.length(), n2 = second.length();

	if (n1 < n2)
		return true;
	else if (n2 < n1)
		return false;
	else if((n1==n2)&&(first<second))
		return true;
	else
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

bool greaterORequal(string s1, string s2){
    if(s2.size() < s1.size()){
        return true;
    }else if(s2 <= s1 && s2.size() == s1.size()){
        return true;
    }
    return false;
}
void division(string s1, string s2){
	if(is_small(s1,s2))
	{
		cout<<"0 0"<<endl;
		return;
	}
    string remainder="";
    string answer="";

    int j=0;
    while(1){
        string divisor=s2;
        string dividend = remainder;
        bool flag= false;
        if(j == 0){
            for(int i=j; i<s1.size(); i++){
            dividend += s1[i];
            if(greaterORequal(dividend, divisor)){
                j = i+1;
                flag = true;
                break;
                }
            }
        }
        else{
        for(int i=j; i<s1.size(); i++){
            dividend += s1[i];
            string sm="";
            for(int k =0 ; k<dividend.size(); k++){
                if(dividend[k] == '0' && sm == ""){
                    continue;
                }
                else{sm += dividend[k];}
            }
            dividend = sm;
            if(greaterORequal(dividend, divisor)){
                j = i+1;
                flag = true;
                break;
            }
            answer += '0';
        }}
        if(dividend == ""){dividend = '0';}
        //cout<<divisor<<" "<<dividend<<endl;
        if(!flag && !greaterORequal(dividend, divisor)){
            cout<<answer<<"\n"<<dividend<<endl;
            return;
        }
        int j2=0;
        while(greaterORequal(dividend, divisor)){
            divisor = addition(divisor, s2);
            j2++;
        }
        //cout<<divisor<<endl;
        divisor = subtract(divisor, s2);
        remainder = subtract(dividend, divisor);
        if(j2 != 0){
            answer += j2+'0';
        }

    }
}

int main(){
    long long q;
    cin>>q;
    while(q--){
        string s1, s2;
        cin>>s1>>s2;
        division(s1, s2);
    }

}
