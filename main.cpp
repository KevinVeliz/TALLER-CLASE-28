#include <iostream>
#include <fstream>
using namespace std;

const int N=10;
int mitad(int arr[], int pinicial, int pfinal);
void ordenar(int arr[], int pinicial, int pfinal);

int main() 
{
  char r;
  ofstream archivo;
  string datos;
  cout << "Ingrese el nombre del archivo: ";
  getline(cin,datos);
  archivo.open(datos.c_str(),ios::app);

  do{
    
    int A[N];
    for (int i=0; i<N ; i++){
      cout << "Ingrese arreglo en la posicion[" << i <<"]: ";
      cin >> A[i];
    }

    cout << "Arreglo original\n" ;
    archivo << "Arreglo original\n" ;
    for(int i=0; i<10; i++)
    {
      cout << "|" << A[i] << "|";
      archivo << "|" << A[i] << "|";
    }
    cout << endl;

    ordenar(A, 0, 9);
    cout << endl;
    cout << "Arreglo ordenado\n";
    archivo << "\nArreglo ordenado\n";
    for(int i=0; i<10; i++)
    {
      cout << "|" << A[i] << "|";
      archivo << "|" << A[i] << "|";
    }
    archivo << "\nAlgoritmo de ordenamiento utilizado es: QUICKSORT" << endl;
    cout<<"\nDESEA AGREGAR OTRO DATO s/n: ";
    cin>>r;
    cin.ignore();
  }while(r=='s');
}

int mitad(int arr[], int pinicial, int pfinal){

  return arr[(pinicial + pfinal)/2];
}

void ordenar(int arr[], int pinicial, int pfinal){

  int i = pinicial;
  int j = pfinal;
  int temp;
  int piv = mitad(arr, pinicial, pfinal);

  do{

    while(arr[i] < piv){
      i++;
    }

    while(arr[j] > piv){
      j--;
    }

    if(i <= j){
      temp = arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
      i++;
      j--;
    }

  }while(i <= j);

  if(pinicial < j){
    ordenar(arr, pinicial, j);
  }
  if(i < pfinal){
    ordenar(arr, i, pfinal);
  }
}