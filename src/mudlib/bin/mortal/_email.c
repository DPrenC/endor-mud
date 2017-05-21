/* SIMAURIA '/bin/mortal/_email.c'
*/

#include "/secure/userinfo.h"
#include <input_to.h>
#include <characters.h>

private static string _email;
private static mixed *uinfo;

public int main(string str)
{
    uinfo = MASTER->find_userinfo(TNREAL, 1);
    if (!str || str == "")
    {
        write("Tu direcci�n de correo electr�nico actual es: " +
              uinfo[USER_EMAIL] + ".\n");
        return 1;
    }
    if (uinfo[USER_ID] != uinfo[USER_MAIN_CHARACTER])
    {
        return notify_fail("S�lo podr�s cambiar la direcci�n de correo de tus personajes "
                           "desde tu personaje principal.\n");
    }
    if (uinfo[USER_EMAIL] == str)
    {
        return notify_fail("Esa ya es tu direcci�n de correo actual.\n");
    }
    if (LOGIN->valid_email(str) <= 0)
    {
        return notify_fail("Esa direcci�n de correo no es v�lida.\n");
    }
    if (MASTER->mail_exists(str))
    {
        return notify_fail("Esa direcci�n de correo ya est� registrada en el sistema para otro "
                           "personaje no asociado a este.\n");
    }
    _email = str;
    input_to("enter_email", INPUT_PROMPT,
        "Vuelve a escribir la nueva direcci�n de correo electr�nico: ");
    return 1;
}

public void enter_email(string str)
{
    mixed *info;
    if (str != _email)
    {
        write("�Has introducido dos direcciones de correo diferentes!\n");
        return;
    }
    if ((info = CHARMASTER->QueryBanishedEmail(str, CH_INFO))[CH_STATUS])
    {
        write("\n�Esa direcci�n de correo electr�nico est� baneada" +
            (info[CH_INFO][E_BAN_UNTIL] ? " hasta el " + STR->etime(1, ctime(info[CH_INFO][E_BAN_UNTIL])) : "") +
            "!\n");
        return;
    }
    if (!send_server_request("ChangeEmail", MASTER->find_userinfo(TNREAL)[USER_ID], _email))
    {
        write("�Error al enviar la petici�n de cambio de direcci�n de correo electr�nico!\n"
              "Por favor, int�ntalo de nuevo, y si contin�a sin funcionar, contacta con "
              "un vala.\n");
        return;
    }
    write("De acuerdo. Se te ha enviado un e-mail a " + _email + " con instrucciones "
          "para realizar el cambio de direcci�n.\n");
}