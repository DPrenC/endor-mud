/*
DESCRIPCION  : frasco vacio
FICHERO      : /d/akallab/comun/objeto/otro/frasco.c
MODIFICACION : 23-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit THING;
#include "path.h"
#include AK_MACRO
#include <properties.h>

int vacio;
string contenido;

string VerFrasco()
{
string s;
s="Es un pequenyo frasco de cristal con una tapadera de corcho. Esta "+
  (vacio==1?"vacio":"lleno con "+contenido)+".\n";
return s;
}

int SetContenido(string s){
  contenido=s;
  vacio=0;
  SetShort("un frasco de "+contenido);
  SetLong(VerFrasco());
  return 1;
}

string QueryContenido(){ return (vacio==1?"vacio":contenido);}


create() {
 ::create();
 vacio=1;
 contenido="";
 AddId("frasco");
 AddId("frasco_vacio");
 AddAdjective("vacio");
 SetShort("un frasco vacio");
 SetLong(VerFrasco());
 SetWeight(200);
 SetValue(10);
}

