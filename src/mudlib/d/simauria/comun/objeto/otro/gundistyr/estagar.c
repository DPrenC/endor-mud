/* ******************************************************
   *                                                    *
   *  Archivo:      estagar.c                           *
   *  Autor:        [a] Articman                        *
   *  Descripción:  Estatua de la gargola que cobrara   *
   *                vida con el amuleto                 *
   *  Modificación: 04/02/02 [a] Creación               *
   ******************************************************  */


inherit THING;
#include <properties.h>
#include "path.h"

create() {
::create();
SetShort("una estatua de una gárgola");
SetLong(W("Es una enorme estatua de una gárgola sentada en cuclillas. "
"Está un poco deteriorada por el paso del tiempo pero aun así puedes "
"distinguir su feroz rostro con grandes colmillos. Tiene unas enormes "
"garras y le falta una de las alas que debió romperse hace ya mucho "
"tiempo.\n"));
SetIds(({"gargola","gárgola","q_estatua_gargola"}));
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetWeight(300000); //a ver quien la coge :P
}
