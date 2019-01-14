#include <iostream> 

using namespace std;

class Kvadr {

  public:
    Kvadr(double x);
    Kvadr(double a, double b, double c);
    ~Kvadr(void);
    void vypisInfo(void);

  private:
    double hranaA, hranaB, hranaC;
    double povrch(void);
    double objem(void);
    bool jeKrychle(void);
};

Kvadr::Kvadr(double x){
  hranaA = hranaB = hranaC = x;
}

Kvadr::Kvadr(double a, double b, double c){
  hranaA = a;
  hranaB = b;
  hranaC = c;
}

Kvadr::~Kvadr(void){
  //empty
}

void Kvadr::vypisInfo(void){
  cout << "Hrana A: " << hranaA << endl;
  cout << "Hrana B: " << hranaB << endl;
  cout << "Hrana C: " << hranaC << endl;
  cout << "Povrch: " << povrch() << endl;
  cout << "Objem: " << objem() << endl;
  if(jeKrychle()){
    cout << "Jedna se o krychli." << endl;
  }
  else {
    cout << "Nejedna se o krychli." << endl;
  }
}

double Kvadr::povrch(void){
  return 2*((hranaA*hranaB)+(hranaA*hranaC)+(hranaB*hranaC));
}

double Kvadr::objem(void){
  return hranaA*hranaB*hranaC;
}

bool Kvadr::jeKrychle(void){
  if((hranaA==hranaB) && (hranaB == hranaC) && (hranaA == hranaC)){
    return true;
  }
  return false;
}

int main(int argc, char** argv) {

  Kvadr prvni(4,5,6);
  Kvadr druhy(5);

  prvni.vypisInfo();
  cout << endl << endl;
  druhy.vypisInfo();

  return (0);
}

