#include <iostream>
using namespace std;


#include "ArvoreBinariaBusca.h"
#include "Fila.h"


ArvoreBinariaBusca::ArvoreBinariaBusca()
{

    Raiz = NULL;
    Contador = 0;
}

ArvoreBinariaBusca::~ArvoreBinariaBusca(){


     Destruir(Raiz);
     Contador = 0;
}

void ArvoreBinariaBusca::Destruir(Celula *&Raiz){


     if(Raiz!=NULL)
     {
         Destruir(Raiz->Esq);
         Destruir(Raiz->Dir);

         delete(Raiz);
         Raiz = NULL;
     }
}


bool ArvoreBinariaBusca::Vazia()
{

   return Raiz == NULL;
}

int ArvoreBinariaBusca::Tamanho()
{

   return Contador;
}

bool ArvoreBinariaBusca::Inserir(TipoItem Dado)
{

     return Inserir(Dado, Raiz);
}

bool ArvoreBinariaBusca::Inserir(TipoItem Dado, Celula *&Raiz)
{

     if(Raiz == NULL)
     {
        if((Raiz = new(Celula)) == NULL)
           return false;
        else
        {
            Raiz->Dado = Dado;
            Raiz->Esq = Raiz->Dir = NULL;
            Raiz->Altura = 0;
            Raiz->Nivel = 0;
            Contador++;
            return true;
        }
     }
     else
     {
         if(Dado < Raiz->Dado)
           return Inserir(Dado, Raiz->Esq);
         else
         {
            if(Dado > Raiz->Dado)
              return Inserir(Dado, Raiz->Dir);
            else return false;
         }
     }
}


bool ArvoreBinariaBusca::Pesquisar(TipoItem Dado)
{

     return Pesquisar(Dado, Raiz);
}

bool ArvoreBinariaBusca::Pesquisar(TipoItem Dado, Celula *Raiz)
{

     if(Raiz == NULL) return false;
     else
     {
         if(Dado < Raiz->Dado)
           return Pesquisar(Dado, Raiz->Esq);
         else
         {
            if(Dado > Raiz->Dado)
              return Pesquisar(Dado, Raiz->Dir);
             else return true;
         }
     }
}

bool ArvoreBinariaBusca::RemoverFusao(TipoItem Dado)
{

    return RemoverFusao(Dado, Raiz);
}

bool ArvoreBinariaBusca::RemoverFusao(TipoItem Dado, Celula *&Raiz)
{

     Celula *Temp;

     if(Raiz == NULL) return false;
     else
     {
         if(Dado < Raiz->Dado)
           return RemoverFusao(Dado, Raiz->Esq);
         else
         {
            if(Dado > Raiz->Dado)
              return RemoverFusao(Dado, Raiz->Dir);
             else
             {
                 Temp = Raiz;

                 if(Raiz->Esq == NULL)
                    Raiz = Raiz->Dir;
                 else{
                     if(Raiz->Dir == NULL)
                        Raiz = Raiz->Esq;
                     else   //a raiz tem ambos os filhos
                     {
                        Temp = Raiz -> Esq;

                        while(Temp->Dir != NULL)
                          Temp = Temp->Dir;

                        Temp->Dir = Raiz->Dir;

                        Temp = Raiz;
                        Raiz = Raiz->Esq;
                     }
                 }
                 Temp->Dir = Temp->Esq = NULL;
                 delete(Temp);
                 Contador--;
                 return true;
             }
         }
     }
}

bool ArvoreBinariaBusca::RemoverCopia(TipoItem Dado)
{

    return RemoverCopia(Dado, Raiz);
}

bool ArvoreBinariaBusca::RemoverCopia(TipoItem Dado, Celula *&Raiz)
{

     Celula *Temp, *Ant;

     if(Raiz == NULL) return false;
     else
     {
         if(Dado < Raiz->Dado)
           return RemoverCopia(Dado, Raiz->Esq);
         else
         {
            if(Dado > Raiz->Dado)
              return RemoverCopia(Dado, Raiz->Dir);
             else
             {

                 Temp = Raiz;

                 if(Raiz->Esq == NULL)
                    Raiz = Raiz->Dir;
                 else
                 {
                     if(Raiz->Dir == NULL)
                        Raiz = Raiz->Esq;
                     else   //a raiz tem ambos os filhos
                     {
                        Temp = Raiz -> Esq;
                        Ant = Raiz;

                        while(Temp->Dir != NULL)
                        {
                          Ant = Temp;
                          Temp = Temp->Dir;
                        }

                        Raiz->Dado = Temp->Dado;

                        if(Ant == Raiz) Ant->Esq = Temp->Esq;
                        else Ant->Dir = Temp->Esq;
                     }
                 }

                 Temp->Dir = Temp->Esq = NULL;
                 delete(Temp);
                 Contador--;
                 return true;
             }
         }
     }
}


void ArvoreBinariaBusca::Percurso(int ordem)
{

     switch (ordem)
     {
        case 0: PreOrdem(Raiz); break;
        case 1: EmOrdem(Raiz); break;
        case 2: PosOrdem(Raiz); break;
        case 3: PorNivel(Raiz); break;
        default: cout <<"Ordem desconhecida";
     }
}

void ArvoreBinariaBusca::EmOrdem(Celula *Raiz)
{

     if(Raiz!=NULL)
     {
         EmOrdem(Raiz->Esq);
         cout << Raiz->Dado << " ";
         EmOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca::PreOrdem(Celula *Raiz)
{

     if(Raiz!=NULL)
     {
         cout << Raiz->Dado << " ";
         PreOrdem(Raiz->Esq);
         PreOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca::PosOrdem(Celula *Raiz)
{

     if(Raiz!=NULL)
     {
         PosOrdem(Raiz->Esq);
         PosOrdem(Raiz->Dir);
         cout << Raiz->Dado << " ";
     }

}

int ArvoreBinariaBusca::CalculaAltura() {
    return CalculaAltura(Raiz);
}

///Percorre a arovre em pos-ordem e calcula sua altura recursivamente
int ArvoreBinariaBusca::CalculaAltura(Celula *Raiz)
{
    int altura = 0;

    if(Raiz!=NULL)
    {
        altura = CalculaAltura(Raiz->Esq);
        if(Raiz->Altura < altura) Raiz->Altura = altura;
        altura = CalculaAltura(Raiz->Dir);
        if(Raiz->Altura < altura) Raiz->Altura = altura;
        cout << Raiz->Dado << "(" << Raiz->Altura << ")" << " ";
        return Raiz->Altura + 1;
    }

    return 1;
}

void ArvoreBinariaBusca::CalculaNivel() {
    CalculaNivel(Raiz, Raiz);
}

///Percorre a arvore em-ordem e calcula o nivel de cada nó recursivamente
void ArvoreBinariaBusca::CalculaNivel(Celula *Raiz, Celula *Ant) {
    if(Raiz!=NULL)
    {
        if(Raiz == Ant) {
            Raiz->Nivel = 1;
            cout << Raiz->Dado << "(" << Raiz->Nivel << ")" << " - ";
        } else {
            Raiz->Nivel = Ant->Nivel + 1;
            cout << Raiz->Dado << "(" << Raiz->Nivel << ")" << " - ";
        }

        CalculaNivel(Raiz->Esq, Raiz);
        CalculaNivel(Raiz->Dir, Raiz);
    }
}

void ArvoreBinariaBusca::PorNivel(Celula *Raiz)
{
    Fila *fila;
    if(Raiz != NULL)
    {
        fila = new Fila();
        fila->Enfileirar(*Raiz);
        while(!fila->Vazia()) {
            Celula *atual = new Celula();
            fila->Desenfileirar(*atual);
            cout << atual->Dado << " - ";
            if(atual->Esq != NULL) {
                fila->Enfileirar(*atual->Esq);
            }
            if(atual->Dir != NULL) {
                fila->Enfileirar(*atual->Dir);
            }
        }
    }
}
