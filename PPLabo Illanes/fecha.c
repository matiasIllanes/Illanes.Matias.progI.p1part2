#include "fecha.h"

void eFecha_mostrar(eFecha vec){
    printf("%d/%d/%d \n", vec.dia, vec.mes, vec.anio);
}

eFecha eFecha_pedir(){
    eFecha fecha;
    printf("Ingrese fecha XX/XX/XXXX: \n");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    while(fecha.dia>31 || fecha.dia<1 || fecha.mes<1 || fecha.mes>12 || fecha.anio>2022 || fecha.anio<1950){
        printf("ERROR.Ingrese una fecha valida XX/XX/XXXX : \n");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }
    return fecha;
}
