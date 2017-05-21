/******************************************************************************
*                                                                             *
*        Archivo: eriador.h                                              *
*   Descripcion: Archivo de sistema de eriador (paths y abreviaturas)    *
*                                                                             *
******************************************************************************/

#ifndef __ERIADOR_H
#define __ERIADOR_H

/* Nombre del dominio */
#define DOMINIO  "eriador"

/* include standard para todos los dominios */
#include <domain.h>    // estructura de dominios standard

//|  PARTE PARTICULAR PARA ESTE DOMINIO                                        |

#define SERVER          DOM_STD "clima" // Servidor de Clima
// ----- Standards Globales --------------------------------------------------

#define CAMINOS         "/d/eriador/comun/habitacion/caminos/"
#define CAMINO_ESTE_BREE(x)  "/d/pais-bree/comun/habitacion/caminos/" + x
#define CAMINO_ESTE_ERIADOR1(x)  "/d/eriador/comun/habitacion/caminos/camino_este/" + x
#define CAMINO_ESTE_ERIADOR(x)  "/d/eriador/comun/habitacion/caminos/camino_este/" + x


#endif /* __ERIADOR_H */