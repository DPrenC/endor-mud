/*
DESCRIPCION  : Salvoconducto
FICHERO      : /d/akkallab/comun/objeto/otro/salvoconducto.c
MODIFICACION : 20-03-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include <properties.h>

//variables
string zona;

//funciones publicas
public void    SetZona(string str);
public string  QueryZona();

//funciones privadas
protected void updateDesc();


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

public string  QueryZona(){return zona;}
public void    SetZona(string str){
  zona=str;
  updateDesc();
  AddId("salvoconducto_"+zona);
}



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
   if (!str) return 0;
   if (member(Query(P_IDS), str)<0) return 0;
   if (!present(TO, TP)) {
      notify_fail("Tienes que cogerlo primero.\n");
      return 0;
      }
   say(TP->QueryName()+" lee un documento.\n",TP);
   if (QueryZona()!="")
   write("Mediante este documento, el emperador orco pemite a su portador transitar por el "
         "territorio de "+capitalize(QueryZona())+" libremente. Firmado: Gobernador Sikkuk.\n");
   else
   write("El texto esta enborronado y apenas se puede leer. El salvoconducto posiblemente "
         "ya no sirva de nada.\n");
   return 1;
}
