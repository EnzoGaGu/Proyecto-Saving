#include "ControladorEnums.h"

string ControladorEnums::plataformaToString(EnumPlataforma plataforma){
    switch(plataforma){
        case EnumPlataforma::WINDOWS:
            return "WINDOWS";
        case EnumPlataforma::LINUX:
            return "LINUX";
        case EnumPlataforma::ANDROID:
            return "ANDROID";
        case EnumPlataforma::PS1:
            return "PS1";
        case EnumPlataforma::PS2:
            return "PS2";
        case EnumPlataforma::GAMECUBE:
            return "GAMECUBE";
        case EnumPlataforma::XBOX:
            return "XBOX";
    }
    
    return "";
}

EnumPlataforma ControladorEnums::stringToPlataforma(string plataforma){
    EnumPlataforma ePlataforma;

    if(plataforma == "WINDOWS"){
        ePlataforma = EnumPlataforma::WINDOWS;
    }
    else if(plataforma == "LINUX"){
        ePlataforma = EnumPlataforma::LINUX;
    }
    else if(plataforma == "ANDROID"){
        ePlataforma = EnumPlataforma::ANDROID;
    }
    else if(plataforma == "PS1"){
        ePlataforma = EnumPlataforma::PS1;
    }
    else if(plataforma == "PS2"){
        ePlataforma = EnumPlataforma::PS2;
    }
    else if(plataforma == "GAMECUBE"){
        ePlataforma = EnumPlataforma::GAMECUBE;
    }
    else if(plataforma == "XBOX"){
        ePlataforma = EnumPlataforma::XBOX;
    }

    return ePlataforma; 
}

string ControladorEnums::fuenteToString(EnumFuente fuente){
    switch(fuente){
        case EnumFuente::PC:
            return "PC";
        case EnumFuente::CONSOLA:
            return "CONSOLA";
        case EnumFuente::CELULAR:
            return "CELULAR";
    }

    return "";
}

EnumFuente ControladorEnums::stringToFuente(string fuente){
    EnumFuente plataformaFuente; 

    if(fuente == "PC"){
        plataformaFuente = EnumFuente::PC;
    }
    else if(fuente == "CONSOLA"){
        plataformaFuente = EnumFuente::CONSOLA;
    }
    else if(fuente == "CELULAR"){
        plataformaFuente = EnumFuente::CELULAR;
    }

    return plataformaFuente; 
}

string ControladorEnums::tipoDatoToString(EnumTipoDato tipoDato){
    switch(tipoDato){
        case EnumTipoDato::CONFIG:
            return "CONFIG";
        case EnumTipoDato::PARTIDA:
            return "PARTIDA";
    }

    return "";
}

EnumTipoDato ControladorEnums::stringToTipoDato(string tipoDato){
    EnumTipoDato eTipoDato; 

    if(tipoDato == "PARTIDA"){
        eTipoDato = EnumTipoDato::PARTIDA;
    }
    else if(tipoDato == "CONFIG"){
        eTipoDato = EnumTipoDato::CONFIG;
    }

    return eTipoDato; 
}