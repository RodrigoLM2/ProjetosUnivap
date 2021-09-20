#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

/*

	Projeto 1 de SC

Turma: 1FID
Materia: SC

ALUNO 1: Rodrigo Lopes Marques
ALUNO 2: Gustavo Otac?lio Jacinto Ramos
ALUNO 3: Henrique Curtis Correa Marques

*/

int i, ia, qa, im, ie, is, opc, end, x, y, z, nSorteado;
char vazio, programa, memoria[10], aptos[10], suspensos[10], executados[512];

main(){
	
	// Essa linha de comando faz o programa aceitar acentua��o nos printf
	setlocale(LC_ALL,"Portuguese");
	
	// Para gerar o n�mero ale�torio
	srand(time(NULL));
	
	while(end==0){
		system("cls");
		opc=0;
		z=1;
		y=0;
		
		// Cabe�alho inicial do MENU do Simulador
		printf("===========================================\n");
		printf("SIMULADOR DO FUCIONAMENTO DE UM PROCESSADOR\n");
		printf("===========================================\n\n");
		
		printf("MENU: \n");
		// Op��es do MENU
		printf("[1] - Carregar Programa na Mem�ria\n");
		printf("[2] - Listagem Programas na Mem�ria\n");
		printf("[3] - Listagem Programas Aptos\n");
		printf("[4] - Listagem Programas Suspensos\n");
		printf("[5] - Enviar Programa da Mem�ria para Fila de Aptos\n");
		printf("[6] - Executar Programas\n");
		printf("[7] - Tirar Programa da Fila de Suspensos\n");
		printf("[8] - Encerrar Simulador\n\n");
		// Usuario decide qual op��o prosseguir 
		printf("Selecione a op��o digitando o N�MERO correspondente:\n[   ]\b\b\b");
		scanf("%d", &opc);		
		
		// de acordo com qual op��o escolhida o switch leva ao case especifico
		switch (opc){
			
			case 1:
				while(z==1){
					system("cls");
					y=0;
					opc=0;
					
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
					printf("Carregar Programa na Mem�ria\n");
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
					
					// Verifica se h� mais espa�o na mem�ria(vetor), se n�o tiver mais for�a o usuario voltar ao menu
					if(im==10){
						system("cls");
						printf("N�o h� mais espa�os na mem�ria\n");
						getch();	
						break;
					}else{	
						// Caso ao contr�rio pedir� a letra para representa o programa que ser� carregado na mem�ria(vetor)	
						printf("\nDigite uma �nica letra que representar� o programa carregado na mem�ria:\n");
						fflush(stdin);
						scanf("%c", &programa);
					}
					
					if(z==0){
						for(x=0; x<=9; x++){
							// Verifica se a letra digitado � igual a uma letra j� armazenada no mem�ria(vetor)
							if(programa == memoria[x]){
								y++;
							}
						}	
					}
					
					if(y==0){
						// Armazena a letra digitada na memoria(Vetor)
						memoria[im] = programa;
						printf("\nPrograma [%c] carregado\n\n", memoria[im]);
						im++;
						// Da op��o de carregar outro programa(letra) na mem�ria(vetor) ou voltar ao menu
						printf("Deseja carregar outro programa? 1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);

					}else{
						// Caso ja exista um programa com a letra digitada da op��o a usuario digitar outra letra ou voltar ao menu
						system("cls");
						printf("Programa j� usando a letra de indentifica��o: [%c]", programa);
						printf("\nDeseja tentar carregar o programa com outra letra? 1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);

					}					
				}

				break;
			

			case 2:
				system("cls");
				// Apenas apresenta o que est� no vetor memoria, e da op��o de voltar ao menu
				printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
				printf("Listagem Programas na Mem�ria\n");
				printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
				
				printf("\nProgramas carregados na MEM�RIA:\n\n");
				for(i=0; i<=9; i++){
					printf("[%c] ", memoria[i]);					
				}
				getch();
				
				break;			
				
							
			case 3:
				system("cls");
				// Apenas apresenta o que est� no vetor aptos, e da op��o de voltar ao menu
				printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
				printf("Listagem Programas Aptos\n");
				printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
				
				printf("\nProgramas na lista de APTOS:\n\n");
				for(i=0; i<=9; i++){
					printf("[%c] ", aptos[i]);					
				}
				getch();
				
				break;		
			
			
			case 4:
				system("cls");
				// Apenas apresenta o que est� no vetor suspensos, e da op��o de voltar ao menu
				printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
				printf("Listagem Programas Suspensos\n");
				printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
				
				printf("\nProgramas na lista de SUSPENSOS:\n\n");
				for(i=0; i<=9; i++){
					printf("[%c] ", suspensos[i]);					
				}
				getch();
				
				break;	
				
			
			
			case 5:
				while(z==1){
				
					system("cls");
					y=0;
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
					printf("Envio de Programas Para a Fila de Aptos\n");
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
					
					// Recebe o valor da letra que sera enviada para o vetor o aptos
					printf("\nDigite a LETRA do programa que esta na mem�ria que deseja enviar para a lista de APTOS:\n");
					fflush(stdin);
					scanf("%c", &programa);
					
					// Testa se a letra digita existe no vetor memoria, se sim ela � apagada no vetor memoria e ja reoganiza o vetor
					for(x=0; x<=im-1; x++){
						if(programa == memoria[x]){
							
							memoria[x] = vazio;	
							y=1;
							for(i=x; i<=8; i++){
								memoria[i] = memoria[i+1];
							}	
							im--;	
							memoria[9] = vazio;
						}
					}
					
					// De acordo com a ultimo bloco de comando, se existir no vetor, a letra digitada sera enviada para aptos
					// e dar� ao usuario a op��o de enviar outra letra ou voltar ao menu
					if(y==1){
						aptos[ia] = programa;
						printf("\nPrograma [%c] enviado para lista de APTOS\n\n", aptos[ia]);
						ia++;
						
						printf("Deseja enviar outro programa? 1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);

					}else{
						// se n�o tiver a letra no vetor, informa ao usuario
						// e dar� ao usuario a op��o de tentar enviar outra letra ou voltar ao menu
						system("cls");
						printf("Nenhum programa encontrado com letra de indentifica��o: [%c]", programa);
						printf("\nDeseja tentar enviar outro programa? 1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);

					}				
				}
							
				break;			
			
			
			case 6:
				system("cls");
					
				printf("=-=-=-=-=-=-=-=-=-\n");
				printf("Executar Programas\n");
				printf("=-=-=-=-=-=-=-=-=-\n");
				
				// Pergunta se quer iniciar a execu��o dos programas, pois uma vez iniciada ele ira executar quem tiver no vetor aptos[0]
				printf("Deseja iniciciar a execu��o dos programas na fila de Aptos? \n1 -> Sim / 2 -> VOLTAR MENU\n");
				scanf("%d", &z);

				while(z==1){
					
					system("cls");
					// testa se h� alguma letra no vetor aptos, para ver � possivel prosseguir
					if(ia<=0){
						printf("N�o h� nenhum programa na fila de Aptos para ser executado");
						getch();
						break;
					}
					
					// Apenas para ficar bonitinho para o usu�rio
					printf("Executando o [%c] ", aptos[0]);
					printf(" .");
					printf(" .");
					printf(" .");
					
					// Gera um numero "ale�torio" de 0 a 2
						nSorteado = rand()%3;
						printf(" %d", nSorteado);


					// de acordo com o numero gerado define o resultado da execu��o do programa
					if(nSorteado == 0){
						printf("\n\nExecutado at� o final");
						executados[ie] = aptos[0];
						ie++;
					}else{
						if(nSorteado == 1){
							printf("\n\nFim do tempo de quantum");
							memoria[im] = aptos[0];
							im++;
						}else{
							if(nSorteado == 2){
								printf("\n\nSuspens�o");
								suspensos[is] = aptos[0];
								is++;
							}
						}
					}
					
					//Reoganiza o vetor aptos apos a retirada do programa processado da fila de aptos
					aptos[0] = vazio;
					for(i=0; i<=8; i++){
						aptos[i] = aptos[i+1];
					}
					qa--;
					ia--;	
					aptos[9] = vazio;
					
					//Da op��o de repetir o processo ou voltar ao menu					
					printf("\n\nDeseja executar outro programa? \n1 -> SIM / 2 -> VOLTAR MENU\n");
					scanf("%d", &z);
				}			
				break;	
				
				
			case 7:
				
				while(z==1){
					system("cls");				
					y=0;
							
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
					printf("Tirar o Programa da Fila de Suspensos\n");
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
						
					//Usuario informa a letra para retirar do vetor suspensos
					printf("\nDigite a LETRA do programa que deseja tirar da lista de suspensos:\n");
					fflush(stdin);
					scanf("%c", &programa);
					
					//Testa se a letra digita existe no vetor suspensos, se sim ela � apagada no vetor memoria e ja reoganiza o vetor
					for(i=0; i<=is-1; i++){
							
						if(programa == suspensos[i]){
							suspensos[i] = vazio;
							for(x=0; x<=8; x++){
								suspensos[x] = suspensos[x+1];
							}
							suspensos[9] = vazio;
							y++;
						}
					}
					
					//Se existir no vetor apenas informa ao usuario
					if(y==1){
						printf("\n\nPrograma [%c] foi retirado da lista de suspensos", programa);
						printf("\n\nDeseja retirar outro programa na lista de suspensos? \n1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);
					}else{
						//Se n�o informa ao usuario, e da ele a op��o de tentar novamente ou voltar ao menu
						system("cls");
						printf("Nenhum programa encontrado com letra de indentifica��o: [%c]", programa);
						printf("\n\nDeseja tentar retirar outro programa da lista de suspensos? \n1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);
					}					
				}
			
				break;	
				
				
			case 8:
				//Finaliza o programa
				printf("\nSimulador Finalizado");
				end++;
				break;
			
			
			default:
				//� executado quando a op��o digitada no menu n�o corresponde nenhuma das op��es disponivel
				printf("\nValor Digitado Incorreto!");
				getch();
				break;
		}	
	}	
}
