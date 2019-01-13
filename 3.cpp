#include <iostream> 
#include <string>

using namespace std;

class Prvek {
  
  public:
    Prvek(string a);
    Prvek(string a, int b);
    ~Prvek(void);

    Prvek * next;
    string slovo;
    int cislo;

};

Prvek::Prvek(string a){
  slovo = a;
  cislo = -1;
  next = NULL;
}

Prvek::Prvek(string a, int b){
  slovo = a;
  cislo = b;
  next = NULL;
}

Prvek::~Prvek(void){
  //empty
}

class Kolecko {
  
  public:
    Kolecko(void);
    ~Kolecko(void);
    void pridej(Prvek * prvek);
    void rotuj(int i);

  private:
    Prvek * first;
    Prvek * last;

};

Kolecko::Kolecko(void){
  first=NULL;
  last=NULL;
}

Kolecko::~Kolecko(void){
  //empty
}

void Kolecko::pridej(Prvek * prvek){
  if(first == NULL){
    first = prvek;
    last = prvek;
    last->next = NULL;
  }
  else{
    last->next=prvek;
    last=prvek;
    last->next=NULL;
  }
}

void Kolecko::rotuj(int i){
  int j;
  Prvek * vypis;
  vypis = first;
  
  if(first==NULL){
    cout << "kolecko je prazdne" << endl;
  }

  for(j=0;j<i;j++){
    cout << "slovo: " << vypis->slovo << endl;
    if(vypis->cislo!=-1){
      cout << "cislo: " << vypis->cislo << endl << endl;
    }
    else{
      cout << "cislo: nenastaveno" << endl << endl;
    }
    if(vypis->next==NULL){
      vypis=first;
    }
    else{
      vypis=vypis->next;
    }
  }
}

int main(int argc, char** argv) {

  Kolecko k;
  
  Prvek prvni("kamen", 1);
  Prvek druhy("voda");
  Prvek treti("vzduch", 6);
  Prvek ctvrty("ohen", 90);

  k.pridej(&prvni);
  k.pridej(&druhy);
  k.pridej(&treti);
  k.pridej(&ctvrty);

  k.rotuj(3);
  cout << endl << endl;
  k.rotuj(9);

  return (0);
}

