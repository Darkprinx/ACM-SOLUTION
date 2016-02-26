/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~

   Problem Name: 599 - The Forrest for the Trees
       Platform: Uva
     Algorithom: Graph
  Author's Name: RC Tushar




   ~~~     Never Lost Hope     ~~~

*/


#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define PS system("pause")
#define liter(n,T1)  for(list<T1>::iterator it=n.begin();it!=n.end();it++)
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
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pf printf
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define sqr(x) (( (x)* (x))%MOD)
#define cube(x)   ( (sqr(x)*(x))%MOD)
#define bit_cnt(x)   __builtin_popcount(x)
#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define btz(a)   __builtin_ctz(a)
#define Mems(p,n) memset(p, n, sizeof(p))
#define makeint(n,s)  istringstream(s)>>n
#define BOUNDARY(i,j,Row,Col) ((i >= 0 && i < Row) && (j >= 0 && j < Col))
#define ubound(d,val)  int (upper_bound (d.begin(), d.end(), val) - d.begin())
#define lbound(d,val)  int (lower_bound (d.begin(), d.end(), val) - d.begin())
#define M 123456
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<char,char> pcc;
typedef pair<ll,bool> pib;
typedef pair<double,int> pdi;
typedef pair<int,string> pis;


//FAST_INPUT
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



//~~~~~~~~~~~~CODE STARTING POINT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

vi nod[200];
bool mark[200];


void dfs(int u)
{
    for(int i=0; i<nod[u].size(); i++)
    {
        int v=nod[u][i];
        if(!mark[v])
        {
            mark[v]=true;
            dfs(v);
        }
    }
}

int main()
{
    int test,cnt,mnt;
    fs(test);
    string str;



    while(test--)
    {
        Mems(mark,false);

        for(int i='A'; i<='Z'; i++)
            nod[i].clear();
        cnt=mnt=0;
        while(cin>>str&&str[0]!='*')
        {
            nod[str[1]].pb(str[3]);
            nod[str[3]].pb(str[1]);
        }
        cin>>str;
        for(int i=0; str[i]; i++)
            if(i%2==0&&!mark[str[i]])
            {
                dfs(str[i]);
                cnt++;
            }

        for(int i=0; str[i]; i++)
            if(i%2==0&&!mark[str[i]])
                mnt++;

        printf("There are %d tree(s) and %d acorn(s).\n",cnt-mnt,mnt);
    }

}
