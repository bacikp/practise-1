#include <iostream>
#include <math.h>

using namespace std;

class Trojuhelnik {

  public:
    Trojuhelnik(double x);
    Trojuhelnik(double a, double b, double c);
    ~Trojuhelnik(void);
    void vypisInfo(void);

  private:
    double strA, strB, strC;
    double obvod(void);
    double obsah(void);
    bool jePravouhly(void);
    bool jeRovnostranny(void);
};

Trojuhelnik::Trojuhelnik(double x){
  strA = strB = strC = x;
}

Trojuhelnik::Trojuhelnik(double a, double b, double c){
  if(((a+b)>c) && ((a+c)>b) && ((b+c)>a)){ 
    strA = a;
    strB = b;
    strC = c;
  }
  else{
    throw 1;
  }
}

Trojuhelnik::~Trojuhelnik(void){
  //empty
}

void Trojuhelnik::vypisInfo(void){
  cout << "Strana A:" << strA << endl;
  cout << "Strana B:" << strB << endl;
  cout << "Strana C:" << strC << endl;
  cout << "Obvod:" << obvod() << endl;
  cout << "Obsah:" << obsah() << endl;
  if(jePravouhly()){
    cout << "Trojuhelnik je pravouhly." << endl;
  }
  else {
    cout << "trojuhelnik neni pravouhly" << endl;
  }
  if(jeRovnostranny()){
    cout << "Trojuhelnik je rovnostranny." << endl;
  }
  else {
    cout << "Trojuhelnik neni rovnostranny." << endl;
  }
}

double Trojuhelnik::obvod(void){
  return strA+strB+strC;
}

double Trojuhelnik::obsah(void){
  double s;
  s = (strA+strB+strC)/2;
  
  return sqrt(s*(s-strA)*(s-strB)*(s-strC));
}

bool Trojuhelnik::jePravouhly(void){
  int i;
  double temp;
  double strany[3];
  strany[0]=strA;
  strany[1]=strB;
  strany[2]=strC;
  for(i=0;i<2;i++){
    if(strany[i]>strany[i+1]){
      temp=strany[i+1];
      strany[i+1]=strany[i];
      strany[i]=temp;
    }
  }
  if((strany[0]*strany[0])+(strany[1]*strany[1])==(strany[2]*strany[2])){
    return true;
  }
  else{
    return false;
  }
}

bool Trojuhelnik::jeRovnostranny(void){
  if((strA==strB) && (strB==strC) && (strA==strC)){
    return true;
  }
  else {
    return false;
  }
}

int main(int argc, char** argv) {

  try {
    Trojuhelnik t1(3,4,5);
    Trojuhelnik t2(5);
    Trojuhelnik t3(3,4,6);
//    Trojuhelnik t4(100,1,1);

    t1.vypisInfo();
    cout << endl;
    t2.vypisInfo();
    cout << endl;
    t3.vypisInfo();
    cout << endl;
//    t4.vypisInfo();
  }
  catch(int e){
    cout << "zadane strany nemohou tvorit trojuhelnik" << endl;
  }


  return (0);
}

