/***************************************************************************************
 ARCHIVO:	pasillo_00.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo este 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, primer piso, ala este");
  AddExit("norte",RHOEHAB("seri/piso01/centro/escalerae"));
  AddExit("sur",RHOEHAB("seri/piso01/este/pasillo_01"));
  AddExit("este",RHOEHAB("seri/piso01/este/pasillo_11"));
  AddExit("noroeste",RHOEHAB("seri/piso01/centro/pasillo_02"));
  AddExit("suroeste",RHOEHAB("seri/piso01/centro/pasillo_01"));
  AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1+random(2));
}
