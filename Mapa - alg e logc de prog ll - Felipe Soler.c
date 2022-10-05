//ALUNO: FELIPE CAPPI SOLER
//MAPA ALGORITMOS E L�GICA DE PROGRAMA��O II

//INCLUS�O DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
//DEFINI��O DE CONSTANTE
#define TAM 5
//LAN�AMENTO DO STRUCT CLIENTE COM OS DADOS SOLICITADO
struct cliente
{
	int codigo;
	unsigned char nome[50], tel[50], email[50];
};
//INICIO DO PROGRAMA PRINCIPAL
int main()
{
setlocale(LC_ALL, "Portuguese");
//LAN�AMENTO DAS VARIAVEIS
struct cliente ficha[20];
char res;
int i, j, op;
//INICIALIZA��O DE ALGUMAS VARIAVEIS
i=1;
//LAN�AMENTO DO MENU PRINCIPAL
while (op !=0)
	{
	printf("ESCOLHA UMA OP��O:\n");
	printf("1 - Cadastrar clientes\n");
	printf("2 - Mostrar dados dos clientes cadastrados\n");
	printf("0 - Finalizar programa\n");
	scanf("%d", &op);
	fflush(stdin);
	
//VERIFICA��O DO LAN�AMENTO DE N�MEROS
//VERIFICA��O DA ESCOLHA CERTA DAS OP��ES
if (isdigit(op) || op!=1 && op!=2 && op!=0)
{
	system("cls");
	printf("\nERRO: OP��O INV�LIDA!\n");
	system ("pause");
	system ("cls");
}
//INICIO DAS CONFIGURA��ES DA OP 1 DO MENU
if (op == 1)
{
system("cls");
	//LIMITA��O A 5 LAN�AMENTOS
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
			//CONTADOR VINCULADO AO C�DIGO DO CLIENTE
			ficha[i].codigo=i;
			//CONTADOR J LAN�ADO PARA SUA UTILIZA��O NO FUTURO "FOR"
			j=i;
			//CONTADOR I=I+1
			i++;
				//LIMITA��O EM 5 LAN�AMENTO AP�S O QUINTO
				if (i==6)
				{
					printf("\n\nClientes salvos\n\nAgenda lotada!\n\nLimite de 5 clientes\n\n ");
					system ("pause");
					system ("cls");	
				}
				else
				{
					//MENSAGEM SOLICITANDO A NECESSIDADE DE UM NOVO LAN�AMENTO DE CLIENTE
					printf("\nDeseja fazer outro cadastro? (se sim, digite s)\n");
					scanf("%c", &res);
					fflush(stdin);
					system("cls");
				}
		}
		//VERIFICA��O PARA A INICIALIZA��O DA ENTRADA DE UM NOVO CLIENTE
		while ((res=='s' || res=='S') && i<=TAM);
		//ASSOCIA��O DA VARIAVEL OP PARA UMA NOVA VERIFICA��O E VALIDA��O
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
	//INICIO DE CONFIGURA��O DA OP��O 2 DO MENU
	else
	{
		if (op == 2)
		{
			system("cls");
		/*VERIFICA��O SE EXISTE ALGUM LAN�AMENTO DE CLIENTE, CASO O CONTADO I SE ENCONTRE NO VALOR 1 
		N�O OUVE NENHUM LAN�AMENTO*/
		if (i==1)
		{
			printf("Agenda Vazia!\n\n");
			system ("pause");
			system ("cls");
			op='1';
		}
		else
		{
		//LAN�AMENTO DOS CLIENTES NA TELA
			printf("LISTA DE CLIENTES:\n\n");
		for (i=1; i<=j; i++)
		{
			
			printf("C�digo do cliente: cd_%d \n\n", ficha[i].codigo);
			printf("Nome: %s\n", ficha[i].nome);
			printf("Telefone: %s\n", ficha[i].tel);
			printf("E-mail: %s\n", ficha[i].email);
			printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
			//ASSOCIA��O DA VARIAVEL OP PARA UMA NOVA VERIFICA��O E VALIDA��O
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
