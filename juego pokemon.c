#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#define N 20

typedef struct{

	int vida;
	int fuerza;
	int mana;

}player1;


typedef struct{

	int vida;
	int fuerza;
	int mana;

}player2;
int elegir();
void seleccion(int opcion,char *nombre);
void select(int opcion);
void batalla(char *nombre,char *nombre2);

player1 poke1;
player2 poke2;
char *nombre,*nombre2;

int main(){
	
	int c;
	
	c = elegir();
	seleccion(c,nombre);
	select(c);
	batalla(nombre,nombre2);
	//cambio();
	
	return 0;
	system("pause");
}


int elegir(){
	
	int n,opc,opcion,a,aux;
	opcion = 0;
	printf("Elige un pokemon\n");
	printf("1.Piplup\n");
	printf("2.Chimchar\n" );
	printf("3.Turtwig\n");
	scanf("%i",&opcion);

	srand(time(NULL));
	

	
	nombre = (char *)malloc((N+1)*sizeof(char));
	nombre2 = (char *)malloc((N+1)*sizeof(char));	
		
	switch(opcion){
		
		case 1:{
			strcpy(nombre,"Piplup");
			
			break;
		}
		
		case 2:{
			strcpy(nombre,"Chimchar");
				
			break;
		}
		
		case 3:{
			strcpy(nombre,"Turtwig");
		
			break;
		}
			
		default:printf("Opcion no disponible\n");
		
	}
		 
	opc = 1 + rand() %  ((3+1)-1);	
		
		switch(opc){
		
			case 1:{
				strcpy(nombre2,"Piplup");
				
				break;
			}
		
			case 2:{
				strcpy(nombre2,"Chimchar");
				
				break;
			}
		
			case 3:{
				strcpy(nombre2,"Turtwig");
				
				break;
			}		
		
	}

	return opcion;
	
}


void seleccion(int opcion,char *nombre){
	
	poke1.vida = 500;
	poke1.mana = 500;
	poke1.fuerza =200;
	
	
	
	switch(opcion){
		case 1:
			printf("\nTu elegiste a Piplup\nHealth:%i\nEnergia:%i\nFuerza:%i\n",poke1.vida,poke1.mana,poke1.fuerza);
			strcpy(nombre,"Piplup");
		break;
		
		case 2:
			printf("\nTu elegiste a Chimchar\nHealth:%i\nEnergia:%i\nFuerza:%i\n",poke1.vida,poke1.mana,poke1.fuerza);
			strcpy(nombre,"Chimchar");
		break;
	
		case 3:
			printf("\nTu elegiste a Turtwig \nHealth:%i\nEnergia:%i\nFuerza:%i\n",poke1.vida,poke1.mana,poke1.fuerza);
			strcpy(nombre,"Turtwig");
		
		break;
		default:printf("No esta esa opcion");
	}
}

void select(int opcion){
	
	int opc;
	
	poke2.vida = 500;
	poke2.mana = 500;
	poke2.fuerza =200;
			
	srand(time(NULL));
	
	opcion =  1 + rand() %  ((3+1)-1);
		
	
	switch(opcion){
	
		
		

		case 1:
			printf("\nTu oponente eligio a Piplup\nHealth:%i\nEnergia:%i\nFuerza:%i\n",poke2.vida,poke2.mana,poke2.fuerza);
			printf("\n");
		break;
		
		case 2:
			printf("\nTu oponente eligio a Chimchar\nHealth:%i\nEnergia:%i\nFuerza:%i\n",poke2.vida,poke2.mana,poke2.fuerza);
			printf("\n");
		break;
	
		case 3:
			printf("\nTu oponente eligio a Turtwig \nHealth:%i\nEnergia:%i\nFuerza:%i\n",poke2.vida,poke2.mana,poke2.fuerza);
			printf("\n");
		break;
		
	
		
	}


}



void batalla(char *nombre,char *nombre2){

	int op,i,damage,salud,x,energy;

	damage = 0;
	
	poke1.vida = 500;
	poke1.mana = 500;
	poke1.fuerza =200;
	
	poke2.vida = 500;
	poke2.mana = 500;
	poke2.fuerza =200;
	
	srand(time(NULL));

	

	do{
		do{
			printf("1.COMBATE\n");
			printf("2.BOLSA\n");
			scanf("%i",&x);
			
			
			
			if(x == 1){
				
				printf("\nSeleccione la accion\n");			
				printf("\n1.Atacar\n2.Pasar\n3.Salir\n");
				scanf("%i",&op);
				printf("\n");
				
			switch(op){
					
				case 1:{
					
					damage = poke1.fuerza *(rand () % 5);						
					printf("%s ataca\n",nombre);
					printf("Damage %i\n",poke1.fuerza);
					poke2.vida -= poke1.fuerza; 		
					if(poke2.vida < 0){
						printf("Health:0");
					}
					else{
					printf("Health:%i\n",poke2.vida);
					}
				break;
				}	
				case 2:{
						
					printf("%s pasa el turno",nombre);
						
				break;
				}	
					
				case 3:{
						
					printf("Has avandonado la batalla\n");
					exit(1);
				break;
				}	
			
			
			
			
			}
			
		}
		else if(x == 2){
			
			printf("\nSeleccione la accion\n");			
			printf("\n1.Sanar\n2.Cambiar pokemon\n3.Usar fruta de mana\n");
			scanf("%i",&op);
			printf("\n");
			
			switch(op){
				case 1:{
					
					if(poke1.mana > 0){
						salud = poke1.vida + (rand() % ((100+1)-1));	
						printf("\n");
						
						printf("%s utiliza sanacion\n",nombre);
						poke1.vida += salud; 		
						poke1.mana-=salud;
						printf("Health:%i\n",poke1.vida);
						printf("Energia:%i\n",poke1.mana);
						printf("\n");
							
						}
						else{
							printf("No tienes suficiente mana\n");
						
						}	
					
					break;
				}
				
				
				case 2:{
					
					int opcion = 0;
					printf("Elige un pokemon\n");
					printf("1.Piplup\n");
					printf("2.Chimchar\n" );
					printf("3.Turtwig\n");
					scanf("%i",&opcion);
					
					seleccion(opcion,nombre);
					
					
					break;
				}
				
				case 3:{
					
						energy = poke1.mana + (rand() %  ((100+1)-1));	
						//printf("\n");
						printf("%s utiliza fruta de mana\n",nombre);
						poke1.mana+= energy;
						printf("Energia:%i\n",poke1.mana);
						printf("\n");
							 + rand() %  ((3+1)-1);	
					
					break;
				}
				
				
				
				
			}
		
		
		}
	
		
		}while(op < 1 || op > 2);
		
	
				
		printf("\n");
			
		 if(poke2.vida < 0){
			printf("VICTORIA\n");
				
		}
		
		 
		else{
			printf("Para terminar turno <pulse una tecla>\n");
			getch();
			printf("\n");
			printf("Turno del oponente\n");	
			printf("\n");
			damage  = poke2.fuerza * (rand() % 3);	
			printf("%s ataca\n",nombre2);
			printf("Damage %i\n",damage);
			poke1.vida -= damage; 	
			if(poke1.vida < 0){
				printf("Health : 0");
			}
			else{
				printf("Health:%i\n",poke1.vida);
			}
		
		printf("\n");
		
		}
				
	}while(poke2.vida > 0 && poke1.vida > 0 );
	
		 if(poke1.vida < 0){
			
			printf("DERROTA\n");
			
		}
	
}


