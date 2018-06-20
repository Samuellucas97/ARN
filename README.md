# Árvore Rubro-Negra

Neste repositório é implementada a estrutura de dados __Árvore Rubro-Negra__ referente à atividade da 3ª unidade da disciplina de ***Estrutura de Dados II*** do bacharelado em Tecnologia da Informação (__UFRN__). 


## :page_facing_up: O que é uma Árvore Rubro-Negra?
ma árvore rubro-negra é uma árvore de busca binária onde cada nó tem um atributo de cor, vermelho ou preto. 
Além dos requisitos ordinários impostos pelas árvores de busca binárias, as árvores rubro-negras tem os seguintes requisitos adicionais:
  
:one: Um nó é **vermelho** ou **preto**.  
:two: A raiz é **preta**.   
:three: Todas as folhas ( ***nós externos/nill*** ) são **pretas**.  
:four: Ambos os filhos de todos os nós **vermelhos** são **pretos**.  
:five: Todo caminho de um dado nó para qualquer de seus nós folhas descendentes contém o mesmo número de nós **pretos**.  


<p align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/66/Red-black_tree_example.svg/1280px-Red-black_tree_example.svg.png" width="40%"  />
</p>

  
O objetivo desta árvore é estruturar os dados de forma a permitir busca, inserção e remoção sejam feita em `O(log n)`. [Wikipedia]

[Wikipedia]:https://pt.wikipedia.org/wiki/%C3%81rvore_rubro-negra
  

:hammer: **FUNCIONALIDADES IMPLEMENTADAS**  

- [:heavy_check_mark:]  search - ***O(log n)***  
	Busca a chave dada na árvore e se exitir retorna true/verdadeiro senão false/falso.
- [:x:]  insert - ***O(log n)*** - :construction: ( _Imcompleto_ )  
	Insere a chave dada na árvore se não já existir previamente, retornando true/verdadeiro, caso contrário - ou seja, a chave já existe - retorna false/falso.
- [:x:]  remove - ***O(log n)*** - :construction: ( _Imcompleto_ )  
	Remove a chave dada na árvore se já existir previamente, reotornando true/verdadeiro, caso contrário - ou seja, a chave não existe na árvore - retorna false/falso.

## Requisitos mínimos

Compilador C++ 11 (**g++**), GNU debugger (**GDB**) e Doxygen.
	
	Obs.: Para usuários Linux, tanto o g++ quanto o gdb são ambos nativo, faltando apenas instalar o Doxygen.  
	Porém, caso deseje usar o gdb no Windows será necessário instalar o MinGW. 

### :package: Download Doxygen 
  
Visite a página de [Download] ou instale diretamente no terminal usando o seguinte código caso seja usuário ***Ubuntu***:  

```$ sudo apt-get install doxygen``` 	

[Download]:http://www.stack.nl/~dimitri/doxygen/download.html

## Etapa de compilação e execução

	Obs.: Todos os códigos digitados no terminal deverão ser na respectiva pasta raiz do programa.  
	Exceto na vizualização da documentação do projeto, não será necessário alterar a pasta.

Depois de clonar o repositório na respectiva pasta local, digite ```make``` para 
realizar a compilação, resultando na criação do arquivo binário(executável) 
denominado ***arn***. Em seguida, digite ```./arn``` para executar o programa.

###  Documentação e exclusão dos objetos e do executável

Caso deseje verificar a documentação, digite ```make doxy```. Diante disso, abra a pasta **html**, depois abra o arquivo chamado **index.html** o qual possui a documentação.  

Além disso, caso deseje fazer o debugger do programa, primeiro digite no terminal ```make debug```, depois digite ```gdb ./arn```.  Ou, se quiser apagar os objetos e o executável, digite ```make clean```.

<p align="right">
<img src="https://www.star.bnl.gov/public/comp/sofi/doxygen/doxygen_logo.gif" width="14%"  />
</p>

## Autores :smile: 

Samuel Lucas de Moura Ferino ( :email:  <samuel1797@gmail.com> )
