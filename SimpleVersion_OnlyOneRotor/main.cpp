using namespace std;
#include <iostream>
/*#include <cmath>
#include <string.h>*/

const uint8_t asciiA=65;
                                 // A B C  D E F G  H  I  J  K  L M N O  P  Q  R  S T  U  V W  X  Y  Z
const uint8_t reflectorValues[26]={12,5,18,4,3,1,25,13,11,21,22,8,0,7,15,14,24,20,2,23,17,9,10,19,16,6};
const uint8_t rotor1Values[2][26]={{13,25,20,22,11,1,17,23,4,9,2,5,18,16,6,21,3,8,15,7,12,24,10,0,14,19},{23,5,10,16,8,11,14,19,17,9,22,4,20,0,24,18,13,6,12,25,2,15,3,7,21,1}};
//const uint8_t rotor1Values[1][26]={13,25,20,22,11,1,17,23,4,9,2,5,18,16,6,21,3,8,15,7,12,24,10,0,14,19};
int rotorPos[3]={0,0,0};

void changeRotorPos(){
    rotorPos[0]++;
        if (rotorPos[0]>25){
            rotorPos[1]++;
            rotorPos[0]=0;
            if (rotorPos[1]>25){
                rotorPos[2]++;
                rotorPos[1]=0;
                if (rotorPos[2]>25){
                    rotorPos[2]=0;
                }
            }
        }
}

uint8_t reflector(uint8_t input){
    return 65+reflectorValues[input-65];
}

uint8_t rotor1(uint8_t direction, uint8_t input){
    input=input-65+rotorPos[0];
    if (input>25){
        input=input-26;
    }
    uint8_t result=65-rotorPos[0]+rotor1Values[direction][input];
    if (result<65){
        result=result+26;
    }
    return result;
}

/*uint8_t rotor2(uint8_t direction, uint8_t input){
    input=input-65+rotorPos[1];
    if (input>25){
        input=input-26;
    }
    uint8_t result=65-rotorPos[1]+rotor2Values[direction][input];
    if (result<65){
        result=result+26;
    }
    return result;
}

uint8_t rotor3(uint8_t direction, uint8_t input){
    input=input-65+rotorPos[2];
    if (input>25){
        input=input-26;
    }
    uint8_t result=65-rotorPos[2]+rotor3Values[direction][input];
    if (result<65){
        result=result+26;
    }
    return result;
}*/

int main()
{
    cout << "Enter first rotor position (1-26):" << endl;
    cin >> rotorPos[0];
    cout << "Enter second rotor position (1-26):" << endl;
    cin >> rotorPos[1];
    cout << "Enter third rotor position (1-26):" << endl;
    cin >> rotorPos[2];
    //cout << int(rotorPos[0]);
    char symbol;
    cin >> symbol;
    symbol = toupper(symbol);
    uint8_t asciiVal=uint8_t(symbol);
    while (asciiVal!=46){ // Ascii 46 = dot. Cout here for showing middle result.
        /*cout << asciiVal << " ";
        cout << int(asciiVal) << " ";
        cout << int(asciiVal)-64 << endl;*/
        asciiVal=rotor1(0,asciiVal);
        asciiVal=reflector(asciiVal);
        asciiVal=rotor1(1,asciiVal);
        changeRotorPos();
        cout << asciiVal << endl;

        cin >> symbol;
        symbol = toupper(symbol);
        asciiVal=uint8_t(symbol);
    }
    return 0;
}

















    /*switch(input){
        case 0:
            return asciiA+13;
            break;
        case 1:
            return asciiA+6;
            break;
        case 2:
            return asciiA+19;
            break;
        case 3:
            return asciiA+5;
            break;
        case 4:
            return asciiA+4;
            break;
        case 5:
            return asciiA+2;
            break;
        case 6:
            return asciiA+26;
            break;
        case 7:
            return asciiA+14;
            break;
        case 8:
            return asciiA+12;
            break;
        case 9:
            return asciiA+22;
            break;
        case 10:
            return asciiA+23;
            break;
        case 11:
            return asciiA+9;
            break;
        case 12:
            return asciiA+1;
            break;
        case 13:
            return asciiA+8;
            break;
        case 14:
            return asciiA+16;
            break;
        case 15:
            return asciiA+15;
            break;
        case 16:
            return asciiA+25;
            break;
        case 17:
            return asciiA+21;
            break;
        case 18:
            return asciiA+24;
            break;
        case 19:
            return asciiA+18;
            break;
        case 20:
            return asciiA+10;
            break;
        case 21:
            return asciiA+11;
            break;
        case 22:
            return asciiA+20;
            break;
        case 23:
            return asciiA+17;
            break;
        case 24:
            return asciiA+7;
            break;
        case 25:
            return asciiA+6;
            break;
    }*/
