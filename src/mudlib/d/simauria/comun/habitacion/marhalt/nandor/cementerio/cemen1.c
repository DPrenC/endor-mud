/*          cemen1.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 23-09-98
            Modificado por :
	    [Nemesis] A�adida la funci�n para salir del cementerio tirando de
                      de las puertas. Cambios en la descripcion con objeto de
                      hacerla mas tetrica.
	    [Jessy]   Castellanizaci�n del fichero y consiguientes correcciones
		      ^_^
*/
#include "./path.h"

#include <properties.h>
#include <moving.h>
inherit SIM_ROOM;

haz_sur() {
 write("Las puertas est�n cerradas... Deber�as abrirlas antes.\n");
 return 1;
}


abrir_puertas(string str)
{
  int dur; // Dureza de las bisagras...
  if (!str) write ("�QU� quieres abrir?\n");
  else
  {
   if (str!="puertas" && str!="puerta") 
    write("No hay nada parecido a "+str+" que se pueda abrir por aqu�.\n");
   else {
   dur=random(TP->QueryStr()*2);
   if (dur<((TP->QueryStr()+TP->QueryDex())/2)){
       write("Te agarras con fuerza de las puertas y las bisagras ceden "
             "poco a poco...\n Las puertas se abren.....\n..... y sales del cementerio....\n");
       TP->move(CNSH("caminoc"), M_SILENT);
       tell_room(CNSH("caminoc"),
                 TP->QueryName()+" sale disparado del cementerio.\n");
       tell_room(MARH("nandor/cementerio/cemen1"),
        TP->QueryName()+
              " se agarra de las puertas y logra abrirlas. Las atraviesa con cara "
              "de espanto y desaparece hacia el sur. Las puertas se cierran tras �l.\n");
       write("Las puertas se cierran tras de ti haciendo un gran ruido.\n");
       }
    else{
         write("Agarras con fuerza las puertas, pero no las mueves ni un mil�metro. "
               "Sin embargo, has estado cerca... tal vez si lo vuelves a intentar...\n");
       }
  }
 }
 return 1;
}

empujar_puertas(str) {

 if (!str) write("�QU� quieres empujar?\n");
 else {
  if (str!="puertas" && str!="puerta")
    write("Intentas empujar "+str+", pero como s�lo est� en tu mente, te caes al suelo.\n");
  else write("Empujas las puertas con todas tus fuerzas... Ahora est�n bien cerradas.\n");
  }
 return 1;
}


init()
{
 ::init();
 add_action("abrir_puertas", "abrir");
 add_action("abrir_puertas", "tirar");
 add_action("empujar_puertas", "empujar");
}

create() {
    ::create();
    SetLocate("Cementerio de Nandor");
    SetIntShort("la entrada al Cementerio");
    SetIntLong("Est�s en la entrada al cementerio. Hay tumbas por todas partes, aunque "
    "el contenido de algunas est� esparcido por ah�. Las l�pidas de muchas de ellas est�n "
    "destrozadas.\n Un camino flanqueado por cipreses va hacia el norte, en direcci�n "
    "a una construcci�n que se ve a lo lejos.\n Al sur puedes ver las altas puertas del "
	  "cementerio, la �nica salida de este lugar tan t�trico.\n");
SetIndoors(0);
AddDetail(({"contenido"}),
            "Hay de todo: huesos, trozos de ata�d, calaveras...\n");
AddDetail(({"calaveras","calavera","huesos","cad�veres","restos","cadaveres","muertos"}),
            "Est�n muertos, no debes tenerles miedo.\n");
AddDetail(({"cipreses","cipres","cipr�s"}),
            "Son muy altos y parece que llevan mucho tiempo aqu�.\n");
    AddDetail(({"flores","flor"}),"Est�n marchitas, hace tiempo que nadie viene "
    "por aqu� a regarlas ni renovarlas.\n");
    AddDetail(({"puertas","puerta"}),         
    "Las puertas son enormes y parecen pesadas. Va a ser dif�cil "
	    "abrirlas...\n");
    AddDetail(({"tumbas","tumba"}),
            "La mayor�a han sido profanadas, aunque en algunas hay flores.\n");
    AddDetail(({"camino", "suelo"}),
            "Es un camino de gravilla, aunque s�lo se ven huellas de ida, no "
	    "de vuelta.\n");
    AddDetail(({"lapidas","l�pidas"}),
            "La mayor�a est�n esparcidas por ah�, muchas en trozos.\n");
    AddDetail(({"construcci�n","edificio","construccion"}),
            "Parece un templo u otra construcci�n religiosa.\n");
    AddExit("norte","./cemen2");
    AddExit("este","./cemen1e");
    AddExit("oeste","./cemen1o");
    AddExit("sur",SF(haz_sur));
    HideExit("sur",1);
}
