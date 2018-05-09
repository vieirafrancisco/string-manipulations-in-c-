#include <iostream>
#include <string>
using namespace std;

/** Manipulações de strings:
   -Tamanho;
   -Inverter a ordem;
   -Verificar presença de uma substring em uma string;
   -Quantas vezes uma substring se repete na maior;
   -Separar strings;
   -Adicionar uma substring;
   -Remover uma substring; **/

/** Protótipos das funções **/
int tamanho(string str);
string inverterString(string str);
bool temSubstringNaString(string substr, string str);
int freqSubstring(string substr, string str);
int separarString(string str, string criterio, string *array);
string copiar(string str, int inicio, int fim);
string add(string substr, string str);
string remover(string substr, string str);

/** Função principal **/
int main(){
    /** Tamanho **/
    cout << "O tamanho desse texto eh: " << tamanho("O tamanho desse texto eh") << "\n";

    /** Inverter a ordem da string **/
    cout << "O inverso desse texto eh: " << inverterString("O inverso desse texto eh") << "\n";

    /** Verificar presença de uma substring em uma string **/
    if(temSubstringNaString("a natureza", "Eu amo a natureza")){
        cout << "Existe essa substring nesta string" << "\n";
    } else{
        cout << "Nao existe essa substring nesta string" << "\n";
    }

    /** Quantas vezes uma substring se repete na maior **/
    cout << "sabia que o sabia sabia assobia?, sabia quantas vezes? " << freqSubstring("sabia", "sabia que o sabia sabia assobia?") << "\n";

    /** Separar strings **/
    string substrings[100];
    int tamanhoArray = separarString("sabia que o sabia sabia assobia?", " ", substrings);
    for(int i = 0; i < tamanhoArray; i++){
        cout << substrings[i] << "\n";
    }

    /** Adicionar uma substring **/
    string a = "Hello ";
    string b = "World!";
    string c = add(b, a);
    cout << c << "\n";

    /** Remover uma substring **/
    string all = "Hello World! Brasil! World!";
    string sub = "World!";
    string res = remover(sub, all);
    cout << res << "\n";

    return 0;
}

int tamanho(string str){
/** Dado uma string retorna seu tamanho **/
    int length = 0;
    for(string::iterator i = str.begin(); i != str.end(); i++){
        length++;
    }
    return length;
}

string inverterString(string str){
/** Dado uma string retorna sua inversa **/
    string reverseStr;
    for(int i = tamanho(str) - 1; i >= 0; i--){
        reverseStr += str[i];
    }
    return reverseStr;
}

bool temSubstringNaString(string substr, string str){
/** Dado uma substring e uma string retornar se há ou não esta substring na string
    Exemplo:
    str: Eu amo a natureza (17)
    substr: amo (3)
    return: True **/
    int n = tamanho(str);
    int m = tamanho(substr);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(str[i + j] == substr[j]){
                if(j == m - 1){
                    return true;
                }
            } else{
                break;
            }
        }
    }
    return false;
}

int freqSubstring(string substr, string str){
/** Dado uma substring e uma string retornar a frequencia dessa substring
    Exemplo:
    str: sabia que o sabia sabia assobia?
    substr: sabia **/
    int frequencia = 0;
    int n = tamanho(str);
    int m = tamanho(substr);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(str[i + j] == substr[j]){
                if(j == m - 1){
                    frequencia++;
                }
            } else{
                break;
            }
        }
    }
    return frequencia;
}

int separarString(string str, string criterio, string *array){
    int inicio = 0;
    int fim = 0;
    int indice = 0;
    int cont = 0;
    int n = tamanho(str);
    int m = tamanho(criterio);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(str[i + j] == criterio[j]){
                if(j == m - 1){
                    array[indice] = copiar(str, inicio, fim);
                    inicio = fim + m;
                    indice++;
                    cont++;
                }
            } else{
                break;
            }
        }
        fim++;
    }
    array[indice] = copiar(str, inicio, fim);
    cont++;
    return cont;
}

string copiar(string str, int inicio, int fim){
    string finalStr;
    for(int i = inicio; i < fim; i++){
        finalStr += str[i];
    }
    return finalStr;
}

string add(string substr, string str){
/** Adicionar a substring na string **/
    return str + substr;
}

string remover(string substr, string str){
/** Remover uma substring de uma string **/
    string novaString[100];
    string finalString;
    int tamanho = separarString(str, substr, novaString);
    for(int i = 0; i < tamanho; i++){
        finalString = add(novaString[i], finalString);
    }
    return finalString;
}
