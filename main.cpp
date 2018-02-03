#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std ;
/*-----------------------------------------------------------------------------------------------------
                                        Global variable
------------------------------------------------------------------------------------------------------*/

string fName1;
string lName1;
string bookTitle1;
string publisher1;
double price1;
string SLastname;
bool notfound=false;
vector<int> matchingIndex;
/*-----------------------------------------------------------------------------------------------------
                                        Function is used so far
------------------------------------------------------------------------------------------------------*/

void newBookEntry();
void showBookEntry();
void changeBookEntry();
void searchLastName();
void saveSearchResult();
void programTerminate();

/*-----------------------------------------------------------------------------------------------------
                                        Data Type so far used
------------------------------------------------------------------------------------------------------*/

struct bookDatabase
{   vector<string> fName;
    vector<string> lName;
    vector<string> bookTitle;
    vector<string> publisher;
    vector<double> price;
    vector<string> type;
    vector<bool> readState;

}book_data;

struct bookTopic{
    string a="Chemistry";
    string b="Physics";
    string c="Electrical Engineering";
    string d="computer Science";
    string e="Software";

}topic;
bool state;
/*-----------------------------------------------------------------------------------------------------
                                        Main Manu
------------------------------------------------------------------------------------------------------*/

int main()

{
    int option;

    cout<<"\n\n\n                Please choose          \t\n";
    cout<<"||-------------------------------------------||\t\n";
    cout<<"||    (1) New book entry                     ||\t\n";
    cout<<"||    (2) Show book entry                    ||\t\n";
    cout<<"||    (3) Change book entry                  ||\t\n";
    cout<<"||    (4) Search a certain last name         ||\t\n";
    cout<<"||    (5) Save the search results in a file  ||\t\n";
    cout<<"||    (6) Program termination                ||\t\n";
    cout<<"||-------------------------------------------||\t\n\n";
    cin>>option;

    while(cin.fail()|| option<1 || option>6)
    {

        cout<<endl<<" Please input Only 1, 2, 3, 4, 5, 6 to continue "<<endl;
        cin.clear();
        cin.ignore(100,'\n');
        cin>>option;
    }


    switch (option) {
    case 1:

        newBookEntry();
        break;
    case 2:
        showBookEntry();
        break;

    case 3:
        changeBookEntry();
        break;

    case 4:
        searchLastName();
        break;

    case 5:
        saveSearchResult();
        break;

    default:
        programTerminate();
        return 0;
        break;
    }
}
/*-----------------------------------------------------------------------------------------------------
                                        New Book Entry Function
------------------------------------------------------------------------------------------------------*/

void newBookEntry()
{
    cin.ignore();
    cout<<endl<<"Author's First name: ";
    getline(cin,fName1);
    book_data.fName.push_back(fName1);

    cout<<endl<<"Author's Last name: ";
    cin>>lName1;
    book_data.lName.push_back(lName1);
    cin.ignore();

    cout<<endl<<"Title of the Book: ";
    getline(cin,bookTitle1);
    book_data.bookTitle.push_back(bookTitle1);

    cout<<endl<<"Title of the Publisher: ";
    getline(cin,publisher1);
    book_data.publisher.push_back(publisher1);

    cout<<endl<<"Price of the Book: ";
    cin>>price1;
    while(cin.fail()){cin.clear();     //--------------input checking-------
        cin.ignore(100,'\n');
        cout<<endl<<"Price should be Double type: ";
        cin>>price1;}
    book_data.price.push_back(price1);

    cout<<endl<<"choose the Topic of the book:"<<endl;
    cout<<"         "<<"1). Chemistry "<<endl;
    cout<<"         "<<"2). Physics "<<endl;
    cout<<"         "<<"3). Electrical-engineering "<<endl;
    cout<<"         "<<"4). Computer Science "<<endl;
    cout<<"         "<<"5). Software "<<endl;
    int topic1;
    cin>>topic1;
    while(cin.fail()){cin.clear();       //---------------input checking-------
        cin.ignore(100,'\n');
        cout<<endl<<"Please choose 1,2,3,4,5 for respective book type: ";
        cin>>topic1;}

    switch (topic1) {

    case 1:book_data.type.push_back(topic.a); break;
    case 2:book_data.type.push_back(topic.b); break;
    case 3:book_data.type.push_back(topic.c); break;
    case 4:book_data.type.push_back(topic.d); break;
    case 5:book_data.type.push_back(topic.e); break;


    }
    bool bookState;
    cout<<endl<<"Have you read the Book True(1) or False(0):";
    cin>>bookState;
    while(cin.fail()||(bookState<0||bookState>1)){cin.clear();  //----------input checking-----
        cin.ignore(100,'\n');
        cout<<endl<<"Please Choose 1(for True/Yes) 0(False/No): ";
        cin>>bookState;}
    if(bookState==true )
    {
        state= true;
        book_data.readState.push_back(state);

    }
    else {state=false;book_data.readState.push_back(state);}


    main ();


}

/*-----------------------------------------------------------------------------------------------------
                                        Show the entered Book Information
------------------------------------------------------------------------------------------------------*/

void showBookEntry()
{
    if(book_data.fName.size()){
        cout<<"Book Data Base for Author's"<<endl;
        cout<<"---------------------------"<<endl<<endl;

        for( unsigned int i=0;i<book_data.fName.size();i++)
        {
            cout<<endl<<endl;
            cout<<"Author's First name: "<<book_data.fName[i]<<endl;
            cout<<"Author's Last name: "<<book_data.lName[i]<<endl;
            cout<<"Book title: "<<book_data.bookTitle[i]<<endl;
            cout<<"Publisher: "<<book_data.publisher[i]<<endl;
            cout<<"Price: "<<book_data.price[i]<<endl;
            cout<<"Book type: "<<book_data.type[i]<<endl;
            book_data.readState[i];
            if(book_data.readState[i]== true)
            {
                cout<<"Reading state: Yes"<<endl<<endl<<endl;
            }
            else cout<<"Reading state: No"<<endl<<endl<<endl;


        }
    }
    else cout<< "===Error !!! DataBase is Empty.====";


    main ();

}
/*-----------------------------------------------------------------------------------------------------
                                        Change the Book Entry
------------------------------------------------------------------------------------------------------*/

void changeBookEntry()
{   notfound=false;
    int desire;

    if(book_data.lName.size()){
        cout<<endl<<endl<<"To change Book Entry Please enter the last name: ";
        cin>>SLastname;

        for (unsigned int i=0; i<book_data.lName.size();i++)
        {

            if (SLastname==book_data.lName[i])
            {
                notfound=true;
                cout<<endl<<"====Founded Matching Data===="<<endl;
                cout<<"Author's First name: "<<book_data.fName[i]<<endl;
                cout<<"Author's Last name: "<<book_data.lName[i]<<endl;
                cout<<"Book title: "<<book_data.bookTitle[i]<<endl;
                cout<<"Publisher: "<<book_data.publisher[i]<<endl;
                cout<<"Price: "<<book_data.price[i]<<endl;
                cout<<"Book type: "<<book_data.type[i]<<endl;
                book_data.readState[i];
                if(book_data.readState[i]== true)
                {
                    cout<<"Reading state: Yes"<<endl<<endl<<endl;
                }
                else cout<<"Reading state: No"<<endl<<endl<<endl;

                cout<<endl<<"Do you want to change this data Yes(1) or No(2):";
                cin>>desire;
                while(cin.fail()||(desire<1||desire>2)){cin.clear();               //--------input checking------
                    cin.ignore(100,'\n');
                    cout<<endl<<"Please Choose 1for Yes or 2 for N0: ";
                    cin>>desire;}
                if(desire==1)
                {
                    cin.ignore();
                    cout<<endl<<"Author's First name: ";
                    getline(cin,fName1);
                    book_data.fName[i]=fName1;

                    cout<<endl<<"Author's Last name: ";
                    cin>>lName1;
                    book_data.lName[i]=lName1;
                    cin.ignore();

                    cout<<endl<<"Title of the Book: ";
                    getline(cin,bookTitle1);
                    book_data.bookTitle[i]=bookTitle1;

                    cout<<endl<<"Title of the Publisher: ";
                    getline(cin,publisher1);
                    book_data.publisher[i]=publisher1;

                    cout<<endl<<"Price of the Book: ";
                    cin>>price1;
                    while(cin.fail()){cin.clear();      //-----------input checking-------
                        cin.ignore(100,'\n');
                        cout<<endl<<"Price should be Double type: ";
                        cin>>price1;}
                    book_data.price[i]=price1;

                    cout<<endl<<"choose the Topic of the book:"<<endl;
                    cout<<"         "<<"1). Chemistry "<<endl;
                    cout<<"         "<<"2). Physics "<<endl;
                    cout<<"         "<<"3). Electrical-engineering "<<endl;
                    cout<<"         "<<"4). Computer Science "<<endl;
                    cout<<"         "<<"5). Software "<<endl;
                    int topic1; // global variable kora jabe
                    cin>>topic1;
                    while(cin.fail()){cin.clear();      //-----------input checking-------
                        cin.ignore(100,'\n');
                        cout<<endl<<"Please choose 1,2,3,4,5 for respective book type: ";
                        cin>>topic1;}


                    switch (topic1)
                    {
                    case 1:book_data.type[i]=topic.a; break;
                    case 2:book_data.type[i]=topic.b; break;

                    case 3:book_data.type[i]=topic.c; break;

                    case 4:book_data.type[i]=topic.d; break;
                    case 5:book_data.type[i]=topic.e; break;


                    }
                    bool bookState;
                    cout<<endl<<"Have you read the Book True(1) or False(0):";
                    cin>>bookState;
                    while(cin.fail()||(bookState<0||bookState>1)){cin.clear();  //-----------input checking-------
                        cin.ignore(100,'\n');
                        cout<<endl<<"Please Choose 1(True/Yes) or 0(False/No): ";
                        cin>>bookState;}
                    if(bookState==true )
                    {
                        state= true;
                        book_data.readState[i]=state;
                    }
                    else {state=false;book_data.readState[i]=state;}
                }
                else { main(); }
            }
        }

        while (notfound==false){
            int searchAgain;
            cout<<endl<<"=== Last Name Not Found ==="<<endl;
            cout<<endl<<"Do You want to search again? Yes(1) or No(2):";
            cin>>searchAgain;
            while(cin.fail()||(searchAgain<1||searchAgain>2)){
                cin.clear();
                cin.ignore(100,'\n');
                cout<<endl<<"Error!! Please Choose 1 for yes, 2 for no:";
                cin>>searchAgain;

            }
            if(searchAgain==1){changeBookEntry();}
            else { main();}

        }
    }
    else cout<<"===Error !!! DataBase is Empty.====";

    main();
}

/*-----------------------------------------------------------------------------------------------------
                                        Search with the certain last name
------------------------------------------------------------------------------------------------------*/

void searchLastName()
{   notfound=false;
    if(book_data.lName.size()){
        cout<<endl<<endl<<"Please input the last name:";
        cin>>SLastname;
        cout<<endl<<endl;

        for (unsigned int i=0; i<book_data.lName.size();i++)
        {

            if (SLastname==book_data.lName[i])
            {   matchingIndex.push_back(i);
                notfound=true;

                cout<<"====Founded Matching Data===="<<endl;
                cout<<"Author's First name: "<<book_data.fName[i]<<endl;
                cout<<"Author's Last name: "<<book_data.lName[i]<<endl;
                cout<<"Book title: "<<book_data.bookTitle[i]<<endl;
                cout<<"Publisher: "<<book_data.publisher[i]<<endl;
                cout<<"Price: "<<book_data.price[i]<<endl;
                cout<<"Book type: "<<book_data.type[i]<<endl;
                book_data.readState[i];
                if(book_data.readState[i]== true)
                {
                    cout<<"Reading state: Yes"<<endl<<endl<<endl;
                }
                else cout<<"Reading state: No"<<endl<<endl<<endl;


            }


        }
        while (notfound==false){
            int searchAgain;
            cout<<endl<<"=== Last Name Not Found ==="<<endl;
            cout<<endl<<"Do You want to search again? Yes(1) or No(2):";
            cin>>searchAgain;
            while(cin.fail()||(searchAgain<1||searchAgain>2)){
                cin.clear();
                cin.ignore(100,'\n');
                cout<<endl<<"Error!! Please Choose 1 for yes, 2 for no:";
                cin>>searchAgain;

            }
            if(searchAgain==1){searchLastName();}
            else { main();}
        }
    }
    else cout<<"===Error !!! DataBase is Empty.====";

    main();

}
/*-----------------------------------------------------------------------------------------------------
                                        Save the Search Result
------------------------------------------------------------------------------------------------------*/

void saveSearchResult()
{

    ofstream newFile;
    newFile.open("SearchReasult.txt",ios::app);
    if(matchingIndex.size())
    {   cout<<endl<<"===Your ALL Search Result Is Saved In A File==="<<endl;

        for(unsigned int i=0; i<matchingIndex.size();i++)
        {
            //cout<<matchingIndex[i]<<endl;
            newFile<<"First name:"<< book_data.fName[matchingIndex[i]]<<endl;
            newFile<<"Last Name: "<<book_data.lName[matchingIndex[i]]<<endl;
            newFile<<"Book Title: "<<book_data.bookTitle[matchingIndex[i]]<<endl;
            newFile<<"Publisher: "<<book_data.publisher[matchingIndex[i]]<<endl;
            newFile<<"Price: "<<book_data.price[matchingIndex[i]]<<endl;
            newFile<<"Book Type: "<<book_data.type[matchingIndex[i]]<<endl;
            newFile<<"Reading state:"<<book_data.readState[matchingIndex[i]]<<endl;


        }
    }
    else {cout<<"===You have not done your search yet==="<<endl;
        cout<<"===First search and then save the result==="<<endl;}



    main();
}
/*-----------------------------------------------------------------------------------------------------
                                        Deleting the Data Base && Termination
------------------------------------------------------------------------------------------------------*/


void programTerminate()
{
    cout<<"=============== Your DataBase is Deleted ==============="<<endl;

}
