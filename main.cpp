// LINK PARA VIDEO NO YOUTUBE:
/* OBSERVAÇÕES: Tenho consciência de que o meu programa não
   estará obedecendo a alguns dos critérios que o senhor pediu e
   que isso estará sujeito a descontos da nota, mas ainda assim preferi
   entregar o trabalho. Desculpe qualquer coisa :p

   Como ficaram faltando alguns detalhes na execução do jogo,
   deixei as funções e trecho de código que nao terminei no final
   do código como comentários, para se caso sejam levadas em consideração na hora da correção.

    Obrigado pela atenção! :)
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>

using namespace std;
int pontuacao = 0;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void branco(){
    SetConsoleTextAttribute(hConsole, 15);
}
void azul(){
    SetConsoleTextAttribute(hConsole, 11);
}
void vermelho(){
    SetConsoleTextAttribute(hConsole, 12);
}
void rosa(){
    SetConsoleTextAttribute(hConsole, 13);
}
void amarelo(){
    SetConsoleTextAttribute(hConsole, 14);
}
void verde(){
    SetConsoleTextAttribute(hConsole, 10);
}
void printarPalavraProcurada(char *palavraProcurada,int t){
    cout << endl << "A palavra que eu procuro eh: ";
    rosa();
    for (int i = 0; i < t; i++){
        cout << palavraProcurada[i];
    }
    branco();
    cout<<endl;
    pontuacao++;
}

void marca(char **matriz, char **matrizCopia, int nPalavras){
    char direita[] = {"direita"};
    char esquerda[] = {"esquerda"};
    char cima[] = {"cima"};
    char baixo[] = {"baixo"};
    char diagSupDir[] = {"diagSupDir"};
    char diagSupEsq[] = {"diagSupEsq"};
    char diagInfDir[] = {"diagInfDir"};
    char diagInfEsq[] = {"diagInfEsq"};

    int l, c, t;
    char direcao[15];
    char palavraProcurada[25];
    verde();
    cout << "Digite as coordenadas, o tamanho e a direcao: ";
    branco();
    cin >> l >> c >> t;
    cin >> direcao;
    if (strcmp(direcao,cima) == 0) {
        for (int i = 0; i < t; i++) {
            palavraProcurada[i] = matriz[l-i][c];
            matrizCopia[l-i][c] = matriz[l-i][c];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }
    else if (strcmp(direcao,baixo) == 0) {
        for (int i = 0; i < t; i++){
            palavraProcurada[i] = matriz[l+i][c];
            matrizCopia[l+i][c] = matriz[l+i][c];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }
    else if (strcmp(direcao,direita) == 0) {
        for (int i = 0; i < t; i++){
            palavraProcurada[i] = matriz[l][c+i];
            matrizCopia[l][c+i] = matriz[l][c+i];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }
    else if (strcmp(direcao,esquerda) == 0) {
        for (int i = 0; i < t; i++){
            palavraProcurada[i] = matriz[l][c-i];
            matrizCopia[l][c-i] = matriz[l][c-i];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }
    else if (strcmp(direcao,diagSupDir) == 0) {
        for (int i = 0; i < t; i++){
            palavraProcurada[i] = matriz[l-i][c+i];
            matrizCopia[l-i][c+i] = matriz[l-i][c+i];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }
    else if (strcmp(direcao,diagSupEsq) == 0) {
        for (int i = 0; i < t; i++){
            palavraProcurada[i] = matriz[l-i][c-i];
            matrizCopia[l-i][c-i] = matriz[l-i][c-i];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }
    else if (strcmp(direcao,diagInfDir) == 0) {
        for (int i = 0; i < t; i++){
            palavraProcurada[i] = matriz[l+i][c+i];
            matrizCopia[l+i][c+i] = matriz[l+i][c+i];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }
   else if (strcmp(direcao,diagInfEsq) == 0) {
        for (int i = 0; i < t; i++){
            palavraProcurada[i] = matriz[l+i][c-i];
            matrizCopia[l+i][c-i] = matriz[l+i][c-i];
        }
        printarPalavraProcurada(palavraProcurada,t);
    }else{
        vermelho();
        cout << endl << "Direcao invalida :p" << endl;
        branco();
    }
}
void printacoord(int i){
    if (i>=10){
        if(i>=20){
            cout<<i%20;
        }
        else{
            cout<<i%10;
        }
    }else{
        cout<<i;
    }
}

void printaMatriz(char **matriz, int nLinhas, int nColunas, char **matrizCopia){
    cout << setw(31) << "  ";
    azul();
    for (int i = 0; i < nColunas; i++) {
        printacoord(i);
        cout << " ";
    }
    branco();
    cout << endl;
    for(int i = 0; i < nLinhas; i++){
        azul();
        cout << setw(30);
        printacoord(i);
        cout << " ";
        branco();
        for(int j = 0; j < nColunas; j++){
            if (matriz[i][j] == matrizCopia[i][j]){
                vermelho();
            }
            cout << matriz[i][j] << " ";
            branco();
        }
        azul();
        printacoord(i);
        cout << endl;
        branco();
    }
    cout << setw(31) << "  ";
    azul();
    for (int i = 0; i < nColunas; i++) {
        printacoord(i);
        cout << " ";
    }branco();
    cout << endl;
}

void carrega(){
    branco();
    char nomeArquivo[] = {};
    verde();
    cout << "Digite o nome do arquivo: ";
    branco();
    cin >> nomeArquivo;
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    int nLinhas, nColunas, nPalavras;

    if(arquivo == NULL){
        verde();
        cout << "Arquivo nao encontrado" << endl;
        branco();
    }else{

        fscanf(arquivo, "%d %d %d\n",&nLinhas,&nColunas,&nPalavras);
        // COLUNA NUMERICA HORIZONTAL DA DIREITA
        cout << setw(31) << "  ";
        azul();
        for (int i = 0; i < nColunas; i++) {
            printacoord(i);
            cout << " ";
        }
        branco();
        cout << endl;

        char **matriz = (char**)malloc(nLinhas * sizeof(char*));
        for(int i = 0; i < nLinhas; i++){
            azul();
            cout << setw(30);
            printacoord(i);
            cout << " ";
            branco();
            matriz[i] = (char*)malloc(nColunas * sizeof(char));
            for(int j = 0; j < nColunas; j++){
                matriz[i][j] = fgetc(arquivo);
                cout << matriz[i][j] << " ";
            }
            fgetc(arquivo);
            azul();
            printacoord(i);
            cout << endl;
            branco();
        }
        cout << setw(31) << "  ";
        azul();
        for (int i = 0; i < nColunas; i++) {
            printacoord(i);
            cout << " ";                    //
        }
        branco();
        cout << endl;

        char **matrizCopia = (char**)malloc(nLinhas*sizeof(char*));     // MATRIZ COPIA
        for (int i = 0; i < nLinhas; i++) {
            matrizCopia[i] = (char*)malloc(nColunas*sizeof(char));
        }
        verde();
        cout << "Numero de Palavras: ";
        rosa();
        cout << nPalavras << endl;
        verde();
        cout << "Vamos marcar palavras agora!" << endl;
        branco();

        char escolha[4];
        char sim[] = {"sim"};
        char nao[] = {"nao"};
        do{
            if (pontuacao==nPalavras){
                amarelo();
                cout << "PARABENS!!!! VC ENCONTROU TODAS AS PALAVRAS!!!!" << endl;
                branco();
                break;
            }
            verde();
            cout << "Quer marcar mesmo? ";
            branco();
            cin >> escolha;

            if (strcmp(escolha,sim) == 0){
                marca(matriz, matrizCopia, nPalavras);
                cout << endl;
                printaMatriz(matriz,nLinhas,nColunas, matrizCopia);
                cout<<endl;
            }
        } while((strcmp(escolha,nao) != 0));
    free(matriz);
    free(matrizCopia);
    }

    fclose(arquivo);
}

int main(){
    amarelo();
    cout << setw(50) << "******BEM VINDO!******"<<endl;
    branco();
    int comando;
    do{
        verde();
        cout << "1 - carrega" << endl;
        cout << "2 - sair" << endl;
        cout << "Digite um comando: ";
        branco();
        cin >> comando;
        switch(comando){
            case 1:
                carrega();
                break;
        }
    }while(comando != 2);
    azul();
    cout << endl << "Pontuacao: " << pontuacao << endl;
    cout << "Obrigado por jogar! :)" << endl;
    branco();

}
/* FUNÇÕES E CÓDIGOS PENDENTES:

PARA IMPRIMIR AS PALAVRAS QUE O JOGADOR DEVERIA ACHAR:
void imprimePalavrasQueFaltam(int nPalavras, char **palavrasAchar){
    cout << "Palavras a serem encontradas: " << endl;
    for (int i = 0; i < nPalavras; i++){
        cout << "- " << palavrasAchar[i] << endl;
    }
    cout << endl;


PARA ALOCAR A MATRIZ QUE IRIA CONTER AS PALAVRAS A SEREM ACHADAS:
    char **palavrasAchar = (char**)malloc(nPalavras*sizeof(char*));
    for (int i = 0; i < nPalavras; i++) {
        palavrasAchar[i] = (char*)malloc(15*sizeof(char));
        for (int j = 0; j < coluna; j++){
            palavrasAchar[i][j] = fgetc(arquivo);
        }
    }
}

PARA VERIFICAR SE A PALAVRA QUE O JOGADOR QUERIA MARCAR ESTÁ NA MATRIZ
bool estaNaMatriz(int t, int c, int l, int nLinhas, int nColunas){
    return ((t + l <= nLinhas) && (t + c <= nColunas) &&
            (t + sqrt(pow(l,2)+ pow(c,2)) <= sqrt(pow(nColunas,2) + pow(nLinhas,2)))); // <- A PALAVRA TMB TEM QUE SER MENOR QUE A DIAGONAL
}
*/
