/* baskari.c
  Jefe de la compa��a.
  Tiene informaci�n sobre los miembros de la compa��a.
  Intentaremos que sea un poco 'Stan'...
  NOTA: Las comas han sido suprimidas a prop�sito...
  [n] nemesis@simauria

  Creaci�n: 05-Dic-2001 17:09:35 CET (hora y media en acabarlo... la firgen)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

create() {
  ::create();
 SetStandard("Baskari", "medio-elfo", 100, GENERO_MASCULINO);
  SetShort("Baskari, jefe de los artistas ambulantes");
  SetLong("Tienes ante ti a un medio-elfo bastante alto y de complexi�n fuerte. "
          "Te mira de arriba a abajo, como si buscase en ti a un posible cliente "
          "para sus productos. Piensas que as� miran los buitres a la gacela "
          "moribunda...\n");
  AddId(({"Baskari","baskari","se�or Baskari","se�or baskari","jefe",
          "jefe de los artistas","jefe de los artistas ambulantes"}));
  SetAlign(400);
  InitChats(5,({
   "Baskari dice: 'Si no consigo ayuda no llegaremos nunca a Lengor.'\n",
   "Baskari coge la rueda y le da vueltas como si buscase una manera de "
   "unirla de nuevo al eje.\n",
   "Baskari se seca el sudor con su pa�uelo.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"robo","ladr�n","ladrones"}),
  "Baskari te dice: 'En mi compa��a no hay ladrones. Todos saben a lo que "
  "se exponen si yo me entero de que andan en ese tipo de negocios.'\n",1);
  AddQuestion(({"l�tigo","latigo","l�tigo de Lady Morkobva",
                "l�tigo de lady Morkobva","l�tigo de lady morkobva",
                "latigo de Lady Morkobva","latigo de lady Morkobva",
                "latigo de lady morkobva"}),
  "Baskari te dice: 'S�, Lady Morkobva usa un l�tigo, si no �c�mo iba a "
  "a poder dominar a la terrible fiera?'\n",1);
  AddQuestion(({"aver�a","Lengor","lengor","averia","carro"
                "carro averiado","rueda averiada"}),
  W("Baskari te dice: 'Ver�s, s� que nos est�n esperando en Lengor, pero este "
    "maldito carro ha decidido averiarse en el peor momento. Es el carro donde "
    "guardamos nuestros �tiles de trabajo, y sin ellos no podemos actuar. "
    "Me parece que estaremos aqu� hasta que consiga arreglarlo.'\n"),1);
  AddQuestion(({"ayuda"}),
  "Baskari te dice: 'Muchas gracias por el ofrecimiento, pero de momento creo "
  "que puedo arregl�rmelas...'\n",1);

// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a","forzudo de la compa�ia"}),
  W("Baskari te dice: 'Una aut�ntica maravilla de la naturaleza. Grande como "
    "una casa y fuerte como un oso. En m�s de 100 combates nadie le ha tumbado "
    "jam�s. Un diamante en bruto. En MUY bruto, jejeje...'\n"),1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Baskari te dice: 'Un prodigio de equilibrio y agilidad. Juventud belleza "
  "y flexibilidad todo en uno. Bueno en dos.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Baskari te dice: 'Un aut�ntico prodigio de flexibilidad. Tendr�as que verla "
  "realizando equilibrios en la cuerda floja. Es un espect�culo digno de ser "
  "visto. Previo pago de mis honorarios, que son...'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Baskari te dice: 'Jam�s nadie ha realizado piruetas m�s espectaculares. "
  "S�lo igualado por su hermana. Los dos por el precio de uno. Los hay "
  "m�s baratos pero no son tan buenos.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Baskari te dice: 'Magia ilusi�n fantas�a. Un truco nuevo cada vez, una "
  "sorpresa nueva cada d�a �se es su lema. Si descubres el truco te "
  "devolvemos el dinero... si nos encuentras.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Baskari te dice: 'La mort�fera lanzadora Nikaia capaz de acertar a una "
  "mosca entre los ojos a doscientos pasos. Su ayudante puede estar tranquilo "
  "nunca falla. El n�mero con las hachas se paga aparte...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Baskari te dice: 'Bella pero fr�a como el hielo. Elegante pero mortal. "
  "Es la pantera. Y para hacerle frente y dominar a esa fiera nadie como "
  "nuestra domadora. Se necesitan nervios de acero decisi�n y mucha sangre "
  "fr�a pero Lady Morkobva tiene todo eso y m�s. Vea el excitante espect�culo "
  "de la Bella y la Bestia frente a frente. Y el no menos excitante espect�culo "
  "de las curvas de la Bella... todo por el mismo precio.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Baskari te dice: 'Las bellezas m�s ex�ticas del Norte el Sur y el Oeste "
  "en exclusiva para ti. Exotismo sensualidad y belleza en unos bailes que "
  "traen para ti la magia y el misterio de lejanas tierras.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Baskari te dice: 'Todo el exotismo de su raza directamente para ti desde "
  "las nieves del Norte.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Baskari te dice: 'Proveniente de una extra�a tribu de elfos s�lo ella "
  "puede desvelar los secretos que se esconden en las misteriosas danzas "
  "de su pueblo.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Baskari te dice: 'En sus ojos reside toda la magia de los pa�ses del Sur. "
  "Sus bailes te transportar�n a lugares a la orilla del mar donde el sol "
  "brilla siempre y el verano es eterno.'\n",1);
  AddQuestion(({"Baskari","baskari","se�or Baskari","se�or baskari",
                "senyor Baskari","senyor baskari"}),
  "Baskari hace una reverencia y te dice: 'Tu humilde servidor. Jefe de esta "
  "humilde compa��a de c�micos. Tambi�n soy actor y conozco miles de historias "
  "en prosa y en verso a cu�l m�s incre�ble.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Baskari te dice: 'Mi querida esposa. Pitonisa y curandera. Tiene grandes "
  "poderes sobre lo visible y lo invisible y es capaz de ver mucho de lo "
  "que fue lo que es y lo que vendr�. Tambi�n conoce multitud de recetas para "
  "hacer pociones y filtros de todas clases.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Baskari te dice: 'Nuestro grupo de payasos. Diversi�n sana para toda la "
  "familia. Disponibles s�lo en grupo, no por separado.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Baskari te dice: 'Conoce cientos de miles de chistes. Una hora con �l "
  "es diversi�n asegurada.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Baskari te dice: 'Incansable creador de bromas. �Nadie est� a salvo!'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Baskari te dice: 'Inventor incansable de divertidas m�quinas. �No te pierdas "
    "nuestro 'Museo de las Cosas Imposibles' si quieres conocer una m�nima "
    "parte de lo que es capaz su talento! La entrada cuesta 5 monedas de plata.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
  W("Baskari te dice: 'Tiene un talento para las m�quinas similar al de su hermano "
    "Pinky pero lo utiliza en crear nuevas formas de expresi�n musical. Uno de "
    "sus conciertos te proporcionar� experiencias musicales como nunca antes has "
    "escuchado. Ni siquiera o�do.'\n"),1);
  AddQuestion(({"Clyde","clyde"}),
  "Baskari te dice: 'Es el payaso m�s peque�o pero no es el menor en diversi�n.'\n",1);
}
