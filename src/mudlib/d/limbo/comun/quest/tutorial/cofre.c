/*
DESCRIPCION  : cofre usado en el tutorial
MODIFICACION : 2008-03-23 [Angor@Simauria] Creacion
*/

#include "path.h"
#include <lock.h>
#include <properties.h>
inherit "/obj/chest";

create () {
  object ob;
  int cobre, plata;
  ::create();
  SetShort ("un viejo cofre");
  SetIntShort ("dentro de un viejo cofre de madera");
  SetLong ("Un viejo cofre de madera sin nada de especial.\n");
  SetIntLong ("Estás en el interior de un viejo cofre dee madera.\n");
  SetPreContent ("Contiene:\n");
  SetValue (200);
  SetWeight (20000);
  SetMaxIntWeight (30000); 
  Set(P_NOGET,1);
  AddId ("cofre");

  SetLockState (LOCK_OPEN);
  ob=clone_object(PROT("escudo")); 
  ob->move(TO);
  ob=clone_object(ARMA("espada")); 
  ob->move(TO);
  cobre=10+random(5);
  plata=random(5);
  ob=clone_object("/obj/money");
  ob->AdjustMoney((["cobre":cobre, "plata":plata]));
  ob->move(TO);
  
  SetLockState (LOCK_CLOSED);
}
