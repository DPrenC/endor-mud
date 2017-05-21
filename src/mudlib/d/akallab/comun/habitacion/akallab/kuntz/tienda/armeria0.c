/*
DESCRIPCION : armeria Troll
FICHERO     : /d/akallab/comun/habitacion/akallab/kuntz/tienda/armeria0.c
MODIFICACION: 17-11-99 [Angor@Simauria] Creacion
*/
#include "./path.h"
#include AK_MACRO
#include <properties.h>



inherit SHOP;

create(){
  ::create();
 SetIntShort("una armería troll");
  SetIntLong(
  "Te hallas en una armeria troll. En esta cueva habita el equivalente "
    "troll a un herrero, un troll que se gana la vida fabricando o "
	"a veces reparando las toscas armas de su tribu. En un medio de la "
	"cueva ves un pequenyo horno para fundir metal y un yunque. De las "
	"paredes de la cueva cuelgan distintas armas de las que habitualmente "
	"usan los troll.\n");

  AddDetail(({"paredes"}),
  "Las paredes de la cueva estan talladas toscamente en la roca de la "
    "montanya. En ellas hay colgadas algunas de las armas tipicas que "
	"suelen utilizar los troll.\n");

  AddDetail(({"yunque"}),
  "Es un gran y pesado bloque de metal. El armero golgea contra el el "
    "metal al rojo para darle forma.\n");

  AddDetail(({"horno"}),
  "En el medio de la cueva hay un pequenyo horno. Es alli donde se "
    "calienta la piedra de mineral para fundir el metal que contiene. "
	"Es alli tambien donde se calienta el metal antes de moldearlo en "
	"el yunque. La temperatura del horno no es muy alta y el metal que "
	"con el se trabaja queda muy lejos del que se puede obtener en "
	"cualquier forja.\n");

 SetIntNoise("Oyes el crepitar de las brasas en el horno.\n");
 SetIntSmell("Hay un denso olor a carbor y humo.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(30);

 AddExit("oeste",K_CUEVA("caverna01"));

 CanSell(0);     //El cliente no puede vender a la tienda
 CanAppraise(0); //No se valoran objetos
 CanIdentify(0); //No se identifican objetos
 RemoveDustbin();

 SetShopkeeper(0,([P_SHORT:"Kang el troll",
P_LONG:  "Kang es un troll adulto. Cojea de la pierna derecha, probablemente "
         "debido a alguna grave herida en alguna refriega contra el ejercito "
		 "orco o quiza con algun semejante. Ahora se dedica a fabricar "
		 "toscas armas para ganarse la vida.\n",
P_IDS:({"kang","Kang","tendero","troll"}),
P_LEVEL:10,
P_STR:10,
P_CON:10,
P_DEX:2,
P_INT:1,
P_GENDER:GENDER_MALE
]));

AddArticle(ARMA("vara"), REFRESH_REMOVE, 4);
AddArticle(ARMA("gargaz"), REFRESH_REMOVE, 2);
AddArticle(ARMA("azagaya"), REFRESH_REMOVE, 1);

AddRoomCmd("coger", "coger_cmd");
}

void init()
{
  (::init());
  write("Kang te saluda con un grunyido al entrar en la cueva.\n");
  say(  "Kang saluda con un grunyido a "+NOMBRE+" al entrar a la cueva.\n");
}

int coger_cmd(string str){
 if ((!str)||((str!="yunque")&&(str!="armas"))) return 0;
 if (str=="yunque")
    write("El yunque es demasiado pesado como para que cargues con el.\n");
 if (str=="armas")
    write("Las armas de las paredes estan firmemente sujetas a ellas "
	        "para evitar que alguien tenga la tentacion de cogerlas.\n");
 return 1;
}