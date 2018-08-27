///=================================================///
///               BISHAL GAUTAM                     ///
///         [ bishalg.tech@gmail.com ]              ///
///=================================================///
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 1000001
#define MD 998244353LL
#define T long long
 T BigMod(T b,T p,T m) {
    T r=1;
    while(p) {
        if(p&1)r=(r*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return r;
}

ll fac[MX+2],bp[MX+2];

void preCal() {
    fac[0]=bp[0]=1;
    for(ll i=1; i<=MX ; i++) {
        fac[ i ]=( fac[i-1]*i )%MD;
        bp[i]=(bp[i-1]*2)%MD;
    }
}

ll nCk(int n,int k) {
    return (fac[n]*(( BigMod(fac[k],MD-2,MD)*BigMod(fac[n-k],MD-2,MD) )%MD ))%MD;

}

int main() {
    preCal();
    ll n,m;
    cin>>m>>n;
    ll tot=BigMod( (bp[m]-1+MD)%MD, n, MD);
    cout<<"trc "<<tot<<endl;
    for(int i = 1; i<=m ; i++) {
        ll ways= ( nCk(m,i)*BigMod( (bp[m-i]-1+MD)%MD, n,MD ) )%MD;
        if( i&1 )tot=(tot - ways + MD)%MD;
        else tot=(tot + ways)%MD;
        cout<<ways<<endl;
    }
    cout<<(tot+MD)%MD<< "\n";
    return 0;
}
