/*
   Problem Name: 1112 - Curious Robin Hood
       Platform: LightOj
     Algorithom: Segmented Tree
   Coder's Name: RC Tushar

~~~ Never Show Your Arrogance.Keep In Mind,You Were Born From A Drop Of Impure Water ~~~

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
#define M  100002
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};                         //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};     //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};   //Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1};              //Hexagonal Direction

typedef vector<int> vi;

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

int ara[M],tree[M*3];
void boshi_ja(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    boshi_ja(left,b,mid);
    boshi_ja(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void taka_de(int node,int b,int e,int i,int taka)
{
    if(i>e||i<b)
        return ;
    if(e==b)
    {
        if(taka)
        {
            tree[node]+=taka;
            return;
        }
        else
        {
            pf("%d\n",tree[node]);
            tree[node]=taka;
            return;
        }

    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    taka_de(left,b,mid,i,taka);
    taka_de(right,mid+1,e,i,taka);
    tree[node]=tree[left]+tree[right];
}

int hishab_kor(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)
        return 0;
    if(b>=i&&e<=j)
        return tree[node];

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    int ans1=hishab_kor(left,b,mid,i,j);
    int ans2=hishab_kor(right,mid+1,e,i,j);
    return ans1+ans2;
}

int main()
{

    int test,n,q,sw,a,b;
    fs(test);
    Sfor(test)
    {
        fs(n);
        fs(q);
        loop(j,0,n)
            fs(ara[j]);
        boshi_ja(1,0,n-1);
        pf("Case %d:\n",i);
        loop(j,0,q)
        {
            fs(sw);
            switch(sw)
            {
            case 1:
                fs(a);
                taka_de(1,0,n-1,a,0);
                break;
            case 2:
                fs(a);
                fs(b);
                taka_de(1,0,n-1,a,b);
                break;
            case 3:
                fs(a);
                fs(b);
                pf("%d\n",hishab_kor(1,0,n-1,a,b));
            }
        }
    }
    return 0;
}
