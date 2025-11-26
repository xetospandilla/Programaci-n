#include <iostream>
#include <list>
using namespace std;

double ult(double list[], int cuantos){
 
 int i = cuantos -1;
 double *p = &list[i];
 
 double ult_valor = *p;

 cout << "El último punto es: " << ult_valor << endl;
 return ult_valor;
}

int main(){
 double list[] = {0.0,0.1,0.2,0.3,0.4};
 
 if(ult(list, 5) == 0.4){
  cout << "Todo ok.";
 }else{
  cout << "Me cago en tus muertos.";
 }

 return 0;
}