/*

Quiza haga excesivos chekeos en las funciones, pero mejor ir sobreseguro
*/

#include <groups.h>
#include <colours.h>

#define IN_ARRAY(x,y) (member(y,x)>-1) //si, macho, me da por usar lo al revés
#define MAX_DIF_LEVEL_GROUP	5
#define TEAM_LEADER	0 //en el array team el 0 es el lider

//----------------------------------------------------------------------------

public int QueryLevel();                              // std/living/description
public int QueryGuildLevel();
public int CanSeeObject(object liv);                  // std/living/description
public string QueryName();                            // std/living/description

//----------------------------------------------------------------------------

private nosave object *team,	// el equipo, el unico correcto al 100% es el del lider
                      *invited;	// los invitados POR mi

//----------------------------------------------------------------------------
// Equipo
//----------------------------------------------------------------------------
//Devuelve un array con los objetos de los miembros
private object *QueryRealTeam() { return copy(team=(team||({}))-({0}));}
public object *QueryTeam() {return copy(team=(team||({}))-({0}));}
//Establece el array del equipo
public object *SetTeam(mixed ob)   {return copy(team=ob);} //array
//añade un compi //1 si lo añade, 2 si ya estaba añadido, 0 si error
public int AddTeammate(object ob) {
  if (!ob || !TO || !living(ob)) return JOIN_ERROR;
  if (IN_ARRAY(ob, QueryRealTeam())) return JOIN_ALREADY;
  if (sizeof(QueryRealTeam())) team += ({ob});
  else team = ({TO, ob});
  call_other(QueryTeam()-({TO}),"SetTeam",QueryTeam());
  return  JOIN_OK;
}
//quita a un compi //1 si estaba en el grupo, 0 en caso contrario
// public int RemoveTeammate(object ob) { return IN_ARRAY(ob,QueryRealTeam())?(team-=({ob})),(ob->ResetTeammate()):0; }
public int RemoveTeammate(object ob) {
  if (IN_ARRAY(ob,QueryRealTeam())) {
    team-=({ob});
    return ob->ResetTeammate();
  }
  else return 0;
}
//resetea la lista de equipo
public int ResetTeammate() {return pointerp(team=({}));}

//----------------------------------------------------------------------------
// Lider
//----------------------------------------------------------------------------
//quien es mi lider
public object QueryLeader()   { return (sizeof(QueryTeam()-({TO})))?QueryRealTeam()[TEAM_LEADER]:0;}
//soy yo lider?
public int QueryIsLeader() { return (QueryLeader()==TO);}

//----------------------------------------------------------------------------
// Invitados
//----------------------------------------------------------------------------
//devuelve un array con los invitados o ({})
private object *QueryRealInvited() { return copy(invited=sizeof(invited)?(invited-({0})):({}));}
public object *QueryInvited(){return copy(invited=sizeof(invited)?(invited-({0})):({}));}
//añade un invitado //1 si lo invita, 2 si ya estaba invitado, 0 si error
public int AddInvited(object ob) {
  if (!ob || !TO || !living(ob)) return INVITE_ERROR;
  if (IN_ARRAY(ob, QueryRealInvited())) return INVITE_ALREADY;
  invited += ({ob});
  return  INVITE_OK;
}
//quita a un invitado //1 si estaba invitado, 0 en caso contrario
//public int RemoveInvited(object ob) { return IN_ARRAY(ob,QueryRealInvited())?(invited-=({ob})),1:0; }
public int RemoveInvited(object ob) {
  if (IN_ARRAY(ob,QueryRealInvited())) {
    invited -= ({ob});
    return 1;
  }
  else return 0;
}
//resetea la lista de invitados
public int ResetInvited() {return pointerp(invited=({}));}

//----------------------------------------------------------------------------
// Funciones del equipo
//----------------------------------------------------------------------------
// invita a ob a MI grupo
//los codigos de vuelta negativos indican errores (ahora son defines)
public int TeamInvite(object ob) {
  if (!ob || !living(ob) || !TO) return INVITE_ERROR;
  if (ob->QueryLeader())   return INVITE_OB_HAS_LIDER;
  if (ob->QueryIsLeader()) return INVITE_OB_IS_LEADER;
  if ((ob->QueryGuildLevel()-QueryGuildLevel())>MAX_DIF_LEVEL_GROUP) return INVITE_OB_HIGH_LEVEL;
  if ((QueryGuildLevel()-ob->QueryGuildLevel())>MAX_DIF_LEVEL_GROUP) return INVITE_OB_LOW_LEVEL;
  return AddInvited(ob);
}

// quita a ob de mi lista de invitados
public int TeamUnvite(object ob) {
  if (!ob || !TO || !living(ob)) return UNVITE_ERROR;
  if (!RemoveInvited(ob)) return UNVITE_OB_NOT_INVITED;
  return UNVITE_OK;
}

//une a ob al grupo (a MI grupo) si puede
public int TeamJoin(object ob) {
  if (!ob || !TO || !living(ob)) 	return JOIN_ERROR;
  if (!RemoveInvited(ob)) 			return JOIN_OB_NOT_INVITED;
  if (QueryLeader() && !QueryIsLeader())	return JOIN_TO_HAS_LEADER;
  if (ob->QueryLeader()) 			return JOIN_OB_HAS_LEADER;
  if (ob->QueryIsLeader()) 			return JOIN_OB_IS_LEADER;
  if ((ob->QueryGuildLevel()-QueryGuildLevel())>MAX_DIF_LEVEL_GROUP) return JOIN_OB_HIGH_LEVEL;
  if ((QueryGuildLevel()-ob->QueryGuildLevel())>MAX_DIF_LEVEL_GROUP) return JOIN_OB_LOW_LEVEL;
  return AddTeammate(ob);
}

//Quita a ob del grupo
public int TeamLeave(object ob) {
  if (!ob || !TO || !living(ob)) return LEAVE_ERROR;
  if (RemoveTeammate(ob)) {
    call_other(QueryTeam()-({TO}),"SetTeam",QueryTeam());
    return LEAVE_OK;
  }
  return LEAVE_ERROR;
}

//Eres lider y hechas a ob del grupo
public int ForceTeamLeave(object ob) {
  if (!ob || !TO || !living(ob)) return FORCELEAVE_ERROR;
  if (!QueryIsLeader()) return FORCELEAVE_ISNT_LEADER;
  if (RemoveTeammate(ob)) {
    call_other(QueryTeam()-({TO}),"SetTeam",QueryTeam());
    return FORCELEAVE_OK;
  }
  return FORCELEAVE_ERROR;
}

public void create() {
  team = invited = ({ });
}

// -----------------------------------------------------------------------------
// Manejo de llamadas
// -----------------------------------------------------------------------------
public int view_grupo() {
  string str;
//  write(sprintf("%O\n",QueryRealTeam()));
// nivel, nombre, gremio, pv, pm, pf, px, fza, des, con, int
  str = "[Niv] "+TC_BOLD+TC_GREEN+STR->ladjust("Nombre",10," ")+TC_NORMAL+"[Niv] "+TC_BOLD+TC_CYAN+STR->ladjust("Gremio",14," ")+TC_NORMAL+/*" Fue Des Con Int"*/TC_RED"  PV/Max  "TC_CYAN" PM/Max  "TC_YELLOW" PF/Max      "TC_PURPLE" PX"TC_NORMAL"\n";
  foreach(object ob:QueryRealTeam())
    str+= "["+STR->radjust(to_string(ob->QueryLevel()),3,"0")+"] "+STR->ladjcut(ob->QueryName(),10," ")
        +"["+STR->radjust(to_string(ob->QueryGuildLevel()),3,"0")+"] "+STR->ladjcut(capitalize(ob->QueryGuild()||"sin gremio"),14," ")
    	//+STR->radjust(to_string(ob->QueryStr()),4," ")+STR->radjust(to_string(ob->QueryDex()),4," ")+STR->radjust(to_string(ob->QueryCon()),4," ")+STR->radjust(to_string(ob->QueryInt()),4," ")
    	+STR->radjust(to_string(ob->QueryHP()),4," ")+"/"+STR->ladjust(to_string(ob->QueryMaxHP()),4," ")
    	+STR->radjust(to_string(ob->QuerySP()),4," ")+"/"+STR->ladjust(to_string(ob->QueryMaxSP()),4," ")
    	+STR->radjust(to_string(ob->QueryTP()),4," ")+"/"+STR->ladjust(to_string(ob->QueryMaxTP()),4," ")
    	+STR->radjust(to_string(ob->QueryXP()),12," ")+"\n";
  TO->catch_msg(str);
  return 1;
}

/*
pepe> grupo juan:
juan esta en mi grupo y soy lider: le hecho
juan esta en mi grupo y es lider:  me voy
juan esta en mi grupo y ninguno es lider: no pasa na
juan esta en mis invitados: le desinvito
pepe esta en los invitados de juan: nos unimos
juan no esta en mis invitados: le invito
*/
public int cmd_grupo(string str) {
  object ob, leader;

//if (find_object("nyh")) dtell("nyh",sprintf("%O->cmd_grupo(%O)\nteam=%O\ninvited=%O\n",TO,str,team,invited));
  if (!str) return view_grupo();
  str = lower_case(str);

  if ( !(ob=present(str)) && sizeof(QueryRealTeam()) ) //miro a ver si es alguno del grupo q se ha pirado...
    foreach(object ob2:team) if (str==lower_case(ob2->QueryName())) ob=ob2; //de haber varios solo pillo uno
  if (!ob) return notify_fail("No encuentras a '"+str+"' a tu alrededor.\n");
  if (ob==TO) return notify_fail("Se supone que tu ya vas contigo.\n");
//ya tengo a ob
  if ( sizeof(QueryTeam()-({TO})) ) { //estoy en un grupo
    if ((leader=QueryLeader())==TO) { //YO soy el leader
      if (IN_ARRAY(ob,QueryRealTeam())) { //ob esta en el grupo->le hecho
      	switch (ForceTeamLeave(ob)) {
	  case FORCELEAVE_OK: 	TO->catch_msg("Hechas a "+capitalize(str)+" del grupo.\n");
				tell_object(ob,capitalize(QueryName())+" te ha hechado del grupo.\n");
				str=capitalize(QueryName())+" ha hechado a "+capitalize(str)+" del grupo\n";
				map(QueryTeam()-({TO}),lambda(({SYM(x)}),({SF(tell_object),SYM(x),str})));
				return 1;
	  case FORCELEAVE_ERROR: return notify_fail("No puedes hechar a "+capitalize(str)+" del grupo.\n");
	  case FORCELEAVE_ISNT_LEADER: return notify_fail("No puedes hechar a alguien sin ser el líder.\n");
	  default: return notify_fail("Error 1 en el comando 'grupo'.\n");
	} //switch
      } //in array
      else { //no esta en el grupo->le invito
	switch (TeamInvite(ob)) {
	  case INVITE_OK: TO->catch_msg("Invitas a "+capitalize(str)+" a tu grupo.\n");
			  tell_object(ob,capitalize(QueryName())+" te invita a su grupo.\n");
			  str=capitalize(QueryName())+" ha invitado a "+capitalize(str)+" al grupo\n";
			  map(QueryTeam()-({TO}),lambda(({SYM(x)}),({SF(tell_object),SYM(x),str})));
			  return 1;
	  case INVITE_ERROR:		return notify_fail("No puedes invitar a "+capitalize(str)+".\n");
	  case INVITE_OB_HAS_LIDER: 	return notify_fail("No puedes invitar a alguien que tenga lider.\n");
	  case INVITE_OB_IS_LEADER:	return notify_fail("No puedes invitar a alguien que sea lider.\n");
	  case INVITE_OB_HIGH_LEVEL:	return notify_fail("No puedes invitar a alguien que te saque más de "+MAX_DIF_LEVEL_GROUP+" niveles.\n");
	  case INVITE_OB_LOW_LEVEL:	return notify_fail("No puedes invitar a alguien al que saques más de "+MAX_DIF_LEVEL_GROUP+" niveles.\n");
	  default: return notify_fail("Error 2 en el comando 'grupo'.\n");
        } //switch
      } //else in array
    } //if yo soy el lider
    else { //leader es el lider
      if (ob==leader) { //ob es el lider->me desagrupo
	switch (leader->TeamLeave(TO)) {
	  case LEAVE_OK:	TO->catch_msg("Abandonas el grupo de "+capitalize(str)+".\n");
				//tell_object(ob,capitalize(QueryName())+" ha abandonado tu grupo.\n");
				str=capitalize(QueryName())+" ha abandonado tu grupo.\n";
				map(leader->QueryTeam(),lambda(({SYM(x)}),({SF(tell_object),SYM(x),str})));
				return 1;
	  case LEAVE_ERROR:	return notify_fail("No puedes desagruparte de ningún grupo.\n");
	  default: return notify_fail("Error 3 en el comando 'grupo'.\n");
	}
      }
      else { //ob no se quien es... ni me importa
        return notify_fail("Sólo el líder del grupo puede hacer eso.\n");
      } //ob no se quien es
    } //leader es el lider
  } // estoy en un grupo
  else { //no estoy en ningun grupo
    if (IN_ARRAY(ob,QueryRealInvited())) { //ob esta invitado-> le desinvito
      switch (TeamUnvite(ob)) {
	case UNVITE_ERROR:          return notify_fail("No puedes retirar tu invitación a "+capitalize(str)+".\n");
	case UNVITE_OB_NOT_INVITED: return notify_fail("No puedes retirar tu invitación a "+capitalize(str)+".\n");
	case UNVITE_OK: TO->catch_msg("Retiras tu invitación de agruparte a "+capitalize(str)+".\n");
                	tell_object(ob,capitalize(QueryName())+" ha retirado su invitación de agruparos.\n");
	default: return notify_fail("Error 4 en el comando 'grupo'.\n");
      }
    } // IN_ARRAY esta invitado
    else { //no esta invitado
      if (IN_ARRAY(TO,ob->QueryInvited())) { //estoy en sus invitados->grupo!!!
	switch (ob->TeamJoin(TO)) {
	  case JOIN_OK: 	TO->catch_msg("Te unes al grupo de "+capitalize(str)+".\n");
				tell_object(ob,capitalize(QueryName())+" se une a tu grupo.\n");
				str=capitalize(QueryName())+" se une al grupo.\n";
				map(QueryTeam()-({TO}),lambda(({SYM(x)}),({SF(tell_object),SYM(x),str})));
				return 1;
	  case JOIN_ERROR:		return notify_fail("No puedes agruparte con "+capitalize(str)+".\n");
	  case JOIN_OB_NOT_INVITED:	return notify_fail("No puedes agruparte con alguien que no te ha invitado.\n");
	  case JOIN_TO_HAS_LEADER:	return notify_fail("No puedes agruparte con alguien que tiene un lider.\n");
	  case JOIN_OB_HAS_LEADER:	return notify_fail("No puedes agruparte con alguien si ya estas agrupado.\n");
	  case JOIN_OB_IS_LEADER:	return notify_fail("No puedes agruparte con alguien si eres lider de un grupo.\n");
	  case JOIN_OB_HIGH_LEVEL:	return notify_fail("No puedes agruparte con al que que saques más de "+MAX_DIF_LEVEL_GROUP+" niveles.\n");
	  case JOIN_OB_LOW_LEVEL:	return notify_fail("No puedes agruparte con que te saque más de "+MAX_DIF_LEVEL_GROUP+" niveles.\n");
	  default: return notify_fail("Error 5 en el comando 'grupo'.\n");
	}
      }
      else { //no estoy en sus invitados->le invito (a ob)
	switch (TeamInvite(ob)) {
	  case INVITE_OK:	TO->catch_msg("Invitas a "+capitalize(ob->QueryName())+" a tu grupo.\n");
				tell_object(ob,"Has sido invitado a unirte al grupo de "+capitalize(QueryName())+".\n");
				return 1;
	  case INVITE_ERROR:		return notify_fail("No puedes invitar a "+capitalize(str)+".\n");
	  case INVITE_OB_HAS_LIDER: 	return notify_fail("No puedes invitar a alguien que tenga lider.\n");
	  case INVITE_OB_IS_LEADER:	return notify_fail("No puedes invitar a alguien que sea lider.\n");
	  case INVITE_OB_HIGH_LEVEL:	return notify_fail("No puedes invitar a alguien que te saque más de "+MAX_DIF_LEVEL_GROUP+" niveles.\n");
	  case INVITE_OB_LOW_LEVEL:	return notify_fail("No puedes invitar a alguien al que saques más de "+MAX_DIF_LEVEL_GROUP+" niveles.\n");
	  default: return notify_fail("Error 6 en el comando 'grupo'.\n");
	}
      } //le invito
    } // no esta invitado
  } //no estoy en ningun grupo
  return 0;
}

public void add_groups_cmds() {
  add_action("cmd_grupo","grupo");
}
