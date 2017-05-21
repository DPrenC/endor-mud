/* baskari.c
  Jefe de la compañía.
  Tiene información sobre los miembros de la compañía.
  Intentaremos que sea un poco 'Stan'...
  NOTA: Las comas han sido suprimidas a propósito...
  [n] nemesis@simauria

  Creación: 05-Dic-2001 17:09:35 CET (hora y media en acabarlo... la firgen)
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
  SetLong("Tienes ante ti a un medio-elfo bastante alto y de complexión fuerte. "
          "Te mira de arriba a abajo, como si buscase en ti a un posible cliente "
          "para sus productos. Piensas que así miran los buitres a la gacela "
          "moribunda...\n");
  AddId(({"Baskari","baskari","señor Baskari","señor baskari","jefe",
          "jefe de los artistas","jefe de los artistas ambulantes"}));
  SetAlign(400);
  InitChats(5,({
   "Baskari dice: 'Si no consigo ayuda no llegaremos nunca a Lengor.'\n",
   "Baskari coge la rueda y le da vueltas como si buscase una manera de "
   "unirla de nuevo al eje.\n",
   "Baskari se seca el sudor con su pañuelo.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"robo","ladrón","ladrones"}),
  "Baskari te dice: 'En mi compañía no hay ladrones. Todos saben a lo que "
  "se exponen si yo me entero de que andan en ese tipo de negocios.'\n",1);
  AddQuestion(({"látigo","latigo","látigo de Lady Morkobva",
                "látigo de lady Morkobva","látigo de lady morkobva",
                "latigo de Lady Morkobva","latigo de lady Morkobva",
                "latigo de lady morkobva"}),
  "Baskari te dice: 'Sí, Lady Morkobva usa un látigo, si no ¿cómo iba a "
  "a poder dominar a la terrible fiera?'\n",1);
  AddQuestion(({"avería","Lengor","lengor","averia","carro"
                "carro averiado","rueda averiada"}),
  W("Baskari te dice: 'Verás, sé que nos están esperando en Lengor, pero este "
    "maldito carro ha decidido averiarse en el peor momento. Es el carro donde "
    "guardamos nuestros útiles de trabajo, y sin ellos no podemos actuar. "
    "Me parece que estaremos aquí hasta que consiga arreglarlo.'\n"),1);
  AddQuestion(({"ayuda"}),
  "Baskari te dice: 'Muchas gracias por el ofrecimiento, pero de momento creo "
  "que puedo arreglármelas...'\n",1);

// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía","forzudo de la compañia"}),
  W("Baskari te dice: 'Una auténtica maravilla de la naturaleza. Grande como "
    "una casa y fuerte como un oso. En más de 100 combates nadie le ha tumbado "
    "jamás. Un diamante en bruto. En MUY bruto, jejeje...'\n"),1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Baskari te dice: 'Un prodigio de equilibrio y agilidad. Juventud belleza "
  "y flexibilidad todo en uno. Bueno en dos.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Baskari te dice: 'Un auténtico prodigio de flexibilidad. Tendrías que verla "
  "realizando equilibrios en la cuerda floja. Es un espectáculo digno de ser "
  "visto. Previo pago de mis honorarios, que son...'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Baskari te dice: 'Jamás nadie ha realizado piruetas más espectaculares. "
  "Sólo igualado por su hermana. Los dos por el precio de uno. Los hay "
  "más baratos pero no son tan buenos.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Baskari te dice: 'Magia ilusión fantasía. Un truco nuevo cada vez, una "
  "sorpresa nueva cada día ése es su lema. Si descubres el truco te "
  "devolvemos el dinero... si nos encuentras.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Baskari te dice: 'La mortífera lanzadora Nikaia capaz de acertar a una "
  "mosca entre los ojos a doscientos pasos. Su ayudante puede estar tranquilo "
  "nunca falla. El número con las hachas se paga aparte...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Baskari te dice: 'Bella pero fría como el hielo. Elegante pero mortal. "
  "Es la pantera. Y para hacerle frente y dominar a esa fiera nadie como "
  "nuestra domadora. Se necesitan nervios de acero decisión y mucha sangre "
  "fría pero Lady Morkobva tiene todo eso y más. Vea el excitante espectáculo "
  "de la Bella y la Bestia frente a frente. Y el no menos excitante espectáculo "
  "de las curvas de la Bella... todo por el mismo precio.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Baskari te dice: 'Las bellezas más exóticas del Norte el Sur y el Oeste "
  "en exclusiva para ti. Exotismo sensualidad y belleza en unos bailes que "
  "traen para ti la magia y el misterio de lejanas tierras.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Baskari te dice: 'Todo el exotismo de su raza directamente para ti desde "
  "las nieves del Norte.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Baskari te dice: 'Proveniente de una extraña tribu de elfos sólo ella "
  "puede desvelar los secretos que se esconden en las misteriosas danzas "
  "de su pueblo.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Baskari te dice: 'En sus ojos reside toda la magia de los países del Sur. "
  "Sus bailes te transportarán a lugares a la orilla del mar donde el sol "
  "brilla siempre y el verano es eterno.'\n",1);
  AddQuestion(({"Baskari","baskari","señor Baskari","señor baskari",
                "senyor Baskari","senyor baskari"}),
  "Baskari hace una reverencia y te dice: 'Tu humilde servidor. Jefe de esta "
  "humilde compañía de cómicos. También soy actor y conozco miles de historias "
  "en prosa y en verso a cuál más increíble.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Baskari te dice: 'Mi querida esposa. Pitonisa y curandera. Tiene grandes "
  "poderes sobre lo visible y lo invisible y es capaz de ver mucho de lo "
  "que fue lo que es y lo que vendrá. También conoce multitud de recetas para "
  "hacer pociones y filtros de todas clases.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Baskari te dice: 'Nuestro grupo de payasos. Diversión sana para toda la "
  "familia. Disponibles sólo en grupo, no por separado.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Baskari te dice: 'Conoce cientos de miles de chistes. Una hora con él "
  "es diversión asegurada.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Baskari te dice: 'Incansable creador de bromas. ¡Nadie está a salvo!'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Baskari te dice: 'Inventor incansable de divertidas máquinas. ¡No te pierdas "
    "nuestro 'Museo de las Cosas Imposibles' si quieres conocer una mínima "
    "parte de lo que es capaz su talento! La entrada cuesta 5 monedas de plata.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
  W("Baskari te dice: 'Tiene un talento para las máquinas similar al de su hermano "
    "Pinky pero lo utiliza en crear nuevas formas de expresión musical. Uno de "
    "sus conciertos te proporcionará experiencias musicales como nunca antes has "
    "escuchado. Ni siquiera oído.'\n"),1);
  AddQuestion(({"Clyde","clyde"}),
  "Baskari te dice: 'Es el payaso más pequeño pero no es el menor en diversión.'\n",1);
}
