/**
 * @file	main.cpp
 * @brief	Contém a função main com a manipulação de arquivos
 * @author 	Samuel Lucas de Moura Ferino
 * @author 	Emanoel Dantas Pereira
 * @author	Madson Rodrigues Liborio
 */
#include "ARN.h"

#include <string>
#include <fstream>

#include <iostream>


/*! @fn int main(int argc, char * argv[])
 *	@brief	Função main
 *	@param 	argc	Quantidade de argumentos passados via linha de comando
 *	@param 	argv	Vetor contendo os argumentos passados via linha de comando
 */
//int main(int argc, char* argv[]){
int main(){

	ARN tree;
	tree.insert(19);
	tree.insert(18);
	tree.insert(16);
	tree.insert(15);
	tree.insert(17);
	tree.insert(2);
	tree.levelTravel();
	
	
	tree.remove(2);
	tree.travellingRecursively();
	tree.levelTravel();

	if( tree.search(2) == true ){
		std::cout << "2 estah na arvore" << std::endl;
	}



/*	int valor; //variavel que recebe cada valor que será salvo na arvore

	string nomeArquivo = argv[1]; //nome do arquivoDeComandos passado por parametro

	ifstream arquivo; //usado para ler os comandos do arquivoDeComandos

	string comando; // usado para comandos que nao tem indice N

	string comandoPrincipal; //usado para comandos que tem indice N

	int indiceN;

	int inicio; //usado para salvar a posição de inicio do valor N na strig

	ARN tree;

	if(nomeArquivo != "arquivoDeComandos"){
		cout << "Falha ao executar o programa!" << endl;
		cout << "Para executar, digite o seguinte comando no terminal:" << endl;
		cout << "\t./bst arquivoDeComandos < arquivoDeEntradaDaABB" << endl;
	}else{

		arquivo.open(nomeArquivo, fstream::in);//Abrindo o arquivo com os comandos

		if( !(arquivo.is_open()) ){ 		
			cerr << "Falha ao abrir o arquivo de comandos!" << endl;
	 		return 1; 	
	 	}

	 	//lendo os valores e inserindo na arvore
		while(! cin.eof()){
			cin >> valor;
			tree.insert(valor);
		}

		//lendo e tratando os comandos
		while( !arquivo.eof() ){
			getline (arquivo,comando);//lendo cada linha de comando

			if(comando.size() < 5){
				//5 é o tamanho do menor comando (comando CHEIA)
				cout << endl;

			}else if(comando == "MEDIANA"){
				cout << "Comando MEDIANA foi passado: " << tree.mediana() << endl;

			}else if(comando == "CHEIA"){
				cout << "Comando CHEIA foi passado: ";

				if( tree.ehCheia() ){
					cout << "VERDADEIRO" << endl;
				}
				else{
					cout << "FALSO" << endl;
				}

			}else if(comando == "COMPLETA"){
				cout << "Comando COMPLETA foi passado: ";

				if( tree.ehCompleta() ){
					cout << "VERDADEIRO" << endl;
				}
				else{
					cout << "FALSO" << endl;
				}

			}else if(comando == "IMPRIMA"){
				cout << "Comando IMPRIMA foi passado:  " << tree.toString() << endl;

			}else{

				//calculando o valor de N para comandos que passam o indice N como parametro
				inicio = comando.find(" ") + 1; //posição de inicio de N na string
				indiceN = stoi( comando.substr(inicio, comando.size() - inicio) ); //converte string referente a N para o valor em int
				comandoPrincipal = comando.substr(0,inicio - 1); //calcula o nome do comando sem a parte N

				if(comandoPrincipal == "ENESIMO"){
				cout << "Comando ENESIMO foi passado com indice " << indiceN;
				cout << ": " << tree.enesimoElemento(indiceN) << endl;

				}else if(comandoPrincipal == "POSICAO"){
					cout << "Comando POSICAO do elemento " << indiceN;
					cout << ": " << tree.posicao(indiceN, tree.raiz) << endl;

				}else if(comandoPrincipal == "REMOVA"){
					cout << "Comando REMOVA foi passado com indice " << indiceN << ": ";

					if(tree.remove(indiceN) )
						cout << "Elemento removido com sucesso!"<< endl;
					else
						cout << "Elemento não está na árvore!" << endl;
				}
			}	
		}

		cout << endl;
		tree.travellingRecursively();

		arquivo.close();//fechando o arquivo com os comandos
	}
*/
	
	return 0;
}