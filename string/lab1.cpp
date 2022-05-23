#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string a ="I am a student", b=" in CUET";
    //cin >> a >> b;
    cout<<a.substr(1,2)<<endl;
    cout<<a.insert(3,"m")<<endl;
    cout<<a.replace(2,2,"are")<<endl;
    a.erase(3,7);
    cout<<a<<endl;
    cout<<a+b<<endl;
    return 0;
}
