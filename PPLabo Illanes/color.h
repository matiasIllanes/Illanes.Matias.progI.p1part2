#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

/** \brief
 *
 * \param vec[] eColor
 * \param tam int
 * \return int
 *
 */
int eColor_mostrarColores(eColor vec[], int tam);
/** \brief
 *
 * \param vec[] eColor
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int eColor_cargarDescripcion(eColor vec[], int tam, int id, char descripcion[]);





#endif // COLOR_H_INCLUDED
