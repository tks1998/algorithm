    #include <bits/stdc++.h>

    using namespace std;
    const int base=1e9 +7;
    const int maxn=1e6+10;
    int l,r,maxl,maxr; long long a[maxn];
    long long s;
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        int t,n;
        cin>>t;
        while (t-->0)
        {
            cin>>n;
            for (int i=1;i<=n;i++) cin>>a[i];
            l=1; r=n; maxl=0 ; maxr=0;
            s=0;
            while (l<=r)
            {
                if (a[l]<a[r])
                {
                   if (a[l]>maxl) maxl=a[l];
                   else s+=(maxl-a[l]) % base ;
                   l++;
                }
                else
                {
                    if (a[r]>maxr) maxr=a[r];
                    else s+=(maxr-a[r]) %  base;
                    r--;
                }
            }
            cout<<s% base <<'\n';
        }
        return 0;
    }
