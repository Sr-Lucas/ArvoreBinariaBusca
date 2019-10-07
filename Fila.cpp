#include <iostream>
#include <stdlib.h>

#include "Fila.h"

using namespace std;


//------------------INÍCIO DA IMPLEMENTAÇÃO DA FILA-----------------------------
//Um construtor é um método que é executado antes da fila ser utilizada
Fila::Fila()
{


  Frente = Tras = NULL;  //estado inicial da fila.
                         //Tanto Frente quanto Tras devem apontar para NULL
                         //indicando que nenhum Dado foi enfileirado
                         //Frente e Tras [nos métodos a seguir] sempre são
                         //utilizados na manipulação da Fila dinâmica

  Contador = 0;   //Armazena a quantidade de Dados na Fila
                  //Como a Fila está sendo construída, não há Dados
}

//Método para recuperar a memória dinâmica alocada para a Fila
//Ao contrário de um construtor, o destrutor é um método executado
//depois da fila ser utilizada
Fila::~Fila()
{


   Celula *Temp;  //Ponteiro temporário utilizado para desalocar a memória

   while(Frente != NULL)  //Enquanto Frente não chegar em Nulo (Enquanto a Fila não estiver vazia)
   {
     Temp = Frente;  //o ponteiro temporário deve apontar para o mesmo endereço que Frente
     Frente = Frente -> Prox; //Frente avança para a célula seguinte

     Temp->Prox = NULL; //desliga a célula a ser excluída da Fila
     delete Temp;  //desaloca o espaço de memória (célula) apontado por Temp
   }
}

//Função para indicar se a Fila está ou não vazia (se exite ou não algum Dado armazenado)
bool Fila::Vazia()
{

   return Frente == NULL;  //Pela forma como os Dados são Enfileirados e Desenfileirados (métodos a seguir)
                           //tem-se que a Fila está vazia se um dos ponteiros (nesse caso, Frente)
                           //aponta para NULL

                           //se Frente apontar para NULL, a função retorna verdadeiro
                           //caso contrário, será retornado falso (operador de comparação ==)

                          //Esse comando poderia também ser substituído por Contador == 0
                          //uma vez que essa variável indica a quantidade de Dados
                          //armazenados na Fila
}


//Função para retornar a quantidade de Dados armazenados na Fila
int Fila::Tamanho()
{
    return Contador;  //É retornado o contador de Dados, manipulado nos métodos de Enfileirar e Desenfileirar
}



//Método para adicionar Dados na Fila (Enfileirar)
//Se o Dado for Enfileirado (armazenado na Fila), o método retorna verdadeiro
//caso contrário, retorna falso
//Esse método também é conhecido como Enqueue
bool Fila::Enfileirar(TipoDado Dado)
{

   Celula *Nova;  //Ponteiro temporário utilizado para apontar para a nova célula a ser criada

   if((Nova = new(Celula))==NULL)  //tenta alocar dinâmicamente na memória a primeira célula da Fila
   {                                                             //e Nova deve apontar para esse endereço de memória

       //caso não for possível alocar mais uma célula na memória (Nova aponta para NULL e torna a condição do if verdadeira)
       //Retona falso, indicando que nenhum Dado foi Enfileirado (não foi possível alocar mais memória)
       return false;
   }
   else
   {
          Nova->Dado = Dado; //Como Nova aponta para um espaço de memória disponível, guardamos o Dado a ser armazenado nesse espaço
          Nova->Prox = NULL;  //Sendo Nova a última celula que será adicionada na Fila,
                              //seu ponteiro Prox deve apontar para NULL (Fim da Fila)

          if(Vazia())  //Caso a Fila esteja em seu estado inicial
            Frente = Nova;  //Corrige o ponteiro Frente, que deve apontar para a nova (e única) célula da Fila
          else Tras->Prox = Nova;  //caso a Fila não esteja no estado inicial,
                                   //Faz a ligação entre a última célula encadeada na Fila, com a Nova célula criada

          Tras = Nova;  //Nova sempre deve apontar para a nova célula criada
          Contador++;       //Um Dado foi enfileirado, portanto deve-se incrementar o contador de Dados da Fila

          return true;            //Retona verdadeiro, indicando que o Dado foi Enfileirado (inserido na Fila)
   }
}


//Método para remover Dados da Fila
//Se o Dado for Desenfileirado (removido da Fila), o método retorna verdadeiro
//caso contrário, retorna falso
//O Dado na Frente da Fila é removido e retornado por referência pelo parâmetro da função
//Esse método também é conhecido como Dequeue
bool Fila::Desenfileirar(TipoDado &Dado)
{

     if(!Vazia()){  //Se a Fila não estiver vazia, podemos remover algum Dado

        Celula *Temp = Frente;//Cria um ponteiro temporário (Temp) e faz apontar para o mesmo endereço de Frente
                                  //Essa célula será excluída da Fila

        Dado = Frente->Dado;  //Como Frente deve apontar para uma célula com o primeiro valor
                                  //a ser desenfileirado, deve ser retornado o Dado dentro da célula
                                  //apontada por Frente

        Frente = Frente->Prox;  //Faz o ponteiro de Frente da Fila apontar para a célula seguinte
                                //Esse procedimento define a célula eleita como sendo a primeira da Fila

        Temp->Prox = NULL;  //Remove a ligação entre a célula a ser excluída e a célula de frente da Fila (Segurança)

        delete Temp;         //Desaloca o espaço de memória reservado pela célula apontada por Temp
                            //(devolve esse espaço de memória ao sistema operacional)

        if(Frente == NULL) //Se Frente, ao apontar para célula seguinte, for igual a NULL, significa que a Fila só tinha um Dado armzenado e este foi excluído (A Fila agora está vazia)
          Tras = NULL;  //No caso de Fila vazia, Tras também deve apontar para NULL (Estado inicial da Fila)

        Contador--;  //"Contador" é decrementado para indicar que um Dado foi removido da Fila (desenfileirado)

        return true;   //Retona verdadeiro, indicando que o Dado foi desenfileirado
     }
     else //caso a Fila esteja vazia
       return false;  //Retona falso, indicando que nenhum Dado foi desenfileirado (a Fila está vazia)
}

//Método para retornar o Dado na frente da Fila sem reemovê-lo
//O Dado é retornado por referência pelo parâmetro da função
bool Fila::Front(TipoDado &Dado)
{
     if(!Vazia())  //primeiro deve-se conferir se a Fila não está vazia
     {
        Dado = Frente->Dado;  //assim como no método Desenfileirar, a primeira célula
                                  //na Fila apontada por Frente possui um valor válido

                                  //Repare que aqui a variável Frente não avança na Fila,
                                  //o que iria "remover" o Dado da Fila
        return true;  //retorna verdadeiro indicando que um Dado foi retornado
     }
     else //caso a Fila esteja vazia
          return false;  //retorna falso, indicando que não foi possível retornar um Dado
}
