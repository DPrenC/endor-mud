/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 25-09-99                |
 |                                                             |
 | 25-09-99 [w] Para resolver el MiniQuest tienes que beber    |
 |              agua en este orden:                            |
 |                  izq-der-izq-cen-izq-der-cen-izq            |
 |              Si lo consigues hacer bien te aumentan tus     |
 |              stats en 5, pero solo momentaneamente.         |
 *=============================================================*/

#include "./path.h"
#include <sounds.h>
#include <properties.h>
#define ATR "hago_quest"
inherit GROOM;

object jugador;
int sin_agua,chorro1,chorro2,chorro3,posicion;

restaurar()
{
 if (!sin_agua)
    tell_object(TP,"La fuente sigue seca, quizás debieras esperar a más tarde.\n");
 else if (chorro1 && chorro2 && chorro3) {
    tell_room(TO,"Empieza a salir un poco más de agua por cada chorro.\n");
    jugador = TP;
    jugador->SetAttribute(ATR,time());
 }
 else {
    tell_room(TO,"Comienza a salir agua por los tres chorros a la vez.\n");
    chorro1 = chorro2 = chorro3 = 1;
    posicion = 0;
        jugador = TP;
        jugador->SetAttribute(ATR,time());
 }
}

pronunciar(string str)
{
 if (!str)
   if (query_verb()=="decir") return notify_fail("No dices nada.\n");
   else return 0;
 if (str!="Urbi e haro khupae" && str!="Urbi e haro khupae") {
   if (query_verb()=="decir") return notify_fail("Dices en voz alta: "+str+"\n");
   else return 0;
 }
 if (query_verb()=="decir") write("Dices en voz alta: Urbi e haro khupae\n");
 call_out("restaurar",3);
 if (query_verb()=="decir") return 1;
 else return 0;
}

_beber(string str)
{
    if(!str) return notify_fail("¿Qué es lo que quieres beber?\n",
        NOTIFY_NOT_VALID);
    if((str=="agua") || (str=="fuente") || (str=="de la fuente") ||
        (str=="agua de la fuente") || (str=="agua de fuente"))
    {
        if (TP->QueryAttribute(ATR)) return notify_fail("¿De qué chorro quieres "
            "beber agua?\n",NOTIFY_NOT_VALID);
        if (TP->QueryDrink()>=TP->QueryMaxDrink())
        {
            say(CAP(TNREAL)+" intenta beber agua, pero está lleno.\n",TP);
            return notify_fail("Tienes el estómago rebosando, no te cabe ni "
                "una gota.\n",NOTIFY_NOT_VALID);
        }
        TP->AddDrink(10);
        say(CAP(TNREAL)+" bebe un buen trago de agua.\n",TP);
        return notify_fail("Bebes un buen trago de agua... Es deliciosa "
            "cuando se tiene sed.\n",NOTIFY_NOT_VALID);
    }

 /* IZQUIERDO */
 if (str=="agua del chorro de la izquierda" || str=="agua del chorro izquierdo" ||
     str=="agua de izquierda" || str=="agua izquierda" || str=="agua chorro izquierdo" ||
     str=="agua de elfo" || str=="agua de escultura elfo" || str=="agua escultura de elfo" ||
     str=="chorro izquierdo")
 {
   if (!sin_agua)
     return notify_fail("La fuente ahora no tira suficiente agua como para "
         "que puedas beber de ella.\n"),0;
   if (!chorro1)
     return notify_fail("La fuente no tira suficiente agua por ese chorro como para que puedas beber.\n"),0;
   if(TP->QueryDrink()>=TP->QueryMaxDrink())
     return notify_fail("No puedes beber más cantidad de agua.\n"),0;
   write("Bebes un poco de agua del chorro izquierdo.\n");
   say(CAP(TNREAL)+" bebe un poco de agua de la fuente.\n");
   sin_agua--;
   TP->AddDrink(1);
   if (!jugador || (jugador && jugador!=TP)) {
     tell_room(TO,"Deja de salir agua de todos los chorros.\n");
     chorro1 = chorro2 = chorro3 = 0;
    TP->RemoveAttribute(ATR);
    posicion = jugador = 0;
    return 1;
    }
    if (!posicion)
    {
        posicion++;
        chorro1 = 0;
        return tell_room(TO,"Deja de salir agua del chorro izquierdo.\n"),1;
    }
    if (posicion==2)
    {
        posicion++;
        chorro1 = 0;
        chorro3 = 1;
        return tell_room(TO,"Deja de salir agua del chorro izquierdo y "
            "comienza a salir por el derecho.\n"),1;
    }
    if (posicion==4)
    {
        posicion++;
        chorro1 = 0;
        chorro2 = 1;
        return tell_room(TO,"Deja de salir agua del chorro izquierdo y "
            "comienza a salir por el central.\n"),1;
    }
    if (posicion==7)
    {
        if (QUESTMASTER->QueryQuestSolved("fuente_crowy",TP))
        {
            tell_room(TO,"Las tres esculturas se ocultan en la fuente pero "
                "vuelven de inmediato.\n");
            tell_room(TO,"El agua brota otra vez de los tres chorros.\n");
            return 1;
        }
        else
        {
            tell_room(TO,"Las tres esculturas se ocultan y una intensa aura "
                "ilumina a "+CAP(TP->QueryRealName())+".\n",({TP}));
            write("Las tres esculturas se ocultan en la fuente y comienzas a "
                "notar un extraño poder en tu cuerpo. Tu fuerza, "
                "inteligencia, destreza y constitución han aumentado de "
                "forma considerable, aunque igual estos efectos no duren "
                "mucho.\n");
            QUESTMASTER->SetPlayerQuest("fuente_crowy",TP);
            QUESTMASTER->InformSolution(capitalize(TP->QueryName())+" ha conseguido el poder de "
                "la fuente de Crowy!\n");
            if (TP->QueryGender()==GENDER_FEMALE)
            TP->set_title("la poderosa guerrera legendaria");
            else
            TP->set_title("el poderoso guerrero legendario");
            TP->ModifyAttr("Str",5);
            TP->ModifyAttr("Int",5);
            TP->ModifyAttr("Con",5);
            TP->ModifyAttr("Dex",5);
            tell_room(TO,"Las esculturas aparecen y el agua vuelve a brotar de los chorros.\n");
            chorro1 = chorro2 = chorro3 = 1;
            TP->RemoveAttribute(ATR);
            posicion = jugador = 0;
        }
   }

   tell_room(TO,"Deja de salir agua de todos los chorros.\n");
   chorro1 = chorro2 = chorro3 = 0;
    TP->RemoveAttribute(ATR);
   posicion = jugador = 0;
   return 1;
 }

 /* CENTRAL */
 if (str=="agua del chorro del centro" || str=="agua del chorro central" ||
     str=="agua de centro" || str=="agua centro" || str=="agua chorro central" || str=="agua chorro centro" ||
     str=="agua de humano" || str=="agua de escultura humano" || str=="agua escultura de humano" ||
     str=="chorro central")
 {
   if (!sin_agua)
     return notify_fail("La fuente ahora no tira suficiente agua como para que puedas beber de ella.\n"),0;
   if (!chorro2)
     return notify_fail("La fuente no tira suficiente agua por ese chorro como para que puedas beber.\n"),0;
   if(TP->QueryDrink()>=TP->QueryMaxDrink())
     return notify_fail("No puedes beber más cantidad de agua.\n"),0;
   write("Bebes un poco de agua del chorro central.\n");
   say(CAP(TNREAL)+" bebe un poco de agua de la fuente.\n");
   sin_agua--;
   TP->AddDrink(1);
   if (!jugador || (jugador && jugador!=TP)) {
     tell_room(TO,"Deja de salir agua de todos los chorros.\n");
     chorro1 = chorro2 = chorro3 = 0;
    TP->RemoveAttribute(ATR);
     posicion = jugador = 0;
     return 1;
   }
   if (posicion==3) {posicion++; chorro2 = 0; chorro1 = 1; return tell_room(TO,"Deja de salir agua del chorro central y comienza a salir por el izquierdo.\n"),1; }
   if (posicion==6) {posicion++; chorro2 = 0; chorro3 = 1; return tell_room(TO,"Deja de salir agua del chorro central y comienza a salir por el derecho.\n"),1; }

   tell_room(TO,"Deja de salir agua de todos los chorros.\n");
   chorro1 = chorro2 = chorro3 = 0;
    TP->RemoveAttribute(ATR);
   posicion = jugador = 0;
   return 1;
 }

 /* DERECHO */
 if (str=="agua del chorro de la derecha" || str=="agua del chorro derecho" ||
     str=="agua de derecho" || str=="agua derecho" || str=="agua chorro derecho" || str=="agua chorro derecha" ||
     str=="agua de enano" || str=="agua de escultura enano" || str=="agua escultura de enano" ||
     str=="chorro derecho")
 {
   if (!sin_agua)
     return notify_fail("La fuente ahora no tira suficiente agua como para que puedas beber de ella.\n"),0;
   if (!chorro3)
     return notify_fail("La fuente no tira suficiente agua por ese chorro como para que puedas beber.\n"),0;
   if(TP->QueryDrink()>=TP->QueryMaxDrink())
     return notify_fail("No puedes beber más cantidad de agua.\n"),0;
   write("Bebes un poco de agua del chorro derecho.\n");
   say(CAP(TNREAL)+" bebe un poco de agua de la fuente.\n");
   sin_agua--;
   TP->AddDrink(1);
   if (!jugador || (jugador && jugador!=TP)) {
     tell_room(TO,"Deja de salir agua de todos los chorros.\n");
     chorro1 = chorro2 = chorro3 = 0;
    TP->RemoveAttribute(ATR);
     posicion = jugador = 0;
     return 1;
   }
   if (posicion==1) {posicion++; chorro3 = 0; chorro1 = 1; return tell_room(TO,"Deja de salir agua del chorro derecho y comienza a salir por el izquierdo.\n"),1; }
   if (posicion==5) {posicion++; chorro3 = 0; chorro1 = 1; return tell_room(TO,"Deja de salir agua del chorro derecho y comienza a salir por el izquierdo.\n"),1; }

   tell_room(TO,"Deja de salir agua de todos los chorros.\n");
   chorro1 = chorro2 = chorro3 = 0;
    TP->RemoveAttribute(ATR);
   posicion = jugador = 0;
   return 1;
 }

 return notify_fail("¿De que chorro quieres beber agua?\n"),0;
}

string mirar_chorro()
{
 string s;

 if (!sin_agua || (!chorro1 && !chorro2 && !chorro3)) s="Miras con detenimiento las esculturas y ves que la de la izquierda"
" se asemeja bastante al cuerpo de un elfo, la del centro se parece al "
"cuerpo de un humano y la de la derecha es parecida al cuerpo de un enano. "
"Observas como no sale agua de ninguno de los chorros.\n";

 else if (!chorro1) s="Miras con detenimiento las esculturas y ves que la de la izquierda"
" se asemeja bastante al cuerpo de un elfo, la del centro se parece al "
"cuerpo de un humano y la de la derecha es parecida al cuerpo de un enano. "
"Observas como no sale agua del chorro de la izquierda.\n";

 else if (!chorro2) s="Miras con detenimiento las esculturas y ves que la de la izquierda"
" se asemeja bastante al cuerpo de un elfo, la del centro se parece al "
"cuerpo de un humano y la de la derecha es parecida al cuerpo de un enano. "
"Observas como no sale agua del chorro del centro.\n";

 else if (!chorro3) s="Miras con detenimiento las esculturas y ves que la de la izquierda"
" se asemeja bastante al cuerpo de un elfo, la del centro se parece al "
"cuerpo de un humano y la de la derecha es parecida al cuerpo de un enano. "
"Observas como no sale agua del chorro de la derecha.\n";

 else s = "Miras con detenimiento las esculturas y ves que la de la izquierda"
" se asemeja bastante al cuerpo de un elfo, la del centro se parece al "
"cuerpo de un humano y la de la derecha es parecida al cuerpo de un enano.\n";

 return s;
}


create()
{
 ::create();
 chorro1 = chorro2 = chorro3 = 1;
 posicion = jugador = 0;
 sin_agua=40;

 SetIntShort("una fuente");
 SetIntLong(
"Estás al borde de una fuente de piedra de la que salen tres chorros de agua\n\
de tres esculturas talladas en la piedra. Puedes ver una placa en la parte\n\
inferior con una leyenda, aunque de momento, si bebes te calmará la sed. Al\n\
Norte hay un pequeño jardín y si vas al Sur llegarás a la entrada de la\n\
ciudad. La calle también continua hacia el Este y el Oeste.\n");

 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"placa","leyenda"}),
"Puedes leer:\n\
Dice la leyenda que si bebes de los tres chorros en un orden determinado,\n\
después de haber pronunciado las palabras 'Urbi e haro khupae' te hará la\n\
persona más poderosa de todos los tiempos.\n");
 AddReadMsg(({"placa","leyenda"}),
"Puedes leer:\n\
Dice la leyenda que si bebes de los tres chorros en un orden determinado\n\
después de haber pronunciado las palabras 'Urbi e haro khupae' te hará la\n\
persona más poderosa de todos los tiempos.\n");

 AddDetail(({"fuente","fuente de piedra","bebedero","fuente piedra"}),
"Puedes ver una enorme fuente esculpida en piedra y de la que sale un chorro\n\
de agua de cada uno de los tres esculturas talladas sobre ella. Quizás debieras\n\
mirar con más atención los objetos y después beber un poco de la fuente.\n");
 AddDetail(({"objetos","esculturas talladas","esculturas","chorros","chorro"}), SF(mirar_chorro));

 AddRoomCmd(({"decir","pronunciar","'"}),"pronunciar");

 AddExit("sur",CROWY("entrada1"));
 AddExit("norte",CROWY("jardin"));
 AddExit("este",CROWY("calle10"));
 AddExit("oeste",CROWY("calle7"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);
 AddItem(PNJ("crowy/kguardia_orco"),REFRESH_DESTRUCT);

 SetLocate("crowy");
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}

reset()
{
 sin_agua=40;
 ::reset();
}

void init()
{
 add_action("_beber","beber");
 ::init();
}

/* DEBUG */
string QueryChorro() {
 return "POSICION: "+posicion+" IZQUIERDO: "+chorro1+" CENTRAL: "+chorro2+" DERECHO: "+chorro3;
}