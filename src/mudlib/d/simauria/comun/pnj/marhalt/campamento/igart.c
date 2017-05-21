/* igart.c
  Bailarina kainoak.
  Tiene informaci�n relativa al caso del l�tigo desaparecido.
  [n] nemesis@simauria

  Creaci�n: 05-Dic-2001 00:01:47 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_robo() {
 if(TP->Query("beni_acusa"))
  return W("Le cuentas a Igart lo que Beni te ha contado sobre el robo del l�tigo "
           "de Lady Morkobva. La sonrisa se borra de su cara y te dice: '�Esa "
           "renacuaja de Beni te ha dicho eso? Pues ya le puedes decir que "
           "nosotras no somos tan rastreras. Adem�s, si quisi�ramos hacerle algo "
           "a ella o a su hermanito, lo har�amos cara a cara. Le puedes decir "
           "que si quiere hacer alguna acusaci�n, que nos lo diga a la cara. "
           "Entonces ajustaremos cuentas.'\n");
  else return "Igart te dice: 'No s� de qu� carajo me hablas.'\n";
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return "Igart te dice: '�sa soy yo. �Quieres algo, cari�o?'\n";
 else return "Igart te dice: '�sa soy yo. �Quieres algo?'\n";
}

create() {
  ::create();
 SetStandard("Igart", "kainoak", 100, GENERO_FEMENINO);
  SetShort("Igart, una bailarina");
  SetLong("Una joven kainoak m�s esbelta de lo que es natural en estos seres. "
          "Sin duda esto la ayuda en su profesi�n, y hace que se mueva m�s "
          "insinuantemente. Al ver que la miras, te sonr�e con descaro.\n");
  // En la habitaci�n habr� un AddDetail tal que as�n:
  // AddDetail(({"bailarina ex�tica","bailarina exotica","bailarina"}),
  //           "�Cu�l de las tres?");
  AddId(({"Igart","igart","bailarina kainoak"}));
  SetAlign(400);
  InitChats(5,({
   "Igart dice: 'Ya ha vuelto Lattini a poner un clavel en mi ventana. �No se "
   "da por vencido nunca!'\n Las otras dos r�en con ganas.\n",
   "Igart comienza unos pasos de baile, pero al ver que la miras se para.\n",
   "Igart le dice algo al o�do a Morda mirando a Kwailin. De pronto ambas "
   "estallan en sonoras carcajadas.\n",
   "Igart, Kwailin y Morda te miran y cuchichean algo entre ellas. Luego "
   "comienzan a re�r.\n"
  }));
  // Questions... Laaarga lista... (no �sta, en general)
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a","forzudo de la compa�ia"}),
  "Igart te dice: 'Andr� es nuestro 'hombre fuerte'. Pero no creas que por ser "
  "grande es tonto. No, eso lo creen los dem�s, pero yo s� que es muy listo. "
  "Adem�s, tiene un gran coraz�n y siempre est� dispuesto a usar su fuerza "
  "para ayudar a los m�s d�biles.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Igart te dice: 'Yo no s� qu� le ve la gente a las contorsiones y ejercicios "
  "que hacen esos dos. Se lo digo siempre a Baskari: saldr�an m�s baratos unos "
  "cuantos monos. Claro que �l prefiere ahorrar en nuestros sueldos. �Mira mi "
  "vestido! Lo he remendado no s� cu�ntas veces, pero �l no quiere comprarnos "
  "nuevos vestidos, dice que ser�a mucho gasto. Ser� hur�n...'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Igart te dice: 'No me hables de esa ni�ata. Es la excusa que Baskari usa "
  "para no aumentar nuestro sueldo. Que baila mejor... ya me gustar�a ver a "
  "esa remilgada bailando delante de todos esos salvajes, aguantando lo que "
  "nosotras tenemos que aguantar... Y todo �para qu�? Para que Baskari se "
  "quede con el dinero que ganamos y luego nos d� una miseria.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Igart te dice: 'El hermano de esa remilgada de Beni. Me gustar�a ver la "
  "cara que pone si Baskari le dice que su hermanita tiene que salir "
  "pr�cticamente desnuda a contonearse delante de los hombres. Creo que "
  "Baskari se llevar�a una buena sorpresa.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Igart te dice: 'Es el ilusionista de la caravana. Domina toda clase de "
  "juegos de manos, t� ya me entiendes. Su esposa me da un poco de pena, "
  "porque creo que se ha acostado con todas las mujeres que se le han "
  "puesto a tiro. Bueno, excepto quiz� con Lady Morkobva. Pero es normal, "
  "no creo que esa fr�gida sepa apreciar a un hombre como �l.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Igart te dice: '�La esposa de Lattini? Pobrecita. Tiene que agacharse "
  "para pasar por las puertas, ya me entiendes... �Ja, ja, ja!'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Igart te dice: '��sa? Va de mujer dura por la vida, con su traje de cuero "
  "y sus l�tigos, y sus cadenas... Ahora, te digo que en el fondo es una "
  "frustrada que no sabr�a qu� hacer si un hombre se le insinuase. Bueno, s� "
  "que lo sabe: arrearle un zurriagazo... Pero es lo que yo digo, es m�s "
  "divertido ser apasionada de otra forma...'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Igart te dice: 'Las tienes delante: las mejores bailarinas del norte, del "
  "este y del sur, a tu servicio por un pu�ado de monedas.'\n",1);
  AddQuestion(({"Igart","igart"}),SF(answ_self),1);
  AddQuestion(({"Morda","morda"}),
  "Igart te dice: 'Mi compa�era, aqu� presente. Preg�ntale lo que quieras, "
  "que estoy segura que te contestar� con placer.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("Igart te dice: 'Mi compa�era m�s joven. Entre nosotros... �ltimamente est� muy "
    "rara, y no para de hacerle ojitos a ese imb�cil de Mossi. Mira que si "
    "se enamora de semejante idiota...'\n"),1);
  AddQuestion(({"Baskari","baskari","se�or Baskari","se�or baskari",
                "senyor Baskari","senyor baskari"}),
  "Igart te dice: 'Es un explotador, que se enriquece a costa nuestra. "
  "Le gusta aparentar que tiene coraz�n recogiendo a muertos de hambre "
  "como los gemelos Trassi, pero en el fondo s�lo tiene un inter�s: "
  "el dinero y los beneficios. Pero ya llegar� la revoluci�n...'\n",1); // Un poco rojilla s� es...
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Igart te dice: 'La esposa de Baskari. Es la �nica que sabe ponerle en "
  "su sitio cuando se enfada o nos grita sin raz�n. Las cosas nos ir�an "
  "mejor con ella al mando.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Igart te dice: '�No me hables! �Menudos gamberros! Por aquello de que son "
  "peque�os, a Andr� le caen bastante bien, pero lo cierto es que al final "
  "vamos a tener que echarlos. Desde que est�n con nosotros s�lo nos han "
  "causado problemas. Parecen tener una fijaci�n especial con Baskari y su "
  "esposa. S�lo sent� aquella vez que casi matan a Beni. Qu� rabia que "
  "fallaran, oyes...'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Igart te dice: 'El mayor de los hermanos Kutiri. Y el peor.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Igart te dice: 'Uno de los hermanos Kutiri. Es m�s guarro que la mierda.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Igart te dice: 'Uno de los hermanos Kutiri. Suele definirse como inventor "
  "de aparatos in�tiles.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Igart te dice: 'Uno de los hermanos Kutiri. Un aut�ntico ladr�n. Y m�s "
 "malo que la ti�a.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Igart te dice: 'Uno de los hermanos Kutiri. Hay algo en �l que no parece "
  "de la misma familia... y no me refiero s�lo al nombre...'\n",1);
}
