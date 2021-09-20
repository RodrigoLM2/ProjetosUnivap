#include <stdio.h>
#include <stdlib.h>
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

int i, sjf[10], opc, end, x, z, menor, qtde, aux, index;

main(){
	
	// Essa linha de comando faz o programa aceitar acentuação nos printf
	setlocale(LC_ALL,"Portuguese");
	
	while(end==0){

		system("cls");
		z=1;
		printf("================================\n");
		printf("   SIMULADOR DO ALGORITIMO \nESCALONADOR SHORTEST JOB FIRST\n");
		printf("================================\n\n");
		
		printf("MENU: \n");
		//Opções do MENU
		printf("[1] - Inserir Novo Processo\n");
		printf("[2] - Processar Processo\n");
		printf("[3] - Ordenar Processos\n");
		printf("[4] - Encerrar programa\n");

		// Usuario decide qual opção prosseguir 
		printf("\nSelecione a opção digitando o NÚMERO correspondente:\n[   ]\b\b\b");
		scanf("%d", &opc);		
		
		// de acordo com qual opção escolhida o switch leva ao case especifico
		switch (opc){
			
			case 1:
				while(z==1){
					
					system("cls");
					
					printf("=-=-=-=-=-=-=-=-=-=-=\n");
					printf("Inserir Novo Processo\n");
					printf("=-=-=-=-=-=-=-=-=-=-=\n");
					
					printf("\nInsira o tamanho de um novo processo:\n");
					scanf("%d", &sjf[i]);
					i++;					
						 
					printf("Deseja inserir outro processo? 1 -> SIM / 2 -> VOLTAR MENU\n");
					scanf("%d", &z);
 
				}
				
				break;
				
			case 2:
				system("cls");
				
				printf("=-=-=-=-=-=-=-=-=-\n");
				printf("Processar Processo\n");
				printf("=-=-=-=-=-=-=-=-=-\n\n");
					
				for(x=0; x<=9; x++){
					if(sjf[x] != 0){
						printf("[%d] ", sjf[x]);
					}					
				}
				
				menor = sjf[0];
				for(x=0; x<=i-1; x++){
					
					if(sjf[x] < menor){
						menor = sjf[x];
						index = x;
					}
				}
					
				printf("\n\n[%d] foi retirado\n\n", sjf[index]);
				i--;
				sjf[index] = 0;
						
				for(x=index; x<=8; x++){
					sjf[x] = sjf[x+1];
				}		
				sjf[9] = 0;
					
				for(x=0; x<=9; x++){
					if(sjf[x] != 0){
						printf("[%d] ", sjf[x]);
					}				
				}
				getch();
					
				break;
				
			case 3:
				system("cls");
				
				printf("=-=-=-=-=-=-=-=-=\n");
				printf("Ordenar Processos\n");
				printf("=-=-=-=-=-=-=-=-=\n\n");
				
				qtde = 10;
				while(qtde>1){
			
					for (x = 0; x <=qtde-2; x++){
						
						if (sjf[x] > sjf[x+1]){
							
							aux = sjf[x];
				       		sjf[x] = sjf[x+1];
				      		sjf[x+1] = aux;
				   		}
				  	}
				  	qtde--;
				}
				printf("Processos foram ordenados:\n\n");
				for(x=0; x<=9; x++){
					if(sjf[x] != 0){
						printf("[%d] ", sjf[x]);
					}				
				}
				
				getch();
				break;
				
			case 4:
				end++;
				printf("\nPrograma Finalizado.");
				break;
				
		}
	}	
}
