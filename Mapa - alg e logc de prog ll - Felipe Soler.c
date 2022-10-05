//ALUNO: FELIPE CAPPI SOLER
//MAPA ALGORITMOS E LÓGICA DE PROGRAMAÇÃO II

//INCLUSÃO DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
//DEFINIÇÃO DE CONSTANTE
#define TAM 5
//LANÇAMENTO DO STRUCT CLIENTE COM OS DADOS SOLICITADO
struct cliente
{
	int codigo;
	unsigned char nome[50], tel[50], email[50];
};
//INICIO DO PROGRAMA PRINCIPAL
int main()
{
setlocale(LC_ALL, "Portuguese");
//LANÇAMENTO DAS VARIAVEIS
struct cliente ficha[20];
char res;
int i, j, op;
//INICIALIZAÇÃO DE ALGUMAS VARIAVEIS
i=1;
//LANÇAMENTO DO MENU PRINCIPAL
while (op !=0)
	{
	printf("ESCOLHA UMA OPÇÃO:\n");
	printf("1 - Cadastrar clientes\n");
	printf("2 - Mostrar dados dos clientes cadastrados\n");
	printf("0 - Finalizar programa\n");
	scanf("%d", &op);
	fflush(stdin);
	
//VERIFICAÇÃO DO LANÇAMENTO DE NÚMEROS
//VERIFICAÇÃO DA ESCOLHA CERTA DAS OPÇÕES
if (isdigit(op) || op!=1 && op!=2 && op!=0)
{
	system("cls");
	printf("\nERRO: OPÇÃO INVÁLIDA!\n");
	system ("pause");
	system ("cls");
}
//INICIO DAS CONFIGURAÇÕES DA OP 1 DO MENU
if (op == 1)
{
system("cls");
	//LIMITAÇÃO A 5 LANÇAMENTOS
	if(i<=TAM)
	{
		do
		{	
	//MENSAGENS PARA ENTRADA DE DADOS NO PROGRAMA
			fflush(stdin);
			printf("Digite o nome do cliente: \n");
			fgets(ficha[i].nome, 50, stdin);
			fflush(stdin);
			printf("\nDigite o telefone do cliente: \n");
			fgets(ficha[i].tel, 50, stdin);
			fflush(stdin);
			printf("\nDigite o email do cliente: \n");
			fgets(ficha[i].email, 50, stdin);
			fflush(stdin);
			//CONTADOR VINCULADO AO CÓDIGO DO CLIENTE
			ficha[i].codigo=i;
			//CONTADOR J LANÇADO PARA SUA UTILIZAÇÃO NO FUTURO "FOR"
			j=i;
			//CONTADOR I=I+1
			i++;
				//LIMITAÇÃO EM 5 LANÇAMENTO APÓS O QUINTO
				if (i==6)
				{
					printf("\n\nClientes salvos\n\nAgenda lotada!\n\nLimite de 5 clientes\n\n ");
					system ("pause");
					system ("cls");	
				}
				else
				{
					//MENSAGEM SOLICITANDO A NECESSIDADE DE UM NOVO LANÇAMENTO DE CLIENTE
					printf("\nDeseja fazer outro cadastro? (se sim, digite s)\n");
					scanf("%c", &res);
					fflush(stdin);
					system("cls");
				}
		}
		//VERIFICAÇÃO PARA A INICIALIZAÇÃO DA ENTRADA DE UM NOVO CLIENTE
		while ((res=='s' || res=='S') && i<=TAM);
		//ASSOCIAÇÃO DA VARIAVEL OP PARA UMA NOVA VERIFICAÇÃO E VALIDAÇÃO
		op='1';
	}
	else
	{
	//AVISO DE AGENDA LOTADA
		printf("\n\nAgenda lotada!\n\n");
		system ("pause");
		system ("cls");	
		op='1';
	}
}
	//INICIO DE CONFIGURAÇÃO DA OPÇÃO 2 DO MENU
	else
	{
		if (op == 2)
		{
			system("cls");
		/*VERIFICAÇÃO SE EXISTE ALGUM LANÇAMENTO DE CLIENTE, CASO O CONTADO I SE ENCONTRE NO VALOR 1 
		NÃO OUVE NENHUM LANÇAMENTO*/
		if (i==1)
		{
			printf("Agenda Vazia!\n\n");
			system ("pause");
			system ("cls");
			op='1';
		}
		else
		{
		//LANÇAMENTO DOS CLIENTES NA TELA
			printf("LISTA DE CLIENTES:\n\n");
		for (i=1; i<=j; i++)
		{
			
			printf("Código do cliente: cd_%d \n\n", ficha[i].codigo);
			printf("Nome: %s\n", ficha[i].nome);
			printf("Telefone: %s\n", ficha[i].tel);
			printf("E-mail: %s\n", ficha[i].email);
			printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
			//ASSOCIAÇÃO DA VARIAVEL OP PARA UMA NOVA VERIFICAÇÃO E VALIDAÇÃO
			op='1';
		}
		system ("pause");
		system ("cls");
		}
		}
	}
	}
	//FINAL DO PROGRAMA
	return (0);
}
