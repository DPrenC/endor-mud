/* SIMAURIA '/std/thing/restrictions.c'
   ====================================
*/

//--- global variables ------------------------------------------------------

private int pWeight = 0; // Mi peso

//--- weight handling of a thing --------------------------------------------

/**
 * Devuelve lo que pesa el objeto.
 * Tiene que ser varargs porque en contenedores QueryWeight() devuelve el
 * peso total, pero QueryWeight(1) devuelve solo el peso de this_object sin
 * sumar lo que contiene.
 */
public varargs int QueryWeight() {
    return pWeight;
}

public int SetWeight(int w) {
  if(!environment() || environment()->MayAddIntWeight(w - pWeight))
  {
    if (environment()) environment()->AddIntWeight(w - pWeight);
    pWeight = w;
  }
  return pWeight;
}

/**
 * Devuelve lo máximo que puede llegar a pesar un objeto
 * Se sobrecarga en el container...
 */
public int QueryMaxWeight() {
    return pWeight;
}

//---------------------------------------------------------------------------
