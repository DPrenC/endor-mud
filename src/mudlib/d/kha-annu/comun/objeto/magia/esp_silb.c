/****************************************************************/
/*  Fichero: esp_silb.c                                         */
/*  Creado por:  [I] Izet@Simauria, Lord de Kha-annu.           */
/*               [T] Tannis@Simauria, Vice-Lord de Kha-annu.    */
/*               [Y] Yandros@Simauria, Vice-Lord de Kha-annu.   */
/*  Utilidad:  Conocer los deseos de los jugadores.             */
/*             Objeto de Quest.                                 */
/*  Ultima modificacion:  25 Nov, 1997.                         */
/*               [Woo] Modificado                               */
/****************************************************************/

#include "./path.h"
#include <properties.h>

inherit THING;

create() {
  ::create();
  SetIds(({"espada","espadas"}));
  AddAdjective(({"una","unas","silbantes","silbante"}));
  SetShort("las Espadas Silbantes");
  SetLong(
"Ves las Espadas Silbantes. Las espadas están hechas de mithril con finas "
"lineas de oro. Están moviendose constantemente y al cruzarse desprenden un "
"intenso silbido. Alrededor de las espadas notas un aura muy poderosa y un "
"misterioso brillo azul y verde invade tus sentidos.\n\
El pedestal sobre el que se encuentran las espadas tiene un inscripción.\n");
   SetWeight(50000);
   SetValue(0);
   Set(P_NOGET,1);
   TP->SetAttribute("maldito",0);
}

init() {
   ::init();
   add_action("PideDeseo","desear");
   add_action("PideDeseo","deseo");
   add_action("NoCoger","coger");
   add_action("NoCoger","robar");
   add_action("NoCoger","tocar");
   add_action("Leer","leer");
}

Leer (string str) {
   if ( (str == "inscripcion") || (str == "espadas") ||
        (str == "espada") || (str == "espadas silbantes") ||
        (str == "espada silbante") || (str == "la espada") ||
        (str == "la espada silbante") || (str == "las espadas") ||
        (str == "inscripción") || (str == "la inscripcion") ||
        (str == "el pedestal") ||
        (str == "las espadas silbantes") || (str == "pedestal") ) {
         write(
                        "Lees la inscripción del pedestal:\n"
"Estas son las sagradas Espadas Silbantes de Kha-annu. Las leyendas dicen\n"
"que estas espadas tienen el poder de conceder un deseo único a los mortales\n"
"dependiendo de sus buenas y malas acciones.\n"
"Para pedir un deseo usa 'desear <deseo>'.\n"
"No malgastes tu única oportunidad en esta vida.\n");
       say(TP->QueryName()+" lee una inscripción.\n");
       return 1;
     }
     else {
           write("No encuentras "+str+" para leer.\n");
           return 1;
     }
}
NoCoger(string str)  {
object izet;

       if ((str == "espada") || (str == "espadas") || (str == "la espada")
            || (str == "las espadas") || (str == "espada silbante") ||
            (str == "espadas silbantes") || (str == "la espada silbante")
            || (str == "las espadas silbantes") ) {
           if (TP->QueryAttribute("maldito") == 0) {
	      write(
"Al intentar coger las espadas, recibes una descarga y sientes un intenso\n"
"dolor. Parece como si algo dentro de ti estuviera escapándose.\n");
              say(TP->QueryName()+
		  " intenta coger las espadas, pero estas se ponen a la\n"+
		  "defensiva. Parece que se ha hecho daño.\n");
	      TP->SetHP(1);
              TO->SetLong(
"Ves las Espadas Silbantes. Las espadas están hechas de mithril con finas\n"
"lineas de oro. Parece que están a la defensiva, como si alguien hubiera\n"
"tratado de robarlas. Alrededor de las espadas notas un aura muy poderosa y\n"
"un misterioso brillo azul y verde invade tus sentidos.\n"
"El pedestal sobre el que se encuentran las espadas tiene una inscripción.\n");
              TP->SetAttribute("maldito",1);
               return 1;
	   }
           if (TP->QueryAttribute("maldito") != 0) {
                write(
"Las Espadas Silbantes extienden su aura sobre tu cuerpo, y al intentar\n"
"cogerlas solo alcanzas a ver un intenso rayo de luz que se interna en tu\n"
"cerebro.\n");
   write("Has muerto.\n");
   say(TP->QueryName()+
" intenta coger las espadas. De repente un intenso\n"
"resplandor invade la estancia y cuando se disipa observas a "+TP->QueryName()+
" tendido boca abajo en el suelo con una mueca de terror en su cara.\n"+
       TP->QueryName()+" ha muerto.\n");
               TP->Die();
               TP->SetAttribute("maldito",0);
               if (izet = find_object("izet") ) {
                   tell_object(izet, "*** "+capitalize(getuid(TP))+
                              " ha sido muerto por las Espadas Silbantes.\n");
               TO->SetLong(
"Ves las Espadas Silbantes. Las espadas estan hechas de mithril con finas\n"
"lineas de oro. Estan moviendose constantemente y al cruzarse desprenden un\n"
"intenso silbido. Alrededor de las espadas notas un aura muy poderosa y un\n"
"misterioso brillo azul y verde invade tus sentidos.\n"
"El pedestal sobre el que se encuentran las espadas tiene una inscripción.\n");
	       return 1;
	    }
       }
    }
}

PideDeseo (string deseo) {
object marca, izet;


   if (deseo == 0) {
      write("Desear QUE?\n");
      return 1;
    }
   if (present("deseo",TP) ) {
        write(
"Las Espadas Silbantes dicen: No abuses de nuestros poderes, mortal. Ya\n"
"hemos escuchado tus deseos.\n");
        say(TP->QueryName()+" pide un deseo.\n"
"Las Espadas Silbantes dicen: No abuses de nuestros poderes, mortal. Ya\n"
"hemos escuchado tus deseos.\n");
      return 1;
     }
     else {
         if (izet = find_object("izet") ) {
            tell_object(izet, "*** "+capitalize(getuid(TP))+" ha "
            "formulado el siguiente deseo:\n"+deseo+".\n");
        }
        log_file("DESEOS",ctime(time())+" ---> "+capitalize(getuid(TP))+" ha "
        "formulado el siguiente deseo:\n"+deseo+"\n");

	write(
"Las Espadas Silbantes dicen: Tus deseos han sido escuchados. Deberas\n"
"algun tiempo para que examinemos tus buenas y malas acciones.\n");
        say( TP->QueryName()+" pide un deseo a las Espadas Silbantes.\n"
"Las Espadas Silbantes dicen: Tus deseos han sido escuchados. Deberás\n"
"esperar algún tiempo para que examinemos tus buenas y malas acciones.\n");
        marca=clone_object("/d/Kha-annu/comun/objeto/magia/marca");
        marca->move(TP);
        return 1;
     }
}
