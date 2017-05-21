/*
DESCRIPCION  : tinaja de arcilla
FICHERO      : /d/akallab/comun/objeto/otro/tinaja.c
MODIFICACION : 23-11-99 [Angor@Simauria] Creacion
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
s="Es una tinaja de arcilla de mediano tamanyo, ya que debe tener unos "
  "50 cm de alto y unos 25 de diametro en su parte mas ancha. La tinaja "
  "es un ancho recipiente mas ancha en el centro que en los extremos y "
  "en ella se suelen almacenar liquidos. Esta "+
  (vacio==1?"vacia":"llena con "+contenido)+".\n";
return s;
}

int SetContenido(string s){
  contenido=s;
  vacio=0;
  SetShort("una tinaja mediana llena de "+contenido);
  SetLong(VerFrasco());
  return 1;
}

string QueryContenido(){ return (vacio==1?"vacia":contenido);}

create() {
 ::create();
 vacio=1;
 contenido="";
 AddId("tinaja");
 AddId("tinaja_vacio");
 AddAdjective("vacia");
 SetShort("una tinaja mediana de arcilla");
 SetLong(VerFrasco());
 SetWeight(2000);
 SetValue(15);
}

