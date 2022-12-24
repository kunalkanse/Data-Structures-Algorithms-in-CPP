
// This program demonstrate the implementation of the QUEUE in C++.
// CUI (command user interface) Application.
// menu driven code for GENERIC QUEUE.
// As A generic Works for Any DataType

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// structure decleration
//-------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct node
{
    int data;
    struct node * next;

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// class decleration
//-------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    private:
        node<T> * first;
        node<T> * last;
        int size;

    public:

        Queue();
        void Enqueue(int);
        void Dequeue();

        void Display();
        int Count();

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
// function definations
//-------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Constructor
// Description : used to initialise resources
// parameters : NONE
// return value : NONE
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
Queue<T> :: Queue()
{
    first = NULL;
    last = NULL;
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
void Queue<T> :: Display()
{
    node<T> * temp = first;

    for(int iCnt = 1; iCnt <= size; iCnt++ , temp = temp->next)
    {
        cout<<"|"<<temp->data<<"|->";
    }

    cout<<"NULL";
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
int Queue<T> :: Count()
{
    return size;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : Enqueue
// Description : used to insert Data At Last position
// parameters : data of node
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: Enqueue(int no)
{
    node<T> * newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    size++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------
// function name : DEqueeue
// Description : used to delete Data At first position
// parameters : 
// return value : void
//----------------------------------------------------------------
//////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: Dequeue()
{
    node<T> * temp = first;

    if((first==NULL) && (last==NULL))
    {
        return;
    }

    if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete temp;
    }

    size--;
    
}

///////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------
// main function
//-----------------------------------------------------------------
///////////////////////////////////////////////////////////////////

int main()
{

    Queue <int>IObj;
    Queue <float>FObj;
    Queue <char>CObj;

    int type = 1, iRet = 0, iChoice = 1;

    int iData = 0, fData = 0, cData = 0;

    while(type != 0)
    {
        cout<<"\n------------------------------------------------------------\n";
        cout<<"\nEnter the proper choice to slect data : \n";
        cout<<"\n 1 : To integer Data\n";
        cout<<" 2 : To Decimal Data\n";
        cout<<" 3 : To Character Data\n";
        cout<<" 0 : To terminate the Application\n";
        cout<<"\n---------------------------------------------------------------\n";

        cout<<"\nEnter the choice : ";
        cin>>type;

        switch(type)
        {
            case 1:

                while(iChoice != 0)
                {
                    cout<<"\n------------------------------------------------------------\n";
                    cout<<"\nEnter the proper choice to perform operations : \n";
                    cout<<"\n 1 : To EnQueue the data\n";
                    cout<<" 2 : To Dequeue the data\n";
                    cout<<" 3 : To display data\n";
                    cout<<" 4 : To Count the elements\n";
                    cout<<" 0 : To terminate\n";
                    cout<<"\n---------------------------------------------------------------\n";

                    cout<<"\nEnter the choice : ";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                        case 1:
                            cout<<"Enter the data : ";
                            cin>>iData;

                            IObj.Enqueue(iData);
                            break;

                        case 2:
                            IObj.Dequeue();
                            break;

                        case 3:
                            IObj.Display();
                            cout<<endl;
                            break;

                        case 4:
                            iRet = IObj.Count();
                            cout<<"\nCount is : "<<iRet<<endl;
                            break;

                        case 0:
                            cout<<"\n-------------------------------------------------------\n";
                            cout<<"terminating Integer Stack\n";
                            cout<<"Back to main menu...............\n";
                            cout<<"-------------------------------------------------------\n";
                            break;

                        default:
                            cout<<"\n-------------------------------------------------------\n";
                            cout<<"\nInvalid Choice\nEnter Again...............\n";
                            cout<<"-------------------------------------------------------\n";
                            break;

                    }
                }

                break;

            case 2:
                while(iChoice != 0)
                {
                    cout<<"\n------------------------------------------------------------\n";
                    cout<<"Enter the proper choice to perform operations : \n";
                    cout<<"\n 1 : To push the data\n";
                    cout<<" 2 : To pop the data\n";
                    cout<<" 3 : To display data\n";
                    cout<<" 4 : To Count the elements\n";
                    cout<<" 0 : To terminate\n";
                    cout<<"\n---------------------------------------------------------------\n";

                    cout<<"\nEnter the choice : ";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                        case 1:
                            cout<<"Enter the data : ";
                            cin>>fData;

                            FObj.Enqueue(fData);
                            break;

                        case 2:
                            FObj.Dequeue();
                            break;

                        case 3:
                            FObj.Display();
                            cout<<endl;
                            break;

                        case 4:
                            iRet = FObj.Count();
                            cout<<"\nCount is : "<<iRet<<endl;
                            break;

                        case 0:
                            cout<<"\n-------------------------------------------------------\n";
                            cout<<"terminating Integer Stack\n";
                            cout<<"Back to main menu...............\n";
                            cout<<"-------------------------------------------------------\n";
                            break;

                        default:
                            cout<<"\n-------------------------------------------------------\n";
                            cout<<"\nInvalid Choice\nEnter Again...............\n";
                            cout<<"-------------------------------------------------------\n";
                            break;

                    }
                }

                break;

            case 3:

                while(iChoice != 0)
                {
                    cout<<"\n------------------------------------------------------------\n";
                    cout<<"Enter the proper choice to perform operations : \n";
                    cout<<"\n 1 : To push the data\n";
                    cout<<" 2 : To pop the data\n";
                    cout<<" 3 : To display data\n";
                    cout<<" 4 : To Count the elements\n";
                    cout<<" 0 : To terminate\n";
                    cout<<"\n---------------------------------------------------------------\n";

                    cout<<"\nEnter the choice : ";
                    cin>>iChoice;

                    switch(iChoice)
                    {
                        case 1:
                            cout<<"Enter the data : ";
                            cin>>cData;

                            CObj.Enqueue(cData);
                            break;

                        case 2:
                            CObj.Dequeue();
                            break;

                        case 3:
                            CObj.Display();
                            cout<<endl;
                            break;

                        case 4:
                            iRet = CObj.Count();
                            cout<<"\nCount is : "<<iRet<<endl;
                            break;

                        case 0:
                            cout<<"\n---------------------------------------\n";
                            cout<<"terminating Integer Stack\n";
                            cout<<"Back to main menu...............\n";
                            cout<<"---------------------------------------\n";
                            break;

                        default:
                            cout<<"\n---------------------------------------\n";
                            cout<<"\nInvalid Choice\nEnter Again...............\n";
                            cout<<"---------------------------------------\n";
                            break;

                    }
                }

                break;

            case 0:
                cout<<"\n-------------------------------------------------------\n";
                cout<<"Thanks For Using This Application........!!!!!!! \n";
                cout<<"-------------------------------------------------------\n";

                break;

            default:
                cout<<"\n-------------------------------------------------------\n";
                cout<<"\nInvalid Choice\nEnter Again.....!!!!!!!\n";
                cout<<"-------------------------------------------------------\n";
                break;

        }
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////