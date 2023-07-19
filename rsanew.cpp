#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool checkPrime(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0) 
        return false;
    }
    return true;
}
int gcd(int a, int b)
{
    if (b==0)return a;
    return gcd(b, a % b);   
}
int decrypter(int x , int key , int n)
{
    int v = 1;
    while(key--)
    {
        v *=x;
        v %=n;
    }
    return v;
}
string decoder(vector<int> message , int key , int n)
{
    string ans;
    int c;
    for(int i=0;i<message.size();i++)
    {
        c = decrypter(message[i],key,n);
        ans+=c;
    }
    return ans;
}
int encrypt(int c , int key,int n)
{
    int x=1;
    while(key--)
    {
        x*=c;
        x%=n;
    }
    return x;
}
vector<int> encoder(string Message  , int publicKey , int n)
{
    vector<int> encryptmessage;
    int x;
    for(int i=0;i<Message.size();i++)
    {
        x = encrypt((int)Message[i],publicKey,n);
        encryptmessage.push_back(x);
    }
    return encryptmessage;
    
}
int main()
{
    int prime1=0,prime2=0;
    int n=0;
    int fi=0;
    int publicKey=0;
    int privateKey = 0;
    label1: cin>>prime1;
    if(checkPrime(prime1)==false)
    {
        cout<<"reenter Prime1"<<endl;
        goto label1;
    }
    label2: cin>>prime2;
    if(checkPrime(prime2)==false || prime1==prime2)
    {
        cout<<"reenter Prime2"<<endl;
        goto label2;
    }
    n = prime1*prime2;
    fi = (prime1-1)*(prime2-1);
    int e=2;
    while(1)
    {
        if(gcd(e,fi)==1)
        break;
        e++;
    }
    publicKey = e;
    cout<<endl<<publicKey<<endl;
    int d=2;
    while(1)
    {
        if((d*e)%fi==1)
        break;
        d++;
    }
    privateKey = d;
    cout<<endl<<privateKey<<endl;
    cout<<"Enter the Message"<<endl;
    string Message;
    cin.ignore();
    getline(cin,Message);
    vector<int> encrypted;
    encrypted = encoder(Message,publicKey,n);
    // for(int i=0;i<encrypted.size();i++)
    // {
    //     cout<<encrypted[i];
    // }
    string decrypt;
    cout<<decrypt;
    cout<<1;
    decrypt = decoder(encrypted,privateKey,n);
    cout<<decrypt;
    return 0;
}
//////note using higher value of the prime number gets more chance for the correct ans