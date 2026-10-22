#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Binario
{
    private:
    
    double binario;
    
    string binarioConvertir(char c, int base) {
        int valor = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
        int bits = log2(base);
        string bin = "";
        for(int i=0; i<bits; i++) {
            bin += (valor & (1<< (bits - 1 - i))) ? '1' : '0';
        }
        return bin;
    }
    //Binario a otra base
    char binarioAbase(const string& bits) {
        int valor = 0;
        for(char b : bits) {
            valor = valor * 2 + (b - '0');
        }
        if (valor < 10) return char('0' + valor);
        else return char('A' + (valor - 10));
    }
    
    public:
    
    string convertir(const string& n, int base, int baseConvertir) {
        string binario = "";
        //Convertir los digitos en binario
        for(char c : n) {
            if(c == '.') { binario += '.'; continue;
            }
            binario += binarioConvertir(c, base);
        }
        
        int grupo = log2(baseConvertir);
        string resultado = "";
        string parteEntera = binario;
        string parteFrac = "";
        
        size_t punto = binario.find('.');
        if(punto != string::npos) {
            parteEntera = binario.substr(0, punto);
            parteFrac = binario.substr(punto + 1);
        }
        
        while (parteEntera.size() % grupo != 0) parteEntera = "0" + parteEntera;
        for(size_t i=0; i<parteEntera.size(); i+=grupo) {
            resultado += binarioAbase(parteEntera.substr(i, grupo));
        }
        
        if(!parteFrac.empty()) {
            resultado += ".";
            while(parteFrac.size() % grupo != 0) parteFrac += "0";
            for(size_t i=0; i<parteFrac.size(); i += grupo) {
                resultado += binarioAbase(parteFrac.substr(i, grupo));
            }
        }
        return resultado;
    }
};

class Decimal 
{
    private: 
    
    double toDecimal(const string& n, int deBase) {
        size_t punto = n.find('.');
        string parteEntera = (punto == string::npos) ? n : n.substr(0, punto);
        string parteFrac = (punto == string::npos) ? "" : n.substr(punto + 1);
        
        //Parte entera
        int valorEntero = 0;
        int potencia = 1;
        string revEntera = parteEntera;
        reverse(revEntera.begin(), revEntera.end());
        for(char c : revEntera) {
            int digito = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
            valorEntero += digito * potencia;
            potencia *= deBase;
        }
        
        //Parte fraccion
        double valorFrac = 0.0;
        double divisor = deBase;
        for(char c : parteFrac) {
            int digito = isdigit(c) ? c - '0' : toupper(c) - 'A' + 10;
            valorFrac += digito / divisor;
            divisor *= deBase;
        }
        return valorEntero + valorFrac;
    }
    
    //Convertir de decimal a otra base
    string deDecimal(double decimalA, int paraBase, int precision = 10) {
        //Parte entera
        int entero = (int)decimalA;
        string parteEntera = "";
        if(entero == 0) parteEntera = "0";
        while(entero>0) {
            int resto = entero % paraBase;
            parteEntera += (resto < 10) ? char('0' + resto) : char('A' + (resto - 10));
            entero /= paraBase;
        }
        reverse(parteEntera.begin(), parteEntera.end());
    
    double frac = decimalA - (int)decimalA;
    string parteFrac = "";
    for (int i=0; i<precision && frac > 0; i++) {
        frac *=paraBase;
        int digito = (int)frac;
        parteFrac += (digito < 10) ? char('0' + digito) : char('A' + (digito - 10));
        frac -= digito;
    }
    return parteFrac.empty() ? parteEntera : parteEntera + "." + parteFrac;
    }
    
    public:
    
    string convertir(const string& n, int base, int baseConvertir, int precision=10) {
        double valorDecimal = toDecimal(n, base);
        return deDecimal(valorDecimal, baseConvertir, precision);
    }
};

class Operacion
{
    public:
    
    //Convertir a decimal
    int valorDigito(char c)
    {
        if(isdigit(c))
            return c - '0';
        else
            return toupper(c) - 'A' + 10;
    }
    
    //Valor de un numero en hexadecimal
    char caracterDigito(int valor)
    {
        if(valor < 10)
            return char('0' + valor);
        else
            return char('A' + valor - 10);
    }
    
    //Convertir a decimal
    double aDecimal(string n, int base)
    {
        size_t punto = n.find('.');
        
        string parteEntera;
        string parteFraccionaria;
        
        if (punto == string::npos)
        {
            parteEntera = n;
            parteFraccionaria = "";
        }
        else 
        {
            parteEntera = n.substr(0, punto);
            parteFraccionaria = n.substr(punto + 1);
        }
        
        //Parte entera
        double resultado = 0;
        
        for (char c : parteEntera)
        {
            int digito = valorDigito(c);
            resultado = resultado * base + digito;
        }
        
        //Parte fraccionaria 
        double potencia = 1.0 / base;
        
        for (char c : parteFraccionaria)
        {
            int digito = valorDigito(c);
            resultado += digito * potencia;
            potencia /= base;
        }
        return resultado;
    }
    
    //De decimal a otra base
    string desdeDecimal(double numero, int base, int precision = 10)
    {
        if(numero == 0)
            return "0";
            
        string resultado = "";
        
        //Signo
        if (numero < 0)
        {
            resultado += "-";
            numero = -numero;
        }
        
        //Parte entera
        long long entero = (long long)numero;
        string parteEntera = "";
        if (entero == 0)
        {
            parteEntera = "0";
        }
        else
        {
            while(entero > 0)
            {
                int resto = entero % base;
                parteEntera += caracterDigito(resto);
                entero /= base;
            }
            reverse(parteEntera.begin(), parteEntera.end());
        }
        resultado += parteEntera;
        
        //Parte decimal
        double fraccion = numero - (long long)numero;
        
        if(fraccion > 0)
        {
            resultado += ".";
            
            for (int i=0; i<precision && fraccion > 0; i++)
            {
                fraccion *= base;
                int digito = (int)fraccion;
                resultado += caracterDigito(digito);
                fraccion -= digito;
            }
        }
        return resultado;
    }
};

int main()
{
    string n, n1, n2;
    int base, baseConvertir, puntos, operacion, opcion;
    bool salir = false;
    
    Operacion signo_a = Operacion();
    
    double resultadoDecimal;
    
    do 
    {
        cout<<" ========================================="<<endl;
        cout<<"                MENÚ PRINCIPAL            "<<endl;
        cout<<" ========================================="<<endl;
        cout<<"  1. Convertir una base a otra"<<endl;;
        cout<<"  2. Realizar operaciones entre numeros de otra base"<<endl;;
        cout<<"  3. Volver"<<endl;
        cout<<"  4. Salir"<<endl;
        cout<<"  Escoge un numero según el menú: ";
        cin>>puntos;
        cout<<endl;
    
        switch (puntos) 
        {
            case 1: 
            {
                cout<<"   ========================================="<<endl;
                cout<<"           CONVERTIR UNA BASE A OTRA        "<<endl;
                cout<<"   ========================================="<<endl;
                cout<<"    Ingrese el numero: ";
                cin>>n;
                cout<<"    Ingrese la base: ";
                cin>>base;
                cout<<"    Ingrese a que base convertir: ";
                cin>>baseConvertir;
                cout<<endl;
                //cout<<"  Convertir "<<n<<" en base "<<base<<" a la base "<<baseConvertir<<endl;
    
                if(base>0 && (base & (base - 1)) == 0) 
                {
                    cout<<"    Convertir "<<n<<" en base "<<base<<" a la base "<<baseConvertir<<endl;
    
                    Binario conv;
                    string resultado = conv.convertir(n, base, baseConvertir);
                    cout<<endl;
                    cout<<"    El numero en base "<<baseConvertir<<" es: "<<resultado<<endl;
                } 
                else 
                {
                    cout<<"    Convertir "<<n<<" en base "<<base<<" a la base "<<baseConvertir<<endl;
    
                    Decimal bc;
                    string resultado = bc.convertir(n, base, baseConvertir);
                    cout<<endl;
                    cout<<"    El numero en base "<<baseConvertir<<" es: "<<resultado<<endl;
    
                }
                
                n.clear();
                base = 0;
                baseConvertir = 0;
                break;
            }
            
            
            case 2:
            {
                cout<<"   ========================================="<<endl;
                cout<<"    OPERACIONES CON NUMEROS DE OTRAS BASES      "<<endl;
                cout<<"   ========================================="<<endl;
                cout<<"    Ingrese el primer numero: ";
                cin>>n1;
                cout<<"    Ingrese el segundo numero: ";
                cin>>n2;
                cout<<"    Ingrese su base: ";
                cin>>base;
                cout<<endl;
                cout<<"    1. Suma"<<endl;;
                cout<<"    2. Resta"<<endl;;
                cout<<"    3. Multiplicacion"<<endl;;
                cout<<"    4. Division"<<endl;
                cout<<"    ¿Qué operación desea realizar? ";
                cin>>operacion;
                cout<<endl;
                
                double numero1 = signo_a.aDecimal(n1, base);
                double numero2 = signo_a.aDecimal(n2, base);
                
                double resultadoDecimal = 0;
                
                switch(operacion)
                {
                    case 1: 
                    {
                        cout<<"    La suma de: "<<endl;
                        resultadoDecimal = numero1 + numero2;
                        break;
                    }
                    
                    case 2:
                    {
                        cout<<"    La resta de: "<<endl;
                        resultadoDecimal = numero1 - numero2;
                        break;
                    }
                    
                    case 3: 
                    {
                        cout<<"    La multiplicación de: "<<endl;
                        resultadoDecimal = numero1 * numero2;
                        break;
                    }
                    
                    case 4: 
                    {
                        if(numero2 == 0)
                        {
                            cout<<"   Error"<<endl;
                            return 0;
                        }
                        cout<<"    La división de: "<<endl;
                        resultadoDecimal = numero1 / numero2;
                        break;
                    }
                    
                    case 5: 
                    {
                        cout<<"   Volviendo..."<<endl;
                        break;
                    }
                    
                    default:
                    {
                        cout<<"    Error..."<<endl;
                        return 0;
                    }
                }
                
                if(operacion >= 1 && operacion <= 4 && numero2 != 0)
                {
                    string resultado = signo_a.desdeDecimal(resultadoDecimal, base);
                
                    cout<<endl;
                    cout<<"    Primer numero: "<<n1<<endl;
                    cout<<"    Segundo numero: "<<n2<<endl;
                    cout<<"    Base: "<<base<<endl;
                    cout<<"    Resultado: "<<resultado<<endl;
                }
                
                n1.clear();
                n2.clear();
                base = 0;
                operacion = 0;
                break;
            }
            
            case 3:
            {
                cout<<"   Volviendo..."<<endl;
                break;
            }
            
            case 4:
            {
                cout<<"   Programa finalizado..."<<endl;
                break;
            }
            
            default:
            {
                cout<<"    Error..."<<endl;
                return 0;
            }
        }
        
        if (puntos >= 1 && puntos <= 3) {
            cout<<endl;
            cout<<"   Desea continuar con el programa..."<<endl;
            cout<<"   1. Regresar al menu principal"<<endl;
            cout<<"   2. Salir"<<endl;
            cout<<"   ¿Qué desea? ";
            cin>>opcion;
            cout<<endl;
            
            if(opcion==1) {
                puntos = 3;
            } else if (opcion == 2) {
                salir = true;
                puntos = 4;
            }
        }
    } while(puntos != 4 && !salir);
    
    return 0;
}