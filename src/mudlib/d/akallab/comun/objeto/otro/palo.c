/*
DESCRIPCION  : Palo para expulsar las abejas del panal
FICHERO      : /d/akallab/comun/quest/curandera/palo.c
MODIFICACION : 20-02-99 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/


#include <lamp.h>
#include <properties.h>
#include <nightday.h>

inherit LAMP;

create() {
  ::create();
  AddId("palo");
  SetWeights(200,40);
  SetValues(1,1);
  SetFuelAmount(10+random(20));
  SetBrightness(REL_STATE(ND_DAWN,MAX_SUNBRIGHT));
  SetLampMsg(({"El palo ya esta ardiendo.\n",
  "El palo no esta ardiendo.\n",
  "El palo esta totalmente quemado, asi que no puede encenderse de nuevo.\n",
  "Acercas @@Lighter@@ al palo, y tras unos golpecitos, consigues que la madera comience a arder.\n",
  "@@Pl_Name@@ enciende un palo.\n",
  "El palo se apaga.\n",
  "@@Pl_Name@@ apaga su antorcha.\n",
  "Tu palo chisporrotea y se apaga.\n",
  "La antorcha de @@Pl_Owner@@ chisporrotea y se apaga.\n",
  "No tienes nada con lo que encender el palo.\n",
  "Acercas @@Lighter@@ al palo, pero por más que golpeas la piedra, no consigues hacer "
  "saltar ninguna chispa para encenderlo.\n"}));
}

public int QueryNoBuy() { return QueryBurning(); }

public int QueryValue() {
   return 0;
}

string QueryShort() {
  if (QueryFuel()) return ("un palo"+(QueryBurning() ?" ardiendo":""));
  return "los restos quemados de un palo";
}

string QueryLong() {
 string rc;
 if (QueryBurning()) rc="Un palo ardiendo con una llama que apenas desprende humo.\n";
 else rc="Un largo palo de madera. Encendido seria una buena antorcha.\n";
 if (QueryFuel() == QueryFuelMax()) rc+="Todavia no ha sido usado.\n";
 else if (QueryFuel() *4 > QueryFuelMax() *3) rc+="Esta ligeramente quemado.\n";
 else if (QueryFuel() * 2 > QueryFuelMax()) rc+="Mas de la mitad esta ya quemado.\n";
 else if (QueryFuel() * 4 > QueryFuelMax()) rc+="Apenas queda un poco de madera sin quemar.\n";
 else rc = "En algun momento fue un buen palo, pero ahora esta quemado por completo.\n";
 return rc;
}

string QuerySmell() {
 if (QueryBurning()) return "Hueles el olor que desprende la madera del palo al quemarse.\n";
 if (QueryFuel() == QueryFuelMax()) return "Huele a madera de roble seca.\n";
 if (!QueryFuel()) return "Huele a madera.\n";
 return "Huele a cenizas frias.\n";
}

