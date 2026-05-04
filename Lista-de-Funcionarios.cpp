#include <iostream>
#include <string>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <clocale>
using namespace std;

struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
	Funcionario *prox;
};

Funcionario* init()
{
	return NULL;
}

int isEmpty(Funcionario* funcionario)
{
	return (funcionario == NULL);
}


Funcionario* insert(Funcionario* funcionario, int prontuario, string nome, double salario )
{
	Funcionario* novo = new Funcionario();
	novo->prontuario = prontuario;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = funcionario;
	return novo;
}

Funcionario* find(Funcionario* funcionario, int prontuario)
{
	Funcionario* aux;
	aux = funcionario;
	while(aux != NULL && aux->prontuario != prontuario)
	{
		aux = aux->prox;
	}
	return aux;
}

Funcionario* remove(Funcionario* funcionario, int prontuario)
{
	Funcionario* ant = NULL;
	Funcionario* aux;
	aux = funcionario;
	while(aux != NULL && aux->prontuario != prontuario)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		cout << "Usuário não encontrado! " << endl;
		return funcionario;
	}
	if (ant == NULL) 
	{
		funcionario = aux->prox;
	}
	else 
	{
		ant->prox = aux->prox;
	}
	delete aux;

	cout << "Usuário removido! " << endl;

	return funcionario;
}


void print(Funcionario* funcionario)
{
	int soma = 0;
	Funcionario* aux;
	aux = funcionario;
	cout << "-----------" << endl;
	while(aux != NULL)
	{
		soma += aux->salario;
		cout << "Prontuário: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Sálario: " << aux->salario << endl;
		cout << "-----------" << endl;
		aux = aux->prox;
	}
	cout << "Total de sálario: R$" << soma << endl;
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
	Funcionario *minhaLista;
	minhaLista = init();

	int escolha;

	while(true)
	{
		int prontuario;
		string nome;
		double salario;

		while(true)
		{
			string entrada_escolha;
			cout << "----- Menu do Banco de Dados -----" << endl
				 << "Digite: " << endl << "0. Sair" << endl
				 << "1. Incluir" << endl << "2. Excluir" << endl
				 << "3. Pesquisar" << endl << "4. Listar" << endl
				 << "Digite a opção: ";


			getline(cin, entrada_escolha);

			cout << endl;

			if(entrada_escolha.empty())
			{
				cout << "Digite uma opção!" << endl;
				cout << endl;
				continue;
			}

			bool valido = true;

			for(int i = 0; i < entrada_escolha.length(); i++)
			{
				if(!isdigit((unsigned char)entrada_escolha[i]))
				{
					valido = false;
					break;
				}
			}


			if(!valido)
			{
				cout << "Digite apenas números!" << endl;
				cout << endl;
				continue;
			}

			escolha = atoi(entrada_escolha.c_str());

			if(escolha < 0 || escolha > 4)
			{
				cout << "Opção inválida!" << endl;
				cout << endl;
				continue;
			}
			break;

		}


		if(escolha == 0)
		{
			cout << "Encerrando o Programa..." << endl;
			break;
		}

		else if(escolha == 1)
		{
			cout << "----- Inclusão -----" << endl;
			while(true)
			{
				string entrada;
				cout << "Digite o prontuário: ";
				getline(cin, entrada);
				cout << endl;

				if(entrada.empty())
				{
					cout << "Prontuário não pode ser vazio!" << endl;
					cout << endl;
					continue;
				}

				bool valido = true;

				for(int i = 0; i < entrada.length(); i++)
				{
					if(!isdigit((unsigned char)entrada[i]))
					{
						valido = false;
						break;
					}
				}


				if(!valido)
				{
					cout << "Digite apenas números!" << endl;
					cout << endl;
					continue;
				}

				prontuario = atoi(entrada.c_str());

				Funcionario* procurado = find(minhaLista, prontuario);

				if(procurado != NULL)
				{
					cout << "Prontuário já existente!" << endl;
					cout << endl;
					continue;

				}

				break;

			}

			while(true)
			{
				cout << "Digite o nome: ";

				getline(cin, nome);
				cout << endl;

				if(nome.empty())
				{
					cout << "Nome não pode ser vazio!" << endl;
					cout << endl;
					continue;
				}

				bool valido = true;

				for(int i = 0; i < nome.length(); i++)
				{
					if(isdigit((unsigned char)nome[i]))
					{
						valido = false;
						break;
					}
				}

				if(!valido)
				{
					cout << "Nome não pode conter numeros!" << endl;
					cout << endl;
					continue;
				}

				break;
			}

			while(true)
			{
				string entrada;
				cout << "Digite o salario: ";
				getline(cin, entrada);
				cout << endl;
				if(entrada.empty())
				{
					cout << "Salario não pode ser vazio!" << endl << endl;
					continue;
				}

				bool valido = true;
				bool ponto = false;

				for(int i = 0; i < entrada.length(); i++)
				{
					if(entrada[i] == '.' && !ponto)
					{
						ponto = true;
						continue;
					}

					if(!isdigit((unsigned char)entrada[i]))
					{
						valido = false;
						break;
					}
				}

				if(!valido)
				{
					cout << "Digite um sálario válido!" << endl << endl;
					continue;
				}

				salario = atof(entrada.c_str());
				break;

			}

			cout << "Usuário incluido no banco de dados!" << endl;
			minhaLista = insert(minhaLista, prontuario, nome, salario);

		}

		else if(escolha == 2)
		{
			cout << "----- Exclusão -----" << endl;
			while(true)
			{
				int procurar;
				string entrada;
				cout << "Digite o prontuário do funcionário: ";
				getline(cin, entrada);
				cout << endl;

				if(entrada.empty())
				{
					cout << "Prontuário não pode ser vazio!" << endl;
					cout << endl;
					continue;
				}

				bool valido = true;

				for(int i = 0; i < entrada.length(); i++)
				{
					if(!isdigit((unsigned char)entrada[i]))
					{
						valido = false;
						break;
					}
				}


				if(!valido)
				{
					cout << "Digite apenas números!" << endl;
					cout << endl;
					continue;
				}

				procurar = atoi(entrada.c_str());
				Funcionario* procurado = find(minhaLista, procurar);
				if (procurado == NULL)
				{
					cout << "Prontuário não encontrado" << endl;
					break;
				}
				else
				{
					minhaLista = remove(minhaLista, procurar);
					cout << endl;
					break;
				}
			}
		}

		else if(escolha == 3)
		{
			cout << "----- Procurar -----" << endl;
			while(true)
			{
				int procurar;
				string entrada;
				cout << "Digite o prontuário do funcionario: ";
				getline(cin, entrada);
				cout << endl;

				if(entrada.empty())
				{
					cout << "Prontuário não pode ser vazio!" << endl;
					cout << endl;
					continue;
				}

				bool valido = true;

				for(int i = 0; i < entrada.length(); i++)
				{
					if(!isdigit((unsigned char)entrada[i]))
					{
						valido = false;
						break;
					}
				}


				if(!valido)
				{
					cout << "Digite apenas números!" << endl;
					cout << endl;
					continue;
				}

				procurar = atoi(entrada.c_str());
				Funcionario* procurado = find(minhaLista, procurar);

				if (procurado == NULL)
				{
					cout << "Prontuário não encontrado" << endl;
					break;
				}
				else
				{
					cout << "Prontuário pesquisado: "
						 << procurado->prontuario << endl
						 << "Nome: " << procurado->nome << endl
						 << "Sálario: R$ " << procurado->salario << endl;
					cout << endl;
					break;
				}
			}
		}

		else if(escolha == 4 )
		{
			cout << "----- Lista de Funcionários ----- " << endl;
			if(isEmpty(minhaLista) == true)
			{
				cout << "Lista Vazia!" << endl;
				cout << endl;
			}
			else
			{
				print(minhaLista);
			}
		}

		cout << "Pressione qualquer tecla...";
		_getch();
		system("cls");


	}
	return 0;
}
