/*  
    For Mautoz Tech YouTube channel
    Copyright 2022 Mikhail Kuznetsov

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

using namespace std;
#include <iostream>
int rotorPos=0;
                                 // A B C  D E F G  H  I  J  K  L M N O  P  Q  R  S T  U  V W  X  Y  Z
const uint8_t reflectorValues[26]={12,5,18,4,3,1,25,13,11,21,22,8,0,7,15,14,24,20,2,23,17,9,10,19,16,6};
const uint8_t rotor1Values[2][26]={{13,25,20,22,11,1,17,23,4,9,2,5,18,16,6,21,3,8,15,7,12,24,10,0,14,19},{23,5,10,16,8,11,14,19,17,9,22,4,20,0,24,18,13,6,12,25,2,15,3,7,21,1}};

void changeRotorPos(){
    rotorPos++;
        if (rotorPos>25){
            rotorPos=0;
        }
}

uint8_t reflector(uint8_t input){
    return 65+reflectorValues[input-65];
}

uint8_t rotor1(uint8_t direction, uint8_t input){
    input=input-65+rotorPos;
    if (input>25){
        input=input-26;
    }
    uint8_t result=65-rotorPos+rotor1Values[direction][input];
    if (result<65){
        result=result+26;
    }
    return result;
}

int main()
{
    cout << "Enter initial rotor position (1-26):" << endl;
    cin >> rotorPos;
    char symbol;
    cout << "Input: ";
    cin >> symbol;
    symbol = toupper(symbol);
    uint8_t asciiVal=uint8_t(symbol);
    while (asciiVal!=46){ // Ascii 46 = dot.
        asciiVal=rotor1(0,asciiVal);
        asciiVal=reflector(asciiVal);
        asciiVal=rotor1(1,asciiVal);
        changeRotorPos();
        cout << "Output: " << asciiVal << endl << "Input: ";

        cin >> symbol;
        symbol = toupper(symbol);
        asciiVal=uint8_t(symbol);
    }
    return 0;
}
