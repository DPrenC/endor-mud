/***************************************************************************************
 ARCHIVO:	parada.c
 AUTOR:		[z] Zomax
 FECHA:		14-12-2001
 COMENTARIOS:	Funciones de las caravanas.
 		Adaptacion para Rhoemas por [z] Zomax (simplemente eliminados los
 		comentarios y el create, porque me petaban mis mappings al heredar,
 		ahora la incluyo solo.
 ***************************************************************************************/

#define DESIERTO "/room/desierto"

inherit ROOM;
inherit "/obj/lib/string";

private static string *Pcaravanas;
private static int Pautocall;

public string *SetCaravanas(string *s) { return Pcaravanas = s; }
public string *QueryCaravanas() { return (Pcaravanas||({}))+({}); }

public string *AddCaravana(string caravanafile)
{
  caravanafile = resolve_file(caravanafile);
  return Pcaravanas = (Pcaravanas||({}))-({caravanafile})+({caravanafile});
}

public int SetAutocall(int mode)
{
  return Pautocall = mode;
}
public int QueryAutocall() { return Pautocall; }

protected object valid_caravana(string caravana)
{
  object res;
  string error;
  if (file_size(caravana+".c")<0)
    {
      MASTER->runtime_error("Esa caravana no existe!\n",
                            object_name(),caravana,-1);
      return 0;
    }
  if (error = catch(res = load_object(caravana)))
    {
      MASTER->runtime_error("Error caravana: "+error,
                            object_name(),caravana,-1);
      return 0;
    }
  return res;
}

protected int get_caravana_number(string caravana)
{
  object ob;
  mapping paradas;
  int *idx,pos;
  string *list;
  if (ob = valid_caravana(caravana))
    {
      paradas = caravana->QueryParadas();
      list = m_values(paradas);
      idx = m_indices(paradas);
      if ((pos = member(list,object_name()))==-1)
	{
	  MASTER->runtime_error("La caravana no conoce ese lugar.\n",
                                object_name(),caravana,-1);
          return -1;
	}
      return idx[pos];
    }
  return -1;
}

public mapping QueryTable()
{
  int i,*nrs;
  string *caravanas;
  caravanas = QueryCaravanas();
  nrs = map(caravanas,SF(get_caravana_number));
  return mkmapping(caravanas,nrs);
}

protected string evaluate_course(int c)
{
  mapping table;
  string *caravanas;
  int i,nr;
  table = QueryTable();
  i = sizeof(caravanas = m_indices(table));
  nr = 1;
  while(i--)
    {
      mixed idx;
      object caravana;
      mapping paradas;
      int j;

      if (table[caravanas[i]]==-1) continue;
      if (nr<c)
	{
	  nr++;
          continue;
	}
      if (nr>c)
	return "No hay ninguna caravana con el numero "+to_string(c)+" en la tabla.\n";
      paradas = caravanas[i]->QueryParadas();
      j = sizeof(idx = sort_array(m_indices(paradas),SF(<)));
      while(j--)
	idx[j] = paradas[j,1];
      return W(capitalize(caravanas[i]->Query(P_NAME)||
                        strip_article(caravanas[i]->QueryShort()))+
             " hace parada en los siguientes lugares:\n"+
             implode(idx," - ")+".\n");
    }
  return "No se encontro ninguna caravana.\n";
}

public int cmd_course(string str)
{
  int nr;

  if (!str)
    return notify_fail("De que caravana quieres saber el trayecto?\n",
		       NOTIFY_NOT_OBJ),0;
  str = lower_case(str);
  if (   sscanf(str,"%d",nr)!=1
      && sscanf(str,"caravana %d",nr)!=1
      && sscanf(str,"de la caravana %d",nr)!=1)
    return notify_fail("Di el numero de la caravana de la cual quieres conocer su trayecto.\n"
                       ,NOTIFY_NOT_VALID),0;
  write(evaluate_course(nr));
  return 1;
}

public string detail_table(string what)
{
  mapping table;
  string *caravanas,*list;
  int i,nr;
  table = QueryTable();
  i = sizeof(caravanas = m_indices(table));
  list = ({});
  nr = 1;
  while(i--)
    {
      string line;
      object caravana;
      if (table[caravanas]==-1)
	continue;
      line = radjust(to_string(nr),2)+". "+
             ladjust(capitalize(caravanas[i]->Query(P_NAME)||
                                strip_article(caravanas[i]->QueryShort())
                               )+" ",35,".");
      if (!(caravana = caravanas[i]->QueryCaravana())||!environment(caravana) )
        line+=" aniquilada";
      else
        if (environment(caravana)==TO)
          line+=" en la parada";
        else
	  {
	    if (object_name(environment(caravana))==DESIERTO)
              line+=" hacia ";
	    else
              line+=" en ";
	    line+=caravana->Parada();
	  }
      list+=({line});
      nr++;
    }
  if (nr==1)
    return "Ninguna caravana se detiene en este lugar.\n";
  return
    "Caravanas que se detienen en este lugar:\n"
    "---------------------------------------\n\n"+implode(list,"\n")+"\n\n"
    "Puedes conseguir informacion acerca de las escalas de una caravana escribiendo:\n"
    "  escalas <numero>\n"
    "Si quieres subir a la caravana escribe 'unirse <nombre de la caravana>'.\n";
}


public void CallCaravana(string file)
{
  object ob;
  if (ob = valid_caravana(file))
    file->CallCaravana();
}

public void CallCaravanas()
{
  map(QueryCaravanas(),SF(CallCaravana));
}

public void notify_enter(mixed from,int method,mixed extra)
{
  if (query_once_interactive(previous_object())&&QueryAutocall())
    CallCaravanas();
  return (::notify_enter(from,method,extra));
}
