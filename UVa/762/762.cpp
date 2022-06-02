#include <bits/stdc++.h>

using namespace std;

map <string, vector <string>> graph;
map <string, bool> visited;
map <string, string> parent;

void print(string v){
    if(parent[v] != "-1"){
        print(parent[v]);
        cout << parent[v] << " " << v << endl;        
    }
}

bool BFS(string u, string v){
    bool ans = false;
    queue <string> q;
    string val, aux;
    visited[u] = true;
    parent[u] = "-1";
    q.push(u);

    while(!q.empty() && !ans){
        val = q.front();

        for(int i = 0; i < graph[val].size(); i++){
            aux = graph[val][i];
            if(!visited[aux]){
                visited[aux] = true;
                ans = aux == v ? ans = true : ans;
                parent[aux] = val;
                q.push(aux);
            }
        }

        q.pop();
    }

    return ans;

}

int main(){
    int inter, cases = 0;
    string u, v;

    while(cin >> inter){
        if(cases++)
            printf("\n");
        for(int i = 0; i < inter; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            visited[v] = false;
            visited[u] = false;
        }

        cin >> u >> v;

        if(BFS(u, v)){
            print(v);
        }
        else
            printf("No route\n");

        graph.clear();
    }

    return 0;
}