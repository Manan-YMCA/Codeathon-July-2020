/*
********************
Author : Sahil Kundu
********************
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 998244353
#define pb(i) push_back(i)
#define f first
#define s second
#define mk(l,r) make_pair(l,r)
#define vi vector<int>
#define vl vector<ll>
#define vch vector<char>
#define all(vc) vc.begin(),vc.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ms(i,j) memset(i,j,sizeof i)
#define w(t) while(t--)
#define len(s) s.length()
#define rall(i,a) for(auto i : a)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repp(i,n,j) for (ll i=j;i<(n);i++)
#define repa(i,n) for(ll i=n-1;i>=0;i--)
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define PI 3.14159265358979323846
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
const ll MAX=2e6+5;
const ll INF=2e18;

#define INPUT_OUTPUT {\
    freopen("input.txt","r",stdin);\
    freopen("output.txt","w",stdout);\
}


// logical code of program starts here.
void solve()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    rep(i,n)cin>>a[i];
    int cnt=1,ans[n]={0};
    repa(i,n)
    {
        cnt=1;
        repp(j,n,i+1)
        {
            if(a[j]>=a[i])
                cnt=max(ans[j]+1,cnt);
        }
        ans[i]=cnt;
    }
    w(q)
    {
        int x,res=0;
        cin>>x;
        rep(i,n)
        {
            if(a[i]>=x)
                res=max(res,ans[i]);
        }
        cout<<res<<endl;
    }
}


// mian function 
int main()
{
    INPUT_OUTPUT;//file handling
    fastIO;// fast input output
    clock_t start, end; 
    start = clock();
    int t;
    t=1;
    //cin>>t;
    w(t) solve();
    end = clock();   
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC); 
    clog << "Time taken by program is : " << fixed 
    << time_taken << setprecision(5); 
    clog << " sec " << endl;
    return 0;
}