/* ****************************************************************
   *                                                              *
   *  Archivo:      manuscrito.c                                  *
   *  Autor:        [a] Articman                                  *
   *  Descripci�n:  Objeto para dar y completar quest.            *
   *                Se consigue pidiendolo :P                     *
   *  Modificaci�n: 31/01/02 [a] Creaci�n                         *
   ****************************************************************  */


inherit THING;
#include <properties.h>
#include "path.h"

create() {
::create();
SetShort("un mont�n de papeles");
SetLong(W("Son un mont�n de papeles unidos por una fina cuerda para evitar "
"que se extrav�en. Echas un vistazo a lo que pone y ves notas y dibujos "
"sobre algunos antiguos monumentos. Est�n bastante sucios, pero se podr�a "
"entender lo que pone sino fuera por la mala caligraf�a.\n"));
SetIds(({"papeles","manuscrito","mont�n de papeles","monton de papeles"
,"monton papeles","mont�n papeles","q_manuscritos_gargola"}));
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_PLURAL);
SetWeight(50);
Set(P_CANT_STEAL,1);
}
