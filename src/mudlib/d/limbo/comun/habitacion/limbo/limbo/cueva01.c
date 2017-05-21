/*
[n] Nemesis@simauria

DESCRIPCION  : Cueva en el acantilado del este de la isla.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/cueva01.c
MODIFICACION : 
20-01-97 [angor] Creacion.
2002     [Zomax] Añade un cable para el quest de Leyma
09-07-03 [n] Quita el cable.
         Añade una función para que la descripción de la habitación cambie 
         dependiendo de si el cofre está o no está enterrado (cofre_desc).
         Añade una función para que la descripción cambie dependiendo de si 
         se ha arrancado el cable o no (cable_desc). Cambia la forma de 
         obtener el cable. Se acuerda de los familiares hasta la segunda 
         generación de todos los que tocaron este archivo antes que él...
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

static int abierto, // el cofre está abierto
           vacio,   // el cofre está vacío
	   enterrado,  // el cofre está enterrado
	   cable_in; // El cable está incrustado en la pared

reset() {
  ::reset();
  abierto = 0;
  vacio = 0;
  enterrado = 1;
  cable_in = 1;
}

/*
int search_cmd(string str)
{
   if(!str) return 0;
   if(str!="pared" && str!="pared sur" && str!="pared del sur" &&
       str!="en pared" && str!="en pared sur" && str!="en pared del sur" &&
       str!="en la pared" && str!="en la pared sur" && str!="en la pared del sur")
   say(TP->QueryName()+" parece buscar algo en la pared.\n");
   write("Encuentras un resorte en la pared.\n");
   TP->Set("_i_found_lever",1);
   return 1;
}*/

/*
int push_cmd(string str)
{
   if(!str) return 0;
   if(str!="resorte") return 0;
   if(!TP->Query("_i_found_lever")) return 0;
   write("Aprietas el resorte, y enormes rocas te caen encima! RUMMMBLE!\n");
   say(TP->QueryName()+" hace algo con la pared, y enormes rocas "
   "le caen encima! RUMMMBLE!\n");
   if(TP->QueryHP() <= 100)
      TP->Die();
   else TP->AddHP(-100);
   return 1;
}*/

int desenterrar_cmd(string str) {
  if ((str!="cofre")&&(str!="viejo cofre")) {notify_fail("¿Qué es lo que quieres desenterrar?\n"); return 0;}
  if (enterrado) {
      write("Te arrodilas en la húmeda arena y comienzas a excavar con las manos en ella. "
     "Poco a poco el cofre se va haciendo más visible hasta que al final, tras un "
     "tiron seco, consigues sacarlo totalmente a la superficie.\n");
      enterrado=0; return 1; }
  else {write("¡El cofre ya está desenterrado!\n");return 1;}
}


int abrir_cmd(string str) {
  if ((str!="cofre")&&(str!="viejo cofre")) {notify_fail("¿Qué es lo que quieres abrir?\n"); return 0;}
  if (enterrado){write("El cofre está medio enterrado en la arena. Si quieres abrirlo deberás "
   "desenterrarlo primero.\n");return 1;}
  if (!abierto) {
      write("Tras forcejear un poco con el oxidado cerrojo del cofre, consigues abrirlo. "
            "Ahora puedes mirar en su interior.\n");
      abierto=1; return 1; }
  else {write("¡El cofre ya está abierto!\n");return 1;}
}


int cerrar_cmd(string str) {
  if ((str!="cofre")&&(str!="viejo cofre")) {notify_fail("¿Qué es lo que quieres cerrar?\n"); return 0;}
  if (enterrado){write("El cofre está medio enterrado en la arena. Para hacer algo con el, primero "
   "deberas desenterrarlo.\n");return 1;}
  if (abierto) {
      write("Cierras el viejo cofre mientras sus oxidadas bisagras crujen lastimeramente.\n");
      abierto=0; return 1; }
  else {write("¡El cofre ya está cerrado!\n");return 1;}
}


mirar_cofre(string str) {
write("En el suelo de la cueva, semienterrado entre la arena hay lo que parece ser un cofre. Probablemente alguien lo escondió en esta cueva por alguna razón y la arena arrastrada por la subida de la marea lo ha enterrado.\n");

  if (enterrado==1) return "No puedes verlo muy bien pues está semienterrado en la arena. Si de verdad "
 "echarle un vistazo, deberias desenterrarlo primero.\n";

  if (!abierto) return "El cofre es de tamaño mediano, está hecho de madera y con remates de metal. "
 "El cofre está cerrado y tu te preguntas que podrá contener en su interior.\n";

  if (vacio) return "Miras al interior del cofre abierto que hay en el suelo y descubres que excepto "
 "por un poco de arena en su fondo, el cofre está vacio.\n";

  return "En el interior del cofre y envuelta en una vieja tela descolorida, se encuentra "
 "una pequeña daga con varias inscripciones en su hoja y una empuñadura en la "
 "que se hayan incrustadas varias piedras preciosas.\n";
}

/*
string mirar_pared()
{
   string mess;
   mess="Es la única pared que no está cubierta por las algas.\n";
   if(TP->Query("_i_found_lever"))
      mess+="Ves un pequeño resorte en la pared.\n";
   else
      mess+="Podrías buscar en ella.\n";
   return(mess);
}*/

int coger_cmd(string str) {
  object daga;
  if ((str!="daga")&&(str!="pequenya daga")&&(str!="pequeña daga"))
  {
     notify_fail("¿Qué es lo que quieres coger?\n");
     return 0;
  }
  if (!((!enterrado)&&(abierto)&&(!vacio)))
  {
     notify_fail("No ves ninguna daga por aquí cerca.\n");
     return 0;
  }
  vacio=1;
  daga=clone_object(ARMA("daga_joya"));
  daga->move(TP);

  write("Coges la daga con gemas incrustadas que había en el cofre.\n");
  return 1;
}

/*
int arrancar_cmd(string str) {
  object cable;

  if((str!="cable")&&(str!="cable incrustado")) {
     notify_fail("¿Qué es lo que quieres arrancar?\n");
     return 0;
  }

  if(!cable_in) return 0;

  write("Con un fuerte tirón, arrancas el cable de la roca.\n");
  say(TP->QueryName()+"tira con fuerza de un cable y se cae de culo.\n");
  cable_in = 0;
  cable = clone_object(OTRO("cable"));
  if ( cable->move(TP,M_SILENT)!=ME_OK )
    cable->move(environment(TP), M_TELEPORT, "cae al suelo");
  cable->SetOwner(TP->QueryRealName());
  return 1;
}*/

/*
string ver_cable() {
  if (cable_in)
    return
"Bajo una gruesa capa de algas puedes distinguir lo que parece un viejo cable.\n";
  else return 0;
}*/

private string cofre_desc() {
  if(enterrado)
    return "En el suelo y semienterrado en la arena hay lo que parece ser un viejo cofre. ";
  else
    return "";
}

/*
private string cable_desc() {
  if(cable_in)
    return "En una de las paredes ves un cable incrustado.\n";
  else
    return "\n";
}*/

public string QueryIntLong() {
  return
   "Te encuentras en el fondo de la cueva que hay en la pared del acantilado "
"de la costa este de Limbo. La cueva es un estrecho corredor que se adentra "
"en el interior de la tierra.\n"+cofre_desc()+".\n";
}

create() {
  ::create();
  SetIntShort("una cueva");
  SetIntNoise("Las olas rompen una y otra vez contra la base del acantilado.\n");
  SetIntSmell("Huele a mar.\n");
  SetLocate("isla Limbo");

//AddItem("/d/limbo/comun/objeto/otro/cable",REFRESH_REMOVE,1);

AddRoomCmd("desenterrar",SF(desenterrar_cmd));
AddRoomCmd("abrir",SF(abrir_cmd));
AddRoomCmd("cerrar",SF(cerrar_cmd));
AddRoomCmd("coger",SF(coger_cmd));
//AddRoomCmd("buscar",SF(search_cmd));
//AddRoomCmd("pulsar",SF(push_cmd));
//AddRoomCmd("arrancar",SF(arrancar_cmd));
AddDetail("cofre",SF(mirar_cofre));
//AddDetail("paredes","Estan cubiertas de algas, excepto la pared del sur.\n");
//AddDetail(({"pared","pared sur","pared del sur"}),SF(mirar_pared));
//AddDetail(({"cable","cable en pared","cable incrustado en pared", "cable incrustado en la pared","cable en la pared"}), SF(ver_cable));

AddExit("este",LIMBO("cueva00"));

SetIntBright(0); //sin luz
SetIndoors(1);  //a cubierto
reset();
}

