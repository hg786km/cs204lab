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

bool greaterORequal(string s1, string s2){
    if(s2.size() < s1.size())
    {
        return true;
    }
    else if((s2 <= s1) && (s2.size() == s1.size()))
    {
        return true;
    }
    return false;
}
string divide(string s1, string s2){
    if(s2.size() > s1.size()){
        string s=s1;
        s1=s2;
        s2=s;
    }
    else if(s2 > s1 && s2.size() == s1.size()){
        string s=s1;
        s1=s2;
        s2=s;
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

        if(!flag && !greaterORequal(dividend, divisor)){

            return dividend;
        }
        int j2=0;
        while(greaterORequal(dividend, divisor)){
            divisor = Add_strings(divisor, s2);
            j2++;
        }
        divisor = subtract(divisor, s2);
        remainder = subtract(dividend, divisor);
        if(j2 != 0){
            answer += j2+'0';
        }

    }
}
bool OnlyGreater(string s1, string s2){
    if(s2.size() < s1.size()){
        return true;
    }else if(s2 < s1 && s2.size() == s1.size()){
        return true;
    }
    return false;
}
void prime(string one){
    string s = "2";
    if(one == "2"){
        cout<<"Prime\n";
        return;
    }
    if(one == "3"){
        cout<<"Prime\n";
        return;
    }
    while(OnlyGreater(one, s)){
        if(divide(one, s) == "0"){
            cout<<"Not a Prime\n";
            return;
        }
        if(s == "2"){
        s = Add_strings(s, "1");}
        else{s = Add_strings(s, "2");
        }
    }
    cout<<"Prime\n";
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        prime(s);
    }
}