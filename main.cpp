#include <iostream>
#include <stdlib.h>
#include <cmath>


using namespace std;

class cFormulas
{
    public:

//    float Sumatoria(float l, float m, float s)
//    {
//        float lam = l;
//        float mi = m;
//        float ser = s;
//
//        float sum = 0, PO=0;
//
//        for(int n = 0; n <= ser-1; n++)
//        {
//            sum = sum + (pow((lam/mi),n)/1);
//        }
//
//        PO = 1/(sum+(pow((lam/mi),ser)/2)*((1/(1-(lam/(ser*mi))))));
//        cout<<"PO: "<<PO<<endl;
//    }

    float FPo(float l, float m, int s)
    {
        float lam = l;
        float mi = m;
        int ser = s;

        float sum = 0, PO=0;

        for(int loop = 0; loop <= ser-1; loop++)
        {
        //cout<<"*****VALOR SUM: "<<sum<<"****VALOR LOOP: "<<loop<<endl;

            sum = sum + ((pow((lam/mi),loop))/(Factorial(loop)));
            cout<<"*****VALOR SUM: "<<sum<<"****VALOR LOOP: "<<loop<<"///POW FUN: "<<pow((lam/mi),loop)<<endl;
        }

        PO = 1/(sum+((pow((lam/mi),ser)/Factorial(ser))*((1/(1-(lam/(ser*mi)))))));
        cout<<"PO: "<<PO<<endl;
        return PO;
    }

    int Factorial(int num)
    {
        int numC = num;

        if(numC == 0)
        {
            return 1;
        }
        else if(numC == 1)
        {
            return 1;
        }
        else
        {
            return numC * Factorial(numC - 1);
        }
    }

    float FLS(float l, float m, float s, float vPO)
    {
        float lam = l;
        float mi = m;
        float serv = s;
        float Po = vPO;
        float LS = 0;

        LS = ((lam * mi * (pow((lam/mi), serv)) * Po) / ((Factorial(serv - 1)) * (pow(((serv * mi) - lam), 2)))) + (lam/mi);

        cout<<LS<<endl;
        return LS;
    }

    float FWS(float ls, float l)
    {
        float vls = ls;
        float lam = l;
        float WS = 0;

        WS = (vls/lam);
        cout<<WS<<endl;
        return WS;

    }

    float FLq(float l, float m, float s, float po)
    {
        float lam = l;
        float mi = m;
        float serv = s;
        float vPo = po;
        float LQ = 0;

        LQ = vPo * ((pow((lam/mi), (serv + 1))) / (Factorial((serv - 1)) * (pow((serv - (lam/mi)), 2))));
        cout<<LQ<<endl;
        return LQ;
    }

    float FWq(float lq, float l)
    {
        float Lq = lq;
        float lam = l;
        float Wq = 0;

        Wq = (Lq/lam);

        cout<<Wq<<endl;
        return Wq;
    }

    float FCT(float lq, float cw, float s, float cs)
    {
        float Lq = lq;
        float Cw = cw;
        float serv = s;
        float Cs = cs;
        float CT = 0;

        CT = (Lq * Cw) + (serv * Cs);
        cout<<CT<<endl;
        return CT;
    }
};

int main()
{
    cFormulas obj;
    float l, m, vPO, ls, Lq, Wq, Cw, Cs;
    int opcSw, opc, s;
    do
    {
        cout<<"IO Unidad 4."<<endl;
        cout<<" 1.- Probabilidad de que ningun cliente se encuentre en el Sistema(PO)"<<endl;
        cout<<" 2.- Numero promedio de Unidades en el Sistema(LS)."<<endl;
        cout<<" 3.- Tiempo promedio en el que una unidad este dentro del sistema(WS)"<<endl;
        cout<<" 4.- Numero de Clientes en la Fila(Lq)"<<endl;
        cout<<" 5.- Tiempo de Espera en la Fila(Wq)"<<endl;
        cout<<" 6.- Costo Total(CT)"<<endl;
        cout<<" Opcion Deseada: ";
        cin>>opcSw;
        switch(opcSw)
        {
            case 1:
                cout << "Po" << endl;
                cout<<"Valor de 'Lambda': ";
                cin>>l;
                cout<<"Valor de 'M': ";
                cin>>m;
                cout<<"Cantidad de Servidores: ";
                cin>>s;
                vPO = obj.FPo(l, m, s);
                //obj.Factorial(s);
                    break;
            case 2:
                cout<<"Calcular LS"<<endl;
                ls = obj.FLS(l, m, s, vPO);
                break;
            case 3:
                cout<<"WS"<<endl;
                obj.FWS(ls, l);
                break;
            case 4:
                cout<<"Lq"<<endl;
                Lq = obj.FLq(l, m, s, vPO);
                break;
            case 5:
                cout<<"Wq"<<endl;
                obj.FWq(Lq, l);
                break;
            case 6:
                cout<<"Ingrese el Valor de Cw: ";
                cin>> Cw;
                cout<<"Ingrese el Valor de Cs: ";
                cin>>Cs;
                obj.FCT(Lq, Cw, s, Cs);
                break;
            default:
                break;
        }
        cout<<"Desea Continuar? 1/2:  ";
        cin>>opc;
    }while(opc != 2);
    return 0;
}
