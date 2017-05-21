/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 20-04-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

#define LISTA DOM_STD "asesinos"

int MasBuscados(string str);

create()
{
 ::create();
 SetIntShort("las puertas de Crowy");
 SetIntLong(
"Est�s en frente de las puertas que dan entrada a la ciudad. Tienes que\n\
levantar todo lo que puedes la cabeza para poder verlas en su totalidad.\n\
En un muro, a tu lado izquierdo, hay un tabl�n de anuncios que no estaria\n\
de m�s que lo mirases. A tus lados el r�o que rodea la ciudad te impide ir\n\
en esa direcci�n. Si continuas al Norte entrar�s en Crowy y si deseas no\n\
entrar o alejarte lo m�s facil es ir hacia el Sur.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"puerta","puertas","portones","porton","entrada"}),
"Se trata de una enorme puerta de madera de un grosor de m�s de un brazo.\n\
Su altura es considerable lo cual hace que sea practicamente imposible poder\n\
entrar a la ciudad cuando se encuentran cerradas, cosa que ocurre todas las\n\
noches para impedir que el pueblo pueda ser atacado aprovechando la oscuridad.\n");
 AddDetail(({"tablon","tablon anuncios","tablon de anuncios","tabl�n"}),
"Es un tabl�n de madera donde colocan los mensajes para los habitantes y\n\
extranjeros que llegan a la ciudad. Quiz�s debieras leer las normas de la\n\
ciudad as� como la lista de los m�s buscados.\n");
 AddDetail(({"muro","muros"}),
"Ves unos muros corrientes de piedra que bordean toda la ciudad.\n");
 AddDetail(({"puente","pasarela"}),
"Un enorme puente de piedra que te permite cruzar el r�o que rodea Crowy.\n");
 AddDetail(({"lista buscados","lista","lista mas buscados"}),
"Es una lista con los proscritos de la ciudad, quiz�s debieras leerla.\n");
 AddDetail(({"r�o","arroyo","agua"}),
"Te arrimas a la orilla del puente y miras hacia abajo. Un terrible olor\n\
proveniente del agua te impide casi respirar, seguramente hara a�os que no\n\
se ha cambiado ese agua estancada. Toda clase de enseres y porqueria flota\n\
en la superficie de ese agua grasienta y de color amarillo.\n");
 AddDetail(({"normas","normas de la ciudad","normas ciudad"}),
"Yo de ti las leeria para evitar problemas futuros.\n");

 AddExit("norte",CROWY("entrada1"));
 AddExit("sur",CROWY("puente"));
 AddRoomCmd("leer",SF(MasBuscados));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+2);

 SetLocate("crowy");
}

int MasBuscados(string str)
{
 if (!str) return 0;
 if (str=="tablon")
     return write("�Qu� parte del tabl�n deseas leer exactamente?\n"),1;
 if (str=="lista" || str=="lista de los m�s buscados" || str=="lista buscados"
     || str=="lista m�s buscados")
     return write(LISTA->Listar()+"\n"),1;
 if (str=="normas" || str=="normas de la ciudad" || str=="normas ciudad")
     return write(
 "\n                    NORMAS DE CONDUCTA EN CROWY\n\n\
   Estimados ciudadanos y gente de paso, Crowy naci� como una ciudad en la\n\
 que la buena convivencia y la neutralidad era parte fundamental. Todas las\n\
 razas son bien recibidas si su caracter es pac�fico. Aqu� no hacemos juicios\n\
 de las acciones que hayan hecho en el pasado o vayan a hacer en el futuro.\n\
   Los asesinatos, raptos, extorsiones, etc.. ser�n tratados de la forma m�s\n\
 dura posible dentro de los limites de la ciudad por los mismos ciudadanos.\n\
\n\
                                                   Fdo: Hardester Rankomme\n"),1;

 return 0;
}