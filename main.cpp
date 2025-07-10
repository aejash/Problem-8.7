/**** Problem 8.7 - Chapter 8, Project A
*---------------------------------------------
Random monoalphabet cipher.
***** The Caesar cipher, which shifts all letters by a fixed amount, is far too easy to crack.
***** Here is a better idea. As the key, don’t use numbers but words.
***** Suppose the key word is FEATHER. Then first remove duplicate letters, yielding FEATHR,
***** and append the other letters of the alphabet in reverse order:
***** Write a program that encrypts or decrypts a file using this cipher. For example,

***** crypt -d -FEATHER encrypt.txt output.txt

***** decrypts a file using the keyword FEATHER. It is an error not to supply a keyword.
// Programmer - Ashley Jacobson
// Tester - Audrey Tapia
// Group Project A //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/




#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


//***** Remove duplicate letters from key *****//
//***** Append the other letters of the alphabet in reverse order *****//

vector<char> modify_vector(string key, vector<char>& reverse)
{
    char temp = 0;


    for(int i = 0; i < key.length(); i++)
    {
        for(int j = 1; j < key.length(); j++)
        {
            if(key[i] == key[j] && temp == 0)
            {
                key.erase(j, 1);
                temp = key[j];
            }
        }
    }

    for(int i = key.length(); i >= 0; i--)
    {
        for(int j = 1; j < 27; j++)
        {

            for(int j = 1; j < reverse.size(); j++)
            {
                if(key[i] == reverse[j])
                {
                    reverse.erase(reverse.begin() + j);
                    reverse.insert(reverse.begin(), 1);
                    reverse[0] = key[i];
                }

            }
        }

    }
    return reverse;
}
//***** Encrypt Input File and write to output file *****//

void encrypt_file(ifstream& in, ofstream& out, string key, vector<char>& reverse, vector<char>& alphabet)
{
    char ch;
    bool flag = false;
    while(in.get(ch))
    {
        flag = false;
        for(int i = 0; i < alphabet.size(); i++)
        {
            if(flag == true)
            {
                break;
            }
                if(ch == ' ')
                {
                    out << ch;
                    break;
                }
                for(int j = 0; j < alphabet.size(); j++)
                {
                    if(toupper(ch) == alphabet[j])
                    {
                        ch = reverse[j];
                        out << ch;
                        flag = true;
                        break;
                    }
                }
        }
        }
    }

//***** Decrypt Input File and write to Output file *****//

void decrypt_file(ifstream& in, ofstream& out, string& key, vector<char>& reverse,vector<char>& alphabet)
{
    char ch;
    bool flag = false;
    while(in.get(ch))
    {
        flag = false;
        for(int i = 0; i < reverse.size(); i++)
        {
            if(flag == true)
            {
                break;
            }
            if(ch == ' ')
            {
                out << ch;
                break;
            }
            for(int j = 0; j < reverse.size(); j++)
            {
                if(toupper(ch) == reverse[j])
                {
                    ch = alphabet[j];
                    out << ch;
                    flag = true;
                    break;
                }
            }
        }
    }
}

// Write to command line as follows
//***** ./main -d FEATHER encrypt.txt output.txt
//***** ./main -e FEATHER encrypt.txt output.txt

int main(int argc, char* argv[])
{
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<char> reverse = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q',
                            'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G',
                            'F', 'E', 'D', 'C', 'B', 'A'};

    string key;
    ifstream in;

    if (argc < 5)
    {
        cout << "Error: please enter a key. " << endl;
        return 1;
    }
    key = argv[2];  // Input key from command line
    if(key == "encrypt"|| key == "decrypt")
    {
        cout << "Error: please enter a valid key. " << endl;
        return 1;
    }
    in.open(argv[3]); // Open "encrypt.txt" from command line
    ofstream out;
    out.open(argv[4]); // Open "output.txt" from command line


    reverse = modify_vector(key, reverse); // Modify reverse alphabet vector to encrypt with
    if(!in.is_open())
    {
        cout << "Error opening file " << argv[3] << endl;
        return 1;
    }
    if(!out.is_open())
    {
        cout << "Error opening file " << argv[4] << endl;
        return 1;
    }

    // Check to see if user chooses encryption or decryption
    if(strcmp(argv[1], "-e") == 0)
    {
        encrypt_file(in, out, key, reverse, alphabet);
    }
    else if(strcmp(argv[1], "-d") == 0)
    {
        decrypt_file(in, out, key, reverse, alphabet);
    }

    // Close files
    out.close();
    in.close();



    return 0;
}
