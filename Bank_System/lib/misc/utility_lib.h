#pragma once
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

class clsUtilities {
    private:
    enum _enCharType {smallLetter = 1, capitalLetter=2, specialCharacter=3, digit=4};

    protected:

   static int ReverseNumbers(int nums){
    int reversed = 0, reminder = 0;
    while(nums > 0){
        reminder = nums % 10;
        nums = nums /10;
        reversed = (reversed * 10 )+ reminder;
    }
    return reversed;
}

    public:

static void PrintDigitsFromLeftToRight(int nums){
    nums = ReverseNumbers(nums);
    int Remainder = 0;
    while(nums > 0){
        Remainder = nums % 10;
        nums = nums /10;
        
        cout << Remainder << endl;
    }

}

static void srand_seed(){
    srand((unsigned) time(NULL));
}
static int GenerateRandomNumber(short from, short to){
    short random = rand() % (to - from) + from;

    return random;
}



static char GenerateRnadomCharacter(_enCharType charType){
    switch (charType) {
        case _enCharType::smallLetter:
        return GenerateRandomNumber(97, 122);
        break;

        case _enCharType::capitalLetter:
        return GenerateRandomNumber(65, 90);
        break;

        case _enCharType::specialCharacter:
        return GenerateRandomNumber(33, 47);
        break;

        case _enCharType::digit:
        return GenerateRandomNumber(48, 57);
        break;
    }
    return charType;
}

static string GenerateWord(short Length, _enCharType Type){
    string Word = "";
    for(int x = 1; x <= Length; x++){
        Word = Word + GenerateRnadomCharacter(Type);
    }
    return  Word;
}

static string GenerateWord(short len = 4) {
    string word = "";
    for (int i = 0; i < len; i++) {
        _enCharType charType = MixedChars();
        char newChar;
        
        switch (charType) {
            case _enCharType::smallLetter:
                newChar = GenerateRandomNumber('a', 'z');
                break;
            case _enCharType::capitalLetter:
                newChar = GenerateRandomNumber('A', 'Z');
                break;
            case _enCharType::digit:
                newChar = GenerateRandomNumber('0', '9');
                break;
            case _enCharType::specialCharacter:
                // Using common special characters
                newChar = "!@#$%^&*"[GenerateRandomNumber(0, 7)];
                break;
        }
        word += newChar;
    }
    return word;
}

// Usage example:
string result = GenerateWord();  // Will generate something like "K7$p"

static string GenerateKey(){
    string Key = "";

    Key = GenerateWord(4, _enCharType::capitalLetter) + "-";
    Key = Key + GenerateWord(4, _enCharType::capitalLetter) + "-";
    Key = Key + GenerateWord(4, _enCharType::capitalLetter) + "-";
    Key = Key + GenerateWord(4, _enCharType::capitalLetter);

    return Key;
}

static _enCharType MixedChars() {
    short random = GenerateRandomNumber(1, 5);
    switch (random) {
      case 1:
      return _enCharType::smallLetter;
      case 2:
      return _enCharType::capitalLetter;
      case 3: 
      return _enCharType::specialCharacter;
      case 4 : 
      return _enCharType::digit;  

      default:
      return _enCharType::digit;
    }
}

static string GenerateKey(_enCharType MixedChars){
        string Key = "";

    Key = GenerateWord(4) + "-";
    Key = Key + GenerateWord(4) + "-";
    Key = Key + GenerateWord(4) + "-";
    Key = Key + GenerateWord(4);

    return Key;
}


static void GenrateRequestedNumberOfKeys(int input){
    for(int x = 1; x <= input; x++){
        cout << "Key ["<<x<<"]: "<< GenerateKey()<<endl;
    }
}

static void GenrateRequestedNumberOfKeys(int input, _enCharType MixedChar){
    for(int x = 1; x <= input; x++){
        cout << "Key ["<<x<<"]: "<< GenerateKey(MixedChar)<<endl;
    }
}

static void Swap(int& num1, int& num2){
    int Temp = 0;
    Temp = num1;
    num1 = num2;
    num2 = Temp;
}

static void Swap(double& num1, double& num2){
    double Temp = 0;
    Temp = num1;
    num1 = num2;
    num2 = Temp;
}
static void Swap(string& str1, string& str2){
    string Temp = "";
    Temp = str1;
    str1 = str2;
    str2 = Temp;
}

static void ShuffleArray(int arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
       Swap(arr[GenerateRandomNumber(1, arrLength)-1] , arr[GenerateRandomNumber(1, arrLength)]);
    }
}

static void ShuffleArray(string arr[100], int arrLength){
    for(int x = 0; x < arrLength; x++){
       Swap(arr[GenerateRandomNumber(1, arrLength)-1] , arr[GenerateRandomNumber(1, arrLength)]);
    }
}

static void FillArrayWithRandomNumbers(int arr[100], int arrLength, short from, short to){
 
   for(int x = 0; x < arrLength; x++){
    arr[x] = GenerateRandomNumber(from, to);
   }
}

static void FillArrayWithRandomWords(string arr[100], int arrLength){
 
   for(int x = 0; x < arrLength; x++){
    arr[x] = GenerateWord();
   }
}

static  string Tab(short tapAmount){
    string tap = "";
   for(int x = 1; x <= tapAmount; x++){
    tap= tap+"\t";
   }

   return tap;
 }

 static string EncryptText(string text, short encryptionKey){
    for(int x = 0; x <= text.length(); x++){
        text[x] = char((int) text[x] + encryptionKey);
    }

    return text;

}

static string DecryptText(string encryptedText, short encryptionKey){
    for(int x = 0; x <= encryptedText.length(); x++){
        encryptedText[x] = char((int) encryptedText[x] - encryptionKey);
    }

    return encryptedText;

}

static string ConvertNumberToText(int number){
   if(number == 0){
    return "";
   } 

   if(number >= 1 && number <= 19){
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight",
        "Nine", "Ten", "Eleven", "Twelve", "Therteen", "Fourteen", "Fifteen", "Sixteen",
       "Seventeen", "Eighteen", "Ninteen"};

       return arr[number] + " ";
   }
   
   if(number >= 20 && number <= 99){
    string arr[] = {"","", "Twenty", "Thirty", "Fourty", "Fifety","Sixty", "Seventy", "Eighty", "Ninety"};
    return arr[number / 10] + " " + ConvertNumberToText(number % 10);
   } 

   if(number >= 100 && number <= 199){
    return "One Hundred " + ConvertNumberToText(number % 100);
   }

   if(number >= 200 && number <= 999){
    return ConvertNumberToText(number /100) + "Hundreds " + ConvertNumberToText(number % 100);
   }

   if(number >= 1000 &&  number <= 1999){
    return "One Thousand " + ConvertNumberToText(number % 1000);
   }

   if(number >= 2000 && number < 999999){
    return ConvertNumberToText(number / 1000) + "Thousands " + ConvertNumberToText(number % 1000);
   }

   if(number >= 1000000 && number <= 1999999){
    return "One Million " + ConvertNumberToText(number % 1000000);
   }

   if(number >= 2000000 && number <= 999999999){
    return ConvertNumberToText(number / 1000000) + "Million " + ConvertNumberToText(number % 1000000);
   }

   if(number >= 1000000000 && number <= 1999999999){
    return "One Billion " + ConvertNumberToText(number % 1000000000);
   }

   else if(number >= 2000000000) {
    return ConvertNumberToText(number / 1000000000) + "Billion " + ConvertNumberToText(number % 1000000000);
   }

   return "Stack overflow number.";

   }


};