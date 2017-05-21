/*
DESCRIPCION  : cuenco de arcilla
FICHERO      : /d/akallab/comun/objeto/otro/cuenco.c
MODIFICACION :
23-11-99 [Angor@Simauria] Creacion
11-12-99 [Angor@Simauria] Se puede llenar para su uso en el quest
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
s="Es un pequenyo cuenco de arcilla.\nEsta "+
  (vacio==1?"vacio":"lleno con "+contenido)+".\n";
return s;
}

int SetContenido(string s){
  contenido=s;
  vacio=0;
  SetShort("un cuenco de lleno de "+contenido);
  SetLong(VerFrasco());
  return 1;
}

string QueryContenido(){ return (vacio==1?"vacio":contenido);}

create() {
 ::create();
 vacio=1;
 contenido="";
 AddId("cuenco");
 AddId("cuenco_vacio");
 AddAdjective("vacio");
 SetShort("un cuenco de arcilla");
 SetLong(VerFrasco());
 SetWeight(200);
 SetValue(5);
}

init()
{
::init();
add_action("usar_cmd","usar");
add_action("llenar_cmd","llenar");
}

void llenar(object ob)
{
SetContenido(ob->QueryShort());
//guardar el path para regenerar el objeto algun dia?
ob->remove();
return;
}

int usar_cmd(string str){
string s;
object ob;

if (!str) return 0;
if ((sscanf(str,"%s con cuenco",s)==1)||(sscanf(str,"cuenco con %s",s)==1))
   {
   ob=present(s,TP);
   if (!ob || !call_other(ob,"id","frutos del bosque"))
      {
	  write("No puedes llenar el cuenco con eso.\n");
      return 1;
	  }
   else
      {
 	  write("Llenas el cuenco con "+ob->QueryShort()+".\n");
      llenar(ob);
      return 1;
      }
   }
return 0;
}

int llenar_cmd(string str){
string s;
object ob;

if (!str) return 0;
if (sscanf(str,"cuenco con %s",s)==1)
   {
   ob=present(s,TP);
   if (!ob || !call_other(ob,"id","frutos del bosque"))
      {
	  write("No puedes llenar el cuenco con eso.\n");
      return 1;
	  }
   else
      {
 	  write("Llenas el cuenco con "+ob->QueryShort()+".\n");
      llenar(ob);
      return 1;
      }
   }
return 0;
}
