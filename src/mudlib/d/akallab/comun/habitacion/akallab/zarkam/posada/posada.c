/*
DESCRIPCION : comedor de una posada/fonda
FICHERO     : /d/akallab/?
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include RAIZ "sys/macros.h"

#include <moving.h>
#include <money.h>

#include <rooms.h>
#include <properties.h>
#include <health.h>             /* for food costs (still not avail) */

inherit ROOM;
inherit "/lib/money";

//macros
#define P_DICE(s)  write(posadero+" dice:'"+s+"'.\n")

//variables internas
string posadero;  //nombre del posadero
string cocinero;  //nombre del cocinero
string tipo;      //posada, fondam etc..
string pos_nom;   //nombre de la posada

static string ultimo_cliente;
static int num_jabalis,num_corderos,num_guisos,num_pollos,num_sopas;

public void reset ()
{
::reset ();
    num_jabalis=random(2)+1;
    num_corderos=random(3)+1;
    num_guisos=random(5)+1;
    num_pollos=random(8)+2;
    num_sopas=random(12)+1;
}

/*
1. EFECTO DE LAS COMIDAS:

 FOOD += n*2
 HP += n*2

2. PARAMETROS DE LAS COMIDAS

[1] Jabali asado      (300 cobre / n=12)
[2] Cordero al horno  (180 cobre / n= 8)
[3] Guiso de ternera  (120 cobre / n= 6)
[4] Pollo con patatas ( 75 cobre / n= 4)
[5] Sopa de verduras  ( 45 cobre / n= 2)

[6] Jarra de vino     ( 10 cobre / DRINK+= 8 / alcohol+=6 / HP+=3)
[7] Jarra de cerveza  ( 10 cobre / DRINK+= 8 / alcohol+=4 / HP+=2)
 */


// --------------------------------------------------------------------------------
string ver_menu()
{
 string menu;
 if (!(num_jabalis||num_corderos||num_guisos||num_pollos||num_sopas))

 menu= posadero+", el posadero, te dice: Lo siento, pero en este momento no nos queda nada. "
       "Vuelve mas tarde cuando "+cocinero+" haya cocinado nuevos platos.\n";
 else {
 menu=
  posadero+" dice: Esto es lo que servimos en esta "+tipo+": "
  "   COMIDAS                                BEBIDAS "
  "1: Jabali asado      (300 cobre)       6: Jarra de vino    ( 10 cobre) "
  "2: Cordero al horno  (180 cobre)       7: Jarra de cerveza ( 10 cobre) "
  "3: Guiso de ternera  (120 cobre) "
  "4: Pollo con patatas ( 75 cobre) "
  "5: Sopa de verduras  ( 45 cobre)\n";
 menu += "Usa 'pedir <numero>' para consumir ahora lo que quieras.\nBuen provecho.\n";
 }
 return(menu);
}


int ver_menu2(){write(ver_menu());return 1;}


int noHayComida(string s)
{
    say(posadero+" el posadero grita a la cocina:'"+cocinero+"! +Nos queda "+s+"?'\n");
    write(posadero+" el posadero grita a la cocina:'"+cocinero+"! +Nos queda "+s+"?'\n");
    say("Desde la cocina se oye a "+cocinero+":'No, ya no queda!'\n");
    write("Desde la cocina se oye a "+cocinero+":'No, ya no queda!'\n");
    P_DICE("Lo siento, no nos queda "+s);
    if (num_jabalis||num_corderos||num_guisos||num_pollos||num_sopas)
         P_DICE("Si te interesa aun nos quedan otras comidas");
    else P_DICE("Vuelve mas tarde cuando "+cocinero+" haya cocinado nuevos platos");
    return 1;
}


void siHayComida(string s)
{
    say(posadero+" el posadero grita a la cocina:'"+cocinero+"! +Nos queda "+s+"?'\n");
    write(posadero+" el posadero grita a la cocina:'"+cocinero+"! +Nos queda "+s+"?'\n");
    say("Desde la cocina se oye a "+cocinero+":'Si carinyo, aun tenemos!'\n");
    write("Desde la cocina se oye a "+cocinero+":'Si carinyo, aun tenemos!'\n");
    P_DICE("Perfecto! Ahora mismo te traigo lo que quieres");
}


void traeComida(string s)
{
    P_DICE("Ahora te traigo "+s);
    say(posadero+" desaparece tras la puerta de la cocina. Al momento vuelve cargado con "
        "varias fuentes y jarras a la mesa donde esta "+NOMBRE+".\n",TP);
    write(posadero+" desaparece tras la puerta de la cocina. Al momento vuelve cargado con "
          "varias fuentes y jarras. Aqui tienes lo que me has pedido, dice "+posadero+".\n");
}


void traeBebida(string s)
{
    P_DICE("Ahora te traigo "+s);
    say(posadero+" desaparece tras la puerta de la cocina. Al momento vuelve cargado con "
        "una generosa jarra a la mesa donde esta "+NOMBRE+".\n",TP);
    write(posadero+" desaparece tras la puerta de la cocina. Al momento vuelve cargado con "
          "una generosa jarra. Aqui tienes lo que me has pedido, dice "+posadero+".\n");
}


tieneDinero(int n)
{
    if (!TP) return 0;
    if (QuerySomeonesValue (TP) < n)
    {
        write("Cuando vas a pagar te das cuenta de que no llevas suficiente dinero. "
              "El posadero "+posadero+" dice: Vaya... parece que no tienes suficiente dinero. Lo "
              "siento pero se ha de pagar lo que se consume.\n");
        return 0;
    }
    write("Le pagas a "+posadero+" el importe de lo que has pedido.\n");
    PayValue (TP, n);
    return 1;
}

digerirComida(n, coste)
{
    if (!TP) return 0;
    if (! TP->AddFood (3 * n)){
        TP->SetFood(TP->QueryMaxFood());
        write("Cuando te traen la comida te das cuenta de que no estas tan hambrient"+AO+" como "
              "creias, por lo que dejas parte en el plato.\n");
    }
    else write("Te comes la comida que habias pedido.\n");
    if (NOMBRE == ultimo_cliente)
        P_DICE("Me alegro de que repita en mi establecimiento.");
    ultimo_cliente = NOMBRE;
    curar(2 * n);
    return 1;
}


curar(n)
{
    int hp, maxhp;

    hp = TP->QueryHP ();
    maxhp =  TP->QueryMaxHP();
    if (hp < maxhp)
    {
        if (hp + n > maxhp) n = maxhp - hp;
        TP->SetHP (hp + n);
    }
}


consumir(string s)
{
  if (!s){P_DICE("Tendras que decirme que es lo que quieres comprar");return 1;}

//[1] Jabali asado      (300 cobre / n=12)
  if (s == "1" || s== "<1>"){
if (!num_jabalis) {noHayComida("jabali asado");return 0;}
                       else siHayComida("jabali asado");
    if (!tieneDinero(300)) return 1;
    traeComida("un jabali asado");
    if (digerirComida(12, 300)) num_jabalis-=1;
    return 1;
  }

//[2] Cordero al horno  (180 cobre / n= 8)
  if (s == "2" || s== "<2>")
  {
    if (!num_corderos) {noHayComida("cordero al horno");return 0;}
                       else siHayComida("cordero al horno");
    if (!tieneDinero(180)) return 1;
    traeComida("un cordero al horno");
    if (digerirComida(8, 180)) num_corderos-=1;
    return 1;
  }

//[3] Guiso de ternera  ( 120 cobre / n= 6)
  if (s == "3" || s== "<3>")
  {
    if (!num_guisos) {noHayComida("guiso de ternera");return 0;}
                      else siHayComida("guiso de ternera");
    if (!tieneDinero(120)) return 1;
    traeComida("un guiso de ternera");
    if (digerirComida(6, 120)) num_guisos-=1;
    return 1;
  }

//[4] Pollo con patatas ( 75 cobre / n= 4)
  if (s == "4" || s== "<4>")
  {
    if (!num_pollos) {noHayComida("pollo con patatas");return 0;}
                      else siHayComida("pollo con patatas");
    if (!tieneDinero(75)) return 1;
    traeComida("un pollo con patatas");
    if (digerirComida(4, 75)) num_pollos-=1;
    return 1;
  }

//[5] Sopa de verduras  ( 45 cobre / n= 2)
  if (s == "5" || s== "<5>")
  {
    if (!num_sopas) {noHayComida("sopa de verduras");return 0;}
                      else siHayComida("sopa de verduras");
    if (!tieneDinero(45)) return 1;
    traeComida("una sopa de verduras");
    if (digerirComida(2, 45)) num_sopas-=1;
    return 1;
  }

//[6] Jarra de vino     (  10 cobre / DRINK+= 8 / alcohol+=6 / HP+=3)
  if (s == "6" || s == "<6>" || s == "vino")
  {
    if (! tieneDinero(10)) return 1;
    traeBebida("una jarra de vino");
    if (! TP->AddDrink(8))
    {
      TP->SetDrink(TP->QueryMaxDrink());
      write("No estas tan sedient"+AO+" como para acabarte la bebida.\n");
    }
    if (! TP->AddAlcohol(6))
    {
      P_DICE("Amig"+AO+", estas bastante borrach"+AO+". Yo de tu no beberia mas");
      return 1;
    }
    write("Es un vino peleon, pero te calienta el cuerpo.\n");
    say (NOMBRE+" se bebe una jarra de vino.\n");
    curar(3);
    return 1;
  }

//[7] Jarra de cerveza  (  10 cobre / DRINK+= 8 / alcohol+=4 / HP+=2)
  if (s == "7" || s == "<7>" || s == "cerveza")
  {
    if (! tieneDinero(10)) return 1;
    traeBebida("una jarra de cerveza");
    if (! TP->AddDrink(8))
    {
      TP->SetDrink(TP->QueryMaxDrink());
      write("No estas tan sedient"+AO+" como para acabarte la bebida.\n");
    }
    if (! TP->AddAlcohol(4))
    {
      P_DICE("Amig"+AO+", estas bastante borrach"+AO+". Yo de tu no beberia mas");
      return 1;
    }
    write("Es una cerveza aceptable, aunque el sabor es un poco fuerte.\n");
    say (NOMBRE+" se bebe una jarra de cerveza.\n");
    curar(2);
    return 1;
  }

  P_DICE("No tenemos ese numero en el menu, intenta otra opcion.");
  return 1;
}


ambiente() {
  string *chats;
  int i;

  chats=(({
     posadero+" se va hacia una mesa al fondo de la "+tipo+".\n",
     posadero+" entra en la cocina y al momento sale cargado con varias fuentes'.\n",
     posadero+" sale de la cocina cargado con varias jarras grandes de bebida'.\n",
     "Un cliente grita:'"+posadero+", a ver cuando vienes a atender aqui de una vez!'\n",
     posadero+" le dice a un cliente:'Marchando su comida!'\n",
     posadero+" le dice a alguien: 'Un momento, lo suyo ya casi esta hecho.'\n",
     "Un cliente dice:'"+posadero+" esto estaba muy bueno, trae otro de lo mismo!'\n",
     posadero+" te dice:'Si quieres ver la lista de las comidas, mira el menu'.\n",
     "Alguien dice:'Esto esta muerto! Bardo, cantanos alguna cancion alegre!'\n",
     posadero+" te dice: 'Tras elegir tu comida, simplemente pidela y te la servire'.\n",
     "Un cliente dice:'"+posadero+", otra ronda para mis amigos! Esta vez pagare yo'.\n",
     "Alguien dice:'"+posadero+", dile a "+cocinero+" que su asado esta muy bueno hoy!'\n",
     cocinero+" dice:'"+posadero+", ven a la cocina un momento!'\n",
     posadero+" dice: Si miras el menu veras las comidas y bebidas que servimos en "
     "este establecimiento. Una vez que elijas, solo tienes que pedirmelo. "
     }));

  i=random(sizeof(chats));
  tell_room(TO,chats[i]);
  call_out("ambiente",15+random(10));

  //if (present(TP, TO)) call_out("ambiente",15+random(10));

  return;
}

int mirar_cmd(string str){
   if ((!str)||((str!=posadero)&&(str!=lower_case(posadero))&&(str!="posadero"))) return 0;
   write(
     posadero+" es el orco propietario de la "+tipo+" "+pos_nom+". Es un tipo "
     "alegre aunque un poco tosco, que no para de ir de un lado para otro de la " +
     tipo+" atendiendo a sus clientes.\n");
  return 1;
}

//--------------------------------------------------------------------------------
create() {
   if (!posadero) posadero="el posadero";
   if (!cocinero) cocinero="la cocinera";
   if (!tipo) tipo="posada";
   if (!pos_nom) pos_nom="sin nombre";

  ::create();
  reset();

  SetIntShort("la " + tipo+" "+pos_nom);

  //SetIntShort() la pone el fichero que hereda

  AddDetail(({"menu"}),SF(ver_menu));
  AddRoomCmd ("menu", SF(ver_menu2));
  AddRoomCmd ("pedir", SF(consumir));
  AddRoomCmd ("mirar", SF(mirar_cmd));
  AddRoomCmd ("m", SF(mirar_cmd));

  SetIntNoise("Oyes a la gente comiendo.\n");
  SetIntSmell("Hmmmm! el olor que llega de la cocina te hace la boca agua.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  //AddItem(PNJ("bardo"),REFRESH_DESTRUCT,1);
  //AddItem(PNJ("cliente"),REFRESH_DESTRUCT,1);

  ambiente();
}

