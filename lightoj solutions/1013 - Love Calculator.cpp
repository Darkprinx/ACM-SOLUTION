/*
   ~~~ BISMILLAH HIR RAHMANIR RAHIM ~~~
   Problem Name: 1013 - Love Calculator
       Platform: LightOj
     Algorithom: LCS
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
#define M 10500
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction
//freopen("sum.in","r",stdin);
//freopen("sum.out","w",stdout);
typedef vector<int> vi;


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

// ~~~~~~~~~~~~~~~ CODE STARTING POINT ~~~~~~~~~~~~~~~~



int main()
{
    string str,vtr;

int dp[63][63],len1,len2;
ll cp[63][63];
    int test;
    fs(test);

    Sfor(test)
    {
        cin>>str>>vtr;

        len1=str.size();
        len2=vtr.size();

        for(int j=0;j<=len1;j++)
        dp[j][0]=j,cp[j][0]=1;

        for(int j=0;j<=len2;j++)
        dp[0][j]=j,cp[0][j]=1;

        for(int j=1;j<=len1;j++)
        for(int k=1;k<=len2;k++)
        if(str[j-1]==vtr[k-1])
            dp[j][k]=dp[j-1][k-1]+1;
        else
            dp[j][k]=min(dp[j-1][k],dp[j][k-1])+1;

        for(int j=1;j<=len1;j++)
        for(int k=1;k<=len2;k++)
        {
            cp[j][k]=0;
            if(str[j-1]==vtr[k-1])
            cp[j][k]+=cp[j-1][k-1];
        else
            {
                if(dp[j-1][k]+1==dp[j][k])
                cp[j][k]+=cp[j-1][k];

                if(dp[j][k-1]+1==dp[j][k])
                cp[j][k]+=cp[j][k-1];
            }
        }
        pf("Case %d: %d %lld\n",i,dp[len1][len2],cp[len1][len2]);
    }
    return 0;
}

