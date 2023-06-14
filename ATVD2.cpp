#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Time {
string nome;
int jogos, pontos, vitorias, empates, derrotas;
int golsPro, golsContra, saldo;
double aproveitamento;
Time() {
    nome = "";
    jogos = pontos = vitorias = empates = derrotas = 0;
    golsPro = golsContra = saldo = 0;
    aproveitamento = 0.0;
}

Time(string _nome) {
    nome = _nome;
    jogos = pontos = vitorias = empates = derrotas = 0;
    golsPro = golsContra = saldo = 0;
    aproveitamento = 0.0;
}

void computarJogo(int _golsPro, int _golsContra) {
    jogos++;
    if (_golsPro > _golsContra) {
        vitorias++;
        pontos += 3;
    } else if (_golsPro == _golsContra) {
        empates++;
        pontos += 1;
    } else {
        derrotas++;
    }
    golsPro += _golsPro;
    golsContra += _golsContra;
    saldo = golsPro - golsContra;
    aproveitamento = (pontos / (jogos * 3.0)) * 100.0;
}

void imprimirTime() {
    cout << nome << "\t" << jogos << "\t" << pontos << "\t" << vitorias << "\t"
         << empates << "\t" << derrotas << "\t" << saldo << "\t" << golsPro << "\t"
         << golsContra << "\t" << aproveitamento << endl;
}
};

void bubbleSort(Time times[]) {
Time time2;
cout << "\nTabela ordenada com bubbleSort\n";
cout << "Nome\tJogo\tPontos\tVitorias\tEmpates\tDerrotas\tSaldo\tGolsPRO\tGolsContra\tAproveitamento\n";

for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
        if (times[i].pontos > times[j].pontos) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        } else if (times[i].pontos == times[j].pontos && times[i].vitorias > times[j].vitorias) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        } else if (times[i].pontos == times[j].pontos && times[i].vitorias == times[j].vitorias &&
                   times[i].saldo > times[j].saldo) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        } else if (times[i].pontos == times[j].pontos && times[i].vitorias == times[j].vitorias &&
                   times[i].saldo == times[j].saldo && times[i].golsPro > times[j].golsPro) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        }
    }
}
void selectionSort(Time times[]) {
Time time2;
cout << "\nTabela ordenada com selectionSort\n";
cout << "Nome\tJogo\tPontos\tVitorias\tEmpates\tDerrotas\tSaldo\tGolsPRO\tGolsContra\tAproveitamento\n";

for (int i = 0; i < 12; i++) {
    for (int j = i + 1; j < 12; j++) {
        if (times[i].pontos < times[j].pontos) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        } else if (times[i].pontos == times[j].pontos && times[i].vitorias < times[j].vitorias) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        } else if (times[i].pontos == times[j].pontos && times[i].vitorias == times[j].vitorias &&
                   times[i].saldo < times[j].saldo) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        } else if (times[i].pontos == times[j].pontos && times[i].vitorias == times[j].vitorias &&
                   times[i].saldo == times[j].saldo && times[i].golsPro < times[j].golsPro) {
            time2 = times[i];
            times[i] = times[j];
            times[j] = time2;
        }
    }
}
}

bool troca(Time times, Time time2) {
if (times.pontos < time2.pontos) {
return true;
} else if (times.pontos == time2.pontos && times.vitorias < time2.vitorias) {
return true;
} else if (times.pontos == time2.pontos && times.vitorias == time2.vitorias && times.saldo < time2.saldo) {
return true;
} else if (times.pontos == time2.pontos && times.vitorias == time2.vitorias && times.saldo == time2.saldo &&
times.golsPro < time2.golsPro) {
return true;
}
return false;
}

void insertionSort(Time times[]) {
Time time2;
int i, j;
cout << "\nTabela ordenada com insertionsort\n";
cout << "Nome\tJogo\tPontos\tVitorias\tEmpates\tDerrotas\tSaldo\tGolsPRO\tGolsContra\tAproveitamento\n";

for (i = 1; i < 12; i++) {
    time2 = times[i];
    for (j = i - 1; j >= 0 && troca(times[j], time2) == true; j--) {
        times[j + 1] = times[j];
    }
    times[j + 1] = time2;
}
}

int main() {
Time times[12];
string t1, t2;
int r1, r2, ultimo_id = -1;
ifstream file("dados.txt");

while (file >> t1 >> r1 >> r2 >> t2) {
    int i1 = -1, i2 = -1;
    for (int i = 0; i <= ultimo_id; i++) {
        if (times[i].nome == t1) {
            i1 = i;
        }
        if (times[i].nome == t2) {
            i2 = i;
        }
    }
    if (i1 == -1) {
        ultimo_id++;
        times[ultimo_id].nome = t1;
        i1 = ultimo_id;
    }
    if (i2 == -1) {
        ultimo_id++;
        times[ultimo_id].nome = t2;
        i2 = ultimo_id;
    }
    times[i1].computarJogo(r1, r2);
    times[i2].computarJogo(r2, r1);
}

for (int i = 0; i <= ultimo_id; i++) {
    times[i].imprimirTime();
}

int numero;
cout << "\nDigite uma das opcoes:\n";
cout << "1 - Bubble Sort\n";
cout << "2 - Selection Sort\n";
cout << "3 - Insertion Sort\n";
cin >> numero;

switch (numero) {
    case 1:
        bubbleSort(times);
        for (int i = 0; i < 12; i++) {
            times[i].imprimirTime();
        }
        break;

    case 2:
        selectionSort(times);
        for (int i = 0; i < 12; i++) {
            times[i].imprimirTime();
        }
        break;

    case 3:
        insertionsort(times);
        for (int i = 0; i < 12; i++) {
            times[i].imprimirTime();
        }
        break;

    default:
        cout << "Opcao invalida!\n";
        return 0;
}

return 0;
}