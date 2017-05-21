/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>



inherit ROOM;

int subir () {
  string nom,como;
  if (!TP->QueryIsPlayer()) {
    nom=TP->QueryName();
    if ( (nom=="oso") || (nom=="lobo") || (nom=="liebre") ) {return 0;}
      TP->move(Z_BOSQUE("arbol_40"),M_SPECIAL,
      ({"sube a la copa del arbol","llega trepando desde abajo",
        ""}));
      return 1;}

  if (TP->QueryDex()>0) como="ayudandose de los tablones";
  if (TP->QueryDex()>10) como="sin ningun problema";
  if (TP->QueryDex()>16) como="con una agilidad felina";

 TP->move(Z_BOSQUE("arbol_40"),M_SPECIAL,
    ({"trepa al arbol "+como,"llega trepando desde el suelo",
      "Tras un poco de esfuerzo alcanzas la copa del arbol"}));
 return 1;
}

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
"Ante ti observas un gran arbol, posiblemente el mas grande del bosque. Tal "
"vez por esta razon alguien construyo una plataforma en su copa. Desde ahi "
"arriba se podria tener un control absoluto del claro que hay al noroeste y "
"de la entrada del bosque por el sur. Es un perfecto puesto de vigia. "
"Varios tablones clavados horizontalmente en su tronco permiten acceder a "
"la plataforma sin ningun problema.\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("oeste",Z_BOSQUE("bosque_39"));
  AddExit("sur",Z_BOSQUE("bosque_30"));
  AddExit("suroeste",Z_BOSQUE("bosque_29"));
  AddExit("sudeste",Z_BOSQUE("bosque_31"));
  AddExit("arriba",SF(subir));
  AddDetail(({"arbol"}),
  "El inmenso arbol que se alza ante ti alverga una pequenya plataforma en su "
  "copa.\n");
  AddDetail(({"plataforma","cabanya","torreta","copa"}),
  "En la copa del arbol ves una construccion de madera que, vista desde aqui, "
  "parece bastante resistente y que seguro que ofrece una vision inmejorable "
  "del bosque.\n");
  AddDetail(({"tablones","tablon","tronco"}),
  "Los tablones que permiten el acceso a la copa del arbol llaman tu atencion, "
  "te acercas para mirarlos de cerca, parecen resistentes pero estan cubiertos "
  "de alguna sustancia. Los rascas con las unyas y compruebas que se trata de "
  "sangre reseca.\n");
  SetIntNoise("Oyes crujir las ramas bajo tus pies.\n");
  SetIntSmell("Ueles a Naturaleza.\n");
  SetLocate("bosque de Zarkam");
}
