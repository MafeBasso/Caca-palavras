#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PRETO "\x1b[;30m"
#define VERMELHO "\x1b[;31m"
#define VERDE "\x1b[;32m"
#define AMARELO "\x1b[;33m"
#define AZUL "\x1b[;34m"
#define MAGENTA "\x1b[;35m"
#define CIANO "\x1b[;36m"
#define BRANCO "\x1b[;37m"

using namespace std;

int lin, col, qtdPalavras, k = 0, compLinha, compColuna, compTamanho, comparar = 0, comparar1 = 0, comparar2 = 0;
char **matriz = (char**)malloc(lin * sizeof(char*));
int *vetorNovo = (int*)malloc(qtdPalavras * sizeof(int));
char vetorPalavras[40];
char *vetorMarca = (char*) malloc(sizeof(char)*compTamanho);

void carrega(){
    char nomeArquivo[] = {};
    cout << VERDE << "Digite o nome do arquivo: ";
    cin >> nomeArquivo;
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");

    if(arquivo == NULL){
        cout << VERMELHO << "Arquivo nao encontrado" << endl;
    }else{
        fscanf(arquivo, "%d %d %d\n",&lin,&col,&qtdPalavras);
        int b = 0, c = 0;
        for(int i = 0; i < lin; i++){
            matriz[i] = (char*)malloc(col * sizeof(char));
            if (i == 0) {
                for (int a = 0; a < col; a++) {
                    if (a == 0) {
                        cout << " ";
                    }
                    cout << " " << AMARELO << a;
                    if (a == col-1) {
                        cout << endl;
                    }
                }
            }
            for(int j = 0; j < col; j++){
                matriz[i][j] = fgetc(arquivo);
                if (j == 0) {
                    cout << AMARELO << b << " ";
                    b++;
                }
                cout << matriz[i][j] << " ";
                if (j == col-1) {
                    cout << AMARELO << c;
                    c++;
                }
                if (i == lin-1 && j == col-1) {
                    for (int a = 0; a < col; a++) {
                        if (a == 0) {
                            cout << endl << " ";
                        }
                        cout << " " << AMARELO << a;
                    }
                }
            }
            fgetc(arquivo);
            cout << endl;
        }
        int l = 0;
        cout << AZUL << "Encontre as palavras a seguir:" << endl;
        while (vetorPalavras[k] = fgetc(arquivo)) {
            cout << AZUL << vetorPalavras[k];
            if (vetorPalavras[k] == '\n') {
                l++;
                if (l == qtdPalavras) {
                    break;
                }
            }
            k++;
        }
        fclose(arquivo);
        int aux = 0, x=0;
        for (int i=0; i <= k; i++) {
            if (vetorPalavras[i] == '\n') {
                vetorNovo[x] = aux;
                x = x+1;
                aux = 0;
            } else {
                aux = aux+1;
            }
        }
    }
    return;
}

void imprimirColorido() {
    int b = 0, c = 0, m = 0;
    if (comparar == 1) {
        for(int i = 0; i < lin; i++){
            if (i == 0) {
                for (int a = 0; a < col; a++) {
                    if (a == 0) {
                        cout << " ";
                    }
                    cout << " " << AMARELO << a;
                    if (a == col-1) {
                        cout << endl;
                    }
                }
            }
            for(int j = 0; j < col; j++){
                if (j == 0) {
                    cout << AMARELO << b << " ";
                    b++;
                }
                if (i == compLinha && j == compColuna+m) {
                    cout << VERMELHO << matriz[compLinha][compColuna+m] << " ";
                    m++;
                } else {
                    cout << matriz[i][j] << " ";
                }
                if (j == col-1) {
                    cout << AMARELO << c;
                    c++;
                }
                if (i == lin-1 && j == col-1) {
                    for (int a = 0; a < col; a++) {
                        if (a == 0) {
                            cout << endl << " ";
                        }
                        cout << " " << AMARELO << a;
                    }
                }
            }
            cout << endl;
        }
    } else if (comparar == 2) {
        for(int i = 0; i < lin; i++){
            if (i == 0) {
                for (int a = 0; a < col; a++) {
                    if (a == 0) {
                        cout << " ";
                    }
                    cout << " " << AMARELO << a;
                    if (a == col-1) {
                        cout << endl;
                    }
                }
            }
            for(int j = 0; j < col; j++){
                if (j == 0) {
                    cout << AMARELO << b << " ";
                    b++;
                }
                if (i == compLinha && j == compColuna-m) {
                    cout << VERMELHO << matriz[compLinha][compColuna-m] << " ";
                    m++;
                } else {
                    cout << matriz[i][j] << " ";
                }
                if (j == col-1) {
                    cout << AMARELO << c;
                    c++;
                }
                if (i == lin-1 && j == col-1) {
                    for (int a = 0; a < col; a++) {
                        if (a == 0) {
                            cout << endl << " ";
                        }
                        cout << " " << AMARELO << a;
                    }
                }
            }
            cout << endl;
        }
    } else if (comparar == 3) {
        for(int i = 0; i < lin; i++){
            if (i == 0) {
                for (int a = 0; a < col; a++) {
                    if (a == 0) {
                        cout << " ";
                    }
                    cout << " " << AMARELO << a;
                    if (a == col-1) {
                        cout << endl;
                    }
                }
            }
            for(int j = 0; j < col; j++){
                if (j == 0) {
                    cout << AMARELO << b << " ";
                    b++;
                }
                if (i == compLinha+m && j == compColuna) {
                    cout << VERMELHO << matriz[compLinha+m][compColuna] << " ";
                    m++;
                } else {
                    cout << matriz[i][j] << " ";
                }
                if (j == col-1) {
                    cout << AMARELO << c;
                    c++;
                }
                if (i == lin-1 && j == col-1) {
                    for (int a = 0; a < col; a++) {
                        if (a == 0) {
                            cout << endl << " ";
                        }
                        cout << " " << AMARELO << a;
                    }
                }
            }
            cout << endl;
        }
    } else if (comparar == 4) {
        for(int i = 0; i < lin; i++){
            if (i == 0) {
                for (int a = 0; a < col; a++) {
                    if (a == 0) {
                        cout << " ";
                    }
                    cout << " " << AMARELO << a;
                    if (a == col-1) {
                        cout << endl;
                    }
                }
            }
            for(int j = 0; j < col; j++){
                if (j == 0) {
                    cout << AMARELO << b << " ";
                    b++;
                }
                if (i == compLinha-m && j == compColuna) {
                    cout << VERMELHO << matriz[compLinha-m][compColuna] << " ";
                    m++;
                } else {
                    cout << matriz[i][j] << " ";
                }
                if (j == col-1) {
                    cout << AMARELO << c;
                    c++;
                }
                if (i == lin-1 && j == col-1) {
                    for (int a = 0; a < col; a++) {
                        if (a == 0) {
                            cout << endl << " ";
                        }
                        cout << " " << AMARELO << a;
                    }
                }
            }
            cout << endl;
        }
    } else if (comparar == 5) {
        if (comparar1 == 1 && comparar2 == 3) {
            for(int i = 0; i < lin; i++){
                if (i == 0) {
                    for (int a = 0; a < col; a++) {
                        if (a == 0) {
                            cout << " ";
                        }
                        cout << " " << AMARELO << a;
                        if (a == col-1) {
                            cout << endl;
                        }
                    }
                }
                for(int j = 0; j < col; j++){
                    if (j == 0) {
                        cout << AMARELO << b << " ";
                        b++;
                    }
                    if (i == compLinha+m && j == compColuna+m) {
                        cout << VERMELHO << matriz[compLinha+m][compColuna+m] << " ";
                        m++;
                    } else {
                        cout << matriz[i][j] << " ";
                    }
                    if (j == col-1) {
                        cout << AMARELO << c;
                        c++;
                    }
                    if (i == lin-1 && j == col-1) {
                        for (int a = 0; a < col; a++) {
                            if (a == 0) {
                                cout << endl << " ";
                            }
                            cout << " " << AMARELO << a;
                        }
                    }
                }
                cout << endl;
            }
        } else if (comparar1 == 1 && comparar2 == 4) {
            for(int i = 0; i < lin; i++){
                    if (i == 0) {
                        for (int a = 0; a < col; a++) {
                            if (a == 0) {
                                cout << " ";
                            }
                            cout << " " << AMARELO << a;
                            if (a == col-1) {
                                cout << endl;
                            }
                        }
                    }
                    for(int j = 0; j < col; j++){
                        if (j == 0) {
                            cout << AMARELO << b << " ";
                            b++;
                        }
                        if (i == compLinha-m && j == compColuna+m) {
                            cout << VERMELHO << matriz[compLinha-m][compColuna+m] << " ";
                            m++;
                        } else {
                            cout << matriz[i][j] << " ";
                        }
                        if (j == col-1) {
                            cout << AMARELO << c;
                            c++;
                        }
                        if (i == lin-1 && j == col-1) {
                            for (int a = 0; a < col; a++) {
                                if (a == 0) {
                                    cout << endl << " ";
                                }
                                cout << " " << AMARELO << a;
                            }
                        }
                    }
                    cout << endl;
                }
        } else if (comparar1 == 2 && comparar2 == 3) {
            for(int i = 0; i < lin; i++){
                    if (i == 0) {
                        for (int a = 0; a < col; a++) {
                            if (a == 0) {
                                cout << " ";
                            }
                            cout << " " << AMARELO << a;
                            if (a == col-1) {
                                cout << endl;
                            }
                        }
                    }
                    for(int j = 0; j < col; j++){
                        if (j == 0) {
                            cout << AMARELO << b << " ";
                            b++;
                        }
                         if (i == compLinha+m && j == compColuna-m) {
                            cout << VERMELHO << matriz[compLinha+m][compColuna-m] << " ";
                            m++;
                        } else {
                            cout << matriz[i][j] << " ";
                        }
                        if (j == col-1) {
                            cout << AMARELO << c;
                            c++;
                        }
                        if (i == lin-1 && j == col-1) {
                            for (int a = 0; a < col; a++) {
                                if (a == 0) {
                                    cout << endl << " ";
                                }
                                cout << " " << AMARELO << a;
                            }
                        }
                    }
                    cout << endl;
                }
        } else if (comparar1 == 2 && comparar2 == 4) {
            for(int i = 0; i < lin; i++){
                if (i == 0) {
                    for (int a = 0; a < col; a++) {
                        if (a == 0) {
                            cout << " ";
                        }
                        cout << " " << AMARELO << a;
                        if (a == col-1) {
                            cout << endl;
                        }
                    }
                }
                for(int j = 0; j < col; j++){
                    if (j == 0) {
                        cout << AMARELO << b << " ";
                        b++;
                    }
                        if (i == compLinha-m && j == compColuna-m) {
                        cout << VERMELHO << matriz[compLinha-m][compColuna-m] << " ";
                        m++;
                    } else {
                        cout << matriz[i][j] << " ";
                    }
                    if (j == col-1) {
                        cout << AMARELO << c;
                        c++;
                    }
                    if (i == lin-1 && j == col-1) {
                        for (int a = 0; a < col; a++) {
                            if (a == 0) {
                                cout << endl << " ";
                            }
                            cout << " " << AMARELO << a;
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    if (k == 1) {
        cout << AZUL << "Parabens! Voce completou o caca palavras!" << endl;
        cout << VERMELHO << "Carregue o proximo ou feche o programa" << endl;
    } else {
        cout << AZUL << "Faltam essa(s) palavra(s): " << endl;
        for (int y = 0; y <= k; y++) {
            cout << AZUL << vetorPalavras[y];
        }
    }
}

void marca(){
    char dir[] = {}, dirDiagonal1[] = {}, dirDiagonal2[] = {};
    cout << "Indique a direcao, as coordenadas e o tamanho da palavra: ";
    cin >> dir;
    if (strcmp(dir,"direita")==0){
        comparar = 1;
    } else if (strcmp(dir,"esquerda")==0){
        comparar = 2;
    } else if (strcmp(dir,"baixo")==0){
        comparar = 3;
    } else if (strcmp(dir,"cima")==0){
        comparar = 4;
    } else if (strcmp(dir,"diagonal")==0){
        comparar = 5;
    }
    if (comparar == 5){
        cin >> dirDiagonal1 >> dirDiagonal2 >> compLinha >> compColuna >> compTamanho;
        if (strcmp(dirDiagonal1,"direita")==0){
            comparar1 = 1;
        } else if (strcmp(dirDiagonal1,"esquerda")==0) {
            comparar1 = 2;
        }
        if (strcmp(dirDiagonal1,"baixo")==0) {
            comparar2 = 3;
        } else if (strcmp(dirDiagonal1,"cima")==0) {
            comparar2 = 4;
        }
    } else {
        cin >> compLinha >> compColuna >> compTamanho;
    }
    if (comparar == 1) {
        for (int m = 0; m < compTamanho; m++) {
            vetorMarca[m] = matriz[compLinha][compColuna+m];
        }
    } else if (comparar == 2) {
        for (int m = 0; m < compTamanho; m++) {
            vetorMarca[m] = matriz[compLinha][compColuna-m];
        }
    } else if (comparar == 3) {
        for (int m = 0; m < compTamanho; m++) {
            vetorMarca[m] = matriz[compLinha+m][compColuna];
        }
    } else if (comparar == 4) {
        for (int m = 0; m < compTamanho; m++) {
            vetorMarca[m] = matriz[compLinha-m][compColuna];
        }
    } else if (comparar == 5) {
        if (comparar1 == 1 && comparar2 == 3) {
            for (int m = 0; m < compTamanho; m++) {
                vetorMarca[m] = matriz[compLinha+m][compColuna+m];
            }
        } else if (comparar1 == 1 && comparar2 == 4) {
            for (int m = 0; m < compTamanho; m++) {
                vetorMarca[m] = matriz[compLinha-m][compColuna+m];
            }
        } else if (comparar1 == 2 && comparar2 == 3) {
            for (int m = 0; m < compTamanho; m++) {
                vetorMarca[m] = matriz[compLinha+m][compColuna-m];
            }
        } else if (comparar1 == 2 && comparar2 == 4) {
            for (int m = 0; m < compTamanho; m++) {
                vetorMarca[m] = matriz[compLinha-m][compColuna-m];
            }
        }
    }
    int f = 0, d = 0, x = 0;
    if (compTamanho == vetorNovo[x]){
        for (int u=0; u<=k; u++){
            if (vetorPalavras[u+f] == '\n') {
                f = f + u + 1;
                d = 0;
                u = 0;
            }
            if (u+f >= k) {
                cout << VERDE << "Voce errou" << endl;
                break;
            }
            if (vetorPalavras[u+f] == vetorMarca[u]) {
                d++;
            }
            if (compTamanho == d) {
                cout << VERDE << "Voce acertou!" << endl;
                for (int i = 0; i < k; i++) {
                    vetorPalavras[u+f-d+1+i] = vetorPalavras[u+f+2+i];
                }
                k = k - d;
                imprimirColorido();
                return;
            }
        }
        x = x+1;
    } else {
        x = x - 1;
        cout << VERDE << "Voce errou" << endl;
    }
    if (k == 1) {
        cout << AZUL << "Voce ja completou o caca palavras!" << endl;
        cout << VERMELHO << "Carregue o proximo ou feche o programa" << endl;
    } else {
        cout << AZUL << "Faltam essa(s) palavra(s): " << endl;
        for (int y = 0; y <= k; y++) {
            cout << AZUL << vetorPalavras[y];
        }
    }
    return;
}

int main(){
    char comando[] = {};
    int resposta = 0;
    do{
        cout << "Insira seu comando: ";
        cin >> comando;
        if (strcmp(comando,"carrega")==0) {
            resposta = 1;
        } else if (strcmp(comando,"marca")==0) {
            resposta = 2;
        } else if (strcmp(comando,"fecha")==0) {
            resposta = 3;
        }
        switch(resposta){
        case 1:
            free(matriz);
            free(vetorNovo);
            free(vetorMarca);
            carrega();
            break;
        case 2:
            marca();
            break;
        case 3:
            free(matriz);
            free(vetorNovo);
            free(vetorMarca);
            return 0;
        default:
            cout << VERMELHO << "Digite um comando valido" << endl;
        }
    }while(resposta != 0);
}
