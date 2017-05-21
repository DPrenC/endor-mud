/* lattini.c
  Ilusionista de la compañía.
  Necesita una daga que tiene Madamme Nileki.
  Sólo entregándosela podrás hablar con su esposa, Nikaia.
  Por cierto, tiene tela. Pero TELA...
  [n] nemesis@simauria

  Creación: 03-Dic-2001 13:53:16 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Respuestas a las preguntas. Siendo Lattini como es, todas tienen "premio"

string piropo() {
// Lattini está hecho un donjuan de mucho cuidado...
 switch(random(7)) {
  case 1: return "Lattini te dice: 'Estaré encantado de ayudar a una chica tan bonita como tú.\n";
          break;
  case 2: return "Lattini te dice: 'Con esos ojos podrías conseguir lo que quieras de mí.\n";
          break;
  case 3: return "Lattini te dice: '¿Cómo podría yo negarme a contestarle a una belleza como tú?.\n";
          break;
  case 4: return "Lattini te dice: 'Princesa, si me lo pides así no puedo negarme...\n";
          break;
  case 5: return "Lattini te dice: 'Claro, preciosa, te diré todo lo que sé sobre eso.\n";
          break;
 }
 return  "Lattini te dice: 'No me puedo negar a ayudar a una chica como tú.\n";
}

private string answ_espada() {
 if(TI->QueryGender() == GENDER_FEMALE) {
  return W(piropo()+"Pero no sé a qué te refieres. Quizá quieras "
           "hablar con mi esposa, ella es la que colecciona espadas, cuchillos y armas "
           "blancas en general. Yo soy un hombre pacífico.'\n");
 }
 else return "El Gran Lattini te dice: '¿Espadas? No sé a qué te refieres. Quizá quieras "
             "hablar con mi esposa, ella es la que colecciona espadas, cuchillos y armas "
             "blancas en general. Yo soy un hombre pacífico.'\n";
}

private string answ_espada_andre() {
  if(TI->QueryGender() == GENDER_FEMALE) {
   return W(piropo()+"Déjame pensar... ¿La espada de André? Sí, se la gané hace unos meses "
            "en una partida de cartas. El pobre iluso creyó que mis poderes disminuían "
            "con el alcohol, pero no sabe que el alcohol me vuelve más hábil. Le desplumé "
            "y sólo pudo hacer frente a la deuda con una vieja espada. Yo no la quería "
            "para nada, pero a mi esposa le encantó. Dijo que era de Ontu-no-se-qué. Por "
            "lo visto es obra de un artesano orco muy famoso. De manera que ahora la "
            "tiene ella. Quizá si hablas con ella te la devuelva.'\n");
  }
  else return W("El Gran Lattini te dice: '¿La espada de André? Sí, se la gané hace unos meses "
                "en una partida de cartas. El pobre iluso creyó que mis poderes disminuían "
                "con el alcohol, pero no sabe que el alcohol me vuelve más hábil. Le desplumé "
                "y sólo pudo hacer frente a la deuda con una vieja espada. Yo no la quería "
                "para nada, pero a mi esposa le encantó. Dijo que era de Ontu-no-se-qué. Por "
                "lo visto es obra de un artesano orco muy famoso. De manera que ahora la "
                "tiene ella. Quizá si hablas con ella te la devuelva.'\n");
}


private string answ_mujeres() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return "Lattini te mira de arriba a abajo y te dice, guiñando un ojo: 'He visto a muchas mujeres hermosas en mi vida, pero tú eres la más hermosa de todas.'\n";
 else return "El Gran Lattini te dice: Ah... tantas mujeres hermosas y tan poco tiempo... Es una pena que la vida sea tan corta, ¿no crees?\n";
}

private string answ_beni() {
  if(TI->QueryGender() == GENDER_FEMALE)
   return W("El Gran Lattini te dice: 'Oh, una muchachita deliciosa, de formas delicadas, "
            "pero fuerte y ágil. Y unas piernas... oh... qué piernas... Ah, un auténtico "
            "ángel en la tierra... Francamente preciosa, como tú.'\n");
  else return W("El Gran Lattini te dice: 'Oh, una muchachita deliciosa, de formas delicadas, "
                "pero fuerte y ágil. Y unas piernas... oh... qué piernas... Ah, un auténtico "
                "ángel en la tierra... Por cierto... no le digas a mi mujer que yo he dicho "
                "eso... es un poco celosa, ya sabes...'\n");
}


private string answ_self() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return "El Gran Lattini te guiña un ojo y dice: 'Ése soy yo, preciosa, ¿qué deseas?'\n";
 else return "El Gran Lattini te dice: 'Ése soy yo, ¿querías algo de mí?'\n";
}

private string answ_nikaia() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return W("El Gran Lattini te dice: 'Es mi bella esposa. Y una lanzadora de cuchillos de "
           "primera. Es muy celosa, y creo que si me viera hablando con una belleza como tú "
           "practicaría su puntería con nosotros. Por desgracia, tuvimos una discusión y "
           "ahora estoy en un lío. Se ha encerrado en el carro y no deja entrar a nadie. "
           "Llevo una semana durmiendo a la intemperie, con el frío que hace. ¿No podrías "
           "ayudarme?'\n");

  else return W("El Gran Lattini te dice: 'Es mi bella esposa. Y una lanzadora de cuchillos de "
                "primera. Tuvimos una pequeña discusión y ahora estoy en un pequeño aprieto... "
                "Se ha encerrado en el carro y no deja entrar a nadie. Llevo una semana durmiendo "
                "a la intemperie, con el frío que hace ¿No podrías ayudarme?'\n");
}

private string answ_daga_nikaia() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return W("El Gran Lattini te dice: 'Mmm... digamos que \"perdí\" una daga que es muy "
           "importante para mi esposa. Ella cree que pagué una deuda de juego con ella, y me ha "
           "echado del carromato. Dice que no piensa dejarme entrar hasta que no la "
           "recupere. Seguro que alguien tan dulce como tú puede convencer a Madamme "
           "Nileki para que me la devuelva...'\n");
  else return W("El Gran Lattini te dice: Verás... como no podía tener a Lady Morkobva por medios \"normales\", "
                "decidí pedir ayuda a Madamme Nileki. Cuando quiere puede hacer pociones que "
                "hacen a las personas someterse a sus deseos. Así que le pedí un filtro de "
                "amor... Ella accedió, pero a cambio me pidió una pequeña daga que mi esposa "
                "tenía guardada en un cajón. Yo pensaba que no lo notaría, pero resultó que "
                "era una de sus más preciadas posesiones y se puso hecha una furia cuando "
                "descubrió que no estaba. Piensa que la perdí jugando a las cartas, y me ha "
                "echado del carromato. Dice que no piensa dejarme entrar hasta que no la "
                "recupere. Si tú la recuperaras, te estaría muy agradecido...'\n");
}

private string answ_pocion() {
 if(TI->QueryGender() == GENDER_FEMALE) {
  if(TI->Query("talked_nileki")) {
   return W("El Gran Lattini te dice: 'Así que has hablado con esa bruja. Entonces "
            "ya sabrás que me engañó como a un tonto. Pero tienes que comprenderlo... Yo "
            "tengo que conseguir a Lady Morkobva o me volveré loco...'\n");
  }
  else return W("El Gran Lattini parece nervioso y te dice: 'Creo que para esas cosas "
                "deberías hablar con Madamme Nileki. Lo suyo es la magia, lo mío simplemente son ilusiones.'\n");
 }
 else return W("El Gran Lattini te dice: 'El filtro amoroso tuvo el mismo efecto "
               "en Lady Morkobva que un vaso de agua. Y lo peor es que Madamme Nileki no quiere "
               "devolverme la daga, dice que me merezco una lección... ¿No me ayudarás?'\n");
}

private string answ_morkobva() {
 if(TI->QueryGender() == GENDER_FEMALE)
  return W("El Gran Lattini te dice: 'Es la elfa oscura más sensual que he visto en "
           "toda mi vida."+((TI->QueryRace() == "elfo-oscuro")?" Exceptuándote a ti, claro. "
           :"'\n"));
 else return W("El Gran Lattini abre mucho los ojos y te dice: 'Es lo más sensual que camina por "
               "el mundo. Cuando la veo actuar, con ese traje de cuero, me pongo... "
               "Pero es fría como el hielo. Y una auténtica fiera... No veas la habilidad "
               "que tiene con el látigo... Ah, si la vieras me comprenderías. Necesitaba "
               "poseerla, hacerla mía. Por eso hice lo que hice. Y ahora estoy metido en un "
               "buen lío...'\n");
}

private string answ_igart() {
 if(TI->QueryGender() == GENDER_FEMALE)
 return W("El Gran Lattini te dice: 'No es mi tipo, francamente. A mí me gusta "
          "que las mujeres tengan el mismo número de brazos que yo.\n"+
          ((TI->QueryRace() == "kainoak")?" Claro que contigo podría hacer una excepción, muñeca...' "
          :"Como tú, por ejemplo, princesa...'\n"));
 else return W("El Gran Lattini te dice: 'Entre nosotros, a mí me gusta que las mujeres tengan el mismo número "
               "de brazos que yo. Además, creo que a ese tonto de André le gusta. Pero no "
               "le digas a nadie que te lo he dicho yo...'\n");
}

private string answ_kwailin() {
 if(TI->QueryGender() == GENDER_FEMALE)
 return W("El Gran Lattini te dice: 'Una gran bailarina. Y te lo dice alguien que "
          "conoce los talentos de las mujeres con sólo mirarlas. "
          "Por cierto... ¿sabes que tú podrías hacer una gran carrera en el mundo del "
          "espectáculo? Piénsatelo y me llamas.'\n");
 else return W("El Gran Lattini te dice: 'Mmmm... Sin duda, mi favorita de las tres. "
               "Puro fuego, pero a la vez toda dulzura y delicadeza. Me refiero al baile, claro.'\n");
}

private string answ_morda() {
 if(TI->QueryGender() == GENDER_FEMALE)
 return W("El Gran Lattini te dice: 'No sé, supongo que una elfa negra introduce "
          "variedad. El mundo sería muy aburrido si sólo hubiera una raza y sólo un color. "
          +((TI->QueryRace() == "elfo")?"Claro que, seamos sinceros... A "
          "mí las elfas me gustan con la piel tan blanca como la tuya.'\n":"'\n"));
 else return W("El Gran Lattini te dice: 'Entre nosotros... Yo no sé si será elfa o "
               "o medio-elfa... Lo que sí te puedo decir es que es una mujer entera, ya me entiendes...'\n");
}

private string answ_nileki() {
 if( (TI->QueryGender() == GENDER_FEMALE) &&
     (!TI->Query("talked_nileki")) )
  return W("El Gran Lattini te dice, visiblemente alterado: 'Es la esposa de Baskari, "
           "y una experta en pociones y en engañar a los incautos.'\n");
 else return W("El Gran Lattini te dice: 'Esa maldita bruja... Se divierte engañando "
               "a pobres enamorados desesperados...'\n");
}

// create

create() {
  ::create();
 SetStandard("Lattini", "humano", 100, GENERO_MASCULINO);
  SetShort("El Gran Lattini");
  SetLong("Se trata de un humano alto y bien parecido, con un bigotillo bien recortado, "
          "que él cree que le hace irresistible. No parece muy fuerte, y en sus ojos "
          "ves algo que te recuerda a algo así como una rata cobarde y rastrera. Algo "
          "te dice que no es muy de fiar... especialmente si eres de sexo femenino.\n");
  AddId(({"Lattini","lattini","el Gran Lattini","el gran Lattini",
          "el gran lattini","Gran Lattini","gran Lattini","gran lattini",
          "ilusionista"}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(0);
  InitChats(5,({
   "El Gran Lattini dice: '¿Por qué me fiaría de esa bruja?'\n",
   "El Gran Lattini murmura: 'Tiene que ser mía... Será mía.'\n",
   "El Gran Lattini dice: 'Voy a coger un resfriado si sigo durmiendo en la calle.'\n",
   "El Gran Lattini estornuda.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"espada"}), SF(answ_espada),1);
  AddQuestion(({"espada de andre","espada de andré","espada de André",
                "espada de Andre","espada del forzudo"}),SF(answ_espada_andre),1);
  AddQuestion(({"mujeres","muchachas","jovencitas","chicas","nenas"}),
                SF(answ_mujeres),1);
  AddQuestion(({"ocho y media","cartas","partida","8 y media"}),
  "El Gran Lattini saca un mazo de cartas y te dice: '¿No querrías jugar una "
  "manita de Real Oriental? ¿Cuatro Reinas? ¿Ocho y Media? ¿Trece? ¿Fénix? "
  "¿No? Vaya... Más tarde, quizá...'\n",1);
  AddQuestion(({"discusión","discusion","problema","aprieto","ayuda","lío","lio",
                "daga","daga de Nikaia","daga de nikaia"}), SF(answ_daga_nikaia),1);
  AddQuestion(({"poción","pocion","filtro","filtro amoroso","filtro de amor"}),
                SF(answ_pocion),1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "El Gran Lattini te dice: 'Tan grande y fuerte como tonto. Pero en fin, "
  "supongo que no se puede tener todo...'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "El Gran Lattini te dice: 'Son los miembros más jóvenes de la compañía. "
  "No comprendo cómo una muchacha tan deliciosamente dulce puede tener por "
  "hermano a una mula como Mossi.'\n",1);
  AddQuestion(({"Beni","beni"}),SF(answ_beni),1);
  AddQuestion(({"Mossi","mossi"}),
  "El Gran Lattini te dice: 'Es el hermano de Beni. Una mula, en mi opinión. "
  "Una vez me puso un ojo morado por hablarle a su hermana. ¡Yo sólo intentaba "
  "ser amable!'",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}), SF(answ_self),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
                SF(answ_nikaia),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),SF(answ_morkobva), 1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  W("El Gran Lattini te dice: 'Sin duda, Baskari tiene buen ojo para el exotismo: "
    "a quién sino a él se le podría ocurrir poner a bailar juntas a una humana, "
    "a una kainoak y a una elfa negra...\n"),1);
  AddQuestion(({"Igart","igart"}),SF(answ_igart),1);
  AddQuestion(({"Kwailin","kwailin"}),SF(answ_kwailin),1);
  AddQuestion(({"Morda","morda"}),SF(answ_morda),1);
  AddQuestion(({"Baskari","baskari"}),
  "El Gran Lattini te dice: 'Es nuestro jefe. No le gustan los alborotos, por "
  "eso no le he dicho nada de mi pequeño \"problema\" con Nikaia...'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),SF(answ_nileki),1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("El Gran Lattini te dice: 'Binky, Dinky, Pinky, Tinky y Clyde. Los payasos de "
    "la compañía. Son una panda de impresentables hijos de mala madre. Se creen "
    "graciosos y lo único que van a conseguir es que el día menos pensado "
    "vayamos todos a prisión.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "El Gran Lattini te dice: 'El mayor de los hermanos Kutiri. El muy cerdo me "
  "puso engrudo en las barajas... No veas qué ridículo cuando intenté hacer "
  "mi número de cartas...'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Es un guarro. En una "
  "ocasión se meó en mi sombrero. Casi voy a la cárcel cuando le dije al "
  "alcalde que metiera la mano para sacar una paloma...'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Una vez me cortó el "
  "bigote mientras dormía... y luego me lo pegó a las cejas. Si lo llego a "
  "coger entonces no lo cuenta, pero Baskari me detuvo.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Me ha robado cientos "
  "de veces una lupa que utilizo en uno de mis números.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "El Gran Lattini te dice: 'Uno de los hermanos Kutiri. Una vez ató los "
  "pañuelos que utilizo en mi número al vestido de Nikaia. Se quedó desnuda. "
  "delante de todo el público. No veas qué vergüenza...'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "El Gran Lattini se dirige al carromato gritando: '¡Cariño! He encontrado "
 "tu daga! ¿Ves cómo no la perdí jugando a las cartas?' Acto seguido vuelve "
 "y te da efusivamente las gracias.\n");
 // Texto que te da las demás veces que lo resuelvas
 SetAgainText(
  "El Gran Lattini te dice: '¿Para mí? Muchas gracias. Veré si a mi esposa le gusta'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: "lattini";
 SetQuest("sangorquest","lattini",({"daga_nikaia"}),0,0,0);
 // En este caso, no recibes ningún objeto a cambio, simplemente puedes
 // entrar en el carromato de Lattini para hablar con su esposa, que te
 // pedirá una espada parecida a la de André.
}
