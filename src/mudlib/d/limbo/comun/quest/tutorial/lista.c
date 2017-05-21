/*
DESCRIPCION  : lista del tutorial
MODIFICACION : 2008-03-22 [Angor@Simauria]
*/

#include "path.h"
#include <properties.h>

inherit THING;

#define STEP_DESC ({"Entorno","Inventario","Usar objetos","Movimiento",\
"Salud y comida","Combate","Dormir","Habilidades y gremios","Comunicación","Quests y ayuda",})

#define STEP_DONE       ({0,0,0,0,0,0,0,0,0,0})

private string *step_desc;
private int *step_done;

//Declaracion de funciones
int HacerDesc();
int EsObjDeLista(object ob, object pl);
int Marca(int cual, int valor, object pl);
int entregados();
string Lista();

//Paso del tutorial hecho
int SetStepDone(int i){
	step_done=Query(P_AUX1);
	step_done[i]=1;
        Set(P_AUX1, step_done);
	HacerDesc();
	this_player()->SaveMe();
	return 1;
}

//Paso siguiente a hacer
int QueryNextStep(){
int i, c;
  c=-1;
  for(i=0;i<sizeof(step_desc);i++) {
  	if (step_done[i]==0){c=i; i=sizeof(step_desc);}
  	}
return c;
}

int QueryStepDone(int i){
return step_done[i];
}

int QueryNumberStepsDone(){
int i, c;
  c=0;
  for(i=0;i<sizeof(step_desc);i++) c+=(step_done[i]==0?0:1);
return c;
}

int QueryStepRemain(){return (sizeof(step_desc)-QueryNumberStepsDone());}

//Definicion de funciones
int HacerDesc(){
  SetLong("\nTareas del tutorial:\n"+Lista()+"\n");
  return 1;
}

//Lista
string Lista(){
string s;
int i;
  s="";
  for(i=0;i<sizeof(step_done);i++){
  s+="["+(step_done[i]==0?"No hecho":"Hecho   ")+"] "+step_desc[i]+"\n";
  }
  s+="\nTe faltan "+( sizeof(step_desc) - QueryNumberStepsDone() )+" por hacer.\n";
  return s;
}

create() {
  ::create();
  step_desc=STEP_DESC;
  //step_done=STEP_DONE;
  step_done=Query(P_AUX1);
  if (!step_done) step_done=STEP_DONE;
  Set(P_AUX1, step_done);
  SetShort("lista de tareas del tutorial");
  HacerDesc();

  SetIds(({"lista","lista_tutorial"}));
  SetWeight(10);
  SetValue(0);
}
