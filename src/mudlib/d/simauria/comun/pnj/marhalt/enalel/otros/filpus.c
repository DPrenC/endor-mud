/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
 
  SetStandard("Filpus","humano",12+random(3),GENERO_MASCULINO);
  SetShort("Filpus el banquero");
  SetLong(W("Es un anciano humano nacido en Enalel. Viste las ropas del gremio "
  "de banqueros. Parece estar siempre en una constante concentración.\n"));
  SetIds(({"humano","banquero","hombre","filpus","Filpus","anciano","viejo"}));
  Set(P_CANT_LURE,1);
  SetAlign(100);
  InitChats(3,({
    "Filpus saca unos papeles del escritorio y comienza a calcular.\n",
    "Filpus mira a la calle un instante y luego sigue con su tarea.\n",
    "Filpus dice: 'Vaya, parece que pronto empezará la recaudación de impuestos en Simauria'\n",
    "Filpus examina monedas comprobando su autenticidad.\n"}));
}
