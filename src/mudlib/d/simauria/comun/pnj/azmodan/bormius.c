/*********************************************************/
//		"bormius"
//	El hermano mayor de Phobos un ogro cachas!
//		12-12-01: Kodex-> creaci�n
//		10-01-02: Kodex-> �ltima modificaci�n
//	*Cambiado el nombre Deimos por Bormius.
//      13-06-03 [n] Ligeros retoques en la descripci�n y
//                   los mensajes.
//
/*********************************************************/

#include <properties.h>
#include "./path.h"
#define COSTE 25000 //5 mithriles por la informaci�n
#include <gremios.h>

inherit NPC;

dar_cmd(string str)
{
	object ob,dinero,dinero_jugador;
	if (!str) return 0;
	str=lower_case(str);
	if (str == "la mano a bormius" || str == "mano a bormius")

        	{
                dinero_jugador="/lib/money"->QuerySomeonesValue(TP);
        	if(dinero_jugador < COSTE)
                	{
                	write(W("Bormius te dice: 'Si tuvieras 5 monedas de "
                	"mithril podr�amos hacer un trato.'\n"));
                	return 1;
                	}
                dinero="/lib/money"->PayValue2(TP,COSTE);
                if (intp(dinero))
                       	write("Pagas "+dinero+".\n");
                else
                       	write("Pagas "+dinero[0]+(dinero[1] ? " y recibes "+dinero[1] : "")+".\n");
                write("Bormius te dice: Trato hecho, esta es la historia....\n"
                	"    'Hace tiempo mi ej�rcito y yo luchabamos en los campos de batalla de\n"
                	"     Azmodan contra la invasi�n de los orcos, nuestros aliados los enanos\n"
                	"     forjaron una espada que ser�a la ruina de los orcos y la llamaron\n"
                	"     Scyla. Una compa��a de guerreros comandados por Geluin el entonces\n"
                	"     gran h�roe de Kha-Annu se ofrecieron para traerme la espada al campo\n"
                	"     de batalla... Pero una emboscada orca los atrap� sobre las minas, todos\n"
                	"     fueron masacrados pero algunos exploradores lograron huir con la espada\n"
                	"     escondiendola en lo m�s profundo de la mina. Los orcos jam�s permitir�n\n"
                	"     que se descubra esa espada y har�n lo que sea para protegerse de su poder.'\n");
                return 1;
		}
}

create()
{
::create();
SetStandard("Bormius","humano",([GC_LUCHADOR: 30]),GENERO_MASCULINO);
SetShort("el viejo general Bormius");

SetLong(W("Bormius es un anciano humano, pero parece a�n fuerte "
"y resistente. Curtido en m�s de mil batallas al servicio del "
"ej�rcito humano este incre�ble h�roe pasa sus d�as charlando "
"con amigos y viejos conocidos. A�n parece un gran guerrero a "
"pesar de su edad y tiene el porte de un general.\n"));

SetIds(({"general","viejo general","viejo","Bormius"}));

SetAggressive(0);
SetAlign(200);

AddQuestion(({"scyla","Scyla"}),
W("Bormius dice: 'Esa historia es muy antigua y nadie la conoce excepto yo ... lo cual "
"la hace muy valiosa ... �est�s dispuesto a pagar por o�rla?'\nBormius a�ade: 'Si lo est�s,"
" dame la mano y cerramos el trato.'\n"));

InitChats(4,({"Bormius dice: 'Me pregunto que habr� sido de Scyla.'\n",
"Bormius dice: '�Soy un general! m�s respeto.'\n"}));

}

init()
{
::init();
add_action("dar_cmd","dar");
}
