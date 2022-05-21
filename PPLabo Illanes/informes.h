#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "bicicleta.h"


void listarBicicletasColor(eBicicleta vecBici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo);
void listarBicicletasTipo(eBicicleta vecBici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo);
void cantidadBicicletasMaterial(eBicicleta vecBici[], int tamBici, eTipo tipo[], int tamTipo, eColor color[], int tamColor);
void listarBicisPorTipos(eBicicleta bici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo);
void cantidadBicicletasColorTipo(eBicicleta bici[], int tamBici, eColor color[], int tamColor, eTipo tipo[], int tamTipo);
void colorMasElegido(eBicicleta bici[], int tamBici, eColor color[], int tamColor);


#endif // INFORMES_H_INCLUDED
