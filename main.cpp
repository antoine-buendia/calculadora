#include <iostream>
#include <conio.h> // para usar el getch
using namespace std;


struct complejo{  // Creo la estructura
	float real,imaginaria ; // Declaro  miembros
}n1,n2; // nombres de las variables a usar


//Prototipo de Función
void pedirDatos();
complejo suma(complejo,complejo); //funcion de retorno de nuemeros complejos resultante .por qeu tiene 2 partes
complejo resta(complejo,complejo); // funcion de retorno de nuemeros complejos resultante .por qeu tiene 2 partes
complejo multi(complejo,complejo);
complejo division(complejo,complejo);

//funcion pedir datos
void muestrasuma(complejo);
void muestraresta(complejo);
void muestramulti(complejo);
void muestradivision(complejo);


int main()
{
    int reset = 0;
    do{
    system("cls");
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "++                       CALCULADORA NUMEROS COMPLEJOS                    ++" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                                                                            " << endl;
    cout << "                                                                            " << endl;
    cout << "------------------------------   OPCIONES  ---------------------------------" << endl;
    cout << "--                   Suma   ------------------------->       Ingrese   1  --" << endl;
    cout << "--                  Resta   ------------------------->       Ingrese   2  --" << endl;
    cout << "--         Multiplicacion   ------------------------->       Ingrese   3  --" << endl;
    cout << "--               Division   ------------------------->       Ingrese   4  --" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

        int operacion;

        do{
            cout << "                                                                            " << endl;
            cout << "============================================================================" << endl;
            cout << "                 Ingrese un numero valido para operacion:                  " << endl;
            cout << "============================================================================" << endl;

            cin >> operacion;
        }while((operacion < 1) || (operacion > 4) ); // Limitado de 1-4 sino vuelve a preguntar
            switch(operacion){

                case 1:{
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "++                                  SUMA                                  ++" << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    pedirDatos(); // pide datos de la funcion pedir datos
                    complejo x = suma(n1,n2);
                    muestrasuma(x);
                }
                break;
                case 2:{
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "++                                  RESTA                                 ++" << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    pedirDatos(); // pide datos de la funcion pedir datos
                    complejo x = resta(n1,n2);
                    muestraresta(x);

                }
                break;
                case 3:{
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "++                             MULTIPLICACION                             ++" << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    pedirDatos(); // pide datos de la funcion pedir datos
                    complejo x = multi(n1,n2);
                    muestramulti(x);

                }
                break;
                case 4:{
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "++                                 DIVISION                               ++" << endl;
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    pedirDatos(); // pide datos de la funcion pedir datos
                    complejo x = division(n1,n2);
                    muestradivision(x);

                }
                break;
        }
        system("pause"); //PAUSA PARA MOSTRAR RESULTADO DE LA OPERACION
        system("cls"); // LIMPIAR LO REALIZADO
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "--             Para Continuar     ------------------->       Ingrese   1  --" << endl;
        cout << "--              Para Terminar     ------------------->       Ingrese   0  --" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cin >> reset;
    }while(reset == 1);
    getch(); //pausar para mostrar 
    return 0;
}


void pedirDatos(){
	cout<<"\n                    Digite el primer numero complejo: "                       <<endl;
	cout<<"Parte Real: "; cin>>n1.real;
	cout<<"Parte Imaginaria: "; cin>>n1.imaginaria;
	
	cout<<"\n		    Digite el segundo numero complejo: "					   <<endl;
	cout<<"Parte Real: "; cin>>n2.real;
	cout<<"Parte Imaginaria: "; cin>>n2.imaginaria;
}

//hallar las operaciones con los datos ingresados
complejo suma(complejo n1,complejo n2){
	complejo s;
	s.real = n1.real + n2.real;
	s.imaginaria = n1.imaginaria + n2.imaginaria;
	return s; // n1 contiene 2 parametros , la parte real y parte imagnario
}
complejo resta(complejo n1,complejo n2){
	complejo r;
	r.real = n1.real - n2.real;
	r.imaginaria = n1.imaginaria - n2.imaginaria ;
	return r;
}
complejo multi(complejo n1,complejo n2){
	complejo m;
	m.real = (n1.real * n2.real) + ((n1.imaginaria * n2.imaginaria) * - 1 );
	m.imaginaria= (n1.real * n2.imaginaria) + (n1.imaginaria * n2.real);
	return m;
}
complejo division(complejo n1,complejo n2){
	complejo d;
	float  den;
	den = n2.real * n2.real + n2.imaginaria * n2.imaginaria; // creamos la variable para el denominador
	d.real = ((n1.real * n2.real) + (n1.imaginaria * n2.imaginaria)) / den;
	d.imaginaria = ((-n1.real * n2.imaginaria) + (n1.imaginaria * n2.real)) / den;
	return d;
}

void muestrasuma(complejo x){
	cout<<"\nLa Suma es: "<<x.real<<" , "<<x.imaginaria<<"i"<<endl; // concatenamos la i al munero complejo de respuesta
}
void muestraresta(complejo x){
	cout<<"\nLa Resta es: "<<x.real<<" , "<<x.imaginaria<<"i"<<endl;
}
void muestramulti(complejo x){
	cout<<"\nLa Multiplicacion es: "<<x.real<<" , "<<x.imaginaria<<"i"<<endl;
}
void muestradivision(complejo x){
	cout<<"\nLa Division es: "<<x.real<<" , "<<x.imaginaria<<"i"<<endl;
}


