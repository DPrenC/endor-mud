/* 
DESCRIPCION  : Un dado
FICHERO      : /d/limbo/comun/objeto/otro/dado.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion
               23-04-99 [Angor@Simauria] Quitado gran parte de su valor,
	                vista la avaricia de los players...
*/

#include <properties.h>
#include <money.h>
#include <properties.h>

inherit THING;

create() {
  ::create();
  SetIds(({"dado"}));
  SetShort("un dado");
  SetLong("Es un dado corriente de 6 caras hecho de marfil. Puedes lanzarlo o usarlo.\n");
  SetWeight(10);
  SetValue(5);
}


init() {
  ::init();
    add_action("lanzar_cmd", "lanzar");
    add_action("lanzar_cmd", "usar");
}

lanzar_cmd(str) {
   int d;
   string dib;
   if (!id(str)) return 0;
   d = random(6) + 1;
   switch(d) {
      case 1 : dib="    /\\\n"+
                   "   /  \\\n"+
                   "  / o  \\\n"+
                   " |\\    /|\n"+
                   " | \\  /o|\n"+
                   " |o \\/  |\n"+
                   "  \\o |o/\n"+
                   "   \\o|/\n"+
                   "    \\/\n";break;
      case 2 : dib="    /\\\n"+
                   "   /  \\\n"+
                   "  / o  \\\n"+
                   " |\\  o /|\n"+
                   " |o\\  / |\n"+
                   " |o \\/ o|\n"+
                   "  \\ o| /\n"+
                   "   \\o|/\n"+
                   "    \\/\n";break;
      case 3 : dib="    /\\\n"+
                   "   /o \\\n"+
                   "  / o  \\\n"+
                   " |\\ o  /|\n"+
                   " |o\\  /o|\n"+
                   " |oo\\/  |\n"+
                   "  \\oo|o/\n"+
                   "   \\o|/\n"+
                   "    \\/\n";break;
      case 4 : dib="    /\\\n"+
                   "   /o \\\n"+
                   "  /o   \\\n"+
                   " |\\   o/|\n"+
                   " | \\ o/o|\n"+
                   " |  \\/  |\n"+
                   "  \\o |o/\n"+
                   "   \\ |/\n"+
                   "    \\/\n";break;
      case 5 : dib="    /\\\n"+
                   "   /o \\\n"+
                   "  /ooo \\\n"+
                   " |\\ o  /|\n"+
                   " | \\  / |\n"+
                   " |o \\/ o|\n"+
                   "  \\o | /\n"+
                   "   \\o|/\n"+
                   "    \\/\n";break;
      case 6 : dib="    /\\\n"+
                   "   /o \\\n"+
                   "  /o o \\\n"+
                   " |\\ o o/|\n"+
                   " | \\ o/o|\n"+
                   " |o \\/oo|\n"+
                   "  \\o |o/\n"+
                   "   \\o|/\n"+
                   "    \\/\n";break;
      default: dib="";
 }
 write("Lanzas el dado y obtienes un:\n"+dib);
 return 1;
}


