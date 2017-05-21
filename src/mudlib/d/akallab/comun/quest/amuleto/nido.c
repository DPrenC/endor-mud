/*
DESCRIPCION  : nido de urracas para el quest del amuleto perdido
FICHERO      : /d/akallab/comun/quest/amuleto/nido.c
MODIFICACION : 28-10-99 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include AK_MACRO

#include <properties.h>
#include <lock.h>

#include <rooms.h>

#define THIS TO
inherit "/std/room/items"; // reset() is here
inherit CONTAINER;

//int look_nido(string str);

create () {
  ::create();
  SetShort("un nido");
  SetLong("Un pequenyo nido de urracas. Estos pajaros son muy aficionados a "
          "recoger objetos brillantes o que les resulten llamativos que luego "
          "suelen guardar en sus nidos.\n");
  SetPreIntShort("dentro de");
  SetIntShort("un nido");
  SetIntLong("Estas en el interior de un nido... aunque no deberias.\n");
  SetPreContent("Contiene:\n");
  SetValue(0);
  SetNoGet("Para que molestarse en cogerlo? No sirve para nada.\n");
  AddId("nido");
  SetMaxIntWeight(500);
  AddItem(OTRO("cristal"), REFRESH_REMOVE);
  AddItem(QUEST+"amuleto/amuleto", REFRESH_REMOVE);

}

int IsObjBag() { return 1; }

init() {
  ::init();
  add_action("get_nido","coger");
  add_action("look_nido","mirar");
  add_action("look_nido","m");
  add_action("look_nido","mi");
  add_action("look_nido","mir");
  add_action("look_nido","mira");
}

protected object busca (string str){
object objeto;
  if (!environment(TP)) return 0;
  if (objeto=search(environment(TP),str,SEARCH_INV|SM_OBJECT))
    return objeto;
  return 0;
}

get_nido(string que) {

object obj,ur;
int i,x;
status avisado;
object *inv;

  if (!obj=busca(que)) {
     write ("No encuentras "+que+" para coger.\n");
     return 1;}

  avisado=0;
  if (environment(obj)==TO) {
     i=sizeof(inv=all_inventory(environment(TP)));
     for (x=i-1;x>=0;x--){
         ur=inv[x];
         if (ur->QueryName()=="urraca"){
            if (!avisado){
               write("Parece que a las duenyas del nido no les ha gustado "
                       "nada tu osadia...\n");
               avisado=1;
               }
            ur->Kill(TP);
            }
         }
     if (avisado) return 1;
     }
  TP->ftake(que);
  return 1;
}


int look_nido(string str){

object obj,elem;
int i,x;
status si;
object *inv;

  if((!str) || (member(TO->QueryIds(), lower_case(str))==-1)) return 0;

  write(TO->QueryLong());
  i=sizeof(inv=all_inventory(TO));
  if (i==0) {return 1;}
  write(TO->QueryPreContent());
   for (x=i-1;x>=0;x--) {
     elem=inv[x];
     write(capitalize(elem->QueryShort())+"\n");
  }
  return 1;
}