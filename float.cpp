#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    float a,b,c;
    cin>>a;
    c=10*a;
    b=(int(c)/1000+((int(c)/100)%10)*10+((int(c)/10)%10)*100+(int(c)%10)*1000)*0.001;
    cout<<b;
    return 0;
}