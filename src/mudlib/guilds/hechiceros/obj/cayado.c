/*
        SIMAURIA [/guilds/hechicero/obj/cayato.c]
        ========

        [g] Guybrush (email: guybrush@simauria.upv.es)
	[m] Maler (maler@simauria.upv.es)
	[h] Nyh (nyh@simauria.upv.es)

	28/10/99 [g] Creación.
	13/09/00 [m] Creación (pero esta vez en serio)
	13/09/00 [m] Añado la funcion QuerySaveName(), ya casi ta funcional
	04/10/00 [m] Comienzo la implementacion del luz
	31/10/00 [m] Ya casi esta termina la vara, me falta el concentrar,
			voy con eio
 	25-04-03 [h] Con el nuevo sistema de combate me penco las actuales
 			habilidades de combate de aqui
*/
#include "/secure/daemons.h"
#include <magicd.h>
#include <wizlevels.h>
#include <properties.h>
#include <guild.h>
#include <skills.h>
#include <colours.h>
#include <combat.h>
#include <moving.h>
#include "./path.h"

#define GEN(x,y) ((TP->QueryGender()==2?x:y))
#define P_CONCENTRADO "P_CONCENTRADO"
#define P_LANZANDO "P_LANZANDO"
#define H_MASTER H_HOME+"/hmaster"

inherit "/std/weapon";

inherit G_GUILDOBJ;

//[m] restrinjo materiales a saco

#define MATERIALES_ILEGALES   ({M_ALUMINIO_TXT,M_PLOMO_TXT,M_ACERO_TXT,M_HIERRO_TXT,M_COBRE_TXT,M_BRONCE_TXT,\
                                M_PLATA_TXT,M_ORO_TXT,M_PLATINO_TXT,M_TITANIO_TXT,M_MITHRIL_TXT,M_ADAMANTIO_TXT,M_ESPECIAL_TXT})
#define MATERIALES_LEGALES  ({M_TELA_TXT,M_CUERO_TXT,M_PIEL_TXT})
#define OTROS_MATERIALES  ({M_MADERA_TXT,M_HUESO_TXT,M_PIEDRA_TXT,M_CRISTAL_TXT})

static object hechicero;
static string nombre_h;
//[m] Addicion del QuerySaveName() q guy lo coloque donde le rote
varargs string QuerySaveName(string appendix)
{
 string s;

 if(!appendix) appendix="";
 if(nombre_h) s=lower_case(nombre_h);
 else s="nadie";
 s=s+appendix;
 s=H_SAVE(s);
 return s;
}
create()
{
   int i;

   ::create();
   if (!clonep()) return;

   // Cosas normalitas del /std/thing
   //
   seteuid( getuid( TO ) );
   //[m] lo pongo a dos manos, WC10, y tipo bludgeon
   SetStandard(WT_VARA, 10, P_SIZE_GENERIC, M_MADERA);
   SetShort( "un cayado" );
   SetIds( ({ "cayado__hech", "cayado", "cayado de hechicero" }) );
   SetWeight( 0 );
   SetValue( 0 );
   Set(P_NUMBER_HANDS, 2);
   Set( P_NOSELL, "No puedes vender tu cayato.\n" );
   Set( P_NOBUY );
   Set( P_NOGIVE, "No puedes dar tu cayato.\n" );
   Set( P_NODROP, "No puedes tirar tu cayato.\n" );

   /* --- COSAS DE GREMIO --- */

   SetUsage( EQM_WIELD );
   SetGuild("/guilds/hechiceros/hechiceros");

   // Comprueba que el gremio del tipo/a que lleva esta vara es del gremio
   // de hechiceros.
   //
   if( TP )
   {
      SetObjectOwner( TP );
      if( TP->QueryGuild() != GC_HECHICEROS ) call_out( "remove", 1 );
   }

   // Carga el objeto.
   //[m] esto petaba, me se de alguien q no se aclara ni con sus propios defines
  restore_object(QuerySaveName(""));

   // Muestra las el contenido de /docs/NOTICIAS una sola vez.
   //
   if( clonep( TO ) && file_size( H_HOME + "NOTICIAS" ) > 0 )
   //[m] de nuevo, fallo con los defines
      cat(H_DOCS("NOTICIAS"));
}

object QueryObjectOwner() { return hechicero; }
int SetObjectOwner(object jug)
{
 if (!jug || !jug->QueryIsPlayer()) return 0;
 hechicero=jug;
 nombre_h=jug->QueryRealName();
 return 1;
}

int HasSkill(string habilidad)
{
 return QueryObjectOwner()->HasSkill(habilidad);
}
//[m] meto aqui el SetLong()
string QueryLong()
{
string s;
s="No es más que un palo de madera algo deforme que, en el extremo superior,\n\
termina en una garra que sostiene una especie de roca de cristal.\n";

if (TP==QueryObjectOwner())
   s+="Es el cayado que te fue entregado cuando te uniste al gremio de Hechiceros.\n\
   Puedes usar el comando 'gayuda' para obtener más información del gremio.\n";
 return W(s);
}

string QueryTituloHechicero()
{
   string str;

 str=(TP->QueryGender()==2?"la hechicera":"el hechicero");
 switch(TP->QueryLevel())
 {
  case   0..3: return GEN("la hechicera novata","el hechicero novato");
  case   4..5: return GEN("la aprendiz de hechicera","el aprendiz de hechicero");
  case   6..7: return GEN("la pequeña hechicera","el pequeño hechicero");
  case   8..9: return GEN("la hechicera","el hechicero");
  case 10..11: return GEN("la hechicera experimentada","el hechicero experimentado");
  case 12..14: return GEN("la conocida hechicera","el conocido hechicero");
  case 15..17: return GEN("la famosa hechicera","el famoso hechicero");
  case 18..20: return GEN("la gran hechicera","el gran hechicero");
  case 21..23: return GEN("la poderosa hechicera","el poderoso hechicero");
  case 24..28: return GEN("la temible hechicera","el temible hechicero");
  case 29..33: return GEN("la temible hechicera oscura","el temible hechicero oscuro");
  case 34..37: return GEN("la portadora de luz","el portador de luz");
  case 38..43: return GEN("la creadora de luz","el creador de luz");
  case 44..49: return GEN("la invencible hechicera","el invencible hechicero");
  case     50: return GEN("la omnipotente hechicera","el omnipotente hechicero");
  default: return str;
 }
   return str;
}

public mixed ChkEquip(object pl, object armour, int flags)
{
  string material;

    if ( !(flags&EWF_WEAPON) )
	return EQ_OK;
    if (!armour || (pl != QueryObjectOwner()))
	return "Me parece que no vas a poder ponerte eso tan facilmente.\n";

    if (!armour->QueryArmourType()) return EQ_OK;

    // [w] Pueden llevar anillos y amuletos de metal.
    if (armour->QueryArmourType()==AT_AMULETO || armour->QueryArmourType()==AT_ANILLO)
         return EQ_OK;

    // [w] Pueden ponerse la coraza de acero mágica del conjuro 'coraza ligera'.
    //	if (armour->QueryCorazaLigera()) return EQ_OK;

    // [k] Pues eso, que es un string
    //material=(mixed) armour->QueryMaterial()||M_DESCONOCIDO_TXT;
    material=(armour->QueryMaterial()||M_DESCONOCIDO_TXT);

    // [k] Esta línea es la que lo jode todo cuando la gente no sigue
    // los estandares, así que la comento y pongo la buena.
    if (member(MATERIALES_LEGALES,material)==(-1))
      return W(
        "Tu condición de conjurador te impide llevar protecciones de "+
        ((material!="")?(material):("ese material"))+".\n");

    return ::ChkEquip(pl, armour, flags);
}

//Creacion del comando luz.
luz_cmd()
{
object *ob;
int i,j;
j=0;
if (TO->QueryLight()!=0) {write("Ya está encendido.\n");return 1;}
//[m] chequeo q el palo esta empunyao
ob=QueryObjectOwner()->QueryWeapons();
for(i=0;i<sizeof(ob);i++)
{
if(ob[i]==TO)j++;
}

if(j!=0)
{
	TO->SetLight(20);
	tell_object(QueryObjectOwner(),"Gritas en alto la palabra luz, y pocos instantes después, "
	"la gema de cristal en la punta\n"
	"de tu cayado reacciona, iluminándo suavemente a su alrededor.\n"
	"Para apagar el cayado pon 'apagar'.\n");
	tell_room(environment(QueryObjectOwner()),capitalize(QueryObjectOwner()->QueryName())+" grita 'luz'. Acto seguido, "
	"la punta del cayado que empuña se ilumina levemente.\n",(({QueryObjectOwner()})));
	return 1;
}
else
{
tell_object(QueryObjectOwner(),"Gritas en alto la palabra luz, pero nada pasa. "
	"quizá debas empuñar el cayado para hacer eso.\n");
	tell_room(environment(QueryObjectOwner()),capitalize(QueryObjectOwner()->QueryName())+" grita 'luz'.\n "
	"Aparentemente nada pasa, y ves como mira a su alrededor consternado.\n",(({QueryObjectOwner()})));
return 1;
}
}

//Creacion del comando apagar.
apagar_cmd()
{
object *ob;
int i,j;
j=0;
if(TO->QueryLight()==0)
{
tell_object(QueryObjectOwner(),"Quizá deberías encenderlo antes, para ello pon 'luz'.\n");
return 1;
}
//[m] chequeo q el palo esta empunyao
ob=QueryObjectOwner()->QueryWeapons();
for(i=0;i<sizeof(ob);i++)
{
if(ob[i]==TO)j++;
}
if(j==0)
{
TO->SetLight(0);
tell_object(QueryObjectOwner(),"Tu cayado se apaga.\n");
	tell_room(environment(QueryObjectOwner()),capitalize("El cayado de "+QueryObjectOwner()->QueryName())+" se apaga.\n",(({QueryObjectOwner()})));
	return 1;
}
if(j!=0)
{
	TO->SetLight(0);
	tell_object(QueryObjectOwner(),"Gritas en alto la palabra oscuridad.\n"
	"Al instante, el extremo de tu cayado vacila un momento y se apaga lentamente.\n"
	"Para encender el cayado pon 'luz'.\n");
	tell_room(environment(QueryObjectOwner()),capitalize(QueryObjectOwner()->QueryName())+" grita 'oscuridad'.\n"
	"Acto seguido, la punta del cayado que empuña oscila y se apaga.\n",(({QueryObjectOwner()})));
	return 1;
}
else
{
tell_object(QueryObjectOwner(),"Gritas en alto la palabra oscuridad, pero nada pasa. "
	"quizá debas empuñar el cayado para hacer eso.\n");
	tell_room(environment(QueryObjectOwner()),capitalize(QueryObjectOwner()->QueryName())+" grita 'oscuridad'.\n "
	"Aparentemente nada pasa, y ves como mira a su alrededor consternado.\n",(({QueryObjectOwner()})));
return 1;
}
}
//[m]funcion para apagar el cayado al desempuñar
apagarenc_cmd()
{
TO->SetLight(0);
tell_object(QueryObjectOwner(),"Al desempuñar tu cayado ves como la luz oscila y se apaga al perder poder.\n");
	tell_room(environment(QueryObjectOwner()),"La luz en el extremo del cayado de "+capitalize(QueryObjectOwner()->QueryName())+" oscila y se apaga.\n",(({QueryObjectOwner()})));
return 1;
}

init()
{
   object ob;

   ::init();

   if( !TP ) return;
   ob = QueryObjectOwner();

   if( ob && ob == TP )
   {
      Equip(ob, EWF_WEAPON | EWF_SILENT );
     add_action("cmd_estado","estado");
     add_action("cmd_gayuda","gayuda");
	 add_action("luz_cmd","luz");
	 add_action("apagar_cmd","apagar");
	 add_action("churrupetear_cmd","concentrarse");
	 add_action("efectos","",1);
   }
   if(OWNER->Query(P_CONCENTRADO)!=0) call_out("awake",Query(P_CONCENTRADO));
   if(OWNER->Query(P_LANZANDO)!=0) call_out("wake",Query(P_LANZANDO));
   }


Debug(string texto)
{
#ifndef DEBUG
  return 0;
#else
//  LOG("DEBUG",STR->etime()+"> "+texto+"\n");
  LOG("DEBUG","> "+texto+"\n");
  return 1;
#endif
}
public int SaveMe()
{
   save_object( QuerySaveName( "" ) );
   return 1;
}

int cmd_salvar(string str)
{
   SaveMe();
   return 0;
}


remove()
{
   object ob;

   ob = QueryObjectOwner();
   if( ob ) SaveMe();
   return ::remove();
}

public varargs int UseSkill(string name, int chance, int percentage)
{
 int align;

 if (!name) return 0; // [w] Sin habilidad.. na de na.

// [w] Si el skill no es de conjurador hace el UseSkill normal.
// [m] si no es de hechicero mas de lo mismo.
 if (member(HAB_HECHICEROS,name)==-1)
 {
   percentage=OWNER->UseSkill(name,chance);
   if (percentage>0) return 1;
   else return 0;
 }
 if (!HasSkill(name)) return 0; // [w] Si el jugador no posee esa habilidad, sale.

 percentage=OWNER->UseSkill(name,chance);
 Debug("Skill: "+name+" Percentage: "+percentage+" Align: "+align+" Chance: "+chance);
 if (percentage>0) return 1;
 else return 0;
 return 0;
}

//[m]toco la funcion notifyunwield para q al desempuñar llame al apagar,
//caso de q este encendido, claro.
public varargs void NotifyUnequip(object liv, object weapon, int flags)
{
  if (weapon != TO) return;
  if (weapon->QueryLight()!=0) apagarenc_cmd();
  ::NotifyUnequip(liv, weapon, flags);
}

int cmd_estado()
{
 string msg;

 if (TP->QueryGhost()) return 0;
 msg="Eres "+TC_GREEN+capitalize(TP->QueryRealName())+TC_NORMAL+", ";
 msg+=QueryTituloHechicero()+" de nivel "+TP->QueryLevel()+".\n";
 write(msg);
 return 0;
}

int cmd_gayuda(string str)
{
string s;
if (!str)
   {
   s="\nUsa "+TC_BOLD+"gayuda <tema>"+TC_NORMAL
   +" para ver un tema en concreto.\nTemas disponibles:\n"
   +TC_GREEN+"historia"+TC_NORMAL+" ..... Historia de los hechiceros.\n"
   +TC_GREEN+"gremio"+TC_NORMAL+"........ Informacion genérica del gremio.\n"
   +TC_GREEN+"habilidades"+TC_NORMAL+"... Informacion sobre habilidades.\n"
   +TC_GREEN+"hechizos"+TC_NORMAL+" ..... Informacion sobre hechizos.\n";
    write(s);
    return 1;
    }

 s=H_HOME+"ayuda/"+str;
 if(file_size(s)<=0)
   return notify_fail("No existe información sobre ese tema.\n"),0;
 STR->smore(read_file(s));
 return 1;
}
//creacion del comando.. chupamela... weno, el concetrarse
mixed churrupetear_cmd(string str)
{
int chance,percent;
if(str!="poco" && str!="normal" && str!="mucho") return notify_fail("Uso: concentrarse poco, concentrarse normal o concentrarse mucho.\n");
 if (HasSkill(HAB_CONCENTRAR))
 {
  chance=-20+((OWNER->QueryInt()*5)+(OWNER->QueryCon()*1));
  if (chance > 20 ) chance=20;
  if (chance <-20) chance=-20;
 }
switch (str)
{
case "mucho":
if (UseSkill(HAB_CONCENTRAR,chance,&percent))
{

    if (percent>=90)
    {
	  OWNER->Set(P_CONCENTRADO,8);
	  call_out("awake",8);
	  OWNER->AddSP(16);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡¡Te concentras!!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡¡"+capitalize(OWNER->QueryName())+" se concentra!!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=65)
    {
      OWNER->Set(P_CONCENTRADO,16);
	  call_out("awake",16);
	  OWNER->AddSP(16);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡Te concentras!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡"+capitalize(OWNER->QueryName())+" se concentra!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=50)
    {
	  OWNER->Set(P_CONCENTRADO,20);
	  call_out("awake",20);
	  OWNER->AddSP(16);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡Te concentras!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡"+capitalize(OWNER->QueryName())+" se concentra!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=25)
    {
	  OWNER->Set(P_CONCENTRADO,30);
	  call_out("awake",30);
	  OWNER->AddSP(16);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_YELLOW+"Te concentras\n"TC_NORMAL);
      tell_room(environment(OWNER),"  "+capitalize(OWNER->QueryName())+" se concentra\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
	else
    {
	  OWNER->Set(P_CONCENTRADO,30);
	  call_out("awake",30);
	  OWNER->AddSP(8);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,"Te concentras\n");
      tell_room(environment(OWNER),"  "+capitalize(OWNER->QueryName())+" se concentra\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
}
else return notify_fail("Fallas al intentar concentrarte.\n");
break;
case "normal":
if (UseSkill(HAB_CONCENTRAR,chance,&percent))
{
   if (percent>=90)
    {
	  OWNER->Set(P_CONCENTRADO,4);
	  call_out("awake",4);
	  OWNER->AddSP(8);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡¡Te concentras!!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡¡"+capitalize(OWNER->QueryName())+" se concentra!!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=65)
    {
      OWNER->Set(P_CONCENTRADO,8);
	  call_out("awake",8);
	  OWNER->AddSP(8);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡Te concentras!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡"+capitalize(OWNER->QueryName())+" se concentra!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=50)
    {
      OWNER->Set(P_CONCENTRADO,10);
	  call_out("awake",10);
	  OWNER->AddSP(8);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡Te concentras!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡"+capitalize(OWNER->QueryName())+" se concentra!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=25)
    {
	  OWNER->Set(P_CONCENTRADO,15);
	  call_out("awake",15);
	  OWNER->AddSP(8);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_YELLOW+"Te concentras\n"TC_NORMAL);
      tell_room(environment(OWNER),"  "+capitalize(OWNER->QueryName())+" se concentra\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
	else
    {
	  OWNER->Set(P_CONCENTRADO,15);
	  call_out("awake",15);
	  OWNER->AddSP(4);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,"Te concentras\n");
      tell_room(environment(OWNER),"  "+capitalize(OWNER->QueryName())+" se concentra\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
}
else return notify_fail("Fallas al intentar concentrarte.\n");
break;
case "poco":
if (UseSkill(HAB_CONCENTRAR,chance,&percent))
{
   if (percent>=90)
    {
	  OWNER->Set(P_CONCENTRADO,2);
	  call_out("awake",2);
	  OWNER->AddSP(4);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡¡Te concentras!!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡¡"+capitalize(OWNER->QueryName())+" se concentra!!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=65)
    {
      OWNER->Set(P_CONCENTRADO,4);
	  call_out("awake",4);
	  OWNER->AddSP(4);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡Te concentras!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡"+capitalize(OWNER->QueryName())+" se concentra!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=50)
    {
      OWNER->Set(P_CONCENTRADO,5);
	  call_out("awake",5);
	  OWNER->AddSP(4);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_RED+"¡Te concentras!\n"TC_NORMAL);
      tell_room(environment(OWNER),"  ¡"+capitalize(OWNER->QueryName())+" se concentra!\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }
    else if (percent>=25)
    {
      OWNER->Set(P_CONCENTRADO,8);
	  call_out("awake",8);
	  OWNER->AddSP(4);
	  if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	  OWNER->SetSP(OWNER->QueryMaxSP());
      tell_object(OWNER,TC_YELLOW+"Te concentras\n"TC_NORMAL);
      tell_room(environment(OWNER),"  "+capitalize(OWNER->QueryName())+" se concentra\n",(({OWNER})));
      Debug("Ataque Especial: concentracion:"+percent);
    }

	else
	{
	OWNER->Set(P_CONCENTRADO,8);
	call_out("awake",8);
	OWNER->AddSP(2);
	if(OWNER->QuerySP() >= OWNER->QueryMaxSP())
	OWNER->SetSP(OWNER->QueryMaxSP());
	tell_object(OWNER,"Te concentras\n");
	tell_room(environment(OWNER),"  "+capitalize(OWNER->QueryName())+" se concentra\n",(({OWNER})));
	Debug("Ataque Especial: concentracion:"+percent);
	}
}
else return notify_fail("Fallas al intentar concentrarte.\n");
 break;
 }
return "No tienes esa habilidad.\n";
}
int awake()
{
OWNER->Set(P_CONCENTRADO,0);
write("Dejas de concentrarte.\n");
say(capitalize(OWNER->QueryName())+" deja de concentrarse.\n",OWNER);
return 1;
}
int wake(string str)
{
OWNER->Set(P_LANZANDO,0);
write("Terminas de lanzar el hechizo.\n");
say(capitalize(OWNER->QueryName())+" termina de lanzar el hechizo.\n",OWNER);
    seteuid(getuid());
    return MAGICD->main(OWNER,str);
}
int efectos()
{
string suf;
if((OWNER->QueryGender())==2) suf="a";
else suf="o";
if(OWNER->Query(P_CONCENTRADO)!=0)
{
write("Estás concentrad"+suf+".\n");
say(capitalize(OWNER->QueryName())+" está concentrad"+suf+".\n",OWNER);
return 1;
}
if(OWNER->Query(P_LANZANDO)!=0)
{
write("Estás preparando un hechizo.\n");
say(capitalize(OWNER->QueryName())+" está preparando un hechizo.\n",OWNER);
return 1;
}
else
return 0;
}
magia(string str)
{
mapping spells;
string st;
string verb, rest;


   if (!str) return MAGICD->md_usage();

   if (sscanf(str, "%s %s", verb, rest) != 2) verb=str;
   if (!rest) rest="";

   seteuid(getuid());

   /* Comprobamos el estado de la base de datos */
   MAGICD->md_check_db();

   switch (verb) {
      case MAGICD_INFOVERB : MAGICD->md_info(rest);return 1; break;
      case "bug": MAGICD->md_report("BUG",rest);return 1; break;
      case "idea": MAGICD->md_report("IDEA",rest); break;
      case "generarbd" : if (IS_WIZARD(TP))
                           { return MAGICD->md_build_spell_db(); break; }
      case "bd"  : if (IS_WIZARD(  TP))
                           { printf("haz xcall $me->RemovePath('/guilds/hechiceros/bin') y prueba de nuevo.\n");
                               return 1; break; }
   }






if (sscanf(str,"'%s'",st)==1||sscanf(str,"'%s'%s",st)==2);
{
tell_object(find_object("maler"),sprintf("str y st son:%O:%O\n",str,st));
tell_object(OWNER,"Comienzas a preparar el hechizo.\n");
spells=OWNER->QuerySpells();
if(!spells) spells=([]);
if(!spells[st]) return notify_fail("No tienes ese hechizo.\n");
else
{
switch(spells[st])
{
case 0..40:OWNER->Set(P_LANZANDO,3);call_out("wake",3,str);break;
case 41..60:OWNER->Set(P_LANZANDO,2);call_out("wake",2,str);break;
case 61..98:OWNER->Set(P_LANZANDO,1);call_out("wake",1,str);break;
case 99..100:wake(str);break;
default:OWNER->Set(P_LANZANDO,3);call_out("wake",3,str);break;
}
}
}
}
void catch_tell(string str)
{
tell_object(OWNER,sprintf("El cayao te dice: %O.\n",str));
return;
}
