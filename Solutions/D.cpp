#include <bits/stdc++.h>
#define MAXN 600*600+2 //Limite de vértices
using namespace std;

int n, m, H = 0, F = 1, disH[MAXN], disF[MAXN];
//disH[i] = menor instante em que Hélio consegue chegar no vértice i
//disF[i] = instante em que o vértice i pega fogo
//H = vértice artificial criado para representar Hélio
//F = vértice artificial criado para representar o fogo

char grid[600][600];
vector<int> adj[MAXN]; //Lista de adjacência

int get(int i, int j){ //Retorna o vertice associado à célula (i,j)
    return i*m + j + 2;
}

void add(int a, int b){ //Adiciona aresta entre "a" e "b"
    adj[a].push_back(b);
    adj[b].push_back(a);
}

//Busca em largura a partir do vértice V
void bfs(int v, int * dis){
    for(int i = 0; i < MAXN; i++)
        dis[i] = -1; //Marca todos os vértices como não visitados
    dis[v] = 0; //coloca que V chega no instante 0
    queue<int> fila;
    fila.push(v); //Coloca V na fila da BFS
    while(!fila.empty()){
        v = fila.front(); //para cada elemento na busca
        fila.pop();
        for(int i = 0; i < (int)adj[v].size(); i++) //Percorre seus adjacentes
            if(dis[adj[v][i]] == -1){  //Verifica se esse adjacente ainda nao foi visitado
                dis[adj[v][i]] = dis[v]+1; //Visita ele no instante seguinte
                fila.push(adj[v][i]); //Coloca ele na fila
            }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf(" %c", &grid[i][j]); //Lendo o grid
            if(grid[i][j] == 'H')
                add(H, get(i,j)); //Ligando a célula (i,j) a Hélio (ocorre apenas em uma célula)
            if(grid[i][j] == 'F')
                add(F,get(i,j)); //Ligando a célula (i,j) ao fogo
            if(i > 0 && grid[i][j] != '#' && grid[i-1][j] != '#')
                add(get(i,j),get(i-1,j)); //Adicionando aresta entre células da mesma coluna
            if(j > 0 && grid[i][j] != '#' && grid[i][j-1] != '#')
                add(get(i,j),get(i,j-1)); //Adicionando aresta entre células da mesma linha
        }
    bfs(H,disH); //Busca a partir de Hélio
    bfs(F,disF); //Busca a partir do fogo
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(i==0 || j==0 || i==n-1 || j==m-1){ //Caso exista uma célula na borda do grid
                //Em que Hélio consegue chegar antes do fogo, então há solução
                if(disH[get(i,j)] != -1 && (disH[get(i,j)] < disF[get(i,j)] || disF[get(i,j)] == -1)){
                    puts("Corre!");
                    return 0;
                }
            }
    puts("Vish!"); //Se em nenhuma isso ocorrer, não há solução
}

