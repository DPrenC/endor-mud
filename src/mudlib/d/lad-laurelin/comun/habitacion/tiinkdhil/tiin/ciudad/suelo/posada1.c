/*
*
* Notas: Hay que crear las llaves4-6.c y hecharles un ojo a las llaves1-3.c
* Fuentes cogidas y adaptadas de:
*
*/

/* ------------------------------ { INCLUDES } -----------------------------*/

#include <moving.h>
#include <money.h>


#include <rooms.h>
#include <properties.h>
#include <health.h>
#include "./path.h"

/* ------------------------------ { DEFINES } ------------------------------ */

#define Name     (TP->QueryName())
#define Speak(s) write ("El posadero dice: "+s+"\n")

/* ------------------------------ { INHEIRTS } ----------------------------- */

inherit SHOP;
inherit "/lib/money";

/* --------------------------- { VARIABLES & TYPOS } --------------------------- */

static int comida3, comida2, comida4, comida1;
static string last_eater;

/* ------------------------- { ¿INICILIZAR VARIABLES? } ------------------------ */

reset ()
{
::reset ();
    comida1 = random (2) +1;
    comida3 = random (8) + 2;
    comida2 = random (5) + 1;
    comida4 = random (12) + 1;
}

/* ----------------------- { FUNCIONES & PROCEDIMIENTOS } ---------------------- */

/* ------ { Funcion : ir_oeste } ------ */
int ir_oeste()
{
   if (present("llave1",TP) || present("llave2",TP) || present("llave3",TP) ||
       present("llave4",TP) || present("llave5",TP) || present("llave6",TP))
     {
      write("El posadero te para los pies.\n");
      say("El posadero detiene a "+TP->QueryName()+".\n");
      tell_room(TO, "El posadero dice: Por favor, noble "+TP->QueryRace()+
                " A donde se dirige con mi llave!? Tiene que 'depositarla' antes de salir.\n");
      return 1;
   } else {
       TP->move(TCSUELO("viajero2"),M_GO); // mover el obj a la calle.
       return 1;
   }
}

/* ------ { Funcion : ir_arriba } ------ */
int ir_arriba()
{
    tell_room(TCSUELO("./posada/privado1"),"Unos ligeros crugidos ascienden por la escalera.\n");
    TP->move(TCSUELO("./posada/pasillo1"),M_GO);
    return 1;
}

/* ------ { Funcion : mostrar_menu } ------ */

mostrar_menu ()
{
    string menu;
    menu = "\n";
    if ( ! (comida3 || comida2 || comida4 || comida1))
        menu +="El posadero dice: Lo siento pero estamos con la despensa vacia... vuelva otro dia.\n";
    else
      {
        menu +="         Lista de comidas y bebidas\n"
               " --------------------------------------------\n";
        menu +="  1: Salmon ahumado         --> 120 cobre.\n"
               "  2: Ternera con guarnicion -->  80 cobre.\n"
               "  3: Pollo                  -->  50 cobre.\n"
               "  4: Sopa de pan            -->  30 cobre.\n"
               "  5: Cerveza de primera     -->   5 cobre.\n";
        menu +="\nUsar 'comprar <numero>' para consumir ahora lo que quieras.\n";
      }
    write(menu);
    return 1;
}

/* ------ { Funcion : no_food } ------ */
no_food ()
{
	Speak ("Lo siento... pero no nos queda");
	if (comida3 || comida2 || comida4 || comida1)
		Speak ("Por que no lo intentas con otra comida?");
	else
		Speak ("Vuelva despues, gracias");
	return 1;
}

/* ------ { Funcion : pays } ------ */
pays (int n)
{
	if (!TP) return 0;
	if (QuerySomeonesValue (TP) < n)
	{ Speak ("No hay dinero, no hay comida.");
		return 0;
	}
	PayValue (TP, n);
	return 1;
}

/* ------ { Funcion : tease } ------ */
tease (n, cost)
{
	/* is it too rich ? */
	if (!TP) return 0;
	if (! TP->AddFood (3 * n))
	{
                Speak ("Estas que revientas... vuelve otro dia.");
		PayValue (TP, -cost);
		return 0;
	}

	if (Name == last_eater)
		Speak ("Espero que la comida sea de su agrado.");
	last_eater = Name;
	heal (2 * n);
	return 1;
}

/* ------ { Funcion : heal } ------ */
heal (n)
{
	int hp, maxhp;

	hp = TP->QueryHP (), maxhp =  TP->QueryMaxHP ();
	if (hp < maxhp)
	{
		if (hp + n > maxhp)
			n = maxhp - hp;
		TP->SetHP (hp + n);
	}
}

/* ------ { Funcion : buy } ------ */
buy (string s)
{
	if (! s)
	{
            Speak ("Que va a tomar?");
		return 1;
	}
	/* salmon, price 120, heals 12 */

	if (s == "1" || s== "<1>")
	{
		if (! comida1) return no_food();
		if (! pays (120)) return 1;
                write ("Salmon del norte....\n");
                say (Name+" ha pedido salmon\n");
		if (tease (12, 120))
			comida1 = comida1 - 1;
		return 1;
	}

	/* ternera, price 80, heals 8 */
	if (s == "2" || s== "<2>")
	{
		if (! comida2) return no_food ();
		if (! pays (80)) return 1;
                write ("Con pimiento y tomate.\n");
                say (Name+" ha pedido ternera con guarnicion\n");
		if (tease (8, 80))
			comida2 = comida2 - 1;
		return 1;
	}
	/* pollo, price 50, heals 4 */
	if (s == "3" || s == "<3>")
	{
		if (! comida3) return no_food ();
		if (! pays (50)) return 1;
                write ("Pollo de la polleria....\n");
                say (Name+" ha pedido pollo\n");
		if (tease (4, 50))
			comida3 = comida3 - 1;
		return 1;
	}
	/* sopa, price 30, heals 2 */
	if (s == "4" || s == "<4>")
	{
		if (! comida4) return no_food ();
		if (! pays (30)) return 1;
                write ("Mira que buena esta....\n");
                say (Name+" ha pedido sopa de pan\n");
		if (tease (2, 30))
			comida4 = comida4 - 1;
		return 1;
	}
        if (s == "5" || s == "<5>" || s == "cerveza" || s== "birra")
	{
		if (! pays (5)) return 1;
		if (! TP->AddDrink(8))
		{
			Speak(
"No se te ve con sed...vuelve luego, gracias.");
			PayValue (TP, -4);
			return 1;
		}
		if (! TP->AddAlcohol(4))
		{
			Speak(
"Ya has bebido suficiente, ¨no?.");
			PayValue (TP, -4);
			return 1;
		}
		write(
"Esta buena la cerveza, ¨verdad?.\n");
		say (Name+" se bebe una cerveza.\n");
		heal (2);
		return 1;
	}
	Speak ("No tenemos ese numero en el menu, intenta otra opcion.");
	return 1;
}


/* --------------------------- { CUERPO DEL OBJETO } --------------------------- */

create() {
   ::create();

   SetIntShort("la posada El Viajero");
   SetIntLong(
"El ambiente de la posada es bastante relajado. Una gran alfombra cubre todo\n"
"el suelo desde la entrada hasta las escaleras que dan al segundo piso. Detras\n"
"del mostrador hay un cuadro bastante llamativo. Varias antorchas iluminan la\n"
"habitacion y un timbre decora el mostrador.\n");
   SetIntBright(70);
   SetIndoors(1);
   AddArticle("llave1",REFRESH_REMOVE,1);
   AddArticle("llave2",REFRESH_REMOVE,1);
   AddArticle("llave3",REFRESH_REMOVE,1);
   AddArticle("llave4",REFRESH_REMOVE,1);
   AddArticle("llave5",REFRESH_REMOVE,1);
   AddArticle("llave6",REFRESH_REMOVE,1);
   RemoveDustbin();
   SetSell(0);
   CanShow(0);
   SetAppraise(0);
   SetIdentify(0);

   AddDetail(({"alfombra","gran alfombra"}),
"Cubre todo el suelo y esta decorada con rombos y figuras geometricas.\n");
   AddDetail(({"escaleras"}),
"Las escaleras llevan al segundo piso y estan construidas en piedra.\n");
   AddDetail(({"mostrador"}),
"Modelado en la mas fina madera se ve desgastado por paso del tiempo.\n");
   AddDetail(({"cuadro"}),
"Contiene el impresionante dibujo de un dragon rojo descansando en un hermoso\n"
"lago con un bosque espeso a su espalda.\n");
   AddDetail(({"timbre"}),
"Es un pequenyo timbre que puedes usar para llamar la atencion del encargado.\n");
   AddDetail(({"antorchas"}),
"Decoran las paredes e iluminan la habitacion.\n");

   AddExit("arriba",SF(ir_arriba));
   AddExit("norte",TCSUELO("./posada/privado1"));
   AddExit("este",TCSUELO("./posada/cocina"));
   AddExit("noreste",TCSUELO("./posada/privado2"));
   AddExit("oeste",SF(ir_oeste));

   AddRoomCmd ("menu", SF(mostrar_menu));
   AddRoomCmd ("comprar", SF(buy));
   AddRoomCmd ("pedir", SF(buy));

   SetLocate("posada");
/* Anyadir path   SetShopkeeper(PNJ("posadero")); */
}

/* ------------------------ { DECLARACION DE ACCIONES } ------------------------ */

init() {
   ::init();
    add_action("Devuelta","depositar");
    add_action("Devuelta","devolver");
    add_action("Devuelta","entregar");
    add_action("Venta","vender");
    add_action("Timbre","usar");
    add_action("Timbre","tocar");
    add_action("Timbre","llamar");
    add_action("Timbre","pulsar");
    add_action("Timbre","apretar");
    add_action("Timbre","golpear");
    add_action("Matar","matar");
}

/* -------------------------------- { ACCIONES } ------------------------------- */

Devuelta(string str){
object ob;
   if (str != "llave" &&
      (   present("llave1",TP)
       || present("llave2",TP)
       || present("llave3",TP)
       || present("llave4",TP)
       || present("llave5",TP)
       || present("llave6",TP)
      ))
     {
      write("Depositar QUE?\n");
      return 1;
     }

   if (!present("llave",TP)) return 0;

   if (present("llave1",TP))
     {
       ob = present("llave1",TP);
       ob->remove();
       if(ob) destruct(ob);
       write("Entregas la llave al posadero, y este la coloca en su sitio");
       say(TP->QueryName()+" entrega una llave al posadero.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
/* poner el path       TO->AddArticle(OTROS+"llave1",REFRESH_REMOVE,1); */
       return 1;
     }

   if (present("llave2",TP))
     {
       ob = present("llave2",TP);
       ob->remove();
       if (ob) destruct(ob);
       write("Entregas la llave al posadero, y este la coloca en su sitio");
       say(TP->QueryName()+" entrega una llave al posadero.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
/* poner el path       TO->AddArticle(OTROS+"llave2",REFRESH_REMOVE,1); */
       return 1;
     }

   if (present("llave3",TP))
     {
       ob = present("llave3",TP);
       ob->remove();
       if (ob) destruct(ob);
       write("Entregas la llave al posadero, y este la coloca en su sitio");
       say(TP->QueryName()+" entrega una llave al posadero.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
/* poner el path       TO->AddArticle(OTROS+"llave3",REFRESH_REMOVE,1); */
       return 1;
     }

   if (present("llave4",TP))
     {
       ob = present("llave4",TP);
       ob->remove();
       if (ob) destruct(ob);
       write("Entregas la llave al posadero, y este la coloca en su sitio");
       say(TP->QueryName()+" entrega una llave al posadero.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
/* poner el path para el obj       TO->AddArticle("llave4",REFRESH_REMOVE,1); */
       return 1;
     }
   if (present("llave5",TP))
     {
       ob = present("llave5",TP);
       ob->remove();
       if (ob) destruct(ob);
       write("Entregas la llave al posadero, y este la coloca en su sitio");
       say(TP->QueryName()+" entrega una llave al posadero.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
/* poner el path para el obj       TO->AddArticle(OTROS+"llave3",REFRESH_REMOVE,1); */
       return 1;
     }


   if (present("llave6",TP))
     {
       ob = present("llave6",TP);
       ob->remove();
       if (ob) destruct(ob);
       write("Entregas la llave al posadero, y este la coloca en su sitio");
       say(TP->QueryName()+" entrega una llave al posadero.\n");
       tell_room(TO,"El posadero dice: Gracias "+TP->QueryRace()+". Vuelve "
                 "cuando quieras.\n");
/* poner el path para el obj       TO->AddArticle(OTROS+"llave3",REFRESH_REMOVE,1); */
       return 1;
     }

} //fin del Devuelta()

Matar(string str) {

     if (!str) { write("Matar a quien?\n"); return 1; }

/* hay que poner el nombre al posadero y los descriptores */

     if (str == "posadero" || str == "ashurak" || str == "el posadero" ||
         str == "al posadero" || str == "Ashurak" || str == "Ashurak, el posadero")
       {
        write("No seria muy inteligente matar al posadero en SU posada. "
              "Podria traerte complicaciones.\n");
        return 1;
       }
     else return 0;
}

Timbre(string str) {
      if (str != "timbre"){
	 write("Que quieres hacer con eso?\n");
	 return 1;
        }
      if (QueryShopkeeper()) {
         write("Aporreas el timbre que hay sobre la barra.\n");
         say(TP->QueryName()+" toca el timbre que hay sobre la barra.\n");
         tell_room(TO,"El posadero dice: "+capitalize(TP->QueryRace())+", no veis que estoy aqui?? Que deseas?\n");
         return 1;
        }
      else {
         write("Aporreas el timbre que hay sobre la barra.\n"
               "Pero nadie acude a atenderte.\n");
         say(TP->QueryName()+" toca el timbre que hay sobre la barra.\n");
         return 1;
        }
}

Venta(string str) {
    if (!str) { write("Vender que?.\n"); return 1; }
    if (QueryShopkeeper()) {
       write("Intentas vender tu "+str+" al posadero.\n");
       say(TP->QueryName()+" intenta vender algo al posadero.\n");
       tell_room(TO,"El posadero dice: Lo siento alabado, "+TP->QueryRace()+". No suelo comprar nada.\n");
       return 1;
      }
    else {
       write("No ves aqui a nadie para venderle nada.\n");
       return 1;
      }
}

