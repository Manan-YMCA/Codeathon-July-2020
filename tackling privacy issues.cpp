/*
********************
Author : Sahil Kundu
********************
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
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
#define rep(i,n) for(int i=0;i<(n);++i)
#define repa(i,n) for(int i=n-1;i>=0;i--)
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define PI       3.14159265358979323846
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
const ll MAX=1e5+5;
const ll INF=2e18;

#define INPUT_OUTPUT {\
	freopen("sample.txt","r",stdin);\
	freopen("outputsample.txt","w",stdout);\
}
struct Point{
    ll x,y;
    void input()// taking input 
    {
        cin>>x>>y;
    }
}base;

// function to check orientation of 3 points.
int crossproduct(Point a, Point b, Point c) 
{
    ld x1=a.x-b.x;
    ld x2=a.x-c.x;
    ld y1=a.y-b.y;
    ld y2=a.y-c.y;
    ld res1=x1*y2,res2=x2*y1;
    if(res1>res2)return 1; // c lies left to ab line segment
    else if(res1==res2) return 0;// points are collinear
    else return -1; //c lies right to ab line segment
}

int distance(Point a,Point b,Point c)// function for compairing distances.
{
    ld x1=a.x-b.x;
    ld x2=a.x-c.x;
    ld y1=a.y-b.y;
    ld y2=a.y-c.y;
    ld d1= x1*x1 + y1*y1 ;
    ld d2= x2*x2 + y2*y2 ;
    if(d1>d2)return 1;// if b is farther than c to a.
    else return 0;
}

bool comp(Point a,Point b)// compare function for sorting.
{
    int val = crossproduct(base, a, b);
    if(val == 1)// if b is left of base-a 
        return true;
    if(val == -1)
        return false; // if b is right of base-a
    val = distance(base, a, b); // if collinear then nearer to base will come first
    if(val) return false;
    return true;
}


vector<Point> convex_hull(vector<Point> p , int n)// Graham scan algo for convex hull.
{
    int mi=0,miny=p[0].y;
    rep(i,n) // selecting lowest value of y. 
    {
        int y=p[i].y;
        if(miny > y or (miny == y and p[i].x < p[mi].x))
        {
            mi = i;
            miny = y;
        }
    }
    swap(p[0], p[mi]);
    base = p[0];// lowest point in y direction
    sort(p.begin()+1, p.end(), comp);// sort according to angles. right to base first
    stack<Point>hull;
    hull.push(base);
    hull.push(p[1]);
    rep(i,n)
    {
        if(i<2)continue;
        Point c = p[i];
        while(hull.size()>1)
        {
            Point a,b;
            b = hull.top();
            hull.pop();
            a = hull.top();
            int orient = crossproduct(a,b,c);
            if(orient != -1)// if c is not on right of ab line segment
            {
                hull.push(b);
                break;
            }
        }
        hull.push(c);
    }
    Point last=hull.top();
    repa(i,n)// this loop will handle all collinear points to the last point in hull
    {        // because during sorting left collinear points are reversed.
        if(last.x != p[i].x or last.y != p[i].y)
        {
            if(!crossproduct(base,last,p[i]))
                hull.push(p[i]);
        }
    }
    vector<Point> res;
    map<pll,ll>mp;
    while(hull.size())// inserting hull points in clockwise manner in vector.
    {
        Point px = hull.top();
        pll xt = {px.x,px.y};
        if(mp[xt]==0){
        res.pb(hull.top());}
        mp[xt]++;
        hull.pop();
    }
    return res;
}
   
// removing points that lies in boundaries of hull.
vector<Point> duplicate(vector<Point> convhull,vector<Point> pts){
	vector<Point> pp;
	for(auto i:pts){
		bool f = true;
		for(auto j:convhull){
			if(i.x==j.x and i.y==j.y){
				f= false;
				break;
			}
		}
		if(f)
			pp.push_back(i);
	}
	return pp;
}

bool check(vector<Point> hull , Point pt)
{
    ll n=hull.size();
    //rep(i,n)hull[i].output();
    //cout<<" done "<<endl;
	rep(i,n-1)
    {   
        ll val=crossproduct(hull[i],hull[i+1],pt);
        if(val>=0)
            return false;
    }
    if(hull[0].x != hull[n-1].x or hull[0].y != hull[n-1].y)
    {
        if(crossproduct(hull[0],hull[n-1],pt)>=0)
            return false;
    }
    return true;
}

// function to check is all points are not collinear
bool valid(vector<Point> pts,int n)
{ 
    if(n<3)
    	return false;
   	Point a,b;
   	a = pts[0];
   	b = pts[1];
   	for(int i=2;i<n;i++){
   		Point c = pts[i];
   		int col = crossproduct(a,b,c);
   		a = b;
   		b = c;
   		if(col)
   			return true;
   	}
   	return false;
} 

// logical code of program starts here.
void solve()
{
    int n,q;
    cin>>n;
    //cin>>n>>q;
    //cout<<q<<endl;
    vector<Point> p(n);
    for(int i=0;i<n;i++)
        p[i].input();
    
    // code for problem.
    vector<Point> hull = convex_hull(p,p.size());
    if(hull.size()>=3)
    cout<<hull.size()<<endl;
else cout<<0<<endl;
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