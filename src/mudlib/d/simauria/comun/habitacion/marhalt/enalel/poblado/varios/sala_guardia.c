/*

    Nombre      : salaGuardiaEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 17/01/2005
    Descripción : La sala de la guardia
    
*/

#include "path.h"

inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("la sala de guardia");
  SetIntLong(W("Estás en una tosca habitación de paredes oscuras donde la guardia de Enalel descansa.\n"
  "Unos cuantos camastros sirven como lugar de descanso para los cansados guardias.\n"
  "Una escalera comunica hacia arriba con el salón del cuartel y hacia abajo con la carcel.\n"));
  SetIndoors(1);
  SetIntBright(50);
  SetIntNoise("No escuchas nada fuera de lo normal.\n");
  SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
  AddDetail(({"cama","camas","camastro","camastros","catre","catres"}),"son unas camas simples pero cómodas.\n");
  AddExit("arriba",ENALHAB"poblado/varios/cuartel");
  AddExit("abajo",ENALHAB"poblado/varios/carcel");
  AddItem(ENALPNJ"guardias/enalel",REFRESH_DESTRUCT,4);
  AddItem(ENALPNJ"guardias/sargento",REFRESH_DESTRUCT,3);
}