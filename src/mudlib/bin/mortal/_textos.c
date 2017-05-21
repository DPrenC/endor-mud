// Comando textos

int main(string str) {
    if (!str)
        return notify_fail("\t Textos descripción: para activar o desactivar la descripción "
        "de las rooms al moverte y, nombres de salidas y puertas completos o abreviados.\n"
        "\t Textos combate: para activar y desactivar los mensajes de combate abreviados.\n"
        "\t Textos especial: para activar y desactivar la impresión o anulación de algunos "
        "textos como los de adorno o sustitutos de colores. Recomendado cuando se usa lector de pantalla.\n");
  switch (str){
    case "combate":
      {
        if (TP->SetCombateBreve(!(TP->QueryCombateBreve())))
        write("Activados los mensajes de combate abreviados.\n");
    else write("Desactivado los mensajes de combate abreviados.\n");
    return 1;
  }
    break;
  case "descripción":
        case "descripcion":
            case "descripciones":
                {
    if (TP->SetBrief(!TP->QueryBrief()))
        write("Desactivadas las descripciones de las rooms al moverte. Los "
        "nombres de salidas y puertas serán abreviados.\n");
    else
        write("activadas las descripciones de las rooms al moverte. Los nombres "
        "de salidas y puertas se mostrarán completos.\n");
    return 1;
  }
  break;
    case "especial":
    case "especiales":
 if (TP->QueryTiflo()) {
    TP->SetTiflo(0);
    write("Desactivado el modo de textos especiales.\n");
    return 1;
  }else{
    TP->SetTiflo(1);
    write("Activado el modo de textos especiales.\n");
    return 1;
  }
  break;
    default:
        write("\t Textos descripción: para activar o desactivar la descripción "
        "de las rooms al moverte y, nombres de salidas y puertas completos o abreviados.\n"
        "\t Textos combate: para activar y desactivar los mensajes de combate abreviados.\n"
        "\t Textos especial: para activar y desactivar la impresión o anulación de algunos "
        "textos como los de adorno o sustitutos de colores. Recomendado cuando se usa lector de pantalla.\n");
        break;
}
return 1;
}