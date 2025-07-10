Problem 8.7 - Chapter 8, Project A
---------------------------------------------
Random monoalphabet cipher.
The Caesar cipher, which shifts all letters by a fixed amount, is far too easy to crack.
Here is a better idea. As the key, don’t use numbers but words.
Suppose the key word is FEATHER. Then first remove duplicate letters, yielding FEATHR,
and append the other letters of the alphabet in reverse order:
Write a program that encrypts or decrypts a file using this cipher. For example,
crypt -d -FEATHER encrypt.txt output.txt
decrypts a file using the keyword FEATHER. It is an error not to supply a keyword.

---------------------------------------------

Write to command line as follows:
---------------------------------------------
./main -d FEATHER encrypt.txt output.txt OR
---------------------------------------------
./main -e FEATHER encrypt.txt output.txt

---------------------------------------------

Programmer - Ashley Jacobson
Tester - Audrey Tapia

---------------------------------------------

Group Project A 
---------------------------------------------
Members
Ashley Jacobson
Giannfranco Brance
Audrey Tapia
Heily Cabrera Guerrero
