#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBinariaBusca.h"


/*
� Nome do aluno        : Lucas Teixeira Santos
� Objetivo do programa : Exibir os nos de uma arvore por n�vel e exibir a altura e nivel de cada na arovore;

� Entrada de dados     : A arvore deve ser preenchida com seus valores (pressionando 1 para preencher cada valor) em seguida o usu�rio
                        ira escolher '0' para exibir os valores da arvore por nivel, '66' para saber a altura de cada n� e 88 para saber
                        n�vel de cada n�.

� Resultado            :Os resultados ser�o relativos aos valors que o usu�rio esolher no menu:
                          0 - Ir� exibir todos os dados na arvore por Nivel.
                          66 - Ir� exibir todos os dados da arvore e suas respectivas alturas.
                          88 - Ir� exibir todos os dados da arvore e seus respectivos niveis.
*/

///OBS IMPORTANTE:
///    - O algoritmo considera que o menor n�vel da arvore sej� 1;
///    - O algoritmo considera que a menor altura da arvore sej� 1;


using namespace std;

//Fun��o principal para demonstrar o uso da �rvore Bin�ria de Busca
int main()
{

    int x; //Vari�vel utilizada para receber o valor digitado do usu�rio e colocar na �rvore Bin�ria de Busca
    int opcao; //vari�vel utilizada no Menu para testar a �rvore Bin�ria de Busca

    ArvoreBinariaBusca *ABB = new ArvoreBinariaBusca(); //para iniciar a �rvore Bin�ria de Busca



    do{  //menu com op��es para testar a implementa��o da �rvore Bin�ria de Busca


         system("cls");

          cout << "Programa para uso da Lista Duplamente Encadeada\n\n";
          cout << "Escolha uma das opcoes abaixo.";
          cout << "\n\n\nMenu: \n" << endl << endl;
          cout << "0 - Percurso POR NIVEL\n";
          cout << "66 - Altura de cada NO\n";
          cout << "88 - Nivel de cada NO\n";
          cout << endl << endl;
          cout << "\n1 - Inserir dado";
          cout << "\n2 - Remover dado por fusao";
          cout << "\n3 - Remover dado por copia";
          cout << "\n4 - Pesquisar dado";
          cout << "\n5 - Percurso Pre-Ordem";
          cout << "\n6 - Percurso Em-Ordem";
          cout << "\n7 - Percurso Pos-Ordem";
          cout << "\n8 - Numero de elementos na arvore";
          cout << "\n9 - Arvore vazia?";
          cout << "\n10 - Sair\n";
          cout << "\nOpcao: ";
          cin >> opcao;

          system("cls");

          switch(opcao){
        case 66:
            cout << "\n\nALTURA: \n\n";

           ABB->CalculaAltura();

            cout << "\n\n";
            system("pause");
            break;
        case 88:
            cout << "\n\nNIVEL: \n\n";

           ABB->CalculaNivel();

            cout << "\n\n";
            system("pause");
        break;
          case 0:

            cout << "\n\nPercurso POR NIVEL: \n\n";

            ABB->Percurso(3);

            cout << "\n\n";
            system("pause");

            break;

             case 1:
                        cout << "\n\nDigite o dado: ";
                        cin >> x;

                        if(ABB->Inserir(x))
                          cout << "Elemento inserido.";
                        else cout << "Erro ao inserir dado.";

                        cout << "\n\n";
                        system("pause");
                        break;

             case 2:
                         cout << "Digite um dado para remover por fusao: ";
                         cin >> x;

                         if(ABB->RemoverFusao(x))
                            cout << "\n\nDado " << x << " removido.";
                         else cout << "Erro. Dado nao encontrado.";

                         cout << "\n\n";
                         system("pause");
                         break;


             case 3:     cout << "Digite um dado para remover por copia: ";
                         cin >> x;

                         if(ABB->RemoverCopia(x))
                            cout << "\n\nDado " << x << " removido.";
                         else cout << "Erro. Dado nao encontrado.";

                         cout << "\n\n";
                         system("pause");
                         break;


             case 4:     cout << "Digite um dado para pesquisar: ";
                         cin >> x;

                         if(ABB->Pesquisar(x))
                            cout << "\n\nDado " << x << " encontrado";
                         else cout << "Erro. Dado nao encontrado.";

                         cout << "\n\n";
                         system("pause");
                         break;

            case 5:
                       cout << "\n\nDados em pre-ordem: \n";
                       ABB->Percurso(0);

                       cout << "\n\n";
                       system("pause");
                       break;

            case 6:
                       cout << "\n\nDados em em-ordem: \n";
                       ABB->Percurso(1);

                       cout << "\n\n";
                       system("pause");
                       break;


            case 7:
                       cout << "\n\nDados em pos-ordem: \n";
                       ABB->Percurso(2);

                       cout << "\n\n";
                       system("pause");
                       break;


            case 8:
                        cout << "\n\nNumero de elementos na arvore: " << ABB->Tamanho();
                        cout << "\n\n";
                        system("pause");
                        break;

            case 9:
                        if(ABB->Vazia())
                            cout << "\n\nArvore vazia.\n\n";
                        else cout << "\n\nA arvore nao esta vazia.\n\n";

                        system("pause");
                        break;


            case 10:    delete ABB;
                        break;

            default: cout << "\n\nOpcao invalida\n\n";
                     system("pause");
          }
    }while(opcao != 10);


    return 0;
}
