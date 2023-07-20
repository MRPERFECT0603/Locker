#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string cipher(string message, int key)
{   
    for(int i=0;i<message.size();i++)
    {
        message[i] = message[i]+(key % 26);
    }
    return message;
}
string decipher(string message, int key)
{
    for(int i=0;i<message.size();i++)
    {
        message[i] = message[i]-(key % 26);
    }
    return message;
}
int main()
{
    int key;
    string message;
    getline(cin,message);
    cin>>key;
    cout<<endl;
    cout<<"The message is:"<<endl;
    cout<<message;
    message=cipher(message,key);
    cout<<"\n the encrypted message is:"<<endl;
    cout<<message;
    message=decipher(message,key);
    cout<<"\n the decrypted message is:"<<endl;
    cout<<message;
    return 0;
}