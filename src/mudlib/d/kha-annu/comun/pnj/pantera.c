/* cat.c      Creado por Mateesse@Nightfall.
   pantera.c  Modificacion, y debug de cat.c por [i] Izet@Simauria.
   Ultima modificacion:  5 Oct, 1997.
 */

#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;

object socio;
status seg;
string fnombre,cnombre;

create() {
  ::create();
 SetName("pantera");
  SetShort("una pantera");
  SetLong("Es una pantera negra de combate. Podrias adoptarla.\n");
  SetRace("animal");
  SetLevel(20);
  SetMaxHP(200);
  SetHP(200);
  SetAlign(0);
  SetHands( ({ ({"garra izquierda",0,8}),({"garra derecha",0,8}),({"colmillos",0,5}) }) );
  SetAC(3);
  seg=0;
  cnombre="pantera";
  Set(P_IS_PET, 1);
  Set("RefreshRemoveOk", 1);  // [Just for the time of hunting down offenders, Mateese]
}

catch_tell(str) {
 string a,b;
 if (sscanf(str,"%s ha muerto.",a)==1) {
    call_out("eat",3); return; }
 if (sscanf(str,"%s adopta a la pantera.",a)==1) {
    if (seg) write("Ya esta adoptada!\n");
    if (!seg) {socio=TP;
	 if (socio) {set_fellow(); write("Tu la adoptas a partir de ahora."+
					 "Ahora le puedes dar un nombre.\n"); }
	 return 1;}
 }
 return;
}

pet(str) {
   if (str!="pantera") return;
   if (seg) write("Ya esta adoptada!\n");
   if (!seg) {socio=TP;
	 if (socio) {set_fellow(); write("Tu la adoptas a partir de ahora.\n"); }
	 return 1;}
   return 1;
}

init() {
  ::init();
  add_action("hit","golpear");
  add_action("hit","pegar");
  add_action("name","nombre");
  add_action("pet","adoptar");
}

eat() {
 object ob;
 ob= present("cadaver",environment());
 if (ob) {
    if (!socio) return;
    tell_room(environment(),({ MSG_SEE, "La pantera de "+capitalize(socio->QueryName())+
      " devora el cadaver.\n"}),({socio}));
 tell_object(socio,"Tu pantera devora el cadaver.\n");
 Heal(4);
 call_other(ob,"remove");
 return 1;}
return 1;
}

set_fellow() {
 fnombre=capitalize(socio->QueryRealName());
 SetFriendObj(socio);
  SetShort("La pantera de "+(fnombre));
 SetLong("Es la pantera negra de combate de "+(fnombre)+".\n");
 if (!seg) {seg=1; call_out("follow",2);}
}

name(str) {
 string n;
 if (!str) return 0;
 if (sscanf(str,"pantera %s",n)!=1) {return 0; }
 if (TP!=socio) {notify_fail("No es tuya!\n"); return 0; }
 cnombre=capitalize(n);
 SetName(lower_case(n));
 AddId(n);
 SetShort(cnombre+" (La pantera de "+fnombre+")");
 SetLong((cnombre)+" es la pantera negra de combate de "+(fnombre)+".\n");
 AddId("pantera");
 write("Tu le das el nombre de "+cnombre+" a tu pantera.\n");
 return 1;
}

follow() {
  mixed *ene,*filter;
  object ec,e;
  int i;
  ec=environment(TO);
/* (1 line) bugfix supposed by Thragor [21Jan94]:
*/  if (!socio) return;
  if (!living(ec) && !present(socio)) {
  e=environment(socio);
  move(e, M_GO, "");
  } else if (!living(ec)) {
    ene=socio->QueryEnemies();
    filter=filter(ene,"angreifen",TO);
  }
  call_out("follow",2);
}

angreifen(ob) {
   TO->Kill(ob);
   return 1;
}

hit(str) {
     if (str!=cnombre) return;
     write("Golpeas a tu pantera para mostrarle que ya es hora de que te deje!\n");
     seg=0; remove_call_out("follow");
     socio=TO;
     cnombre="";
     fnombre="";
     SetShort("Una pantera");
     SetLong("Es una pantera negra de combate. Podrias adoptarla.\n");
     return 1;
}
