/***************************************************************************************
 ARCHIVO:	pantano_03.c
 AUTOR:		[k] Korsario
 FECHA:		03-05-1998
 COMENTARIOS:	Pantano de la muerte
 ***************************************************************************************/

#include "path.h"

inherit FLENHAB+"pantano/pantano";

create(){
   ::create();

  fsalidas();
  switch(random(5))
  {
	case 0:	AddItem(FLENPNJ+"pantano/mosquito",REFRESH_DESTRUCT,1+random(2));	break;
	case 1:	AddItem(FLENPNJ+"pantano/arbol_vivo",REFRESH_DESTRUCT,1+random(2));	break;
	case 2:	AddItem(FLENPNJ+"pantano/serpiente",REFRESH_DESTRUCT,1+random(2));	break;
	case 3:	AddItem(FLENPNJ+"pantano/caiman",REFRESH_DESTRUCT,1+random(2));	break;
	default:break;
  }
}

init(){
  ::init();

  call_out("forientarse",1,TP);
}
