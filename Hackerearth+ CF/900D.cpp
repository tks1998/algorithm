#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int base=1e9+7;
map<int,ll> M;
ll pow(int n)
{
    if (n==0) return 0;
    if (n==1) return 2;
    ll t=pow(n/2);
    t=t*t%base;
    if (n%2==1) t=t*2%base;
    return t;
}
int calculate(int n)
{
    if (n==1) return 1;
    if (M.find(n)!=M.end()) return M[n];
    ll kq;
    kq=pow(n-1)%base-1;
    for (int i=2 ; i*i<=n ; i++)
    {
        if (n%i==0 )
        {
            if (i*i!=n) kq=kq-calculate(i)-calculate(n/i);
            else kq=kq-calculate(i);
            kq=(kq+base)%base;
        }
    }
    M[n]=kq;
    return kq;
}
int main()
{
    int x ,y;
    cin>>x>>y;
    if (y%x!=0) cout<<0;
    else
    {
        cout<<calculate(y/x);
    }
    return 0;
}
