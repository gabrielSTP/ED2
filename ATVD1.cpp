#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

#define MAX_NOMES 1000

using namespace std;

int encontrar_nome(char nomes[MAX_NOMES][30], int n, char prefixo[30]) {
int esquerda = 0, direita = n - 1, meio;
while (esquerda <= direita) {
meio = (esquerda + direita) / 2;
if (strncmp(nomes[meio], prefixo, strlen(prefixo)) >= 0) {
direita = meio - 1;
} else {
esquerda = meio + 1;
}
}
return esquerda;
}

void buscar_nomes(char nomes[MAX_NOMES][30], int n, char prefixo[30]) {
int indice = encontrar_nome(nomes, n, prefixo);
for (int i = indice; i < n && strncmp(nomes[i], prefixo, strlen(prefixo)) == 0; i++) {
cout << nomes[i] << endl;
}
}

int main() {
char nomes[MAX_NOMES][30];
char prefixo[30];
int n = 0;
ifstream arquivo("nomes.txt");
if (!arquivo) {
    cout << "Não foi possível abrir o arquivo." << endl;
    return 1;
}

char linha[30];
while (arquivo.getline(linha, 30)) {
    linha[strcspn(linha, "\n")] = '\0';
    strlwr(linha);
    strcpy(nomes[n++], linha);
}

arquivo.close();

cout << "Digite o prefixo: ";
cin >> prefixo;
strlwr(prefixo);

buscar_nomes(nomes, n, prefixo);

return 0;
}

