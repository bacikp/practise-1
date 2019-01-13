#include <iostream> 
#include <string>

using namespace std;

class Policista {

  public:
    Policista(string i_jmeno, string i_hodnost, double i_plat);
    ~Policista(void);
    void setPartak(Policista * jinyPolicista);
    void vypis(void);

  protected:
    string jmeno;
    string hodnost;
    double plat;
    Policista * partak;

};

Policista::Policista(string i_jmeno, string i_hodnost, double i_plat){
  jmeno=i_jmeno;
  hodnost=i_hodnost;
  plat=i_plat;
  partak=NULL;
}

Policista::~Policista(void){
  //empty
}

void Policista::setPartak(Policista * jinyPolicista){
  partak=jinyPolicista;
}

void Policista::vypis(void){
  cout << "policista: " << hodnost << " " << jmeno << endl;
  if(partak!=NULL){
    cout << "partak: " << partak->hodnost << " " << partak->jmeno << endl;
  }
  else {
    cout << "partak: neznamy/a" << endl;
  }
}


int main(int argc, char** argv) {

  Policista prvni("Pepa Novak", "maj.", 18000.0);
  Policista druhy("Franta Siska", "gen.", 23000.0);
  Policista treti("Fanfan Tulipan", "por.", 20000.0);

  prvni.setPartak(&druhy);

  prvni.vypis();
  treti.vypis();

  return (0);
}
