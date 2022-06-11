#include <iostream>
using namespace std;

struct Data {
	int dia;
	int mes;
	int ano;
	char barra;
};


struct Dados {
	Data emprestimo;
	int matricula;
	char identificar[5];
	float multa;
};


struct Meses {
	char mes[20];
};


void Linhas(char a, int b);

istream& operator>>(istream& is, Data& value1);

ostream& operator<<(ostream& os, Dados& show);

int operator-(Data c, Data d);

float TotalMultas(Data emprestimo, int size, Data devolucao);

void Resumo(Dados * emprestimo, Data * devolucao);
