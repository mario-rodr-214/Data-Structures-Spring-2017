//       Author / s : Mario Rodriguez(#40) Kyle Smith(#46)
//       Due Date : 2/22/2017
//       Programming Assignment Number 2
//       Spring 2017 - CS 3358 - Section Number 2
//
//       Instructor: Husain Gholoom.
//
//       This file defines the functions inside of the class.

#include "MyGradesDT.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

//*************************************************
//  the constructor, sets midGrades max value to 2
//
//  returns nothing
//*************************************************
myGrades::myGrades()
{
    midGrades.reserve(2);
}

//*************************************************
//  takes a number from the user and inserts it into the
//  quiz vector if it is valid
//
//  returns nothing
//*************************************************
void myGrades::setQuiz()
{
    double num;

    cout << "Enter a Quiz grade:    ";
    try
    {
        cin >> num;
        if(!cin)
        {
            cin.clear();
            cin.ignore(100,'\n');
            throw "\nERROR *** You entered a character";
        }
        if(num<0 || num>10)
        {
            throw "Not a valid number. Quiz grades are recorded by the scale of 0-10";
        }
    }
    catch (const char* msg)
    {
        cout << msg << endl << endl << endl;
        return;
    }

    quizGrade.push_back(num);
}

//*************************************************
//  checks to see if the quiz vector is empty, if it is
//  the function states that and returns, if the vector is
//  not empty, the function shows the grades in the vector and
//  calculates the average of the grades in the vector
//
//  returns nothing
//*************************************************
void myGrades::showQuiz()
{
    double avgNum = 0.0;
    //displays output for no quiz grades
    cout << "show all Quiz grade with average.\n";
    if(quizGrade.size() == 0)
    {
        cout << "No Quiz grades are recorded" << endl;
        return;
    }

    cout     << "Quiz Grades are As Follows\n";
    cout << fixed << setprecision(2);



    for(int j=0; j<quizGrade.size(); j++)
    {
         cout << quizGrade[j] << " ";
         avgNum+= quizGrade[j];
    }
    avgNum /= quizGrade.size();

    cout << "\nAverage Quiz Grades is " << avgNum << " Out of  10" << endl;
}

//*************************************************
//  takes a number from the user and inserts it into the
//  assignment vector if it is valid
//
//  returns nothing
//*************************************************
void myGrades::setPro()
{
    double num;

    cout << "Enter a Programing assignment grade:    ";
    try
    {
        cin >> num;
        if(!cin)
        {
            cin.clear();
            cin.ignore(100,'\n');
            throw "\nERROR *** You entered a character";
        }
        if(num<0 || num>10)
        {
            throw "Not a valid number. Programing assignments are recorded by the scale of 0-10";
        }
    }
    catch (const char* msg)
    {
        cout << msg << endl << endl << endl;
        return;
    }

    progrAssign.push_back(num);

}

//*************************************************
//  checks to see if the assignment vector is empty, if it is
//  the function states that and returns, if the vector is
//  not empty, the function shows the grades in the vector and
//  calculates the average of the grades in the vector
//
//  returns nothing
//*************************************************
void myGrades::showPro()
{
    double avgNum;
    cout << "Show All Programming Assignment grades with Average.\n";
    //display output for no test grades
    if(progrAssign.size() == 0)
    {
        cout << "No Programming assignment grades are recorded" << endl;
        return;
    }




    cout << "Programming Assignment Grades are As Follows\n";
    cout << fixed << setprecision(2);


    //find average
    for(int j=0; j<progrAssign.size(); j++)
    {
        cout << progrAssign[j] << "  ";
        avgNum += progrAssign[j];
    }
    avgNum /= progrAssign.size();
    avgNum *= 2;
    cout << "\nAverage Programming Assignments Grades is " << avgNum << " Out of  20" << endl;
}

//*************************************************
//  takes a number from the user and inserts it into the
//  test vector if it is valid
//
//  returns nothing
//*************************************************
void myGrades::setTest()
{
    double num;

    if(midGrades.size() >= 2)
    {
        cout << "Reached maximum number of Test Grades";
        return;
    }

    cout << "\nEnter a test grade:    ";
    try
    {
        cin >> num;
        if(!cin)
        {
            cin.clear();
            cin.ignore(100,'\n');
            throw "\nERROR *** You entered a character";
        }
        if(num<0 || num>20)
        {
            throw "Not a valid number. tests are recorded by the scale of 0-20";
        }
    }
    catch (const char* msg)
    {
        cout << msg << endl << endl << endl;
        return;
    }

    midGrades.push_back(num);
}

//*************************************************
//  checks to see if the test vector is empty, if it is
//  the function states that and returns, if the vector is
//  not empty, the function shows the grades in the vector and
//  calculates the average of the grades in the vector
//
//  returns nothing
//*************************************************
void myGrades::showTest()
{
    double num;

    cout << "Show All Test grades with Average.\n";
    //display output for no test grades
    if(midGrades.size() == 0)
    {
        cout << "\nNo Test grades are recorded" << endl;
        return;
    }

    cout << "Test Grades are As Follows\n";
    cout << fixed << setprecision(2);


    //find average
    for(int j=0; j<midGrades.size(); j++)
    {
        cout << midGrades[j] << " ";
        num += midGrades[j];
    }
    if(midGrades.size() == 1)
    {
        cout << "\nAverage Test Grades is " << num << " Out of  20" << endl;
    }
    if(midGrades.size() == 2)
    {
        cout << "\nAverage Test Grades is " << num << " Out of  40" << endl;
    }

}

//*************************************************
//  the function calculates the overall grade in the class
//  by taking the average of all grades in each vector if not empty
//  and calculates the overall grade based on all existing averages.
//
//  returns nothing
//*************************************************
void myGrades::showGrade()
{
   double total = 0.0;
   double avgNum = 0.0;
   double points = 0.0;

   cout << "Show Overall All Grades.\n";
   if (quizGrade.size() == 0)
   {
       cout << "\n no quizzes are recorded";
   }
   else
   {
       total += 10.0;

       cout << "\n\nquiz grades are as follows\n";
       for(int j=0; j<quizGrade.size(); j++)
       {
          cout << quizGrade[j] << " ";
          avgNum+= quizGrade[j];
       }
       avgNum /= quizGrade.size();
       cout << "\n average quiz grades is " << avgNum << " out of 10" << endl;
   }

   points =+ avgNum;
   avgNum = 0.0;
   if (progrAssign.size() == 0)
   {
       cout << "\n no programing grades are recorded";
   }
   else
   {
       total += 20.0;

       cout << "\n\nprograming assignment grades are as follows\n";
       for(int j=0; j<progrAssign.size(); j++)
       {
          cout << progrAssign[j] << " ";
          avgNum+= progrAssign[j];
       }
       avgNum /= progrAssign.size();
       avgNum *= 2;
       cout << "\n average programing assignment grades is " << avgNum << " out of 20" << endl;
   }

   points += avgNum;
   avgNum = 0.0;
   if (midGrades.size() == 0)
   {
       cout << "\n no test grades are recorded";
   }
   else if (midGrades.size() == 1)
   {
       total += 20.0;
       cout << "\n\ntest grades are as follows\n";
       for(int j=0; j<midGrades.size(); j++)
       {
          cout << midGrades[j] << " ";
          avgNum+= midGrades[j];
       }
       cout << "\n average programing assignment grades is " << avgNum << " out of 20" << endl;
   }
   else if (midGrades.size() == 2)
   {
       total += 40.0;
       cout << "\n\ntest grades are as follows\n";
       for(int j=0; j<midGrades.size(); j++)
       {
          cout << midGrades[j] << " ";
          avgNum+= midGrades[j];
       }
       cout << "\n average programing assignment grades is " << avgNum << " out of 40" << endl;
   }
   points += avgNum;

   cout << "\n\nOverall Total   -- >    " << points << " out of " << total;
}