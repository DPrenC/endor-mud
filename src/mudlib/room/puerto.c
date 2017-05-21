/* SIMAURIA '/room/puerto.c'
   =========================
   [w] Woo@simauria

   29-12-97 [w] Traduccion y adaptacion para Simauria.
   27-10-98 [w] Modificado el lugar de habitacion.c
*/


#include <config.h>
#include <properties.h>

inherit ROOM;
inherit STR;

private static string *Pships;
private static int Pautocall;

public string *SetShips(string *s) { return Pships = s; }
public string *QueryShips() { return (Pships||({}))+({}); }

/* Anyadira un barco cuando el jugador entre en el puerto
 */
public string *AddShip(string shipfile)
{
  shipfile = resolve_file(shipfile);
  return Pships = (Pships||({}))-({shipfile})+({shipfile});
}

/* Si el modo es !=0 el barco sera llamado automaticamente cuando el
 * jugador entre en el puerto. En caso contrario el barco no sera llamado
 * y habra que anyadirlo manualmente.
 */
public int SetAutocall(int mode)
{
  return Pautocall = mode;
}
public int QueryAutocall() { return Pautocall; }

protected object valid_ship(string ship)
{
  object res;
  string error;
  if (file_size(ship+".c")<0)
    {
      MASTER->runtime_error("Ese barco no existe!\n",
                            object_name(),ship,-1);
      return 0;
    }
  if (error = catch(res = load_object(ship)))
    {
      MASTER->runtime_error("Error barco: "+error,
                            object_name(),ship,-1);
      return 0;
    }
  return res;
}

protected int get_ship_number(string ship)
{
  object ob;
  mapping ports;
  int *idx,pos;
  string *list;
  if (ob = valid_ship(ship))
    {
      ports = ship->QueryPorts();
      list = m_values(ports);
      idx = m_indices(ports);
      if ((pos = member(list,object_name()))==-1)
	{
	  MASTER->runtime_error("El barco no conoce ese puerto.\n",
                                object_name(),ship,-1);
          return -1;
	}
      return idx[pos];
    }
  return -1;
}

/* Devuelve todos los barcos anyadidos a este puerto y la posicion de
 * de este puerto en la Lista de Puertos del barco.
 * Si por alguna razon el barco no pasara por este puerto devolveria un -1
 */
public mapping QueryTable()
{
  int i,*nrs;
  string *ships;
  ships = QueryShips();
  nrs = map(ships,SF(get_ship_number));
  return mkmapping(ships,nrs);
}

protected string evaluate_course(int c)
{
  mapping table;
  string *ships;
  int i,nr;
  table = QueryTable();
  i = sizeof(ships = m_indices(table));
  nr = 1;
  while(i--)
    {
      mixed idx;
      object ship;
      mapping ports;
      int j;

      if (table[ships[i]]==-1) continue;
      if (nr<c)
	{
	  nr++;
          continue;
	}
      if (nr>c)
	return "No hay ningun barco con el numero "+to_string(c)+" en la tabla.\n";
      ports = ships[i]->QueryPorts();
      j = sizeof(idx = sort_array(m_indices(ports),SF(<)));
      while(j--)
	idx[j] = ports[j,1];
      return wrap(capitalize(ships[i]->Query(P_NAME)||
                        strip_article(ships[i]->QueryShort()))+
             " hace escala en los puertos siguientes:\n"+
             implode(idx," - ")+".\n");
    }
  return "No se encontro ningun barco.\n";
}

public int cmd_course(string str)
{
  int nr;

  if (!str)
    return notify_fail("De que barco quieres saber el trayecto?\n",
		       NOTIFY_NOT_OBJ),0;
  str = lower_case(str);
  if (   sscanf(str,"%d",nr)!=1
      && sscanf(str,"barco %d",nr)!=1
      && sscanf(str,"del barco %d",nr)!=1)
    return notify_fail("Di el numero del barco del cual quieres conocer su trayecto.\n"
                       ,NOTIFY_NOT_VALID),0;
  write(evaluate_course(nr));
  return 1;
}

public string detail_table(string what)
{
  mapping table;
  string *ships,*list;
  int i,nr;
  table = QueryTable();
  i = sizeof(ships = m_indices(table));
  list = ({});
  nr = 1;
  while(i--)
    {
      string line;
      object ship;
      if (table[ships]==-1)
	continue;
      line = radjust(to_string(nr),2)+". "+
             ladjust(capitalize(ships[i]->Query(P_NAME)||
                                strip_article(ships[i]->QueryShort())
                               )+" ",35,".");
      if (!(ship = ships[i]->QueryShip())||!environment(ship) )
        line+=" hundido";
      else
        if (environment(ship)==TO)
          line+=" en el muelle";
        else
	  {
	    if (object_name(environment(ship))==OCEAN)
              line+=" hacia ";
	    else
              line+=" en ";
	    line+=ship->Harbour();
	  }
      list+=({line});
      nr++;
    }
  if (nr==1)
    return "Ningun barco hace escala en este puerto.\n";
  return
    "Barcos que hacen escala en este puerto:\n"
    "---------------------------------------\n\n"+implode(list,"\n")+"\n\n"
    "Puedes conseguir informacion acerca de las escalas de un barco escribiendo:\n"
    "  escalas <numero>\n"
    "Si quieres subir al barco escribe 'subir <nombre del barco>'.\n";
}


public void CallShip(string file)
{
  object ob;
  if (ob = valid_ship(file))
    file->CallShip();
}

public void CallShips()
{
  map(QueryShips(),SF(CallShip));
}

public void create()
{
  ::create();
  SetIntShort("Un puerto");
  SetIntLong(
    "Este es un puerto como otro cualquiera donde algunos barcos atracan.\n"
    "Puedes ver una tabla con los distintos horarios.\n");
  SetIndoors(0);
  SetAutocall(1);
  AddDetail(({"tabla","tabla de horarios","horarios","tabla horarios"}),
    SF(detail_table));
  AddReadMsg(({"tabla","tabla de horarios","horarios","tabla horarios"}),
    SF(detail_table));
  AddRoomCmd("escalas",SF(cmd_course));
}

public void notify_enter(mixed from,int method,mixed extra)
{
  if (query_once_interactive(PO)&&QueryAutocall())
    CallShips();
  return (::notify_enter(from,method,extra));
}
