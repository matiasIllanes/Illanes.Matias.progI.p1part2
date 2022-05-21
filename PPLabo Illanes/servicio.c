#include "servicio.h"



int eServicio_mostrarServicios(eServicio vec[], int tam)
{
    int retorno=0;
        system("cls");
        printf("             *** SERVICIOS ***\n");
        printf("-----------------------------------------\n");
        printf("ID        DESCRIPCION           PRECIO\n");
        printf("-----------------------------------------\n");
        for(int i=0; i<tam; i++)
        {

            printf("%1d       %8s      %12.2f\n", vec[i].id, vec[i].descripcion, vec[i].precio);
            retorno=1;

        }

    return retorno;
}


int eServicio_cargarDescripcion(eServicio vec[], int tam, int id, char descripcion[])
{
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
