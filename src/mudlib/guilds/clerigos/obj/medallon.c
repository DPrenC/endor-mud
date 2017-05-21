/**
 * SIMAURIA '/guilds/clerigos/obj/medallon.c'
 */

 // Vilmente copiado de la capa de los conjuradores

#define GEN(x,y) ((TP->QueryGender()==2?x:y))

#include <properties.h>
#include <guild.h>
#include <skills.h>
#include <colours.h>
#include <combat.h>
#include <moving.h>
#include "./path.h"

inherit "/std/thing";
inherit "/std/equipment";
inherit G_GUILDOBJ;

//#define DEBUG 1 //[w] Descomentar solo en modo prueba.
#define MATERIALES_ILEGALES   ({M_ALUMINIO_TXT,M_PLOMO_TXT,M_ACERO_TXT,M_HIERRO_TXT,M_COBRE_TXT,M_BRONCE_TXT,\
                                M_PLATA_TXT,M_ORO_TXT,M_PLATINO_TXT,M_TITANIO_TXT,M_MITHRIL_TXT,M_ADAMANTIO_TXT})

/*
 ======================
   [w] VARIABLES
 ======================
*/
static object clerigo;
static string nombre_clerigo;

/*
 ========================================
   [w] FUNCIONES SET, QUERY, ADD y HAS
 ========================================
*/

varargs string QuerySaveName(string appendix)
{
 string s;

 if(!appendix) appendix="";
 if(nombre_clerigo) s=lower_case(nombre_clerigo);
 else s="nadie";
 s=s+appendix;
 s=CLERIGO_SAVE(s);
 return s;
}

object QueryObjectOwner() { return clerigo; }
int SetObjectOwner(object jug)
{
 if (!jug || !jug->QueryIsPlayer()) return 0;
 clerigo=jug;
 nombre_clerigo=jug->QueryRealName();
 return 1;
}

int HasSkill(string habilidad)
{
 return QueryObjectOwner()->HasSkill(habilidad);
}

string QueryLong()
{
string s;
s=  "Es una capa blanca.. una simple capa blanca..\n";

if (TP==QueryObjectOwner())
   s+="Puedes usar el comando 'gayuda' para obtener más información del gremio.\n";
 return W(s);
}

string QueryConjuradorTitle()
{
 string str;

 str=(TP->QueryGender()==2?"la clerigoa":"el clerigo");
 switch(TP->QueryGuildLevel())
 {
  case   0..3: return GEN("la clerigoa novata","el clerigo novato");
  case   4..5: return GEN("la aprendiz de clerigoa","el aprendiz de clerigo");
  case   6..7: return GEN("la pequeña clerigoa","el pequeño clerigo");
  case   8..9: return GEN("la clerigoa","el clerigo");
  case 10..11: return GEN("la clerigoa experimentada","el clerigo experimentado");
  case 12..14: return GEN("la conocida clerigoa","el conocido clerigo");
  case 15..17: return GEN("la famosa clerigoa","el famoso clerigo");
  case 18..20: return GEN("la gran clerigoa","el gran clerigo");
  case 21..23: return GEN("la poderosa clerigoa","el poderoso clerigo");
  case 24..28: return GEN("la temible clerigoa","el temible clerigo");
  case 29..33: return GEN("la temible clerigoa oscura","el temible clerigo oscuro");
  case 34..37: return GEN("la invocadora de la oscuridad","el invocador de la oscuridad");
  case 38..43: return GEN("la clerigoa del abismo negro","el clerigo del abismo negro");
  case 44..49: return GEN("la invencible clerigoa","el invencible clerigo");
  case     50: return GEN("la semidiosa","el semidios");
  default: return str;
 }
 return str;
}


/*
 ======================
   [w] CREATE()
   [a]
 ======================
*/
create()
{
  int i;
  object *armas;

  ::create();
 seteuid(getuid(TO));

  SetMaterial(M_TELA);
  SetSize(P_SIZE_GENERIC);

  SetUsage(EQM_WEAR);
  SetShort("un medallón");

  SetGuild("/guilds/clerigos/gremio");

  if (TP)
    {
    SetObjectOwner(TP);
    if (TP->QueryGuild()!=GC_CONJURADORES) call_out("remove",1);
    }

  SetIds(({"medallon","medallon de clerigo"}));
  SetWeight(0);
  SetValue(0);
  Set(P_NOSELL,"Sería una ofensa para el gremio si la vendieses.\n");
  Set(P_NOBUY);
  Set(P_NOGIVE);
  Set(P_NODROP);

  restore_object(QuerySaveName(""));
  if (clonep(TO)) // Comprobación para que no pueda ver dos veces las noticias.
   if (file_size(GCLERIGOS+"NOTICIAS")>0) cat(GCLERIGOS+"NOTICIAS");
}


/*
 ======================
   [w] INIT()
 ======================
*/
init()
{
 object ob;
 ::init();

 if (!TP) return;
 ob=QueryObjectOwner();

 if (ob && ob==TP)
 {
  Equip(ob, EWF_WEAPON | EWF_SILENT );
  add_action("cmd_estado","estado");
  add_action("cmd_gayuda","gayuda");
  add_action("cmd_conjuros","conjuros");
  add_false_cmds();
 }
}

/*
 ======================
   [w] OTRAS FUNCIONES
 ======================
*/
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
 save_object(QuerySaveName(""));
 return 1;
}

remove()
{
 object ob;

 ob=QueryObjectOwner();
 if(ob)
 {
  SaveMe();
  Unequip();
 }
 return ::remove();
}

/*
 =============================
   [w] FUNCIONES PRINCIPALES
 =============================
*/
public mixed ChkEquip(object pl, object armour, int flags)
{
    mixed material;

    if ( !(flags&EWF_WEAPON) )return EQ_OK;
    if (!armour || (pl != QueryObjectOwner()))
	    return "Me parece que no vas a poder ponerte eso tan facilmente.\n";

    // [w] Pueden llevar anillos y amuletos de metal.
    if (armour->QueryArmourType()==AT_AMULETO || armour->QueryArmourType()==AT_ANILLO)
      return EQ_OK;

    // [w] Pueden ponerse la coraza de acero mágica del conjuro 'coraza ligera'.
    if (armour->QueryCorazaLigera()) return EQ_OK;

    material=(mixed) armour->QueryMaterial()||M_DESCONOCIDO_TXT;
    if (member(MATERIALES_ILEGALES,material)!=-1)
      return "Tu condición de clerigo te impide llevar protecciones de metal.\n";

   return ::ChkEquip(pl, armour, flags);
}

/*
 ======================
   [w] HABILIDADES
 ======================
*/
public varargs int UseSkill(string name, int chance, int percentage)
{
 int align;

 if (!name) return 0; // [w] Sin habilidad.. na de na.

// [w] Si el skill no es de clerigo hace el UseSkill normal.
 if (member(HAB_CONJURADORES,name)==-1)
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

/*
 ======================
   [w] COMANDOS 'CMD'
 ======================
*/
//[a]
int cmd_estado()
{
 string msg;

 if (TP->QueryGhost()) return 0;
 msg="Eres "+TC_GREEN+capitalize(TP->QueryRealName())+TC_NORMAL+", ";
 msg+=QueryConjuradorTitle()+".\n";//+" de nivel "+TP->QueryLevel()+".\n";
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
   +TC_GREEN+"historia"+TC_NORMAL+" ..... Historia de los clerigoes.\n"
   +TC_GREEN+"gremio"+TC_NORMAL+"........ Informacion genérica del gremio.\n"
   +TC_GREEN+"comandos"+TC_NORMAL+"...... Nuevos comandos de gremio.\n"
   +TC_GREEN+"magia"+TC_NORMAL+"......... Informacion sobre la magia.\n"
   +TC_GREEN+"habilidades"+TC_NORMAL+"... Informacion sobre habilidades.\n"
   +TC_GREEN+"conjuros"+TC_NORMAL+" ..... Informacion sobre conjuros.\n";
    write(s);
    return 1;
    }

 str=STR->string_replace(str," ",""); //Nos aseguramos que no ponen algo raro
 s=GCLERIGOS+"ayuda/"+str;
 if(file_size(s)<=0)
   return notify_fail("No existe información sobre ese tema.\n"),0;
 STR->smore(read_file(s));
 return 1;
}

int cmd_salvar(string str)
{
 SaveMe();
 return 0;
}

string nivel(int n)
{
  if (!n) return "desconocido";
  switch (n) {
    case 0..4:   return "desastroso";
    case 5..9:   return "fatal";
    case 10..14: return "pésimo";
    case 15..19: return "muy mal";
    case 20..24: return "bastante mal";
    case 25..29: return "mal";
    case 30..39: return "regular";
    case 40..49: return "aceptable";
    case 50..54: return "adecuado";
    case 55..64: return "bueno";
    case 65..69: return "muy bueno";
    case 70..79: return "excelente";
    case 80..89: return "óptimo";
    case 90..98: return "casi perfecto";
    case 99..100: return "perfecto";
    default: return "desconocido";
  }
  return "desconocido";
}

string nivel_max(int n)
{
 if (!n) return "[Aprendiz]";
 if (n<=50) return "[Aprendiz]";
 if (n<=70) return "[Mago]";
 if (n>70) return "[Archimago]";
}

int cmd_conjuros(string w)
{
  mapping sp;
  mixed *idx;
  string p;
  int i;

  p="";

  sp=TP->QuerySpells();
  if (!sp || !sizeof(sp)) return notify_fail("No conoces ningún conjuro.\n");

  idx=m_indices(sp);
  for (i=0; i<sizeof(idx); i++)
    p+="  "+STR->ladjust(idx[i]+" ",25,".")+" "TC_GREEN+STR->ladjust(""+nivel(sp[idx[i],0])+TC_NORMAL" ",18,".")
        +" "+nivel_max(sp[idx[i],1])+"\n";

  seteuid(getuid(TP));
  if (p!="")
  {
    write(TC_BOLD"Conjuros que tienes memorizados:\n"TC_NORMAL);
    STR->smore(p,TP->QueryPageSize());
  }
  return 1;
}
