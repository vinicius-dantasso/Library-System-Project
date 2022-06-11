#include "biblioteca.h"

int main() {
	setlocale(LC_ALL, "Portuguese"); // Mostrar os acentos no prompt
	const float taxa = 0.80;
	int size;

	cout << "Qual o número de devoluções para hoje? ";
	cin >> size;

	Data devolucao;
	Dados* returns = new Dados[size]; //Vetor dinâmico para guardar as informações inseridas

	cout << "Digite a data de hoje: ";
	cin >> devolucao;
	const int saveMonth = devolucao.mes; //Variável feita para facilitar quando for mostrar a data no resumo mais adiante
	
	Linhas('-', 42); //Função linhas que faz as divisórias
	
	int cont = 0;
	int atraso;
	float multaTotal = 0.0;

	for (int i = 0; i < size; i++) {
		
		cout << "Aluno"; cout << right; cout.width(7); cout.fill(' '); cout << ": ";
		cin >> returns[i].matricula;

		cout << "Livro"; cout << right; cout.width(7); cout.fill(' '); cout << ": ";
		cin >> returns[i].identificar;

		cout << "Empréstimo: ";
		cin >> returns[i].emprestimo;

		atraso = returns[i].emprestimo - devolucao; //Variável para guardar a diferença entre as datas
		cout << "Atraso"; cout << right; cout.width(6); cout.fill(' '); cout << ": ";
		cout << atraso << " dia(s)" << endl;

		returns[i].multa = atraso * taxa;
		cout << fixed;
		cout.precision(2);
		cout << "Multa"; cout << right; cout.width(7); cout.fill(' '); cout << ": ";
		cout << "R$" << returns[i].multa << endl;

		multaTotal += TotalMultas(returns[i].emprestimo, size, devolucao);

		while (cont < (size - 1)) { //Laço para fazer as divisórias menores não aparecerem na última entrada
			Linhas('-', 35);
			cont++;
			break;
		}
	}

	Linhas('-', 42);
	
	Meses* month = new Meses[13]; //Vetor Dinâmico para guardar o nome dos meses em registro Meses
	strcpy_s(month[1].mes, "janeiro");
	strcpy_s(month[2].mes, "fevereiro");
	strcpy_s(month[3].mes, "março");
	strcpy_s(month[4].mes, "abril");
	strcpy_s(month[5].mes, "maio");
	strcpy_s(month[6].mes, "junho");
	strcpy_s(month[7].mes, "julho");
	strcpy_s(month[8].mes, "agosto");
	strcpy_s(month[9].mes, "setembro");
	strcpy_s(month[10].mes, "outubro");
	strcpy_s(month[11].mes, "novembro");
	strcpy_s(month[12].mes, "dezembro");
	
	cout << "Resumo do dia " << devolucao.dia;
	cout << " de " << month[saveMonth].mes;
	cout << " de " << devolucao.ano;
	cout << "\n\n";

	for (int j = 0; j < size; j++) {
		Resumo(&returns[j], &returns[j].emprestimo);
	}
	
	cout << "\n";
	cout << "Total em multas: " << "R$" << multaTotal << endl;

	Linhas('-', 42);

	cout << "\n";
	cout << "Encerrando programa...\n";

	delete[] returns;
	delete[] month;
}