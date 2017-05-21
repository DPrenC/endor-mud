/*
DESCRIPCION  : un gran armario de madera con armas
FICHERO      : /d/akallab/comun/objeto/mueble/armario_armas.c
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
  ::create();
  SetShort ("un armario armería");
  SetIntShort ("dentro de un gran armario de madera");
  SetLong ("Un gran armario de madera donde se guardan armas.\n");
  SetIntLong ("Estas en el interior de un gran armario de madera.\n");
  SetPreContent ("Contiene:\n");
  SetValue (200);
  SetWeight (10000); // 10 kilos
  Set(P_NOGET, 1);
  SetMaxIntWeight (90000);// 90 kg carga
  SetIds(({"mueble","armario","armeria","armería"}));
  SetLockState (LOCK_OPEN);

  //objetos que contiene:
  switch(random(100)){
  	case 0..25: //25% vacio
    			break;
    case 26..50:{ //25% duenyo pobre
	            if (random(2)==0) ob=clone_object(PROT("casco"));
                else ob=clone_object(PROT("camisa_cuero"));
				ob->move(TO);
				ob=clone_object(ARMA("daga"));
    			ob->move(TO);
				break;
				}
    case 51..80: //30% duenyo normal
	            if (random(2)==0) ob=clone_object(PROT("cota_malla"));
                else ob=clone_object(PROT("camisa_cuero"));
				ob->move(TO);
	            if (random(2)==0) ob=clone_object(ARMA("espada_corta"));
                else ob=clone_object(ARMA("azagaya"));
				ob->move(TO);
				ob=clone_object(ARMA("daga"));
    			ob->move(TO);
				break;
    case 81..95: //15% duenyo rico
	            if (random(2)==0) ob=clone_object(PROT("casco"));
	            else ob=clone_object(PROT("escudo"));
	     		ob->move(TO);
	            if (random(2)==0) ob=clone_object(PROT("cota_malla"));
                else ob=clone_object(PROT("camisa_cuero"));
				ob->move(TO);
	            if (random(2)==0) ob=clone_object(ARMA("espada_corta"));
                else ob=clone_object(ARMA("azagaya"));
				ob->move(TO);
				ob=clone_object(ARMA("daga"));
    			ob->move(TO);
     			break;
    case 96..100: //10% duenyo muy rico
	            if (random(2)==0) ob=clone_object(PROT("casco"));
	            else ob=clone_object(PROT("escudo"));
	     		ob->move(TO);
	            if (random(2)==0) ob=clone_object(PROT("cota_malla"));
                else ob=clone_object(PROT("camisa_cuero"));
				ob->move(TO);
	            if (random(2)==0) ob=clone_object(ARMA("espada_corta"));
                else ob=clone_object(ARMA("azagaya"));
				ob->move(TO);
				ob=clone_object(ARMA("katana"));
				ob->move(TO);
				ob=clone_object(ARMA("daga"));
    			ob->move(TO);
     			break;
   }
   SetLockState (LOCK_CLOSED);
}
