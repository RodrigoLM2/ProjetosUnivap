#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int n, i, key, x;
char c, msg[50];

main()
{
	
	do{
		
		system("cls");
		printf("=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Criptografia de Cesar\n");	
		printf("=-=-=-=-=-=-=-=-=-=-=\n\n");
		
		printf("[1] - Criptografar um texto\n");
		printf("[2] - Descriptografar um texto\n");
		printf("[0] - Encerrar\n\n");
		
		printf("-> ");
		scanf("%d", &x);
		
		switch(x){
			
			case 1:
				
				system("cls");
				
				printf("Texto: ");
				fflush(stdin);
			    gets(msg);
			    
			    printf("\nKey: ");
			    scanf("%d", &key);
			    
			    printf("\nTexto Criptografado: ");
			    n = strlen(msg);
			
			    for (i = 0; i < n; i++)
			    {
					if(isalpha(msg[i]) == 0)
			        {
			        	c = msg[i];
			            printf("%c", c);
			        }
			        else if(islower(msg[i]) == 0)
			        {
			            c = ((msg[i] - 65) + key) % 26;
			            printf("%c", c + 65);
			        }
			        else if(isupper(msg[i]) == 0)
			        {
			            c = ((msg[i] - 97) + key) % 26;
			            printf("%c", c + 97);
			        }
			    }
			    
			    printf("\n\n");
			    system("pause");
				break;
				
			case 2:
				
				system("cls");
				
				printf("Texto: ");
				fflush(stdin);
			    gets(msg);
			    
			    printf("\nKey: ");
			    scanf("%d", &key);
			    
			    printf("\nTexto Descriptografado: ");
			    n = strlen(msg);
			
			    for (i = 0; i < n; i++)
			    {
			        if(isalpha(msg[i]) == 0)
			        {
			        	c = msg[i];
			            printf("%c", c);
			        }
			        else if(islower(msg[i]) == 0)
			        {
			            c = ((msg[i] - 65) - key) % 26;
			            printf("%c", c + 65);
			        }
			        else if(isupper(msg[i]) == 0)
			        {
			            c = ((msg[i] - 97) - key) % 26;
			            printf("%c", c + 97);
			        }
			    }
			    printf("\n\n");
			    system("pause");
				break;	
			
			case 0:
				break;		
			
			
			default:
				x = 1;
				break;			
		}
		
	}while (x > 0);
	
}
