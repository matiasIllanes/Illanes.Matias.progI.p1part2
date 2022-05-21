#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"



    int eCliente_mostrar(eCliente vec[], int tam)
    {
            int retorno=0;

            system("cls");
            printf("  *** CLIENTES ***\n");
            printf("-------------------------\n");
            printf("ID            CLIENTE\n");
            for(int i=0; i<tam; i++){

                    printf("%1d        %8s\n", vec[i].id, vec[i].nombre);
                    retorno=1;

            }

            return retorno;
    }

    int eCliente_cargarNombre(eCliente vec[], int tam, int id, char nombre[]){
        int todoOk=0;

        if(vec!= NULL && tam>0 && nombre!= NULL){
            for(int i=0; i< tam; i++){
                if(vec[i].id == id){
                    strcpy(nombre, vec[i].nombre);
                    todoOk=1;
                    break;
                }
            }
        }
        return todoOk;

    }
