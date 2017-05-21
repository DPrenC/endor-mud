/*
DESCRIPCION  : un gran armario de madera con ropa
FICHERO      : /d/akallab/comun/objeto/mueble/armario_ropa.c
MODIFICACION : 11-03-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include <lock.h>
#include <properties.h>
//inherit "/std/room/items"; // reset() is here
//inherit CONTAINER;
inherit "/obj/chest";

create () {
  object ob;
  int cobre, plata;
  ::create();
  SetShort ("un gran armario");
  SetIntShort ("dentro de un gran armario de madera");
  SetLong ("Un gran armario de madera sin nada de especial.\n");
  SetIntLong ("Estas en el interior de un gran armario dee madera.\n");
  SetPreContent ("Contiene:\n");
  Set(P_NOGET,1);
  SetValue (200);
  SetWeight (10000);
  SetMaxIntWeight (90000); // 90 kg carga
  SetIds(({"mueble","armario"}));
  SetLockState (LOCK_OPEN);

  //objetos que contiene:
  switch(random(100)){
  	case 0..25: //25% vacio
    			break;
    case 26..50:{ //25% duenyo pobre
	            if (random(2)==0) ob=clone_object(PROT("capa"));
                else ob=clone_object(PROT("camisa"));
				ob->move(TO);
				break;
				}
    case 51..80: //30% duenyo normal
                if (random(2)==0) ob=clone_object(PROT("capa"));
                else ob=clone_object(PROT("sombrero"));
                ob->move(TO);
				if (random(2)==0) ob=clone_object(PROT("camisa"));
				else ob=clone_object(PROT("pantalon"));
   			    ob->move(TO);
                cobre=5+random(10);
				plata=random(3);
                ob=clone_object("/obj/money");
                ob->AdjustMoney((["cobre":cobre, "plata":plata]));
                ob->move(TO);
				break;
    case 81..95: //15% duenyo rico
	            if (random(2)==0) ob=clone_object(PROT("capa"));
	            else ob=clone_object(PROT("sombrero"));
	            ob->move(TO);
	     		if (random(2)==0) ob=clone_object(PROT("camisa"));
				else ob=clone_object(PROT("pantalon"));
			    ob->move(TO);
	     		if (random(2)==0) ob=clone_object(PROT("camisa"));
				else ob=clone_object(PROT("capa"));
			    ob->move(TO);
                cobre=10+random(20);
				plata=random(10);
                ob=clone_object("/obj/money");
                ob->AdjustMoney((["cobre":cobre, "plata":plata]));
                ob->move(TO);
     			break;
    case 96..100: //10% duenyo muy rico
	            if (random(2)==0) ob=clone_object(PROT("capa"));
	            else ob=clone_object(PROT("sombrero"));
	            ob->move(TO);
	     		if (random(2)==0) ob=clone_object(PROT("camisa"));
				else ob=clone_object(PROT("pantalon"));
			    ob->move(TO);
	     		if (random(2)==0) ob=clone_object(PROT("camisa"));
				else ob=clone_object(PROT("capa"));
			    ob->move(TO);
                cobre=50+random(20);
				plata=random(50);
                ob=clone_object("/obj/money");
                ob->AdjustMoney((["cobre":cobre, "plata":plata]));
                ob->move(TO);
     			break;
   }
   SetLockState (LOCK_CLOSED);
}
