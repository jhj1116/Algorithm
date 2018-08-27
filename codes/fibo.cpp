#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

pair<int,int> memo[41];


pair<int,int> fibo(int n){
    
    if(n==0) return make_pair(1,0);
    if(n==1) return make_pair(0,1);
    
    pair<int,int>& ret = memo[n];
    
    if(ret.first != -1&&ret.second!=-1) return ret;
    
    return ret = make_pair(fibo(n-1).first + fibo(n-2).first, fibo(n-1).second+fibo(n-2).second);
    
}



int main(int argc, const char * argv[]) {
    
    memset(memo,-1,sizeof(memo));
    
    int N;
    cin >> N;
    
    int n;
    n = N;
    int num;
    
    pair<int,int> ans[N];
    
    while(n--){
        cin >> num;
        ans[n] = fibo(num);
    }
    while(N--){
        cout << ans[N].first << " " << ans[N].second << endl;
    }
    
}


