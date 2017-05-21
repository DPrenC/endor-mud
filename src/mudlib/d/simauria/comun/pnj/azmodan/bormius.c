/*********************************************************/
//		"bormius"
//	El hermano mayor de Phobos un ogro cachas!
//		12-12-01: Kodex-> creación
//		10-01-02: Kodex-> última modificación
//	*Cambiado el nombre Deimos por Bormius.
//      13-06-03 [n] Ligeros retoques en la descripción y
//                   los mensajes.
//
/*********************************************************/

#include <properties.h>
#include "./path.h"
#define COSTE 25000 //5 mithriles por la información
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
                	"mithril podríamos hacer un trato.'\n"));
                	return 1;
                	}
                dinero="/lib/money"->PayValue2(TP,COSTE);
                if (intp(dinero))
                       	write("Pagas "+dinero+".\n");
                else
                       	write("Pagas "+dinero[0]+(dinero[1] ? " y recibes "+dinero[1] : "")+".\n");
                write("Bormius te dice: Trato hecho, esta es la historia....\n"
                	"    'Hace tiempo mi ejército y yo luchabamos en los campos de batalla de\n"
                	"     Azmodan contra la invasión de los orcos, nuestros aliados los enanos\n"
                	"     forjaron una espada que sería la ruina de los orcos y la llamaron\n"
                	"     Scyla. Una compañía de guerreros comandados por Geluin el entonces\n"
                	"     gran héroe de Kha-Annu se ofrecieron para traerme la espada al campo\n"
                	"     de batalla... Pero una emboscada orca los atrapó sobre las minas, todos\n"
                	"     fueron masacrados pero algunos exploradores lograron huir con la espada\n"
                	"     escondiendola en lo más profundo de la mina. Los orcos jamás permitirán\n"
                	"     que se descubra esa espada y harán lo que sea para protegerse de su poder.'\n");
                return 1;
		}
}

create()
{
::create();
SetStandard("Bormius","humano",([GC_LUCHADOR: 30]),GENERO_MASCULINO);
SetShort("el viejo general Bormius");

SetLong(W("Bormius es un anciano humano, pero parece aún fuerte "
"y resistente. Curtido en más de mil batallas al servicio del "
"ejército humano este increíble héroe pasa sus días charlando "
"con amigos y viejos conocidos. Aún parece un gran guerrero a "
"pesar de su edad y tiene el porte de un general.\n"));

SetIds(({"general","viejo general","viejo","Bormius"}));

SetAggressive(0);
SetAlign(200);

AddQuestion(({"scyla","Scyla"}),
W("Bormius dice: 'Esa historia es muy antigua y nadie la conoce excepto yo ... lo cual "
"la hace muy valiosa ... ¿estás dispuesto a pagar por oírla?'\nBormius añade: 'Si lo estás,"
" dame la mano y cerramos el trato.'\n"));

InitChats(4,({"Bormius dice: 'Me pregunto que habrá sido de Scyla.'\n",
"Bormius dice: '¡Soy un general! más respeto.'\n"}));

}

init()
{
::init();
add_action("dar_cmd","dar");
}
