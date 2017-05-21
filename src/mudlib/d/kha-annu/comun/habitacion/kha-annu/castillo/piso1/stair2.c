/* Coded by Yandros to Aurora MUD.
   Modificado por [i] Izet@Simauria, para inplementar a Nightfall(tm).
   Ultima modificacion: 9 Oct, 1997.
*/

#define tp TP
#include "path.h"
inherit KHA_ROOM;
int gargola;
int x;

create() {
   ::create();
gargola=0;
SetIntShort("las escaleras hacia el oeste");

SetIntLong(
"Estas en un gran hall. Frente a ti puedes ver unas escaleras hechas de marmol "
"llenas de adornos y decorandolas con un estilo unico. Las escaleras suben hacia "
"las habitaciones reales del castillo.\n");

SetIndoors(1);

SetIntBright(70);

AddExit("oeste", PISO1+"patio7");
AddExit("escalera",PISO2+"piso2_9");

AddDetail(({"gargola","gargolas"}),
"Miras cuidadosamente las gargolas de las escaleras, y no encuentras nada en "
"especial... solo que una parece diferente de la otra.\n");
}

void init ()  {
x=random(4);
if (x>2)
	{
tell_object(tp,"Oyes algunos gritos distantes... Parecen voces que provienen "+
	       "de algun lugar bajo tus pies.\n");
	}
if (x<2)
	{
tell_object(tp,"Escuchas ruidos metalicos lejanos de algo golpeando. Parecen "+
	       "provenir justo de debajo de ti.\n");
	}
   ::init();
/*
      add_action("mover","mover");
*/
}

/*
int mover (string str) {
    if ((str != "gargola") && (str != "gargolas")) {
      return 0;
    }
    else {
    if ((str == "gargola") || (str == "gargolas")) {
	    if (gargola == 0) {
		write(
"Mueves la gargolas y una trampilla se abre bajo tus pies... Has caido a las "
"minas!\n");
		gargola=1;
		say((string)TP->query_cap_name()+
" ha tocado algo y de repente a desaparecido delante de tus ojos.\n");
                tp->move(MPISO1+"add6");
		return 1;
	    }
	    if (gargola == 1) {
		write(
"Parece que alguien ya ha movido la gargola. Prueba en otro momento.\n");
		return 1;
	    }
	}
    }
}
*/