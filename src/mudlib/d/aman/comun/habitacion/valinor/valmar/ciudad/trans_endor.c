/****************************************************************************
fichero: trans_endor.c
Autor: Aule
Fecha: 15/10/2012
Descripci�n: Sala de transporte a las futuras zonas de Endor
*/

#include "./path.h"
#include <stdrooms.h>
inherit ROOM;

create () {
  ::create();
  SetIndoors(1);
  SetIntBright(35);
  SetIntSmell("En el aire percibes el olor salino del oc�ano, la resina de frondosos "
  "pinares boreales, la fragancia de los espesos bosques templados, el aroma de las "
  "amplias praderas herbosas, el seco viento arenoso del desierto, la tenue brisa "
  "proveniente de las nieves perpetuas...\n");
  SetIntNoise("Escuchas multitud de sonidos procedentes de cada uno de los portales.\n"
  "Se trata de un conjunto sonoro particular, pues el rumor de las olas de los oc�anos "
  "se une  al susurro del viento en las ramas de los �rboles, los fr�os vientos de alta "
  "monta�a, el goteo de agua en  umbr�as cavernas, el canto de aves marinas, el aullido "
  "de lobos, el desprendimiento de aludes, el traj�n de grandes ciudades y el triste "
  "gemido de vientos fr�os sobre p�ramos olvidados junto con el soplo ardiente "
  "procedente de lejanos desiertos.\n");
  SetIntShort("la sala de los portales");
  SetIntLong("Esta es la antigua sala de los portales, una c�mara alargada y abovedada "
    "con las paredes, techo y suelo hechos de m�rmol negro y pulido.\n"
  "A lo largo de los muros se abren altas arcadas que dan a los distintos lugares de Arda.\n");
  AddDetail(({"portales","portal"}),
  "Altas arcadas de piedra blanca cerradas por intrincadas verjas de plata.\n"
  "M�s all� vislumbras visos de las distintas tierras de Arda.\n");
  AddExit("sim", "./trans_antiguo");
  AddExit("bree", ENCRUCIJADA_BREE);
    AddExit("poney", PONEY_PISADOR);



  }