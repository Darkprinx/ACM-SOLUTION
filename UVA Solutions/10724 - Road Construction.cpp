
/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 10724 - Road Construction
       Platform: Uva
     Algorithom: Floyed Warshal
  Author's Name: RC Tushar




         ~~~~~ MY DEDICATION TO SOME FRIENDS ~~~~~

   Kim: Whenever you start to believe yourself, people also start to believe in you.
  Oshy: Every programming contest is like a new life.To do better in every life you must dedicate your real life.
 Elise: Keep studying and the improvement will come. it's a slow process but each step is rewarding.


 ~~~     Never Lose Hope     ~~~
*/


#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
#define meter(n,T1,T2)  for(map<T1,T2>::iterator it=n.end();it!=n.begin();it--)
#define FOR(s,e,inc) for(int i=s;i<=e;i+=inc)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define Sfor(n) for(int i=1;i<=n;i++)
#define inf (1<<30)
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-9
#define gcd(x,y) __gcd(x,y)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define on(x,w)  x=x|(1<<w)
#define check(x,w) (x&(1<<w))==(1<<w)?true:false
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtin_popcount(x)
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())

using namespace std;

//int dx[]= {1,0,-1,0};
//int dy[]= {0,1,0,-1};                        //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,bool> pib;
typedef pair<double,double> pdd;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;
typedef pair< int, pii> ipii;
typedef pair< int, string> pis;


//TEMPLATES
template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


int sat(int n,int pos)
{
    return n=n | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool cak(int n,int pos)
{
    return (bool)(n&(1<<pos));
}

ll binPow(ll a, ll q, ll mud)
{
    a %= mud;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}

template<class T>
double dif(T a,T b)
{
    ll ans=(a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
    return sqrt(ans);
}

#define M  100000


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    double tot;
    double ds;
    int u,v;
    st (double a,double b,int c,int d)
    {
        tot=a;
        ds=b;
        u=c;
        v=d;
    }
    bool operator <(const st& op)const
    {
        if(tot==op.tot)
            return ds<op.ds;
        return tot>op.tot;
    }
};

ll n,m,x,y;
pll ara[105];
double cost[105][105];


void clr()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            cost[i][j]=1e14;
        cost[i][i]=0;
    }
}

int main()
{
    while(fs(n)&&fs(m)&&n&&m)
    {
        clr();

        loop(i,1,n+1)
        {
            fs(ara[i].F);
            fs(ara[i].S);
        }

        loop(i,0,m)
        {
            fs(x);
            fs(y);
            cost[x][y]=cost[y][x]=dif(ara[x],ara[y]);
        }

        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);

        st ans(0,1e12,100,100);

        for(int u=1; u<=n; u++)
            for(int v=u+1; v<=n; v++)
            {
                double sum=0;
                double uv=dif(ara[u],ara[v]);
                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                        sum+=(cost[i][j]-min3(cost[i][j],cost[i][u]+uv+cost[v][j],cost[i][v]+uv+cost[u][j]));
                ans=min(ans,st(sum,uv,u,v));
            }

        if(ans.tot<=1)
            pf("No road required\n");
        else
            pf("%d %d\n",ans.u,ans.v);
    }

    return 0;
}
