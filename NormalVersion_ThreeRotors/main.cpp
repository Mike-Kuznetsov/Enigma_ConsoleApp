using namespace std;
#include <iostream>
#include<limits>
                                 // A B C  D E F G  H  I  J  K  L M N O  P  Q  R  S T  U  V W  X  Y  Z
const uint8_t reflectorValues[26]={12,5,18,4,3,1,25,13,11,21,22,8,0,7,15,14,24,20,2,23,17,9,10,19,16,6};
const uint8_t rotor1Values[2][26]={{13,25,20,22,11,1,17,23,4,9,2,5,18,16,6,21,3,8,15,7,12,24,10,0,14,19},{23,5,10,16,8,11,14,19,17,9,22,4,20,0,24,18,13,6,12,25,2,15,3,7,21,1}};
const uint8_t rotor2Values[2][26]={{11,14,22,21,25,1,2,13,23,4,9,8,15,18,17,20,3,19,0,12,10,7,16,6,5,24},{18,5,6,16,9,24,23,21,11,10,20,0,19,7,1,12,22,14,13,17,15,3,2,8,25,4}};
const uint8_t rotor3Values[2][26]={{21,11,25,22,19,17,24,6,5,13,18,9,20,14,16,2,3,0,4,23,15,12,10,8,1,7},{17,24,15,16,18,8,7,25,23,11,22,1,21,9,13,20,14,5,10,4,12,0,3,19,6,2}};
int rotorPos[3]={0,0,0};

void rotorPosInput(){
    cout << "Enter first rotor position (1-26): ";
    while(!(cin >> rotorPos[0])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
    }
    while ((rotorPos[0]>26)||(rotorPos[0]<0)){
        cout << "Invalid input.  Try again: ";
        while(!(cin >> rotorPos[0])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }
    }
    rotorPos[0]-1;
    cout << "Enter second rotor position (1-26): ";
    while(!(cin >> rotorPos[1])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
    }
    while ((rotorPos[1]>26)||(rotorPos[1]<0)){
        cout << "Invalid input.  Try again: ";
        while(!(cin >> rotorPos[1])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }
    }
    rotorPos[1]-1;
    cout << "Enter third rotor position (1-26): ";
    while(!(cin >> rotorPos[2])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
    }
    while ((rotorPos[2]>26)||(rotorPos[2]<0)){
        cout << "Invalid input.  Try again: ";
        while(!(cin >> rotorPos[2])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }
    }
    rotorPos[2]-1;
}

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

uint8_t rotor2(uint8_t direction, uint8_t input){
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
}

int main()
{
    rotorPosInput();
    char symbol;
    cout << "Input: "; // You can input several symbols if you want, not only one
    cin >> symbol;
    symbol = toupper(symbol); // We'll use only UPPER CASE.
    uint8_t asciiVal=uint8_t(symbol);
    while (asciiVal!=46){ // Ascii 46 = dot .
        asciiVal=rotor1(0,asciiVal); // Forward, vpered -->>
        asciiVal=rotor2(0,asciiVal);
        asciiVal=rotor3(0,asciiVal);
        asciiVal=reflector(asciiVal);
        asciiVal=rotor3(1,asciiVal); // Backward, nazad <<--
        asciiVal=rotor2(1,asciiVal);
        asciiVal=rotor1(1,asciiVal);
        changeRotorPos();
        cout << "Output: " << asciiVal << endl << "Input: ";

        cin >> symbol;
        symbol = toupper(symbol);
        asciiVal=uint8_t(symbol);
    }
    return 0;
}