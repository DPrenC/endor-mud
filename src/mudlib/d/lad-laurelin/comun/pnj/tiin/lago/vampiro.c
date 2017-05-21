/* Y cuando se haga podemos ponerle la enfermedad Vampirismo pa quien muerda
CREACION: Alura
UBICACION: /d/lad-laurelin/comun/pnj/tiin/lago/vampiro.c
DESCRIPCION: pues es una vampiresa que muerde y to*/

#include <money.h>
#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include <moving.h>
inherit "/d/lad-laurelin/comun/pnj/tiin/lago/stdvampi";

int car;

move(dest,method,stuff) {
  if(method==M_GO && dest->QueryLocate()!="templo de Dehim") return ME_NO_ENTER;
  return ::move(dest,method,stuff);
}

create() {
seteuid(getuid());
car=random(2);
::create();
SetStandard("una vampiresa","no-muerto",25+car,2);
AddAdjective("bella");
SetIds(({"vampiro","vampiresa","vampira"}));
SetShort("una vampiresa");
SetLong("Es un muerto viviente cuyos grandes (y visibles) colmillos usa para sorberte\n"+"la sangre ...\n");
SetSize(P_SIZE_MEDIUM);
SetNoGet(1);
SetWeight(75000);
SetInt(25+car);
SetDex(25+car);
SetStr(25+car*2);
SetHands(({({"la mano izquierda",0,6}),({"la mano derecha",0,7}),({"los colmillos",1,8})}));
SetAlign(-500);
SetWhimpy(15);
InitChats(5,({"Una vampiro te mira con ojos ardientes ...\n",
"La vampiro se contonea ante ti y te dice: -Ven... necesito tu... eh... quiero tocarte...\n",
"La vampiro se rie cruelmente al verte.\n"}));

AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
([P_SHORT: "tunica transparente",
P_LONG:  "Una tunica de gasa transparente.\n",      P_ARMOUR_TYPE:AT_ARMOUR, //GLOVES,CLOAK,ARMOUR,RING,BOOTS,SHIELD,TROUSERS
P_IDS: ({"tunica","túnica", "tunica transparente", "túnica transparente"}),
P_AC: 0, //
P_SIZE:P_SIZE_MEDIUM,
P_RESET_QUALITY: 95,
P_WEIGHT: 300,
P_VALUE: 80]) );
}