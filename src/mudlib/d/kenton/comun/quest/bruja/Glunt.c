/*
O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O
/                                                                     /
O---------------------------------------------------------------------O
/   [K] Korsario@Simauria                                             /
O---------------------------------------------------------------------O
\   Kreacion.............. 05/04/98                                   \
O   Ultima modificacion... 07/10/00 [Kr]                              O
/                                                                     /
O   14/04/98 [K] Kreacion.                                            O
/                                                                     /
O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O
*/

#include "./path.h"

inherit NPC;

int x;
create ()
{
   ::create();
   SetName("Glunt");
   SetAds(({"un","el"}));
   SetIds(({"kender"}));

   SetShort("Glunt el kender artista");
   SetLong(
"Ves a Glunt, parece tener algo en mente. Tiene una mirada muy despierta pero "
"ahora mismo debe estar pensando en algo, probablemente en su pr�xima creaci�n.\n");
   SetRace("kender");
   SetGender (1);
   x=random(8)+2;
   SetLevel(x);
   InitChats(2, ({
"Glunt te mira con curiosidad.\n",
"Glunt dice: Deseas saber algo?\n",
"Glunt dice: Venga, no tengo todo el d�a, vas a preguntarme sobre alguna prueba?\n",
"Glunt silba una canci�n y sonr�e.\n",
"Glunt dice: Aaaaah...!!! ya lo tengo...!!!\n",
"Glunt dice: Eh tu...!!! Mira por donde vas...!!!\n",
"Glunt dice: Te has fijado?, menudas pruebas tenemos este a�o.\n",
"Glunt dice: Si lo deseas, puedes preguntarme sobre la 'prueba 1', o sobre la "
"que quieras, pero r�pido que no tengo todo el d�a.\n" }) );
   InitAChats(10, ({
"Glunt grita con histerismo: Socorrooo, que me est�n haciendo da�o!!! Socorroo!!!",
                 }) );

  SetHands(({ ({"mano derecha", 0,1}), ({"mano izquierda",0,1}) }) );

  AddQuestion(({"prueba 1","la prueba 1"}),
"Glunt dice: Esa prueba es nueva este a�o, habiamos pensado lanzar otras cosas "
"como gallinas, pero como abr�an las alas no ca�an bien, y la mayor�a quiso "
"poner cerdos para ver como ca�an. Claro que los lanzamos sobre barro, tambi�n "
"queremos ver hasta donde llega el barro cuando el cerdo cae encima. "
"Gana el que lance el cerdo m�s lejos.\n");

  AddQuestion(({"prueba 2","la prueba 2"}),
"Glunt dice: La de la puerta sobre el tejado ya es una tradici�n, no la conocias? "
"Pues consiste en que los habitantes de la aldea se tiran desde el tejado de la "
"casa mas alta, subidos en una puerta. Seguro que has visto que a casi todas las "
"casas les faltan las puertas ji ji ji. "
"Esta prueba es muy divertidaaaaa, no veas como llegan abajo...!!! Gana el que "
"menos da�o se haga.\n");

  AddQuestion(({"prueba 3","la prueba 3"}),
"Glunt dice: Se me ha abierto el apetito, ahora vuelvo.\n"
"Glunt se va a una caseta y se pone a comer un plato que tiene muy buena pinta.\n"
"Glunt llega relamiendose.\n"
"Glunt dice: Esta prueba es la que m�s me gusta, consiste en premiar el mejor "
"plato de comida.\n");

  AddQuestion(({"prueba 4","la prueba 4"}),
"Glunt dice: La de la rana fue idea m�a, no participa uno directamente, tienes "
"que inscribir a una rana para que participe.\n"
"La rana tiene que ir saltando de un sitio a otro hasta llegar al final. "
"Las ranas son muy listas, y es impresionante esta prueba, a los ni�os les "
"encanta, sobre todo porque con las ranas perdedoras se divierten un rato.\n");

  AddQuestion(({"prueba 5","la prueba 5"}),
"Glunt dice: Esa prueba no me gusta nada, hay que tragarse un pescado enorme "
"y vivo sin masticar. Yo participe en los juegos no oficiales en esa prueba y "
"a�n recuerdo como coleteaba el pescado en mi est�mago, que dolor...!!!.\n");

  AddQuestion(({"prueba 6","la prueba 6"}),
"Glunt dice: Pues esta es complicada, se juega en equipo de dos. Uno lanza un "
"tronco y el otro lo intenta romper con la cabeza. \n"
"Los troncos tampoco son muy grandes, pero es muy divertida esta prueba.\n");

  AddQuestion(({"prueba 7","la prueba 7"}),
"Glunt dice: Pues es la t�pica carrera de sacos con una variante, se corre "
"hacia atr�s, y se pueden poner 'peque�as trampas' a los corredores, como "
"charcos, animalitos y cosas as�.\n");
}
/*-------------------------------------------------------------*/
