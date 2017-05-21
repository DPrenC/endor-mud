/***************************************************************************************
 ARCHIVO:	arbol_vivo.c
 AUTOR:		[k] Korsario
 FECHA:		18-09-1998
 COMENTARIOS:	Un caimán
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

create(){
  ::create();
 SetStandard("un árbol viejo","árbol",10,GENERO_MASCULINO);
  SetHands(({({"una rama superior",1,2}),({"una rama inferior",1,1}),({"una raiz",1,1})}));
  SetIds(({"arbol","árbol"}));
  SetStr(50);
  SetCon(50);
  SetDex(10);
  SetAlign(0);
  SetWhimpy(0);
  SetGoChance(0);
  SetWeight(50000);
  SetHP(QueryMaxHP());

  SetShort("un árbol viejo");
  SetLong("Ves un gran árbol centenario. Su tronco es de una gran envergadura, "
  	"y tiene muchas ramas cercanas al suelo. Tiene un aspecto inquietante y a "
  	"veces parece que te está observando.\n");

  InitChats(5,({"Escuchas el ruido que producen las ramas del arbol al moverse, "
  	"a pesar de que no hay viento.\n"}));
  InitAChats(5,({"Las ramas del arbol crujen con violencia y furia. Las raices "
  	"se retuercen en la tierra como si quisieran despegarse de ella.\n"}));
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="pantano de la muerte")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
