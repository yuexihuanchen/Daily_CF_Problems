/*
*   哥德巴赫猜想：
    第一条：每个大于2的偶数都是两个素数之和。
    第二条：每个大于5的奇数都是三个素数之和。

    ①将每个元素的值作为下标，记录该元素所在的位置。
    ②排序的时候判断该点是否为本身。
    如果不是的话，就去判断两点之间的距离是否为素数，不是则变为两个素数相加即可。
 *
 * */
#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int>pii;
#define x first
#define y second

const int N = 1e5 + 10;
int a[N];
bool vis[N];
bool prime[N];
int need[N];
unordered_map<int,int>m; //输入数组值和其下标
vector<pii> ans;

void init(){  //筛法求素数
    memset(vis,false,sizeof vis);
    memset(prime,false,sizeof prime);
    memset(need,0,sizeof need);

    for(int i = 2; i < N; i++){
        if(!vis[i]){
            prime[i] = true;
            for(int k = i; k < N; k+= i){
                vis[k] = true;
            }
        }
    }

    for(int i = 2; i < N; i++){ //小于等于该值最近的素数
        if(prime[i]) need[i] = i;
        else need[i] = need[i-1];
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        m[a[i]] = i;
    }
    init(); //预处理出所有素数
    for(int i = 1; i <= n; i++){
        while(m[i] != i){ //当当前下标不为目标下标

            int t = m[i] - i + 1; //
            int k = m[i] - need[t] + 1;
            ans.emplace_back(k,m[i]);
            m[a[k]] = m[i];
            swap(a[m[i]], a[k]);
            m[i] = k;
        }
    }

    cout << ans.size() << endl;
    for(auto & an : ans){
        cout << an.x << " " << an.y << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //   cin >> T;
    while (T--)
        solve();
    return 0;
}
