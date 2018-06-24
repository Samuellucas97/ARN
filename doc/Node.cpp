/**
 * @file 		Node.cpp 
 * @brief		Contém a implementação dos métodos da struct Node que representa um nó de uma árvore rubro-negra
 * @author 		Samuel Lucas de Moura Ferino
 * @since		14.06.2018
 * @version		0.0.2
*/ 

/*!	\include Node.h	
		\brief	Contém a classe ARN que representa um nó de uma árvore rubro-negra
 */
#include "Node.h"

/**
 * @brief 	Construtor parametrizado
 * @param 	Chave 		Chave do nó
 * @param 	p 			Ponteiro/Endereço para o nó pai
 * @param 	esquerda	Ponteiro/Endereço para o nó filho à esquerda
 * @param 	direita 	Ponteiro/Endereço para o nó filho à direita
 * @param 	cor 		Cor do nó
 */		 
Node::Node(	int novaChave /**= 0**/, 
			Node* novoP /**= nullptr**/, 
			Node* novoEsquerda /**= nullptr**/, 
			Node* novoDireita /**= nullptr**/, 
			COR novaCor /**= RUBRO**/):
			
			chave(novaChave), 
			p(novoP), 
			esquerda(novoEsquerda), 
			direita(novoDireita), 
			cor(novaCor)	{  }	
/**
 * @brief	Destrutor padrão
 */
Node::~Node(){}