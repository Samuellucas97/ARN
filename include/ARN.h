/**
 * @file		ARN.h 
 * @brief     	Contém a classe ARN que representa uma árvore rubro-negra
 * @author 		Samuel Lucas de Moura Ferino
 * @author		Madson Rodrigues Liborio
 * @since		12.06.2018
 * @version		0.0.3
*/

#ifndef	_ARN_H
#define	_ARN_H

/*!	\include Node.h	
		\brief	Contém a classe Node
 */
#include "Node.h" 

/// ESTRUTURA DE DADOS DA STL

/*!	\include stack	
		\brief	Contém a classe stack (pilha)
 */
#include <stack>		//	stack
using std::stack;


/*! \class 		ARN
		\brief	Representa uma Árvore Rubro-Negra
*/
class ARN{
	
	/// ATRIBUTOS

	public:
	
		/*!	\var	Node* raiz	
				\brief	Nó raiz 
		 */
		Node* raiz;

		/*!	\var	Node* raiz	
				\brief	Nó externo 
				\details	Para facilitar e economizar espaço será usada apenas 1 único nó externo
		 */
		Node* externo;
		
		/*!	\var 	stack<Node*> pilha	
		 		\brief	Guardará os nó no momento de percorrer a árvore não recursivamente
		 */
		stack<Node*> pilha;

    	/*! 	\var  int quantidadeDeElementos
     	  		\brief  Quantidade de elementos/nós que a árvore contém
     	*/
    	int quantidadeDeElementos;

		
	/// MÉTODOS

	public:

		/**
		 * @brief 	Construtor padrão
		 */	
		ARN();

		/**
		 * @brief	Destrutor padrão 
		 */	
		~ARN();
	    
		/**
		 * @brief	Percorre a árvore toda recursivamente, imprimindo-a
		 */
		void travellingRecursively();
		
		/**
		 * @brief 	Percorre por nível imprimindo as cores
		 */
		void levelTravel();

		/**
	     	 * @brief   	Busca recursivamente a chave na árvore
	     	 * @param   	key   Chave a ser buscada
	     	 * @return  	true caso tenha encontrado o respectivo nó com a chave senão false
	     	 */ 
	    bool search(int key);
		
		/**
		 * @brief   	Cria um novo nó com o conteúdo entrado, identifica o local 
		 *          	onde ele deve ser colocado na árvore e adiciona-o
		 * @param   	value   Conteúdo do novo nó
		 */ 
		bool insert(int value);

		/**
		 * @brief   Remove da árvore o nó com a respectiva chave, se existir
		 * @param   value 	Valor da chave a ser removida
		 */ 
		bool remove( int value);
		
		/**
		 * @brief   Remove da árvore o nó com a respectiva chave, se existir
		 * @param   value 	Valor da chave a ser removida
		 */
		bool deleta(int value);

	/**    /\/\/\/\/\/\      MÉTODOS PRIVADOS    /\/\/\/\/\/\      */
	  
	private:

		/**
		 * @brief   Identifica o local onde deve ser colocado o novo nó na árvore e adiciona-o
		 * @param   z   Novo nó
		 * @return  \code{.cpp}true\endcode caso tenha sido adiciona, \code{.cpp}false\endcode caso contrário
		 */ 
		void insertNode(Node* z);
		
		/**
		 * @brief   Identifica o local onde do nó na árvore a ser removido e se existir, remove-o
		 * @param   z   Nó a ser removido
		 * @return  \code{.cpp}true\endcode caso tenha sido removido, \code{.cpp}false\endcode caso contrário
		 */ 
		void removeNode( Node* z );
		/**
	   	 * @brief   Busca o extremo nó à esquerda de qualquer nó
	   	 * @param   x   Nó usado como ponto de partida
	   	 * @return  O nó extremo à esquerda
	   	 */
		Node * mimimunOfAnyNode(Node* x);
  
    	/**
	   	 * @brief   Substitui uma subárvore como um filho de seu pai por outra subárvore
    	 * @param   u 	Nó que será substituído pelo nó v
     	 * @param   v 	Nó que substituirá o nó u
     	 */
		void transplant(Node * u, Node * v);
  	
    	/**
     	 * @brief   Destrói os nós da árvore
     	 * @param   x   Nó a terá os subnós destruídos
     	 */ 
    	void destroyTheTree(Node * x);

		///   ********* PERCORRENDO ATRAVÉS DA ÁRVORE  ********** 
	
		/**
		 *	@brief		Parte recursiva Pré-Ordem
		 * 	@param		x 	Nó atual 
		*/	
		void preOrderTreeWalk(Node * x);
		
		/**
		 *	@brief		Parte recursiva In-Ordem
		 * 	@param		x 	Nó atual 
		*/	
		void inOrderTreeWalk(Node * x);

		/**
		 *	@brief		Parte recursiva Pós-Ordem
		 * 	@param		x 	Nó atual 
		*/	
		void posOrderTreeWalk(Node * x);

		/**
     	 * @brief   Busca recursivamente a chave na árvore
     	 * @param   x     Nó a partir do qual será buscado
     	 * @param   key   Chave a ser buscada
     	 * @return  Um ponteiro nulo ou o ponteiro para o nó buscado
     	 */ 
    	Node* searchRecursively(Node *& x, int key);
	   	  	
    	/**
     	 * @brief   Realiza uma rotação SIMPLES à esquerda
     	 * @param   x   Nó que sofrerá a rotação e descerá de nível
     	 */ 
    	void leftRotate( Node* x);

	   	/**
     	 * @brief   Realiza uma rotação SIMPLES à direita
     	 * @param   x   Nó que sofrerá a rotação e subirá de nível
     	 */ 
    	void rightRotate(Node* y);

	   	void fixUpOfColorsInsert(Node* z);
		void fixUpOfColorsRemove(Node* z);

		/**
		 * @brief   Busca o nó que contém o sucessor do nó x
		 * @param   x   Nó o qual será buscando o seu sucessor
		 * @return  Nó sucessor
		 */ 
		Node* sucessor(Node* x);

};

#endif