//
//  main.cpp
//  nCr
//
//  Created by 정혜진 on 2018. 4. 7..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N, R;
long memo[1002][1002];

long coefficient(int n, int k){
    
    if(n<k) return 0;
    if(k==0 || k==n) return 1;
    
    long& ret = memo[n][k];
    if(ret !=-1) return ret%10007;
    
    return ret = coefficient(n-1,k-1) + coefficient(n-1,k);
    
}

int main(int argc, const char * argv[]) {


        memset(memo,-1,sizeof(memo));
        
        scanf("%d", &N);
        scanf("%d", &R);
        
        long result = coefficient(N,R);
        cout << result%10007 <<endl;
}
