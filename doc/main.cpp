/**
 * @file	main.cpp
 * @brief	Contém a função main com a manipulação de arquivos
 * @author 	Samuel Lucas de Moura Ferino
 * @version	0.0.9
 */
#include "ARN.h"

#include <iostream>
using std::cout;
using std::endl;

/*! @fn int main()
 *	@brief	Função main
 */
int main(){
	
	ARN tree;

	tree.insert(19);
	tree.insert(18);
	tree.insert(16);
	tree.insert(15);
	tree.insert(17);
	tree.insert(2);
	

	cout << endl << "Percorrendo por nível: " << endl;
	tree.levelTravel();
	cout << endl;
		
	tree.remove(2);

	tree.travellingRecursively();

	cout << endl << "Percorrendo por nível: " << endl;
	tree.levelTravel();
	cout << endl;

	tree.remove(16);
	
	tree.travellingRecursively();
	cout << endl << "Percorrendo por nível: " << endl;
	tree.levelTravel();
	cout << endl;


	if( tree.search(2) == true ){
		cout << "Há nó com chave 2 na árvore" << endl;
	}
	else{
		cout << "Não há nó com chave 2 na árvore" << endl;		
	}

	
	return 0;
}

