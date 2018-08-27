//
//  main.cpp
//  greedypanda
//
//  Created by 정혜진 on 2018. 8. 2..
//  Copyright © 2018년 정혜진. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int bamboo[502][502];
int memo[502][502];

int maximum = 0;

int find(int x, int y){
    
    int& ret = memo[x][y];
    if(ret!=-1) return ret;
    
    
    if(bamboo[x][y] < bamboo[x+1][y]) ret = find(x+1,y);
    
    if(bamboo[x][y] < bamboo[x][y+1]) ret = max(ret,find(x,y+1));
    
    if(bamboo[x][y] < bamboo[x-1][y]) ret = max(ret,find(x-1,y));
    
    if(bamboo[x][y] < bamboo[x][y-1]) ret = max(ret,find(x,y-1));
    
    
    return ret+=1;
    
}

int main(int argc, const char * argv[]) {
    
    memset(memo,-1,sizeof(memo));
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &bamboo[i][j]);
        }
    }
    
    
    for(int p=0; p<n; p++){
        for(int q=0; q<n; q++){
            maximum = max(maximum, find(p,q));
        }
    }

    printf("%d\n", maximum+1);
    
}
