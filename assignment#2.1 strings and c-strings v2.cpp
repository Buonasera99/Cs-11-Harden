// made by oran collins
//assignment 2.1
//class Dave harden
//the persouse of this assignment is to recreate vary
//simple functions that are standard c++ by hand
//to better understand what happens to the data when
//operations happen upon them.
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
//phase 1
//1.
int lastIndexOf(const char* inString, char target);
//2.
void reverse(char* inString);
//3.
int replace(char* inString, char target, char replacementChar);
//4.
int findSubstring(const char* inString, const char substring[]);
//5.
bool isPalindrome(const char* inString);
//6.
void toupper(char* inString);
//7.
int numLetters(const char* inString);

//phase 2
//#1
void read(char*& readMe);
//#2
void concatenate(char*& left, char* right);

int main()
{
    char* inString;
    inString = new char[12];
    char replacementChar = 'e';
    char target = 't';
    char substring[3];
    char userInput[81];
    char tempLeft [81];
    char tempRight[81];
    char* readMe;
    char* left;
    char* right;
    char temporary[81];

//1.
    cout << "Phase One " << endl;
    cout << "1." << endl;
    //input apple into char array inString
    inString[0] = 'a';
    inString[1] = 'p';
    inString[2] = 'p';
    inString[3] = 'l';
    inString[4] = 'e';
    cout << "To find the desired letter From the word ""APPLE"" type a letter  : " << endl;
    //get a letter from the user to be found the the cstring IE TYPE "e"
    cin >> target;

    cout << "Index of the letter you searched for is , index : [" << lastIndexOf(inString, target) << "]" << endl;

    cout << "2." << endl;
    //input 'flower' into inString
    inString[0] = 'f';
    inString[1] = 'l';
    inString[2] = 'o';
    inString[3] = 'w';
    inString[4] = 'e';
    inString[5] = 'r';
    inString[6] = '\0';
    cout << "Input 'flower' into inString " << endl;
    reverse(inString);
    cout << "After the reversal of 'flower' " << endl;
    cout << "Output : " <<  inString << endl;

    cout << "3." << endl;

    cout << "Replace letter in 'REWOLF' by entering a letter EX 'e'" << endl;
    cout << "Target Letter : ";
    cin  >> target;

    cout << "Replace  with : ";
    cin  >>  replacementChar;
    replace(inString, target, replacementChar);
    cout << "Result is     :" << inString << endl;

    cout << "4." << endl;
    cout << "Find index of substring 'ple' in'apple'" << endl;
    //put apple in to inString
    inString[0] = 'a';
    inString[1] = 'p';
    inString[2] = 'p';
    inString[3] = 'l';
    inString[4] = 'e';
    //set substring equal to "ple" in apple
    substring[0] = 'p';
    substring[1] = 'l';
    substring[2] = 'e';

    cout << "Output : index [" << findSubstring(inString, substring) << "]" << endl;

    cout << "5." << endl;
    cout << "Test if aBbA is a palindrome" << endl;
    //rest instring to aBbA
    inString[0] = 'a';
    inString[1] = 'B';
    inString[2] = 'b';
    inString[3] = 'A';
    inString[4] = '\0';
    cout << "Output : " << isPalindrome(inString) << " (1 equals true) " << endl;

    cout << "6." << endl;

    cout << "converts 'ApPlE' into 'APPLE' " << endl;
    //puts apple into array inString
    inString[0] = 'A';
    inString[1] = 'p';
    inString[2] = 'P';
    inString[3] = 'l';
    inString[4] = 'E';
    inString[5] = '\0';

    cout << "input  : " << inString << endl;
    toupper(inString);
    cout << "output : " << inString << endl;

    cout << "7." << endl;

    inString[0] = 'A';
    inString[1] = '2';
    inString[2] = '1';
    inString[3] = 'p';
    inString[4] = '4';
    inString[5] = '\0';
    cout << "Finds the number of letter in '" << inString << "'" << endl;
    cout << "number = [" << numLetters(inString) + 1 << "]" << endl;

    cout << "Phase Two " << endl;
    cout << "#1." << endl;
    cout << "Put some words into the char string readMe"<< endl;
    cin.ignore();
    cin.getline(temporary, 81);

    readMe = new char[strlen(temporary)];
    strcpy(readMe, temporary);
    read(readMe);

    cout << "#2." << endl;
    cout << "Left side then Enter: ";
    //gets the user input into tempLeft variable
    cin.getline(tempLeft, 81);

    cout << "Right side then Enter: ";
    cin.getline(tempRight, 80);
    //makes a dynamic array for left side variable
    left = new char[strlen(tempRight) + strlen(tempLeft) + 1];
    right = new char[strlen(tempRight)];
    //copy data from the temp variables into
    // left and right
    strcpy(left, tempLeft);
    strcpy(right, tempRight);
    //concatenate what every the user intered
    //Output something + somethingElse
    concatenate(left, right);

    cout << "Concatenated Left + Right to make : " << endl;
    cout << left << endl;



    return 0;
}
//1. searches for a letter
int lastIndexOf(const char* inString, char target)
{
    int index = -1;//used to test if there are not matchs
    //runs though the array char's
    for (int count = 0; count < inString[count] != '\0'; count++)
    {   //checks to see if there is the desired letter and then sets the
        //array index to a temparay variable to be used to determine if there is a
        // the letter in the array
        if (inString[count] == target)
        {
            index = count;
        }
    }
    //checks to see if there was a letter found
    if (index > -1)
    {
        //letter found and reports the location in
        //the array
        return index;
    }
    else
    {
        //reports no found letter
        return -1;
    }
}
//2. swaps the first and last letters utill the whole array is
//reversed
void reverse(char* inString)
{
    //runs half of the length of the array size
    for (int count = 0; count < strlen(inString)/2; count++)
    {
        //stores the first char of array in temp
        char temp = inString[count];
        //copys the last char of array into the first
        inString[count] = inString[strlen(inString) - count -1];
        //sets the stored charater to the last element of array
        inString[strlen(inString) - count -1] = temp;
    }
}
//3. Search and replaces letter with desired letter
int replace(char* inString, char target, char replacementChar)
{
    int index = 0;
    //stops at end of array
    for (int count = 0; count < inString[count] != '\0'; count++)
    {
        //checks to see if the letter matches
        if (inString[count] == target)
        {
            //records the location of the letters
            index = count;
            //replaces the letter with the selected letter
            inString[count] = replacementChar;
        }
    }
    //checks if there was no letters returns false
    if (index == 0)
    {
        return 0;
    }
}
//4. looks for a 3 character string in a larger string
//reports back the index of the substring
int findSubstring(const char* inString, const char substring[])
{
    int counter = 0;
    //stops at end of array
    for(int count = 0; count < inString[count] != '\0'; count++)
    {
        //checks the first letter of substring against the current location
        //of the index and if it matches
        // return the location
        if(substring[0] == inString[count] && substring[1] == inString[count + 1] && substring[2] == inString[count + 2])
        {
            counter = count;
        }
    }
    //checks to see if no substring matches
    if(counter  == 0)
    {
        return -1;
    }
    else
    {
        // return the location of substring
        return counter;
    }
}
//5. checks to see if the sting is a palindrome
// IE "Hannah"
bool isPalindrome(const char* inString)
{
    int counter = 0;
    //stops at end of array
    for (int count = 0; count < strlen(inString)/2; count++)
    {
        //1) sets all letters to lower case
        //2) checks to see if the last letter is the same as the first number
        //and looks inward intill it reaches the center
        if(tolower(inString[count]) == tolower(inString[strlen(inString) - count -1]))
        {
            counter++;//logic counter
        }
    }
    //checks to see if all the letters are the same
    //by comaring the half the length of the string
    // and the number of letters found to be the
    //same if true when word is a palindrome
    if(counter == strlen(inString)/2)
    {
         return true;
    }
    else
    {
        return false;
    }
}
//6. sets letters uppercase
void toupper(char* inString)
{
    for (int count = 0; count < inString[count] != '\0'; count++)
    {
        //sets letters to there uppercase brethren
        inString[count] = toupper(inString[count]);
    }
}
//7. finds the number of letter
int numLetters(const char* inString)
{
    int temp = 0;
    for(int count = 0; count < inString[count] != '\0'; count++)
    {
        //checks to see if its a letter then adds to the counter
        //if its true
        if( isalpha(inString[count]) != 0)
         temp++;
    }
    return temp;
}
//phase 2
//#1 gets user input and copys into dynamic array
void read(char*& readMe)
{
    char userInput[81];
    readMe = new char[strlen(userInput) + 1];// make array the size of user input
    for(int count = 0; count < userInput[count] != '\0';  count++)//strlen(userInput); count++)
    {
        readMe[count] ='  ';//initulize the array with starting \0
        readMe[count] = userInput[count];//copies contents from array to array
    }
    delete userInput;//.clear(); dealocates userinput
}
//#2
void concatenate(char*& left, char* right)
{   //makes a static variable
    //that is for offsetting the copy of data untill the
    //for loop gets passed the data privousely stored
    //in the left array
    int x = strlen(left);
    for(int count = 0; count < left[count] != '\0'; count++)
    {
        //starts coping data after the word sored in
        //left
        left[count + x] = right[count];
    }
}
/*
Phase One
1.
To find the desired letter From the word APPLE type a letter  :
e
Index of the letter you searched for is , index : [4]
2.
Input 'flower' into inString
After the reversal of 'flower'
Output : rewolf
3.
Replace letter in 'REWOLF' by entering a letter EX 'e'
Target Letter : f
Replace  with : @
Result is     :rewol@
4.
Find index of substring 'ple' in'apple'
Output : index [2]
5.
Test if aBbA is a palindrome
Output : 1 (1 equals true)
6.
converts 'ApPlE' into 'APPLE'
input  : ApPlE
output : APPLE
7.
Finds the number of letter in 'A21p4'
number = [3]
Phase Two
#1.
Put some words into the char string readMe
puttingWordsInTheVariableHere
#2.
Left side then Enter: will
Right side then Enter: smith
Concatenated Left + Right to make :
willsmith

Process returned 0 (0x0)   execution time : 67.547 s
Press any key to continue.


*/
