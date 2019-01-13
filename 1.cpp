#include <iostream> 
#include <string>

using namespace std;

class BednaVina {

  public:
    BednaVina(string i_nazevTypuBedny, int i_pocetLahvi, double i_objemJedneLahve);
    ~BednaVina(void);
    void prehled(void);
    void porovnejObjem(BednaVina & jinaBedna);

  protected:
    string nazevTypuBedny;
    int pocetLahvi;
    double objemJedneLahve;

};

BednaVina::BednaVina(string i_nazevTypuBedny, int i_pocetLahvi, double i_objemJedneLahve){
  nazevTypuBedny=i_nazevTypuBedny;
  pocetLahvi=i_pocetLahvi;
  objemJedneLahve=i_objemJedneLahve;
}

BednaVina::~BednaVina(void){
  //empty
}

void BednaVina::prehled(void){
  cout << "bedna typu: " << nazevTypuBedny << ", objem: " << pocetLahvi * objemJedneLahve << " litru" << endl;
  return;
}

void BednaVina::porovnejObjem(BednaVina & jinaBedna){
  if((pocetLahvi*objemJedneLahve)>(jinaBedna.pocetLahvi*jinaBedna.objemJedneLahve)){
    cout << "bedna typu: " << nazevTypuBedny << " je vetsi nez: " << jinaBedna.nazevTypuBedny << endl;
  }
  else if((pocetLahvi*objemJedneLahve)<(jinaBedna.pocetLahvi*jinaBedna.objemJedneLahve)){
    cout << "bedna typu: " << nazevTypuBedny << " je mensi nez: " << jinaBedna.nazevTypuBedny << endl;
  }
  else {
    cout << "bedna typu: " << nazevTypuBedny << " je stejne velka jako bedna typu: " << jinaBedna.nazevTypuBedny << endl;
  }
}

int main(int argc, char** argv) {

  BednaVina prvni("mala", 8, 0.7);
  BednaVina druha("stredni", 15, 1.0);
  BednaVina treti("velka", 20, 1.5);

  prvni.prehled();
  druha.prehled();
  treti.prehled();

  prvni.porovnejObjem(druha);
  prvni.porovnejObjem(treti);

  druha.porovnejObjem(prvni);
  druha.porovnejObjem(treti);

  treti.porovnejObjem(prvni);
  treti.porovnejObjem(druha);

  return (0);
}
