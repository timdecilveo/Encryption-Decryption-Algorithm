/*
Author Name: Tim Decilveo
Description: The below program will encrypt and decrypt a series of characters or integers
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <typeinfo>

using namespace std;

void choices();
char get_selection();

void p_selection();
void c_selection();
void unknown_selection();
void q_selection();

char alphabet_digits [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                            'o','p','q','r','s','t','u','v','w','x','y','z','0','1',
                            '2','3','4','5','6','7','8','9'};
string ad_converted {alphabet_digits};

int main(){
    char selection {};

    do{
        choices();
        selection = get_selection();
        switch(selection){
            case 'p':
                p_selection();
                break;
            case 'C':
                c_selection();
                break;
            case 'Q':
            case 'q':
                q_selection();
                break;
            default:
                unknown_selection();
        }
    } while(selection != 'p' || selection != 'C');

    cout << endl;
    return 0;
}

void choices(){
    /*
    This function tells the user which choices to enter into the prompt
    */
    cout<< "\n\nEnter p - ENCRYPT a set of characters" << endl;
    cout<< "Enter C - DECRYPT a set of characters" << endl;
    cout<< "Enter Q - Quit the program" << endl;

    cout<< "\nEnter your selection: ";
}

char get_selection(){
    char selection{};
    cin >> selection;
    return selection;
}

/*
SELECTION OPTIONS
*/
void p_selection(){
    /************************ ENCRYPTION ************************
    To encrypt a plaintext string use the following formula to compute an
    index i into the alphabet_digits array:

        Ci = E(p) = (p + k) mod 36;
    
    where mod is the modulus operator %,
    C is the ciphertext,
    E is the encryption function,
    p is the index of the plaintext character,
    k is the key shift,
    36 is the length of the alphabet_digits array.
    ************************ ENCRYPTION ************************/
   
    string plaintext {};
    string ciphertext {};
    int k_value {};
    int n = sizeof(alphabet_digits);
    
    cout << "Enter message to encrypt: ";
    cin >> plaintext;
    cout << "Enter an integer for the k value: ";
    cin >> k_value;
    cout << "Encrypting message -p " << plaintext << " -k " << k_value << " -E\n" << endl;

   for (char c: plaintext){
        size_t position = ad_converted.find(c); // this looks for the position of the character in the ad_converted string
        int plaintext_manipulator = (position + k_value) % n; // manipulates plaintext to ciphertext

        if(position != string::npos){ // this means we found the character
            char new_char {ad_converted.at(plaintext_manipulator)}; //need a new character from the ad_converted string
            ciphertext += new_char;
        }
        else{
            ciphertext += c;
        }
    }
    cout << "The ciphertext is: " << ciphertext << endl;
}

void c_selection(){
    /************************ DECRYPTION ************************
    To decrypt a ciphertext string use the following formula to compute
    an index i into the alphabet_digits array:

        pi = D(C) = (C - k) mod 36;                     (C - k) >= 0
        pi = D(C) = (((C - k) mod 36) + 36) mod 36;     (C - k) < 0

    where mod is the modulus operator %
    C is the index of the ciphertext character
    D is the decryption function
    p is the plaintext
    k is the key shift
    36 is the length of the alphabet_digits marray.
    ************************ DECRYPTION ************************/

    string ciphertext {};
    string plaintext {};
    int k_value {};
    int n = sizeof(alphabet_digits);
    
    cout << "Enter message to decrypt: ";
    cin >> ciphertext;
    cout << "Enter an integer for the k value: ";
    cin >> k_value;
    cout << "Decrypting message -C " << ciphertext << " -k " << k_value << " -D" << endl;

    for (char c: ciphertext){
        size_t position = ad_converted.find(c); // this looks for the position of the character in the ad_converted string
        int ciphertext_manipulator = (position - k_value) % n; // manipulates ciphertext to plaintext
        int ciphertext_manipulator_greater_than_0 = (position - k_value) % n; // manipulates ciphertext to plaintext if position - k_value > 0
        int ciphertext_manipulator_less_than_0 = (((position - k_value) % n) + n) % n; // manipulates ciphertext to plaintext if position - k_value < 0

        if(position != string::npos){ // this means you found the character
            char new_char {ad_converted.at(ciphertext_manipulator)}; //need a new character from the ad_converted string
            plaintext += new_char;
            cout << "ciphertext_manipulator: " << ciphertext_manipulator << endl;
        }
        else{
            plaintext += c;
        }
    }
    cout << "The plaintext is: " << plaintext << endl;
}

void q_selection(){
    cout << "Goodbye!" << endl;
    exit (EXIT_FAILURE);
}

void unknown_selection(){
    cout << "Unknown selection, please try again." << endl;
}