#include<iostream>
#include<stdio.h>

class asc{
  public:
    inline bool operator()(int *a, int *b){return *(a)>*(b);}
};
class dsc{
  public:
    inline bool operator()(int *a, int *b){return *(a)<*(b);}
};
template<class T>
class Sort{
  public:
    T commande;
    void burbuja(int *S,int *fin){
 	 bool camb=true;
  	while(camb){
    		int *coureur=S;
    		camb=false;
    		for(;coureur<fin;++coureur){
      			if(commande(coureur,(coureur+1))){
          		int temp=*coureur;
  	  		*coureur=*(coureur+1);
  	  		*(coureur+1)=temp;
         		 camb=true;
      			}
    		}
    		--fin;
    	}	
    }
};
void imprimir(int *S, int *fin){
   for(int *i=S;i<=fin;++i){
	std::cout<<*i<<" ";
   }
   std::cout<<std::endl;
}

int main(){
    Sort<asc> test;
    int *lista=new int[11];
    int e=0;
    for(int i=11;i>-1;--i){
	lista[e]=i;++e;
    }
    imprimir(lista,lista+11);
    test.burbuja(lista,lista+11);
    imprimir(lista,lista+11);
}
