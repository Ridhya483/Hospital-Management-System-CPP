#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream>



using namespace std ;




// ************************************************************************************ // 



// ************************************************************************************ //

class base
{   
    public :
    string name;
    int ID;
    
};

// ************************************************************************************ //

// ************************************************************************************ //

class patient : public base  // PUBLICLY INHERITS BASE CLASS
{
    public :
    
    string disease;
    string medication;
    
    
    

   

    patient* next ;   // the class object will be a linked list 

    patient()  // CONSTRUCTOR FOR SETTING INITIAL VALUES OF MEDICATION AND DISEASE 
    {
        disease = "FILLED BY DOCTOR";
        medication = "FILLED BY DOCTOR";
    }

    void newPatient()
    {   
        cout << "\n\n------------------------------";
        
        cout << "\n\n  NAME :            ";
        cin >> name ;

        cout << "\n\n  PATIENT ID :      ";
        cin >> ID ;

      
        

    }

    void displayPatient()
    {
        cout << "\n\n------------------------------";

        cout << "\n\nYOUR MEDICAL DETAILS : \n\n";
        
        cout << "\n\n  NAME :            " << name;
        cout << "\n\n  PATIENT ID :      " << ID;
        cout << "\n\n  DISEASE :         " << disease;
        cout << "\n\n  MEDICATION :      " << medication;
        
    }


    void Diagnose()
    {
        cout << "\n\n------------------------------";

        cout <<"\n\n  DIAGNOSE DISEASE OF PATIENT   :     " ;
        cin >> disease ;

        cout <<"\n\n  ENTER MEDICATION OF PATIENT   :     " ;
        cin >> medication ;

        cout <<"\n\n  DETAILS HAVE BEEN UPDATED  " ;
    }

};















// ************************************************************************************ //


int menu () ;
void patientMenu () ;
void doctorMenu () ;
void patientEntry ();
void patientDisplay ();
void patientEdit ();
void fileEntry ();
void readFile ();
void debugDisp();
void deletePatient() ;
patient* headCreation () ;

// ************************************************************************************ //



patient* head = headCreation() ;


// ************************************************************************************ //



int main ()
{
    

    int mainChoice ;

    


    // main menu 
   
    while(mainChoice = menu())
    {

    switch (mainChoice)
    {
        case 1 :    patientMenu();
                    break;

        case 2 :    doctorMenu();
                    break;

        case 3 :    fileEntry();
                    break;
        
        case 4 :    readFile();
                    debugDisp();
                    break;
        
        case 5 :    deletePatient();
                    break;
    }

    }

    return 0 ;

    
}


// ************************************************************************************ //


// menu function 
int menu ()
{
    int m;
do
	{   
        

        cout << "\n\n------------------------------"; 
        cout << "\n          0: EXIT ";
        cout << "\n          1: PATIENT ";
        cout << "\n          2: DOCTOR  ";
        cout <<" \n          3: UPDATE RECORD  ";
        cout <<" \n          4: VIEW RECORD  ";
        cout <<" \n          5: DELETE RECORD  ";

	
	    m = getche()-'0';
   }
while(m > 5 || m < 0);
return m;
}



// ************************************************************************************ //


// displays patient menu 
void patientMenu ()
{
    int patientChoice;

    do {

        cout << "\n\n------------------------------"; 
        cout << "\n\n\n          1.EXISTING PATIENT ";
        cout << "\n\n\n          2.NEW PATIENT ";
        
    patientChoice = getche()-'0';
    
    }

    while( patientChoice != 1 && patientChoice != 2);
    
    if( patientChoice == 1)
    {   
        
        patientDisplay();
    }

    else
    {
       

       patientEntry();

    }
}



// ************************************************************************************ //


// displays doctor menu
void doctorMenu ()
{
    int doctorChoice;
    int subChoice ;
    
    do{
        cout << "\n\n------------------------------";
        cout << "\n\n\n          1.VIEW PATIENT RECORDS ";
        cout << "\n\n\n          2.EDIT PATIENT RECORDS ";

        doctorChoice = getche()-'0';
        
    
    }

    while( doctorChoice != 1 && doctorChoice != 2);


    if( doctorChoice == 1)
    {
       patientDisplay();
       
        
    }

    else
    {
        patientEdit();
    }
}


// ************************************************************************************ //


void patientEntry()   // creates new node for each patient and adds to the linked list
{
   patient* newNode = new patient ;  // creation of new patient node

   newNode->next = NULL ;

   newNode->newPatient();  // entering data into the node 
   

   // linking the node to the linked list 
   patient* temp = head ;

   while(temp->next!=NULL)
   {
       temp = temp->next ;
   }

   temp->next = newNode ;

   cout << "\n\n\n                YOUR DETAILS HAVE BEEN ENTERED INTO THE SYSTEM " ;
   

}


// ************************************************************************************ //

void patientDisplay()   // takes in patientID from user and displays the data
{
    patient* temp = head ;
    temp = temp->next ;   // as head is just a dummy node 

    int pat_id ;
    int flag = 0;   // for checking if patient is found 

    cout << "\n\n\n                ENTER YOUR PATIENT ID TO VIEW YOUR DETAILS  :     " ;
    cin >> pat_id ;

    while(temp!=NULL)
    {
        if(temp->ID == pat_id)
        {
            temp->displayPatient();
            flag++ ;
            break ;
        }

        temp = temp->next ;
    }


    if(flag == 0)
    {
        cout << "\nPatient not found  " ;
    }

    getch();    // program execution moves forward on pressing enter
}



// ************************************************************************************ //



void patientEdit ()
{

    int pat_id ;
    int flag = 0 ;

    cout << "\n\n\n                ENTER YOUR PATIENT ID TO EDIT DETAILS  :     " ; 
    cin >> pat_id ;

    patient* temp = head ;

    temp = temp->next ;

    while(temp!=NULL)
    {
        if(temp->ID == pat_id)
        {
            temp->displayPatient() ;
            temp->Diagnose() ;
            flag++ ;
            break;
        }

        temp=temp->next ;
    }


    if(flag==0)
    {
        cout << "\n\n  PATIENT NOT FOUND "  ;
    }
}



// ************************************************************************************ //


void fileEntry()
{

    


    cout <<"\n\nCONTENTS WRITTEN INTO FILE   " ;

    


    fstream tempfile ;

    tempfile.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\temp.dat",ios::out) ;

    tempfile << "hello" ;

    tempfile.close() ;


    
    fstream outfile ;
    fstream outfileID ;
    fstream outfileDis ;
    fstream outfileMed ;

    outfile.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\Name.dat" ,  ios::out | ios::out) ;
    outfileID.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\ID.dat" ,  ios::out | ios::out) ;
    outfileDis.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\Disease.dat" ,  ios::out | ios::out) ;
    outfileMed.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\Medication.dat" ,  ios::out | ios::out) ;
    

    
    
    patient *temp = head ;
    temp = temp->next ;

    char tmp[30] ;

    //strcpy(tmp,temp->name.c_str());

    //cout << tmp ;


    //outfile << tmp ;

    outfile << "\n" ; 
    

    while(temp!=NULL)
    {
        outfileID << temp->ID << "\n" ; ;

        strcpy(tmp,temp->name.c_str());
        outfile << tmp << "\n" ;
        strcpy(tmp,temp->disease.c_str());
        outfileDis << tmp << "\n" ;
        strcpy(tmp,temp->medication.c_str());
        outfileMed << tmp << "\n" ;

        temp = temp->next ;
        

    }

    outfile.close() ;
    outfileID.close() ;
    outfileDis.close() ;
    outfileMed.close() ;



    
}





void readFile()
{
    fstream namebuf ;
    fstream IDbuf ;
    fstream medbuf ;
    fstream disbuf ;

    namebuf.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\Name.dat" , ios::in) ;
    IDbuf.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\ID.dat" , ios::in) ;
    medbuf.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\Medication.dat" , ios::in) ;
    disbuf.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\Disease.dat" , ios::in) ; 



    string tmp ;
    int tp[100] ;
    int i = 0 ;

    patient *temp = head ;
    //temp = temp->next ;


   // cout << "pt1" ;

    while (getline(namebuf,tmp))
    {
        patient *newNode = new patient ;
       // cout << tmp ;
        temp->next = newNode ;
        temp->name = tmp ;
       // cout << temp->name ;
        temp->ID = 0 ;
        temp = temp->next ;
    }

    temp->next = NULL ;
   // cout << "pt2" ;
    

    namebuf.close() ;




    while (getline(IDbuf,tmp))
    {  //temp = temp->next ;
       tp[i] = atoi(tmp.c_str());
       //cout << tp <<"\n" ;
       //temp->ID = tp ;
       i++ ;
              
        
    }

    


    


    IDbuf.close() ;


    patient *newtemp = head ;
    newtemp = newtemp->next ;
    i = 0 ;
 
    while(newtemp!=NULL)
    {   
        //cout << "\n" << tp[i] ;
        newtemp->ID = tp[i] ;
        newtemp=newtemp->next ;
        i++ ;
    }



    temp = head ;
    temp = temp->next;

    while (getline(medbuf,tmp))
    {
        temp->medication = tmp ;
        temp = temp->next ;
    }
    

    
    temp = head ;
    temp = temp->next;

    while (getline(disbuf,tmp))
    {
        temp->disease = tmp ;
        temp = temp->next ;
    }

}



void debugDisp()
{
    patient *temp = head ;
    temp = temp->next ;
   
    while(temp->next!=NULL)
    {   cout << "\n\n------------------------------" ;
        cout << "\n\nNAME  :  " << temp->name ;
        cout << "\n\nID  :  " << temp->ID ;
        cout << "\n\nMEDICATION  :  " << temp->medication ;
        cout << "\n\nDISEASE  :  " << temp->disease ;
        
        temp = temp->next ;

    }
}


void deletePatient()
{
    int n ;
    char chc ;

    patient *temp = head ;
    patient *prev ;


    cout << "\n\n------------------------------" ;
    cout << "\n\n\n                ENTER YOUR PATIENT ID TO DELETE RECORD  :     " ;
    cin >> n ;


    prev = temp ;
    temp = temp->next;

    while(temp->ID != n || temp == NULL)
    {
        temp = temp->next ;
        prev = prev->next ;
    }

    if(temp == NULL)
    {
        cout << "\n\n          PATIENT NOT FOUND " ; 
        return ;         
    }
    

    temp->displayPatient();

    cout << "\n\n          DO YOU WANT TO CONTINUE ? [Y/N]    :     " ;
    cin >> chc ;

    if(chc == 'Y' || chc == 'y')
    {   
        
        string tmp ;
        char password[20] ;
        int p = 0 ;
        int tmp_mt ;
        
        fstream passbuf ;
        passbuf.open("C:\\Users\\RIDZZ ZOLDYCK\\Desktop\\sdp\\config" , ios::in) ;

        passbuf >> tmp ;
        
        cout << "\n\n          ENTER ADMIN PASSWORD           :       " ;
        do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*"); 
        } 
        p++; 
    }while(password[p-1]!='\r');

    tmp_mt = strcmp(password,tmp.c_str());






        if(tmp_mt != 1)
        {
            cout << "\n\n         PASSWORDS DONT MATCH. UNABLE TO CONTINUE " ;
            passbuf.close();
            return ;
        }


        prev->next = temp->next ;
        delete temp ;
        cout << "\n\n          PATIENT RECORD HAS BEEN DELETED. UPDATE THE RECORD " ;
    

    }

    else
    {
        cout << "\n\n          PATIENT RECORD NOT DELETED" ;
    }
    





    
}












// ************************************************************************************ //

// creates head with no data for the patient linked list 
patient* headCreation()
{
    patient* head = new patient ;
    head->next = NULL ;
    return head ;
}