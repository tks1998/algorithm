#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int base=998244353;
ll pow(int n)
{
    if (n==0) return 1;
    if (n==1) return 2;
    ll t= pow(n/2);
    t=t*t % base;
    if (n%2==1) t=t*2% base;
    return t;
}
int main()
{
    int m,n;
    cin>>m>>n;
    ll kq=pow(n);
    kq=(kq-1)*(kq-1)% base;
    for (int i=1;i<m;i++)
    {
        kq=kq-(n*(m-i)%base) ;
        kq%=base;
    }
    kq=(kq+base)%base;
    cout<<kq<<endl;
    return 0;
}
