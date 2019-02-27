//     Roster Numbers: 40/46
//
//     Authors: Mario Rodriguez/Kyle Smith
//     Due Date: 3/29/2017
//     Programming Assignment Number 6
//
//     Spring 2017 - CS 3358 - section 2
//
//     Instructor: Husain Gholoom.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


void sort(int *, int, int);
void displayArr(int [], int);
int powerFnct(int, int);
int sumOfSquares(int);
void bubbleSort(int[], int);


int main()
{
    bool loopAgain = true;
    char userChoice;

    cout << "Thinking Recursively\n" << endl;
    cout << "The function of this program is to\nuse recursion to  :-" << endl;
    cout << "       1.  Display squares of integers in ascending\n"
         << "           order from 1 to the last element in the array\n"
         << "       2.  Raise the first number to a power  2\n"
         << "       3.  Return the sums of squares of the numbers\n"
         << "           from 0 to a fifth element in the array\n"
         << "       4.  Search the array for the first value in the array\n"
         << "       5.  Sort the array in ascending order\n"
         << "       6.  Search the array for the first value in the array\n"
         << "       7.  Search the array for the number 600\n"
         << "       8.  Determine if a number is prime (processes all array values)\n";


    do
    {
        cout << "Select from the following menu\n";
        cout << "A. Enter Array Size that is > 4." << endl;
        cout << "X. Terminate the program.     ";
        cin >> userChoice;
        cout << "\n";

        if ((userChoice == 'x') || (userChoice == 'X'))
        {
            loopAgain = false;
        }

        else if ((userChoice == 'a') || (userChoice =='A'))
        {
            int size;
            cout << "Enter Array Size: ";
            cin >> size;
            //creates array of random integers based on input size
            srand(time(NULL));
            int xRan;
            int * myArr;
            myArr = new int[size];
            for( int i = 0; i < size; i++)
            {
                xRan=rand()%50+1;
                myArr[i] = xRan;
            }

            displayArr(myArr, size);

            //needs work
            //numArr.tableHelp();
            //numArr.powerHelp();
            //numArr.sumOfSquaresHelp();

            int temp = myArr[0];
            int Intpower = 2;

            cout <<"Power Function:" << endl;
            cout << temp << " raised to the 2nd power is: " << powerFnct(temp, Intpower)<<endl;
            cout << endl;

            int temp2 = myArr[size-2];
            cout << endl;
            cout <<"Sum of squares between 0 and " << temp2 << " is: " << sumOfSquares(temp2);
            cout << endl << endl;

            cout << "Sorted Array\n";
            bubbleSort(myArr, size);

            for(int i = 0; i < size; i++)
            {
                cout << myArr[i] << " ";
            }
            cout << endl << endl;
        }
        else
        {
            cout << "***   Invalid Option   ***" << endl << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }

    }
    while (loopAgain);


    cout << "***Program is terminated. Written by Kyle smith and Mario Rodriguez***" << endl;





    return 0;
}


void displayArr(int myArr[], int size)
{
    cout << "\nThe generated array is: ";
    for(int i = 0; i < size; i++)
    {
        cout << myArr[i] << " ";
    }
    cout << endl << endl;
}


int tableOfsq(int number)
{
    if(number == 0)
        return 1;
    int temp;
    temp = tableOfsq(number-1);
    cout <<number << "    "  << temp << endl;
    return number * number;
}
//void tableHelp()
//{
//    int lastVal = myArr[size-1];
//    cout << "Table of Square values 1 - " << lastVal << endl;
//    cout <<"N       N Squared" << endl;
//
//    tableOfsq(lastVal);
    //for(int i=1; i <= lastVal; i++){
    //    cout << left << setw(8) << i << right << tableOfsq(i) << endl;
   // }

//};


int powerFnct(int x, int y)
{
   if(y ==0)
        return (1);
   else if(y == 1)
        return (x);
   else
        return (x * powerFnct(x, y -1));
}

int sumOfSquares(int x)
{
    if(x==0)
        return 0;
    else
    {
        return (sumOfSquares(x-1)+(x*x));
    }
}

bool isPrime(int n, int d)
{
    if(n<2)
        return 0;
    if(d == 1)
        return true;
    else
    {
        if(n % d == 0)
            return false;
        else
            return isPrime(n, d - 1);
    }
}

void bubbleSort(int arr[], int n)
{

    if (n == 1)
        return;

    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    bubbleSort(arr, n-1);
}
