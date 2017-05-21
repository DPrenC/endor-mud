// combatmaster.c
// Creado por Nyh para Simauria en Abril de 2003
//
// Este es el objeto que se encarga de resolver los ataques en los combates.
// Es invocado desde cada living cada vez que este asesta un golpe
//
// Creado como preludio y plataforma de pruebas para el sistema de combate de
// Simauria 2.
//
// Algo de código en su origen era parte del sistema de combate de Nightfall,
//  pero actualmente dudo que quede algo reconocible de todo ello...

#include <config.h>
#include <properties.h>
#include <living.h>
#include <combat.h>
#include <wizlevels.h>
#include <attributes.h>
#include <colours.h>
#include <colours.h>
#include <messages.h>
#include <skills.h>
#include <perception.h>

//#define NYH_DEBUG_PUPA
#define DEBUG_AGGRESSIVE
//#define DEBUG_NOPEGO
//#define DEBUG_ELE

#define ESTADISTICAS

// -----------------------------------------------------------------------------
// Ataque
// -----------------------------------------------------------------------------
// minimo: 1+stat/10
// maximo: stat/10+wc
public int CalcBaseDamage(int wc, int stat) {
  return 1+(stat/10+random(wc))*3/2;
}
public int CalcHandDamage(object atk, int hand) {
  return CalcBaseDamage(atk->QueryHands()[hand][HAND_WC],atk->QueryStr());
}
//  { return 1 + random(2*(atk->QueryHands()[hand][HAND_WC]) + (atk->QueryDex()+atk->QueryStr())/4); }
//armas: damage = 1+random((2*QueryWC()+stat/2)*(1+(hands>1?hands:1))/2);

public varargs int CalcDamage(object atk, mixed weapon, object def, int chance) {
  int dam = 0;

  if (objectp(weapon))
  { // Si atacamos con un arma, x es un objeto (el arma)
    if (function_exists("QueryDamage", weapon))
    { // es un arma de verdad
        dam = weapon->QueryDamage(def);
    }
    else { //es un arma improvisada...
        switch (weapon->QueryWeight())
        {
            case      1 ..    999: dam = d3();  break;
            case   1000 ..   2999: dam = d4();  break;
            case   3000 ..   5999: dam = d6();  break;
            case   6000 ..  11999: dam = d8();  break;
            case  12000 ..  24999: dam = d6(2); break;
            case  25000 ..  49999: dam = d6(3); break;
            case  50000 ..  99999: dam = d6(4); break;
            case 100000 .. 199999: dam = d6(5); break;
            case 200000 .. __INT_MAX__: dam = d6(6); break;
            default: dam = 0;
        }
    }
    dam += (dam*(atk->UseSkill(HAB_MASDANYO)>0)?BONUS_MASDANYO:0) /100;
  }
  else
  { // En cambio, si atacamos con una mano x = nº de "mano" (int)
    dam = CalcHandDamage(atk, weapon);
    dam += (dam*(atk->UseSkill(HAB_ZEN)>0)?BONUS_ZEN : 0) /100;
  }
  dam += (dam*(atk->UseSkill(HAB_CRITICO)>0)?BONUS_CRITICO : 0) /100;
  dam += dam*chance/100;

  return dam;
}

public varargs int CalcDamageType(object atk, mixed weapon, object def, int chance) {
  int dam_type;

  if (objectp(weapon)) {// Si atacamos con un arma, x es un objeto (el arma)
    dam_type = weapon->QueryDamageType();
  }
  else {// En cambio, si atacamos con una mano x = nº de "mano" (int)
    dam_type = atk->QueryHands()[weapon][HAND_WEAPON] || TD_APLASTAMIENTO;
  }
  return dam_type;
}

// -----------------------------------------------------------------------------
// Fin Ataque
// -----------------------------------------------------------------------------
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// -----------------------------------------------------------------------------
// Defensa
// -----------------------------------------------------------------------------

//Devuelve mayor de cero si acierta y menor o igual a cero si falla
public varargs int CalcIsHit(object atk, object def, mixed weapon, int bonus) {
  int atk_bonus = 0, def_bonus = 0, res = 0;

  if (!atk || !def) return 0;

  atk_bonus = atk->CalcAtkHitBonus(def, weapon);
  def_bonus = def->CalcDefHitBonus(atk, weapon);

  res = BASE_CHANCE + bonus + atk_bonus - def_bonus - d100Check();

  if (find_object("nyh") && find_object("nyh")->Query("DebugCombat"))
    dtell("nyh",sprintf("BASE_CHANCE = %O\tbonus = %O\t[%O]%O->atk_bonus = %O\t[%O]%O->def_bonus = %O\tchance = %O\ttirada = %O\tresultado = %O\n"
         , BASE_CHANCE, bonus, atk->QueryGuildLevel(), atk->QueryName(), atk_bonus, def->QueryGuildLevel(), def->QueryName(), def_bonus, BASE_CHANCE + bonus + atk_bonus - def_bonus, BASE_CHANCE + bonus + atk_bonus - def_bonus - res, res));

  // Esta linea hace que si el atacante no ve al defensor falle el 50% del tiempo
  if (res>0 && !(atk->CanSeeObject(def)) && d2()==1) {
    //dtell("nyh",sprintf("%O Falla por concealment.\n",atk->QueryName()));
    return 0;
  }

  return res;
}

// -----------------------------------------------------------------------------
// Fin Defensa
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Manejo de mensajes
// -----------------------------------------------------------------------------
/*
#define DT_SLASH     TD_CORTE
#define DT_BLUDGEON  TD_APLASTAMIENTO
#define DT_PIERCE    TD_PENETRACION
#define DT_FIRE      TD_CALOR
#define DT_COLD      TD_FRIO
#define DT_ELECTRO   TD_ELECTRICIDAD
*/
//Nyh pasar que, y elque por referencia
public int GetDamageMessage(int dam, string what, string how)
{
    switch (dam) {
      case ATK_CURO:      what =    TC_WHITE   "sana"      ;  how  = "";                 break;
      case ATK_RESISTO:   what =    TC_WHITE   "resiste"   ;  how  = " por completo";    break;
      case ATK_BLOQUEADO: what =    TC_WHITE   "bloquea"   ;  how  = " con el escudo";   break;
      case ATK_ESQUIVADO: what =    TC_WHITE   "esquiva"   ;  how  = " hábilmente";      break;
      case ATK_PARADO:    what =    TC_WHITE   "para"      ;  how  = " con el arma";     break;
      case ATK_TAICHI:    what =    TC_WHITE   "desvía"    ;  how  = " con las manos";   break;
      case __INT_MIN__ .. ATK_LOWER_RES-1:
      case ATK_FALLO:     what = "\b\b\b"TC_WHITE"falla"   ;  how  = " miserablemente";  break;
//    case      0:   what =         TC_WHITE   "falla"     ;  how = " miserablemente";   break;
      case   1..2:   what = TC_BOLD TC_BLACK   "acaricia"  ;  how = " suavemente";       break;
      case   3..4:   what = TC_BOLD TC_BLACK   "roza"      ;  how = " suavemente";       break;
      case   5..6:   what = TC_BOLD TC_BLACK   "rasca"     ;  how = " suavemente";       break;
      case   7..8:   what =         TC_CYAN    "raspa"     ;  how = " ligeramente";      break;
      case   9..10:  what =         TC_CYAN    "araña"     ;  how = " ligeramente";      break;
      case  11..12:  what =         TC_CYAN    "lastima"   ;  how = " ligeramente";      break;
      case  13..14:  what = TC_BOLD TC_CYAN    "alcanza"   ;  how = " superficialmente"; break;
      case  15..16:  what = TC_BOLD TC_CYAN    "hiere"     ;  how = " superficialmente"; break;
      case  17..18:  what =         TC_YELLOW  "muele"     ;  how = " superficialmente"; break;
      case  19..20:  what =         TC_YELLOW  "diezma"    ;  how = " profundamente";    break;
      case  21..23:  what =         TC_YELLOW  "devasta"   ;  how = " profundamente";    break;
      case  24..26:  what = TC_BOLD TC_YELLOW  "cruje"     ;  how = " profundamente";    break;
      case  27..29:  what = TC_BOLD TC_YELLOW  "destroza"  ;  how = " salvajemente";     break;
      case  30..32:  what =         TC_GREEN   "desfigura" ;  how = " salvajemente";     break;
      case  33..35:  what =         TC_GREEN   "deforma"   ;  how = " salvajemente";     break;
      case  36..38:  what =         TC_GREEN   "masacra"   ;  how = " brutalmente";      break;
      case  39..41:  what = TC_BOLD TC_GREEN   "incapacita";  how = " brutalmente";      break;
      case  42..44:  what = TC_BOLD TC_GREEN   "lisia"     ;  how = " brutalmente";      break;
      case  45..47:  what =         TC_BLUE    "mutila"    ;  how = " cruelmente";       break;
      case  48..50:  what =         TC_BLUE    "extirpa"   ;  how = " cruelmente";       break;
      case  51..55:  what =         TC_BLUE    "amputa"    ;  how = " cruelmente";       break;
      case  56..60:  what = TC_BOLD TC_BLUE    "demuele"   ;  how = " sádicamente";      break;
      case  61..65:  what = TC_BOLD TC_BLUE    "aniquila"  ;  how = " sádicamente";      break;
      case  66..70:  what =         TC_RED     "destruye"  ;  how = " sádicamente";      break;
      case  71..75:  what =         TC_RED     "licua"     ;  how = " vilmente";         break;
      case  76..80:  what =         TC_RED     "vaporiza"  ;  how = " vilmente";         break;
      case  81..85:  what = TC_BOLD TC_RED     "atomiza"   ;  how = " vilmente";         break;
      case  86..90:  what = TC_BOLD TC_RED     "disipa"    ;  how = " el alma";          break;
      case  91..95:  what =         TC_PURPLE  "desintegra";  how = " el alma";          break;
      case  96..99:  what =         TC_PURPLE  "erradica"  ;  how = " el alma";          break;
      default:       what = TC_BOLD TC_PURPLE  "expulsa"   ;  how = " de este mundo";    break;
       // fulmina empala machaca
  }
  return 1;
}

private string _get_short(object who, object whom)
{
    if (objectp(who) && objectp(whom))
    {
        switch (who->CanSeeObject(whom))
        {
            case CAN_SEE_OBJECT_INWIZ : // Esta inwizible, pero le veo
                return TC_ITALIC + "<(" + ( whom->QueryName()||whom->QueryShort() )
                                 + ")>" + TC_ITALIC_OFF;
            case CAN_SEE_OBJECT_INVIS : // esta invisible, pero le veo
                return TC_ITALIC + "(" + ( whom->QueryName()||whom->QueryShort() )
                                 + ")" + TC_ITALIC_OFF;
            case CAN_SEE_OBJECT_NORMAL : // esta visible, y le veo
                return whom->QueryName() || whom->QueryShort();
        }
    }
    return "alguien";
}

public varargs void DoMeleeMessage(object atk, object def, string verb, string with, int dam, string what, string how) {
//  COMBAT_VERB+s a COMBAT_DEF [con COMBAT_WITH] < y le|, pero lo> COMBAT_WHAT [COMBAT_HOW]
//  COMBAT_ATK te COMBAT_VERB [con COMBAT_WITH] < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]
//  COMBAT_ATK COMBAT_VERB a COMBAT_DEF [con COMBAT_WITH] < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]

  if (!what) GetDamageMessage(dam, &what, &how);

// Mensaje para el atacante
    if (atk->QueryCombateBreve()) {
      tell_object(atk, TC_COMBAT_ATACO
          + capitalize( verb + "s a " + _get_short(atk, def)
          + (dam > 0 ? " y le " : ", pero lo ") + what + (dam >= 0 ? "s" : "") + TC_NORMAL + "\n" ));
    }
    else {
      tell_object(atk, TC_COMBAT_ATACO
          + capitalize( verb + "s a " + _get_short(atk, def)
          + (sizeof(with)?" con "+with:"")
          + (dam > 0 ? " y le " : ", pero lo ") + what + (dam >= 0 ? "s" : "") + how + TC_NORMAL + "\n" ));
    }

// Mensaje para el defensor
    if (def->QueryCombateBreve()) {
      tell_object(def, TC_COMBAT_DEFIENDO
          + capitalize( _get_short(def, atk) + " te " + verb
          + (dam > 0 ? " y te " : ", pero lo ") + what + TC_NORMAL + "\n" ));
    }
    else {
      tell_object(def, TC_COMBAT_DEFIENDO
          + capitalize(  _get_short(def, atk) + " te " + verb
          + (sizeof(with)?" con "+with:"")
          + (dam > 0 ? " y te " : ", pero lo ") + what + how + TC_NORMAL + "\n" ));
    }

}

public void DoThrowMessage(object atk, object def, string verb, string with, int dam, string what, string how) {
//  COMBAT_VERB+s COMBAT_WITH contra COMBAT_DEF < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]
//  COMBAT_ATK te COMBAT_VERB COMBAT_WITH < y le|, pero lo> COMBAT_WHAT [COMBAT_HOW]
//  COMBAT_ATK COMBAT_VERB COMBAT_WITH contra COMBAT_DEF < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]

  if (!what) GetDamageMessage(dam, &what, &how);

// Mensaje para el atacante
    if (atk->QueryCombateBreve()) {
      tell_object(atk, TC_COMBAT_ATACO
          + capitalize( verb + "s " + with + " contra " + _get_short(atk, def)
          + (dam > 0 ? " y le " : ", pero lo ") + what + "s" + TC_NORMAL + "\n" ));
    }
    else {
      tell_object(atk, TC_COMBAT_ATACO
          + capitalize( verb + "s " + with + " contra " + _get_short(atk, def)
          + (dam > 0 ? " y le " : ", pero lo ") + what + "s" + how + TC_NORMAL + "\n" ));
    }

// Mensaje para el defensor
    if (def->QueryCombateBreve()) {
      tell_object(def, TC_COMBAT_DEFIENDO
          + capitalize( _get_short(def, atk) + " te " + verb + " " + with
          + (dam > 0 ? " y te " : ", pero lo ") + what + TC_NORMAL + "\n" ));
    }
    else {
      tell_object(def, TC_COMBAT_DEFIENDO
          + capitalize(  _get_short(def, atk) + " te " + verb + " " + with
          + (dam > 0 ? " y te " : ", pero lo ") + what + how + TC_NORMAL + "\n" ));
    }

}

public void DoSpellMessage(object atk, object def, string verb, string with, int dam, string what, string how) {
//  COMBAT_VERB+s COMBAT_WITH contra COMBAT_DEF < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]
//  COMBAT_ATK COMBAT_VERB COMBAT_WITH contra ti < y le|, pero lo> COMBAT_WHAT [COMBAT_HOW]
//  COMBAT_ATK COMBAT_VERB COMBAT_WITH contra COMBAT_DEF < y te|, pero lo> COMBAT_WHAT [COMBAT_HOW]

  if (!what) GetDamageMessage(dam, &what, &how);

// Mensaje para el atacante
    if (atk->QueryCombateBreve()) {
      tell_object(atk, TC_COMBAT_ATACO
          + capitalize( verb + "s " + with + " contra " + _get_short(atk, def)
          + (dam > 0 ? " y le " : ", pero lo ") + what + "s" + TC_NORMAL + "\n" ));
    }
    else {
      tell_object(atk, TC_COMBAT_ATACO
          + capitalize( verb + "s " + with + " contra " + _get_short(atk, def)
          + (dam > 0 ? " y le " : ", pero lo ") + what + "s" + how + TC_NORMAL + "\n" ));
    }

// Mensaje para el defensor
    if (def->QueryCombateBreve()) {
      tell_object(def, TC_COMBAT_DEFIENDO
          + capitalize( _get_short(def, atk) + " " + verb + " " + with + " contra ti"
          + (dam > 0 ? " y te " : ", pero lo ") + what + TC_NORMAL + "\n" ));
    }
    else {
      tell_object(def, TC_COMBAT_DEFIENDO
          + capitalize( _get_short(def, atk) + " " + verb + " " + with + " contra ti"
          + (dam > 0 ? " y te " : ", pero lo ") + what + how + TC_NORMAL + "\n" ));
    }

}

//dam>=0 daño
//dam<0 tipo de fallo (essquiva, etc...
/* weapon puede ser:
int: atacante living y esto indica numero de mano
object: el arma con el que atacan
({int dam_type, string arma}): el tipo de daño y el nombre de con que atacas
el special es para ataques tipo apuñalar...
*/
public varargs void DoCombatMessage(object atk, object def, mixed weapon, int dam, int special)
{
  string arma;
  string verb, with, what, how;
  int dam_type, sneak, type;

  if (!atk || !def) return;

  if (pointerp(weapon))
  {
    dam_type = weapon[0];
    arma = weapon[1];
  }
  else if (objectp(weapon))
  {
    dam_type = weapon->QueryDamageType() || TD_APLASTAMIENTO;
    arma = weapon->QueryShort();
  }
/*  else if (objectp(atk->QueryHands()[weapon][HAND_WEAPON])) {
    dam_type = weapon->QueryDamageType() || TD_APLASTAMIENTO;
    arma = weapon->QueryShort();*/
  else if (weapon < 100){ //este if chorra es porque a woo le molaba poner de arma 1000...
      // En cambio, si atacamos con una mano weapon = nº de "mano" (int)
      // el explode borra la palabra derecha.
//  if (find_object("nyh")) dtell("nyh",sprintf("atk = %O\tHands = %O\tweapon = %O",atk,atk->QueryHands(),weapon));
    dam_type = atk->QueryHands()[weapon][HAND_WEAPON] || TD_APLASTAMIENTO;
    arma = explode(atk->QueryHands()[weapon][HAND_SHORT]," derecha")[0];
    switch (arma) { // parche chungo
        case "mano":  arma = "las manos";  break;
        case "garra": arma = "las garras"; break;
        case "cola":  arma = "la cola";    break;
        case "pata":  arma = "la pata";    break;
    }
  }

  if (sneak = special & COMBATMESSAGE_SNEAK) special &= ~COMBATMESSAGE_SNEAK;

  switch (special)
  {
    case COMBATMESSAGE_SPELL: // Este ahora no rula
        type = COMBAT_TYPE_SPELL;
        verb = "conjura";
        with = "'"+arma+"'";
      break;
    case COMBATMESSAGE_THROW: // Este ahora no rula
        type = COMBAT_TYPE_THROW;
        verb = "lanza";
        with = arma;
      break;
    default:
        type = COMBAT_TYPE_MELEE;
        switch (dam_type)
        {
            case TD_CORTE:         verb = "saja";       break;
            case TD_APLASTAMIENTO: verb = "aplasta";      break;
            case TD_PENETRACION:   verb = "alancea";      break;
            case TD_CALOR:         verb = "abrasa";       break;
            case TD_FRIO:          verb = "hiela";     break;
            case TD_ELECTRICIDAD:  verb = "electrocuta"; break;
            case TD_ACIDO:         verb = "corroe";    break; // Q pongo aqui?
            case TD_SONICO:        verb = "ensordece";   break; // Pues anda q aqui
            default:               verb = "ataca";
        }  //switch dam_type
        with = arma;
  } //switch special
  if (sneak) verb += " de forma fulminante";

  GetDamageMessage(dam, &what, &how);

  if (dam <= ATK_FALLO) type = -type;

// Envio mensajes a los implicados
    switch (type) {
        case  COMBAT_TYPE_MELEE:
        case -COMBAT_TYPE_MELEE:
            DoMeleeMessage(atk, def, verb, with, dam, what, how);
            break;
        case  COMBAT_TYPE_THROW:
        case -COMBAT_TYPE_THROW:
            DoThrowMessage(atk, def, verb, with, dam, what, how);
            break;
        case  COMBAT_TYPE_SPELL:
        case -COMBAT_TYPE_SPELL:
            DoSpellMessage(atk, def, verb, with, dam, what, how);
            break;
    }

// Envio mensajes al resto del mundo
    tell_room( environment(atk), ({ MSG_COMBAT, type, atk, def, verb, with, dam, what, how }), ({ atk, def }) );
    if (environment(atk) != environment(def)) {
        tell_room( environment(def), ({ MSG_COMBAT, type, atk, def, verb, with, dam, what, how }), ({ atk, def }) );
    }

}

// -----------------------------------------------------------------------------
// Fin Manejo de mensajes
// -----------------------------------------------------------------------------

//atk da un golpe de gracia a def con weapon,
//devuelve 1 si lo mata y 0 si no...
public int GolpeDeGracia(object atk, object def, mixed weapon) {
  string *verb = allocate(3);

  if (!atk || !def || !def->QueryDisabled()) return 0;

  verb[0] = TC_COMBAT_ATACO    + capitalize("Das el golpe de gracia a "+def->QueryName()+""TC_NORMAL);
  verb[1] = TC_COMBAT_DEFIENDO + capitalize(atk->QueryName()+" te da el golpe de gracia"TC_NORMAL);
  verb[2] = TC_COMBAT_OTRO     + capitalize(atk->QueryName()+" da el golpe de gracia a "+def->QueryName()+""TC_NORMAL);

  tell_object( atk, ({ MSG_SEE, verb[0] }) );
  tell_object( def, ({ MSG_SEE, verb[1] }) );
  tell_room( environment(atk), ({ MSG_SEE, verb[2] }), ({ def, atk }) );

  def->SetHP(-1);
  def->Die();
  return 1;
}

private int Consciente(object ob)
{
    return !(ob->QueryCombatDelay() || ob->QueryDisabled());
}
private int Molesto(object ob, int l)
{
    return Consciente(ob)&&((l-ob->QueryLevel())<10);
}

public varargs object Attack(object atk, object def, mixed weapon, int bonus_hit, int bonus_dam, int flags) {
  int dam, orgdam, res, dam_type, deflags;
  object here;
  mixed *xtras;

#ifdef DEBUG_NOPEGO
  if (find_object("nyh")) dtell("nyh",sprintf("\tCM->Attack(%O, %O, %i, %i, %i)\n",weapon,def,bonus_hit,bonus_dam,flags));
#endif

  if (!def || !atk) return 0; //como he quitado el disabled pasa...
  here = environment(atk);
  xtras = ({ });

#ifdef DEBUG_ELE
  if (intp(weapon) && objectp(atk->QueryHands()[weapon][HAND_WEAPON]) && find_object("nyh") )
    dtell("nyh",sprintf("[%O] %O->Attack(%O, %O, %O, %O, %O)\ncaller_stack = %O\n",TP,atk,weapon, def, bonus_hit, bonus_dam, flags,caller_stack()));
#endif


  //como de momento no hay ataque a distancia chekeo a lo burro, q me han dixo q peta...
//  if (!present(def,atk)) return 0;

//  if (find_object("nyh")) dtell("nyh",sprintf("%O->CM->Attack(%O,%O,%i,%i,%i)\n",atk,weapon,def,bonus_hit,bonus_dam,flags));

  if (def->QueryDisabled()) return intp(GolpeDeGracia(atk, def, weapon))?def:0;

  if (def->QueryStatusHelpless())     { bonus_dam+=100; }
  else if (def->QueryStatusTripped()) { bonus_dam+=50;  }

  if (flags==ATTACK_THROW) bonus_hit-= MALUS_THROW-atk->UseSkill(HAB_LANZAR, -weapon->QueryWeight()/100);

  res = CalcIsHit(atk, def, weapon, bonus_hit);

  if (res<1) orgdam = dam = 0;   //si no pega
  else { // si si que pega
    orgdam = dam = CalcDamage(atk, weapon, def, res+bonus_dam);
    dam_type = CalcDamageType(atk, weapon, def, res);

#ifdef ESTADISTICAS
    atk->AddAcierto();
    atk->AddDanyo(dam);
#endif
    if (objectp(weapon)) weapon->DegradeWeapon((["TOTAL":1+random(dam/4)]), ([]), 100, 0);
  }

  //nota: el xtras es un array de arrays de 4 valores:
  // el primero es para el que pega
  // el segundo es para el que defiende
  // el tercero es para los demas
  // el cuarto es una closure a llamar tras los mensajes

  switch (flags) {
    case ATTACK_SNEAK:    deflags=DEFEND_NOMSG|DEFEND_NO_DEF_SK; break;
    default:         deflags=DEFEND_NOMSG;
  }

  res = def->Defend(dam,dam_type,deflags,&xtras);

  // HBSTAT
  if (query_once_interactive(atk)) atk->SubeHBStat(def);

#ifdef ESTADISTICAS
  atk->AddGolpe();
  if (res > 0) atk->AddRecibido();
  if (res==ATK_ESQUIVADO) atk->AddEsquivado();
  if (res==ATK_PARADO) atk->AddParado();
#endif

  if (def->QueryStatusSleeping())
  {
    tell_object(def,"Te despiertas sobresaltad"+def->QueryGenderEndString()+".\n");
    tell_room(environment(def),def->QueryName()+" se despierta sobresaltad" +
                               def->QueryGenderEndString() + ".\n", ({def}) );
    def->SetStatusNormal();
  }
  else if (def->QueryStatusResting())
  {
    tell_object(def,"Te levantas sobresaltad" + def->QueryGenderEndString()+".\n");
    tell_room(environment(def),def->QueryName()+" se levanta sobresaltad" +
                               def->QueryGenderEndString() + ".\n", ({def}));
    def->SetStatusNormal();
  }

#ifdef NYH_DEBUG_PUPA
  write_file("/log/combat/PUPA","["+atk->QueryLevel()+"]<"+atk->QueryGuildLevel()+">"+(atk->QueryGuild()||"ninguno")+" "+capitalize(atk->QueryRealName())+"\tgolpea a ["+def->QueryLevel()+"]<"+def->QueryGuildLevel()+">"+(def->QueryGuild()||"ninguno")+" "+capitalize(def->QueryRealName()));
  write_file("/log/combat/PUPA","\t Daño original: "+orgdam+" defendido: "+dam+"\n");
#endif

  DoCombatMessage(atk, def, weapon, res, flags);

  if (sizeof(xtras)) {
    mixed *func = ({ });
    foreach (mixed arr:xtras) {
      switch (sizeof(arr)) {
        default: if (arr[3]) func += ({ arr[3] });
        case 3:  if (arr[2]) tell_room(environment(atk), arr[2],({atk,def}));
        case 2:  if (arr[1]) tell_object(def, arr[1]);
        case 1:  if (arr[0]) tell_object(atk, arr[0]);
        case 0:  break; // ;p
      }
    }
    if (sizeof(func)) foreach (closure f:func) funcall(f);
  }

  if (def && (environment(def)!=here)) def->RemoveEnemy(atk); //def ha huido o se ha destruido...

  return def;
}
