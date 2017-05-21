// Coded by Yandros to AURORA MUD.

#include "path.h"
#include <moving.h>

inherit KHA_ROOM;

int gargola;
int x;

create() {
   ::create();
gargola=0;

SetIntShort("las escaleras hacia el este");

SetIntLong(
"Te encuentras en frente de una escaleras de marmol. Las escaleras conducen al "
"segundo piso del castillo donde se encuentran las habitaciones reales. Dos "
"pequenyas gargolas en los pomos del principio de las escaleras atraen tu "
"atencion.\n");

SetIndoors(1);

SetIntBright(70);

AddExit("este", PISO1+"patio4");
AddExit("escalera",PISO2+"piso2_1");

AddDetail(({"gargola","gargolas"}),
"Miras cuidadosamente las gargolas de las escaleras, y no encuentras nada en "
"especial... solo que una parece diferente de la otra.\n");
}

void init ()  {
x=random(4);
if (x>2)
	{
tell_object(TP,"Oyes algunos gritos distantes... Parecen voces que provienen "+
	       "de algun lugar bajo tus pies.\n");
	}
if (x<2)
	{
tell_object(TP,"Escuchas ruidos metalicos lejanos de algo golpeando. Parecen "+
	       "provenir justo de debajo de ti.\n");
	}
   ::init();
      add_action("mover","mover");
}

int mover (string str) {
    if ((str != "gargola") && (str != "gargolas")) {
      return 0;
    }
    else {
    if ((str == "gargola") || (str == "gargolas")) {
	    if (gargola == 0) {
              if(TP->QueryDex() < 5) {
                write("No consigues mover la gargola.\n");
                say(TP->QueryName()+" forcejea la gargola de la escalera.\n");
                return 1;
              } else {
              write(
"Mueves la gargolas y una trampilla se abre bajo tus pies... Has caido a las "
"minas!\n");
		gargola=1;
                say(TP->QueryName()+
" ha tocado algo y de repente desaparece delante de tus ojos.\n");
                tell_room(CLOACAS+"cloaca1",
"Ves como "+TP->QueryName()+" cae desde la trampilla que hay sobre tu cabeza.\n");
                TP->move(CLOACAS+"cloaca1",M_SILENT);
                TP->LookAfterMove();
		return 1;
              }
	    }
	    if (gargola == 1) {
		write(
"Parece que alguien ya ha movido la gargola. Prueba en otro momento.\n");
		return 1;
	    }
	}
    }
}