/*
 *  /obj/reportmaster.c
 */

 /*
 Este objeto se encarga de manejar los reportes que den los players acerca de
 ideas, tipos y bugs y escribirlos en el log correspondiente
 */

#include <search.h>
#include "/secure/userinfo.h"

//-----------------------------------------------------------------------------
// [w] Se graban los mensajes de tipo: BUG, IDEA, TYPO en sus respectivos
//     ficheros de log.
private varargs void smart_log(string type, string msg, object env, object obj) {
  string creat, lmsg, lugar;
  string *names;


  if (!env) env = environment(TI);

  lmsg = ctime() + " " + type + " de " + capitalize(TI->QueryRealName())
       + " (" + MASTER->find_userinfo(TNREAL)[USER_EMAIL] + ")";
  if (obj) lmsg += " para " + object_name(obj);
  lmsg += " en " + object_name(env) + ":\n" + msg + "\n";

  if (!obj) obj = env;
  names = explode(object_name(obj), "/");

  if (sizeof(names) >= 3) lugar = names[2];
  if (creat = MASTER->get_wiz_name(obj)) log_file("rep/"+creat, lmsg);
  if (names[0] == "d" && sizeof(names) > 1) log_file("rep/"+names[1], lmsg);
  log_file("rep/"+type, lmsg);
  if (type == "BUG")
  {
      send_server_request("SendAdmin",0, "Bug " + (lugar ? "en " + lugar : ""), lmsg);
  }

}

//-----------------------------------------------------------------------------
// Función auxiliar para hacer un input_to del informe
static int _doreport2(string input, string type, string ack, string nak, object env, object obj)
{
    if (!sizeof(input)) {
        write(nak || "Informe detenido.\n");
        return 1;
    }
    smart_log(type, input, env, obj);
    write(ack || "Tu informe ha sido grabado y será tenido en cuenta. Gracias.\n");
    return 1;
}

//-----------------------------------------------------------------------------
// Funcion principal del reportmaster
//  str - Texto del informe
//        Si es de la forma string1:string1 se supondra que es un informe sobre el
//          objeto string1 y se buscara alrededor de TI para hacer el informe
// type - Tipo de informe ("BUG", "IDEA", "TYPO")
//  ack - Mensaje enviado si se guarda con exito el informe
//  nak - Mensaje enviado si falla al guardar el informe
public int DoReport(string str, string type, string ack, string nak) {
    int i;
    object obj;
    string sobj;

    if (str && -1 != (i = member(str, ':')) && i > 1 && str[i-1] != ' ') {
        sobj = norm_id(str[0..i-1]);
        obj = present(sobj, environment(TI))
              || present(sobj, TI)
              || search(TI, sobj, SEARCH_ENV_INV|SM_REALLY|SM_OBJECT|SM_IGNLIGHT);
        if (!obj) {
            write("No existe el objeto '"+sobj+"' a tu alrededor.\n");
            return 1;
        }
        do i++; while (str[i] == ' ');
        str = str[i..];
    }
    if (!sizeof(str)) {
        write("Introduce la linea de informe: ");
        input_to("_doreport2", 0, type, ack, nak, obj);
        return 1;
    }
    _doreport2(str, type, ack, nak, environment(TI), obj);
    return 1;
}

//-----------------------------------------------------------------------------
