/*          cemen1.c : Cementerio de Nandor
            Creado por : Blackrider
            Fecha : 28-10-97
            Ultima modificacion : 23-09-98
            Modificado por :
	    [Nemesis] Añadida la función para salir del cementerio tirando de
                      de las puertas. Cambios en la descripcion con objeto de
                      hacerla mas tetrica.
	    [Jessy]   Castellanización del fichero y consiguientes correcciones
		      ^_^
*/
#include "./path.h"

#include <properties.h>
#include <moving.h>
inherit SIM_ROOM;

haz_sur() {
 write("Las puertas están cerradas... Deberías abrirlas antes.\n");
 return 1;
}


abrir_puertas(string str)
{
  int dur; // Dureza de las bisagras...
  if (!str) write ("¿QUÉ quieres abrir?\n");
  else
  {
   if (str!="puertas" && str!="puerta") 
    write("No hay nada parecido a "+str+" que se pueda abrir por aquí.\n");
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
              "de espanto y desaparece hacia el sur. Las puertas se cierran tras él.\n");
       write("Las puertas se cierran tras de ti haciendo un gran ruido.\n");
       }
    else{
         write("Agarras con fuerza las puertas, pero no las mueves ni un milímetro. "
               "Sin embargo, has estado cerca... tal vez si lo vuelves a intentar...\n");
       }
  }
 }
 return 1;
}

empujar_puertas(str) {

 if (!str) write("¿QUÉ quieres empujar?\n");
 else {
  if (str!="puertas" && str!="puerta")
    write("Intentas empujar "+str+", pero como sólo está en tu mente, te caes al suelo.\n");
  else write("Empujas las puertas con todas tus fuerzas... Ahora están bien cerradas.\n");
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
    SetIntLong("Estás en la entrada al cementerio. Hay tumbas por todas partes, aunque "
    "el contenido de algunas está esparcido por ahí. Las lápidas de muchas de ellas están "
    "destrozadas.\n Un camino flanqueado por cipreses va hacia el norte, en dirección "
    "a una construcción que se ve a lo lejos.\n Al sur puedes ver las altas puertas del "
	  "cementerio, la única salida de este lugar tan tétrico.\n");
SetIndoors(0);
AddDetail(({"contenido"}),
            "Hay de todo: huesos, trozos de ataúd, calaveras...\n");
AddDetail(({"calaveras","calavera","huesos","cadáveres","restos","cadaveres","muertos"}),
            "Están muertos, no debes tenerles miedo.\n");
AddDetail(({"cipreses","cipres","ciprés"}),
            "Son muy altos y parece que llevan mucho tiempo aquí.\n");
    AddDetail(({"flores","flor"}),"Están marchitas, hace tiempo que nadie viene "
    "por aquí a regarlas ni renovarlas.\n");
    AddDetail(({"puertas","puerta"}),         
    "Las puertas son enormes y parecen pesadas. Va a ser difícil "
	    "abrirlas...\n");
    AddDetail(({"tumbas","tumba"}),
            "La mayoría han sido profanadas, aunque en algunas hay flores.\n");
    AddDetail(({"camino", "suelo"}),
            "Es un camino de gravilla, aunque sólo se ven huellas de ida, no "
	    "de vuelta.\n");
    AddDetail(({"lapidas","lápidas"}),
            "La mayoría están esparcidas por ahí, muchas en trozos.\n");
    AddDetail(({"construcción","edificio","construccion"}),
            "Parece un templo u otra construcción religiosa.\n");
    AddExit("norte","./cemen2");
    AddExit("este","./cemen1e");
    AddExit("oeste","./cemen1o");
    AddExit("sur",SF(haz_sur));
    HideExit("sur",1);
}
