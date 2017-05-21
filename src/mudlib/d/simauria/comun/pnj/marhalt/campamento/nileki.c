/* nileki.c
  Adivina y fabricante de pociones.
  Necesita unos pelos de pantera para preparar una poción.
  A cambio te dará la daga que Lattini le dió en pago por el filtro amoroso.
  [n] nemesis@simauria

  Creación: 06-Dic-2001 01:12:19 CET (todo el mundo de puente y yo con esto...)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Funciones para responder a las preguntas...
// Va a tener tela. Al menos eso pretendo...

private string answ_daga_nikaia() {
 if(TI->QueryGender() == GENDER_FEMALE) {
  TP->Set("talked_nileki",1);
  return W("Le cuentas a Madamme Nileki lo que te dijo Lattini. Ella te mira "
           "con incredulidad por un momento y se echa a reír. Cuando se le pasa "
           "el ataque de risa, te dice: '¡Ay, querida! ¿De verdad te creíste que "
           "Lattini \"perdió\" la daga de su esposa? Mira, te contaré la verdad "
           "para que veas la clase de tipo que es. Casado y todo como está, "
           "su mayor afición es perseguir a las mujeres, sin distinción de "
           "raza, edad o condición. Y ahora está obsesionado con Lady Morkobva, "
           "de manera que me pidió que le fabricara un filtro amoroso para "
           "seducirla. Por supuesto le engañé, pero eso no impidió que el muy "
           "iluso me pagara con la famosa daga. "
           "Madamme Nileki se queda pensativa un momento y te dice: "
           "'Muy bien, te la daré. No creo que a mi marido le gustase que "
           "el único ilusionista que tenemos cogiese una pulmonía. Pero "
           "antes tendrás que hacerme un pequeño favor. Quiero darle una"
           "lección a Lattini y necesito ayuda.'\n");

 }
 else return W("Madamme Nileki te mira con desdén y te dice: 'Así que quiere "
               "recuperar su daga. Y tú te has prestado a ayudarle a pesar "
               "de saber cómo es. Hombres... a veces no sé si merece la pena "
               "indignarse contra el sexo masculino o vale más prescindir "
               "completamente de él por excesivamente despreciable...' "
               "Madamme Nileki se queda pensativa un momento y te dice: "
               "'Muy bien, te la daré. No creo que a mi marido le gustase que "
               "el único ilusionista que tenemos cogiese una pulmonía. Pero "
               "antes tendrás que hacerme un pequeño favor.'\n");
}

private string answ_favor() {
 if(!TI->Query("talked_nileki"))
  return "Nileki te mira extrañada: '¿Favor? Yo no te he pedido ningún favor.'\n";
 else {
  if(TI->QueryGender() == GENDER_FEMALE)
   return W("Madamme Nileki te dice: 'Verás, la verdad es que todas las mujeres "
            "de la compañía estamos hartas de los líos de faldas de Lattini, "
            "así que tenemos dos opciones: contárselo a Nikaia, o intentar "
            "evitarlos. Con lo celosa que es Nikaia, la primera opción supondría "
            "la muerte de Lattini para empezar, y tal vez de Igart y Morda, "
            "lo que sería desastroso para el negocio, así que "
            "hemos decidido poner remedio. Voy a hacer una poción de 'Fidelidad "
            "Infinita', para que Lattini sólo piense en su esposa. Pero me hace "
            "falta el ingrediente principal.'\n");
  // A un hombre le miente descaradamente :)
  else return W("La cara de Madamme Nileki se pone muy seria y te dice: "
                "'Verás, el hijo de mi hermana se está muriendo de una enfermedad "
                "muy rara y ella me ha pedido que le prepare un remedio. Puedo hacerlo, "
                "pero me hace falta el ingrediente principal.'\n");
 }
}

private string answ_ingrediente() {
 if(!TI->Query("talked_nileki"))
  return W("Nileki te dice: '¿Pero qué te has creído? Yo no le "
           "revelo mis secretos a cualquiera.'\n");
 else return W("Nileki te dice: 'El ingrediente principal para la poción son unos pelos de pantera. "
               "Tienen que estar recién cortados o no sirven de nada...'\n");
}

private string answ_pelos() {
 if(TI->Query("talked_nileki")) {
  TI->Set("know_hair",1);
  return W("Madamme Nileki te dice: 'Lady Morkobva tiene una pantera. Estoy "
           "segura de que en un caso como éste no le importará molestar a su "
           "gatita para darte lo que le pides.'\n");
 }
 else
  return W("Madamme Nileki te dice: '¿Por qué esa pregunta tan rara? "
           "¿Me he perdido algo?'\n");
}


private string answ_trassi() {
 return W("Madamme Nileki te dice: 'Una triste historia. Cuando Rufus y Soraya nos "
          "dejaron hace unos tres años, mi marido los contrató a ellos. Desde el "
          "principio no le cayeron muy bien a nadie, salvo a Lady Morkobva, que los "
          "acogió, yo creo que en parte para proteger a Beni de Lattini. El caso es "
          "que con el tiempo las cosas parecen haber ido mejorando. Nunca podrán "
          "llenar el hueco que dejaron sus antecesores, pero después de tres años "
          "los recelos iniciales se han ido desvaneciendo, y unos nos hemos ido "
          "acostumbrando a los otros.'\n");
}

private string answ_lattini() {
 if(TI->Query("talked_nileki")) {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: '¿Después de lo que te he contado todavía "
            "quieres saber más? Pues la verdad es que no hay mucho que decir. "
            "Mujeriego, borracho, jugador y pendenciero. Ése es Lattini. Y creo "
            "que una joven como tú no necesita que le diga nada más para saber "
            "que no le conviene relacionarse con él.'\n");
  else return W("Madamme Nileki te dice: 'No me apetece hablar de él ahora mismo. "
                "Pero estoy segura de que a él no le importará hablarte de sus "
                "múltiples conquistas con todo lujo de detalles...'\n");
 }
 else {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Mira, no creo que te convenga. Es todo lo "
            "que tengo que decir. Si quieres saber más, pregúntale a cualquiera "
            "de las mujeres de la compañía.'\n");
   else return W("Madamme Nileki te dice: '¿Lattini? No creo que yo pueda decir "
                 "de él nada que no te pueda decir cualquier otro miembro femenino "
                 "de la compañía.'\n");
 }
}

private string answ_morkobva() {
 if(TI->Query("know_hair")) {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Lady Morkobva tiene una pantera. Hay quien "
            "dice que la quiere más que a muchas personas, pero estoy segura de "
            "que estará encantada de ayudarnos a darle una lección a Lattini.'\n");
  else return W("Madamme Nileki te dice: 'Lady Morkobva tiene una pantera. Ya está "
                "al corriente de mi problema, seguro que si le dices que te "
                "envío yo, te ayudará encantada. No es tan mala como la pintan.'\n");
 }
 else {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Lady Morkobva es la domadora de fieras. "
            "realmente sólo tiene una fiera, que es su pantera, pero si tuviera "
            "más, también las domaría. Casi todos recelan de ella porque "
            "tiene un carácter muy fuerte y no se deja avasallar. Cuando era "
            "muy joven tuvo una mala experiencia amorosa y desde entonces "
            "no ha vuelto a confiar en nadie. Creo que fue una suerte que "
            "vinieran los gemelos Trassi, ya que desde que están con nosotros "
            "su carácter se ha dulcificado.'\n");
  else return W("Madamme Nileki te dice: 'Lady Morkobva es la domadora de fieras. "
                "realmente sólo tiene una fiera, que es su pantera, pero si tuviera "
                "más, también las domaría. Casi todos recelan de ella porque "
                "tiene un carácter muy fuerte y no se deja avasallar. Pero "
                "puedes estar seguro de que en el fondo tiene buen corazón.'\n");
 }
}

private string answ_nikaia() {
 if( (TI->Query("talked_nileki")) &&
     (TI->QueryGender() == GENERO_FEMENINO) )
   return W("Madamme Nileki te dice: 'Francamente, si no fuera por ella, habría "
            "convertido en sapo a Lattini hace tiempo. Pero Nikaia me cae bien "
            "y no se merece lo que esa sabandija hace con ella. Cometió el error "
            "de enamorarse de quien no debía, pero ella no tiene la culpa. Si me "
            "ayudas, convertiré a Lattini en el marido que ella se merece'.\n");
 else {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Nikaia es nuestra lanzadora de cuchillos. "
            "Está casada con Lattini. Sabiendo cómo es ella, no sé cómo se atreve "
            "Lattini a mirar a otras mujeres, pero supongo que él cree que el "
            "amor es ciego. Y ciego puede que sea, pero no imbécil. Un día Lattini "
            "descubrirá que Nikaia no está tan ciega como él cree y ocurrirá una "
            "desgracia...'\n");
  else return W("Madamme Nileki te dice: 'Nikaia es nuestra lanzadora de cuchillos. "
                "Tiene nervios de acero y es infalible. A pesar de ser una "
                "coleccionista incansable de armas raras, es muy pacífica y "
                "sólo le gusta lanzar sus cuchillos contra los blancos de su "
                "espectáculo. Pero que eso no te engañe. Cuando se enfada es "
                "una auténtica fiera.'\n");
 }
}

// create
create() {
  ::create();
 SetStandard("Madamme Nileki", "medio-elfo", 100, GENERO_FEMENINO);
  SetLong(W("Es una medio-elfo de edad indefinida, aunque no parece joven. "
            "El tiempo y las preocupaciones han dejado algunas arrugas en "
            "su frente, pero lo que te llama la atención son sus bellos ojos "
            "de color violeta, que parecen poder ver hasta los rincones más "
            "secretos de tu alma.\n"));
  SetShort("Madamme Nileki, la adivina");
  AddId(({"Madamme Nileki","madamme Nileki","Madamme nileki","madamme nileki",
          "adivina","pitonisa","nileki","Nileki"}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Madamme Nileki mira en una estantería y murmura: '¿Dónde lo habré metido?'\n",
   "Madamme Nileki mira fijamente su bola de cristal.\n",
   "Madamme Nileki te mira y te dice: 'Acércate, no tengas miedo.'\n",
   "Madamme Nileki murmura: 'A éste le ponía yo dos velas negras...'\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),SF(answ_daga_nikaia),1);
  AddQuestion(({"ingrediente","ingrediente principal"}),SF(answ_ingrediente),1);
  AddQuestion(({"favor"}),SF(answ_favor),1);
  AddQuestion(({"pelos de pantera","pelo de pantera"}),
                SF(answ_pelos),1);
  AddQuestion(({"Rufus y Soraya","rufus y soraya","Rufus y soraya",
                "rufus y Soraya"}),
          W("Nileki te dice: 'Eran los antiguos equilibristas. Hará cosa de tres años, Rufus "
            "tuvo un accidente y se cayó desde una altura de quince metros. "
            "Se partió el cuello y murió. Soraya no pudo volver a trabajar, "
            "decía que todo le recordaba a él. Finalmente nos dejó y volvió "
            "con sus padres, no recuerdo dónde. Tuvimos que contratar a "
            "alguien que los sustituyera, y los elegidos fueron los gemelos "
            "Trassi. Algunos les vieron como a unos intrusos que habían "
            "hecho que Soraya se fuera.'\n"),1);
  AddQuestion(({"Rufus","rufus"}),
          W("Nileki te dice: 'Rufus era uno de los antiguos equilibristas. Su muerte nos afectó "
            "a todos terriblemente, pero sobre todo a su esposa, Soraya.'\n"),1);
  AddQuestion(({"Soraya","soraya"}),
          W("Nileki te dice: 'Soraya era muy alegre. Siempre tenía una palabra amable y una sonrisa "
            "para cualquiera que fuera a hablar con ella. La muerte de Rufus le "
            "afectó mucho. Se pasaba el día llorando y ninguno de nosotros podía "
            "consolarla. No he sabido nada de ella desde que se fue.'\n"),1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "Madamme Nileki te dice: 'Probablemente es el mejor de todos nosotros. Sabe "
  "escuchar, y siempre tiene una palabra de ánimo. No es muy inteligente, pero "
  "no es tan tonto como dicen. Sólo es demasiado bueno.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),SF(answ_trassi),1);
  AddQuestion(({"Beni","beni"}),
  W("Madamme Nileki te dice: 'Cuando llegó era casi una niña, muy dulce, aunque "
    "un poco melancólica. Lady Morkobva la tomó bajo su protección, sabiendo "
    "que Lattini tarde o temprano iría tras ella. La verdad es que esto la "
    "perjudicó, porque Lady Morkobva no es muy popular por aquí, pero lo "
    "cierto es que ahí demostró que tiene buen corazón. En estos tres años "
    "Beni ha crecido mucho, y se ha convertido en una mujercita amable, dulce "
    "amable, dulce y alegre, aunque la tristeza acumulada de tantos años vagando "
    "por las calles mendigando un trozo de pan no se le borrará nunca.\n"),1);
  AddQuestion(({"Mossi","mossi"}),
  W("Madamme Nileki te dice: 'Cuando llegó no se fiaba de nadie, y estaba siempre "
    "dispuesto a iniciar una pelea si creía que alguien molestaba a su hermana. "
    "Eso no le hizo muy popular precisamente, pero creo que en estos años ha "
    "aprendido a confiar un poco en las personas, y su carácter se ha vuelto "
    "un poco menos áspero. Eso sí, si cree que le estás haciendo daño a su "
    "hermana no dudará en protegerla, como Lattini comprobó en sus carnes...'\n"),1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),SF(answ_lattini),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
                SF(answ_nikaia),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),SF(answ_morkobva),1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Madamme Nileki te dice: 'Nuestras bailarinas exóticas. Baskari las eligió "
  "personalmente, pero sólo trabajan para él. Sabe lo que le haré si intenta "
  "ir más lejos.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Madamme Nileki te dice: 'La verdad es que al principio pensé que mi marido "
  "estaba loco. ¡Una kainoak bailarina! ¿Puedes imaginarlo? Yo tampoco, pero "
  "la verdad es que la chica no lo hace mal.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Madamme Nileki te dice: 'Casi todo el mundo piensa que es una medio-elfa "
  "mulata, aunque ella dice que es de una tribu de elfos que tienen la piel "
  "oscura. Lo cierto es que yo no sé que pensar. Y es que, aunque la verdad "
  "es que lo de un elfo negro me parece raro, no veo en ella a una de mi "
  "raza, es demasiado... mmm... élfica.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Madamme Nileki te dice: 'Es una buena chica, aunque durante un tiempo fue "
  "un poco rebelde, como sus compañeras de baile. Sin embargo, últimamente "
  "es mucho más civilizada, e incluso está intentando que Beni le perdone "
  "ciertas maldades pasadas.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Madamme Nileki suspira: 'Ay, ¿qué puedo decir de ese granuja? Es tacaño, "
  "desvergonzado y no tiene escrúpulos. Es un auténtico bribón, pero es "
  "encantador. Eso sí, cuando quiere sabe tener buen corazón. Y le encanta "
  "el mundo del espectáculo, se dedica a ello desde pequeño y no sabe hacer "
  "otra cosa. Al principio no podía ni verle, pero puede ser tan persuasivo "
  "cuando quiere... Y tiene una labia...'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Madamme Nileki te dice: 'Madamme Nileki, pitonisa, experta en pociones y "
  "encantamientos. ¿Qué puedo hacer por ti?'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Madamme Nileki te dice: 'Son un grupo de payasos kenders que contratamos "
  "hace casi siete años. La verdad es que nos han traído muchos problemas, "
  "pero Baskari no se decide a despedirlos. Son muy buenos y nos hacen "
  "ganar mucho dinero.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Madamme Nileki te dice: 'Es el mayor de los hermanos Kutiri. Hace de payaso "
  "listo, y la verdad es que tonto no es, aunque pueda parecerlo.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Madamme Nileki te dice: 'Es el ser más sucio que he tenido la desgracia de "
  "conocer en mi vida.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Madamme Nileki te dice: 'Se hace llamar inventor, aunque su orgullo es que "
  "todavía no ha inventado nada útil. El \"Museo de las Cosas Imposibles\" nos "
  "proporciona unos buenos ingresos, y todos los artilugios que hay allí son "
  "obra suya. Es increíble la habilidad que tiene para las cosas inútiles.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Madamme Nileki te dice: 'Su perdición es que le atrae todo lo que no es suyo. "
 "Más de una vez hemos tenido que salir a escape de un pueblo por culpa suya.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Madamme Nileki te dice: 'Es el más pequeño y hace de payaso tonto. Los otros "
  "son bastante crueles con él porque su nombre es diferente.'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Madamme Nileki dice: 'Muchas gracias. Ahora ya podré preparar la poción'. "
 "Acto seguido, saca una hermosa daga de un cajón y te la entrega.\n");
 // Texto que te da las demás veces que lo resuelvas
 SetAgainText("Madamme Nileki te dice: 'Muchas gracias, nunca viene mal tener un poco "
              "de reserva.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: nileki;
 // Las tres últimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","nileki",({"p_hair"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/daga_nikaia");
}
