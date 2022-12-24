
// This program demonstrate the implementation of the GENERIC SINGLY LINEAR LINKED LIST in C++.
// CUI (command user interface) Application.
// menu driven code for GENERIC SINGLY LINEAR LINKED LIST.
// As A generic Works for Any DataType

#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// structure decleration
//-------------------------------------------------------------------
////////////////////////////////////////////////////////////////////

template <class T>
struct node
{
    T data;
    struct node *next;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// class decleration
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
private:
    node<T> *first;
    int size;

public:
    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(int , T );

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Display
// Description : used to Display List
// parameters :
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
    node<T> *temp = first;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL\n";
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
int SinglyLL<T>::Count()
{
    return size;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : insertFirst
// Description : used to insert Data At first position
// parameters : data of node
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T no)
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
// function name : insertLast
// Description : used to insert Data At last position
// parameters : data of node
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertLast(T no)
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
        node<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    size++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : insertAtPos
// Description : used to insert Data At given position
// parameters : data of node , position
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(int pos, T no)
{
    if ((pos < 1) || (pos > (size + 1)))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == (size + 1))
    {
        InsertLast(no);
    }
    else
    {
        node<T> *newn = new node<T>;

        newn->data = no;
        newn->next = NULL;

        node<T> *temp = first;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        size++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : DeleteFirst
// Description : used to delete Data At first position
// parameters :
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    node<T> *temp = first;

    if (first != NULL)
    {
        first = first->next;
        delete temp;

        size--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : DeleteLast
// Description : used to delete Data At Last position
// parameters :
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
    node<T> *temp = first;

    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        size--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        size--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : DeleteAtPos
// Description : used to delete Data At given position
// parameters : position
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    if ((pos < 1) || (pos > size))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == size)
    {
        DeleteLast();
    }
    else
    {
        node<T> *temp = first;
        node<T> *targeted = NULL;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        targeted = temp->next;
        temp->next = targeted->next;

        delete targeted;

        size--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------
// main function
//-------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////

int main()
{

    SinglyLL<int> IObj;
    SinglyLL<float> FObj;
    SinglyLL<char> CObj;

    int type = 1, FunChoice = 1, iRet = 0, iPos = 0;

    int iData = 0;
    float fData = 0.0;
    char cData = '\0';

    while (type != 0)
    {
        FunChoice = 1;

        cout << "\n______________________________________________________\n";
        cout << "\nEnter the desired Choice to decide the type of data\n";
        cout << "1 : integer data\n";
        cout << "2 : Decimal data\n";
        cout << "3 : character data\n";
        cout << "0 : terminate the application\n";
        cout << "\n________________________________________\n";

        cout << "\nEnter the type choice : ";
        cin >> type;

        switch (type)
        {
        case 1:

            while (FunChoice != 0)
            {

                cout << "\n____________________________________________________________\n";
                cout << "\nEnter the desired operation to perform on linked list\n";
                cout << "\n1 : insert the node at first position\n";
                cout << "2 : insert the node at last position\n";
                cout << "3 : insert the node at desired position\n";
                cout << "\n4 : delete the first node\n";
                cout << "5 : delete the last node\n";
                cout << "6 : delete the node of desired position\n";
                cout << "\n7 : display the content of linked list\n";
                cout << "8 : count he number of elements present in list\n";
                cout << "0 : terminate the application\n";
                cout << "\n________________________________________\n";

                cout << "\nEnter the choice : ";
                cin >> FunChoice;

                switch (FunChoice)
                {
                case 1:
                    cout << "Enter the data to insert : ";
                    cin >> iData;
                    IObj.InsertFirst(iData);
                    break;

                case 2:
                    cout << "Enter the data to insert : ";
                    cin >> iData;
                    IObj.InsertLast(iData);
                    break;

                case 3:
                    cout << "Enter the position : ";
                    cin >> iPos;
                    cout << "Enter the data to insert : ";
                    cin >> iData;
                    
                    IObj.InsertAtPos(iPos, iData);
                    break;

                case 4:
                    IObj.DeleteFirst();
                    break;

                case 5:
                    IObj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : ";
                    cin >> iPos;
                    IObj.DeleteAtPos(iPos);
                    break;

                case 7:
                    cout << endl;
                    IObj.Display();
                    break;

                case 8:
                    cout << endl;
                    iRet = IObj.Count();
                    cout << "\nCount of elements is : " << iRet << endl;
                    break;

                case 0:
                    cout << "\nterminating.............\n";
                    cout << "Back to main menu\n";
                    break;

                default:
                    cout << "Invalid Choice\n Enter the choice again\n";
                    break;
                }
            }

            break;

        case 2:

            while (FunChoice != 0)
            {

                cout << "\n__________________________________________________________\n";
                cout << "\nEnter the desired operation to perform on linked list\n";
                cout << "\n1 : insert the node at first position\n";
                cout << "2 : insert the node at last position\n";
                cout << "3 : insert the node at desired position\n";
                cout << "\n4 : delete the first node\n";
                cout << "5 : delete the last node\n";
                cout << "6 : delete the node of desired position\n";
                cout << "\n7 : display the content of linked list\n";
                cout << "8 : count he number of elements present in list\n";
                cout << "0 : terminate the application\n";
                cout << "\n________________________________________\n";

                cout << "\nEnter the choice : ";
                cin >> FunChoice;

                switch (FunChoice)
                {
                case 1:
                    cout << "Enter the data to insert : ";
                    cin >> fData;
                    FObj.InsertFirst(fData);
                    break;

                case 2:
                    cout << "Enter the data to insert : ";
                    cin >> fData;
                    FObj.InsertLast(fData);
                    break;

                case 3:
                    cout << "Enter the position : ";
                    cin >> iPos;
                    cout << "Enter the data to insert : ";
                    cin >> fData;
                    FObj.InsertAtPos(iPos, fData);
                    break;

                case 4:
                    FObj.DeleteFirst();
                    break;

                case 5:
                    FObj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : ";
                    cin >> iPos;
                    FObj.DeleteAtPos(iPos);
                    break;

                case 7:
                    cout << endl;
                    FObj.Display();
                    break;

                case 8:
                    cout << endl;
                    iRet = FObj.Count();
                    cout << "\nCount of elements is : " << iRet << endl;

                    break;

                case 0:
                    cout << "\nterminating.............\n";
                    cout << "Back to main menu\n";
                    break;

                default:
                    cout << "Invalid Choice\n Enter the choice again\n";
                    break;
                }
            }

            break;

        case 3:

            while (FunChoice != 0)
            {

                cout << "\n__________________________________________________________\n";
                cout << "\nEnter the desired operation to perform on linked list\n";
                cout << "\n1 : insert the node at first position\n";
                cout << "2 : insert the node at last position\n";
                cout << "3 : insert the node at desired position\n";
                cout << "\n4 : delete the first node\n";
                cout << "5 : delete the last node\n";
                cout << "6 : delete the node of desired position\n";
                cout << "\n7 : display the content of linked list\n";
                cout << "8 : count he number of elements present in list\n";
                cout << "0 : terminate the application\n";
                cout << "\n________________________________________\n";

                cout << "\nEnter the choice : ";
                cin >> FunChoice;

                switch (FunChoice)
                {
                case 1:
                    cout << "Enter the data to insert : ";
                    cin >> cData;
                    CObj.InsertFirst(cData);
                    break;

                case 2:
                    cout << "Enter the data to insert : ";
                    cin >> cData;
                    CObj.InsertLast(cData);
                    break;

                case 3:
                    cout << "Enter the position : ";
                    cin >> iPos;
                    cout << "Enter the data to insert : ";
                    cin >> cData;
                    CObj.InsertAtPos(iPos, cData);
                    break;

                case 4:
                    CObj.DeleteFirst();
                    break;

                case 5:
                    CObj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : ";
                    cin >> iPos;
                    CObj.DeleteAtPos(iPos);
                    break;

                case 7:
                    cout << endl;
                    CObj.Display();
                    break;

                case 8:
                    cout << endl;
                    iRet = CObj.Count();
                    cout << "\nCount of elements is : " << iRet << endl;
                    break;

                case 0:
                    cout << "\nterminating.............\n";
                    cout << "Back to main menu\n";
                    break;

                default:
                    cout << "Invalid Choice\n Enter the choice again\n";
                    break;
                }
            }

            break;

        case 0:
            cout << "\n----------------------------------------\n";
            cout << "Thanks for using our Application\n";
            cout << "----------------------------------------\n";
            break;

        default:
            cout << "\nWrong choice\nEnter again..........";
            break;
        }
    }
}
