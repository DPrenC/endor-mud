/*
DESCRIPCION  : lista de componentes de para la curandera
FICHERO      : /d/limbo/comun/objeto/quest/lista.c
MODIFICACION : 23-02-99 [Angor@Simauria] Creacion
		19-11-99 [Theuzifan] Se graban los ingredientes en P_AUX1
		para que al entrar de nuevo los tengas todos ellos.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>

inherit THING;

#define OBJ_QUEST_ID ({"cur_quest_01","cur_quest_02","cur_quest_03",\
"cur_quest_04","cur_quest_05","cur_quest_06","cur_quest_07",\
"cur_quest_08","cur_quest_09","cur_quest_10","cur_quest_11",\
"cur_quest_12"})

#define OBJ_QUEST_DESC ({"Hiedra","fruto de Mandragora","Lavanda","Romero",\
"Tomillo","miel del bosque","salvado de trigo",\
"un frasco de agua cristalina","una garra de oso gris",\
"una pluma de cuervo","una flor de Edelweiss","algas"})

#define OBJ_DADO       ({0,0,0,0,0,0,0,0,0,0,0,0})

private string *obj_desc;
private string *obj_ids;
private int *obj_dado;

//Declaracion de funciones
int HacerDesc();
int EsObjDeLista(object ob, object pl);
int Marca(int cual, int valor, object pl);
int entregados();
string Lista();

//Definicion de funciones
int HacerDesc(){
  SetLong("\nLISTA DE INGREDIENTES PARA LA CURANDERA:\n"+Lista()+"\n");
  return 1;
}

int EsObjDeLista(object ob, object pl){
int i,j,ok;
string *ids;

  ok=0;
  ids=ob->QueryIds();
  for(i=0;i<sizeof(obj_desc);i++)
     for(j=0;j<sizeof(ids);j++)
if (ids[j]==obj_ids[i]) {Marca(i,1,pl); ok=1;};
  return ok;
}

int Marca(int cual, int valor, object pl){
  if ((valor!=0) && (valor!=1)) return 0;
  if ((cual<0) || (cual>=sizeof(obj_desc))) return 0;
  obj_dado=Query(P_AUX1);
  obj_dado[cual]=valor;
  Set(P_AUX1, obj_dado);
  HacerDesc();
pl->SaveMe();
return 1;
}


int entregados(){
int i, c;
  c=0;
  for(i=0;i<sizeof(obj_desc);i++) c+=(obj_dado[i]==0?0:1);
return c;
}

int faltan(){return (sizeof(obj_desc)-entregados());}

string Lista(){
string s;
int i;
  s="";
  for(i=0;i<sizeof(obj_desc);i++){
  s+="["+(obj_dado[i]==0?" ":"X")+"] "+obj_desc[i]+"\n";
  }
  s+="\nIngredientes totales: "+sizeof(obj_desc)+"   Ingredientes entregados: "+entregados()+"\n";
  return s;
}

create() {
  ::create();

  obj_desc=OBJ_QUEST_DESC;
  obj_ids=OBJ_QUEST_ID;
  //obj_dado=OBJ_DADO;
  obj_dado=Query(P_AUX1);
  if (!obj_dado) obj_dado=OBJ_DADO;
  Set(P_AUX1, obj_dado);
  SetShort("una lista de ingredientes");
  HacerDesc();

  SetIds(({"lista","lista_componentes_quest"}));
  SetWeight(50);
  SetValue(0);
}
