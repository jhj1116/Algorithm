#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct Node *Node_pt;
typedef struct Node{
	Node_pt link;
	int vtx;
} Node;

char matrix[MAX][MAX];
char new_matrix[MAX][MAX];

Node_pt list[MAX];
Node_pt new_list[MAX];

int order[MAX];

int discovery_t[MAX];
int finish_t[MAX];

int time = 1;

void dfs(int root){
	Node_pt tmp = list[root];
	discovery_t[root] = time++;
	while(tmp!=NULL){
		if(discovery_t[tmp->vtx]==0){
			dfs(tmp->vtx);
			tmp = tmp->link;
		}
		else{
			tmp = tmp->link;
		}
	}
	finish_t[root] = time++;
}

void dfs2(int root){
        Node_pt tmp = new_list[root];
        discovery_t[root] = time++;
        while(tmp!=NULL){
                if(discovery_t[tmp->vtx]==0){
                        dfs2(tmp->vtx);
                        tmp = tmp->link;
                }
                else{
                        tmp = tmp->link;
                }
        }
        finish_t[root] = time++;
}

void dfs3(int root){
        discovery_t[root] = time++;
        for(int i=1; i<MAX; i++){
                int j = order[i];
		if(discovery_t[j]==0 && new_matrix[root][j]=='1') dfs3(j);
        }
        finish_t[root] = time++;
}

int main(int argc, const char *argv[]) {

	if(argc<2){
		fprintf(stderr, "Usage: ./result input_file\n");
		exit(0);
	}


	FILE *fp;
	fp = fopen(argv[1], "r");

	char data[MAX][MAX];
	
	int check =0;
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			data[i][j] = fgetc(fp);
			if(data[i][j]=='\n') break;
			if(data[i][j]==EOF){
				data[i][j]='\n';
				check = 1;
				break;
			}
		}
		if(check==1) break;
	}

	//printf("0. read the original data file\n");

	int p,q;
	for(p=0; p<MAX; p++){
		if(data[p][0]=='\0') break;
		for(q=0; q<MAX; q++){
			if(data[p][q]=='\0') break;
			//printf("%c",data[p][q]);
		}
   	}

	fclose(fp);

	
	//printf("\n0. represent to type of array\n");

	int k=0;
	for(int i=0; i<p-1; i++){
		k=0;
		for(int j=0; j<p-1; j++){
			if(data[i+1][k]=='\n') break;
			else if(data[i+1][k]=='1' || data[i+1][k]=='0'){
				matrix[i][j] = data[i+1][k];
				//printf("%c", matrix[i][j]);
				k++;
			}
			else{
				k++;
				j--;
			}
		}
		//printf("\n");
	}



	printf("\n");
	printf("1. Array of adjacency list of given graph\n");

	//Node_pt list[p-1];

	Node_pt node;
	Node_pt tmp;
	Node_pt new;

	for(int x=0; x<p-1; x++){
		node = list[x];
		printf("list[%d]: %c  ",x, data[x+1][0]);
		
		for(int y=0; y<p-1; y++){	
			if(matrix[x][y]=='1'){
				new = (Node_pt)malloc(sizeof(Node));
				new->vtx = y;
				
				if(list[x]==node){
					tmp = new;
					list[x] = new;
				}
				else{
					tmp->link = new;
					tmp = new;
				}
				printf("-> %c ", data[new->vtx+1][0]);
			}
		}
	
		new->link = NULL;
		printf("\n");
	}
	

	printf("\n");
	printf("2. Discovery and finish time of each vertex after step1\n");

	for(int i=0; i<p-1; i++){
		discovery_t[i] = 0;
		finish_t[i] = 0;
	}

	for(int root=0; root<p-1; root++){
		if(discovery_t[root]==0) dfs(root);
	}

	
	for(int i=0; i<p-1; i++){
		printf("%c's discovery time is %d\n",data[i+1][0], discovery_t[i]);
	}

	printf("\n");
	for(int j=0; j<p-1; j++){
		printf("%c's finish time is %d\n",data[j+1][0], finish_t[j]);
	}

	printf("\n3. Array of adjacency list of transpose graph after step2\n");

	for(int i=0; i<p-1; i++){
		for(int j=0; j<p-1; j++){
			new_matrix[i][j] = matrix[j][i];
		}
	}


	//Node_pt new_list[p-1];

        

        Node_pt new_node;
        Node_pt new_tmp;
        Node_pt new_new;

        for(int a=0; a<p-1; a++){
                new_node = new_list[a];

                printf("new_list[%d]: %c  ", a, data[a+1][0]);

                for(int b=0; b<p-1; b++){
                        if(new_matrix[a][b]=='1'){
                                new_new = (Node_pt)malloc(sizeof(Node));
                                new_new->vtx = b;

                                if(new_list[a]==new_node){
                                        new_tmp = new_new;
                                        new_list[a] = new_new;
                                }
                                else{
                                        new_tmp->link = new_new;
                                        new_tmp = new_new;
                                }
				printf("-> %c ", data[new_new->vtx+1][0]);
                        }
                }

                new_new->link = NULL;
                printf("\n");
        }
	
	int max;
	int memo;
	for(int i=0; i<p-1; i++){
		max = finish_t[i];
		memo = i;
		for(int j=0; j<p-1; j++){
			if(finish_t[j]>max){
				max=finish_t[j];
				memo = j;
			}
		}
		finish_t[memo] = 0;
		order[i] = memo;
	}
	


	printf("\n");
	printf("4. Discovery and finish time of each vertex after step3\n");

	for(int i=0; i<p-1; i++){
		discovery_t[i] = 0;
		finish_t[i] = 0;
	}
	
	int group_range[p-1];
	time =1;
	for(int i=0; i<p-1; i++){
		int root = order[i];
		group_range[i] = -1;
		if(discovery_t[root]==0){
			dfs2(root);  // dfs3 is also okay..
			group_range[i] = root;
		}
	}

	
	for(int i=0; i<p-1; i++){
		printf("%c's discovery time is %d\n",data[i+1][0], discovery_t[i]);
	}


	printf("\n");
	for(int j=0; j<p-1; j++){
		printf("%c's finish time is %d\n",data[j+1][0], finish_t[j]);
	}
	
	int new_order[p-1];
	for(int i=0; i<p-1; i++){
                max = finish_t[i];
                memo = i;
                for(int j=0; j<p-1; j++){
                        if(finish_t[j]>max){
                                max=finish_t[j];
                                memo = j;
                        }
                }
                finish_t[memo] = 0;
                new_order[i] = memo;
        }
		


	printf("\n5. SCC result\n");
	

	int group_start[p-1];
	k=0;
	for(int i=0; i<p-1; i++)
		if(group_range[i]!=-1) group_start[k++] = group_range[i];

	for(int i=k; i<p-1; i++)
		group_start[i] = -1;	


	int scc[p-1][p-1];
	for(int i=0; i<p-1; i++)
		for(int j=0; j<p-1; j++)
			scc[i][j] = -1;
	
	int new_group_start[p-1];
	for(int i=0; i<p-1; i++)
		new_group_start[i] = -1;

	int idx=0;
	for(int i=p-2; i>=0; i--){
		if(group_start[i]!=-1){
			new_group_start[idx] = group_start[i];
			idx++;
		}
	}
	

	int m=0, n=0;
	for(int j=0; j<p-1; j++){
		if(new_order[j]!=new_group_start[m+1]){
			scc[m][n] = new_order[j];
			n++;
		}
		else{
			m++;
			n=0;
			scc[m][n] = new_order[j];
			n++;
		}
	}
	
	int i=0, j=0;
	while(new_group_start[i]!=-1){
		printf("SCC%d: vertex ", i+1);
		while(scc[i][j]!=-1){
			printf("%c ", data[scc[i][j]+1][0]);
			j++;
		}
		j=0;
		i++;
		printf("\n");
	}
		


}
