#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"



    int eColor_mostrarColores(eColor vec[], int tam){
            int retorno=0;

            system("cls");
            printf("  *** COLORES ***\n");
            printf("-------------------------\n");
            printf("ID            Color\n");
            for(int i=0; i<tam; i++){

                    printf("%1d        %8s\n", vec[i].id, vec[i].nombreColor);
                    retorno=1;

            }

            return retorno;
    }

    int eColor_cargarDescripcion(eColor vec[], int tam, int id, char descripcion[]){
        int todoOk=0;

        if(vec!= NULL && tam>0 && descripcion!= NULL){
            for(int i=0; i< tam; i++){
                if(vec[i].id == id){
                    strcpy(descripcion, vec[i].nombreColor);
                    todoOk=1;
                    break;
                }
            }
        }
        return todoOk;

    }







