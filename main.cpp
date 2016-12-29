#include <iostream> // Header files
#include <cmath>
#include<complex>

/*--------------------------------------------------------------------------------------------------------
                                Function that is being used
--------------------------------------------------------------------------------------------------------*/
void takeCofficient();
void quadraticSolution();
void loopRun();
void programTerminate();

/*--------------------------------------------------------------------------------------------------------
                                Global variable
--------------------------------------------------------------------------------------------------------*/
char userInput1;
char calculator;
bool check=false;
float a, b, c, x1, x2, determinant, realPart, imaginaryPart;

using namespace std;

/*--------------------------------------------------------------------------------------------------------
                                Main
--------------------------------------------------------------------------------------------------------*/
int main()
{

    cout<<endl<<endl;
    cout<<"                 Please give a Input  \n";
    cout<<"------------------------------------------------------\n";
    cout<<"||  Press <r> or <R> to input Quadratic coefficient ||\n";
    cout<<"||  Press <c> or <c> to get the Quadratic Solution  ||\n";
    cout<<"||  Press <w> or <W> to run a loop                  ||\n";
    cout<<"||  Press <t> ot <T> to terminate the program       ||\n";
    cout<<"------------------------------------------------------\n\n";
    cin>>userInput1;

    switch (userInput1) {
    case 'r':
    case 'R':
        takeCofficient();
        break;
    case 'c':
    case 'C':
        quadraticSolution();
        break;
    case 'w':
    case 'W':
        loopRun();
        break;
    case 't':
    case 'T':
        programTerminate();
        break;
    default:
        cout<<endl<<"Error!!! Undesired Input."<<endl;
        cin.clear();
        cin.ignore(100,'\n');

        main();

    }
}

/*--------------------------------------------------------------------------------------------------------
                                Taking Cofficient from the user
--------------------------------------------------------------------------------------------------------*/
void takeCofficient()
{   check=true;
    cout<<endl<<"please input the coefficient of a(a!=0): ";
    cin>>a;
    while (cin.fail()||a==0)
    {
        cout<<endl<<"Data Type Error!! "<<endl;
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"Enter your coefficient a(a!=0) :";
        cin>>a;
    }
    cout<<endl<<"please input the coefficient of b: ";
    cin>>b;
    while (cin.fail())
    {
        cout<<endl<<"Data Type Error!! "<<endl;
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"Enter your coefficient b :";
        cin>>b;
    }
    cout<<endl<<"please input the coefficient of c: ";
    cin>>c;
    while (cin.fail()||a==0)
    {
        cout<<endl<<"Data Type Error!! "<<endl;
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"Enter your coefficient c :";
        cin>>c;
    }

    main();
}

/*--------------------------------------------------------------------------------------------------------
                                Soltution of the Quadratic Eqn
--------------------------------------------------------------------------------------------------------*/

void quadraticSolution(){
    if(check==true){
        cout<<"Quadratic equation will be calculated, the results are:"<<endl;
        determinant=b*b-4*a*c;

        if (determinant > 0) {
            x1 = (-b + sqrt(determinant)) / (2*a);
            x2 = (-b - sqrt(determinant)) / (2*a);
            cout << "Here Roots are real and different." << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }

        else if (determinant == 0) {
            cout << "Here Roots are real and same." << endl;
            x1 = (-b + sqrt(determinant)) / (2*a);
            cout << "x1 = x2 =" << x1 << endl;
        }

        else {
            realPart = -b/(2*a);
            imaginaryPart =sqrt(-determinant)/(2*a);
            cout << "Here Roots are complex and different."  << endl;
            cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
            cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
        }
    }
    else {

        int decision;
        cout<<endl<<"Error!! Input your coefficient:Yes(1) or No(2): ";
        cin>>decision;
        while(cin.fail()||(decision<1||decision>2))
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<endl<<"Please choose 1 or 2:";
            cin>>decision;
        }
        if(decision==1) { takeCofficient();}

    }

    main();
}
/*--------------------------------------------------------------------------------------------------------
                                Loop Run By the user
--------------------------------------------------------------------------------------------------------*/
void loopRun(){
    cout<<endl<<"The program is waiting "<<endl;
    cout<<"please enter how many time you want to run the loop: ";

    int i;
    cin>>i;
    while (cin.fail()||(i<0))
    {   cin.clear();
        cin.ignore(100,'\n');
        cout<<" please enter a positive number"<<endl;
        cin>>i;
    }
    for (int a=0;a<i;a++)
    {};
    cout<<"Loop ran :"<<i<<"times"<<endl;
    main();
}
/*--------------------------------------------------------------------------------------------------------
                                Program Termination
--------------------------------------------------------------------------------------------------------*/

void programTerminate()
{
    cout<<endl<<"===The program will be terminated==="<<endl;
}
