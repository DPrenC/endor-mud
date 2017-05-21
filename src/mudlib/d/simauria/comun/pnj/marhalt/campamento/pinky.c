/* pinky.c
  La 'rama técnica' de la familia Kutiri. Inventor de objetos inútiles.
  Necesita un engranaje para su último invento.
  Los Hermanos Kutiri son questnpcs "peculiares": Sólo te darán el
  objeto que deseas (el látigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creación: 09-Dic-2001 02:31:28 CET (oye, sólo 30 minutos... creo que es un récord...)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Sobrecargamos reward_player para que sólo obtengamos lo que queremos
// si les entregamos los objetos a los cinco hermanos
void reward_player(object pl,object ob) {
 string *wq;
 // para evitar problemas en los member() más abajo
 wq = pl->QueryAttr("sangorquest")||({});
// Como el HelpMessage lo escupe sólo al pasar por reward_player, habrá
// que hacer de alguna manera que el jugata sepa que ha conseguido traer
// el objeto adecuado... Se deja fuera porque mola más que lo diga siempre.
 say(W("Pinky coge el pequeño engranaje, lo mira al trasluz y grita: "
       "'¡Por fin! ¡La pieza esencial para mi máquina!' Ahora sí que conseguiré "
       "la fama mundial.'\n"));
// No se entrega el látigo hasta que no haya resuelto los 5 subquests
 if ( (-1==member(wq,"binky")) ||
      (-1==member(wq,"dinky")) ||
      (-1==member(wq,"pinky")) ||
      (-1==member(wq,"tinky")) ||
      (-1==member(wq,"clyde"))
    ) return;
 else ::reward_player(pl,ob);
}

// Funciones para responder a las preguntas...
private string answ_robo() {
 if(TI->Query("asked_kwailin")) {
  if(!TI->Query("discovered_binky")) {
   TI->Set("discovered_binky",1);
   return W("Le explicas a Pinky lo que te ha contado Kwailin y los hermanos Kutiri. "
            "se echan a reír. Binky te dice: 'Oh, así que Kwailin me vió en el lugar "
            "de los hechos... Sí, fui yo. Lady Morkobva me golpeó con su látigo "
            "y me llamó sucio kender. Así que decidí vengarme con esta pequeña broma. "
            "Para que la venganza fuera completa, intenté enemistarla con las "
            "dos únicas personas que le importan, esos gemelos Trassi. Pero veo que "
            "no lo conseguí, así que de nada me sirve el látigo. Además, mis hermanos "
            "y yo nos hemos peleado por él varias veces. Creo que lo mejor será que "
            "te lo dé... pero antes tendrás que traernos un objeto muy especial "
            "a cada uno...'\n");
  }
  else return W("Binky te dice: 'Ya te lo he explicado, yo robé el látigo "
                "de Lady Morkobva. Estoy dispuesto a devolvértelo si nos traes "
                "a cada uno un objeto especial, así que deja de molestar a "
                "mis hermanos con eso.'\n");
 }
 else return "Pinky te mira fijamente y dice: 'No sé de qué me estás hablando.'\n";
}

// create
create() {
  ::create();
 SetStandard("Pinky", "kender", 100, GENERO_MASCULINO);
  SetLong(W("Es un kender vestido con una especie de mono de color rosa. "
            "Lleva unos lentes que le hacen parecer 'intelectual'. Su "
            "mirada te pone igual de nervioso que las de sus hermanos.\n") );
  SetShort("El payaso Pinky");
  AddId(({"Pinky","pinky","el payaso Pinky","el payaso pinky",
          "payaso Pinky","payaso pinky",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Pinky saca un lápiz y un papel y comienza a escribir fórmulas.\n",
   "Pinky se quita los lentes y los limpia con aire intelectual.\n",
   "Pinky saca unos tornillos del bolsillo y los examina cuidadosamente.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Pinky te dice: 'Yo no sé nada de eso.'\n",1);
  AddQuestion(({"látigo","robo","latigo","lentejuela","látigo de Lady Morkobva",
  "látigo de lady Morkobva","látigo de Lady morkobva","látigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  "Pinky te dice: 'Necesito una pieza para mi último invento.'\n",1); // un engranaje
  AddQuestion(({"pieza","pieza para invento"}),
  "Pinky te dice: 'Es un nombre demasiado técnico que sólo un auténtico "
  "científico como yo podría memorizar, no digamos pronunciar. Tú simplemente "
  "tráeme la pieza que necesito y no te preocupes de más. Yo haré el resto.'\n",1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "Pinky te dice: 'Es un cabeza de chorlito incapaz de comprender una sola "
  "palabra de lo que hago, pero es muy útil para realizar trabajos pesados.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Pinky te dice: '¿Equilibristas? Cualquier mono lo hace mejor que ellos. "
  "Realmente no sé para qué los queremos. Son un par de aburridos.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Pinky te dice: 'La demostración de que no tiene futuro como equilibrista. "
  "Mi hermano Dinky puso un poquito de grasa en su cuerda y ella ¿qué hizo? "
  "¿Aguantó el tipo como una profesional? No señor, cayó a plomo contra la "
  "red que la esperaba abajo. Una auténtica equilibrista ni siquiera habría "
  "usado red. Si haces algo, que sea con todas las consecuencias, es lo que "
  "siempre decía mi madre. Pero parece que a Beni no la educaron bien.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Pinky te dice: 'Intentó pegar a mi hermano. Supongo que se enfadó porque "
  "pusimos en evidencia la poca profesionalidad de Beni.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Pinky te dice: 'El pobre es la víctima perfecta para nuestras bromas. "
  "¡Pica siempre!'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Pinky sonríe y te dice: 'Es mucho más simpática que su marido. Cómo se "
  "rió cuando le hice aquel arreglo al bigote de Lattini.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Pinky te dice: 'No debió hacerle eso a mi hermano. Él se vengará, ya lo verás.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Pinky te dice: 'El objeto principal de nuestras burlas. Dicen que somos "
  "crueles y nos odian, pero yo sé que en el fondo les gusta. Una mala "
  "crítica es un estímulo para todo artista.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Pinky te dice: 'Se enfada mucho con nosotros porque nos reímos de ella. "
  "¿Qué culpa tenemos de que sea tan gracioso verla \"bailar\"?'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Pinky te dice: 'Es la peor de las tres. No sabe aguantar una broma. Una vez "
  "saboteó uno de mis inventos, que explotó. No fue nada gracioso.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Pinky te dice: 'Dicen que está enamorada de Mossi. Eso confirma lo que yo "
  "siempre he dicho: Kwailin tiene muy mal gusto.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Pinky te dice: 'Gracias a él mis inventos son conocidos en todo el mundo, "
  "pero se lleva un porcentaje de las ganancias. Un 90%, para ser exactos... "
  "¡Maldito estafador!'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Pinky te dice: 'Es retorcida y malévola, se le ve en los ojos.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de "
  "payasos de todo el reino de Simauria, para servirte.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Pinky te dice: 'Mi hermano mayor, es el más listo. Después de mí, claro.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Pinky hace una reverencia y te dice: 'Pinky Kutiri, inventor, para servirte.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Pinky te dice: 'Bajo toda esa mugre, late el corazón de un artista de las "
  "bromas. Nunca sabes por dónde va a salir.'\n",1);
   AddQuestion(({"Tinky","Tinky"}),
   "Pinky te dice: 'Supongo que yo soy la rama \"científica\" de la familia y él "
   "la rama artística. Es un músico de primera, y tiene cierto talento para "
   "crear instrumentos, no te creas. En eso se parece mucho a mí.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Pinky te dice: 'Clyde es todo lo contrario a mí. Yo soy educado, elegante, "
  "inteligente... y Clyde es... bueno, es Clyde. Es un desastre, pero sigue "
  "siendo nuestro hermano y le queremos.'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un látigo con empuñadura de marfil negro.\n");

 // Texto que te da las demás veces que lo resuelvas
 SetAgainText("Pinky mira el engranaje con atención y te dice: 'Oye, gracias "
                "por traerme uno de repuesto.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: pinky;
 // Las tres últimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","pinky",({"engranaje"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
