#include "biblioteca.h"

void Linhas(char a, int b) {
	for (int i = 0; i < b; i++) {
		cout << a;
	}
	cout << "\n";
}

istream& operator>>(istream& is, Data& value1) { //Facilitar a entrada de datas no cin
	is >> value1.dia
		>> value1.barra
		>> value1.mes
		>> value1.barra
		>> value1.ano;
	return is;
}

ostream& operator<<(ostream& os, Data& show) { //Facilitar a saída de datas no cout
	os.width(2); os.fill('0');
	os << show.dia;
	os << "/";
	os.width(2); os.fill('0');
	os << show.mes;
	os << "/";
	os << show.ano;
	return os;
}

int operator-(Data c, Data d) { //Calcular a diferença de dias entre as dias convertendo tudo em dias
	int diasAtraso = 0;
	int meses[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (c.mes != d.mes) {
		for (int i = c.mes; i < d.mes; i++) {
			diasAtraso += meses[i];
		}
		diasAtraso += d.dia - c.dia - 3;
		break;
	}
	
	while (c.mes == d.mes) {
		diasAtraso = d.dia - c.dia - 3;
		break;
	}
	while (diasAtraso == 1) {
		return diasAtraso;
	}
	while (diasAtraso == 2) {
		return diasAtraso;
	}
	while (diasAtraso < 3) {
		return diasAtraso = 0;
	}
	return diasAtraso;
}

float TotalMultas(Data emprestimo, int size, Data devolucao) { // Faz o somatório das multas
	const float tax = 0.8;
	int delay;
	float totalCharged = 0.0;

	delay = emprestimo - devolucao;
	totalCharged = (delay * tax) + totalCharged;

	return totalCharged;
}

void Resumo(Dados * emprestimo, Data * datas) { //Faz o resumo, mostrando todos os dados antes inseridos e recebidos
	cout << emprestimo->matricula << " "
		<< emprestimo->identificar << " ";
	cout << *datas;
	cout << " -> R$";
	cout << emprestimo->multa << endl;
}