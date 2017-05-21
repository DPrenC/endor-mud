/* ********************************************************** */
/* *                                                        * */
/* *        ARCHIVO:sala_baculo.c                           * */
/* *        AUTOR: [a] Articman                             * */
/* *        MODIFICACION: [a] Creación (Neme,metele el      * */
/* *                          báculo cuando quieras)        * */
/* *                                                        * */
/* ********************************************************** */

#include <skills.h>
#include "path.h"

inherit SIM_ROOM;

int enc=0;

int cmd_buscar(string str) {
int busc;
object ob;
if (str=="objetos" || str=="esquina" || str=="objeto") {
 busc=TP->UseSkill(HAB_RASTREAR);
 if (busc<=-15) {  // el tio es un paquete y no encuetra nada
  write("Buscas entre el monton de desechos pero no encuentras nada de interés.\n");
  say(TP->QueryName()+" busca en el montón de basura pero no encuentra nada.\n");
  return 1;
  }
 else
  if (busc>-20 && busc<-5){} // el tio es un poco habil y encuentra anillo
     if (enc==0) {
        write("Buscas entre el monton de desechos y encuentras un anillo.\n");
        say(TP->QueryName() +" busca en el montón de basura y encuentra un anillo.\n");
        ob=clone_object(GOBJETO("proteccion/gundistyr/anillooro"));
        ob->move(TP);
        enc=1;
        return 1;
        }
     else{ // el tio es un poco habil pero ya encontro las monedas antes
        write("Buscas entre el montón de desechos pero no encuentras nada de interés.\n");
        say(TP->QueryName()+" busca en el montón de basura pero no encuentra nada.\n");
        return 1;
        }
/*  else  {// el tio es la leche de habil y encuentra el cacho-baculo --- Este lugar es para algun objeto de quest
        write("Entre los restos logras encontrar algo de interés: El fragmento de un báculo antiguo.\n");
	say(TP->QueryName() +" logró encontrar un báculo entre los restos.\n");
	return 1;// aqui va el clone del baculo con su move
	} */
}
else
return 0;
}

create() {
::create();
SetIntShort("la base kobold");
SetIntLong(W("Estás en una habitación que los kobolds usan como cámara "
"del tesoro. Casi todo lo que tienes alrededor son objetos sin valor "
"alguno obtenidos en alguno de los múltiples pillajes a los que se puedan "
"haber dedicado. Todos los objetos están amontonados en una esquina de la "
"habitación.\n"));
AddDetail(({"objetos","esquina"}),W("Ves múltitud de cosas, la mayoría de "
"ellas sin valor, como espejos o jarrones rotos. Quizá si buscaras más "
"profundamente encontraras algo de valor...\n"));

AddExit("oeste","salalider");
}

init() {
::init();
add_action("cmd_buscar","buscar");
}
