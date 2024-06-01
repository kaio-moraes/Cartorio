#include <stdio.h> //blibioteca de comunicaçao com o usuario
#include <stdlib.h> //blibioteca de alicação de espaço em memória
#include <locale.h> // blioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Funçao responsavel por cadastrar novos usuarios
{
	//inicio da criaçao de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// Solicita o CPF do usuário
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // Cria e abre o arquivo para escrita
	fprintf(file, cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	// Reabre o arquivo em modo de adição e escreve uma vírgula
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Solicita o nome do usuário
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	// Adiciona o nome ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	// Adiciona uma vírgula ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Solicita o sobrenome do usuário
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	// Adiciona o sobrenome ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	// Adiciona uma vírgula ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Solicita o cargo do usuário
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	// Adiciona o cargo ao arquivo
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	// Pausa a execução do programa até que o usuário pressione uma tecla
	system("pause");
	
}

int consulta()
{
	// Define a localização para o idioma português, permitindo o uso de caracteres acentuados e outros símbolos específicos do idioma
    setlocale(LC_ALL, "Portuguese");

    // Declara um array de caracteres para armazenar o CPF e outro para o conteúdo do arquivo
    char cpf[40];
    char conteudo[100];

    // Solicita ao usuário que digite o CPF a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // Declara um ponteiro para um arquivo
    FILE *file;

    // Abre o arquivo com o nome do CPF em modo de leitura ("r")
    file = fopen(cpf, "r");
	// Verifica se o arquivo foi aberto com sucesso
	if(file == NULL)
	{
		printf("NÃo foi possivel abrir o arquivo, nÃo localizado!.\n");
	}
		
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas sÃo as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	  	
	system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema");
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
		
		printf("### Cartório da EBAC ### \n\n");//inicio do menu
		printf("Escolha a opção desejada do menu:\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
		
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
			printf("Essa opção não existe.\n");
			system("pause");
			break;	
		} // fim da seleção
	
	} //fim do laço de repetição
}
