/* Fichero: arco_orome.c 
Autor: Aul�
Fecha: 19/10/2014
Descripci�n. Elpoderoso arco  del vala cazador Orom�
*/

#include <combat.h>
#include <properties.h>

inherit "/obj/arco";

create() {
::create();
   SetStandard(WT_CAYADO, 10, P_SIZE_LARGE, M_ESPECIAL);
   SetShort("El arco estelar del Gran Cazador");
   SetLong(
   "Este poderoso arco es una de las armas m�s temidas por los siervos de la Oscuridad "
   "con las que cuentan los Se�ores del Occidente.\n"
   "Este poderoso arco ha sido forjado por Aul�, el vala Herrero, con la mism�sima luz "
   "de las estrellas recogida y solidificada  mediante  el poder  de Varda, Reina de "
   "los Valar. Tiene la altura de un hombre y un cuerpo elegantemente recurvado, "
   "hermosamente decorado con figuras de enrredaderas y hojas, entremezcladas con "
   "volutas y espirales. Los extremos est�n rematados por sendas cabezas de ciervo en "
   "miniatura de dorada cornamenta y ojos de brillantes piedras engastadas.\n"
   "La cuerda titila con luz plateada como si estuviera hecha con un rayo de luna "
   "atrapado y el cuerpo del arma refulge con la luz concentrada del cielo de una "
   "estival noche estrellada . El arco en su conjunto parece no ser s�lido, pudi�ndose "
   "ver a trav�s de �l. A�n as�, las flechas que dispara son veloces como el rayo y de "
   "todo punto infalibles. Ante ellas y la destreza de Orom�, el gran cazador, no "
   "cabe cota, peto ni escudo. Sirvi�ndose de este arma, Orom� ha dado muerte durante "
   "largas edades a un sinf�n de abominaciones malignas creadas por la malicia de "
   "Morgoth. El gran tama�o del arco no lo estorba en absoluto para dispararlo en plena "
   "carrera desde la grupa de su fiel corcel inmortal, Nahar.\n");
SetIds(({"arco", "arma"}));
SetAds(({"de", "luz", "plateado", "estelar", "de orome", "largo", "de caza"}));
    SetWeight(1500);
    SetNumberHands(1);
  SetValue(3000000);
         
  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar el arco con el  que Orom� abati� a tantos oponentes.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "este poderoso arco.\n");
}