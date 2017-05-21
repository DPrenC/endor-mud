/*
DESCRIPCION  : barca al este del puerto
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/barca00.c
MODIFICACION : 14-07-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>#include <moving.h>

inherit ROOM;

#define NOMBRE capitalize(TP->QueryName())
#define GEN    (TP->QueryGenderEndString())

static int abierto, vacio;

reset() {
  ::reset();
  abierto=0;
  vacio=0;
}

int abrir_cmd(string str) {
  if (str!="arcon" && str!="arc�n") {notify_fail("�Qu� es lo que quieres abrir?\n"); return 0;};
  if (!abierto) {
    write("Tras forcejear un poco con el oxidado pestillo del arc�n, consigues abrirlo. "
          "Ahora puedes mirar en su interior.\n");
    abierto=1;
    say(NOMBRE+" abre el arc�n de la barca.\n",TP);
    return 1;
    }
  else {write("El arcon ya est� abierto!\n");return 1;}
}

int cerrar_cmd(string str) {
  if (str!="arcon") {notify_fail("�Qu� es lo que quieres cerrar?\n"); return 0;};
  if (abierto) {
    write("Cierras el arc�n con un golpe seco.\n");
    abierto=0;
    say(NOMBRE+" cierra el arc�n de la barca.\n",TP);
    return 1;
    }
  else {write("�El arc�n ya esta cerrado!\n");return 1;}
}

int coger_cmd(string str) {
  object obj;
  int mov;
  if (str!="anzuelo") return 0;
  if ((abierto==0) || (vacio==1)) {write("No ves ningun anzuelo por aqu� cerca.\n"); return 1;}
  obj=clone_object(OTRO("anzuelo"));
  if (obj->move(TP, M_SILENT) != ME_OK)
  {
      write("No puedes coger el anzuelo... Quiz�s si dejases algo...\n");
      return 1;
  }
  write("Coges el anzuelo del arc�n.\n");
  say(NOMBRE+" coge algo del arc�n.\n",TP);
  call_out("reset",300);
  vacio=1;
  return 1;
}

mirar_arcon(string str) {
  if (abierto==0) return "En la popa de la barca de pesca hay un peque�o arc�n. Est� cerrado.\n";
  if (vacio==0) return "En la popa de la barca de pesca hay un peque�o arc�n. Est� abierto y puedes ver "
     "que en su interior solo hay un poco de agua filtrada y un anzuelo en un rinc�n.\n";
  return "En la popa de la barca de pesca hay un peque�o arc�n. Est� abierto y puedes ver "
     "que en su interior solo hay un poco de agua filtrada.\n";
}

int muelle(){
  write("Desembarcas y subes al muelle.\n");
  say(NOMBRE+" desembarca y sube al muelle.\n",TP);
  tell_room(LIMBO("muelle00"),NOMBRE+" desembarca de la barca amarrada al este y sube al muelle.\n");
  TP->move(LIMBO("muelle00"),M_SILENT);
  return 1;
}

create() {
  ::create();
  SetIntShort("una barca de pesca");
  SetIntLong(
"Est�s a bordo de una de las barcas de pesca amarradas al muelle. Un cabo une la "
"proa con el amarre del muelle. En la popa hay una especie de arc�n y sujetos al "
"mastil un par de cabos enrrollados. Pese a que la barca est� aproada al viento y "
"las velas arriadas, el viento hace oscilar la botavara, as� que deberias tener "
"cuidado de que no te de un golpe en la cabeza.\n");

AddDetail(({"puerto"}),
 "El puerto est� construido sobre las rocas de la costa de la bahia y de �l sale "
 "el muelle donde se amarran las barcas de pesca. El puerto continua tanto hacia "
 "el este como al oeste.\n");

AddDetail(({"muelle"}),
 "El muelle es una plataforma de madera sostenida sobre pilares hechos con troncos "
 "que se hunden en el mar apoy�ndose en su fondo. Esta barca amarrada al muelle "
 "por medio de un cabo.\n");

AddDetail(({"barcas"}),
 "Hay barcas de pescadores amarradas a ambos lados del muelle. Tu te hallas a "
 "bordo de una de ellas.\n");

AddDetail(({"barca"}),QueryIntLong());
AddDetail("arcon",SF(mirar_arcon));

SetIntNoise("Oyes a las olas chocar contra el muelle.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);
AddExit("oeste",SF(muelle));
AddRoomCmd("abrir",SF(abrir_cmd));
AddRoomCmd("cerrar",SF(cerrar_cmd));
AddRoomCmd("coger",SF(coger_cmd));
reset();
}
