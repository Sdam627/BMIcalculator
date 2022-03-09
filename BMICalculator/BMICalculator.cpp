// Name:    Samuel Surdam
// NetID:   scs627
// Course:  CSE 4214
// Purpose: BMI Calcaulator for imperial system measurements.

#include <iostream>
#include <string>  
#include <set>
#include <iomanip>
using namespace std;

float weighttokg(float weight) {
    float kg;
    kg = weight * 0.45359237;

    cout << endl << "Your weight in kilograms is: " << kg << endl;
    return kg;
}

float feettoinch(float feet, float inches) {
    float m;
    m = ((feet * 12) + inches) * 0.0254;

    cout << "Your height in meters is: " << m << endl;
    return m;
}

float getweight() {
    float userweight;

    cout << endl << "What is your weight in pounds (lbs)?" << endl;
    //Validates the input is of the float type.

    /***************************************************************************************
    *    Title: Taking only integer input in C++
    *    Author: Animisha Dalal
    *    Date: 02/24/2022
    *    Code version: N/A
    *    Availability: https://www.codespeedy.com/taking-only-integer-input-in-cpp/
    ***************************************************************************************/
    while (true) {
        cin >> userweight;

        if (!cin || userweight < 0) {
            cout << "Wrong format. Please enter an integer or float value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else break;
    }

    return userweight;
}

float getheightfeet() {
    float userfeet;

    cout << endl << "(Excluding inches) Please enter your height in feet." << endl;

    /***************************************************************************************
    *    Title: Taking only integer input in C++
    *    Author: Animisha Dalal
    *    Date: 02/24/2022
    *    Code version: N/A
    *    Availability: https://www.codespeedy.com/taking-only-integer-input-in-cpp/
    ***************************************************************************************/
    while (true) {
        cin >> userfeet;
        if (!cin || userfeet < 0) {
            cout << "Wrong format. Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else break;
    }

    return userfeet;
}

float getheightinches() {
    float userinches;

    cout << endl << "Now, please, enter the inches part of your height." << endl;

    /***************************************************************************************
    *    Title: Taking only integer input in C++
    *    Author: Animisha Dalal
    *    Date: 02/24/2022
    *    Code version: N/A
    *    Availability: https://www.codespeedy.com/taking-only-integer-input-in-cpp/
    ***************************************************************************************/
    while (true) {
        cin >> userinches;
        if (!cin) {
            cout << "Wrong format. Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else break;
    }

    return userinches;
}

float calculatebmi(float weight, float feet, float inches)
{
    float convertedkg;
    convertedkg = weighttokg(weight);

    float convertedfeettoinch;
    convertedfeettoinch = feettoinch(feet, inches);

    float BMI;
    BMI = convertedkg / (convertedfeettoinch * convertedfeettoinch);

    cout << endl << "============= YOUR BMI IS: ============= " << endl;
    cout << endl << "BMI: " << fixed << setprecision(2) << BMI;
    if (BMI < 18.5) {
        cout << endl << "Your BMI is " << BMI << ", indicating your weight is in the UNDERWEIGHT category for adults of your height." << endl;
    }
    else if (18.5 <= BMI && BMI <= 24.9) {
        cout << endl << "Your BMI is " << BMI << ", indicating your weight is in the HEALTHY category for adults of your height." << endl;
    }
    else if (25 <= BMI && BMI <= 29.9) {
        cout << endl << "Your BMI is " << BMI << ", indicating your weight is in the OVERWEIGHT category for adults of your height." << endl;
    }
    else if (BMI >= 30) {
        cout << endl << "Your BMI is " << BMI << ", indicating your weight is in the OBESE category for adults of your height." << endl;
    }

    return BMI;
}


float correctinputs(float weight, float feet, float inches)
{
    /***************************************************************************************
    *    Title: Validating Yes/No in C++
    *    Author: bluegreen
    *    Date: 02/24/2022
    *    Code version: N/A
    *    Availability: https://codereview.stackexchange.com/questions/180842/validating-yes-no-answers-in-c
    ***************************************************************************************/
    string answer;
    set<string> yesAnswers = { "Y", "y", "yes", "YES", "Yes"};
    set<string> noAnswers = { "N", "n", "no", "NO", "No"};
    set<string> validAnswers;
    validAnswers.insert(yesAnswers.begin(), yesAnswers.end());
    validAnswers.insert(noAnswers.begin(), noAnswers.end());

    do
    {
        cout << endl << "============= YOUR MEASURMENTS ARE ============= " << endl << "Weight: " << weight << " lbs" << endl << "Height: " << feet << "'" << inches << "''" << endl;
        cout << endl << "============= IS THIS CORRECT? ============= " << endl;
        cout << "Enter [y/n]:" << endl;
    } while ((cin >> answer) && validAnswers.find(answer) == validAnswers.end());

    if (yesAnswers.find(answer) != yesAnswers.end()) {
        //calculate BMI
        calculatebmi(weight, feet, inches);
    }
    else if (noAnswers.find(answer) != noAnswers.end()) {
        float weight = getweight();
        float feet = getheightfeet();
        float inches = getheightinches();
        correctinputs(weight, feet, inches);
    }

    return 0;
}

int main()
{
    string iscorrect;

    cout << "============= BMI Calculator Version 1.0 =============" << endl;
    cout << "======================================================" << endl;
    float weight = getweight();
    float feet = getheightfeet();
    float inches = getheightinches();

    correctinputs(weight, feet, inches);
    cout << endl;

    return 0;
}
