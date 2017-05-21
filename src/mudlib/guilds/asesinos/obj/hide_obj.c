#include <wizlevels.h>
#include "/guilds/asesinos/path.h"
inherit "/std/thing";

int QueryHideObj() { return 1; }

void Destruye(object obj) {
 if (!obj) return;
 catch(obj->remove());
 if (obj) destruct(obj);
}

void create() {
   ::create();
  SetShort("hide_obj");
   SetLong(W("No ves nada de eso.\n"));
   SetInvis(10);
   AddId("hide_obj");
   AddId("hide obj");
   AddId("hide object");
   SetWeight(0);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
}

void init() {
  ::init();
  add_action("getaction","",1);
}

void delata(object ob) {
  object *inv;
  int i;

  if (ob->Query(P_HIDDEN) > 0) {
    ob->Set(P_HIDDEN,0);
    tell_object(ob,W("Sales de tu escondite.\n"));
    inv=all_inventory(environment(TP));
    for(i=0;i<sizeof(inv);i++) {
      if(inv[i] != TP) {
        tell_object(inv[i],W(capitalize(TP->QueryName())+" sale de entre las sombras.\n"));
	inv[i]->init();
      }
    }
    inv=deep_inventory(TP);
    for(i=0;i<sizeof(inv);i++) {
      if (inv[i]->QueryHideObj()) {
         Destruye(inv[i]);
      }
    }
  }
}

getaction(string str) {
  return getcmds(query_verb());
}

getinput(string str) {
  mixed ret;
  if (ret = getcmds(str)) input_to("get_input");
  return ret;
}

int getcmds(string str) {
  if (member(COMANDOS_PERMITIDOS_ESCONDIDO, str)==-1) delata(TP);
  return 0;
}
