#include "informes.h"

void listarBicicletasColor(eBicicleta vecBici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int idColor;
    int indice=-1;
    int flag = 0;

    system("cls");
    eColor_mostrarColores(color, tamColor);
    getInt(&idColor, "Ingrese ID de color: ", "ERROR. ", 5000, 5004);

    for(int i=0; i<tamColor; i++)
    {
        if(color[i].id==idColor)
        {
            indice = i;
            break;
        }
    }
    printf("                      \n*** Listado de Bicicletas segun color %s  ***\n", color[indice].nombreColor);
    printf("****************************************************************************\n");
    printf("ID      Marca              Rodado      Material       Tipo             Color\n");
    printf("****************************************************************************\n");
    for(int i=0; i<tamBici; i++)
    {
        if(vecBici[i].isEmpty==0 && vecBici[i].idColor == idColor)
        {

            eBicicleta_listarFila(vecBici[i], tipo, tamTipo, color, tamColor);
            flag = 1;
        }

    }
    if(flag==0)
    {
        printf("No hay bicicletas de color %s\n\n", color[indice].nombreColor);
    }

}

void listarBicicletasTipo(eBicicleta vecBici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int idTipo;
    int indice=-1;
    int flag = 0;

    system("cls");
    eTipo_mostrarTipos(tipo, tamTipo);
    getInt(&idTipo, "Ingrese ID de tipo: ", "ERROR. ", 1000, 1003);

    for(int i=0; i<tamTipo; i++)
    {
        if(tipo[i].id==idTipo)
        {
            indice = i;
            break;
        }
    }
    printf("                      \n*** Listado de Bicicletas segun tipo %s  ***\n", tipo[indice].descripcion);
    printf("****************************************************************************\n");
    printf("ID      Marca              Rodado      Material       Tipo             Color\n");
    printf("****************************************************************************\n");
    for(int i=0; i<tamBici; i++)
    {
        if(vecBici[i].isEmpty==0 && vecBici[i].idTipo == idTipo)
        {

            eBicicleta_listarFila(vecBici[i], tipo, tamTipo, color, tamColor);
            flag = 1;
        }

    }
    if(flag==0)
    {
        printf("No hay bicicletas de tipo %s\n\n", tipo[indice].descripcion);
    }

}





void cantidadBicicletasMaterial(eBicicleta vecBici[], int tamBici, eTipo tipo[], int tamTipo, eColor color[], int tamColor)
{

    int contA = 0;
    int contC = 0;



    for(int i = 0; i < tamBici; i++)
    {
        if(vecBici[i].isEmpty == 0 && vecBici[i].material == 'a')
        {
            contA++;
        }
        else if(vecBici[i].isEmpty == 0 && vecBici[i].material == 'c')
        {
            contC++;

        }
    }
    printf("\n");

    if(contC > contA)
    {
        printf("\nHay mas bicicletas de Carbono (%d)\n", contC);
    }
    else if(contC == contA)
    {
        printf("\nHay igual cantidad de bicicletas de carbono y aluminio: %d\n", contA);
    }
    else
    {
        printf("\nHay mas bicicletas de Aluminio (%d)\n", contA);
    }


}


void listarBicisPorTipos(eBicicleta bici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int flag;
    system("cls");

    printf("      \n*** Listado de Bicicletas por tipo ***\n");
    for(int i=0; i<tamTipo; i++)
    {
        flag=1;
        printf("Tipo: %s\n\n", tipo[i].descripcion);

        printf("****************************************************************************\n");
        printf("ID      Marca              Rodado      Material       Tipo             Color\n");
        printf("****************************************************************************\n");
        for(int j=0; j<tamBici; j++)
        {
            if(bici[j].isEmpty==0 && bici[j].idTipo == tipo[i].id)
            {
                eBicicleta_listarFila(bici[i], tipo, tamTipo, color, tamColor);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay bicicletas de este tipo.\n");
        }
        printf("\n");
    }
}


void cantidadBicicletasColorTipo(eBicicleta bici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int idColor;
    int idTipo;
    int cont=0;

    system("cls");
    printf("    Contador bicicletas de mismo color y tipo\n");
    eColor_mostrarColores(color, tamColor);
    getInt(&idColor, "Ingrese ID de color: ", "ERROR. ", 5000, 5004);


    eTipo_mostrarTipos(tipo, tamTipo);
    getInt(&idTipo, "Ingrese ID de tipo: ", "ERROR. ", 1000, 1003);

    for(int i=0; i<tamBici; i++)
    {
        if(bici[i].idColor==idColor && bici[i].idTipo==idTipo)
        {
            cont++;
        }
    }

    printf("\n Hay %d bicicletas del color y tipo seleccionado\n", cont);
}


void colorMasElegido(eBicicleta bici[], int tamBici, eColor color[], int tamColor)
{

    int acum;
    int aux[tamColor];
    int mayor;
    int flag=0;

    for(int i=0; i<tamColor; i++)
    {
        acum=0;

        for(int j=0; j<tamBici; j++)
        {
            if(bici[j].isEmpty==0 && bici[j].idColor == color[i].id)
            {
                acum++;
            }
        }
        aux[i]=acum;
    }

    for (int i =0; i<tamColor; i++)
    {
        if(flag==0 || aux[i]>mayor)
        {
            mayor= aux[i];
            flag=1;
        }
    }
    printf("El color mas elegido es: ");
    for (int i =0; i<tamColor; i++)
    {
        if(mayor==aux[i])
        {
            printf("%s ", color[i].nombreColor);
        }
    }
    printf("\n\n");
}




void coloresMasElegidos(eBicicleta bici[], int tamBici, eTipo tipo[], int tamTipo, eColor color[], int tamColor)
{

    int contadores[5] = {0};
    int mayorCantColores;

    printf("  *** Colores mas elegidos***\n");
    printf("---------------------------------\n");
    for(int i = 0; i < tamColor; i++)
    {
        for(int j = 0; j < tamBici; j++)
        {
            if(bici[j].idColor == color[i].id && bici[j].isEmpty == 0)
            {
                contadores[i]++;
            }
        }
    }

    for(int i = 0; i < tamColor; i++)
    {
        if(i == 0 || mayorCantColores < contadores[i])
        {
            mayorCantColores = contadores[i];
        }
    }

    for(int i = 0; i < tamColor; i++)
    {
        if(contadores[i] == mayorCantColores)
        {
            printf("El color mas elegido es: %s\n", color[i].nombreColor);
        }
    }
    printf("\n\n");

}
