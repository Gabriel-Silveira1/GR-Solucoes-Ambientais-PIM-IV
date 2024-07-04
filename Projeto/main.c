#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#define SIZE 200

short mensagem;

typedef struct{
    char login[30]; // vetor login da struct pessoa
    char password[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" é o máximo de pessoas com logins e senhas


int main(){
    //ajustando para aceitar acentos
    setlocale(LC_ALL, "Portuguese");

    char login[30]; // responsável por armazenar a senha inserida pelo usuário
    char password[30]; // responsável por armazenar a senha inserida pelo usuário

    strcpy(p[0].login, "Administrador"); // Definindo o login "Administrador" na struct
    strcpy(p[0].password, "123456"); // Definindo a senha "123456"  na struct

    printf("\n===================================================================\n");
    printf("\n                            TELA LOGIN                           \n");
    printf("\n                     GR SOLUÇÕES AMBIENTAIS                          \n");
    printf("\n===================================================================\n");

    printf("\nLogin: ");
    scanf("%s", login); // armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main

    printf("\nSenha: ");
    scanf("%s", password); // armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função main

    if ((strcmp(login,p[0].login)==0) && (strcmp(password,p[0].password)==0)){ // A função strcmp é responsável por comparar string com string
        system("cls");
        printf("Usuário logado"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da função main, usuário será logado.
        menuinicial();
    }else{
        system("cls");
        printf("Login e/ou senha incorretos"); // senão, login ou senha incorreta.
        main();
    }
    return 0;
}

//declarando uma struct
typedef struct {
	char email[30];
	char nome[26];
	char senha[20];
	char sobrenome[30];
	float cnpj[20];
	char razao[40];
	char telefone[16];
	char endereco[50];
	char cidade[50];
	char estado[3];
	char nomefantasia[40];
	char data[11];
	float cep[10];
}Conta;

//declarando as funções
void FazerLogin();
void CriaConta();


int menuinicial(){
	//ajustando para aceitar acentos
    setlocale(LC_ALL, "Portuguese");

    //declaração da variavel de seleção de função
    int select;

do{
    printf("\n===================================================================\n");
    printf("\n                       TELA MENU INICIAL                           \n");
    printf("\n                     GR SOLUÇÕES AMBIENTAIS                          \n");
    printf("\n===================================================================\n");
    printf("1 - Fazer login em uma empresa\n");
    printf("2 - Cadastrar uma empresa\n");
    printf("0 - Finalizar o sistema\n");

	//entrada do numero da função
    printf("Digite o numero da opcao desejada: ");
    scanf("%d",&select);

    switch (select)
    {
    case 1:
    	system("cls");
    	fflush(stdin);
    	FazerLogin();
        break;
    case 2:
    	system("cls");
    	fflush(stdin);
        CriaConta();
        break;
    default:
        break;
    }

    //teste para se o usuario inserir numero menor ou maior do que o permitido
    if(select < 0 || select > 3){
    	system("cls");
        printf("O número da opcao não e valido\n");
    }

//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

}


//criação da função CriaConta
void CriaConta() {
    //ajustando para aceitar acentos
    setlocale(LC_ALL, "Portuguese");

	//abrindo arquivos
	FILE *farq = fopen("conta.txt", "a");
	FILE *fdados = fopen("dadoscadastrais.txt", "a");

	//verificando se o arquivo abriu corretamente
	if(farq == NULL && fdados == NULL){
		exit(0);
	}

	//declaração das variaveis
	Conta tconta;

	printf("\n-----------------------------------------------------------------------\n");
    printf("\n              CADASTRE A EMPRESA PREENCHENDO O FORMULÁRIO          \n");
    printf("\n-----------------------------------------------------------------------\n");

	//entrada do email
	printf("Digite o email de contato da empresa para o login: ");
	scanf( "%29s", tconta.email);
	fflush(stdin);

	//entrada do nome
	printf("Digite o primeiro nome do responsável: ");
	scanf( "%25[^\n]s", tconta.nome);
	fflush(stdin);

	//entrada do sobrenome
	printf("Digite o sobrenome do responsável: ");
	scanf( "%29[^\n]s", tconta.sobrenome);
	fflush(stdin);

	//entrada da senha
	printf("Digite a senha: ");
	scanf( "%19[^\n]s", tconta.senha);
	fflush(stdin);

	//entrada do nome fantasia
	printf("Digite o Nome Fantasia da Empresa: ");
	scanf( "%39[^\n]s", tconta.nomefantasia);
	fflush(stdin);

	//entrada da razão social
	printf("Digite a Razão Social da Empresa: ");
	scanf( "%39[^\n]s", tconta.razao);
	fflush(stdin);

	//entrada do cnpj da empresa
	printf("Digite o CNPJ da Empresa: ");
	scanf( "%18[^\n]s", tconta.cnpj);
	fflush(stdin);

	//entrada do telefone da empresa
	printf("Digite um telefone de contato: ");
	scanf( "%19[^\n]s", tconta.telefone);
	fflush(stdin);

	//entrada do endereço da empresa
	printf("Digite o endereço da empresa com número: ");
	scanf( "%25[^\n]s", tconta.endereco);
	fflush(stdin);

	//entrada do cep da empresa
	printf("Digite o CEP da empresa: ");
	scanf( "%9[^\n]s", tconta.cep);
	fflush(stdin);

	//entrada da cidade
	printf("Digite a cidade da empresa: ");
	scanf( "%49[^\n]s", tconta.cidade);
	fflush(stdin);

	//entrada do estado
	printf("Digite o estado da empresa em sigla: ");
	scanf( "%2[^\n]s", tconta.estado);
	fflush(stdin);

	//entrada da data de cadastro
	printf("Digite a data de cadastro: ");
	scanf( "%10[^\n]s", tconta.data);
	fflush(stdin);
	system("cls");

	printf("\t------Cadastro efetuado com sucesso------\n");
	printf("Email: %s\n",tconta.email);
	printf("Nome: %s\n",tconta.nome);
	printf("Sobrenome: %s\n",tconta.sobrenome);
	printf("Nome Fantasia: %s\n",tconta.nomefantasia);
	printf("Razão Social: %s\n",tconta.razao);
	printf("CNPJ: %s\n", tconta.cnpj);
	printf("Telefone: %s\n",tconta.telefone);
	printf("Endereço: %s\n",tconta.endereco);
	printf("CEP: %s\n",tconta.cep);
	printf("Cidade: %s\n",tconta.cidade);
	printf("Estado: %s\n",tconta.estado);
	printf("Data de cadastro: %s\n",tconta.data);
	printf("\t------------------------------------------\n");

	//salvando as infos da empresa nos arquivos txt
	fprintf(farq, "\n%s %s %s", tconta.email, tconta.nome, tconta.senha);
	fprintf(fdados, "\n%s %s %s %s %s %s %s %s %s %s %s", tconta.nome, tconta.sobrenome, tconta.nomefantasia, tconta.razao, tconta.cnpj, tconta.telefone, tconta.endereco, tconta.cep, tconta.cidade, tconta.estado, tconta.data);

	//fechando arquivos
	fclose(farq);
	fclose(fdados);
}

//criação da função FazerLogin
void FazerLogin(){
    //ajustando para aceitar acentos
    setlocale(LC_ALL, "Portuguese");

	//declaração das variaveis que serão utilizadas
	char email[30], senha[30];
	int testeSenha, testeEmail;

	printf("\n-----------------------------------------------------\n");
    printf("\n              ACESSE A EMPRESA DESEJADA          \n");
    printf("\n-----------------------------------------------------\n");

	//entrada de dados do login
	printf("Insira o email da empresa desejada: ");
	scanf( "%29s", email);
	fflush(stdin);

	printf("Insira a senha cadastrada: ");
	scanf( "%19s", senha);
	fflush(stdin);

	//abrindo o arquivo
	FILE *farq = fopen("conta.txt", "r+b");

	//verificando se o arquivo abriu corretamente
	if(farq == NULL){
		exit(0);
	}

	//apontando no inicio do arquivo
	fseek(farq, 0, SEEK_SET);

	//lendo linha por linha do arquivo ate o fim dele
	while(!feof(farq)){

		Conta tconta;

		fscanf(farq, "%s %s %s", tconta.email, tconta.nome, tconta.senha);

		//testando se o email e senha digitado pelo usuario é o mesmo que esta salvo na linha
		testeEmail = strncmp(tconta.email, email, 29);
		testeSenha = strncmp(tconta.senha, senha, 19);
	}

	//fechando o arquivo
	fclose(farq);

	//teste para verificar se o email e senha estão corretos
	if(testeEmail>0 || testeEmail<0 || testeSenha>0 || testeSenha<0){
		system("cls");
		printf("*********Os dados inseridos são invalidos*********");
		Sleep(1000);
		system("cls");
	}else{
		system("cls");
		printf("Acesso liberado\n");
		Sleep(500);
		system("cls");
		Menu();
	}
}

int Menu(){
    //setlocale permite usar acentos para isso precisa importar a biblioteca "<locale.h>" em cima
    setlocale(LC_ALL, "Portuguese");

    //var usada para selecionar o item do menu
    int select;

do{
    printf("--------------------Menu-----------------------\n");
    printf("\t\t1 - Registrar descarte\n");
    printf("\t\t2 - Relatórios\n");
    printf("\t\t0 - Voltar para login\n");
    printf("-----------------------------------------------\n");

	//entrada do numero da função
    printf("Digite o número da página desejada: ");
    scanf("%d",&select);

    //switch case usado para selecionar o item do menu
    switch (select)
    {
    case 1:
        system("cls");
        registro();
        break;
    case 2:
        system("cls");
        printf("Os relatórios foram gerados em arquivos.txt na pasta do projeto. \nCaso queira visualizar, filtrar ou até exportar os dados de todos os descartes adicionados no sistema, \nabra o arquivo registros.txt e utilize como quiser. \nCaso queira visualizar, filtrar ou até exportar os dados de todos os descartes adicionados no sistema de \num mês específico, ao abrir a pasta do projeto irá visualizar que possuem arquivos.txt correspondentes a\n cada mês do ano.\n");
        printf("\nQual ação deseja realizar agora?\n");
        break;
    default:
        system("cls");
        break;
    }
    //teste para se o usuario inserir numero menor ou maior do que o permitido
    if(select < 0 || select > 4){
        printf("\t\tO número da página não e válido\n");
    }
//se o numero selecionado for zero o sistema finaliza
}while (select != 0);

//fim da função principal main
}

//declarando uma struct


void registro(){
    struct registro
   {
   char destinacaopropria[SIZE];
   char cnpj[SIZE];
   char NomeFantasia[SIZE];
   int mes;
   char destinacaopropriaI[SIZE];
   char destinacaopropriaIIA[SIZE];
   char destinacaopropriaIIB[SIZE];
   char semdestinacaopropriaI[SIZE];
   char semdestinacaopropriaIIA[SIZE];
   char semdestinacaopropriaIIB[SIZE];
   char reciclagemI[SIZE];
   char reciclagemIIA[SIZE];
   char reciclagemIIB[SIZE];
   char gastosI[SIZE];
   char gastosIIA[SIZE];
   char gastosIIB[SIZE];
   char data[SIZE];
   char funcionario[SIZE];
   };
   struct registro empresa;

   system("cls || clear");
   // system("color F4");
   printf("\nRegistro de um descarte de resíduos\n");
   printf("...................................................\n\n");
    fflush(stdin);
    FILE *ponteiroArquivo;
    ponteiroArquivo=(fopen("registros.txt", "a"));
    printf("CNPJ da empresa: ");
    fgets(empresa.cnpj, 200, stdin);
    printf("\nNome fantasia da empresa: ");
    fgets(empresa.NomeFantasia, 200, stdin);
    printf("\nQual tipo de descarte realizado: ");
    fgets(empresa.destinacaopropria, 200, stdin);
    printf("\nQual funcionário acompanhou o descarte realizado: ");
    fgets(empresa.funcionario, 200, stdin);
    printf("\nQuantidade de resíduos com destinação própria, classe I: ");
    fgets(empresa.destinacaopropriaI, 200, stdin);
    printf("\nQuantidade de resíduos com destinação própria, classe IIA: ");
    fgets(empresa.destinacaopropriaIIA, 200, stdin);
    printf("\nQuantidade de resíduos com destinação própria, classe IIB: ");
    fgets(empresa.destinacaopropriaIIB, 200, stdin);
    printf("\nQuantidade de resíduos sem destinação própria, classe I: ");
    fgets(empresa.semdestinacaopropriaI, 200, stdin);
    printf("\nQuantidade de resíduos sem destinação própria, classe IIA: ");
    fgets(empresa.semdestinacaopropriaIIA, 200, stdin);
    printf("\nQuantidade de resíduos sem destinação própria, classe IIB: ");
    fgets(empresa.semdestinacaopropriaIIB, 200, stdin);
    printf("\nQuantidade de resíduos encaminhados para a reciclagem, classe I: ");
    fgets(empresa.reciclagemI, 200, stdin);
    printf("\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: ");
    fgets(empresa.reciclagemIIA, 200, stdin);
    printf("\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: ");
    fgets(empresa.reciclagemIIB, 200, stdin);
    printf("\nQuantidade de gastos com encaminhamento de resíduos, classe I: ");
    fgets(empresa.gastosI, 200, stdin);
    printf("\nQuantidade de gastos com encaminhamento de resíduos, classe IIA: ");
    fgets(empresa.gastosIIA, 200, stdin);
    printf("\nQuantidade de gastos com encaminhamento de resíduos, classe IIB: ");
    fgets(empresa.gastosIIB, 200, stdin);
    printf("\n Informa a data que foi realizado o descarte: ");
    fgets(empresa.data, 200, stdin);
 printf("\n");
     short mes;
    printf("\nInforme o mês do descarte em número: ");
    scanf("%d", &mes);
    if(mes<1 || mes>12)
    {
        mensagem= 2;
        Mensagens(mensagem);
        return;
    }else if(mes>=1 || mes<=12){
       printf("Descarte adicionado com sucesso!");
       sleep(3);
       system("cls");
       Menu();
    }
        fprintf(ponteiroArquivo, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroArquivo, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroArquivo, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroArquivo, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroArquivo, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroArquivo, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroArquivo, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroArquivo, "\nData do descarte realizado: %s\n", empresa.data);
        if(mes == 1) {
            FILE *ponteirojaneiro;
            ponteirojaneiro=(fopen("Relatorios de Janeiro.txt", "a"));
        fprintf(ponteirojaneiro, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteirojaneiro, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteirojaneiro, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteirojaneiro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteirojaneiro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteirojaneiro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteirojaneiro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteirojaneiro, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteirojaneiro);
        }
                if (mes == 2) {
            FILE *ponteiroFevereiro;
            ponteiroFevereiro=(fopen("Relatorios de Fevereiro.txt", "a"));
        fprintf(ponteiroFevereiro, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroFevereiro, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroFevereiro, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroFevereiro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroFevereiro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroFevereiro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroFevereiro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroFevereiro, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroFevereiro);
                }
                if (mes == 3) {
            FILE *ponteiroMarco;
            ponteiroMarco=(fopen("Relatorios de Março.txt", "a"));
        fprintf(ponteiroMarco, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroMarco, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroMarco, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroMarco, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroMarco, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroMarco, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroMarco, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroMarco, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroMarco);
                }
                if (mes == 4) {
            FILE *ponteiroAbril;
        ponteiroAbril=(fopen("Relatorios de Abril.txt", "a"));
        fprintf(ponteiroAbril, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroAbril, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroAbril, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroAbril, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroAbril, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroAbril, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroAbril, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroAbril, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroAbril);
                }
                if (mes == 5) {
            FILE *ponteiroMaio;
        ponteiroMaio=(fopen("Relatorios de Maio.txt", "a"));
        fprintf(ponteiroMaio, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroMaio, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroMaio, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroMaio, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroMaio, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroMaio, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroMaio, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroMaio, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroMaio);
                }
            if (mes == 6) {
            FILE *ponteiroJunho;
        ponteiroJunho=(fopen("Relatorios de Junho.txt", "a"));
        fprintf(ponteiroJunho, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroJunho, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroJunho, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos com destinação própria, classe I: : %s", empresa.destinacaopropriaI);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos com destinação própria, classe II A: : %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos com destinação própria, classe II B: : %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos sem destinação própria, classe I: : %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos sem destinação própria, classe II A: : %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos sem destinação própria, classe II B: : %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: : %s", empresa.reciclagemI);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos encaminhados para a reciclagem, classe II A: : %s", empresa.reciclagemIIA);
        fprintf(ponteiroJunho, "\nQuantidade de resíduos encaminhados para a reciclagem, classe II B: : %s", empresa.reciclagemIIB);
        fprintf(ponteiroJunho, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: : %s", empresa.gastosI);
        fprintf(ponteiroJunho, "\nQuantidade de gastos com o encaminhamento de resíduos, classe II A: : %s", empresa.gastosIIA);
        fprintf(ponteiroJunho, "\nQuantidade de gastos com o encaminhamento de resíduos, classe II B: : %s", empresa.gastosIIB);
        fprintf(ponteiroJunho, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroJunho);
                }
                if (mes == 7) {
            FILE *ponteiroJulho;
        ponteiroJulho=(fopen("Relatorios de Julho.txt", "a"));
        fprintf(ponteiroJulho, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroJulho, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroJulho, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroJulho, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroJulho, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroJulho, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroJulho, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroJulho, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroJulho);
                }
            if (mes == 8) {
            FILE *ponteiroAgosto;
        ponteiroAgosto=(fopen("Relatorios de Agosto.txt", "a"));
        fprintf(ponteiroAgosto, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroAgosto, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroAgosto, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroAgosto, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroAgosto, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroAgosto, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroAgosto, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroAgosto, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroAgosto);
                }
            if (mes == 9) {
            FILE *ponteiroSetembro;
        ponteiroSetembro=(fopen("Relatorios de Setembro.txt", "a"));
        fprintf(ponteiroSetembro, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroSetembro, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroSetembro, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroSetembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroSetembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroSetembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroSetembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroSetembro, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroSetembro);
                }
            if (mes == 10) {
            FILE *ponteiroOutubro;
        ponteiroOutubro=(fopen("Relatorios de Outubro.txt", "a"));
        fprintf(ponteiroOutubro, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroOutubro, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroOutubro, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroOutubro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroOutubro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroOutubro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroOutubro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroOutubro, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroOutubro);
                }
            if (mes == 11) {
            FILE *ponteiroNovembro;
        ponteiroNovembro=(fopen("Relatorios de Novembro.txt", "a"));
        fprintf(ponteiroNovembro, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroNovembro, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroNovembro, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroNovembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroNovembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroNovembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroNovembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroNovembro, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroNovembro);
                }
            if (mes == 12) {
            FILE *ponteiroDezembro;
        ponteiroDezembro=(fopen("Relatorios de Dezembro.txt", "a"));
        fprintf(ponteiroDezembro, "--------------------------------------\n\nCNPJ da empresa: %s", empresa.cnpj);
        fprintf(ponteiroDezembro, "\nNome Fantasia da empresa: %s", empresa.NomeFantasia);
        fprintf(ponteiroDezembro, "\nQual funcionário acompanhou o descarte realizado: %s", empresa.funcionario);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos com destinação própria, classe I: %s", empresa.destinacaopropriaI);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos com destinação própria, classe IIA: %s", empresa.destinacaopropriaIIA);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos com destinação própria, classe IIB: %s", empresa.destinacaopropriaIIB);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos sem destinação própria, classe I: %s", empresa.semdestinacaopropriaI);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos sem destinação própria, classe IIA: %s", empresa.semdestinacaopropriaIIA);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos sem destinação própria, classe IIB: %s", empresa.semdestinacaopropriaIIB);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe I: %s", empresa.reciclagemI);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIA: %s", empresa.reciclagemIIA);
        fprintf(ponteiroDezembro, "\nQuantidade de resíduos encaminhados para a reciclagem, classe IIB: %s", empresa.reciclagemIIB);
        fprintf(ponteiroDezembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe I: %s", empresa.gastosI);
        fprintf(ponteiroDezembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIA: %s", empresa.gastosIIA);
        fprintf(ponteiroDezembro, "\nQuantidade de gastos com o encaminhamento de resíduos, classe IIB: %s", empresa.gastosIIB);
        fprintf(ponteiroDezembro, "\nData do descarte realizado: %s\n", empresa.data);
            fclose(ponteiroDezembro);
                }
        fclose(ponteiroArquivo);
}
void Mensagens( short mensagem)
{
    if (mensagem == 1)
    {
     printf ("\nOpção Inválida! Tente novamente!\n");
    }
    if (mensagem == 2)
    {
     printf ("\nMês Inválido! Tente novamente!\n");
    }
    if (mensagem == 3)
    {
     printf ("\nVenda adicionada com sucesso!!\n");
    }

}
