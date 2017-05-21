/******************************************************************************
*        Archivo: pais-bree.h                                              *
*   Descripcion: Archivo de sistema de país de bree (paths y abreviaturas)    *
******************************************************************************/

#ifndef __PAIS-BREE_H
#define __PAIS-BREE_H

/* Nombre del dominio */
#define DOMINIO  "pais-bree"

/* include standard para todos los dominios */
#include <domain.h>    // estructura de dominios standard

//|  PARTE PARTICULAR PARA ESTE DOMINIO                                        |

#define SERVER          DOM_STD "clima" // Servidor de Clima
#define BREE_ROOM        DOM_STD "bree_room"
#define MUEBREE(x)         ("/d/pais-bree/comun/objeto/mueble/" + x)
#define ARMBREE(x)   ("/d/pais-bree/comun/objeto/arma/bree/" + x)
#define PROTBREE(x)   ("/d/pais-bree/comun/objeto/proteccion/bree/" + x)

#define BREE(x)         ("/d/pais-bree/comun/habitacion/bree/" + x)
#define PNJ_BREE(x)   ("/d/pais-bree/comun/pnj/bree/" + x)

 //camino del este en eriador
#define CAMINO_ESTE_ERIADOR1(x)  "/d/eriador/comun/habitacion/caminos/camino_este/" + x
#endif /* __PAIS-BREE_H */