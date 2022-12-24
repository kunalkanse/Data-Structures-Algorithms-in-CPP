
// This program demonstrate the implementation of the STACK in C++.
// CUI (command user interface) Application.
// menu driven code for GENERIC STACK.
// As A generic Works for Any DataType

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// structure decleration
//-------------------------------------------------------------------
////////////////////////////////////////////////////////////////////

template <class T>
struct node
{
    int data;
    struct node *next;
};

///////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// class decleration
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
private:
    node<T> *first;
    int size;

public:
    Stack();
    void Push(T);
    void Pop();

    void Display();
    int Count();
};

///////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function definations
//----------------------------------------------------------------
///////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Constructor
// Description : used to initialise resources
// parameters : NONE
// return value : NONE
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
Stack<T>::Stack()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Display
// Description : used to Display List
// parameters :
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Display()
{
    node<T> *temp = first;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }

    cout << "NULL";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Count
// Description : used to Count Elements of Queue
// parameters :
// return value : int
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::Count()
{
    return size;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Push
// Description : used to insert Data At Last position
// parameters : data of node
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Push(T no)
{
    node<T> *newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    size++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Pop
// Description : used to delete Data At last position
// parameters : 
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Pop()
{
    node<T> *temp = first;

    if (temp != NULL)
    {
        first = first->next;

        delete temp;

        size--;
    }
}

//////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------
// main function
//-------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////

int main()
{

    Stack<int> IObj;
    Stack<float> FObj;
    Stack<char> CObj;

    int type = 1, iRet = 0, iChoice = 1;

    int iData = 0, fData = 0, cData = 0;

    while (type != 0)
    {
        cout << "\n------------------------------------------------------------\n";
        cout << "\nEnter the proper choice to slect data : \n";
        cout << "\n 1 : To integer Data\n";
        cout << " 2 : To Decimal Data\n";
        cout << " 3 : To Character Data\n";
        cout << " 0 : To terminate the Application\n";
        cout << "\n---------------------------------------------------------------\n";

        cout << "\nEnter the choice : ";
        cin >> type;

        switch (type)
        {
        case 1:

            while (iChoice != 0)
            {
                cout << "\n------------------------------------------------------------\n";
                cout << "Enter the proper choice to perform operations : \n";
                cout << "\n 1 : To push the data\n";
                cout << " 2 : To pop the data\n";
                cout << " 3 : To display data\n";
                cout << " 4 : To Count the elements\n";
                cout << " 0 : To terminate\n";
                cout << "\n---------------------------------------------------------------\n";

                cout << "\nEnter the choice : ";
                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "\nEnter the data : ";
                    cin >> iData;

                    IObj.Push(iData);
                    break;

                case 2:
                    IObj.Pop();
                    break;

                case 3:
                    IObj.Display();
                    cout << endl;
                    break;

                case 4:
                    iRet = IObj.Count();
                    cout << "\nCount is : " << iRet << endl;
                    break;

                case 0:
                    cout << "-------------------------------------------------------\n";
                    cout << "terminating Integer Stack\n";
                    cout << "Back to main menu...............\n";
                    cout << "-------------------------------------------------------\n";
                    break;

                default:
                    cout << "-------------------------------------------------------\n";
                    cout << "\nInvalid Choice\nEnter Again...............\n";
                    cout << "-------------------------------------------------------\n";
                    break;
                }
            }

            break;

        case 2:
            while (iChoice != 0)
            {
                cout << "\n------------------------------------------------------------\n";
                cout << "\nEnter the proper choice to perform operations : \n";
                cout << "\n 1 : To push the data\n";
                cout << " 2 : To pop the data\n";
                cout << " 3 : To display data\n";
                cout << " 4 : To Count the elements\n";
                cout << " 0 : To terminate\n";
                cout << "\n---------------------------------------------------------------\n";

                cout << "\nEnter the choice : ";
                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "\nEnter the data : ";
                    cin >> fData;

                    FObj.Push(fData);
                    break;

                case 2:
                    FObj.Pop();
                    break;

                case 3:
                    FObj.Display();
                    cout << endl;
                    break;

                case 4:
                    iRet = FObj.Count();
                    cout << "\nCount is : " << iRet << endl;
                    break;

                case 0:
                    cout << "\n-------------------------------------------------------\n";
                    cout << "terminating Integer Stack\n";
                    cout << "Back to main menu...............\n";
                    cout << "-------------------------------------------------------\n";
                    break;

                default:
                    cout << "\n-------------------------------------------------------\n";
                    cout << "\nInvalid Choice\nEnter Again...............\n";
                    cout << "-------------------------------------------------------\n";
                    break;
                }
            }

            break;

        case 3:

            while (iChoice != 0)
            {
                cout << "\n------------------------------------------------------------\n";
                cout << "\nEnter the proper choice to perform operations : \n";
                cout << "\n 1 : To push the data\n";
                cout << " 2 : To pop the data\n";
                cout << " 3 : To display data\n";
                cout << " 4 : To Count the elements\n";
                cout << " 0 : To terminate\n";
                cout << "\n---------------------------------------------------------------\n";

                cout << "\nEnter the choice : ";
                cin >> iChoice;

                switch (iChoice)
                {
                case 1:
                    cout << "\nEnter the data : ";
                    cin >> cData;

                    CObj.Push(cData);
                    break;

                case 2:
                    CObj.Pop();
                    break;

                case 3:
                    CObj.Display();
                    cout << endl;
                    break;

                case 4:
                    iRet = CObj.Count();
                    cout << "\nCount is : " << iRet << endl;
                    break;

                case 0:
                    cout << "\n---------------------------------------\n";
                    cout << "terminating Integer Stack\n";
                    cout << "Back to main menu...............\n";
                    cout << "---------------------------------------\n";
                    break;

                default:
                    cout << "\n---------------------------------------\n";
                    cout << "\nInvalid Choice\nEnter Again...............\n";
                    cout << "---------------------------------------\n";
                    break;
                }
            }

            break;

        case 0:
            cout << "\n-------------------------------------------------------\n";
            cout << "Thanks For Using This Application........!!!!!!! \n";
            cout << "-------------------------------------------------------\n";

            break;

        default:
            cout << "\n-------------------------------------------------------\n";
            cout << "\nInvalid Choice\nEnter Again.....!!!!!!!\n";
            cout << "-------------------------------------------------------\n";
            break;
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
