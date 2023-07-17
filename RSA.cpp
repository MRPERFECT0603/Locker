#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
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
int minverse(int a , int t)
{
    int c = 0,k=0;
    while(1)
    {
        c=1+k*t;
        if(c % a == 0)
            return(c/a);
            k++;
    }
}
void rsa()
{
    int p,q;
    labelp:cin>>p;
    bool flag;
    flag = checkPrime(p);
    if(flag==false)
    {
        cout<<"renter p";
        goto labelp;
    }
    labelq:cin>>q;
    flag = checkPrime(q);
    if(flag==false)
    {
        cout<<"renter q";
        goto labelq;
    }
    cout<<p<<q;
    int n = p*q;
    int t = (p-1)*(q-1);
    int k=0;
    int e=0,d=0;
    for(int i=2;i<t;i++)
    {
        if(t%i==0 || checkPrime(i)==false)
        continue;
        if(i!=p && i!=q)
        {
            e=i;
            flag= minverse(e,t);
            if(flag>0)
            {
                d=flag;
                k++;
            }
        }
        if(e!=0&&d!=0)
            break;
    }
    cout<<e<<endl<<d<<endl;;
}
int main()
{
    rsa();
    return 0;
}