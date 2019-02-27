//     Roster Numbers: 40
//
//     Authors: Mario Rodriguez
//     Due Date: 4/27/2017
//     Programming Assignment Number 7
//
//     Spring 2017 - CS 3358 - section 2
//
//     Instructor: Husain Gholoom.
//     This programs generates a empty array of integers. Then populates half
//     of the the array with random integers according to the hash function
//     Generated_Num%Array_size. This is a menu driven program that allows the
//     user to display, search, insert, and delete a specific value from the
//     the array.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int size = 30; //size of array

class Hashed
{
    public:
        Hashed();
        ~Hashed();
        void display();
        int hashFnct(int);
        void insert(int, int &, int &);
        int search(int);
        void deleteNum(int);

    private:
        int myArray[size]; //array of ints

};
int main()
{
    Hashed myTable;

    int posCount = 0; //the amount a position is hashed
    int collisonCount = 0; //the amount of collisions
    bool loopAgain = true;//used to loop the menu
    int userChoice;//holds the menu option inputed by the user
    int halfSize = size/2;//used as counter to insert half random integers
    int key;//holds the value for the function the user wishes to use
    bool validInt = false; //used to check for a valid input

    srand( time(NULL));
    for(int i = 0; i < halfSize; i++)
    {
        int randNum = rand()% 400 + 100;
        myTable.insert(randNum, posCount, collisonCount);
    }

    cout << "***Welcome to my Hash Program***\n" << endl;
    myTable.display(); //displays the table that has been generated
    while(loopAgain)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1.Display the Table"<<endl;
        cout<<"2.Search element from the Table"<<endl;
        cout<<"3.Insert element into the Table"<<endl;
        cout<<"4.Delete element from the Table"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin >> userChoice;
        if(userChoice >= 1 && userChoice <= 5)
            validInt = true;

        else if(!cin)
        {
				cout << "\n*****Error***Incorrect input*****\n";
                cin.clear();
				cin.ignore(100,'\n');
        }
        else
        {
            cout << "\n\nError *** Number must be > 1 and <= 5" << endl << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        if(validInt)
        {
            bool validNum = false;
            switch(userChoice)
            {
                case 1:
                    myTable.display();
                    break;
                case 2:
                    cout<<"\nEnter Integer to be searched between 100 and 500: ";
                    cin >> key;
                    if(key >= 100 && key <= 500)
                        validNum = true;
                    else if(!cin)
                    {
                        cout << "\n*****Error***Incorrect input*****\n";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    else
                    {
                        cout << "\n\nError *** Number must be > 100 and <= 500" << endl << endl;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                    if(validNum)
                    {
                       cout << "Searching for " << key << "....\n";
                       if(myTable.search(key) == -1)
                        cout << key << " was not found within the Hash Table.\n";
                       else
                        cout << key << " is found at postion " << " " << myTable.search(key);
                    }

                    break;
                case 3:
                    cout<<"Enter Integer to be inserted between 100 and 500: ";
                    cin>>key;
                    if(key >= 100 && key <= 500)
                        validNum = true;
                    else if(!cin)
                    {
                        cout << "\n*****Error***Incorrect input*****\n";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    else
                    {
                        cout << "\n\nError *** Number must be > 100 and <= 500" << endl << endl;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                    if(validNum)
                    {
                        cout << "Inserting " << key << "....\n";
                        myTable.insert(key, posCount, collisonCount);
                    }
                    break;
                case 4:
                    cout<<"Enter Integer to be deleted from the table between 100 and 500: ";
                    cin>>key;
                    if(key >= 100 && key <= 500)
                        validNum = true;
                    else if(!cin)
                    {
                        cout << "\n*****Error***Incorrect input*****\n";
                        cin.clear();
                        cin.ignore(100,'\n');
                    }
                    else
                    {
                        cout << "\n\nError *** Number must be > 100 and <= 500" << endl << endl;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                    if(validNum)
                    {
                        cout << "Deleting " << key << "....\n";
                        myTable.deleteNum(key);
                    }
                    break;
                case 5:
                    cout <<"The number of times each position / location is hashed "
                         << posCount << endl;
                    cout <<"The number of linear probes each number is hashed and \n"
                         <<"collisions occurred is " << collisonCount << endl;
                    cout <<"\nThis Hash program is implemented by Mario Rodriguez" << endl;
                    cout <<"April 26th - 2017\n" ;
                    return 0;

        }
        }}

    return 0;
}

//***********************************************
//This function initializes all the elements
//of the array to -1, which is empty.
//
//returns nothing.
//***********************************************
Hashed::Hashed()
{
    //sets hash entire table to -1 empty
    for(int i = 0; i < size; i++)
    {
        myArray[i] = -1;
    }

}
int Hashed::hashFnct(int Num)
{
    return Num % size;
}
//***********************************************
//This function displays the hash table.
//
//returns nothing.
//***********************************************
void Hashed::display()
{
    cout << "\nCurrent Table Values:\n";
    for(int i=0; i < size/2; i++)
    {
        cout  << myArray[i] << "  ";
    }
    cout << endl;
    for(int i = size/2; i < size; i++)
    {
        cout << myArray[i] << "  ";
    }
}
//***********************************************
//This function inserts a number into the table
//according to the hash function.
//
//value: the number to insert into the table
//positionCount: the counter for the number of positions hashed
//probeCount: the counter the amount of linear probe collisions
//returns nothing.
//***********************************************
void Hashed::insert(int value, int &positionCount, int &probeCount)
{
        int temp = value; //makes copy of incoming value
        int hashNum = value%size; //hash function

        while(myArray[hashNum] != -1 && myArray[hashNum] != value)
        {
            temp = temp+1;
            hashNum = temp%size; //new index from collision
            probeCount++; //probe counter
        }

        myArray[hashNum] = value;
        positionCount++;
}
//***********************************************
//This function searches for a number from the table.
//
//value: the number to search within the table
//returns the position in the array.
//***********************************************
int Hashed::search(int value)
{
    for(int i=0; i<size; i++)
    {
        if(myArray[i] == value)
        {
            return i;
        }
    }

    return -1;
}
//***********************************************
//This function deletes a number from the table.
// calls the search function to receive the
// index of the value. If the search function
//returns -1, the value is not found. Otherwise,
//deletes the number from the position and sets it
//as -1.
//
//value: the number to delete
//returns nothing.
//***********************************************
void Hashed::deleteNum(int value)
{
    int position = search(value);

    if (position == -1)
    {
        cout << value <<" Was Not Found.\n";
        return;
    }
    while(position < size - 1)
    {
        myArray[position] = myArray[position + 1];
        position++;
    }
    myArray[size-1] = -1;
    cout << value << " Was Deleted From The Table.";
}
//**************************************
//this function deletes the array used for the table
//
//returns nothing
//****************************************
Hashed::~Hashed()
{
    delete [] myArray;
}
