/*
   Problem Name: 1085 - All Possible Increasing Subsequences
       Platform: LightOj
     Algorithom: BIT
   Coder's Name: RC Tushar

~~~ Never Show Your Arrogance.Keep In Mind,You Were Born From A Drop Of Impure Liquid ~~~

*/

#include<bits/stdc++.h>

#define pi 2*acos(0.0)
#define PS system("pause")
#define siter(n,T1)  for(set<T1>::iterator it=n.begin();it!=n.end();it++)
#define miter(n,T1,T2)  for(map<T1,T2>::iterator it=n.begin();it!=n.end();it++)
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
#define fot(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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
#define M 100003
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;
typedef pair<int,int> pii;

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

//~~~~~~~~~~~~~~~~~CODE STARTING POINT~~~~~~~~~~~~~~~~~~~~~~

struct st
{
    int num,indx;
}ara[M];

ll x[M];
int n;

bool comp (st a,st b)
{
    if(a.num==b.num)
        return a.indx>b.indx;
    return a.num< b.num;
}

int khujo(int id)
{
    ll tmp=0;
    for(;id>0;id-=(id&-id))
        tmp=(tmp%MOD + x[id]%MOD)%MOD;

    return tmp%MOD;
}

void update(int id,int tmp)
{
    for(;id<=n;id+=(id&-id))
        x[id]=(tmp%MOD+x[id]%MOD)%MOD;
}

int main()
{
    int test,a,b;
    fs(test);
    Sfor(test)
    {
        fs(n);
        loop(j,0,n)
            {
                fs(ara[j].num);
                ara[j].indx=j;
                x[j]=0;
            }

        x[n]=0;
        sort(ara,ara+n,comp);

        loop(j,0,n)
        update(ara[j].indx+1,khujo(ara[j].indx+1)+1);

        pf("Case %d: %d\n",i,khujo(n));
    }
    return 0;
}
