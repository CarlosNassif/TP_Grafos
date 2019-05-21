#include <iostream>
#include <vector>

using namespace std;

//Struct de aresta
typedef struct Aresta {
	int out, in;
}Aresta;

typedef struct Vertice {
	char nome;
}Vertice;

const int A = 97;

//Classe grafo
class Grafo {
	public:
		vector<vector<int> > matrizAdj;//Matriz de adjacencia

		//Construtor
		Grafo(vector<Aresta> const &arestas, int N) {
			matrizAdj.resize(N); 

			for(auto &aresta: arestas) matrizAdj[aresta.out].push_back(aresta.in); //Grafo direcionado
			for(auto &aresta: arestas)	matrizAdj[aresta.in].push_back(aresta.out); //Grafo nao direcionado
		}
};

void printMatrizAdj(Grafo const &grafo, int N) {
	for(int i = 0; i < N; i++) {
		int v1 = A+i;
		cout << (char)v1 << " -> ";	//Printa o vertice corrente

		for(int v : grafo.matrizAdj[i]) {
			int v2 = A+v; 
			cout << (char)v2 << " ";	//printa os vertices adjacentes
		}
		cout << endl;
	}
}

int main() {
	int nCasos;
	scanf("%d",&nCasos);

	for(int k = 0; k < nCasos; k++) {
		int numV;
		int numA;
		int count;
		
		//le o num de Vertices e num de Arestas
		scanf("%d %d",&numV,&numA);

		//Cria matriz de adjacencia e seta para 0
		int matriz[numV][numV];
		for(int i = 0; i < numV; i++)
			for(int j = 0; j < numV; j++)
				matriz[i][j] = 0;

		//le as arestas e seta na matriz
		count = numA;
		while (count > 0) {
			char c1, c2;
			int v1, v2;
			char descarte;

			scanf("%c", &descarte);
		
			scanf("%c %c", &c1,&c2);
			//cout << c1 << " " << c2 << '\n';
			v1 = (int)c1-A;
			v2 = (int)c2-A;

			matriz[v1][v2] = 1;
			matriz[v2][v1] = 1;

			count--;
		}

		//imprime o Caso
		cout << "Case #"<< k+1 <<":\n";	

		//imprime cada vertice e uma lista de vertices ligados a ele
		for(int i = 0; i < numV; i++) {
			cout << (char)(i+A) << ':';
			for(int j = 0; j < numV; j++) {
				if(matriz[i][j] == 1) {
					cout << ' ' << (char)(j+A);
				}
			}
			cout << '\n';
		}

		cout << "\n\n";
	}
	return 0;
}
