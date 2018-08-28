#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxx=1e6+10;
const int base=1e9+7;
ll  a[maxx] , x , maxn , count_ ,n , l[maxx] , ans , pow_[maxx+10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ans=0;
    pow_[0]=1;
    for (int i=1;i<=n;i++) pow_[i]=pow_[i-1]*2 % base ;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[x]++;
        maxn=max(maxn,x);
    }
    for (int i=maxn ; i>1 ; i--)
    {
        count_=0;
        for (int j=i ; j<=maxn ; j+=i)  count_+=a[j];

        if (count_)
        {
            l[i]=count_*pow_[count_-1] % base ;
            for (int j=2*i ; j<=maxn ; j+=i) l[i]=(l[i]-l[j]+ base )% base ;
            ans=(ans+(l[i]*i % base ) ) % base ;

        }
    }
    cout<<ans;
    return 0;
}
