#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"



    int eTipo_mostrarTipos(eTipo vec[], int tam)
    {
            int retorno=0;

            system("cls");
            printf("  *** Tipos ***\n");
            printf("-------------------------\n");
            printf("ID            DESCRIPCION\n");
            for(int i=0; i<tam; i++){

                    printf("%1d        %8s\n", vec[i].id, vec[i].descripcion);
                    retorno=1;

            }

            return retorno;
    }

    int eTipo_cargarDescripcion(eTipo vec[], int tam, int id, char descripcion[]){
        int todoOk=0;

        if(vec!= NULL && tam>0 && descripcion!= NULL){
            for(int i=0; i< tam; i++){
                if(vec[i].id == id){
                    strcpy(descripcion, vec[i].descripcion);
                    todoOk=1;
                    break;
                }
            }
        }
        return todoOk;

    }











