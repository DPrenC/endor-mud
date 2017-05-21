/* lattini.c
  Ilusionista de la compa��a.
  Necesita una daga que tiene Madamme Nileki.
  S�lo entreg�ndosela podr�s hablar con su esposa, Nikaia.
  Por cierto, tiene tela. Pero TELA...
  [n] nemesis@simauria

  Creaci�n: 03-Dic-2001 13:53:16 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Respuestas a las preguntas. Siendo Lattini como es, todas tienen "premio"

string piropo() {
// Lattini est� hecho un donjuan de mucho cuidado...
 switch(random(7)) {
  case 1: return "Lattini te dice: 'Estar� encantado de ayudar a una chica tan bonita como t�.\n";
          break;
  case 2: return "Lattini te dice: 'Con esos ojos podr�as conseguir lo que quieras de m�.\n";
          break;
  case 3: return "Lattini te dice: '�C�mo podr�a yo negarme a contestarle a una belleza como t�?.\n";
          break;
  case 4: return "Lattini te dice: 'Princesa, si me lo pides as� no puedo negarme...\n";
          break;
  case 5: return "Lattini te dice: 'Claro, preciosa, te dir� todo lo que s� sobre eso.\n";
          break;
 }
 return  "Lattini te dice: 'No me puedo negar a ayudar a una chica como t�.\n";
}

private string answ_espada() {
 if(TI->QueryGender() == GENDER_FEMALE) {
  return W(piropo()+"Pero no s� a qu� te refieres. Quiz� quieras "
           "hablar con mi esposa, ella es la que colecciona espadas, cuchillos y armas "
           "blancas en general. Yo soy un hombre pac�fico.'\n");
 }
 else return "El Gran Lattini te dice: '�Espadas? No s� a qu� te refieres. Quiz� quieras "
             "hablar con mi esposa, ella es la que colecciona espadas, cuchillos y armas "
             "blancas en general. Yo soy un hombre pac�fico.'\n";
}

private string answ_espada_andre() {
  if(TI->QueryGender() == GENDER_FEMALE) {
   return W(piropo()+"D�jame pensar... �La espada de Andr�? S�, se la gan� hace unos meses "
            "en una partida de cartas. El pobre iluso crey� que mis poderes disminu�an "
            "con el alcohol, pero no sabe que el alcohol me vuelve m�s h�bil. Le desplum� "
            "y s�lo pudo hacer frente a la deuda con una vieja espada. Yo no la quer�a "
            "para nada, pero a mi esposa le encant�. Dijo que era de Ontu-no-se-qu�. Por "
            "lo visto es obra de un artesano orco muy famoso. De manera que ahora la "
            "tiene ella. Quiz� si hablas con ella te la devuelva.'\n");
  }
  else return W("El Gran Lattini te dice: '�La espada de Andr�? S�, se la gan� hace unos meses "
                "en una partida de cartas. El pobre iluso crey� que mis poderes disminu�an "
                "con el alcohol, pero no sabe que el alcohol me vuelve m�s h�bil. Le desplum� "
                "y s�lo pudo hacer frente a la deuda con una vieja espada. Yo no la quer�a "
                "para nada, pero a mi esposa le encant�. Dijo que era de Ontu-no-se-qu�. Por "
                "lo visto es obra de un artesano orco muy famoso. De manera que ahora la "
                "tiene ella. Quiz� si hablas con ella te la devuelva.'\n");
}


private string answ_mujeres() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return "Lattini te mira de arriba a abajo y te dice, gui�ando un ojo: 'He visto a muchas mujeres hermosas en mi vida, pero t� eres la m�s hermosa de todas.'\n";
 else return "El Gran Lattini te dice: Ah... tantas mujeres hermosas y tan poco tiempo... Es una pena que la vida sea tan corta, �no crees?\n";
}

private string answ_beni() {
  if(TI->QueryGender() == GENDER_FEMALE)
   return W("El Gran Lattini te dice: 'Oh, una muchachita deliciosa, de formas delicadas, "
            "pero fuerte y �gil. Y unas piernas... oh... qu� piernas... Ah, un aut�ntico "
            "�ngel en la tierra... Francamente preciosa, como t�.'\n");
  else return W("El Gran Lattini te dice: 'Oh, una muchachita deliciosa, de formas delicadas, "
                "pero fuerte y �gil. Y unas piernas... oh... qu� piernas... Ah, un aut�ntico "
                "�ngel en la tierra... Por cierto... no le digas a mi mujer que yo he dicho "
                "eso... es un poco celosa, ya sabes...'\n");
}


private string answ_self() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return "El Gran Lattini te gui�a un ojo y dice: '�se soy yo, preciosa, �qu� deseas?'\n";
 else return "El Gran Lattini te dice: '�se soy yo, �quer�as algo de m�?'\n";
}

private string answ_nikaia() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return W("El Gran Lattini te dice: 'Es mi bella esposa. Y una lanzadora de cuchillos de "
           "primera. Es muy celosa, y creo que si me viera hablando con una belleza como t� "
           "practicar�a su punter�a con nosotros. Por desgracia, tuvimos una discusi�n y "
           "ahora estoy en un l�o. Se ha encerrado en el carro y no deja entrar a nadie. "
           "Llevo una semana durmiendo a la intemperie, con el fr�o que hace. �No podr�as "
           "ayudarme?'\n");

  else return W("El Gran Lattini te dice: 'Es mi bella esposa. Y una lanzadora de cuchillos de "
                "primera. Tuvimos una peque�a discusi�n y ahora estoy en un peque�o aprieto... "
                "Se ha encerrado en el carro y no deja entrar a nadie. Llevo una semana durmiendo "
                "a la intemperie, con el fr�o que hace �No podr�as ayudarme?'\n");
}

private string answ_daga_nikaia() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return W("El Gran Lattini te dice: 'Mmm... digamos que \"perd�\" una daga que es muy "
           "importante para mi esposa. Ella cree que pagu� una deuda de juego con ella, y me ha "
           "echado del carromato. Dice que no piensa dejarme entrar hasta que no la "
           "recupere. Seguro que alguien tan dulce como t� puede convencer a Madamme "
           "Nileki para que me la devuelva...'\n");
  else return W("El Gran Lattini te dice: Ver�s... como no pod�a tener a Lady Morkobva por medios \"normales\", "
                "decid� pedir ayuda a Madamme Nileki. Cuando quiere puede hacer pociones que "
                "hacen a las personas someterse a sus deseos. As� que le ped� un filtro de "
                "amor... Ella accedi�, pero a cambio me pidi� una peque�a daga que mi esposa "
                "ten�a guardada en un caj�n. Yo pensaba que no lo notar�a, pero result� que "
                "era una de sus m�s preciadas posesiones y se puso hecha una furia cuando "
                "descubri� que no estaba. Piensa que la perd� jugando a las cartas, y me ha "
                "echado del carromato. Dice que no piensa dejarme entrar hasta que no la "
                "recupere. Si t� la recuperaras, te estar�a muy agradecido...'\n");
}

private string answ_pocion() {
 if(TI->QueryGender() == GENDER_FEMALE) {
  if(TI->Query("talked_nileki")) {
   return W("El Gran Lattini te dice: 'As� que has hablado con esa bruja. Entonces "
            "ya sabr�s que me enga�� como a un tonto. Pero tienes que comprenderlo... Yo "
            "tengo que conseguir a Lady Morkobva o me volver� loco...'\n");
  }
  else return W("El Gran Lattini parece nervioso y te dice: 'Creo que para esas cosas "
                "deber�as hablar con Madamme Nileki. Lo suyo es la magia, lo m�o simplemente son ilusiones.'\n");
 }
 else return W("El Gran Lattini te dice: 'El filtro amoroso tuvo el mismo efecto "
               "en Lady Morkobva que un vaso de agua. Y lo peor es que Madamme Nileki no quiere "
               "devolverme la daga, dice que me merezco una lecci�n... �No me ayudar�s?'\n");
}

private string answ_morkobva() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return W("El Gran Lattini te dice: 'Es la elfa oscura m�s sensual que he visto en "
           "toda mi vida."+((TI->QueryRace() == "elfo-oscuro")?" Exceptu�ndote a ti, claro. "
           :"'\n"));
 else return W("El Gran Lattini abre mucho los ojos y te dice: 'Es lo m�s sensual que camina por "
               "el mundo. Cuando la veo actuar, con ese traje de cuero, me pongo... "
               "Pero es fr�a como el hielo. Y una aut�ntica fiera... No veas la habilidad "
               "que tiene con el l�tigo... Ah, si la vieras me comprender�as. Necesitaba "
               "poseerla, hacerla m�a. Por eso hice lo que hice. Y ahora estoy metido en un "
               "buen l�o...'\n");
}

private string answ_igart() {
 if(TI->QueryGender() == GENDER_FEMALE)
 return W("El Gran Lattini te dice: 'No es mi tipo, francamente. A m� me gusta "
          "que las mujeres tengan el mismo n�mero de brazos que yo.\n"+
          ((TI->QueryRace() == "kainoak")?" Claro que contigo podr�a hacer una excepci�n, mu�eca...' "
          :"Como t�, por ejemplo, princesa...'\n"));
 else return W("El Gran Lattini te dice: 'Entre nosotros, a m� me gusta que las mujeres tengan el mismo n�mero "
               "de brazos que yo. Adem�s, creo que a ese tonto de Andr� le gusta. Pero no "
               "le digas a nadie que te lo he dicho yo...'\n");
}

private string answ_kwailin() {
 if(TI->QueryGender() == GENDER_FEMALE)
 return W("El Gran Lattini te dice: 'Una gran bailarina. Y te lo dice alguien que "
          "conoce los talentos de las mujeres con s�lo mirarlas. "
          "Por cierto... �sabes que t� podr�as hacer una gran carrera en el mundo del "
          "espect�culo? Pi�nsatelo y me llamas.'\n");
 else return W("El Gran Lattini te dice: 'Mmmm... Sin duda, mi favorita de las tres. "
               "Puro fuego, pero a la vez toda dulzura y delicadeza. Me refiero al baile, claro.'\n");
}

private string answ_morda() {
 if(TI->QueryGender() == GENDER_FEMALE)
 return W("El Gran Lattini te dice: 'No s�, supongo que una elfa negra introduce "
          "variedad. El mundo ser�a muy aburrido si s�lo hubiera una raza y s�lo un color. "
          +((TI->QueryRace() == "elfo")?"Claro que, seamos sinceros... A "
          "m� las elfas me gustan con la piel tan blanca como la tuya.'\n":"'\n"));
 else return W("El Gran Lattini te dice: 'Entre nosotros... Yo no s� si ser� elfa o "
               "o medio-elfa... Lo que s� te puedo decir es que es una mujer entera, ya me entiendes...'\n");
}

private string answ_nileki() {
 if( (TI->QueryGender() == GENDER_FEMALE) &&
     (!TI->Query("talked_nileki")) )
  return W("El Gran Lattini te dice, visiblemente alterado: 'Es la esposa de Baskari, "
           "y una experta en pociones y en enga�ar a los incautos.'\n");
 else return W("El Gran Lattini te dice: 'Esa maldita bruja... Se divierte enga�ando "
               "a pobres enamorados desesperados...'\n");
}

// create

create() {
  ::create();
 SetStandard("Lattini", "humano", 100, GENERO_MASCULINO);
  SetShort("El Gran Lattini");
  SetLong("Se trata de un humano alto y bien parecido, con un bigotillo bien recortado, "
          "que �l cree que le hace irresistible. No parece muy fuerte, y en sus ojos "
          "ves algo que te recuerda a algo as� como una rata cobarde y rastrera. Algo "
          "te dice que no es muy de fiar... especialmente si eres de sexo femenino.\n");
  AddId(({"Lattini","lattini","el Gran Lattini","el gran Lattini",
          "el gran lattini","Gran Lattini","gran Lattini","gran lattini",
          "ilusionista"}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(0);
  InitChats(5,({
   "El Gran Lattini dice: '�Por qu� me fiar�a de esa bruja?'\n",
   "El Gran Lattini murmura: 'Tiene que ser m�a... Ser� m�a.'\n",
   "El Gran Lattini dice: 'Voy a coger un resfriado si sigo durmiendo en la calle.'\n",
   "El Gran Lattini estornuda.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"espada"}), SF(answ_espada),1);
  AddQuestion(({"espada de andre","espada de andr�","espada de Andr�",
                "espada de Andre","espada del forzudo"}),SF(answ_espada_andre),1);
  AddQuestion(({"mujeres","muchachas","jovencitas","chicas","nenas"}),
                SF(answ_mujeres),1);
  AddQuestion(({"ocho y media","cartas","partida","8 y media"}),
  "El Gran Lattini saca un mazo de cartas y te dice: '�No querr�as jugar una "
  "manita de Real Oriental? �Cuatro Reinas? �Ocho y Media? �Trece? �F�nix? "
  "�No? Vaya... M�s tarde, quiz�...'\n",1);
  AddQuestion(({"discusi�n","discusion","problema","aprieto","ayuda","l�o","lio",
                "daga","daga de Nikaia","daga de nikaia"}), SF(answ_daga_nikaia),1);
  AddQuestion(({"poci�n","pocion","filtro","filtro amoroso","filtro de amor"}),
                SF(answ_pocion),1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "El Gran Lattini te dice: 'Tan grande y fuerte como tonto. Pero en fin, "
  "supongo que no se puede tener todo...'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "El Gran Lattini te dice: 'Son los miembros m�s j�venes de la compa��a. "
  "No comprendo c�mo una muchacha tan deliciosamente dulce puede tener por "
  "hermano a una mula como Mossi.'\n",1);
  AddQuestion(({"Beni","beni"}),SF(answ_beni),1);
  AddQuestion(({"Mossi","mossi"}),
  "El Gran Lattini te dice: 'Es el hermano de Beni. Una mula, en mi opini�n. "
  "Una vez me puso un ojo morado por hablarle a su hermana. �Yo s�lo intentaba "
  "ser amable!'",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}), SF(answ_self),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
                SF(answ_nikaia),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),SF(answ_morkobva), 1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  W("El Gran Lattini te dice: 'Sin duda, Baskari tiene buen ojo para el exotismo: "
    "a qui�n sino a �l se le podr�a ocurrir poner a bailar juntas a una humana, "
    "a una kainoak y a una elfa negra...\n"),1);
  AddQuestion(({"Igart","igart"}),SF(answ_igart),1);
  AddQuestion(({"Kwailin","kwailin"}),SF(answ_kwailin),1);
  AddQuestion(({"Morda","morda"}),SF(answ_morda),1);
  AddQuestion(({"Baskari","baskari"}),
  "El Gran Lattini te dice: 'Es nuestro jefe. No le gustan los alborotos, por "
  "eso no le he dicho nada de mi peque�o \"problema\" con Nikaia...'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),SF(answ_nileki),1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("El Gran Lattini te dice: 'Binky, Dinky, Pinky, Tinky y Clyde. Los payasos de "
    "la compa��a. Son una panda de impresentables hijos de mala madre. Se creen "
    "graciosos y lo �nico que van a conseguir es que el d�a menos pensado "
    "vayamos todos a prisi�n.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "El Gran Lattini te dice: 'El mayor de los hermanos Kutiri. El muy cerdo me "
  "puso engrudo en las barajas... No veas qu� rid�culo cuando intent� hacer "
  "mi n�mero de cartas...'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Es un guarro. En una "
  "ocasi�n se me� en mi sombrero. Casi voy a la c�rcel cuando le dije al "
  "alcalde que metiera la mano para sacar una paloma...'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Una vez me cort� el "
  "bigote mientras dorm�a... y luego me lo peg� a las cejas. Si lo llego a "
  "coger entonces no lo cuenta, pero Baskari me detuvo.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Me ha robado cientos "
  "de veces una lupa que utilizo en uno de mis n�meros.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Una vez at� los "
  "pa�uelos que utilizo en mi n�mero al vestido de Nikaia. Se qued� desnuda. "
  "delante de todo el p�blico. No veas qu� verg�enza...'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "El Gran Lattini se dirige al carromato gritando: '�Cari�o! He encontrado "
 "tu daga! �Ves c�mo no la perd� jugando a las cartas?' Acto seguido vuelve "
 "y te da efusivamente las gracias.\n");
 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText(
  "El Gran Lattini te dice: '�Para m�? Muchas gracias. Ver� si a mi esposa le gusta'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: "lattini";
 SetQuest("sangorquest","lattini",({"daga_nikaia"}),0,0,0);
 // En este caso, no recibes ning�n objeto a cambio, simplemente puedes
 // entrar en el carromato de Lattini para hablar con su esposa, que te
 // pedir� una espada parecida a la de Andr�.
}
