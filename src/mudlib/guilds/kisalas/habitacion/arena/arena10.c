/****************************************************************************
Fichero: arena10.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"
#include <moving.h>

#define MAX_FRUTOS 10
#define COGER ({"fruto", "fruto amarillo", "fruto del arbol", "fruto del �rbol"})

inherit SUELO_ARENA;

private int PFrutos; // frutos del �rbol


public int cmd_coger(string str)
{
    object fruto;
    if (!PFrutos || !str || member(COGER, str) < 0 || present(str)) return::cmd_coger(str);
    fruto = clone_object(AMAZONHOME + "obj/fruto_venenoso");
    if (fruto->move(TP) != ME_OK)
    {
        write("Intentas coger un fruto, pero se te resbala y cae al suelo.\n");
        say(CAP(TNAME) + " intenta coger un fruto del �rbol, pero se le resbala, "
            "cayendo al suelo.\n");
        fruto->move(TO);
    }
    else
    {
        write("Coges un fruto del �rbol.\n");
        say(CAP(TNAME) + " coge un fruto del �rbol.\n");
    }
    PFrutos--;
    return 1;
}


create()
{
    ::create();
    PFrutos = MAX_FRUTOS;
    SetIntLong("Has venido a parar a la costa occidental de la isla, donde "
               "las aguas del lago llegan casi hasta donde est�s. Al borde del "
               "mismo, ves un �rbol espinoso y de aspecto raqu�tico, que hunde "
               "sus ra�ces literalmente en las f�tidas aguas.\n");

    AnadeDetalleLago("oeste");
    AddDetail(({"arbol", "�rbol", "arbol espinoso", "�rbol espinoso",
                "arbol raqu�tico", "�rbol raqu�tico", "arbol raquitico",
                "�rbol raquitico"}),
                (:"Se trata de un �rbol de lo m�s extra�o. Parece que solo tuviese "
                  "ramas y espinas, sin hoja alguna." + (PFrutos ? " En su parte "
                  "superior, sin embargo, observas que las espinas son sustituidas "
                  "por un fruto peque�o de color amarillo." :
                  " En su parte superior, observas restos de lo que parece alg�n tipo "
                  "de fruto. Sin embargo, por m�s que miras, no consigues ver "
                  "ninguno.") + "\n":));

    AddDetail(({"fruto","fruto amarillo", "fruto del �rbol", "fruto del �rbol"}),
              (:(!PFrutos ? "Puedes ver varias ramas en las que parece que "
                            "hubiese habido alg�n tipo de fruto. Sin embargo, "
                            "por m�s que miras, el �rbol est� totalmente pelado.\n":
                            "En la parte superior de este extra�o �rbol, puedes "
                            "ver varios frutos. Son peque�os y redondeados, de un color "
                            "amarillo intenso. Quiz�s podr�as coger uno.\n"):));


    AddRoomCmd("coger","cmd_coger");
    AddExit("oeste","arena9");
    AddExit("norte","arena12");
    AddExit("noroeste","arena11");
    AddExit("sur","arena8");
    AddExit("suroeste","arena7");

}


public void reset()
{
    ::reset();
    PFrutos = MAX_FRUTOS;
}
