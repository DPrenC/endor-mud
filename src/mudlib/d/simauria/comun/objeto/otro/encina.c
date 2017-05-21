/***
Fichero: Encina.c
Autor: [ztico].
Creación: 04-03-05.
07-03-05: [kastwey]: Retoco un par de cosillas.
***/



inherit THING;

string leer();

public create()
{
    ::create();

    SetShort("una encina");
    SetLong(W("Es una espléndida y corpulenta encina cuyo grueso tronco invita a apoyarse en él "
         "y descansar. Las ramas cubiertas de magníficas hojas verdes y brillantes proporcionan "
         "sombra a toda la plaza ofreciendo cobijo a los cansados caminantes. Viéndola, percibes "
         "una sensación muy especial, como si de su interior brotara una poderosa energía que te "
         "llena de paz. Sientes que el árbol te está transmitiendo un mensaje. Fijándote con  "
         "atención, descubres una talla en la corteza que quizás puedas leer.\n"));
    SetIds(({"arbol","árbol","encina","la encina","Encina","La encina"}));
    SetNoGet("Está fuertemente sujeta al suelo, es imposible que la puedas coger.\n");
    AddSubReadMsg(({"talla","la talla","inscripcion","inscripción"}),SF(leer));
}

string leer()
{
    say(CAP(TNAME) + " lee la talla de la encina.\n",TP);
    return
       W("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
         "     Al mayor Andross Corazón de León, guerrero verdadero que supo luchar por la vida con valor,\n"
         "     derrochando amistad y  compañerismo durante el breve tiempo que pasó entre nosotros. Por su\n"
         "     coraje,  por su simpatía, por su  constancia  y por su generosidad. Siempre te recordaremos.\n"
         "\n"
         "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
}

