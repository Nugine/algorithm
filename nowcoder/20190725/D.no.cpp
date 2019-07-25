#include<iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qpow(ll b, ll p, ll m) {
    ll r = 1;
    b %= m;
    while (p) {
        if (p & 1) {
            r *= b;
            r %= m;
        }
        b *= b;
        b %= m;
        p >>= 1;
    }
    return r;
}



ll solve(){
    ll p,n,m;
    cin>>p>>n>>m;
    if(m==3){
        return (n-n/3)*m;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        ll ans = solve();
        cout<<ans<<endl;
    }
}

int _main()
{ 
    long long i,temp,a,b,resi,res,ans,m,n,k,phi;
    cin>>n;
    for (k=1;k<=n;k++)
    {
        cin>>m>>a>>b;
        if (m==3) cout<<(a-a/3)*b<<endl;
        else
        {
            phi=temp=m;
            for (i=2;i*i<=m;++i)
            {
                if (temp%i==0)
                {
                    phi=phi-phi/i;
                    while (temp%i==0)
                    {
                        temp/=i;
                    }
                }
            }
            if (temp>1)
            {
                phi=phi-phi/temp;
            }
            res=1;
            resi=0;
            for (i=1;i<=phi/2;i++)
            {
                if (phi%i==0)
                {
                    res=(res*ksm(10,i-resi,m))%m;
                    resi=i;
                    if (res==1) break;
                }
            }
            if (res==1) phi=i;
            cout<<(a/phi)*b<<endl;
        }
    }
    return 0;
}