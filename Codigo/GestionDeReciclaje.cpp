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
				system("cls"); // limpiar pantalla
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
			
			// registro de materiales y cantidad	
			case 2:
				
				// verificacion de usuario
				if (!esFabricio && !esAlexander) {
                    printf("Primero registre un usuario.\n");
                    break;
                }
                system("cls"); // limpiar pantalla
                printf("Ingrese el tipo de material reciclado (papel, plastico, vidrio, metal): ");
                scanf("%s", material);
                printf("Ingrese la cantidad reciclada: ");
                scanf("%d", &cantidad);
                
				// verificacion de materiales
                if (strcmp(material, "papel") == 0) {
                    if (esFabricio) papelFabricio += cantidad;
                    if (esAlexander) papelAlexander += cantidad;
                } else if (strcmp(material, "plastico") == 0) {
                    if (esFabricio) plasticoFabricio += cantidad;
                    if (esAlexander) plasticoAlexander += cantidad;
                } else if (strcmp(material, "vidrio") == 0) {
                    if (esFabricio) vidrioFabricio += cantidad;
                    if (esAlexander) vidrioAlexander += cantidad;
                } else if (strcmp(material, "metal") == 0) {
                    if (esFabricio) metalFabricio += cantidad;
                    if (esAlexander) metalAlexander += cantidad;
                } else {
                    printf("Material no reconocido. Registro fallido.\n");
                    break;
                }
                
                system("cls");  /*
									limpiar pantalla
									Profe no me acordaba y en el pseudocodigo no me era incomodo.
									Pero a la hora de ir haciendolo era muy incomodo
									 y me acorde entonces lo inclui									
									*/
                if (esFabricio) puntosFabricio += cantidad;  // 1 punto por unidad reciclada
                if (esAlexander) puntosAlexander += cantidad;
                printf("\nUsuario %s ha registrado %d unidades de %s.\n", nombreUsuario, cantidad, material);
                if (esFabricio)
                    printf("\nUsuario %s ha ganado %d puntos. Puntos totales: %d\n", nombreUsuario, cantidad, puntosFabricio);
                if (esAlexander)
                    printf("\nUsuario %s ha ganado %d puntos. Puntos totales: %d\n", nombreUsuario, cantidad, puntosAlexander);
				break;
			
			// estadisticas de reciclaje	
			case 3:
				system("cls");
				if (!esFabricio && !esAlexander) {
                    printf("Primero registre un usuario.\n");
                    break;
                }
                printf("\n===== Estadisticas de Reciclaje de %s =====\n", nombreUsuario);
                if (esFabricio) {
                    printf("Papel reciclado: %d unidades\n", papelFabricio);
                    printf("Plastico reciclado: %d unidades\n", plasticoFabricio);
                    printf("Vidrio reciclado: %d unidades\n", vidrioFabricio);
                    printf("Metal reciclado: %d unidades\n", metalFabricio);
                    printf("Puntos totales acumulados: %d\n", puntosFabricio);
                }
                if (esAlexander) {
                    printf("Papel reciclado: %d unidades\n", papelAlexander);
                    printf("Plastico reciclado: %d unidades\n", plasticoAlexander);
                    printf("Vidrio reciclado: %d unidades\n", vidrioAlexander);
                    printf("Metal reciclado: %d unidades\n", metalAlexander);
                    printf("Puntos totales acumulados: %d\n", puntosAlexander);
                }
                printf("=====================================\n");
				break;
			
			// canjeo de puntos	
			case 4:
				system("cls");
				if (!esFabricio && !esAlexander) {
                    printf("Primero registre un usuario.\n");
                    break;
                }
                printf("Ingrese la cantidad de puntos a canjear: ");
                scanf("%d", &cantidad);

                if (esFabricio && cantidad <= puntosFabricio) {
                    puntosFabricio -= cantidad;
                    printf("Usuario %s ha canjeado %d puntos. Puntos restantes: %d\n", nombreUsuario, cantidad, puntosFabricio);
                } else if (esAlexander && cantidad <= puntosAlexander) {
                    puntosAlexander -= cantidad;
                    printf("Usuario %s ha canjeado %d puntos. Puntos restantes: %d\n", nombreUsuario, cantidad, puntosAlexander);
                } else {
                    printf("Puntos insuficientes para canjear.\n");
                }
				break;
			
			// salida	
			case 5:
				printf("Saliendo del sistema...\n");
				break;
			
			// mensaje de error opcion incorrecta del menu	
			default:
				printf("Opcion no valida, intente nuevamente.\n");
				break;
		}	
    	printf("\n");
    	
	}while(opcion != 5);
	
	return 0;
}
