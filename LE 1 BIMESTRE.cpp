#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

	Projeto 1 de Linguagem Estruturda

Turma: 1FID
Materia: LE

ALUNO 1: Rodrigo Lopes Marques
ALUNO 2: Gustavo Otac?lio Jacinto Ramos
ALUNO 3: Henrique Curtis Correa Marques

*/

int a, b, c, d, res;
int n1, n2, n3, bi;
int dia, ano;
int mes;

main(){
	
	printf("Digite o DIA que vc nasceu: ");
	scanf("%d", &dia);
	
	printf("Digite o MES que vc nasceu ( 1 a 12 ): ");
	scanf("%d", &mes);
	
	printf("Digite o ANO que vc nasceu: ");
	scanf("%d", &ano);
	
	a = ano-1900;
	
	n1 = ano%4;
	n2 = ano%100;
	n3 = ano%400;
	
	if( n1 == 0){
		if( n2 == 0){
			if( n3 == 0){
				bi++;
			}
		}else{
			bi++;
		}
	}else{
		bi = 0;
	}
	
	if( (bi == 1) && ((mes == 1) || (mes == 2))){
			b = (a/4)-1;
	}else{
		b = (a/4);
	}
	
	if(mes==1){
		c = 0;
	}else{
		if(mes==2){
			c = 3;
		}else{
			if(mes==3){
				c = 3;
			}else{
				if(mes==4){
					c = 6;
				}else{
					if(mes==5){
						c = 1;
					}else{
						if(mes==6){
							c = 4;
						}else{
							if(mes==7){
								c = 6;
							}else{
								if(mes==8){
									c = 2;
								}else{
									if(mes==9){
										c = 5;
									}else{
										if(mes==10){
											c = 0;
										}else{
											if(mes==11){
												c = 3;
											}else{
												if(mes==12){
													c = 5;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	d = dia-1;
	
	res = (a+b+c+d)%7;
	
	if( res == 0 ){
		printf("\nVc nasceu na Segunda");
	}else{
		if( res == 1 ){
			printf("\nVc nasceu na Terca");
		}else{
			if( res == 2 ){
				printf("\nVc nasceu na Quarta");
			}else{
				if( res == 3 ){
					printf("\nVc nasceu na Quinta");
				}else{
					if( res == 4 ){
						printf("\nVc nasceu na Sexta");
					}else{
						if( res == 5 ){
							printf("\nVc nasceu no Sabado");
						}else{
							if( res == 6 ){
								printf("\nVc nasceu no Domingo");
							}
						}
					}
				}
			}
		}
	}
	
	if(bi == 0){
		printf("\nNao eh ano Bissexto\n\n");
	}else{
		printf("\nEh ano Bissexto\n\n");
	}
		
}
