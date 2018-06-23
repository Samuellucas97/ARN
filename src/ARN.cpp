/**
 * @file		ARN.h 
 * @brief     	Contém a implementação dos métodos da classe ARN que representa uma árvore rubro-negra
 * @author 		Samuel Lucas de Moura Ferino
 * @since		12.06.2018
 * @version		0.0.6
*/


/*!	\include ARN.h	
		\brief	Contém a classe ARN que representa um nó de uma árvore rubro-negra
 */
#include "ARN.h"

#include <iostream>
using std::cout;
using std::endl;

#include <queue>
using std::queue;

/**
 * @brief Iniciamos apenas com o nó externo (Construtor padrão)
 */	
ARN::ARN(){
	this->externo = new Node();
	this->externo->cor = NEGRO;
	this->externo->p = this->externo;	
	this->externo->esquerda = this->externo;	
	this->externo->direita = this->externo;			
	this->raiz = this->externo;
	this->quantidadeDeElementos = 0;
}

/**
 * @brief	Destrutor padrão 
 */	
ARN::~ARN(){

	if(quantidadeDeElementos > 0){
		destroyTheTree(this->raiz);
		cout << endl << "Árvore sendo destruída... (LINHA 39)" << endl;
	}


	delete this->externo;
}

/**
 * @brief		Percorre a árvore toda recursivamente, imprimindo-a
 */
void 
ARN::travellingRecursively(void){

	if(this->quantidadeDeElementos > 0){
		
		/// PRE-ORDEM

		/*!	\var	Node * copyRootPre 
		 		\brief	 Copia do nó raiz que será usado no momento de percorrer pré-ordem a árvore 
		 */
		Node * copyRootPre = this->raiz; 			

		cout << "PRE-ORDEM: ";

		preOrderTreeWalk(copyRootPre);

		/// IN-ORDEM

		/*!	\var	Node * copyRootIn 
				\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
		 */
		Node * copyRootIn = this->raiz; 			

		cout << endl << "IN-ORDEM: ";

		inOrderTreeWalk(copyRootIn);

		/// POS-ORDEM

		/*!	\var	Node * copyRootPos 
				\brief	 Copia do nó raiz que será usado no momento de percorrer pós-ordem a árvore	 
		 */
		Node * copyRootPos = this->raiz; 				

		cout << endl << "POS-ORDEM: ";

		posOrderTreeWalk(copyRootPos);
		
		cout << endl;
	}	
		
}

/**
 * @brief 	Percorre por nível imprimindo as cores
 */
void 
ARN::levelTravel(){
	
	if( this->raiz != this->externo ){		
		/*! \var queue<Node *> fila
		 		\brief	Fila usada como meio para guardar cada elemento por ordem 
		 */
		queue<Node *> fila; 

		/*!	\var Node * x
				\brief	Nó auxiliar usado no momento de percorrer por nível a ABB
		 */
		Node * x = this->raiz;	 	
		
		fila.push( x );			

		while( !fila.empty() ){

			x = fila.front();
			fila.pop();
			
			cout << x->chave << " (";
			
			if( x->cor == RUBRO){ 
				cout << "RUBRO)" << endl;
			}	
			else{
				cout << "NEGRO)" << endl;
			}	 	

			if( x->esquerda != this->externo ){   /// HÁ NÓ FILHO À ESQUERDA
				fila.push( x->esquerda );
			}

			if( x->direita != this->externo ){	/// HÁ NÓ FILHO À DIREITA
				fila.push( x->direita );
			}
			
		}

	}			

}


/**
 * @brief   Busca iterativamente a chave na árvore
 * @param   key   Chave a ser buscada
 * @return  true caso tenha encontrado o respectivo nó com a chave senão false
 */ 
bool 
ARN::search(int key){
	
	if( this->quantidadeDeElementos == 0){		/// CASO EM QUE A ÁRVORE É VAZIA
		return false;
	}	

	/*!	\var	Node * copyRoot 
			\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
	 */
    Node * copyRoot = this->raiz;
    
	while( copyRoot != this->externo){
  	        	
      	if( key == copyRoot->chave ){ /// Value IGUAL A CHAVE DO PONTEIRO ATUAL
        	return true;
      	}
	    else if( key < copyRoot->chave ){ /// Value MENOR QUE CHAVE DO PONTEIRO ATUAL
        	copyRoot = copyRoot->esquerda;
    	}
    	
      	else{ /// Value MAIOR QUE CHAVE DO PONTEIRO ATUAL
        	copyRoot = copyRoot->direita; 
      	}
    }   
  	      

	return false;

}  


/**
 * @brief   Cria um novo nó com o conteúdo entrado, identifica o local 
 *          onde ele deve ser colocado na árvore e adiciona-o se não existe
 *			previamente
 * @param   value   Conteúdo do novo nó
 * @return 	True se for adicionado senão false
 */
bool 
ARN::insert(int value){

	if( search(value) == false ){
		insertNode( new Node(value, this->externo, this->externo, this->externo) );
		++this->quantidadeDeElementos;
		return true;
	}	

	return false;
} 

/**
 * @brief   Identifica o local onde o novo nó deve ser colocado na árvore e adiciona-o se não existe
 *			previamente
 * @param   z   Nó a ser adicionado
 * @return 	True se for adicionado senão false
 */ 
void 
ARN::insertNode(Node* z){

    Node* x = this->raiz; 

    /*!	\var	Node * nodeSearch 
			\brief	 Nó anterior ao local em que será adicionado o novo nó	 
	 	 */
		Node* y = this->externo;
	  	    
	    /// BUSCANDO SE O NÓ JÁ EXISTE
	    while( x != this->externo){
	      
	    	y = x;
	      	
		  	if( z->chave < x->chave ){ /// Value MENOR QUE CHAVE DO PONTEIRO ATUAL
	        	x = x->esquerda;
	    	}
	      	else{ /// Value MAIOR QUE CHAVE DO PONTEIRO ATUAL
	        	x = x->direita; 
	      	}
	    }   
	    	
	    z->p = y;	

	    if( y == this->externo ){
	    	this->raiz = z ;
	    }
	    else if( z->chave < y->chave ){
	    	y->esquerda = z;
	    }
	    else{
	    	y->direita = z;
	    }

	    z->esquerda = this->externo;
	    z->direita = this->externo;
	    z->cor = RUBRO;

		fixUpOfColorsInsert(z);    
		
}


/**
 * @brief   Busca o extremo nó à esquerda de qualquer nó
 * @param   x   Nó usado como ponto de partida
 * @return  O nó extremo à esquerda
 */
Node* 
ARN::mimimunOfAnyNode(Node * x){

  
  while(x->esquerda != this->externo){ /// ENQUANTO TIVER DESCENTE À ESQUERDA

    x = x->esquerda;

  }
  
  return x;
 
}


bool
ARN::deleta( int value){

    if( this->quantidadeDeElementos > 0){
			 	    	
        /*!	\var	Node* nodeAlvo 
	      		\brief 	Guarda a posição do nó na ABB correspondente à chave, se existir
	     */	
	    Node* nodeAlvo = this->raiz;
	    
	    /*!	\var	bool flag 
	      		\brief 	Variavel auxiliar que guarda true caso o No alvo seja RUBRO e guarda false caso contrario
	     */	
	    bool flag = true;
  	    
  	    /// BUSCANDO SE O NÓ EXISTE
  	    while( nodeAlvo != this->externo &&  value !=  nodeAlvo->chave ){	

  		    if( value <  nodeAlvo->chave ){ /// Value MENOR QUE CHAVE DO PONTEIRO ATUAL
  	        	nodeAlvo = nodeAlvo->esquerda;
  	    	}
  	    	
  	      	else{ /// Value MAIOR QUE CHAVE DO PONTEIRO ATUAL
  	        	nodeAlvo =  nodeAlvo->direita; 
  	      	}
  	    } 
  	    
  	    if( nodeAlvo == this->externo ){ 	/// O NÓ CORRESPONDENTE A CHAVE NÃO FOI ENCONTRADO NA ÁRVORE
  	    	return false;
  		}
  	    
  	    if(nodeAlvo->cor == RUBRO){  /// CASO EM QUE O NÓ REMOVIDO (nodeAlvo) É RUBRO. PORTANTO, A CONTAGEM DE NÓS NEGROS NÃO É ALTERADA  
  	    	flag = false;
  	    }

		if( nodeAlvo-> esquerda == this->externo){  /// O NÓ nodeAlvo A SER REMOVIDO **NÃO TEM** FILHO À ESQUERDA
			transplant(nodeAlvo, nodeAlvo->direita );
		}
		else if( nodeAlvo->direita == this->externo){  /// O NÓ nodeAlvo A SER REMOVIDO **NÃO TEM** FILHO À DIREITA
			transplant(nodeAlvo, nodeAlvo->esquerda );
		}
		else{  /// O NÓ nodeAlvo A SER REMOVIDO **TEM** FILHO À ESQUERDA E À DIREITA

			Node* menorMaiorNoh = mimimunOfAnyNode(nodeAlvo->direita ); /// PEGO O MENOR DOS FILHOS À DIREITA DE nodeAlvo PARA GARANTIR QUE SEJA MAIOR QUE TODOS OS DESCENTES À ESQUERDA DE nodeAlvo

			if(menorMaiorNoh->p != nodeAlvo){
				transplant(menorMaiorNoh, menorMaiorNoh->direita );
				menorMaiorNoh->direita = nodeAlvo->direita ;
				menorMaiorNoh-> p-> direita = menorMaiorNoh ;
			}
			transplant( nodeAlvo, menorMaiorNoh );
			menorMaiorNoh->esquerda = nodeAlvo->esquerda ;
			menorMaiorNoh->esquerda = menorMaiorNoh;

		
		}
  	//   	if(flag == true){
	//		fixUpOfColorsRemove(nodeAlvo);  	   	
	  // 	}


  	   	--(this->quantidadeDeElementos);   /// DECREMENTANDO NA QUANTIDADE TOTAL DE NÓS DA ÁRVORE	
  	   	return true;
    }
   	
   	/// TENTATIVA DE REMOÇÂO EM ÁRVORE VAZIA
    return false;
}


/**
 * @brief   Remove da árvore o nó com a respectiva chave, se existir
 * @param   value 	Valor da chave a ser removida
 */ 
bool 
ARN::remove( int value ){	

	/*!	\var Node* noAlvo
	 		\brief Guardará o nó que será removido da árvore Rubro-negra
	 */		
    Node* noAlvo = this->raiz;
    
    /*!	\var Node* noAuxiliar
	 		\brief Guardará o nó que a partir do qual haverá o recolorimento. Por questões de estética, será inicializado com nodeAlvo
	 */		
    Node* noAuxiliar = noAlvo;
    
	while( noAlvo->chave != value){  /// BUSCANDO O NÓ

		if(  noAlvo == this->externo){ /// NÓ NÃO ENCONTRADO
			return false;
		}

		if( value < noAlvo->chave ){ /// O VALOR BUSCADO É MENOR QUE A CHAVE DO NÓ ATUAL POR ISSO DEVE-SE REALIZAR A BUSCA NA SUB-ÁRVORE ESQUERDA DO NÓ ATUAL
			noAlvo = noAlvo->esquerda;
		}
		else{ /// O VALOR BUSCADO É MAIOR OU IGUAL A CHAVE DO NÓ ATUAL. SE FOR IGUAL A BUSCA TERMINA SENÃO DEVE-SE REALIZAR A BUSCA NA SUB-ÁRVORE DIREITA DO NÓ ATUAL
			noAlvo = noAlvo->direita;
		}
	}

cout << "chave" << noAuxiliar->chave << endl;

	removeNode( noAuxiliar );

	--this->quantidadeDeElementos;

	return true;
    
}  

/**
 * @brief   Identifica o local onde do nó na árvore a ser removido e se existir, remove-o
 * @param   z   Nó a ser removido
 * @return  \code{.cpp}true\endcode caso tenha sido removido, \code{.cpp}false\endcode caso contrário
 */ 
void 
ARN::removeNode( Node* noQueSeraRemovido ){

	Node* y = noQueSeraRemovido;
	Node* x = noQueSeraRemovido;

	
	if( noQueSeraRemovido->esquerda == this->externo || noQueSeraRemovido->direita == this->externo){
		y = noQueSeraRemovido;
	}
	else{
		y = sucessor(noQueSeraRemovido);
	}

	cout << "a chave do y é " << y->chave << endl;

	if( y->esquerda != this->externo ){
		x = y->esquerda;
	}
	else{
		x = y->direita;
	}


	if( x ){
		x->p = y->p;
	}

	if( y->p == this->externo ){
		this->raiz = x;
	}
	else if( y == y->p->esquerda ){
		y->p->esquerda = x;
	}
	else{
		y->p->direita = x;

	}
		levelTravel();
	std::cout << "sucessor(this->raiz)->chave"<< std::endl;
	if( y != noQueSeraRemovido ){
		noQueSeraRemovido->chave = y->chave;
	}

	if( y->cor == NEGRO )
	{
		fixUpOfColorsRemove(x);
	}	

}

/**
 * @brief   Substitui uma subárvore como um filho de seu pai por outra subárvore
 * @param   u 	Nó que será substituído pelo nó v
 * @param   v 	Nó que substituirá o nó u
 */
void 
ARN::transplant(Node * u, Node * v){

	if( u->p == this->externo ){ /// CASO EM QUE SERÁ REMOVIDA A RAIZ, POR ISSO, v SERÁ A NOVA RAIZ 
	  this->raiz = v;
	}
	else if( u == u->p->esquerda ){ /// u É O FILHO À ESQUERDA
	  u->p->esquerda = v;
	}
	else{ /// u É O FILHO À DIREITA
	  u->p->direita =v;
	}
	if(v != this->externo){ /// JÁ QUE FOI MOVIDO UM FILHO NÃO NULO, FALTA DIZER QUEM É O PAI DELE 
	  v->p = u->p;
	}

}

/**
 * @brief   Destrói os nós da árvore
 * @param   x   Nó a terá os subnós destruídos
 */ 
void 
ARN::destroyTheTree(Node * x){

	if(x != this->externo){     /// CASO O NÓ **NÃO SEJA** NULO

		Node * copyLeft = x->esquerda;
		Node * copyRight = x->direita;

	    destroyTheTree(copyLeft);
	    destroyTheTree(copyRight);
	
	    delete x;
	    
	}

}

/**
 *	@brief	Parte recursiva Pré-Ordem
 * 	@param	x 	Nó atual 
 */	
void 
ARN::preOrderTreeWalk(Node * x){
	
	if( x != this->externo){			/// CASO O NÓ **NÃO SEJA** NULO
		
		cout << " " << x->chave << " ";
		preOrderTreeWalk( x->esquerda );
		preOrderTreeWalk( x->direita );

	}

}

/**
 * @brief	Parte recursiva In-Ordem
 * @param	x 	Nó atual 
 */	
void 
ARN::inOrderTreeWalk(Node * x){
	
	if( x != this->externo){			/// CASO O NÓ **NÃO SEJA** NULO
		
		inOrderTreeWalk( x->esquerda );
		cout << " " << x->chave;
		inOrderTreeWalk( x->direita );

	}
	
}

/**
 *	@brief	Parte recursiva Pós-Ordem
 * 	@param	x 	Nó atual 
*/	
void 
ARN::posOrderTreeWalk(Node * x){
	
	if( x != this->externo){			/// CASO O NÓ **NÃO SEJA** NULO
		
		posOrderTreeWalk( x->esquerda );
		posOrderTreeWalk( x->direita );
		cout << " " << x->chave << " ";

	}

}


/**
 * @brief   Realiza uma rotação SIMPLES à esquerda
 * @param   x   Nó que sofrerá a rotação e descerá de nível
 */ 
void 
ARN::leftRotate(Node* x){

	Node* y = x->direita;
	x->direita = y->esquerda;	/// FAZ DA SUBÁRVORE ESQUERDA DE y A SUBÁRVORE DIREITA DE x
	
	if( x->esquerda != this->externo){    /// VERIFICANDO SE O FILHO DE x NÃO É UM NÓ EXTERNO
		y->esquerda->p = x;
	}

	y->p = x->p;				/// LIGA O PAI DE x A y

	if(x->p == this->externo){  /// CASO EM QUE x É RAIZ
		this->raiz = y;	
	}
	else if( x == x->p->esquerda ){  /// CASO EM QUE O x É O FILHO À ESQUERDA
		x->p->esquerda = y;
	}
	else{  /// CASO EM QUE O x É O FILHO À DIREITA
		x->p->direita = y;	
	}

	y->esquerda = x;
	x->p = y;		

}

/**
 * @brief   Realiza uma rotação SIMPLES à direita
 * @param   x   Nó que sofrerá a rotação e subirá de nível
 */ 
void 
ARN::rightRotate(Node* y){

	
	Node* x = y->esquerda;
	y->esquerda = x->direita;		/// FAZ DA SUBÁRVORE DIREITA DE x A SUBÁRVORE ESQUERDA DE y
	
	if( x->direita != this->externo ){    /// VERIFICANDO SE O FILHO DE x NÃO É NULO
		x->direita->p = y;
	}

	x->p = y->p;					/// FAZ O PAI DE y SER O PAI DE x

	if(y->p == this->externo){  /// CASO EM QUE y É RAIZ
		this->raiz = x;	
	}
	else if( y == y->p->direita ){  /// CASO EM QUE O y É O FILHO À ESQUERDA
		y->p->direita = x;
	}
	else{  /// CASO EM QUE O y É O FILHO À DIREITA
		y->p->esquerda = x;	
	}

	x->direita = y;
	y->p = x;

		

}

void 
ARN::fixUpOfColorsInsert(Node* z){

	while(z->p->cor == RUBRO){
		
		if(z->p == z->p->p->esquerda ){ 
			
			Node* y = z->p->p->direita;
			
			if( y->cor == RUBRO){				////   	CASO 1°: O TIO DIREITO Y DE Z É RUBRO
			
				z->p->cor = NEGRO;
				y->cor = NEGRO;
				z->p->p->cor = RUBRO;
				z = z->p->p;

			}									///     TÉRMINA 1º CASO	

			else{
			 	
			 	if(z == z->p->direita){			/// 		CASO 2: O TIO y DE z É NEGRO E z É UM FILHO DA DIREITA
					z = z->p;
					leftRotate(z);
				}								///     	TÉRMINA 2º CASO
				
				z->p->cor = NEGRO;				/// 			CASO 3: O TIO y DE z É NEGRO E z É UM FILHO DA ESQUERDA	
				z->p->p->cor = RUBRO;
				//tree.levelTravel();

				rightRotate(z->p->p);			///				TÉRMINA 3° CASO

			}			
		}

		else{

			Node* y = z->p->p->esquerda;
			
			if( y->cor == RUBRO){				////   	CASO 1°: O TIO DE Y DE Z É RUBRO
				z->p->cor = NEGRO;
				y->cor = NEGRO;
				z->p->p->cor = RUBRO;
				z = z->p->p;

			}									///     TÉRMINA 1º CASO	
			else{
			 	
			 	if(z == z->p->esquerda){		/// 		CASO 2: O TIO y DE z É NEGRO E z É UM FILHO DA DIREITA
					z = z->p;
					rightRotate(z);
				}								///     	TÉRMINA 2º CASO
				
				z->p->cor = NEGRO;				/// 			CASO 3: O TIO y DE z É NEGRO E z É UM FILHO DA ESQUERDA
				z->p->p->cor = RUBRO;
				leftRotate(z->p->p);			///				TÉRMINA 3° CASO
			}	

		}

	} 

	this->raiz->cor = NEGRO;

}

void 
ARN::fixUpOfColorsRemove(Node* n){

	Node* x;

	while (n != this->raiz && n->cor == NEGRO) {
		
		if (n == n->p->esquerda) {
			
			x = n->p->direita;

			if (x->cor == RUBRO) { // caso 1
				x->cor = NEGRO;
				n->p->cor = RUBRO;
				leftRotate(n->p);
				x = n->p->direita;
			}
			if ( x->esquerda->cor == NEGRO && x->direita->cor == NEGRO) { // caso 2
				x->cor = RUBRO;
				n = n->p;
			} 
			else {
				if (x->direita->cor == NEGRO) { // caso 3
					x->esquerda->cor = NEGRO;
					x->cor = RUBRO;
					rightRotate(x);
					x = n->p->direita;
				}
				// caso 4
				x->cor = n->p->cor;
				n->p->cor = NEGRO;
				x->direita->cor = NEGRO;
				leftRotate(n->p);
				n = this->raiz;
			}
		}
		else{
				x = n->p->esquerda;

				if (x->cor == RUBRO) { // caso 1
						x->cor = NEGRO;
						n->p->cor = RUBRO;
						rightRotate(n->p);
						x = n->p->esquerda;
				}
				if (x->esquerda->cor == NEGRO && x->direita->cor == NEGRO) { // caso 2
						x->cor = RUBRO;
						n = n->p;
				}	else {
						if (x->esquerda->cor == NEGRO) { // caso 3
								x->direita->cor = NEGRO;
								x->cor = RUBRO;
								leftRotate(x);
								x = n->p->esquerda;
						}
						// caso 4
						x->cor = n->p->cor;
						n->p->cor = NEGRO;
						x->esquerda->cor = NEGRO;
						rightRotate(n->p);
						n = this->raiz;
				}
		}
	}

	n->cor = NEGRO;
}	

/**
 * @brief   Busca o nó que contém o sucessor do nó x
 * @param   x   Nó o qual será buscando o seu sucessor
 * @return  Nó sucessor
 */ 
Node* 
ARN::sucessor(Node* x)
{

    if(x->direita != this->externo){ /// O NÓ x TEM FILHO À DIREITA
      x = mimimunOfAnyNode( x->direita );
    }
    
    cout << "c"  << x->chave << endl;

    /*!	\var	Node* copyFather 
				\brief	 Copia do nó pai do nó x	 
		 */
    Node* copyFather = x->p; 
     
     while(copyFather != this->externo && copyFather->direita == x ){  /// SUBINDO PELA ÁRVORE
       x = copyFather;
       copyFather = copyFather->p;
     }

     return copyFather;
}
