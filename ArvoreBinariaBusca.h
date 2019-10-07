#ifndef ARVOREBINARIABUSCA_H_INCLUDED
#define ARVOREBINARIABUSCA_H_INCLUDED

typedef int TipoItem;

class ArvoreBinariaBusca
{
          public:

            struct Celula
            {
                TipoItem Dado;
                Celula *Esq, *Dir;
                int Altura;
                int Nivel;
            };


              ArvoreBinariaBusca();
              ~ArvoreBinariaBusca();
              bool Vazia();
              int Tamanho();
              bool Inserir(TipoItem Dado);
              bool Pesquisar(TipoItem Dado);
              bool RemoverFusao(TipoItem Dado);
              bool RemoverCopia(TipoItem Dado);
              void Percurso(int ordem);
              int CalculaAltura();
              void CalculaNivel();

      private:

              Celula *Raiz;
              int Contador;

              bool Inserir(TipoItem Dado, Celula *&Raiz);
              bool Pesquisar(TipoItem Dado, Celula *Raiz);
              bool RemoverFusao(TipoItem Dado, Celula *&Raiz);
              bool RemoverCopia(TipoItem Dado, Celula *&Raiz);
              void EmOrdem(Celula *Raiz);
              void PreOrdem(Celula *Raiz);
              void PosOrdem(Celula *Raiz);
              void PorNivel(Celula *Raiz);
              int CalculaAltura(Celula *Raiz);
              void CalculaNivel(Celula *Raiz, Celula *Ant);
              void Destruir(Celula *&Raiz);
};

#endif // ARVOREBINARIABUSCA_H_INCLUDED
