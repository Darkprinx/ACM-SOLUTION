/*

   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 1150 - GHOSTS!
       Platform: LightOj
      Algorithm: Bipartite matching
  Author's Name: RC Tushar


      ~~~    Never Lose Hope     ~~~
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
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define sz(x) ((int)x.size())
#define eps 1e-11
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
#define inf (1<<29)
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define bit_cnt(x)   __builtin_popcount(x)
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define BOUNDARY(i,j,Row,Col) ((i >= 1 && i <= Row) && (j >= 1 && j <= Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())

using namespace std;

int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};                        //4 Direction
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
typedef pair< int, pii> ipii;
typedef pair< int, string> pis;
typedef pair< string,int> psi;

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


ll sat(ll n,ll pos)
{
    return n=n | (1LL<<pos);
}
ll reset(ll N,ll pos)
{
    return N= N & ~(1LL<<pos);
}
bool cak(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}

ll binPow(ll a, ll q, ll mud)
{
    a %= mud;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2, mud)) % mud;
}

pll ex_clid(ll a,ll b)
{
    if(b==0)
        return pll(1,0);
    pll d=ex_clid(b,a%b);
    return pll(d.S,d.F-d.S*(a/b));
}

ll mod_inv(ll n,ll md)
{
    pll d=ex_clid(n,md);
    return ((d.F%md)+md)%md;
}


template<class T>
double dif(T &a,T& b)
{
    double ans=(a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
    return sqrt(ans);
}

#define M    1000000
//#define mod  (ull)pow(2,64)


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Code Starting Point ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char ara[30][30];
int cost[500][500],hum[500][500],d[30][30];
int n,gh,hh;
bool mark[5000];
int par[5000];
vi nod[5000];

void bfs(int x,int y)
{
    Mems(d,-1);
    queue<pii> q;
    d[x][y]=0;
    q.push(pii(x,y));

    while(!q.empty())
    {
        pii px=q.front();
        q.pop();
        if(ara[px.F][px.S]=='H')
            cost[gh][hum[px.F][px.S]]=d[px.F][px.S];

        pii nx;
        for(int i=0; i<4; i++)
        {
            nx.F=px.F+dx[i];
            nx.S=px.S+dy[i];
            if(d[nx.F][nx.S]==-1&&BOUNDARY(nx.F,nx.S,n,n)&&ara[nx.F][nx.S]!='#')
            {
                d[nx.F][nx.S]=d[px.F][px.S]+1;
                q.push(nx);
            }
        }
    }
}


bool dfs(int u)
{
    for(int i = 0; i < nod[u].size(); i++)
    {
        int v = nod[u][i];
        if(mark[v])
            continue;
        mark[v] = true;
        if(par[v] == -1 )
        {
            par[v] = u;
            return true;
        }
        if(dfs(par[v]))
        {
            par[v] = u;
            return true;
        }
    }
    return false;
}

int match()
{
    Mems(par,-1);
    int tot=0;
    for(int i=0; i<gh; i++)
    {
        Mems(mark,false);
        tot+=dfs(i);
    }
    return tot;
}

int solv()
{
    int mid,l=0,r=200000,mtc;

    while(l<r)
    {
        mid=(l+r)/2;
        for(int i=0; i<=gh*hh; i++)
            nod[i].clear();

        for(int i=0; i<gh; i++)
            for(int j=0; j<hh; j++)
                if(cost[i][j]<=mid&&cost[i][j])
                    nod[i].pb(j);

        mtc=match();
        if(mtc==hh)
            r=mid;
        else
            l=mid+1;
    }
    return r;
}

int main()
{

    int tt;
    fs(tt);

    for(int kk=1; kk<=tt; kk++)
    {
        fs(n);
        gh=0;
        hh=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                cin>>ara[i][j];
                if(ara[i][j]=='H')
                    hum[i][j]=hh++;
            }

        Mems(cost,0);

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(ara[i][j]=='G')
                {
                    bfs(i,j);
                    gh++;
                }
            }
        int ans=solv();
        if(ans==200000)
            pf("Case %d: Vuter Dol Kupokat\n",kk);
        else
        pf("Case %d: %d\n",kk,ans*2+2);
    }
    return 0;
}
