/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 16-11-98                |
 |               Ultima Modificacion.. 06-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <colours.h>
#include <races.h>
#include <properties.h>
#include <combat.h>


inherit NPC;

#define MX 3

string *nombres;
string *razas;
string *MsgBienvenida;

string p_nombre;
string p_raza;
string funcion,tipo,tipo2;

crear()
{
 mixed *d_raza;

 nombres=({"ester","iriva","sirkana","erika","damita",
           "minerva","sira","nora","vervaene"});
 razas=({"elfo","orco","kender","enano","gnomo","humano","duende"});
 MsgBienvenida=({
     "Hola.. que tal estais?",
     "Hola!!",
     "Eeoooo... ya estoy aqui de nuevo.",
     "Me habeis echado mucho de menos? ;)",
     "Hola a todos!"});

 p_nombre=nombres[random(sizeof(nombres))];
 p_raza=razas[random(sizeof(razas))];

 if (d_raza = RACEMASTER->RaceData(p_raza)) {
   SetAlign(d_raza[RD_ALIGN]);
   SetWeight(d_raza[RD_WEIGHT]);
   SetHands(d_raza[RD_HANDS]+({}));
  }

 if(!funcion)
 {
  funcion=allocate(MX);
  tipo=allocate(MX);
  tipo2=allocate(MX);

  funcion[0]="_sonreir";
  tipo[0]="sonrie";

  funcion[1]="_telepatia";
  tipo[1]="te dice";

  funcion[2]="_decir";
  tipo[2]="dice:";

  InitMatch(funcion,tipo,tipo2);
 }
}

QueryNpcName() { return CAP(p_nombre); }
QueryRealName() { return p_nombre; }

SetTitle(str) {
  SetShort(QueryNpcName()+" "+str);
  return str;
}

void Say(string str) {
 tell_room(ENV(TO),str+"\n"); }

void canal(string canal,string mensaje) {
 CHMASTER->SendEmote(canal,mensaje); }

void canal2(string canal,string mensaje)
{
 mensaje=STR->string_replace(mensaje,"[",TC_GREEN"["TC_NORMAL);
 mensaje=STR->string_replace(mensaje,"]",TC_GREEN"]"TC_NORMAL);
 CHMASTER->SendStr(canal,mensaje);
}

void Tell(object jug,string msg)
{ tell_object(jug,msg+"\n"); }

object QuitarPresay(string str)
{
 string *palabras;
 string d;
 object quien;
 int i;

 palabras = explode(str, " ");
 for (i=0;i<sizeof(palabras);i++)
 {
   if (quien = find_object(LOWER(palabras[i])))
    break;
  }
 if (quien==TO || !quien) return 0;
 return quien;
}

void entrada()
{
 canal("mud",QueryNpcName()+" regresa al mundo");
 call_out("canal2",10,"jugadores","["+QueryNpcName()+"] "+MsgBienvenida[random(sizeof(MsgBienvenida))]);
}

int pertenece(string *palabras, mixed *frase) {
  int i;
  string cap;

  for (i=0; i<sizeof(palabras); i++) {
   cap = "";
   if (member(frase, palabras[i])!=-1) return 1;
   if (palabras[i] && palabras[i]!="") cap = capitalize(palabras[i]);
   if (member(frase, cap)!=-1) return 1;
  }
   return 0;
}

string RespAleatoria(string *respuestas)
{ return respuestas[random(sizeof(respuestas))]; }

string Respuesta(string msg)
{
 mixed *frase;
 string a,b,newstr;

 frase=explode(msg," ");

 newstr = msg;
  if (sscanf(newstr, "%s?%s", a, b)==2) newstr = a + " ? " + b;
  if (sscanf(newstr, "%s!%s", a, b)==2) newstr = a + " ! " + b;
  if (sscanf(newstr, "%s,%s", a, b)==2) newstr = a + " , " + b;
  if (sscanf(newstr, "%s\n%s", a, b)>1) newstr = a;
  frase = explode(newstr, " ");

 if (pertenece(({"Hola","hola"}),frase))
  return RespAleatoria(({"Hola :)","Que tal?",":)","Jejeje, hola.."}));
 if (pertenece(({"estamos","bien","genial"}),frase))
  return RespAleatoria(({"Me alegro","Yo tambien","Genial :)","Jejeje"}));
 if (pertenece(({"eres"}),frase) && pertenece(({"donde"}),frase))
  return RespAleatoria(({"Soy de Donosti","Estoy en Madrid","De Valencia",
                         "Soy asturiana pero vivo en Badajoz"}));
 if (pertenece(({"estas"}),frase) && pertenece(({"donde"}),frase))
  return RespAleatoria(({"No lo se exactamente","En Goldhai, creo","Estoy perdida"}));
 if ((pertenece(({"estas"}),frase) && pertenece(({"como"}),frase))
      || (pertenece(({"comostas"}),frase)))
  return RespAleatoria(({"Estoy bien gracias",
                         "Muy bien, y tu?",
                         "Bien gracias, y tu?"}));
 if (pertenece(({"puta","cabrona","hostia","ostia","joder",
                 "asquerosa","capulla","gilipollas","tonta"}),frase))
  return RespAleatoria(({"Creo que dices demasiados tacos.. cielin!",
                         "Asi no se habla con una dama.",
                         "Jajaja.. me haces reir",
                         "Aleee.. que mal hablado estas hecho"}));
 if (pertenece(({"follas","follar","fornicar","fornicas","jodes"}),frase))
  return RespAleatoria(({"Ya te gustaria a ti follar tanto como yo!",
                         "Eres un poco cabroncete, no?",
                         "Eres un estupido.. no me hables mas",
                         "No quiero seguir hablando contigo",
                         "Vete a la mierda mamon"}));
 if (pertenece(({"soy"}),frase) && pertenece(({"chica","mujer","piva","tia"}),frase))
  return RespAleatoria(({"Que suerte","Eres de los que se hace pasar por tio?",
                         "Como yo?","Muy bien"}));
 if (pertenece(({"au","adios","bye","aurrevoire","chao","ciao","adeu"}),frase))
  return RespAleatoria(({"Adios.. nos vemos",
                         "Au, hasta otra",
                         "Adios, un beso",
                         "Ciao ;))",
                         "Hasta otra!"}));
 if (pertenece(({"jeje","jaja","juajua",":))"}),frase))
  return RespAleatoria(({"Eres muy alegre",
                         "Jajaja.. por que te ries?",
                         "Jajajaja",
                         "No me hagas reir ;)"}));


 return RespAleatoria(({"Dejame, no quiero seguir hablando contigo!",
                        "Oye, estoy ocupada.. luego charlamos, vale?",
                        "jejeje :)",
                        "Eres genial..",
                        "No tengo ganas de charlar."}));
}

_sonreir(str)
{
 string jug,msg;
 object jugador;

 if (sscanf(str, "%s te sonrie%s", jug, msg)>1)
  if(jugador=QuitarPresay(jug)) {
   call_out("Tell",5,jugador,QueryNpcName()+" te sonrie.");
   call_out("Tell",15,jugador,QueryNpcName()+" te dice: Que tal estas?");
   return 1;
  }
 return 0;
}

_decir(str)
{
 string jug,msg;
 object jugador;

 if (sscanf(str, "%s dice: %s", jug, msg)>1)
 {
   call_out("Say",10,QueryNpcName()+" dice: "+Respuesta(msg));
   return 1;
 }
 return 0;
}

_telepatia(str)
{
 string jug,msg;
 object jugador;

 if (sscanf(str, "%s te dice: %s", jug, msg)>1)
 {
  if(jugador=QuitarPresay(jug)) {
   call_out("Tell",5,jugador,QueryNpcName()+" te dice: "+Respuesta(msg));
   return 1;
  }
 }
 return 0;
}

create()
{
 object dinero;

  ::create();
enable_commands();
 crear();
 SetStandard(p_nombre,p_raza,random(3)+2,GENERO_FEMENINO);
 SetShort(p_nombre+" la nueva "+CAP(p_raza));
 AddId(p_nombre);
 AddId(CAP(p_nombre));
 SetWhimpy(30);
 SetAggressive(0);
 SetGoChance(10);
 SetTitle("la nueva "+CAP(p_raza));
 entrada();

 dinero=clone_object("/obj/money");
 dinero->AdjustMoney(random(150)+20,"oro");
 dinero->move(TO);
 AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "una hacha de combate",
      P_LONG:  "Una estupenda hacha de combate. La hoja esta afilada para poder traspasar\n"+"casi cualquier tipo de armadura.\n",
      P_IDS: ({"hacha de combate","hacha"}),
      P_WC: 6,
      P_WEIGHT: 3900,
      P_VALUE: 610,
      P_NUMBER_HANDS: 1,
      P_WEAPON_TYPE:WT_HACHA,
      P_DAM_TYPE:DT_SLASH]));
 AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "una coraza de acero",
      P_LONG:  "Es una coraza totalmente forjada de acero y que cubre practicamente el cuerpo.\n",
      P_IDS: ({"coraza","coraza de acero"}),
      P_AC: 4,
      P_WEIGHT: 6900,
      P_VALUE: 6000,
      P_ARMOUR_TYPE:AT_MAIL,
      P_DAM_TYPE:DT_SLASH]));
}

public varargs void Die(mixed silent) {
  canal("mud",QueryNpcName()+" cortó la conexión");
  ::Die(silent);
}
Death() {
  call_out("remove",5);
}

