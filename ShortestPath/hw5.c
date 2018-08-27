#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX 200
#define INF 99999999

char *result[MAX][MAX];
int matrix[MAX][MAX];
int distance[MAX];
int visit[MAX];

struct edge{
	int from;
	int to;
	int weight;
} edge[MAX];

void initialize(int k, int start){
	for(int i=0; i<k-1; i++){
		distance[i] = INF;
		visit[i] = 0;
	}
	distance[start] = 0;
}

void relax(struct edge e){
	if(distance[e.to] > distance[e.from] + e.weight)
		distance[e.to] = distance[e.from] + e.weight;
}

int extract_min_idx(int k){
	int min = INF;
	int idx = 0;
	for(int i=0; i<k-1; i++){
		if(distance[i]<min && !visit[i]){
			min = distance[i];
			idx = i;
		}
	}

	return idx;
}

void dijkstra(int k, int start){
	
	initialize(k, start);

	for(int i=0; i<k-2; i++){
		int u = extract_min_idx(k);
		visit[u] = 1;
		for(int j=0; j<k-1; j++){
			if(!visit[j]){
				if(distance[j] > distance[u]+matrix[u][j])
					distance[j] = distance[u]+matrix[u][j];
			}
		}
	}

	for(int i=0; i<k-1; i++)
		printf("%10d ", distance[i]);
	printf("\n");
}

int bellmanford(int k, int start, int edge_num){
	
	initialize(k, start);

	for(int i=0; i<k-2; i++){
		for(int j=0; j<edge_num; j++){
			relax(edge[j]);
		}
	}


	for(int i=0; i<edge_num; i++)
		if(distance[edge[i].to] > distance[edge[i].from] + edge[i].weight) return 0;

	return 1;

}

void floydwarshall(int k){
	
	for(int p=0; p<k-1; p++)
		for(int i=0; i<k-1; i++)
			for(int j=0; j<k-1; j++)
				if(matrix[i][j]>matrix[i][p]+matrix[p][j])
					matrix[i][j] = matrix[i][p] + matrix[p][j];
	
	for(int i=0; i<k; i++)
		printf("%10s ", result[0][i]);
	printf("\n");
	for(int i=0; i<k-1; i++){
		printf("%10s ", result[i+1][0]);
		for(int j=0; j<k-1; j++){
			printf("%10d ", matrix[i][j]);
		}
		printf("\n");
	}

}



int main(int argc, const char *argv[]) {

	if(argc<2){
		fprintf(stderr, "Usage: ./(program name) (data file).data\n");
		exit(0);
	}


	FILE *fp;
	fp = fopen(argv[1], "r");


	int k=0;
	char buffer[MAX][MAX];
	while(fgets(buffer[k],MAX,fp)){
		k++;
	}

	int q = 1;
	for(int p=0; p<k; p++){
		result[p][q] = strtok(buffer[p],"\n	 ");
		while(result[p][q]!=NULL){
			q++;
			result[p][q] = strtok(NULL,"\n	 ");
		}
		q=0;
	}

    
    int isnegedge = 0;

	for(int i=0; i<k-1; i++){
		for(int j=0; j<k-1; j++){
			if(!strncmp(result[i+1][j+1],"INF", 3))
				matrix[i][j] = INF;
			else
				matrix[i][j] = atoi(result[i+1][j+1]);
            if(matrix[i][j]<0) isnegedge = 1;
		}
	}

	int edge_num;
	for(int i=0; i<k-1; i++)
		for(int j=0; j<k-1; j++)
			if(matrix[i][j]!=INF && matrix[i][j]!=0)
				edge_num++;
	
	int x=0, y=0;
	for(int i=0; i<edge_num; i++){
		if(matrix[x][y]!=INF && matrix[x][y]!=0){
			edge[i].from = x;
			edge[i].to = y;
			edge[i].weight = matrix[x][y];
		}
		else{
			i--;
		}
		y++;
		if(y>=k-1){
			x++;
			y=0;
		}
	}

	printf("\n");
    
	printf("<Dijkstra algorithm Result>\n");
    if(isnegedge==0){
        for(int i=0; i<k; i++)
            printf("%10s ", result[0][i]);
        printf("\n");
        int dijk_start = clock();
        for(int i=0; i<k-1; i++){
            printf("%10s ", result[i+1][0]);
            dijkstra(k,i);
        }
        int dijk_end = clock();
        printf("It tooks %.3lf seconds to compute shortest path between cities with Djikstra algorithm.\n\n",
               (double)(dijk_end-dijk_start)/(double)1000);
    }
    else
        printf("There is a negetive edge weight, so we cannot use dijkstra algorithm.\n\n");

    int r;
	printf("<Bellman Ford Algorithm Result>\n");
	for(int i=0; i<k; i++)
		printf("%10s ", result[0][i]);
	printf("\n");
	clock_t bellman_start = clock();
	for(int i=0; i<k-1; i++){
		r = bellmanford(k,i,edge_num);
		if(r==1){
		printf("%10s ", result[i+1][0]);
        //r = bellmanford(k,i,edge_num);
		//if(r==1){
			for(int i=0; i<k-1; i++)
				printf("%10d ", distance[i]);
		}
		else
			printf("there is negative-weight cycle");
		printf("\n");
	}
	clock_t bellman_end = clock();
	if(r==1) printf("It tooks %.3lf seconds to compute shortest path between cities with Bellman Ford algorithm.",
	(double)(bellman_end-bellman_start)/(double)1000);
	printf("\n\n");

    printf("<Floyd Algorithm Result>\n");
    if(r==1){
        clock_t floyd_start = clock();
        floydwarshall(k);
        clock_t floyd_end = clock();
        printf("It tooks %.3lf seconds to compute shortest path between cities with Floyd algorithm.\n\n",
            (double)(floyd_end-floyd_start)/(double)1000);
    }
    else
        printf("there is negative-weight cycle\n");
    

}
