/****************************************************************************
Fichero: arena10.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"
#include <moving.h>

#define MAX_FRUTOS 10
#define COGER ({"fruto", "fruto amarillo", "fruto del arbol", "fruto del árbol"})

inherit SUELO_ARENA;

private int PFrutos; // frutos del árbol


public int cmd_coger(string str)
{
    object fruto;
    if (!PFrutos || !str || member(COGER, str) < 0 || present(str)) return::cmd_coger(str);
    fruto = clone_object(AMAZONHOME + "obj/fruto_venenoso");
    if (fruto->move(TP) != ME_OK)
    {
        write("Intentas coger un fruto, pero se te resbala y cae al suelo.\n");
        say(CAP(TNAME) + " intenta coger un fruto del árbol, pero se le resbala, "
            "cayendo al suelo.\n");
        fruto->move(TO);
    }
    else
    {
        write("Coges un fruto del árbol.\n");
        say(CAP(TNAME) + " coge un fruto del árbol.\n");
    }
    PFrutos--;
    return 1;
}


create()
{
    ::create();
    PFrutos = MAX_FRUTOS;
    SetIntLong("Has venido a parar a la costa occidental de la isla, donde "
               "las aguas del lago llegan casi hasta donde estás. Al borde del "
               "mismo, ves un árbol espinoso y de aspecto raquítico, que hunde "
               "sus raíces literalmente en las fétidas aguas.\n");

    AnadeDetalleLago("oeste");
    AddDetail(({"arbol", "árbol", "arbol espinoso", "árbol espinoso",
                "arbol raquítico", "árbol raquítico", "arbol raquitico",
                "árbol raquitico"}),
                (:"Se trata de un árbol de lo más extraño. Parece que solo tuviese "
                  "ramas y espinas, sin hoja alguna." + (PFrutos ? " En su parte "
                  "superior, sin embargo, observas que las espinas son sustituidas "
                  "por un fruto pequeño de color amarillo." :
                  " En su parte superior, observas restos de lo que parece algún tipo "
                  "de fruto. Sin embargo, por más que miras, no consigues ver "
                  "ninguno.") + "\n":));

    AddDetail(({"fruto","fruto amarillo", "fruto del árbol", "fruto del árbol"}),
              (:(!PFrutos ? "Puedes ver varias ramas en las que parece que "
                            "hubiese habido algún tipo de fruto. Sin embargo, "
                            "por más que miras, el árbol está totalmente pelado.\n":
                            "En la parte superior de este extraño árbol, puedes "
                            "ver varios frutos. Son pequeños y redondeados, de un color "
                            "amarillo intenso. Quizás podrías coger uno.\n"):));


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
