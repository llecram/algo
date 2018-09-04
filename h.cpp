#include <iostream>
//#include <stdio.h>
#include <ctime>

bool asc(int *a, int *b){
  return *(a)>*(b);
}
bool dsc(int *a, int *b){
  return *(a)<*(b);
}
void imprimir(int *S, int tam){
  for(int i=0;i<=tam;++i){
    std::cout<<*S<<" ";
    ++S;
  }
}
void burbuja(int *S,int *fin, bool (*p)(int *a, int *b)){
  bool camb=true;
  while(camb){
    int *coureur=S;
    camb=false;
    for(;coureur<fin;++coureur){
      if(p(coureur,(coureur+1))){
          int temp=*coureur;
  	  *coureur=*(coureur+1);
  	  *(coureur+1)=temp;
          camb=true;
      }
    }
    --fin;
  }


}
//-“¿Que caracteriza a las regiones más pobres del país?”
//-”¿Cual es la causa más común de pobreza en el país?”
//-”¿Cual es la causa de que la pobreza monetaria del país //creciera por primera vez en el milenio?”

int main(){
  bool (*p)(int *a, int *b)=asc;
  int *lista=new int[100];
  int *coureur=lista;
  for(int i=100;i>-1;--i){
    *coureur=i;
    ++coureur;
  }
  //imprimir(lista,100);
  unsigned t0;
  unsigned t1;
  t0=clock();
  burbuja(lista,(lista+100),p);
  t1=clock();
  std::cout<<t1;
  double time=(double(t1-t0)/CLOCKS_PER_SEC);
  std::cout<<"Execution time: "<<time<<std::endl;
  //imprimir(lista,100);
  return 0;
}
