/* ****************************************************************
   *                                                              *
   *  Archivo:      manuscrito.c                                  *
   *  Autor:        [a] Articman                                  *
   *  Descripción:  Objeto para dar y completar quest.            *
   *                Se consigue pidiendolo :P                     *
   *  Modificación: 31/01/02 [a] Creación                         *
   ****************************************************************  */


inherit THING;
#include <properties.h>
#include "path.h"

create() {
::create();
SetShort("un montón de papeles");
SetLong(W("Son un montón de papeles unidos por una fina cuerda para evitar "
"que se extravíen. Echas un vistazo a lo que pone y ves notas y dibujos "
"sobre algunos antiguos monumentos. Están bastante sucios, pero se podría "
"entender lo que pone sino fuera por la mala caligrafía.\n"));
SetIds(({"papeles","manuscrito","montón de papeles","monton de papeles"
,"monton papeles","montón papeles","q_manuscritos_gargola"}));
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_PLURAL);
SetWeight(50);
Set(P_CANT_STEAL,1);
}
