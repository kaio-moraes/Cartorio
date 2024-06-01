#include <stdio.h> //blibioteca de comunica�ao com o usuario
#include <stdlib.h> //blibioteca de alica��o de espa�o em mem�ria
#include <locale.h> // blioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun�ao responsavel por cadastrar novos usuarios
{
	//inicio da cria�ao de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// Solicita o CPF do usu�rio
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // Cria e abre o arquivo para escrita
	fprintf(file, cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	// Reabre o arquivo em modo de adi��o e escreve uma v�rgula
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Solicita o nome do usu�rio
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	// Adiciona o nome ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	// Adiciona uma v�rgula ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Solicita o sobrenome do usu�rio
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	// Adiciona o sobrenome ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	// Adiciona uma v�rgula ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Solicita o cargo do usu�rio
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	// Adiciona o cargo ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	// Pausa a execu��o do programa at� que o usu�rio pressione uma tecla
	system("pause");
	
}

int consulta()
{
	// Define a localiza��o para o idioma portugu�s, permitindo o uso de caracteres acentuados e outros s�mbolos espec�ficos do idioma
    setlocale(LC_ALL, "Portuguese");

    // Declara um array de caracteres para armazenar o CPF e outro para o conte�do do arquivo
    char cpf[40];
    char conteudo[100];

    // Solicita ao usu�rio que digite o CPF a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // Declara um ponteiro para um arquivo
    FILE *file;

    // Abre o arquivo com o nome do CPF em modo de leitura ("r")
    file = fopen(cpf, "r");
	// Verifica se o arquivo foi aberto com sucesso
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
		
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	  	
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema");
		system("pause");
	}
}

int main()
	{
	int opcao=0; //Definindo Variaveis
	int x=1;
	
	for (x=1;x=1;)
		{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		
		printf("### Cart�rio da EBAC ### \n\n");//inicio do menu
		printf("Escolha a op��o desejada do menu:\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro();
			break;	
			
			case 2:
			consulta();
			break;	
			
			case 3:
			deletar();
			break;	
			
			case 4:
			printf("Obrigado por utilizar o sistema:\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o existe.\n");
			system("pause");
			break;	
		} // fim da sele��o
	
	} //fim do la�o de repeti��o
}
