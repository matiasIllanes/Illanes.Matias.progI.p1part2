#include "trabajo.h"

int eTrabajo_alta(eTrabajo trabajo[], int tamTrab, eBicicleta bici[], int tamBici, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicio[], int tamServ, int* pNextId)
{

    int todoOk=0;
    int index;
    int idBici;
    int idServicio;
    eTrabajo nuevoTrabajo;


    if(trabajo != NULL && bici != NULL && servicio != NULL && tipo != NULL && color != NULL && pNextId != NULL && tamBici>0 && tamColor>0 && tamServ>0 && tamTipo>0 && tamTrab>0)
    {
        system("cls");
        printf("    *** Alta Trabajo ***\n");
        index = eTrabajo_buscarLibre(trabajo, tamTrab);
        if(index>=0)
        {

            eBicicleta_listar(bici, tamBici, tipo, tamTipo, color, tamColor);
            idBici = getEntero("Ingrese ID de bicicleta: ");
            while(eBicicleta_buscarBicicleta(bici, tamBici, idBici)==-1)
            {
                idBici = getEntero("No existe Bicicleta correspondiente al ID seleccionado. Reingrese ID: ");
            }
            nuevoTrabajo.idBicicleta=idBici;

            printf("\n*****************************************\n");

            eServicio_mostrarServicios(servicio, tamServ);
            getInt(&idServicio, "Ingrese ID de servicio: ", "ERROR. ", 20000, 20003);
            nuevoTrabajo.idServicio=idServicio;

            printf("\n*****************************************\n");


            printf("Ingrese fecha dd/mm/aaaa: \n");
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            while(nuevoTrabajo.fecha.dia>31 || nuevoTrabajo.fecha.dia<1 || nuevoTrabajo.fecha.mes<1 || nuevoTrabajo.fecha.mes>12 || nuevoTrabajo.fecha.anio>2022 || nuevoTrabajo.fecha.anio<1950)
            {
                printf("ERROR.Ingrese una fecha valida dd/mm/aaaa : \n");
                scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            }


            nuevoTrabajo.isEmpty=0;
            nuevoTrabajo.id = *pNextId;
            (*pNextId)++;
            trabajo[index] = nuevoTrabajo;

            todoOk = 1;

        }
        else
        {
            printf("No hay mas lugar para trabajos \n");
        }

    }
    return todoOk;
}


void eTrabajo_inicializarVec(eTrabajo vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}



int eTrabajo_buscarLibre(eTrabajo vec[], int tam)
{
    int index=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            index=i;
        }
    }
    return index;
}


void eTrabajo_listarFila (eTrabajo trabajo, eServicio servicio[], int tamServ)
{
    char descripcionServicio[25];

    if(eServicio_cargarDescripcion(servicio, tamServ, trabajo.idServicio, descripcionServicio) == 1)
    {
        printf("%d       %d      %20s  %02d/%02d/%04d \n", trabajo.id
               , trabajo.idBicicleta
               , descripcionServicio
               , trabajo.fecha.dia
               , trabajo.fecha.mes
               , trabajo.fecha.anio);
    }

}

int eTrabajo_listar (eTrabajo trabajo[], int tamTrab, eServicio servicio[], int tamServ)
{

    int retorno=0;

    system("cls");
    printf("                      *** Listado de Bicicletas   ***\n");
    printf("****************************************************************************\n");
    printf("ID TRABAJO     ID BICICLETA             SERVICIO                  FECHA\n");
    printf("****************************************************************************\n");

    for(int i=0; i<tamTrab; i++)
    {
        if(trabajo[i].isEmpty==0)
        {
            eTrabajo_listarFila(trabajo[i], servicio, tamServ);
            retorno=1;
        }
    }
    return retorno;
}





