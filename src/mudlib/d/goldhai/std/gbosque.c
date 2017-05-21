/*=============================================================*
 |            << GOLDHAI.bosque [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 06-01-98               |
 |               Ultima Modificacion... 11-05-99               |
 |                                                             |
 | 06-01-98 [w] La descripcion de los detalles varia segun la  |
 |              epoca del anyo, asi como los olores y sonidos. |
 |              La luz es mas tenue en los meses frios.        |
 | 29-08-98 [w] Introducidos SetIntLong() aleatorios para      |
 |              crear los bosques mas rapidamente con distintas|
 |              descripciones y que no existan sin habitaciones|
 |              sin estas.                                     |
 | 28-10-98 [w] Eliminada la luz como propiedad del bosque.    |
 | 18-11-98 [w] A�adida la funcion AddFlor().                  |
 | 07-02-99 [w] Castellanizadas las descripciones, con acentos |
 |              e�es y dem�s.                                  |
 |              Adaptado al nuevo sistema de estaciones .      |
 |                                                             |
 *=============================================================*/

#include "../sys/goldhai.h"
#include <nightday.h>
inherit GROOM;

private static string mes;
private static int estacion; // 0 primavera, 1 verano, 2 otonyo y 3 invierno

create() {
 ::create();

 mes = (ctime()[4..6]); // Captura el mes en el que estamos
 switch(mes) {
  case "Mar": estacion = 1; break;
  case "Apr": estacion = 2; break;
  case "May": estacion = 3; break;
  case "Jun": estacion = 0; break;
  case "Jul": estacion = 1; break;
  case "Aug": estacion = 2; break;
  case "Sep": estacion = 3; break;
  case "Oct": estacion = 0; break;
  case "Nov": estacion = 1; break;
  case "Dec": estacion = 2; break;
  case "Jan": estacion = 3; break;
  case "Feb": estacion = 0; break;
  default: estacion = 0;
 }

 SetIntShort("un bosque");
 switch(random(5)) {
 case 0:
  SetIntLong("\
Est�s en una peque�a senda que transcurre a trav�s del bosque. Este seria\n\
un estupendo lugar para perderse.\n"); break;
 case 1:
  SetIntLong("\
Te encuentras en medio de uno de los bosques de la isla. Unos estrechos\n\
caminos te van guiando a trav�s de �l. Ser� mejor que pongas atenci�n hacia\n\
donde vas si no quieres encontrarte con una extra�a sorpresa.\n"); break;
 case 2:
  SetIntLong("\
No ves ning�n rastro de civilizaci�n en medio de este bosque. Solo algunas\n\
zonas con menos vegetaci�n te indican el camino que debes seguir.\n"); break;
 case 3:
  SetIntLong("\
Los arboles est�n demasiado presentes en esta zona y te impiden ver que hay\n\
un poco m�s alla. Sin duda los bosques de Goldhai son ideales para descansar\n\
de una larga jornada.\n"); break;
  case 4:
  SetIntLong("\
Est�s en uno de los tantos bosques que hay en la isla. Ser� mejor que no te\n\
pares mucho por aqui si quieres no encontrarte con algun peligro.\n"); break;
  case 5:
  SetIntLong("\
Est�s rodeado de �rboles por todos lados y la vegetaci�n apenas te permite\n\
avanzar. De vez en cuando ves a alg�n animal arrimarse y contemplarte, pero\n\
rapidamente desaparecen en la espesura del bosque.\n"); break;
 default:
  SetIntLong("\
Te encuentras en medio de uno de los bosques de Goldhai.\n");
 }


 SetIndoors(0); // A descubierto

 AddDetail(({"animal","animales"}),"\
No se ven mucho pero da la sensaci�n que el bosque esta plagado de todo tipo\n\
de mam�feros y reptiles.\n");

 switch(estacion) {
 case 0: // -------- PRIMAVERA ---------
 SetIntNoise("Oyes el piar de los pajaros junto a los sonidos de la naturaleza.\n");
 SetIntSmell("Los olores de las diferentes flores y plantas se confunden.\n");
 AddDetail(({"matorral","matorrales"}),"\
Son unos peque�os matorrales situados a los lados de la senda. Algunos de\n\
ellos tienen unas peque�as flores alrededor de las cuales revolotean\n\
peque�os insectos.\n");
 AddDetail(({"arboles"}),"\
Los �rboles empiezan a reverdecer de nuevo. Los nuevos brotes asoman en\n\
las puntas de las ramas.\n");
 AddDetail(({"plantas","planta"}),"\
Las plantas crecen en todos los lugares, parece que nada les pueda parar.\n");
 AddDetail(({"insecto","insectos"}),"\
Ves muchos insectos cerca de las plantas y las flores.\n");
 AddDetail(({"flores","flor"}),"\
A los pies de los arboles crecen todo tipo de flores de colores vivos y\n\
aromas intensos. Este lugar tiene un encanto muy particular en esta �poca.\n");
 AddDetail(({"pajaro","pajaros"}),"\
Los p�jaros pian alegremente y vuelan de arbol en arbol. Algunos de ellos\n\
tienen unos plumajes ex�ticos.\n");
 break;

 case 1: // -------- VERANO ---------
 SetIntNoise("Oyes el piar de los pajaros junto a los sonidos de la naturaleza.\n");
 SetIntSmell("Los olores de las diferentes flores y plantas se confunden.\n");
 AddDetail(({"matorral","matorrales"}),"\
Son unos matorrales situados a los lados de la senda.\n");
 AddDetail(({"arboles"}),"\
Ves unos arboles cubiertos de grandes hojas de color verde.\n");
 AddDetail(({"plantas","planta"}),"\
Las plantas abundan en este lugar.\n");
 AddDetail(({"flores","flor"}),"\
Ves algunas flores a los lados de la senda.\n");
 AddDetail(({"insecto","insectos"}),"\
Ves muchos insectos cerca de las plantas y las flores.\n");
 AddDetail(({"pajaro","pajaros"}),"\
Los p�jaros pian alegremente y vuelan de arbol en arbol. Algunos de ellos\n\
tienen unos plumajes ex�ticos.\n");
 break;

 case 2: // -------- OTONYO ---------
 SetIntNoise("Solo escuchas los sonidos de algunos animales que se mueven tras las plantas.\n");
 SetIntSmell("Apenas puedes percibir olores en este lugar.\n");
 AddDetail(({"matorral","matorrales"}),"\
Son unos matorrales situados a los lados de la senda.\n");
 AddDetail(({"arboles"}),"\
La mayor�a de los arboles empiezan a perder sus hojas y no tienen ese verde\n\
que pose�an hace poco tiempo.\n");
 AddDetail(({"plantas","planta"}),"\
Ves multitud de plantas aunque algo resecas.\n");
 AddDetail(({"flores","flor"}),"\
No hay muchas flores en este lugar, solo aquellas que parecen m�s resistentes.\n");
 AddDetail(({"pajaro","pajaros"}),"\
Solo los m�s aventureros salen de sus agujeros en esta epoca.\n");
 break;

 case 3: // -------- INVIERNO ----------
 SetIntNoise("No escuchas ning�n sonido extra�o, todo parece tranquilo.\n");
 SetIntSmell("No percibes ning�n olor en particular.\n");
 AddDetail(({"matorral","matorrales"}),"\
Apenas quedan unos pocos a los lados del camino.\n");
 AddDetail(({"arboles"}),"\
La mayor�a de los �rboles han perdido sus hojas y acumulan en sus ramas\n\
algo de nieve.\n");
 AddDetail(({"plantas","planta"}),"\
No ves casi ninguna planta, solo aquellas que resisten las bajas temperaturas.\n");
 AddDetail(({"flores","flor"}),"\
Resultar�a casi imposible que pudieras ver una flor en esta �poca.\n");
 AddDetail(({"pajaro","pajaros"}),"\
Es practicamente imposible ver ning�n p�jaro, est�n todos en sus agujeros.\n");
 break;

 default: // --------- Por defecto PRIMAVERA -----------
 SetIntNoise("Oyes el piar de los pajaros junto a los sonidos de la naturaleza.\n");
 SetIntSmell("Los olores de las diferentes flores y plantas se confunden.\n");
 AddDetail(({"matorral","matorrales"}),"\
Son unos peque�os matorrales situados a los lados de la senda. Algunos de\n\
ellos tienen unas peque�as flores alrededor de las cuales revolotean\n\
peque�os insectos.\n");
 AddDetail(({"arboles"}),"\
Los �rboles empiezan a reverdecer de nuevo. Los nuevos brotes asoman en\n\
las puntas de las ramas.\n");
 AddDetail(({"plantas","planta"}),"\
Las plantas crecen en todos los lugares, parece que nada les pueda parar.\n");
 AddDetail(({"insecto","insectos"}),"\
Ves muchos insectos cerca de las plantas y las flores.\n");
 AddDetail(({"flores","flor"}),"\
A los pies de los �rboles crecen todo tipo de flores de colores vivos y\n\
aromas intensos. Este lugar tiene un encanto muy particular en esta �poca.\n");
 AddDetail(({"pajaro","pajaros"}),"\
Los p�jaros pian alegremente y vuelan de arbol en arbol. Algunos de ellos\n\
tienen unos plumajes ex�ticos.\n");
 }

 AddDetail(({"arbol"}),"\
No puedes fijarte en ninguno en concreto ya que hay muchos en este lugar.\n");
}

void AddFlor()
{
 if (random(6) >3) return;
 switch(random(9))
 {
  case 0:   AddItem(PLANTAS("floresamarillas_nar"),REFRESH_REMOVE); break;
  case 1:   AddItem(PLANTAS("floresamarillas_sac"),REFRESH_REMOVE); break;
  case 2:   AddItem(PLANTAS("floresamarillas_ven"),REFRESH_REMOVE); break;
  case 3:   AddItem(PLANTAS("floresblancas_mag"),REFRESH_REMOVE);   break;
  case 4:   AddItem(PLANTAS("floresblancas_ven"),REFRESH_REMOVE);   break;
  case 5:   AddItem(PLANTAS("floresrosas_int"),REFRESH_REMOVE);     break;
  case 6:   AddItem(PLANTAS("hierbas_cur"),REFRESH_REMOVE);         break;
  case 7:   AddItem(PLANTAS("hierbas_int"),REFRESH_REMOVE);         break;
  case 8:   AddItem(PLANTAS("hierbas_sac"),REFRESH_REMOVE);         break;

  default: AddItem(PLANTAS("floresamarillas_nar"),REFRESH_REMOVE);
 }
 return;
}

void AddPnj()
{
    switch(d2())
    {
        case 1:
            int hora = QueryServer()->QueryState();
            if (hora >= ND_PRENIGHT || hora <= ND_SUNRISE)
            {
                if (d20() == 1) AddItem(PNJ("bosques/piton.c"),REFRESH_DESTRUCT,1);
            }
        break;
        case 2:
            AddItem(PNJ("bosques/animales_bosque"),REFRESH_DESTRUCT,1);
        break;
    }
    return;
}
