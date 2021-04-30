#include <iostream>
//#include <boost/algorithm/string.hpp>
#include <string>

//class used for logging certian things and to automatically disabling these things.
class Logger
{
    private:

    bool log = true;

    public:


    //Gets a char array and outputs it into the terminal also ending the line
    void LoggingChar(const char* Lin)
    {


        if(log == true)
        {
        std::cout << "> " << Lin << std::endl;
        }


        else
        {
            std::cout << ">";
        }


    }

    //Same as LoggingChar but doesn't end the line technically not done yet
    void LoggingCharL(const char* Lin)
    {
        std::cout << "> " << Lin;
    }

    
    //This is supposed to log a array specifically a bool array not tested yet..
    void LogBoolArray(bool *boolin)
    {
        for (int ter = 0; ter < sizeof(boolin); ter++)
        {
            std::cout << *(boolin+ter);
        }
    }
    //Changes whether or not the logging is enabled or not.
    void TrueOrFalse(bool boolin)
    {
        log = boolin;
    }

};

//initializes a class for this.
Logger Lg;

//Number litterals that are required to check whether or not the numbers are numbers.
const char NumberLiterals[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

const char OperatorLiterals[4] = {'+', '/', '*', '-'};

//This is a function to check if the certian parts of a string have a number
bool * Check_For_Numbers(std::string Input)
{
    
    Lg.LoggingChar("Creating Is Number in Check_For_Numbers function with size of {Input.size}");
    bool* IsNumber = new bool[Input.size()];

    Lg.LoggingChar("Initializing IsNumber within Check for numbers");
    for (int t = 0; t < Input.size(); t++)
    {
        IsNumber[t] = 0;
    }

    Lg.LoggingChar("Starting Checking of Integers.");
    for (int i = 0; i < Input.size(); i++)
    {



        for (int t = 0; t < sizeof(NumberLiterals); t++)
        {



            if (Input[i] == NumberLiterals[t])
            {
                IsNumber[i] = true;
                break;
            }


            else
            {
                IsNumber[i] = false;
            }



        }



    }

    return IsNumber;

}


std::string Grouper(std::string InString, bool* IsNumb)
{   
    int Groups = 0;
    int i = 0;
    
    for (i < InString.size(); i++;)
    {
        if (*(IsNumb+i) != true)
        {
            Groups = Groups + 2;
        }
    }
    std::cout << Groups;

    return "test";
}

//This is to remove spaces within the inputed string so it makes things easier for me.
std::string NoSpace(std::string IN)
{
    std::string string = "";

    for (int index = 0; index < IN.size(); index++)
    {
        if(IN[index] != ' ')
        {
            string = string + IN[index];
            
        }
        else
        {
            Lg.LoggingChar("There is a Space");
        }
    }

    return string;
}

bool * Check_For_Operators(std::string instr)
{
    bool* IsOperator = new bool[instr.size()];

    for (int i = 0; i < instr.size(); i++)
    {
        for (int j = 0; j < sizeof(OperatorLiterals); j++)
        {
            if(instr[i] == OperatorLiterals[j])
            {
                IsOperator[i] = true;
                break;
            }
            else
            {
                IsOperator[i] = false;
            }
        }
    }

    return IsOperator;
}

int main()
{
    //Initiates the string variable that obtains input from get line.
    std::string Input = "";

    //std::string Final_Use = "";


    //std::string test = "This is a test";

    
    Lg.LoggingChar("Initialized the Input variable");

    getline(std::cin, Input);

    Lg.LoggingChar("getline inputed");

    Input = NoSpace(Input);

    std::cout << "> " << Input << std::endl;

    bool *IsNumber;

    bool *IsOperator;

    Lg.LoggingChar("Is number initialized");

    IsNumber = Check_For_Numbers(Input);

    IsOperator = Check_For_Operators(Input);

    std::string test = Grouper(Input, IsNumber);

    Lg.LoggingChar("Check number is inputed to is number");

    std::cout << "> ";

    for (int terms = 0; terms < Input.size(); terms++)
    {
       std::cout << *(IsNumber+terms);
    }
   
    std::cout << std::endl;

    std::cout << "> ";

    for (int terms = 0; terms < Input.size(); terms++)
    {
        std::cout << *(IsOperator+terms);
    }


    std::cout << std::endl;


}