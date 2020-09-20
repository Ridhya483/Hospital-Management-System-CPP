#include<bits/stdc++.h>



using namespace std ;

void patientMenu () ;
void doctorMenu () ;


int main ()
{
    

    int mainChoice ;



    // main menu
    cout << "\n\n                     ***************************** WELCOME TO SDP HOSPITAL *****************************" << flush << endl ;
    cout << "\n\n\n                1. PATIENT "  << endl ;
    cout << "\n\n\n                2. DOCTOR " << flush << endl ;
    cout << "\n\n\n                3. VIEW HOSPITAL RECORDS " << flush << endl ;
    cout << "\n\n\n                4. ENTER ADMINISTRATOR MODE " << flush << endl ;
    cout << "\n\n\n                PLEASE ENTER YOUR CHOICE :  " << flush ;
    cin >> mainChoice ;  
    system("cls");  // for clearing screen 


    switch (mainChoice)
    {
        case 1 :    patientMenu();
                    break;

        case 2 :    doctorMenu();
                    break;

        default :   cout << "Work in Progress";
    }




    
}




// displays patient menu 
void patientMenu ()
{
    int patientChoice;

    do {
    cout << "\n\n\n                1.EXISTING PATIENT " << flush <<endl ;
    cout << "\n\n\n                2.NEW PATIENT " << flush << endl ;
    cout << "\n\n\n                PLEASE ENTER YOUR CHOICE :  " << flush ;
    cin >> patientChoice ;
    system("cls");
    }

    while( patientChoice != 1 && patientChoice != 2);
    
    if( patientChoice == 1)
    {
        cout << "existing record function to be made";
    }

    else
    {
        cout << "new patient fucntion to be made";
    }
}





// displays doctor menu
void doctorMenu ()
{
    int doctorChoice;
    
    do{
    cout << "\n\n\n                1.PATIENT RECORDS " << flush << endl ;
    cout << "\n\n\n                2.DOCTOR DATABASE " << flush << endl ;
    cout << "\n\n\n                PLEASE ENTER YOUR CHOICE :  " << flush ;
    cin >> doctorChoice ;
    system("cls");
    }

    while( doctorChoice != 1 && doctorChoice != 2);

    if( doctorChoice == 1)
    {
        cout << "patient record function to be made";
    }

    else
    {
        cout << "doctor record fucntion to be made";
    }
}