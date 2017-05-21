/*  DESCRIPCION    : Monje fantasma
FICHERO        : /d/lad-laurelin/pnj/lago/monjef.c
CREACION       : 24-11-98 [Alura]
U.MODIFICACION :
*/
#include <rooms.h> // solo para que pueda perseguir
#include <moving.h>
#include <properties.h>
#include <combat.h>
#include "path.h"
#include <properties.h>


inherit "std/undead";

private string mensaje;

string accion_monje(){
  string msg;
  int num;
  num=random(7);
  switch(num) {
    case 0: msg  =  "Ves un monje putrefacto limpiando afanosamente la habitacion con una escoba.\n"; break;
    case 1: msg =  "Un monje muerto te mira y vuelve a su faena, como si no le importaras.\n"; break;
    case 2: msg =  "Un tipo que huele mal con sotana esta leyendo un libro. No te presta atencion\n"; break;
    case 3: msg = "Es un humano bastante demacrado que lleva un habito hecho jirones.\n"; break;
    case 4: msg = "El tiempo lo ha tratado mal, esta hecho un asco. Parece mas muerto que vivo.\n"; break;
    case 5: msg = "Alguien lo debio traer de la muerte para continuar su vida anterior.\n"; break;
    default: return "Es un muerto viviente.\n";
  }
  return msg;
}

create() {
   ::create();
 seteuid(getuid());
   mensaje=accion_monje();
   SetStandard("monje fantasma","no-muerto",27,GENDER_MALE);
   SetShort("un monje no-muerto");
   SetLong(mensaje);
   SetIds(({"fantasma","muerto","monje"}));   //identificativos
   SetAds(({"el","un","demacrado"}));   //adjetivos feo, alto...
   SetAlign(10);
   SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
   SetHands(({({"mano izquierda",0,1}),({"mano derecha",1,3})}));
   SetAggressive(0);
   AddItem("/d/lad-laurelin/comun/objeto/arma/baston",REFRESH_REMOVE,SF(wieldme));

   AddItem("/d/lad-laurelin/comun/objeto/proteccion/cruz_plata",REFRESH_REMOVE,SF(wearme));
}