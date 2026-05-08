#include<iostream>
using namespace std;
int graph[10][10], visited[10];
int n;
void bfs(int start){
    int queue[10], front=0, rear=0;

    for(int i=0;i<n;i++)
        visited[i]=0;
    queue[rear++]=start;
    visited[start]=1;
    cout<<"BFS Traversal: ";
    while(front<rear){
        int node=queue[front++];
        cout<<node<<" ";
        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && visited[i]==0){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}
void dfs(int node){
    visited[node]=1;
    cout<<node<<" ";
    for(int i=0;i<n;i++){
        if(graph[node][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}
int main(){
    int choice,start;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    do{
        cout<<"\n1.BFS\n2.DFS\n3.Exit\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter starting vertex: ";
                cin>>start;
                bfs(start);
                break;
            case 2:
                for(int i=0;i<n;i++)
                    visited[i]=0;

                cout<<"Enter starting vertex: ";
                cin>>start;
                cout<<"DFS Traversal: ";
                dfs(start);
                break;
        }
   }while(choice!=3);
return 0;
}