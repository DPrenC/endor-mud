/***************************************************************************************
 ARCHIVO:   tinte_azul.c
 AUTOR:     [z] Zomax
 FECHA:     24-04-2003
 COMENTARIOS:   Tinte en polvo, color azul.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit THING;

create () {
  ::create();

  seteuid(getuid());
  SetShort("tinte azul");
  SetLong("Es un fino polvo azulado intenso que sirve para pintar mezclado con aceite.\n");
  SetIds(({"tinte","tinte azul"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(10);
  SetValue(0);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}

init(){
  ::init();

  add_action("fmezclar","mezclar");
}

public int fmezclar(string str)
{
    string cosa1,cosa2;
    object azul=TO;
    object rojo=present("pimienta roja",TP);
    mapping quest=TP->QueryAttribute("DraegoQuest");

    if (!str) return 0;
    else lower_case(str);

    if (sscanf(str,"%s con %s", cosa1,cosa2) != 2) return notify_fail("¿Mezclar <qué> con <qué>?\n"),0;
    else if (azul && rojo && quest && member(quest,"tunica") && quest["tunica",0]==6 && ((azul->id(cosa1) && rojo->id(cosa2))||(azul->id(cosa2) && rojo->id(cosa1)))){
        quest+=(["tunica":7]);
        rojo->remove();
        write("Coges la pimienta y la mezclas con el tinte azúl. Te ha salido un bonito "
        "tinte de color púrpura muy intenso.\n");
        clone_object(RHOEVAR("koek/varios/tinte_purpura.c"))->move(TP,M_NOCHECK);
        return TO->remove();
    }
    else return notify_fail("¿Mezclar <qué> con <qué>?\n"),0;
}
