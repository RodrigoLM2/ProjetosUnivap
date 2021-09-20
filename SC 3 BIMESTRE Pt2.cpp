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
	
	// Essa linha de comando faz o programa aceitar acentuação nos printf
	setlocale(LC_ALL,"Portuguese");
	
	// Para gerar o número aleátorio
	srand(time(NULL));
	
	while(end==0){
		system("cls");
		opc=0;
		z=1;
		y=0;
		
		// Cabeçalho inicial do MENU do Simulador
		printf("===========================================\n");
		printf("SIMULADOR DO FUCIONAMENTO DE UM PROCESSADOR\n");
		printf("===========================================\n\n");
		
		printf("MENU: \n");
		// Opções do MENU
		printf("[1] - Carregar Programa na Memória\n");
		printf("[2] - Listagem Programas na Memória\n");
		printf("[3] - Listagem Programas Aptos\n");
		printf("[4] - Listagem Programas Suspensos\n");
		printf("[5] - Enviar Programa da Memória para Fila de Aptos\n");
		printf("[6] - Executar Programas\n");
		printf("[7] - Tirar Programa da Fila de Suspensos\n");
		printf("[8] - Encerrar Simulador\n\n");
		// Usuario decide qual opção prosseguir 
		printf("Selecione a opção digitando o NÚMERO correspondente:\n[   ]\b\b\b");
		scanf("%d", &opc);		
		
		// de acordo com qual opção escolhida o switch leva ao case especifico
		switch (opc){
			
			case 1:
				while(z==1){
					system("cls");
					y=0;
					opc=0;
					
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
					printf("Carregar Programa na Memória\n");
					printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
					
					// Verifica se há mais espaço na memória(vetor), se não tiver mais força o usuario voltar ao menu
					if(im==10){
						system("cls");
						printf("Não há mais espaços na memória\n");
						getch();	
						break;
					}else{	
						// Caso ao contrário pedirá a letra para representa o programa que será carregado na memória(vetor)	
						printf("\nDigite uma única letra que representará o programa carregado na memória:\n");
						fflush(stdin);
						scanf("%c", &programa);
					}
					
					if(z==0){
						for(x=0; x<=9; x++){
							// Verifica se a letra digitado é igual a uma letra já armazenada no memória(vetor)
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
						// Da opção de carregar outro programa(letra) na memória(vetor) ou voltar ao menu
						printf("Deseja carregar outro programa? 1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);

					}else{
						// Caso ja exista um programa com a letra digitada da opção a usuario digitar outra letra ou voltar ao menu
						system("cls");
						printf("Programa já usando a letra de indentificação: [%c]", programa);
						printf("\nDeseja tentar carregar o programa com outra letra? 1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);

					}					
				}

				break;
			

			case 2:
				system("cls");
				// Apenas apresenta o que está no vetor memoria, e da opçâo de voltar ao menu
				printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
				printf("Listagem Programas na Memória\n");
				printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
				
				printf("\nProgramas carregados na MEMÓRIA:\n\n");
				for(i=0; i<=9; i++){
					printf("[%c] ", memoria[i]);					
				}
				getch();
				
				break;			
				
							
			case 3:
				system("cls");
				// Apenas apresenta o que está no vetor aptos, e da opçâo de voltar ao menu
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
				// Apenas apresenta o que está no vetor suspensos, e da opçâo de voltar ao menu
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
					printf("\nDigite a LETRA do programa que esta na memória que deseja enviar para a lista de APTOS:\n");
					fflush(stdin);
					scanf("%c", &programa);
					
					// Testa se a letra digita existe no vetor memoria, se sim ela é apagada no vetor memoria e ja reoganiza o vetor
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
					// e dará ao usuario a opção de enviar outra letra ou voltar ao menu
					if(y==1){
						aptos[ia] = programa;
						printf("\nPrograma [%c] enviado para lista de APTOS\n\n", aptos[ia]);
						ia++;
						
						printf("Deseja enviar outro programa? 1 -> SIM / 2 -> VOLTAR MENU\n");
						scanf("%d", &z);

					}else{
						// se não tiver a letra no vetor, informa ao usuario
						// e dará ao usuario a opção de tentar enviar outra letra ou voltar ao menu
						system("cls");
						printf("Nenhum programa encontrado com letra de indentificação: [%c]", programa);
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
				
				// Pergunta se quer iniciar a execução dos programas, pois uma vez iniciada ele ira executar quem tiver no vetor aptos[0]
				printf("Deseja iniciciar a execução dos programas na fila de Aptos? \n1 -> Sim / 2 -> VOLTAR MENU\n");
				scanf("%d", &z);

				while(z==1){
					
					system("cls");
					// testa se há alguma letra no vetor aptos, para ver é possivel prosseguir
					if(ia<=0){
						printf("Não há nenhum programa na fila de Aptos para ser executado");
						getch();
						break;
					}
					
					// Apenas para ficar bonitinho para o usuário
					printf("Executando o [%c] ", aptos[0]);
					printf(" .");
					printf(" .");
					printf(" .");
					
					// Gera um numero "aleátorio" de 0 a 2
						nSorteado = rand()%3;
						printf(" %d", nSorteado);


					// de acordo com o numero gerado define o resultado da execução do programa
					if(nSorteado == 0){
						printf("\n\nExecutado até o final");
						executados[ie] = aptos[0];
						ie++;
					}else{
						if(nSorteado == 1){
							printf("\n\nFim do tempo de quantum");
							memoria[im] = aptos[0];
							im++;
						}else{
							if(nSorteado == 2){
								printf("\n\nSuspensão");
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
					
					//Da opção de repetir o processo ou voltar ao menu					
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
					
					//Testa se a letra digita existe no vetor suspensos, se sim ela é apagada no vetor memoria e ja reoganiza o vetor
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
						//Se não informa ao usuario, e da ele a opção de tentar novamente ou voltar ao menu
						system("cls");
						printf("Nenhum programa encontrado com letra de indentificação: [%c]", programa);
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
				//É executado quando a opção digitada no menu não corresponde nenhuma das opções disponivel
				printf("\nValor Digitado Incorreto!");
				getch();
				break;
		}	
	}	
}
