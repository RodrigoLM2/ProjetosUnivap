#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*

 	Projeto 3 de LE

Turma: 1FID
Integrantes:
 - Rodrigo Lopes Marques
 - Henrique Curtis Correa Marques
 - Gustavo Otac�lio
 
*/

int z, i, x, soma, resto, digito1, digito2, validos, invalidos, total; 
float pValidos, pInvalidos;
int cpf[11], a[2][9], b[2][10], multi[10];

main(){
	
	// Essa linha de comando faz o programa aceitar acentua��o e caractere especial nos printf
	setlocale(LC_ALL,"Portuguese");
	
	// Pergunta ao usu�rio se deseja iniciar o teste de valida��o de cpf
	printf("Deseja iniciar o teste de valida��o de CPF? Sim -> 1 / N�o -> 2\n");
	scanf("%d", &z);
	// Testa se a resposta digitado � valida
	while((z != 1) & (z != 2)){
		system("cls");
		printf("\aValor digitado incorreto! fique atento que: Sim -> 1 / N�o -> 2\n");
		printf("Deseja iniciar o teste de valida��o de CPF?\n");
		scanf("%d", &z);
	}

	while(z == 1){
		
		system("cls");
		
		printf("=========================\n");
		printf("Teste de Valida��o de CPF");
		printf("\n=========================\n");
		
		// Pede ao usu�rio digitar o cpf que deseja testar
		printf("\nInforme o CPF a seguir:\n");
		for(i=0; i<=10; i++){
			printf("Digite o %d� numero do CPF: ", i+1);
			scanf("%d", &cpf[i]);
			// Testa se os numeros informados s�o validos, que seria um �nico n�mero por vez de 0 at� 9
			if(cpf[i] < 0 || cpf[i] > 9){
				printf("\nValor Inv�lido! Digite 1 digito de cada vez\n\n");
				i--;
			}
			
		}
		
		x=10;
		soma=0; 
		// Guarda o cpf na primeira linha da Matriz A e numeros de 10 ate 2 na segunda linha
		// Multiplica a primeira linha com a segunda, e soma todos os resultados
		for(i=0; i<=8; i++){
			a[0][i] = cpf[i];
			a[1][i] = x;
			x--;
			multi[i] = a[0][i] * a[1][i];
			soma += multi[i];
		}
		
		// Com a soma � dividido por 11 e � pegado o resto
		resto = soma%11;
		
		// Com o resto descobrimos o primeiro digito
		if(resto < 2){
			digito1 = 0;
		}else{
			digito1 = 11 - resto;
		}
		
		x=11;
		soma = 0;
		// Guarda o cpf na primeira linha da Matriz B com o primeiro digito gerado e numeros de 11 ate 2 na segunda linha
		// Multiplica a primeira linha com a segunda, e soma todos os resultados
		for(i=0; i<=9; i++){
			b[0][i] = cpf[i];
			b[1][i] = x;
			b[0][9] = digito1;
			x--;
			multi[i] = b[0][i] * b[1][i];
			soma += multi[i];
		}
		// Calcula o resto da soma
		resto = soma%11;
		
		// E com o resto descobre o segundo digito
		if(resto < 2){
			digito2 = 0;
		}else{
			digito2 = 11 - resto;
		}
		
		// Com os dois digidos gerados e os informados pelo usu�rio, comparamos, e se for igual � v�lido
		if(cpf[9] == digito1 & cpf[10] == digito2){
			printf("\nCPF V�lido");
			validos++;
		}else{
			printf("\nCPF Inv�lido");
			invalidos++;
		}
		
		// Pergunta se quer testar outro CPF
		printf("\n\nDeseja testar outro CPF? Sim -> 1 / N�o -> 2\n");
		scanf("%d", &z);
		while(z != 1 & z != 2){
			system("cls");
			printf("\aValor digitado incorreto!\n");
			printf("Deseja testar outro CPF? Sim -> 1 / N�o -> 2\n");
			scanf("%d", &z);
		}
    }
    
	system("cls");
	
	// Traz as estatiscas dos CPFs testados no programa
	total = validos + invalidos;
	pValidos = (validos*100)/total;
	pInvalidos = (invalidos*100)/total;
	
	printf("Estat�sticas: \n\n");
	printf("Total de CPF Testados: %d\n", total);
	printf("Total de CPF V�lidos: %d\n", validos);
	printf("Total de CPF Inv�lidos: %d\n", invalidos);
	printf("Percentual de CPF V�lidos: %.1f%%\n", pValidos);
	printf("Pencentual de CPF Inv�lidos: %.1f%%\n", pInvalidos);
	
}
