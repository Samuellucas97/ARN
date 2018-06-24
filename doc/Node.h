/**
 * @file 		Node.h 
 * @brief		Contém a struct Node que representa um nó da árvore rubro-negra
 * @author 		Samuel Lucas de Moura Ferino
 * @since		12.06.2018
 * @version		0.0.2
*/ 

#ifndef _NODE_H
#define _NODE_H

/**! \enum COR
		\brief	Representa a cores possíveis para os nós
 */
enum COR{
	RUBRO, NEGRO
};


/*! \struct		Node
		\brief		Representa um nó de uma árvore rubro negra
 */
struct Node{

	public:
		
		/// ATRIBUTOS 

		/*!	\var int chave	
		  		\brief		Chave/conteúdo do nó 
		 */
		int chave;
		
		/*!	\var	Node* p	
				\brief	Ponteiro que indica quem é o nó pai do nó atual 
		 */	
		Node* p;
		
		/*!	\var	Node* esquerda
				\brief	Ponteiro que indica quem é o nó filho à esquerda do nó atual 
		 */	
		Node* esquerda;
		
		/*!	\var	Node* direita
				\brief	Ponteiro que indica quem é o nó filho à direita do nó atual 
		 */
		Node* direita;
		
		/*!	\var	COR cor 
				\brief 	Cor do nó (RUBRO ou NEGRO)
		 */
		COR cor;

		/// MÉTODOS

		/**
		 * @brief 	Construtor parametrizado
		 * @param 	Chave 		Chave do nó
		 * @param 	p 			Ponteiro/Endereço para o nó pai
		 * @param 	esquerda	Ponteiro/Endereço para o nó filho à esquerda
		 * @param 	direita 	Ponteiro/Endereço para o nó filho à direita
		 * @param 	cor 		Cor do nó
		 */		 
		Node(int novaChave = 0, 
			Node* novoP = nullptr, 
			Node* novoEsquerda = nullptr, 
			Node* novoDireita = nullptr, 
			COR novaCor = RUBRO);	

		/**
		 * @brief	Destrutor padrão
		 */
		~Node();
};

#endif
