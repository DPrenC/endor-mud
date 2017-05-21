/* nileki.c
  Adivina y fabricante de pociones.
  Necesita unos pelos de pantera para preparar una poci�n.
  A cambio te dar� la daga que Lattini le di� en pago por el filtro amoroso.
  [n] nemesis@simauria

  Creaci�n: 06-Dic-2001 01:12:19 CET (todo el mundo de puente y yo con esto...)
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
           "con incredulidad por un momento y se echa a re�r. Cuando se le pasa "
           "el ataque de risa, te dice: '�Ay, querida! �De verdad te cre�ste que "
           "Lattini \"perdi�\" la daga de su esposa? Mira, te contar� la verdad "
           "para que veas la clase de tipo que es. Casado y todo como est�, "
           "su mayor afici�n es perseguir a las mujeres, sin distinci�n de "
           "raza, edad o condici�n. Y ahora est� obsesionado con Lady Morkobva, "
           "de manera que me pidi� que le fabricara un filtro amoroso para "
           "seducirla. Por supuesto le enga��, pero eso no impidi� que el muy "
           "iluso me pagara con la famosa daga. "
           "Madamme Nileki se queda pensativa un momento y te dice: "
           "'Muy bien, te la dar�. No creo que a mi marido le gustase que "
           "el �nico ilusionista que tenemos cogiese una pulmon�a. Pero "
           "antes tendr�s que hacerme un peque�o favor. Quiero darle una"
           "lecci�n a Lattini y necesito ayuda.'\n");

 }
 else return W("Madamme Nileki te mira con desd�n y te dice: 'As� que quiere "
               "recuperar su daga. Y t� te has prestado a ayudarle a pesar "
               "de saber c�mo es. Hombres... a veces no s� si merece la pena "
               "indignarse contra el sexo masculino o vale m�s prescindir "
               "completamente de �l por excesivamente despreciable...' "
               "Madamme Nileki se queda pensativa un momento y te dice: "
               "'Muy bien, te la dar�. No creo que a mi marido le gustase que "
               "el �nico ilusionista que tenemos cogiese una pulmon�a. Pero "
               "antes tendr�s que hacerme un peque�o favor.'\n");
}

private string answ_favor() {
 if(!TI->Query("talked_nileki"))
  return "Nileki te mira extra�ada: '�Favor? Yo no te he pedido ning�n favor.'\n";
 else {
  if(TI->QueryGender() == GENDER_FEMALE)
   return W("Madamme Nileki te dice: 'Ver�s, la verdad es que todas las mujeres "
            "de la compa��a estamos hartas de los l�os de faldas de Lattini, "
            "as� que tenemos dos opciones: cont�rselo a Nikaia, o intentar "
            "evitarlos. Con lo celosa que es Nikaia, la primera opci�n supondr�a "
            "la muerte de Lattini para empezar, y tal vez de Igart y Morda, "
            "lo que ser�a desastroso para el negocio, as� que "
            "hemos decidido poner remedio. Voy a hacer una poci�n de 'Fidelidad "
            "Infinita', para que Lattini s�lo piense en su esposa. Pero me hace "
            "falta el ingrediente principal.'\n");
  // A un hombre le miente descaradamente :)
  else return W("La cara de Madamme Nileki se pone muy seria y te dice: "
                "'Ver�s, el hijo de mi hermana se est� muriendo de una enfermedad "
                "muy rara y ella me ha pedido que le prepare un remedio. Puedo hacerlo, "
                "pero me hace falta el ingrediente principal.'\n");
 }
}

private string answ_ingrediente() {
 if(!TI->Query("talked_nileki"))
  return W("Nileki te dice: '�Pero qu� te has cre�do? Yo no le "
           "revelo mis secretos a cualquiera.'\n");
 else return W("Nileki te dice: 'El ingrediente principal para la poci�n son unos pelos de pantera. "
               "Tienen que estar reci�n cortados o no sirven de nada...'\n");
}

private string answ_pelos() {
 if(TI->Query("talked_nileki")) {
  TI->Set("know_hair",1);
  return W("Madamme Nileki te dice: 'Lady Morkobva tiene una pantera. Estoy "
           "segura de que en un caso como �ste no le importar� molestar a su "
           "gatita para darte lo que le pides.'\n");
 }
 else
  return W("Madamme Nileki te dice: '�Por qu� esa pregunta tan rara? "
           "�Me he perdido algo?'\n");
}


private string answ_trassi() {
 return W("Madamme Nileki te dice: 'Una triste historia. Cuando Rufus y Soraya nos "
          "dejaron hace unos tres a�os, mi marido los contrat� a ellos. Desde el "
          "principio no le cayeron muy bien a nadie, salvo a Lady Morkobva, que los "
          "acogi�, yo creo que en parte para proteger a Beni de Lattini. El caso es "
          "que con el tiempo las cosas parecen haber ido mejorando. Nunca podr�n "
          "llenar el hueco que dejaron sus antecesores, pero despu�s de tres a�os "
          "los recelos iniciales se han ido desvaneciendo, y unos nos hemos ido "
          "acostumbrando a los otros.'\n");
}

private string answ_lattini() {
 if(TI->Query("talked_nileki")) {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: '�Despu�s de lo que te he contado todav�a "
            "quieres saber m�s? Pues la verdad es que no hay mucho que decir. "
            "Mujeriego, borracho, jugador y pendenciero. �se es Lattini. Y creo "
            "que una joven como t� no necesita que le diga nada m�s para saber "
            "que no le conviene relacionarse con �l.'\n");
  else return W("Madamme Nileki te dice: 'No me apetece hablar de �l ahora mismo. "
                "Pero estoy segura de que a �l no le importar� hablarte de sus "
                "m�ltiples conquistas con todo lujo de detalles...'\n");
 }
 else {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Mira, no creo que te convenga. Es todo lo "
            "que tengo que decir. Si quieres saber m�s, preg�ntale a cualquiera "
            "de las mujeres de la compa��a.'\n");
   else return W("Madamme Nileki te dice: '�Lattini? No creo que yo pueda decir "
                 "de �l nada que no te pueda decir cualquier otro miembro femenino "
                 "de la compa��a.'\n");
 }
}

private string answ_morkobva() {
 if(TI->Query("know_hair")) {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Lady Morkobva tiene una pantera. Hay quien "
            "dice que la quiere m�s que a muchas personas, pero estoy segura de "
            "que estar� encantada de ayudarnos a darle una lecci�n a Lattini.'\n");
  else return W("Madamme Nileki te dice: 'Lady Morkobva tiene una pantera. Ya est� "
                "al corriente de mi problema, seguro que si le dices que te "
                "env�o yo, te ayudar� encantada. No es tan mala como la pintan.'\n");
 }
 else {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Lady Morkobva es la domadora de fieras. "
            "realmente s�lo tiene una fiera, que es su pantera, pero si tuviera "
            "m�s, tambi�n las domar�a. Casi todos recelan de ella porque "
            "tiene un car�cter muy fuerte y no se deja avasallar. Cuando era "
            "muy joven tuvo una mala experiencia amorosa y desde entonces "
            "no ha vuelto a confiar en nadie. Creo que fue una suerte que "
            "vinieran los gemelos Trassi, ya que desde que est�n con nosotros "
            "su car�cter se ha dulcificado.'\n");
  else return W("Madamme Nileki te dice: 'Lady Morkobva es la domadora de fieras. "
                "realmente s�lo tiene una fiera, que es su pantera, pero si tuviera "
                "m�s, tambi�n las domar�a. Casi todos recelan de ella porque "
                "tiene un car�cter muy fuerte y no se deja avasallar. Pero "
                "puedes estar seguro de que en el fondo tiene buen coraz�n.'\n");
 }
}

private string answ_nikaia() {
 if( (TI->Query("talked_nileki")) &&
     (TI->QueryGender() == GENERO_FEMENINO) )
   return W("Madamme Nileki te dice: 'Francamente, si no fuera por ella, habr�a "
            "convertido en sapo a Lattini hace tiempo. Pero Nikaia me cae bien "
            "y no se merece lo que esa sabandija hace con ella. Cometi� el error "
            "de enamorarse de quien no deb�a, pero ella no tiene la culpa. Si me "
            "ayudas, convertir� a Lattini en el marido que ella se merece'.\n");
 else {
  if(TI->QueryGender() == GENERO_FEMENINO)
   return W("Madamme Nileki te dice: 'Nikaia es nuestra lanzadora de cuchillos. "
            "Est� casada con Lattini. Sabiendo c�mo es ella, no s� c�mo se atreve "
            "Lattini a mirar a otras mujeres, pero supongo que �l cree que el "
            "amor es ciego. Y ciego puede que sea, pero no imb�cil. Un d�a Lattini "
            "descubrir� que Nikaia no est� tan ciega como �l cree y ocurrir� una "
            "desgracia...'\n");
  else return W("Madamme Nileki te dice: 'Nikaia es nuestra lanzadora de cuchillos. "
                "Tiene nervios de acero y es infalible. A pesar de ser una "
                "coleccionista incansable de armas raras, es muy pac�fica y "
                "s�lo le gusta lanzar sus cuchillos contra los blancos de su "
                "espect�culo. Pero que eso no te enga�e. Cuando se enfada es "
                "una aut�ntica fiera.'\n");
 }
}

// create
create() {
  ::create();
 SetStandard("Madamme Nileki", "medio-elfo", 100, GENERO_FEMENINO);
  SetLong(W("Es una medio-elfo de edad indefinida, aunque no parece joven. "
            "El tiempo y las preocupaciones han dejado algunas arrugas en "
            "su frente, pero lo que te llama la atenci�n son sus bellos ojos "
            "de color violeta, que parecen poder ver hasta los rincones m�s "
            "secretos de tu alma.\n"));
  SetShort("Madamme Nileki, la adivina");
  AddId(({"Madamme Nileki","madamme Nileki","Madamme nileki","madamme nileki",
          "adivina","pitonisa","nileki","Nileki"}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Madamme Nileki mira en una estanter�a y murmura: '�D�nde lo habr� metido?'\n",
   "Madamme Nileki mira fijamente su bola de cristal.\n",
   "Madamme Nileki te mira y te dice: 'Ac�rcate, no tengas miedo.'\n",
   "Madamme Nileki murmura: 'A �ste le pon�a yo dos velas negras...'\n"
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
          W("Nileki te dice: 'Eran los antiguos equilibristas. Har� cosa de tres a�os, Rufus "
            "tuvo un accidente y se cay� desde una altura de quince metros. "
            "Se parti� el cuello y muri�. Soraya no pudo volver a trabajar, "
            "dec�a que todo le recordaba a �l. Finalmente nos dej� y volvi� "
            "con sus padres, no recuerdo d�nde. Tuvimos que contratar a "
            "alguien que los sustituyera, y los elegidos fueron los gemelos "
            "Trassi. Algunos les vieron como a unos intrusos que hab�an "
            "hecho que Soraya se fuera.'\n"),1);
  AddQuestion(({"Rufus","rufus"}),
          W("Nileki te dice: 'Rufus era uno de los antiguos equilibristas. Su muerte nos afect� "
            "a todos terriblemente, pero sobre todo a su esposa, Soraya.'\n"),1);
  AddQuestion(({"Soraya","soraya"}),
          W("Nileki te dice: 'Soraya era muy alegre. Siempre ten�a una palabra amable y una sonrisa "
            "para cualquiera que fuera a hablar con ella. La muerte de Rufus le "
            "afect� mucho. Se pasaba el d�a llorando y ninguno de nosotros pod�a "
            "consolarla. No he sabido nada de ella desde que se fue.'\n"),1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Madamme Nileki te dice: 'Probablemente es el mejor de todos nosotros. Sabe "
  "escuchar, y siempre tiene una palabra de �nimo. No es muy inteligente, pero "
  "no es tan tonto como dicen. S�lo es demasiado bueno.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),SF(answ_trassi),1);
  AddQuestion(({"Beni","beni"}),
  W("Madamme Nileki te dice: 'Cuando lleg� era casi una ni�a, muy dulce, aunque "
    "un poco melanc�lica. Lady Morkobva la tom� bajo su protecci�n, sabiendo "
    "que Lattini tarde o temprano ir�a tras ella. La verdad es que esto la "
    "perjudic�, porque Lady Morkobva no es muy popular por aqu�, pero lo "
    "cierto es que ah� demostr� que tiene buen coraz�n. En estos tres a�os "
    "Beni ha crecido mucho, y se ha convertido en una mujercita amable, dulce "
    "amable, dulce y alegre, aunque la tristeza acumulada de tantos a�os vagando "
    "por las calles mendigando un trozo de pan no se le borrar� nunca.\n"),1);
  AddQuestion(({"Mossi","mossi"}),
  W("Madamme Nileki te dice: 'Cuando lleg� no se fiaba de nadie, y estaba siempre "
    "dispuesto a iniciar una pelea si cre�a que alguien molestaba a su hermana. "
    "Eso no le hizo muy popular precisamente, pero creo que en estos a�os ha "
    "aprendido a confiar un poco en las personas, y su car�cter se ha vuelto "
    "un poco menos �spero. Eso s�, si cree que le est�s haciendo da�o a su "
    "hermana no dudar� en protegerla, como Lattini comprob� en sus carnes...'\n"),1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),SF(answ_lattini),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
                SF(answ_nikaia),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),SF(answ_morkobva),1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Madamme Nileki te dice: 'Nuestras bailarinas ex�ticas. Baskari las eligi� "
  "personalmente, pero s�lo trabajan para �l. Sabe lo que le har� si intenta "
  "ir m�s lejos.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Madamme Nileki te dice: 'La verdad es que al principio pens� que mi marido "
  "estaba loco. �Una kainoak bailarina! �Puedes imaginarlo? Yo tampoco, pero "
  "la verdad es que la chica no lo hace mal.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Madamme Nileki te dice: 'Casi todo el mundo piensa que es una medio-elfa "
  "mulata, aunque ella dice que es de una tribu de elfos que tienen la piel "
  "oscura. Lo cierto es que yo no s� que pensar. Y es que, aunque la verdad "
  "es que lo de un elfo negro me parece raro, no veo en ella a una de mi "
  "raza, es demasiado... mmm... �lfica.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Madamme Nileki te dice: 'Es una buena chica, aunque durante un tiempo fue "
  "un poco rebelde, como sus compa�eras de baile. Sin embargo, �ltimamente "
  "es mucho m�s civilizada, e incluso est� intentando que Beni le perdone "
  "ciertas maldades pasadas.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Madamme Nileki suspira: 'Ay, �qu� puedo decir de ese granuja? Es taca�o, "
  "desvergonzado y no tiene escr�pulos. Es un aut�ntico brib�n, pero es "
  "encantador. Eso s�, cuando quiere sabe tener buen coraz�n. Y le encanta "
  "el mundo del espect�culo, se dedica a ello desde peque�o y no sabe hacer "
  "otra cosa. Al principio no pod�a ni verle, pero puede ser tan persuasivo "
  "cuando quiere... Y tiene una labia...'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Madamme Nileki te dice: 'Madamme Nileki, pitonisa, experta en pociones y "
  "encantamientos. �Qu� puedo hacer por ti?'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Madamme Nileki te dice: 'Son un grupo de payasos kenders que contratamos "
  "hace casi siete a�os. La verdad es que nos han tra�do muchos problemas, "
  "pero Baskari no se decide a despedirlos. Son muy buenos y nos hacen "
  "ganar mucho dinero.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Madamme Nileki te dice: 'Es el mayor de los hermanos Kutiri. Hace de payaso "
  "listo, y la verdad es que tonto no es, aunque pueda parecerlo.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Madamme Nileki te dice: 'Es el ser m�s sucio que he tenido la desgracia de "
  "conocer en mi vida.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Madamme Nileki te dice: 'Se hace llamar inventor, aunque su orgullo es que "
  "todav�a no ha inventado nada �til. El \"Museo de las Cosas Imposibles\" nos "
  "proporciona unos buenos ingresos, y todos los artilugios que hay all� son "
  "obra suya. Es incre�ble la habilidad que tiene para las cosas in�tiles.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Madamme Nileki te dice: 'Su perdici�n es que le atrae todo lo que no es suyo. "
 "M�s de una vez hemos tenido que salir a escape de un pueblo por culpa suya.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Madamme Nileki te dice: 'Es el m�s peque�o y hace de payaso tonto. Los otros "
  "son bastante crueles con �l porque su nombre es diferente.'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Madamme Nileki dice: 'Muchas gracias. Ahora ya podr� preparar la poci�n'. "
 "Acto seguido, saca una hermosa daga de un caj�n y te la entrega.\n");
 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText("Madamme Nileki te dice: 'Muchas gracias, nunca viene mal tener un poco "
              "de reserva.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: nileki;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","nileki",({"p_hair"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/daga_nikaia");
}
