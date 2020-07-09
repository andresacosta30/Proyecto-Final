#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
 using namespace std;
int main(){
 char pronm[20];
 char pronm2[20];
 char pronm3[20];
 char pronm4[20];
 char pronm5[20];
 int pronmvl=10,pronmvl2=9,pronmvl3=10,pronmvl4=20,pronmvl5=10,opc,unit,unit2,unit3,unit4,unit5,totaliva,total,iva;
 char fecha[25];//ctime devuelve 26 caracteres
 int subtotal,suma;
 float a1,a2,a3,a4,a5,prctot1,prctot2,prctot3,prctot4,prctot5;
 cout<<"TIENDA ACOSTA"<<endl;
 cout<<"Nombre del producto1: "<<endl;//Empieza a elegir los productos MAXIMO DE 5 PRODUCTOS
 cin>>pronm;
 cout<<"Cuantas unidades llevara: "<<endl;
 cin>>unit;
 cout <<"Costo de cada unidad: "<<endl;
 cin>>a1;
 cout<<"Nombre del producto2: "<<endl;
 cin>>pronm2;
 cout<<"Cuantas unidades llevara: "<<endl;
 cin>>unit2;
 cout <<"Costo de cada unidad: "<<endl;
 cin>>a2;
 cout<<"Nombre del producto3: "<<endl;
 cin>>pronm3;
 cout<<"Cuantas unidades llevara: "<<endl;
 cin>>unit3;
 cout <<"Costo de cada unidad: "<<endl;
 cin>>a3;
 cout<<"Nombre del producto4: "<<endl;
 cin>>pronm4;
 cout<<"Cuantas unidades llevara: "<<endl;
 cin>>unit4;
 cout <<"Costo de cada unidad: "<<endl;
 cin>>a4;
 cout<<"Nombre del producto5: "<<endl;
 cin>>pronm5;
 cout<<"Cuantas unidades llevara: "<<endl;
 cin>>unit5;
 cout <<"Costo de cada unidad: "<<endl;
 cin>>a5;
 cout<<"imprimiendo ticket..."<<endl;
	prctot1=unit*a1;
	prctot2=unit2*a2;
	prctot3=unit3*a3;
	prctot4=unit4*a4;
	prctot5=unit5*a5;
	/* fecha/hora actual basado en el sistema actual */
time_t now = time(0);
/* Objeto de una estructura tm con fecha/hora local */
tm * time = localtime(&now);
vector<string> dia_semana;
dia_semana.push_back("Domingo");
dia_semana.push_back("Lunes");
dia_semana.push_back("Martes");
dia_semana.push_back("Miercoles");
dia_semana.push_back("Jueves");
dia_semana.push_back("Viernes");
dia_semana.push_back("Sabado");
vector<string> mes;
mes.push_back("Enero");
mes.push_back("Febrero");
mes.push_back("Marzo");
mes.push_back("Abril");
mes.push_back("Mayo");
mes.push_back("Junio");
mes.push_back("Julio");
mes.push_back("Agosto");
mes.push_back("Septiembre");
mes.push_back("Octubre");
mes.push_back("Noviembre");
mes.push_back("Diciembre");
int year = 1900 + time->tm_year;
	subtotal=prctot1+prctot2+prctot3+prctot4+prctot5;
	iva=subtotal*.16;
	totaliva=subtotal+iva;
	ofstream fichout ("ticket.txt",ios::out);
	if(!fichout){
		cout<<"NO se pudo generar el archivo de texto"<<endl;
	}
	else{
		fichout<<"TIENDA ACOSTA"<<endl;
		fichout<<"***TICKET DE COMPRA***"<<endl;
		fichout<<"("<<unit<<")"<<"  De "<<pronm<<"-----"<<"$"<<prctot1<<endl;
		fichout<<"("<<unit2<<")"<<"  De "<<pronm2<<"-----"<<"$"<<prctot2<<endl;
		fichout<<"("<<unit3<<")"<<"  De "<<pronm3<<"-----"<<"$"<<prctot3<<endl;
		fichout<<"("<<unit4<<")"<<"  De "<<pronm4<<"-----"<<"$"<<prctot4<<endl;
		fichout<<"("<<unit5<<")"<<"  De "<<pronm5<<"-----"<<"$"<<prctot5<<endl;
		fichout<<"SUBTOTAL ----"<<"$"<<subtotal<<".00"<<endl;
		fichout<<"IVA ----"<<"$"<<iva<<".00"<<endl;
		fichout<<"TOTAL+IVA ----"<<"$"<<totaliva<<".00"<<endl;
		fichout <<"FECHA DE COMPRA " << dia_semana[time->tm_wday] << ", ";
		fichout << time->tm_mday << " DE " << mes[time->tm_mon] << " DEL " << year << endl;
		fichout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
		fichout<<"Le atendio Andres Acosta"<<endl;
	fichout.close();
	}
}