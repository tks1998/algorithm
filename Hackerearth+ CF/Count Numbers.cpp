#include <bits/stdc++.h>

using namespace std;
int sx,sy,n,t,x,y,count_;
long long mul;
int a[20];
int main()
{
    cin>>n>>t;
    for (int i=0; i<n ; i++)
    {
        cin>>a[i];
    }
    while (t-->0)
    {
        sy=0,sx=0;
        cin>>x>>y;
        for (int i=1 ; i<(1<<n) ; i++)
        {
            mul=1;
            count_=0;
            for (int k=0 ; k<n ; k++)
            {
                if (i&(1<<k))
                {
                    count_++;
                    mul*=a[k];
                }
            }
            if (count_%2==1)
            {
                sy+=y/mul;
                sx+=(x-1)/mul;
            }
            else
            {
                sy-=y/mul;
                sx-=(x-1)/mul;
            }
        }
        cout<<sy-sx<<endl;
    }
    return 0;
}
