#include <iostream>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
	
	// variables
	
	// usuarios predeterminados
	char nombreFabricio[30] = "Fabricio";
    char nombreAlexander[30] = "Alexander";
	
	// materiales por usuario
    int papelFabricio = 0, plasticoFabricio = 0, vidrioFabricio = 0, metalFabricio = 0, puntosFabricio = 0;
    int papelAlexander = 0, plasticoAlexander = 0, vidrioAlexander = 0, metalAlexander = 0, puntosAlexander = 0;
     
	int opcion;
    char nombreUsuario[30];
    char material[30];
    int cantidad;

    int esFabricio = 0;
    int esAlexander = 0;
    
    // menu
    do{
    	printf("\n===== Sistema de Gestion de Reciclaje =====\n");
        printf("1. Registrar Usuario\n");
        printf("2. Registrar Material y Cantidad Reciclada\n");
        printf("3. Generar Estadisticas\n");
        printf("4. Canjear Recompensas\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
		
		// switch para las opciones del menu
		
		switch(opcion){
			
			// registro de usuario
			case 1:
				printf("\nIngrese su nombre de usuario: ");
                scanf("%s", nombreUsuario);
                if (strcmp(nombreUsuario, nombreFabricio) == 0) {
                    esFabricio = 1;
                    esAlexander = 0;
                } else if (strcmp(nombreUsuario, nombreAlexander) == 0) {
                    esFabricio = 0;
                    esAlexander = 1;
                } else {
                    printf("Usuario no reconocido. Intente nuevamente.\n");
                    esFabricio = 0;
                    esAlexander = 0;
                }
				break;
				
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				break;
		}	
    	
    	
    	printf("\n");
	}while(opcion != 5);
	return 0;
}
