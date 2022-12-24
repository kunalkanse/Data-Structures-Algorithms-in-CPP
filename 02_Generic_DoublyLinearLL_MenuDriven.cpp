
// This program demonstrate the implementation of the GENERIC DOUBLY LINEAR LINKED LIST in C++.
// CUI (command user interface) Application.
// menu driven code for GENERIC DOUBLT LINEAR LINKED LIST.
// As A generic Works for Any DataType

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// structure decleration
//-------------------------------------------------------------------
////////////////////////////////////////////////////////////////////

template <class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev;

};

///////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// class decleration
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    private:
        node<T> * first;
        int size;

    public:
        DoublyLL();

        void insertFirst(T);
        void insertLast(T);
        void insertAtPos(T , int);

        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int);

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
DoublyLL<T> :: DoublyLL()
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
void DoublyLL<T> :: Display()
{
    node<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }

    cout<<"NULL\n";
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
int DoublyLL<T>::Count()
{
    return size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : insertFirst
// Description : used to insert Data At first position
// parameters : data of node
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: insertFirst(T data)
{
    node<T> * newn = new node<T>;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
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
void DoublyLL<T> :: insertLast(T data)
{
    node<T> * newn = new node<T>;
    node<T> * temp = first;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
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
void DoublyLL<T> :: insertAtPos(T data , int pos)
{
    if((pos<1) || (pos>(size+1)))
    {
        cout<<"invalid position";
        return;
    }

    if(pos == 1)
    {
        insertFirst(data);
    }
    else if(pos == (size+1))
    {
        insertLast(data);
    } 
    else
    {
        node<T> * newn = new node<T>;

        newn->data = data;
        newn->next = NULL;
        newn->prev = NULL;

        node<T> * temp = first;
        
        for(int iCnt = 1 ; iCnt < (pos-1) ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        size++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
void DoublyLL<T> :: deleteFirst()
{
    if(first != NULL)
    {
        if((first->next) == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            first = first->next;
            delete first->prev;
            first->prev = NULL;
        }

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
void DoublyLL<T> :: deleteLast()
{
    if(first != NULL)
    {
        if((first->next) == NULL)
        {
            delete first;
            first = NULL;
        }
        else
        {
            node<T> * temp = first;

            while((temp->next) != NULL)
            {
                temp = temp->next;
            }

            temp->prev->next = NULL;
            delete temp;
        }

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
void DoublyLL<T> :: deleteAtPos(int pos)
{
    if((pos<1) || (pos>size))
    {
        cout<<"invalid position";
        return;
    }

    if(pos == 1)
    {
        deleteFirst();
    }
    else if(pos == size)
    {
        deleteLast();
    } 
    else
    {
        node<T> * temp = first;
        
        for(int iCnt = 1 ; iCnt < (pos-1) ; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        size--;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------
// main function
//-------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////

int main()
{

    DoublyLL <int>IObj;
    DoublyLL <float>FObj;
    DoublyLL <char>CObj;

    int type = 1, FunChoice = 1, iRet = 0, iPos = 0;
    
    int iData = 0;
    float fData = 0.0;
    char cData = '\0';

    while(type != 0)
    {
        FunChoice = 1;

        cout<<"\n________________________________________\n";
        cout<<"Enter the desired Choice to decide the type of data\n";
        cout<<"1 : integer data\n";
        cout<<"2 : Decimal data\n";
        cout<<"3 : character data\n";
        cout<<"0 : terminate the application\n";
        cout<<"\n________________________________________\n";

        cout<<"Enter the type choice : ";
        cin>>type;

        switch(type)
        {
            case 1:

                while(FunChoice != 0)
                {

                    cout<<"\n________________________________________\n";
                    cout<<"Enter the desired operation to perform on linked list\n";
                    cout<<"1 : insert the node at first position\n";
                    cout<<"2 : insert the node at last position\n";
                    cout<<"3 : insert the node at desired position\n";
                    cout<<"4 : delete the first node\n";
                    cout<<"5 : delete the last node\n";
                    cout<<"6 : delete the node of desired position\n";
                    cout<<"7 : display the content of linked list\n";
                    cout<<"8 : count he number of elements present in list\n";
                    cout<<"0 : terminate the application\n";
                    cout<<"\n________________________________________\n";

                    cout<<"Enter the choice : ";
                    cin>>FunChoice;

                    switch(FunChoice)
                    {
                        case 1:
                            cout<<"Enter the data to insert : ";
                            cin>>iData;
                            IObj.insertFirst(iData);
                            break;

                        case 2:
                            cout<<"Enter the data to insert : ";
                            cin>>iData;
                            IObj.insertLast(iData);
                            break;

                        case 3:
                            cout<<"Enter the data to insert : ";
                            cin>>iData;
                            cout<<"Enter the position : ";
                            cin>>iPos;
                            IObj.insertAtPos(iData,iPos);
                            break;

                        case 4: 
                            IObj.deleteFirst();
                            break;

                        case 5:       
                            IObj.deleteLast();
                            break;  

                        case 6:
                            cout<<"Enter the position : ";
                            cin>>iPos;
                            IObj.deleteAtPos(iPos);
                            break;

                        case 7:
                            cout<<endl;
                            IObj.Display();
                            break;   

                        case 8:
                            cout<<endl;
                            iRet = IObj.Count();
                            cout<<"\nCount of elements is : "<<iRet<<endl;
                            break;

                        case 0:
                            cout<<"\nterminating.............\n";
                            cout<<"Back to main menu\n";
                            break;

                        default:
                            cout<<"Invalid Choice\n Enter the choice again\n";
                            break;
                    }
                }

                break;

            case 2:

                while(FunChoice != 0)
                {

                    cout<<"\n________________________________________\n";
                    cout<<"Enter the desired operation to perform on linked list\n";
                    cout<<"1 : insert the node at first position\n";
                    cout<<"2 : insert the node at last position\n";
                    cout<<"3 : insert the node at desired position\n";
                    cout<<"4 : delete the first node\n";
                    cout<<"5 : delete the last node\n";
                    cout<<"6 : delete the node of desired position\n";
                    cout<<"7 : display the content of linked list\n";
                    cout<<"8 : count he number of elements present in list\n";
                    cout<<"0 : terminate the application\n";
                    cout<<"\n________________________________________\n";

                    cout<<"Enter the choice : ";
                    cin>>FunChoice;

                    switch(FunChoice)
                    {
                        case 1:
                            cout<<"Enter the data to insert : ";
                            cin>>fData;
                            FObj.insertFirst(fData);
                            break;

                        case 2:
                            cout<<"Enter the data to insert : ";
                            cin>>fData;
                            FObj.insertLast(fData);
                            break;

                        case 3:
                            cout<<"Enter the data to insert : ";
                            cin>>fData;
                            cout<<"Enter the position : ";
                            cin>>iPos;
                            FObj.insertAtPos(fData,iPos);
                            break;

                        case 4: 
                            FObj.deleteFirst();
                            break;

                        case 5:       
                            FObj.deleteLast();
                            break;  

                        case 6:
                            cout<<"Enter the position : ";
                            cin>>iPos;
                            FObj.deleteAtPos(iPos);
                            break;

                        case 7:
                            cout<<endl;
                            FObj.Display();
                            break;   

                        case 8:
                            cout<<endl;
                            iRet = FObj.Count();
                            cout<<"\nCount of elements is : "<<iRet<<endl;

                            break;

                        case 0:
                            cout<<"\nterminating.............\n";
                            cout<<"Back to main menu\n";
                            break;

                        default:
                            cout<<"Invalid Choice\n Enter the choice again\n";
                            break;

                    }
                }

                break;

            case 3:

                //SinglyLL <char>CObj;

                while(FunChoice != 0)
                {

                    cout<<"\n________________________________________\n";
                    cout<<"Enter the desired operation to perform on linked list\n";
                    cout<<"1 : insert the node at first position\n";
                    cout<<"2 : insert the node at last position\n";
                    cout<<"3 : insert the node at desired position\n";
                    cout<<"4 : delete the first node\n";
                    cout<<"5 : delete the last node\n";
                    cout<<"6 : delete the node of desired position\n";
                    cout<<"7 : display the content of linked list\n";
                    cout<<"8 : count he number of elements present in list\n";
                    cout<<"0 : terminate the application\n";
                    cout<<"\n________________________________________\n";

                    cout<<"Enter the choice : ";
                    cin>>FunChoice;

                    switch(FunChoice)
                    {
                        case 1:
                            cout<<"Enter the data to insert : ";
                            cin>>cData;
                            CObj.insertFirst(cData);
                            break;

                        case 2:
                            cout<<"Enter the data to insert : ";
                            cin>>cData;
                            CObj.insertLast(cData);
                            break;

                        case 3:
                            cout<<"Enter the data to insert : ";
                            cin>>cData;
                            cout<<"Enter the position : ";
                            cin>>iPos;
                            CObj.insertAtPos(cData,iPos);
                            break;

                        case 4: 
                            CObj.deleteFirst();
                            break;

                        case 5:       
                            CObj.deleteLast();
                            break;  

                        case 6:
                            cout<<"Enter the position : ";
                            cin>>iPos;
                            CObj.deleteAtPos(iPos);
                            break;

                        case 7:
                            cout<<endl;
                            CObj.Display();
                            break;   

                        case 8:
                            cout<<endl;
                            iRet = CObj.Count();
                            cout<<"\nCount of elements is : "<<iRet<<endl;
                            break;

                        case 0:
                            cout<<"\nterminating.............\n";
                            cout<<"Back to main menu\n";
                            break;

                        default:
                            cout<<"Invalid Choice\n Enter the choice again\n";
                            break;
                    }
                }

                break;

            case 0:
                cout<<"\n----------------------------------------\n";
                cout<<"Thanks for using our Application\n";
                cout<<"----------------------------------------\n";
                break;

            default:
                cout<<"\nWrong choice\nEnter again..........";
                break;
        }

    }


    return 0;
}