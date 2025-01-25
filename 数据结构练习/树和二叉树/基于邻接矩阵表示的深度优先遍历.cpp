#include <stdio.h>
#define MVNum 100                           
typedef struct{ 
    char vexs[MVNum];          
    int arcs[MVNum][MVNum];   
    int vexnum,arcnum;      
}AMGraph;
int visited[MVNum];
void CreateUDN(AMGraph &G);//ÊµÏÖÏ¸½ÚÒþ²Ø

void DFS(AMGraph G, int v){  
    printf("%c ",G.vexs[v]);  visited[v] =1;  
    int w;
    for(w = 0; w < G.vexnum; w++)
        if(()&& ())  
        DFS(G, w);
}

void DFSTraverse(AMGraph G){ 
    int v;
    for(v = 0; v < G.vexnum; ++v)  
        visited[v] = 0;
    for(v = 0; v < G.vexnum; ++v) 
        if() 
                 ;
}

int main(){
    AMGraph G;     
    CreateUDN(G);
    DFSTraverse(G);
    return 0;
}
