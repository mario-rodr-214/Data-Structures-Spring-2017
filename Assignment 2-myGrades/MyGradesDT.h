//       Author / s : Mario Rodriguez(#40) Kyle Smith(#46)
//       Due Date : 2/22/2017
//       Programming Assignment Number 2
//       Spring 2017 - CS 3358 - Section Number 2
//
//       Instructor: Husain Gholoom.
//
//       This file is the header file which defines the class

#ifndef MYGRADESDT_H_INCLUDED
#define MYGRADESDT_H_INCLUDED

#include <iostream>
#include <vector>


using namespace std;


class myGrades
{
private:
    vector<double> quizGrade;//vector to hold quiz grades
    vector<double> midGrades;//vector to hold test grades
    vector<double> progrAssign;//vector to hold programming assignment grades


public:
    myGrades();

    void setQuiz();//sets quiz grades
    void setPro();//sets programming assignment grades
    void setTest();//sets tests grades
    void showQuiz();//displays quiz and average grades
    void showPro();//displays programming assignments and averages
    void showTest();//displays test and averages
    void showGrade();//calculates and displays the overall grade

};

#endif // MYGRADESDT_H_INCLUDED
