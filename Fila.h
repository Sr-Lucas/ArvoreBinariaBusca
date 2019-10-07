#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "ArvoreBinariaBusca.h"
//------------------INÍCIO DA DEFINIÇÃO DA FILA---------------------------------
typedef ArvoreBinariaBusca::Celula TipoDado;

class Fila
{

      private:

          struct Celula
          {
                TipoDado Dado;
                Celula *Prox;
          };
          Celula *Frente, *Tras;
          int Contador;


      public:

          Fila();
          ~Fila();
          bool Vazia();
          int Tamanho();
          bool Enfileirar(TipoDado Dado);
          bool Desenfileirar(TipoDado &Dado);
          bool Front(TipoDado &Dado);
};

#endif // FILA_H_INCLUDED
