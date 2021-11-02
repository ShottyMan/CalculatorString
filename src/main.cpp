#include <iostream>
//#include <boost/algorithm/string.hpp>
#include <string>
#include <sstream>

//rewrite to true to turn on debbugger.
bool Debug = true;

//class used for logging certian things and to automatically disabling these things.
class Logger
{
private:
    bool log = true;

public:
    //Gets a char array and outputs it into the terminal also ending the line
    void LoggingChar(const char *Lin, char option)
    {

        if (log == true && option == 'n')
        {

            std::cout << "> " << Lin << std::endl;
        }

        if (log == true && option == 'l')
        {

            std::cout << "> " << Lin;
        }

        else
        {
            std::cout << ">";
        }
    }

    //Same as LoggingChar but doesn't end the line technically not done yet

    //This is supposed to log a array specifically a bool array not tested yet..
    void LogBoolArray(bool *boolin)
    {
        for (int ter = 0; ter < sizeof(boolin); ter++)
        {
            std::cout << *(boolin + ter);
        }
    }
    //Changes whether or not the logging is enabled or not.
    void SetLog(bool boolin)
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
bool *CheckForNumbers(std::string Input)
{

    Lg.LoggingChar("Creating Is Number in Check_For_Numbers function with size of {Input.size}", 'n');
    bool *IsNumber = new bool[Input.size()];

    Lg.LoggingChar("Initializing IsNumber within Check for numbers", 'n');
    for (int t = 0; t < Input.size(); t++)
    {
        IsNumber[t] = 0;
    }

    Lg.LoggingChar("Starting Checking of Integers.", 'n');
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

//This grouper function counts the groups and groups the numbers and expressions accordingly.
std::string *InputItemGrouper(std::string InString, bool *IsNumb, bool *IsOperator, int &ArraySize)
{
    Lg.LoggingChar("Beginning Grouper Function and initializing integers", 'n');
    int Groups = 0;

    int static times = 0;

    Lg.LoggingChar("Initializing the loop", 'n');

    //This is where the counting for the groups is done.
    for (int i = 0; i < InString.size(); i++)
    {

        Lg.LoggingChar("Initialzes the nested loop", 'n');

        if (i == (InString.size() - 1))
        {
            Lg.LoggingChar("End of string adding 1 more groups.", 'n');
            std::cout << "> Index is: " << i << std::endl;
            Groups = Groups + 1;
        }

        else if (*(IsNumb + i) != 1 && i != (InString.size() - 1))
        {

            Lg.LoggingChar("Adding to groups var", 'n');
            std::cout << "> Index is: " << i << std::endl;
            if (*(IsNumb + i) == *(IsNumb + (i + 1)))
            {
                Groups = Groups + 3;
                i = i + 1;
            }

            else
            {
                Groups = Groups + 2;
            }
        }

        else
        {

            Lg.LoggingChar("Condition Not met", 'n');

            std::cout << "> Index is: " << i << std::endl;
        }
    }

    std::string *Index = new std::string[Groups];

    ArraySize = Groups;

    //This is where the groups will actually be made.
    for (int stringindex = 0; stringindex < Groups; stringindex++)
    {
        Lg.LoggingChar("Intializing the Second loop for indexing of the groups.", 'n');
        static int Starter = 0;

        for (int i = Starter; i < InString.size(); i++)
        {
            Lg.LoggingChar("Starting nested loop for the indexing of the groups.", 'n');
            //Tells where to start the loop to add to array.

            if (i == (InString.size() - 1))
            {
                for (int x = Starter; x <= i; x++)
                {

                    *(Index + stringindex) = *(Index + stringindex) + InString[x];
                    if (Debug == true)
                    {
                        std::cout << "> " << InString[x] << std::endl;
                    }
                }
                break;
            }

            else if (*(IsNumb + i) != 1 && i != (InString.size() - 1))
            {

                for (int x = Starter; x < i; x++)
                {

                    *(Index + stringindex) = *(Index + stringindex) + InString[x];
                    if (Debug == true)
                    {
                        std::cout << "> " << InString[x] << std::endl;
                    }
                }

                *(Index + stringindex + 1) = *(Index + stringindex + 1) + InString[i];

                Starter = i + 1;

                stringindex = stringindex + 1;

                break;
            }
        }
    }

    std::cout << "> "
              << "Groups are: " << Groups << " Is Numb is: " << *IsNumb << std::endl;

    return Index;
}

//This is to remove spaces within the inputed string so it makes things easier for me.
std::string SpaceRemover(std::string IN)
{
    std::string string = "";

    for (int index = 0; index < IN.size(); index++)
    {
        if (IN[index] != ' ')
        {
            string = string + IN[index];
        }
        else
        {
            Lg.LoggingChar("There is a Space", 'n');
        }
    }

    return string;
}

//This part checks for the operators withint he expression being inputed in.
bool *CheckForOperators(std::string instr)
{
    bool *IsOperator = new bool[instr.size()];

    for (int i = 0; i < instr.size(); i++)
    {
        for (int j = 0; j < sizeof(OperatorLiterals); j++)
        {
            if (instr[i] == OperatorLiterals[j])
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

    int ArraySize = 0;

    //std::string test = "This is a test";

    Lg.LoggingChar("Initialized the Input variable", 'n');

    getline(std::cin, Input);

    Lg.LoggingChar("getline inputed", 'n');

    Input = SpaceRemover(Input);

    std::cout << "> Input size is: " << Input.size() << std::endl;

    std::cout << "> " << Input << std::endl;

    bool *IsNumber;

    bool *IsOperator;

    Lg.LoggingChar("Is number initialized", 'n');

    IsNumber = CheckForNumbers(Input);

    IsOperator = CheckForOperators(Input);

    std::string *GroupedItems = InputItemGrouper(Input, IsNumber, IsOperator, ArraySize);

    if (Debug == true)
    {
        for (int terms = 0; terms < ArraySize; terms++)
        {
            std::cout << "> ";
            std::cout << *(GroupedItems + terms) << std::endl;
        }
    }

    Lg.LoggingChar("Check number is inputed to is number", 'n');

    /*for (int terms = 0; terms < Input.size(); terms++)
    {
       std::cout << *(IsNumber+terms);
    }*/

    /*for (int terms = 0; terms < Input.size(); terms++)
    {
        std::cout << *(IsOperator+terms);
    }*/

    int StepsNumbers = (.5 * ArraySize) - .5;

    //Terms within a function can be found with the equation terms = (1/2*x)-.5 with x being the amount of operators and numbers.

    double CalculationResults[StepsNumbers];

    int CurrentStep = 0;

    //This is where all of the addition and subtraction should take place.

    for (int CurrentLoopIndex = 0; CurrentLoopIndex <= ArraySize; CurrentLoopIndex++)
    {

        //Addition Part
        if (*(GroupedItems + CurrentLoopIndex) == "+" && CurrentLoopIndex == ((ArraySize - ArraySize) + 1))
        {

            float FirstAdditionTerm = std::stof(*(GroupedItems + CurrentLoopIndex - 1));

            float SecondAdditionTerm = std::stof(*(GroupedItems + CurrentLoopIndex + 1));

            CalculationResults[CurrentStep] = FirstAdditionTerm + SecondAdditionTerm;
            CurrentStep = CurrentStep + 1;
        }

        else if (*(GroupedItems + CurrentLoopIndex) == "+" && CurrentLoopIndex != ArraySize)
        {

            float NextTermAdded = std::stof(*(GroupedItems + CurrentLoopIndex + 1));

            CalculationResults[CurrentStep] = CalculationResults[CurrentStep - 1] + NextTermAdded;

            CurrentStep++;
        }

        else if (*(GroupedItems + CurrentLoopIndex) == "-" && CurrentLoopIndex == ((ArraySize - ArraySize) + 1))
        {

            float FirstSubtractionTerm = std::stof(*(GroupedItems + CurrentLoopIndex - 1));

            float SecondSubtractionTerm = std::stof(*(GroupedItems + CurrentLoopIndex + 1));

            CalculationResults[CurrentStep] = FirstSubtractionTerm - SecondSubtractionTerm;
            CurrentStep = CurrentStep + 1;
        }

        else if (*(GroupedItems + CurrentLoopIndex) == "-" && CurrentLoopIndex != ArraySize)
        {

            float NextTermSubtracted = std::stof(*(GroupedItems + CurrentLoopIndex + 1));

            CalculationResults[CurrentStep] = CalculationResults[CurrentStep - 1] - NextTermSubtracted;

            CurrentStep++;
        }

        else
        {
        }
    }

    std::cout << "\nThis Result should be printed\n";

    std::cout << "The calculation result is: " << CalculationResults[StepsNumbers - 1] << std::endl;

    delete IsNumber;

    delete IsOperator;

    delete[] GroupedItems;
}