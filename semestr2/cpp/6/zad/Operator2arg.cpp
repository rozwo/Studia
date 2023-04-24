#include "Operator2arg.hpp"

int Dod::priorytet() {
    return DOD;
}

double Dod::oblicz() {
    return this->operand1->oblicz() + this->operand2->oblicz();
}

string Dod::zapis() {  
    string lewa, prawa; 
    if(this->operand1->priorytet() >= DOD)
    {
        lewa = "(" + this->operand1->zapis() + ")";
    } 
    else
    {
        lewa = this->operand1->zapis();
    }
    if(this->operand2->priorytet() >= DOD)
    {
        prawa = "(" + this->operand2->zapis() + ")";
    } 
    else
    {
        prawa = this->operand2->zapis();
    }
    return lewa + " + " + prawa;
}

int Odej::priorytet() {
    return ODEJ;
}

double Odej::oblicz() {
    return operand1->oblicz() - operand2->oblicz();
}

string Odej::zapis() {
    string lewa, prawa; 
    if(this->operand1->priorytet() >= ODEJ)
    {
        lewa = "(" + this->operand1->zapis() + ")";
    } 
    else
    {
        lewa = this->operand1->zapis();
    }
    if(this->operand2->priorytet() >= ODEJ)
    {
        prawa = "(" + this->operand2->zapis() + ")";
    } 
    else
    {
        prawa = this->operand2->zapis();
    }
    return lewa + " - " + prawa;
}

int Mnoz::priorytet() {
    return MNOZ;
}

double Mnoz::oblicz() {
    return this->operand1->oblicz() * this->operand2->oblicz();
}

string Mnoz::zapis() {
    string lewa, prawa; 
    if(this->operand1->priorytet() >= MNOZ)
    {
        lewa = "(" + this->operand1->zapis() + ")";
    } 
    else
    {
        lewa = this->operand1->zapis();
    }
    if(this->operand2->priorytet() >= MNOZ)
    {
        prawa = "(" + this->operand2->zapis() + ")";
    } 
    else
    {
        prawa = this->operand2->zapis();
    }
    return lewa + " * " + prawa;
}

int Dziel::priorytet() {
    return DZIEL;
}

double Dziel::oblicz() {
    double licznik = this->operand1->oblicz();
    double mianownik = this->operand2->oblicz();
    if(mianownik == 0)
    {
        throw invalid_argument("Dzielisz przez zero!");
    }
    else
    {
        return licznik / mianownik;
    }
}

string Dziel::zapis() {
    string lewa, prawa; 
    if(this->operand1->priorytet() >= DZIEL)
    {
        lewa = "(" + this->operand1->zapis() + ")";
    } 
    else
    {
        lewa = this->operand1->zapis();
    }
    if(this->operand2->priorytet() >= DZIEL)
    {
        prawa = "(" + this->operand2->zapis() + ")";
    } 
    else
    {
        prawa = this->operand2->zapis();
    }
    return lewa + " / " + prawa;
}

int Mod::priorytet() {
    return MOD;
}

double Mod::oblicz() {
    double liczba = this->operand1->oblicz();
    double dzielnik = this->operand2->oblicz();
    if(dzielnik == 0)
    {
        throw invalid_argument("Dzielisz przez zero! (modulo zero)");
    }
    else
    {
        int x = liczba / dzielnik;
        return liczba - (x * dzielnik);
    }
}

string Mod::zapis() {
    string lewa, prawa; 
    if(this->operand1->priorytet() >= MOD)
    {
        lewa = "(" + this->operand1->zapis() + ")";
    } 
    else
    {
        lewa = this->operand1->zapis();
    }
    if(this->operand2->priorytet() >= MOD)
    {
        prawa = "(" + this->operand2->zapis() + ")";
    } 
    else
    {
        prawa = this->operand2->zapis();
    }
    return lewa + " mod " + prawa;
}

int Log::priorytet() {
    return 0;
}

double Log::oblicz() {
    double baza = this->operand1->oblicz();
    double argument = this->operand2->oblicz();
    try 
    {
        return log(argument) / log(baza); //korzystam ze wzoru ze log[a](b) (gdzie a to baza a b to arg)
    }                                     //jest rowne log(b)/log(a) (czyli ln(b)/ln(a))
    catch (invalid_argument exc)
    {
        throw exc;
    }
}

string Log::zapis() {
    return "log[" + this->operand1->zapis() + "](" + this->operand2->zapis() + ")";
}


int Pot::priorytet() {
    return POT;
}

double Pot::oblicz() {
    return pow(this->operand1->oblicz(), this->operand2->oblicz());
}

string Pot::zapis() {
    string lewa, prawa; 
    if(this->operand1->priorytet() >= POT)
    {
        lewa = "(" + this->operand1->zapis() + ")";
    } 
    else
    {
        lewa = this->operand1->zapis();
    }
    if(this->operand2->priorytet() >= POT)
    {
        prawa = "(" + this->operand2->zapis() + ")";
    } 
    else
    {
        prawa = this->operand2->zapis();
    }
    return lewa + " ^ " + prawa;
}
