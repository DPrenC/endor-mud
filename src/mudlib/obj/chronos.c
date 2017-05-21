/* SIMAURIA '/obj/chronos.c'
   =========================

   [t] Theuzifan

   02-10-99 [t] Creación. Me he basado en el servidor de clima de Woodland
   		hecho por Joern de una manera indirecta, basándome en el
   		de Nandor. Lo hago por varias razones. La primera es que
   		ya he visto dos versiones pataleando, y quizás una tercera
   		que iba a hacer yo.
   		La segunda es que se basaba en la época real del mundo, y
   		pasaba de la del MUD. Ahora esto ya no es asin, puesto que
   		usa unas funcioncillas que he creado que dan fecha del mud
   		basada en time() y lo que duran los dias, meses, etc. en
   		simauria respecto del 'mundo real'.
   07-10-99 [t] Arreglo un bug en los SetDayMessages y SetNightMessages,
   		que hacian mal la comprobación del tamaño...
   13-10-99 [t] Ahora no te devuelve '0' si no hay clima predefinido...
   14-10-99 [t] Se notifica en mi habitación los cambios...
   25-10-99 [t] Ahora tarda un poco más en cambiar de estado.
   03-12-99 [t] Corregida la función CalcWeatherState, que devolvia lo que no
   		debe...
   09-12-99 [t] Recorregida, devolvia otra cosa inconexa total :)
   14-01-00 [t] Corrijo un pequeño bug en un sizeof que daba un index out of
   		bounds que te cagabas, y ahora me dice mensajes a mi de guay
   		pa controlar que pasa por el mundo mundial.
*/

inherit ROOM;
#include <config.h>
#include <properties.h>
#include <weather.h>
#include <chronos.h>
#include <colours.h>

/*--------------------------------------------------------------*/
/*	DEFINICIONES PARA LA OBTENCION DE LA FECHA CORRECTA	*/
/*--------------------------------------------------------------*/

#define T_NORMAL DAY_LENGTH/24/3
#define T_SHORT T_NORMAL/2
#define T_LONG T_NORMAL*2

#define ANYO_BASE 4240

#define SEC_DURATION	(DAY_LENGTH/60/24)
#define M_MINUTOS(x)	(x/(SEC_DURATION))
#define M_HORAS(x) 	(x/(SEC_DURATION*60))
#define M_DIAS(x)	(x/(SEC_DURATION*1440))
#define M_MESES(x)	(x/(SEC_DURATION*43200))
#define M_ESTACIONES(x)	(x/(SEC_DURATION*172800))
#define M_ANYOS(x)	(x/(SEC_DURATION*691200))

#define NC_DEFAULT ({NORMAL,CALOR,FRIO,LLUVIA,VIENTO,TORMENTA,NIEBLA,NIEVE,TORMENTA_NIEVE})
#define C_DEFAULT ({\
	([FRIO:20,TORMENTA:20,NIEBLA:20,NIEVE:40]),\
	([FRIO:30,TORMENTA:20,NIEBLA:15,NIEVE:35]),\
	([FRIO:20,LLUVIA:10,TORMENTA:10,NIEBLA:30,NIEVE:30]),\
	([FRIO:20,LLUVIA:20,TORMENTA:5,NIEBLA:35,NIEVE:20]),\
	([LLUVIA:40,NORMAL:10,VIENTO:20,CALOR:10,]),\
	([LLUVIA:30,NORMAL:20,VIENTO:10,CALOR:20,]),\
	([LLUVIA:30,NORMAL:40,VIENTO:10,CALOR:20]),\
	([LLUVIA:35,NORMAL:35,VIENTO:10,CALOR:20]),\
	([CALOR:30,NORMAL:55,LLUVIA:5]),\
	([CALOR:60,NORMAL:30,LLUVIA:5,TORMENTA:5]),\
	([CALOR:70,NORMAL:20,TORMENTA:5,LLUVIA:5]),\
	([CALOR:30,NORMAL:40,LLUVIA:20,TORMENTA:10]),\
	([NORMAL:35,FRIO:30,LLUVIA:20,NIEBLA:10,VIENTO:5]),\
	([VIENTO:5,FRIO:40,LLUVIA:30,NIEBLA:15,TORMENTA:10]),\
	([VIENTO:15,FRIO:30,LLUVIA:30,NIEBLA:15,TORMENTA:10]),\
	([NIEVE:10,FRIO:30,LLUVIA:30,NIEBLA:15,TORMENTA:15])})

#define L_DEFAULT ({ T_SHORT, T_SHORT, T_NORMAL, T_NORMAL, T_NORMAL, T_LONG,\
                 T_LONG, T_LONG, T_NORMAL, T_NORMAL, T_SHORT, T_SHORT })

static int wstate, weather;
static int *wstatelen; /* Length of the several weather states */
static string wmsg;
static int mtemp;
static mixed *msg_ground;
static mixed *msg_noche, *msg_dia;
static mixed *climate;

/*----------------------------------------------*/
/*	OBTENCION DE LA FECHA CORRECTA		*/
/*----------------------------------------------*/

int QueryYear() { return ANYO_BASE+M_ANYOS(time()); }
int QueryEstacion() { return (M_ESTACIONES(time())%4)+1; }
int QueryMonth() { return (M_MESES(time())%16)+1; }
int QueryDay() { return (M_DIAS(time())%30)+1; }
int QueryHour() { return M_HORAS(time())%24; }
int QueryMinute() { return M_MINUTOS(time())%60; }
int QuerySecond() { return ((time()-21600*43000)*4)%60; }//truco para el overflow


/*------------------------------*/
/*	OBTENCION DEL CLIMA	*/
/*------------------------------*/

mixed *QueryClimate() { return climate; }
mixed *SetClimate(mixed *cl)
{
  if (sizeof(cl||({}))!=16) return climate;
  return climate=cl;
}

int CalcWeatherState()
{
  int *perc, *idx, rand, cperc, i;

  perc=m_values(climate[QueryMonth()-1]);
  idx=m_indices(climate[QueryMonth()-1]);
  rand=random(101);
  cperc=0;

  for (i=0; i<sizeof(perc)-1; i++)
  {
    cperc+=perc[i];
    if (rand<cperc) break;
  }
  return idx[i];
}

create() {
  int nightday;
  ::create();

  SetIntLong("Servidor general de Endor-Mud.\n");
  SetIntShort("servidor de climas");
  seteuid(getuid());
  wstatelen=L_DEFAULT;
  climate=C_DEFAULT;
  msg_dia=MSG_DEFAULT_DIA;
  msg_noche=MSG_DEFAULT_NOCHE;
  msg_ground=MSG_DEFAULT_GROUND;
  wstate=-1;
  weather=CalcWeatherState();
  wmsg=msg_noche[weather][0];

  nightday = NIGHTDAY->QueryState();

  if (nightday<ND_FALL && nightday>ND_DAWN) wmsg=msg_dia[weather][0];
  else wmsg=msg_noche[weather][0];
  call_out("NextWeather", T_SHORT+random(T_SHORT));
}

/*------------------------------------------------------*/
/*	DEFINICION DE LAS VARIABLES CLIMATICAS		*/
/*------------------------------------------------------*/

string QueryWeatherMsg () { return wmsg; }
int QueryWeatherLength () { return wstatelen[wstate]; }
int QueryWeatherTimeLeft() { return find_call_out ("NextWeather"); }
int QueryWeatherState() { return wstate; }
int QueryWeatherClimate() { return mtemp; }
mixed *QueryGroundMessages() { return msg_noche; }
mixed *QueryDayMessages() { return msg_dia; }
mixed *QueryNightMessages() { return msg_noche; }
mapping QueryMonthClimate(int month)
{
  int tmonth;
  if (month>0) tmonth=month-1;
  else tmonth=QueryMonth()-1;
  return climate[tmonth];
}
int *QueryStateLength() { return wstatelen; }
string *QueryDayMessageForClimate(int state) { return msg_dia[state]; }
string *QueryNightMessageForClimate(int state) { return msg_noche[state]; }
string *QueryGroundMessageForClimate(int state) { return msg_ground[state]; }
mixed *SetDayMessageForClimate(int state, string *message)
{
  if (sizeof(message||({}))!=12) return msg_dia;
  if (state>NIEVE) return msg_dia;
  msg_dia[state]=message;
  return msg_dia;
}
mixed *SetNightMessageForClimate(int state, string *message)
{
  if (sizeof(message||({}))!=12) return msg_noche;
  if (state>NIEVE) return msg_noche;
  msg_noche[state]=message;
  return msg_noche;
}
mixed *SetGroundMessageForClimate(int state, string *message)
{
  if (sizeof(message||({}))!=6) return msg_ground;
  if (state>NIEVE) return msg_ground;
  msg_ground[state]=message;
  return msg_ground;
}
int *SetStateLength(int *sl)
{
  if (sizeof(sl||({}))!=12) return wstatelen;
  return wstatelen=sl;
}
mixed *SetMonthClimate(int month, mapping weather)
{
  int tmonth;

  if (!weather) return climate;
  if (month>0) tmonth=month-1;
  else tmonth=QueryMonth()-1;
  climate[tmonth]=weather;
  return climate;
}
string SetWeatherMsg (string m) { return wmsg=m; }
int SetWeatherClimate(int cl)
{
  if (cl>7 || cl<0) return mtemp;
  return mtemp=cl;
}
mixed *SetGroundMessages(mixed *gd)
{
  if (sizeof(gd||({}))!=6) return msg_ground;
  return msg_ground=gd;
}
mixed *SetDayMessages(mixed *ms)
{
  if (sizeof(ms||({}))!=8) return msg_dia;
  return msg_dia=ms;
}
mixed *SetNightMessages(mixed *ms)
{
  if (sizeof(ms||({}))!=8) return msg_noche;
  return msg_noche=ms;
}


/*------------------------------*/
/*	MANEJO DEL CLIMA	*/
/*------------------------------*/

string QueryGroundDesc() { return msg_ground[weather][wstate/2]; }

#define N(x) TC_CYAN+x+TC_NORMAL
void NotifyRoomsOfWeather(string wmsg)
{
  mixed *u;
  int i;
  object room, myroom;
  object server;
  string sServer;
  object *notified;

  notified = ({});
  u = users();

  for (i = 0; i < sizeof(u); i++)
    if ((room = environment(u[i])) && (sServer = room->QueryClimateServer()))
      if ((server = find_object(sServer)) && server == TO)
      {
        if (member(notified, room) < 0)
          if (!room->QueryIndoors())
          {
            tell_room(room, wmsg);
            myroom=find_object("/players/theuzifan/clima");
            if (myroom)
              tell_room(myroom,
            	W("HABITACION "+N(object_name(room))+
            	" con servidor "+N(object_name(server))+" llamado por "+
            	N(object_name(TO))+" con descripción: "+
            	N(wmsg)));
          }
        notified += ({room});
      }
}


varargs void NextWeather()
{
  int nightday, addtime;

  addtime=random(60);
  wstate++;
  if (wstate>11)
  {
    wstate=0;
    weather=CalcWeatherState();
    addtime+=T_NORMAL;
  }
  remove_call_out("NextWeather");
  call_out("NextWeather", wstatelen[wstate]+addtime);

  nightday = NIGHTDAY->QueryState();

  if (nightday<ND_FALL && nightday>ND_DAWN) wmsg=msg_dia[weather][wstate];
  else wmsg=msg_noche[weather][wstate];
  tell_room(TO, "El estado ha cambiado a "+wstate+
  	", para el clima "+weather+".\n");
  NotifyRoomsOfWeather(wmsg);
}

