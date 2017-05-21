/* DESCRIPCION : guardian del templo
FICHERO        : /d/lad-laurelin/comun/pnj/tiin/lago/guardian.c
CREACION       : 2001 [Alura]
*/

//#include <rooms.h> solo para que pueda perseguir
#include "path.h"
#include <properties.h>


inherit "std/undead";

create() {
  ::create();
 SetStandard("el guardian fantasma","elfo",29,GENERO_MASCULINO);
  SetLong("Ante ti tienes la translucida silueta de lo que fue antanyo un elfo.\n"
  "Ya era viejo cuando murio, pero por las visibles heridas que tiene compruebas\n"
  "que su muerte no fue por causa natural .\n");
  SetIds(({"guardian","no-muerto","espiritu"}));
  SetAds(({"fantasma"}));
  SetRace("no-muerto");
  SetAlign(0);
  SetHands(({({"la mano derecha",0,20}),({"la mano izquierda",0,10})}));
  SetAggressive(1);  // agresivo 1=si, 0=no 2=agresivo con pnj
  InitChats(5,({  "El espiritu grita un lamento que te pone los pelos de punta.\n"}));
  InitAChats(10,({  "Nadie debe entrar aqui, lo siento pero tienes que morir ...!\n",
   "No tocaras el idolo de nuestro amado dios!\n"}));
 }