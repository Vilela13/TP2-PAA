#include <iostream>     // Biblioteca padrão de c++
#include <istream>      // Biblioteca padrão de c++
#include <list>         // Biblioteca que contem a estrutura listas
#include <string>       // Biblioteca que contem a estrutura string ( vetor de caracteres)
#include <fstream>      // Biblioteca que contem a estrutura para acessar arquivos txt
#include <vector>       // Biblioteca que contem a estrutura Vector

#include <stdio.h>      // Biblioteca padão de C, principalmente a operações de entrada e saída
#include <stdlib.h>     // Biblioteca padão de C, possui funções envolvendo alocação de memória, controle de processos, conversões e outras.


using namespace std; // utilizar o espaço de nomes em C++



class No{

public:
    No();                                       // construtora da classe

    char estado;                                // estado para uma primeira busca em profundidade
    char estado2;                               // estado para uma segunda busca em profundidade
    int Grupo;                                  // grupo conexo que o grupo pertence
    char Tipo;                                  // tipo do no: SCC, IN, OUT, TendrilA, TendrilB, TendrilC e Disconecto
    list < int > ListaAdjacentes;               // lista de nos adjacentes que são os nos que este no pode chegar
    list < int > ListaAdjacentesInversa;        // lista inversa de nos adjacentes que são os nos que podem chegar nele
    list < int > ListaVizinhos;                 // lista de nos que podem chegar nele e nos que ele pode chegar

    long int TempoDescoberta;                   // tempo descoberta na busca em profundidade
    long int TempoFinaliza;                     // tempo finalização na busca em profundidade

    ~No();       // Destridora
};

No::No(){
    estado = 'b';                   // inicializa o estado da busca em profundidade um como branco
    estado2 = 'b';                  // inicializa o estado da busca em profundidade dois como branco
    Grupo = -1;                     // inicializa o grupo conexo que ele pertence como -1
    Tipo = 'd';                     // inicializa todos os nos como disconectado
    TempoDescoberta = -2;           // inicia tempo descoberta como -2
    TempoFinaliza = -3;             // inicia tempo finaliza como -3
}


No::~No(){
}

class TempoNoFinal{

public:
    TempoNoFinal();             // construtora
    int No;                     // identifica o no
    long int TempoFinaliza;     // tempo que o no foi finalizado
    ~TempoNoFinal();            // destruidora
};

TempoNoFinal::TempoNoFinal(){

}

TempoNoFinal::~TempoNoFinal(){
}

class Algoritmo{        // Classe principal do programa

public:
    Algoritmo();                                            // construtora da classe

    vector<No> ListaDeNos;                                  // vetor dos nos do grafo

    int TamanhoVector;                                      // numero de nos no grafo

    void EscreveTXT();                                      // função que escreve uma entrada para o problema

    int Ledados(char *);                                    // le uma entrada do problema


    void ImprimeListaNos();                                 // imprime a lista de nos do grafo e seus dados



    int long TempoDFS1SCC;                                  // guarda o tempo da busca em profundidade um

    void DFS1SCC();                                         // busca em profundidade um
    void DFS1SCCVisita( int);                               // recursão da busca em profundidade um


    list<TempoNoFinal> OrdemDeTempo;                        // lista de tempos finais dos nos


    void ImprimeListaTempoFinaliza();                       // imprime a lista de tempos finais dos nos

    void OrdenaListaTempoFinaliza();                        // ordena a lista de tempos finais dos nos

    int GrupoAtual;                                         // variavel que guarda o grupo que se esta analizando no momento

    void DFS2SCC();                                         // busca em profundidade um
    void DFS2SCCVisita( int);                               // recursão da busca em profundidade dois


    list < list < int > > ListaDeGrupos;                    // listas dos grupos conexos
    list < int > GrupoX;                                    // variavel auxiliar de um grupo conexo

    void ImprimeListaDeGrupos();                            // imprime a lista dos grupos conexos

    void ColocaListaDeGrupos();                             // coloca os nos em seus respectivos grupos conexos


    list < int > MaiorGrupo;                                // lista com os nos do maior grupo conexo

    void SelecionaMaiorGrupo();                             // seleciona maior grupo conexo

    void ImprimeMaiorGrupo();                               // imprime maior grupo conexo

    void RetornaEstatosDeBuscaEmProfundidade();             // retorna os estados dos nos para a busca um e dois para branco

    void VerificaTendril();                                 // verifica se o no pode ser qualificadao como tendril A, B ou C, ou ate mesmo SCC, IN ou OUT
    void VerificaTendrilVisita( int);                       // parte da recurção da função acima

    void VerificaOUT();                                     // verifica se o no pode ser OUT ou SCC
    void VerificaOUTVisita( int);                           // parte recursiva da função acima

    void VerificaINeSCC();                                  // verifica se o no é IN ou SCC
    void VerificaINeSCCVisita( int);                        // parte da recursão acima

    int TemVisinhoIN;                                       // variavel cinalizadora se o tipo de tendril analizado um ou mais nos IN como vizinhos
    int TemVisinhoOUT;                                      // variavel cinalizadora se o tipo de tendril analizado um ou mais nos OUT como vizinhos

    void ClassificaTendrilA( int);                          // classifica os nos como tendril A
    void ClassificaTendrilB( int);                          // classifica os nos como tendril B
    void ClassificaTendrilC( int);                          // classifica os nos como tendril C
    void VerificaViszinhancaINeOut( int);                   // função que verifica se o conjunto do tendril tem nos IN ou OUT como vizinhos
    void IdentificaTipoTendriu();                           // função que identifica o tipo de tendril

    list<int>   SCC;                                        // lista dos nos SCC
    list<int>   IN;                                         // lista dos nos IN
    list<int>   OUT;                                        // lista dos nos OUT
    list<int>   TendrilA;                                   // lista dos nos TendrilA
    list<int>   TendrilB;                                   // lista dos nos TendrilB
    list<int>   TendrilC;                                   // lista dos nos tendrilC
    list<int>   Desconectados;                              // lista dos nos desconectados

    void ColocaNosEmListaDeTipos();                         // coloca em listas de tipos de nos
    void ImprimeListaDeTipos();                             // imprime a lista dos tipos de nos

    void OrdenaListaSCC();                                  // ordena a lista de tipos de nos SCC
    void OrdenaListaIN();                                   // ordena a lista de tipos de nos IN
    void OrdenaListaOUT();                                  // ordena a lista de tipos de nos OUT
    void OrdenaListaTendrilA();                             // ordena a lista de tipos de nos Tendril A
    void OrdenaListaTendrilB();                             // ordena a lista de tipos de nos Tendril B
    void OrdenaListaTendrilC();                             // ordena a lista de tipos de nos Tendril C
    void OrdenaListaDesconectados();                        // ordena a lista de tipos de nos desconectados

    void EscreveArquivosDeSaida();                          // escreve as listas dos tipos de nos em seus respectivos arquivos de saida


    ~Algoritmo();       // Destridora
};



Algoritmo::Algoritmo(){
}

void Algoritmo::EscreveTXT(){

    ofstream SaidaNos;
    SaidaNos.open("Dados1.txt");

    int NoOrigem, NoDestino;

    NoOrigem = 1; NoDestino = 2;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 1; NoDestino = 3;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 2; NoDestino = 24;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 2; NoDestino = 19;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 3; NoDestino = 4;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;

    NoOrigem = 4; NoDestino = 5;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 5; NoDestino = 6;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 5; NoDestino = 7;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 6; NoDestino = 3;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 7; NoDestino = 8;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;

    NoOrigem = 7; NoDestino = 9;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 8; NoDestino = 10;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 9; NoDestino = 13;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 10; NoDestino = 11;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 10; NoDestino = 3;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;

    NoOrigem = 11; NoDestino = 3;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 11; NoDestino = 20;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 12; NoDestino = 10;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 12; NoDestino = 28;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 13; NoDestino = 17;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;

    NoOrigem = 13; NoDestino = 16;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 14; NoDestino = 14;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 15; NoDestino = 15;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 16; NoDestino = 18;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 17; NoDestino = 18;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;

    NoOrigem = 17; NoDestino = 9;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 18; NoDestino = 13;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 19; NoDestino = 1;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 20; NoDestino = 21;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 22; NoDestino = 23;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;

    NoOrigem = 23; NoDestino = 24;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 25; NoDestino = 26;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 26; NoDestino = 9;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 27; NoDestino = 9;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 28; NoDestino = 29;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;

    NoOrigem = 29; NoDestino = 30;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 30; NoDestino = 20;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;
    NoOrigem = 6; NoDestino = 10;
    SaidaNos << NoOrigem << ' ' << NoDestino << endl;




    SaidaNos.close();
}

int Algoritmo::Ledados(char *InputChar){

    int NoOrigem;
    int Nodestino;
    int TemNo;
    No NoAux;

    TamanhoVector = 0;

    FILE * Le = fopen(InputChar, "r");

    if(!Le){
		return 0;
	}

	while(!feof(Le)){

        fscanf(Le,"%d %d\n", &NoOrigem, &Nodestino);
		//printf("%d %d\n", NoOrigem, Nodestino);

        if( TamanhoVector < NoOrigem){
            TamanhoVector = NoOrigem;
            ListaDeNos.resize(TamanhoVector + 1);
        }

        if( TamanhoVector < Nodestino){
            TamanhoVector = Nodestino;
            ListaDeNos.resize(TamanhoVector + 1);
        }

        if( NoOrigem != Nodestino){
            ListaDeNos[NoOrigem].ListaAdjacentes.push_back(Nodestino);
            ListaDeNos[Nodestino].ListaAdjacentesInversa.push_back(NoOrigem);
            ListaDeNos[NoOrigem].ListaVizinhos.push_back(Nodestino);
            ListaDeNos[Nodestino].ListaVizinhos.push_back(NoOrigem);
		}
	}

	fclose(Le);
	return 1;

}

void Algoritmo::ImprimeListaNos(){


    cout << endl << "  Conteudo da lista " << endl;
    for(int i = 1; i <= TamanhoVector; i++ ){
        cout << i <<  "   Estado1 = '" << ListaDeNos[i].estado << "' Grupo = '" << ListaDeNos[i].Grupo <<  "' Tipo = '" << ListaDeNos[i].Tipo  << "' TempoDescoberta1 = '" << ListaDeNos[i].TempoDescoberta ;
        cout << "' TempoFinalização1 = '" << ListaDeNos[i].TempoFinaliza;
        cout << "' Estado2 = '" << ListaDeNos[i].estado2 << "'" ;
        cout << endl << "      Adj = ";
        for (list< int >::iterator it2 = ListaDeNos[i].ListaAdjacentes.begin(); it2 != ListaDeNos[i].ListaAdjacentes.end(); it2++ ){
            cout << *it2 << " ";
        }
        cout << endl << "      Adj Inversa = ";

        for (list< int >::iterator it3 = ListaDeNos[i].ListaAdjacentesInversa.begin(); it3 != ListaDeNos[i].ListaAdjacentesInversa.end(); it3++ ){
            cout << *it3 << " ";
        }

        cout << endl << "      Vizinhos = ";
        for (list< int >::iterator it4 = ListaDeNos[i].ListaVizinhos.begin(); it4 != ListaDeNos[i].ListaVizinhos.end(); it4++ ){
            cout << *it4 << " ";
        }
        cout << endl << endl;
    }
}

void Algoritmo::DFS1SCC(){

    TempoDFS1SCC = 0;

    for (int i = 1; i <= TamanhoVector; i++){
        if( ListaDeNos[i].estado == 'b'){
            DFS1SCCVisita( i );
        }

    }
}

void Algoritmo::DFS1SCCVisita( int no){

    TempoNoFinal FinalTempoNo;

    ListaDeNos[no].estado = 'z';
    TempoDFS1SCC = TempoDFS1SCC + 1;
    ListaDeNos[no].TempoDescoberta = TempoDFS1SCC;

    for (list< int >::iterator it2 = ListaDeNos[no].ListaAdjacentes.begin(); it2 != ListaDeNos[no].ListaAdjacentes.end(); it2++ ){
        if( ListaDeNos[*it2].estado == 'b' ){
            DFS1SCCVisita( *it2);
        }
    }

    ListaDeNos[no].estado = 'p';
    TempoDFS1SCC = TempoDFS1SCC + 1;
    ListaDeNos[no].TempoFinaliza = TempoDFS1SCC;

    FinalTempoNo.No = no;
    FinalTempoNo.TempoFinaliza = ListaDeNos[no].TempoFinaliza;
    OrdemDeTempo.push_front(FinalTempoNo);

}

void Algoritmo::ImprimeListaTempoFinaliza(){

    TempoNoFinal FinalTempoNoAux;

    cout << endl << endl << "  Lista de ordem de tempos finais " << endl;

    for ( list < TempoNoFinal >::iterator it = OrdemDeTempo.begin(); it != OrdemDeTempo.end(); it++ ){
        FinalTempoNoAux = *it;
        cout << FinalTempoNoAux.No << "  " << FinalTempoNoAux.TempoFinaliza << endl;
    }
    cout << endl;

}

void Algoritmo::OrdenaListaTempoFinaliza(){
    TempoNoFinal FinalTempoNoAux1;
    TempoNoFinal FinalTempoNoAux2;
    TempoNoFinal Chave;

    list < TempoNoFinal >::iterator SegundoElemento;
    list < TempoNoFinal >::iterator i;
    list < TempoNoFinal >::iterator i2;

    if( OrdemDeTempo.size() > 1){

        SegundoElemento = OrdemDeTempo.begin();
        SegundoElemento++;

        for ( list < TempoNoFinal >::iterator j = SegundoElemento; j != OrdemDeTempo.end(); j++ ){
            FinalTempoNoAux1 = *j;
            Chave = FinalTempoNoAux1;
            i = j;
            i--;
            FinalTempoNoAux2 = *i;
            while( ( i != OrdemDeTempo.begin() ) and  (Chave.TempoFinaliza > FinalTempoNoAux2.TempoFinaliza) ){
                i2 = i;
                i2++;
                *i2 = *i;
                i--;
            }
            if( ( i == OrdemDeTempo.begin() ) and  (Chave.TempoFinaliza > FinalTempoNoAux2.TempoFinaliza) ){
                i2 = i;
                i2++;
                *i2 = *i;
                i--;
            }
            i2 = i;
            i2++;
            *i2 = Chave;

        }

    }
}

void Algoritmo::DFS2SCC(){

    TempoNoFinal FinalTempoNoAux;

    GrupoAtual = 1;


    for ( list < TempoNoFinal >::iterator it = OrdemDeTempo.begin(); it != OrdemDeTempo.end(); it++ ){
        FinalTempoNoAux = *it;

        if( ListaDeNos[FinalTempoNoAux.No].estado2 == 'b'){
            DFS2SCCVisita(FinalTempoNoAux.No);
            GrupoAtual = GrupoAtual +1;
        }
    }
}

void Algoritmo::DFS2SCCVisita( int no){



    ListaDeNos[no].estado2 = 'z';

    for (list< int >::iterator it2 = ListaDeNos[no].ListaAdjacentesInversa.begin(); it2 != ListaDeNos[no].ListaAdjacentesInversa.end(); it2++){
        if( ListaDeNos[*it2].estado2 == 'b' ){
            DFS2SCCVisita(*it2);
        }
    }

    ListaDeNos[no].estado2 = 'p';

    ListaDeNos[no].Grupo = GrupoAtual;
}

void Algoritmo::ImprimeListaDeGrupos(){

    list < int > ListaAux;
    int i;
    i = 1;

    cout << endl << "  Lista de grupos " << endl;
    for (list < list < int > >::iterator it1 = ListaDeGrupos.begin(); it1 != ListaDeGrupos.end(); it1++ ){
        ListaAux = *it1;
        cout << " Grupo " << i << " = ";
        for ( list < int >::iterator it2 = ListaAux.begin(); it2 != ListaAux.end(); it2++ ){
            cout << *it2 << "  ";
        }
        cout << endl;
        i++;
    }
}

void Algoritmo::ColocaListaDeGrupos(){

    int PosicaoLista;
    list < list < int > > ::iterator AuxApontadorLista;
    list < int > ListaAux;

    GrupoAtual = GrupoAtual -1;

    for( int i = 0; i < GrupoAtual; i++){
        ListaDeGrupos.push_front(ListaAux);
    }


    //cout << " galo";



    for (int i = 1; i <= TamanhoVector; i++ ){

        PosicaoLista = ListaDeNos[i].Grupo;
        PosicaoLista = PosicaoLista -1;

        AuxApontadorLista = ListaDeGrupos.begin();

        //cout << " lendo " << it->NumNo << "  " << PosicaoLista << endl;


        if( PosicaoLista > 0){
            while( PosicaoLista != 0 ){
                AuxApontadorLista++;
                PosicaoLista--;
            }
        }
        ListaAux = *AuxApontadorLista;
        ListaAux.push_front(i);
        *AuxApontadorLista = ListaAux;
    }
}

void Algoritmo::SelecionaMaiorGrupo(){

    int Tamanho;
    list < int > ListaAux;
    list < list < int > >::iterator it;

    Tamanho = 0;
    it = ListaDeGrupos.begin();
    ListaAux = *it;
    Tamanho = ListaAux.size();
    MaiorGrupo = ListaAux;


    //cout << endl << "  Lista de grupos " << endl;
    for (list < list < int > >::iterator it1 = ListaDeGrupos.begin(); it1 != ListaDeGrupos.end(); it1++ ){
        ListaAux = *it1;
        if(ListaAux.size() > Tamanho ){
            Tamanho = ListaAux.size();
            MaiorGrupo = ListaAux;
        }
    }

}

void Algoritmo::ImprimeMaiorGrupo(){

    cout << endl << endl << " Maior Grupo = ";
    for ( list < int >::iterator it2 = MaiorGrupo.begin(); it2 != MaiorGrupo.end(); it2++ ){
        cout << *it2 << "  ";
    }
    cout << endl;

}


void Algoritmo::RetornaEstatosDeBuscaEmProfundidade(){

    for (int i = 1; i <= TamanhoVector; i++ ){
        ListaDeNos[i].estado = 'b';
        ListaDeNos[i].estado2 = 'b';
    }

}


void Algoritmo::VerificaTendril(){

    int NoDeGrupoMaior;
    list < int >::iterator itMauior;

    itMauior = MaiorGrupo.begin();
    NoDeGrupoMaior = *itMauior;

    //cout << endl << endl << " No do Inicio da busca Tendril =" << NoDeGrupoMaior << endl << endl;

    VerificaTendrilVisita( NoDeGrupoMaior );

}

void Algoritmo::VerificaTendrilVisita( int it){

    ListaDeNos[it].estado = 'z';

    for (list < int >::iterator it2 = ListaDeNos[it].ListaVizinhos.begin(); it2 != ListaDeNos[it].ListaVizinhos.end(); it2++){
        if( ListaDeNos[*it2].estado  == 'b' ){
            VerificaTendrilVisita( *it2);
        }
    }

    ListaDeNos[it].estado = 'p';
    ListaDeNos[it].Tipo = 't';


}



void Algoritmo::VerificaOUT(){

    int NoDeGrupoMaior;
    list < int >::iterator itMauior;

    itMauior = MaiorGrupo.begin();
    NoDeGrupoMaior = *itMauior;

    //cout << endl << endl << " No do Inicio da busca do Out =" << NoDeGrupoMaior << endl << endl;

    VerificaOUTVisita( NoDeGrupoMaior );

}

void Algoritmo::VerificaOUTVisita( int it){

    ListaDeNos[it].estado = 'z';


    for (list < int >::iterator it2 = ListaDeNos[it].ListaAdjacentes.begin(); it2 != ListaDeNos[it].ListaAdjacentes.end(); it2++){
        if( ListaDeNos[*it2].estado  == 'b' ){
            VerificaOUTVisita( *it2);
        }
    }

    ListaDeNos[it].estado = 'p';
    ListaDeNos[it].Tipo = 'o';


}


void Algoritmo::VerificaINeSCC(){

    int NoDeGrupoMaior;
    list < int >::iterator itMauior;

    itMauior = MaiorGrupo.begin();
    NoDeGrupoMaior = *itMauior;

    //cout << endl << endl << " No do Inicio da busca do INeSCC =" << NoDeGrupoMaior << endl << endl;

    VerificaINeSCCVisita( NoDeGrupoMaior );

}

void Algoritmo::VerificaINeSCCVisita( int it){

    ListaDeNos[it].estado2 = 'z';

    for (list < int >::iterator it2 = ListaDeNos[it].ListaAdjacentesInversa.begin(); it2 != ListaDeNos[it].ListaAdjacentesInversa.end(); it2++ ){
        if( ListaDeNos[*it2].estado2 == 'b' ){
            VerificaINeSCCVisita( *it2);
        }
    }

    ListaDeNos[it].estado2 = 'p';

    if( ListaDeNos[it].Tipo == 'o'){
        ListaDeNos[it].Tipo = 's';
    }else{
        ListaDeNos[it].Tipo = 'i';
    }

}



void Algoritmo::ClassificaTendrilA( int it){

    ListaDeNos[it].estado2 = 'z';


    for (list < int >::iterator it2 = ListaDeNos[it].ListaVizinhos.begin(); it2 != ListaDeNos[it].ListaVizinhos.end(); it2++ ){
        if( ListaDeNos[*it2].estado2 == 'b' ){
            if( ListaDeNos[*it2].Tipo == 't'){
                ClassificaTendrilA( *it2);
                ListaDeNos[*it2].Tipo = 'a';
            }
        }
    }

    ListaDeNos[it].estado2 = 'p';


}

void Algoritmo::ClassificaTendrilB( int it){

    ListaDeNos[it].estado2 = 'z';


    for (list < int >::iterator it2 = ListaDeNos[it].ListaVizinhos.begin(); it2 != ListaDeNos[it].ListaVizinhos.end(); it2++ ){
        if( ListaDeNos[*it2].estado2 == 'b' ){
            if( ListaDeNos[*it2].Tipo == 't'){
                ClassificaTendrilB( *it2);
                ListaDeNos[*it2].Tipo = 'b';
            }
        }
    }

    ListaDeNos[it].estado2 = 'p';


}

void Algoritmo::ClassificaTendrilC( int it){

    ListaDeNos[it].estado2 = 'z';


    for (list < int >::iterator it2 = ListaDeNos[it].ListaVizinhos.begin(); it2 != ListaDeNos[it].ListaVizinhos.end(); it2++ ){
        if( ListaDeNos[*it2].estado2 == 'b' ){
            if( ListaDeNos[*it2].Tipo == 't'){
                ClassificaTendrilC( *it2);
                ListaDeNos[*it2].Tipo = 'c';
            }
        }
    }

    ListaDeNos[it].estado2 = 'p';


}

void Algoritmo::VerificaViszinhancaINeOut( int it){

    ListaDeNos[it].estado = 'z';


    for (list < int >::iterator it2 = ListaDeNos[it].ListaVizinhos.begin(); it2 != ListaDeNos[it].ListaVizinhos.end(); it2++ ){
        if( ListaDeNos[*it2].estado == 'b' ){
            if( ListaDeNos[*it2].Tipo == 't'){
                VerificaViszinhancaINeOut( *it2);
            }
            if( ListaDeNos[*it2].Tipo == 'i'){
                TemVisinhoIN = 1;
            }
            if( ListaDeNos[*it2].Tipo == 'o'){
                TemVisinhoOUT = 1;
            }
        }
    }

    ListaDeNos[it].estado = 'p';


}

void Algoritmo::IdentificaTipoTendriu(){

    //cout << endl << " Identificando tipo dentril " << endl<< endl;

    for (int i = 1; i <= TamanhoVector; i++ ){
        if( ListaDeNos[i].Tipo == 't'){
            RetornaEstatosDeBuscaEmProfundidade();
            TemVisinhoIN = 0;
            TemVisinhoOUT = 0;
            VerificaViszinhancaINeOut(i);
            //cout << it->NumNo << " VizinhoIN = '" << TemVisinhoIN << "' VizinhoOUT = '" << TemVisinhoOUT << "'" << endl;

            if( (TemVisinhoIN == 1) and (TemVisinhoOUT == 1) ){
                ListaDeNos[i].Tipo = 'c';
                ClassificaTendrilC(i);
            }else{
                if(TemVisinhoOUT == 1){
                    ListaDeNos[i].Tipo = 'b';
                    ClassificaTendrilB(i);
                }else{
                    ListaDeNos[i].Tipo = 'a';
                    ClassificaTendrilA(i);
                }

            }
        }
    }
}



void Algoritmo::ColocaNosEmListaDeTipos(){

    for (int i = 1; i <= TamanhoVector; i++  ){

        if(ListaDeNos[i].Tipo == 's'){
            SCC.push_back (i);
        }
        if(ListaDeNos[i].Tipo == 'i'){
            IN.push_back (i);
        }
        if(ListaDeNos[i].Tipo == 'o'){
            OUT.push_back (i);
        }
        if(ListaDeNos[i].Tipo == 'a'){
            TendrilA.push_back (i);
        }
        if(ListaDeNos[i].Tipo == 'b'){
            TendrilB.push_back (i);
        }
        if(ListaDeNos[i].Tipo == 'c'){
            TendrilC.push_back (i);
        }
        if(ListaDeNos[i].Tipo == 'd'){
            Desconectados.push_back (i);
        }
    }

}

void Algoritmo::ImprimeListaDeTipos(){

    cout << endl << endl << "  Lista SCC = ";
    for (list<int>::iterator it = SCC.begin(); it != SCC.end(); it++ ){
        cout << *it << " ";
    }

    cout << endl << endl << "  Lista IN = ";
    for (list<int>::iterator it = IN.begin(); it != IN.end(); it++ ){
        cout << *it << " ";
    }

    cout << endl << endl << "  Lista OUT = ";
    for (list<int>::iterator it = OUT.begin(); it != OUT.end(); it++ ){
        cout << *it << " ";
    }

    cout << endl << endl << "  Lista TendrilA = ";
    for (list<int>::iterator it = TendrilA.begin(); it != TendrilA.end(); it++ ){
        cout << *it << " ";
    }

    cout << endl << endl << "  Lista TendrilB = ";
    for (list<int>::iterator it = TendrilB.begin(); it != TendrilB.end(); it++ ){
        cout << *it << " ";
    }

    cout << endl << endl << "  Lista TendrilC = ";
    for (list<int>::iterator it = TendrilC.begin(); it != TendrilC.end(); it++ ){
        cout << *it << " ";
    }

    cout << endl << endl << "  Lista Desconectados = ";
    for (list<int>::iterator it = Desconectados.begin(); it != Desconectados.end(); it++ ){
        cout << *it << " ";
    }
    cout << endl;

}


void Algoritmo::OrdenaListaSCC(){

    int Chave;
    list<int>::iterator SegundoElemento;
    list<int>::iterator i;
    list<int>::iterator iAux;

    if( SCC.size() > 1){
        SegundoElemento = SCC.begin();
        SegundoElemento++;


        for ( list<int>::iterator j = SegundoElemento; j != SCC.end(); j++ ){
            Chave = *j;
            i = j;
            i--;
            while( ( i != SCC.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            if( ( i == SCC.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            iAux = i;
            iAux++;
            *iAux = Chave;
        }
    }

}

void Algoritmo::OrdenaListaIN(){

    int Chave;
    list<int>::iterator SegundoElemento;
    list<int>::iterator i;
    list<int>::iterator iAux;

    if( IN.size() > 1){
        SegundoElemento = IN.begin();
        SegundoElemento++;


        for ( list<int>::iterator j = SegundoElemento; j != IN.end(); j++ ){
            Chave = *j;
            i = j;
            i--;
            while( ( i != IN.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            if( ( i == IN.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            iAux = i;
            iAux++;
            *iAux = Chave;
        }
    }

}

void Algoritmo::OrdenaListaOUT(){

    int Chave;
    list<int>::iterator SegundoElemento;
    list<int>::iterator i;
    list<int>::iterator iAux;

    if( OUT.size() > 1){
        SegundoElemento = OUT.begin();
        SegundoElemento++;


        for ( list<int>::iterator j = SegundoElemento; j != OUT.end(); j++ ){
            Chave = *j;
            i = j;
            i--;
            while( ( i != OUT.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            if( ( i == OUT.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            iAux = i;
            iAux++;
            *iAux = Chave;
        }
    }

}

void Algoritmo::OrdenaListaTendrilA(){

    int Chave;
    list<int>::iterator SegundoElemento;
    list<int>::iterator i;
    list<int>::iterator iAux;

    if( TendrilA.size() > 1){
        SegundoElemento = TendrilA.begin();
        SegundoElemento++;


        for ( list<int>::iterator j = SegundoElemento; j != TendrilA.end(); j++ ){
            Chave = *j;
            i = j;
            i--;
            while( ( i != TendrilA.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            if( ( i == TendrilA.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            iAux = i;
            iAux++;
            *iAux = Chave;
        }
    }

}

void Algoritmo::OrdenaListaTendrilB(){

    int Chave;
    list<int>::iterator SegundoElemento;
    list<int>::iterator i;
    list<int>::iterator iAux;

    if( TendrilB.size() > 1){
        SegundoElemento = TendrilB.begin();
        SegundoElemento++;


        for ( list<int>::iterator j = SegundoElemento; j != TendrilB.end(); j++ ){
            Chave = *j;
            i = j;
            i--;
            while( ( i != TendrilB.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            if( ( i == TendrilB.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            iAux = i;
            iAux++;
            *iAux = Chave;
        }
    }

}

void Algoritmo::OrdenaListaTendrilC(){

    int Chave;
    list<int>::iterator SegundoElemento;
    list<int>::iterator i;
    list<int>::iterator iAux;

    if( TendrilC.size() > 1){
        SegundoElemento = TendrilC.begin();
        SegundoElemento++;


        for ( list<int>::iterator j = SegundoElemento; j != TendrilC.end(); j++ ){
            Chave = *j;
            i = j;
            i--;
            while( ( i != TendrilC.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            if( ( i == TendrilC.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            iAux = i;
            iAux++;
            *iAux = Chave;
        }
    }

}

void Algoritmo::OrdenaListaDesconectados(){

    int Chave;
    list<int>::iterator SegundoElemento;
    list<int>::iterator i;
    list<int>::iterator iAux;

    if( Desconectados.size() > 1){
        SegundoElemento = Desconectados.begin();
        SegundoElemento++;


        for ( list<int>::iterator j = SegundoElemento; j != Desconectados.end(); j++ ){
            Chave = *j;
            i = j;
            i--;
            while( ( i != Desconectados.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            if( ( i == Desconectados.begin() ) and  (Chave < *i ) ){
                iAux = i;
                iAux++;
                *iAux = *i;
                i--;
            }
            iAux = i;
            iAux++;
            *iAux = Chave;
        }
    }

}

void Algoritmo::EscreveArquivosDeSaida(){
    ofstream ArquivoDados;

    ArquivoDados.open("scc.txt");
    for (list<int>::iterator it = SCC.begin(); it != SCC.end(); it++ ){
        ArquivoDados << *it << endl;
    }
    ArquivoDados.close();

    ArquivoDados.open("in.txt");
    for (list<int>::iterator it = IN.begin(); it != IN.end(); it++ ){
        ArquivoDados << *it << endl;
    }
    ArquivoDados.close();

    ArquivoDados.open("out.txt");
    for (list<int>::iterator it = OUT.begin(); it != OUT.end(); it++ ){
        ArquivoDados << *it << endl;
    }
    ArquivoDados.close();

    ArquivoDados.open("tendrils_a.txt");
    for (list<int>::iterator it = TendrilA.begin(); it != TendrilA.end(); it++ ){
        ArquivoDados << *it << endl;
    }
    ArquivoDados.close();

    ArquivoDados.open("tendrils_b.txt");
    for (list<int>::iterator it = TendrilB.begin(); it != TendrilB.end(); it++ ){
        ArquivoDados << *it << endl;
    }
    ArquivoDados.close();

    ArquivoDados.open("tendrils_c.txt");
    for (list<int>::iterator it = TendrilC.begin(); it != TendrilC.end(); it++ ){
        ArquivoDados << *it << endl;
    }
    ArquivoDados.close();

    ArquivoDados.open("disconnected.txt");
    for (list<int>::iterator it = Desconectados.begin(); it != Desconectados.end(); it++ ){
        ArquivoDados << *it << endl;
    }
    ArquivoDados.close();

}



Algoritmo::~Algoritmo(){
}


int main(int argc, char **argv){

    if( argc == 2 ){

        char *input;
        input  = argv[1];

        Algoritmo AG;

        //AG.EscreveTXT();
        AG.Ledados(input);

        //AG.ImprimeListaNos();

        AG.DFS1SCC();

        //AG.ImprimeListaNos();

        //AG.ImprimeListaTempoFinaliza();

        //cout << endl << " Ordena Lista de tempos Finais" << endl;

        //AG.OrdenaListaTempoFinaliza();

        //AG.ImprimeListaTempoFinaliza();


        AG.DFS2SCC();

        //AG.ImprimeListaNos();


        AG.ColocaListaDeGrupos();

        //AG.ImprimeListaDeGrupos();


        AG.SelecionaMaiorGrupo();

        //AG.ImprimeMaiorGrupo();

        AG.RetornaEstatosDeBuscaEmProfundidade();

        //AG.ImprimeListaNos();

        AG.VerificaTendril();

        //AG.ImprimeListaNos();

        AG.RetornaEstatosDeBuscaEmProfundidade();

        //AG.ImprimeListaNos();

        AG.VerificaOUT();

        //AG.ImprimeListaNos();

        AG.VerificaINeSCC();

        //AG.ImprimeListaNos();

        AG.IdentificaTipoTendriu();

        //AG.ImprimeListaNos();

        AG.ColocaNosEmListaDeTipos();

        //AG.ImprimeListaDeTipos();

    /*
        AG.OrdenaListaSCC();
        AG.OrdenaListaIN();
        AG.OrdenaListaOUT();
        AG.OrdenaListaTendrilA();
        AG.OrdenaListaTendrilB();
        AG.OrdenaListaTendrilC();
        AG.OrdenaListaDesconectados();
*/
         //AG.ImprimeListaDeTipos();

         AG.EscreveArquivosDeSaida();


        return 1;
    }else{
        cout << endl << endl << " Erro na entrada de dados " << endl << endl;
        return 0;
    }



}

