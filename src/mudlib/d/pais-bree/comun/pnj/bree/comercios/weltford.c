/***************************************************************************************
 ARCHIVO:	weltford.c
 AUTOR:		Aulë
 FECHA:		14/01/2015
 Descripción:	Weltford, el herrero de Bree.
 Posible pnj para quest. ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("Weltford","humano",30,GENERO_MASCULINO);
  SetWhimpy(5);
  SetAlign(1);
  SetAggressive(0);
  SetName("Weltford");
  SetIds(({"humano","herrero","weltford","Weltford"}));
  Set(P_CANT_LURE,1);
  SetShort("Weltford el herrero");
  SetLong(
"Weltford es el insigne herrero de Bree, aunque también atiende a las otras tres aldeas "
"del País, por lo cual es una persona de reconocido renombre y prestigio entre los "
"hobbits y hombres que a menudo requieren sus servicios para reparar o fabricar "
"herramientas y utensilios o para herrar a sus monturas y animales de tiro.\n"
"Es un hombretón algo bajo y ancho, como lo son los hombres de Bree, pero macizo y "
"musculoso debido a su trabajo. Sus grandes brazos destacan bajo las mangas y una "
"tupida cabellera castaña con algunas pinceladas grises le cae sobre los fornidos hombros "
"en desgreñados rizos. Una barba también castaña y tupida oculta a medias un rostro "
"mofletudo, jovial y bonachón, de nariz algo bulbosa y ojos marrones y alegres.\n"
"En general, es un hombre risueño que ama su trabajo, aunque los rumores que "
"últimamente circulan, traídos por los escasos viajeros hasta el Poney Pisador, lo "
"preocupan. En previsión de cualquier contingencia y a pedido de algunos aldeanos, ha "
"comenzado a forjar, poco a poco, algunas toscas armas para la defensa del País de Bree.\n");

  AddSubDetail(({"brazo","brazos"}),
  "Tiene unos brazos gruesos, de bíceps anchos, hombros poderosos y muñecas gruesas.\n");
  AddSubDetail(({"barba"}),
  "Una poblada barba castaña salpicada de gris cubre el sonrriente rostro del herrero.\n");
  AddQuestion(({"herreria","herrería"}),
  "Weltford comenta: -¿te gusta?\n"
  "El herrero señala todo lo que os rodea con un gesto de su martillo.\n"
  "Weltford dice: -Fue levantada por mis antepasados hace muchas generaciones y mi "
  "familia la ha regentado desde entonces. Es un buen negocio... tranquilo, entretenido... "
  "y sobre todo útil. Y nunca faltan cosas que reparar. Espero que pronto pueda dejar de "
  "forjar armas y sobre todo espero que no tengamos que utilizarlas.\n"
  "Weltford parece preocupado mientras continúa con su trabajo.\n\n");
  AddQuestion(({"armas"}),
  "Weltford señala los objetos colgados de los muros mientras explica:\n"
  "--Todo eso: algunas espadas cortas, dagas, cuchillos.... En Bree no nos gustan los "
  "problemas, tanto la Gente Grande como la Gente Pequeña gusta de la tranquilidad y del "
  "cuidado de la tierra, pero hay rumores de problemas allá en el sur, y gente extraña "
  "que vaga por los bosques de Archet y merodea por los campos.\n");
  AddQuestion(({"gente", "gentes", "gente extraña", "gentes extrañas"}),
  "Weltford pone mala cara mientras dice:\n"
  "--Ya sabes a que me refiero: vagabundos, sureños cetrinos del Sur con acento "
  "extraño que nunca habíamos visto antes. ¡Muchos de ellos hablan de asentarse! "
  "¿Puedes creerlo? Aquí ya somos suficientes y no queremos problemas. ¡Como si no "
  "tuviéramos bastante con los montaraces, yendo y viniendo de aquí para allá!\n");
  AddQuestion(({"problemas", "rumores"}),
  "Weltford se detiene en sus quehaceres y comenta:\n"
  "--Nada concreto... pero se oyen cosas muy extrañas, allá, en el Poney del viejo "
  "Mantecona: los Montaraces vienen y van, agitados como abejas en primavera y "
  "advierten sobre todo tipo de desgracias y guerras lejanas. ¿puedes creerlo? ¡Guerras! "
  "Aquí no nos gustan las guerras, maldita sea. En el Este se habla sobre orcos y "
  "lobos que bajan de las montañas y de los yermos del Norte. Algo se remueve allá, en "
  "las Quebradas de los Túmulos y el pequeño de los Madreselva desapareció en el camino "
  "del Oeste, hacia la Comarca. Y por si fuera poco, se comenta que en el Sur hay guerra "
  "y fuego.... Malos tiempos, sí señor.\n"
  "Weltford coge el martillo y comienza a templar una hoja de azada.\n");
  AddQuestion(({"montaraces"}),
  "Weltford menea la cabeza en actitud reprobatoria mientras pasa la hoja de una "
  "guadaña por la piedra de amolar:\n"
  "--Hummm... los Montaraces. Gente extraña, de mala calaña. Vagabundos sin hogar, "
  "zarrapastrosos silenciosos que vienen a veces del Este y nunca se están quietos en el "
  "mismo sitio. Eso sí... siempre que requieren un servicio lo pagan puntualmente y en "
  "temas de las Tierras Salvajes no encontrarás a nadie que sea más entendido.\n"
  "El más torvo y extraño de todos no hace mucho que nos advirtió contra esos "
  "advenedizos del Sur... Trancos, lo llamamos por aquí.\n");
  AddQuestion(({"Poney", "taberna", "posada", "poney pisador"}),
  "Weltford hace un alto en su trabajo y dice sonrriéndote:\n"
  "--Si lo que buscas es un sitio para tomar unas pintas de buena cerveza, comer o "
  "pasar la noche no hay mejor lugar que el Poney, del viejo Mantecona. Una persona "
  "importante y con los pies en la tierra, sí señor.\n");
  AddQuestion(({"mantecona", "posadero", "cebadilla", "cebadilla mantecona"}),
  "Weltford sonríe ampliamente mientras dice:\n"
  "--Ay, el gordo y viejo señor Cebadilla Mantecona, no encontrarás mejor persona de "
  "aquí a la Comarca, me atrevería a decir. Buen posadero y alguien letrado.\n"
  "Weltford alza un cayoso dedo, subrayando sus palabras.\n"
  "--¡Figúrate que sabe leer! ¡Y escribe con letras grandes y hermosas!\n");
   AddItem(PROTBREE("comercios/delantal_cuero"),REFRESH_REMOVE,SF(wearme));
    AddItem(PROTBREE("comercios/botas_gruesas"),REFRESH_REMOVE,SF(wearme));
      AddItem(PROTBREE("comercios/camisola_cuero"),REFRESH_REMOVE,SF(wearme));
        AddItem(PROTBREE("comercios/guantes_gruesos"),REFRESH_REMOVE,SF(wearme));
          AddItem(PROTBREE("comercios/pantalones_gruesos"),REFRESH_REMOVE,SF(wearme));

  AddItem("/obj/herramientas/martillo_herrero",REFRESH_REMOVE,SF(wieldme));




}
