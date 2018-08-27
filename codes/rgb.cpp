//
//  main.cpp
//  rgb
//
//  Created by 정혜진 on 2018. 3. 27..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int memo[3][1002];

int r[1002]; //0
int g[1002]; //1
int b[1002]; //2


int cost(int c, int n){
    
    
    int& ret = memo[c][n];
    
    if(ret != -1) return ret;
    

    if(c==0) ret = r[n];
    else if(c==1) ret = g[n];
    else if(c==2) ret = b[n];
    
    if(n==N) return ret;
    
    return ret += min(cost((c+1)%3,n+1), cost((c+2)%3,n+1));
    
}


int main(int argc, const char * argv[]) {
    
    memset(memo, -1, sizeof(memo));
    
    scanf("%d",&N);
    
    int i = 0;
    
    for(int x=0; x<N; x++){
        scanf("%d %d %d",&r[i], &g[i], &b[i]);
        i++;
    }
    
    int red = cost(0,0);
    int green = cost(1,0);
    int blue = cost(2,0);
    
    int ans = min(red,min(green,blue));
    
    printf("%d",ans);
    
    
}
