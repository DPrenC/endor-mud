/* ******************************************************
   *                                                    *
   *  Archivo:      estagar.c                           *
   *  Autor:        [a] Articman                        *
   *  Descripci�n:  Estatua de la gargola que cobrara   *
   *                vida con el amuleto                 *
   *  Modificaci�n: 04/02/02 [a] Creaci�n               *
   ******************************************************  */


inherit THING;
#include <properties.h>
#include "path.h"

create() {
::create();
SetShort("una estatua de una g�rgola");
SetLong(W("Es una enorme estatua de una g�rgola sentada en cuclillas. "
"Est� un poco deteriorada por el paso del tiempo pero aun as� puedes "
"distinguir su feroz rostro con grandes colmillos. Tiene unas enormes "
"garras y le falta una de las alas que debi� romperse hace ya mucho "
"tiempo.\n"));
SetIds(({"gargola","g�rgola","q_estatua_gargola"}));
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetWeight(300000); //a ver quien la coge :P
}
