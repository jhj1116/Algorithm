//
//  main.cpp
//  stickers
//
//  Created by 정혜진 on 2018. 7. 6..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int stickers[2][1000001];
int memo[2][1000001];


int find(int x, int y){
    
    if(y>=n) return 0; // base case
    
    int& ret = memo[x][y];
    if(ret != -1) return ret;
    
    
    if(x==0) return ret = stickers[x][y] + max(find(1,y+1),find(1,y+2));
    return ret = stickers[x][y] + max(find(0,y+1), find(0,y+2));
    
}


int main(int argc, const char * argv[]) {
    int T;
    scanf("%d", &T);
    
    while(T--){
        memset(memo, -1, sizeof(memo));
        
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &stickers[0][i]);
        }
        for(int j=0; j<n; j++){
            scanf("%d", &stickers[1][j]);
        }
        
        printf("%d\n", max(find(0,0), find(1,0)));
    }
}
