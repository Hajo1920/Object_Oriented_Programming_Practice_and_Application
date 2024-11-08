#pragma once
#include <iostream>
#include <limits>
#include "date_lib.h"

class clsInputValidator {
    private:

    protected:
      static short SearchNumber(short number, int arr[100], int arrLength){

    for(short x = 0; x <= arrLength; x++){
        if(number == arr[x]){
            return x;
        }
    }
    return -1;
}

    public:

 

static bool IsNumberInArray(short number, int arr[100], int arrLength){
    return SearchNumber(number, arr, arrLength) != -1;
}

static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number , int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate From, clsDate To, clsDate Date)
	{
		//Date>=From && Date<=To
		if ((clsDate::isDateOneAfterDatetwo(Date, From) || clsDate::isDateOneEqualsDatetwo(Date, From)) 
			&&
			(clsDate::isDateOneBeforeDatetwo(Date, To) || clsDate::isDateOneEqualsDatetwo(Date, To))
		  )
		{
			return true;
		}
		
		//Date>=To && Date<=From
		if ((clsDate::isDateOneAfterDatetwo(Date, To) || clsDate::isDateOneEqualsDatetwo(Date, To)) 
			&&
			(clsDate::isDateOneBeforeDatetwo(Date, From) || clsDate::isDateOneEqualsDatetwo(Date, From))
		   )
		{
			return true;
		}

		return false;
	}

   static short ReadShortInput(string msg){
    short num;
    do {
    cout << msg + " ";
    cin >> num;

    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter digit type only!";
        cin >> num;
    }

    } while (num < 0);

    return num;
}
   static int ReadIntInput(string msg){
    int num;
    do {
    cout << msg + " ";
    cin >> num;

    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter digit only!";
        cin >> num;
    }

    } while (num < 0);

    return num;
}

   static double ReadDoubleInput(string msg){
    double num;
    do {
    cout << msg + " ";
    cin >> num;

    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter digit only!";
        cin >> num;
    }

    } while (num < 0);

    return num;
}

   static short ReadShortNumberBetween(string msg, short from, short to){
    short num = ReadShortInput(msg);
  
    while(!IsNumberBetween(num,from, to)){
        cout << "Please enter number between " << from << " and " << to;
        cin >> num;
    }

    return num;
}

   static int ReadIntNumberBetween(string msg, int from, int to){
    int num = ReadIntInput(msg);
  
    while(!IsNumberBetween(num,from, to)){
        cout << "Please enter number between " << from << " and " << to;
        cin >> num;
    }

    return num;
}

   static double ReadDoubleNumberBetween(string msg, double from, double to){
    double num = ReadIntInput(msg);
  
    while(!IsNumberBetween(num,from, to)){
        cout << "Please enter number between " << from << " and " << to;
        cin >> num;
    }

    return num;
}

static string ReadString(string msg){
    string input = "";
    cout << msg << ": ";
    getline(cin >> ws, input);
    return input;
}

static bool isValidDate(clsDate Date){
	return clsDate::IsValidDate(Date);
}
};



