#include <iostream>
#include <stdlib.h>

#include "Fila.h"

using namespace std;


//------------------IN�CIO DA IMPLEMENTA��O DA FILA-----------------------------
//Um construtor � um m�todo que � executado antes da fila ser utilizada
Fila::Fila()
{


  Frente = Tras = NULL;  //estado inicial da fila.
                         //Tanto Frente quanto Tras devem apontar para NULL
                         //indicando que nenhum Dado foi enfileirado
                         //Frente e Tras [nos m�todos a seguir] sempre s�o
                         //utilizados na manipula��o da Fila din�mica

  Contador = 0;   //Armazena a quantidade de Dados na Fila
                  //Como a Fila est� sendo constru�da, n�o h� Dados
}

//M�todo para recuperar a mem�ria din�mica alocada para a Fila
//Ao contr�rio de um construtor, o destrutor � um m�todo executado
//depois da fila ser utilizada
Fila::~Fila()
{


   Celula *Temp;  //Ponteiro tempor�rio utilizado para desalocar a mem�ria

   while(Frente != NULL)  //Enquanto Frente n�o chegar em Nulo (Enquanto a Fila n�o estiver vazia)
   {
     Temp = Frente;  //o ponteiro tempor�rio deve apontar para o mesmo endere�o que Frente
     Frente = Frente -> Prox; //Frente avan�a para a c�lula seguinte

     Temp->Prox = NULL; //desliga a c�lula a ser exclu�da da Fila
     delete Temp;  //desaloca o espa�o de mem�ria (c�lula) apontado por Temp
   }
}

//Fun��o para indicar se a Fila est� ou n�o vazia (se exite ou n�o algum Dado armazenado)
bool Fila::Vazia()
{

   return Frente == NULL;  //Pela forma como os Dados s�o Enfileirados e Desenfileirados (m�todos a seguir)
                           //tem-se que a Fila est� vazia se um dos ponteiros (nesse caso, Frente)
                           //aponta para NULL

                           //se Frente apontar para NULL, a fun��o retorna verdadeiro
                           //caso contr�rio, ser� retornado falso (operador de compara��o ==)

                          //Esse comando poderia tamb�m ser substitu�do por Contador == 0
                          //uma vez que essa vari�vel indica a quantidade de Dados
                          //armazenados na Fila
}


//Fun��o para retornar a quantidade de Dados armazenados na Fila
int Fila::Tamanho()
{
    return Contador;  //� retornado o contador de Dados, manipulado nos m�todos de Enfileirar e Desenfileirar
}



//M�todo para adicionar Dados na Fila (Enfileirar)
//Se o Dado for Enfileirado (armazenado na Fila), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//Esse m�todo tamb�m � conhecido como Enqueue
bool Fila::Enfileirar(TipoDado Dado)
{

   Celula *Nova;  //Ponteiro tempor�rio utilizado para apontar para a nova c�lula a ser criada

   if((Nova = new(Celula))==NULL)  //tenta alocar din�micamente na mem�ria a primeira c�lula da Fila
   {                                                             //e Nova deve apontar para esse endere�o de mem�ria

       //caso n�o for poss�vel alocar mais uma c�lula na mem�ria (Nova aponta para NULL e torna a condi��o do if verdadeira)
       //Retona falso, indicando que nenhum Dado foi Enfileirado (n�o foi poss�vel alocar mais mem�ria)
       return false;
   }
   else
   {
          Nova->Dado = Dado; //Como Nova aponta para um espa�o de mem�ria dispon�vel, guardamos o Dado a ser armazenado nesse espa�o
          Nova->Prox = NULL;  //Sendo Nova a �ltima celula que ser� adicionada na Fila,
                              //seu ponteiro Prox deve apontar para NULL (Fim da Fila)

          if(Vazia())  //Caso a Fila esteja em seu estado inicial
            Frente = Nova;  //Corrige o ponteiro Frente, que deve apontar para a nova (e �nica) c�lula da Fila
          else Tras->Prox = Nova;  //caso a Fila n�o esteja no estado inicial,
                                   //Faz a liga��o entre a �ltima c�lula encadeada na Fila, com a Nova c�lula criada

          Tras = Nova;  //Nova sempre deve apontar para a nova c�lula criada
          Contador++;       //Um Dado foi enfileirado, portanto deve-se incrementar o contador de Dados da Fila

          return true;            //Retona verdadeiro, indicando que o Dado foi Enfileirado (inserido na Fila)
   }
}


//M�todo para remover Dados da Fila
//Se o Dado for Desenfileirado (removido da Fila), o m�todo retorna verdadeiro
//caso contr�rio, retorna falso
//O Dado na Frente da Fila � removido e retornado por refer�ncia pelo par�metro da fun��o
//Esse m�todo tamb�m � conhecido como Dequeue
bool Fila::Desenfileirar(TipoDado &Dado)
{

     if(!Vazia()){  //Se a Fila n�o estiver vazia, podemos remover algum Dado

        Celula *Temp = Frente;//Cria um ponteiro tempor�rio (Temp) e faz apontar para o mesmo endere�o de Frente
                                  //Essa c�lula ser� exclu�da da Fila

        Dado = Frente->Dado;  //Como Frente deve apontar para uma c�lula com o primeiro valor
                                  //a ser desenfileirado, deve ser retornado o Dado dentro da c�lula
                                  //apontada por Frente

        Frente = Frente->Prox;  //Faz o ponteiro de Frente da Fila apontar para a c�lula seguinte
                                //Esse procedimento define a c�lula eleita como sendo a primeira da Fila

        Temp->Prox = NULL;  //Remove a liga��o entre a c�lula a ser exclu�da e a c�lula de frente da Fila (Seguran�a)

        delete Temp;         //Desaloca o espa�o de mem�ria reservado pela c�lula apontada por Temp
                            //(devolve esse espa�o de mem�ria ao sistema operacional)

        if(Frente == NULL) //Se Frente, ao apontar para c�lula seguinte, for igual a NULL, significa que a Fila s� tinha um Dado armzenado e este foi exclu�do (A Fila agora est� vazia)
          Tras = NULL;  //No caso de Fila vazia, Tras tamb�m deve apontar para NULL (Estado inicial da Fila)

        Contador--;  //"Contador" � decrementado para indicar que um Dado foi removido da Fila (desenfileirado)

        return true;   //Retona verdadeiro, indicando que o Dado foi desenfileirado
     }
     else //caso a Fila esteja vazia
       return false;  //Retona falso, indicando que nenhum Dado foi desenfileirado (a Fila est� vazia)
}

//M�todo para retornar o Dado na frente da Fila sem reemov�-lo
//O Dado � retornado por refer�ncia pelo par�metro da fun��o
bool Fila::Front(TipoDado &Dado)
{
     if(!Vazia())  //primeiro deve-se conferir se a Fila n�o est� vazia
     {
        Dado = Frente->Dado;  //assim como no m�todo Desenfileirar, a primeira c�lula
                                  //na Fila apontada por Frente possui um valor v�lido

                                  //Repare que aqui a vari�vel Frente n�o avan�a na Fila,
                                  //o que iria "remover" o Dado da Fila
        return true;  //retorna verdadeiro indicando que um Dado foi retornado
     }
     else //caso a Fila esteja vazia
          return false;  //retorna falso, indicando que n�o foi poss�vel retornar um Dado
}
