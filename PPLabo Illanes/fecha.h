#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct{
        int dia;
        int mes;
        int anio;
    }eFecha;


void eFecha_mostrar(eFecha vec);

eFecha eFecha_pedir();



#endif // FECHA_H_INCLUDED
