/*
DESCRIPCION  : Salvoconducto
FICHERO      : /obj/salvoconducto.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion.
               Mar'99 [Nemesis@Simauria] Castellanizado.
--------------------------------------------------------------------------------
*/

inherit "std/thing";
#include <properties.h>

//variables
string zona;

//funciones publicas
public void    SetZona(string str);
public string  QueryZona();

// Actualiza la descripcion del salvoconducto
protected void updateDesc(){
  if (QueryZona()!=""){
    SetShort("un salvoconducto para "+capitalize(zona));
    SetLong("Es un salvoconducto. Permite transitar por "+capitalize(zona)+".\n");
    }
   else{
    SetShort("un salvoconducto");
    SetLong("Es un salvoconducto.\n");
    }
}


public void    SetZona(string str){zona=str; updateDesc();}
public string  QueryZona(){return zona;}


// Funcion principal
create() {
  ::create();
  SetShort("un salvoconducto");
  SetLong("Es un salvoconducto.\n");
  AddId("salvoconducto");
  AddId("documento");
  AddId("pase");
  SetWeight(100);
  SetZona("");
}


init() {
  ::init();
  add_action("leer_cmd","leer");
}


leer_cmd(str) {
   if (!str) return;
   if (member(Query(P_IDS), str)<0) return;
   if (!present(TO, TP)) {
      notify_fail("Tienes que cogerlo primero.\n");
      return 0;
      }
   say(TP->QueryName()+" lee un documento.\n",TP);
   if (QueryZona()!="")
   write("Mediante este documento, el emperador orco pemite a su portador transitar por el\n"
         "territorio de "+capitalize(QueryZona())+" libremente. Firmado: Gobernador Sikkukut.\n");
   else
   write("El texto está enborronado y apenas se puede leer. El salvoconducto posiblemente\n"
         "ya no sirva de nada.\n");
   return 1;
}
