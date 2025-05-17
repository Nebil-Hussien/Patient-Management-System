#include <iostream>//Use: provides basic input and output services for C++ programs.
#include <sstream>//Use: used to both read strings and write data into strings.
#include <fstream>//Use: used to open a file for writing And open a file for reading purpose.
#include <conio.h>//Use: used mostly by MS-DOS compilers to provide console input/output.
#include <stdio.h>//Use: is a statement which tells the compiler to insert the contents of stdio at that particular place.
#include <cstring>//Use: used to concatenating two objects, and comparing CString objects.
#include <windows.h>//Use: windows.h is a Windows-specific header file for the C and C++ programming languages which contains declarations for all of the functions in the Windows API
#include <cstdio>//Use: This library uses what are called streams to operate with physical devices such as keyboards, printers, terminals or with any other type of files supported by the system.




int Patient_id_key;



using namespace std;


struct Patient
{
	string name;
	int Id;
	int age;
	char gender;
	string address;
    int blood_presure_systoloc;
    int blood_presure_diastolic;
    string blood_type;
    float tempreture;
    string HIV_Test;
    string treatment;
    string drugs_priscribed;
    string stool_investigation;
    string blood_test;

	Patient *next;
}*head=NULL;


void mainInterface();
void registral();
void Nurses();
void Physician();
void Laboratory();
void addNewPatientR();
void displayPatient();
void deletePatient();
void searchPatient();
void loadFromFile();
void saveToFile();
int password();


int main(int argc, char** argv) {

	system("color F0");
   // loadFromFile();
    system("cls");
    password();
    system("cls");
    mainInterface();
    system("cls");
    saveToFile();

	return 0;
}



int password()
{

    cout << "******************************************" << endl;
    cout<<"    The operation you Choose Requires         "<<endl;
    cout<<"    Administrative Permission              "  << endl;
    cout << "******************************************" << endl;
    cout<<"    Please Enter Admin Password:              "<<endl;
    cout << "******************************************" << endl;


    string pass="";
    char ch;
    ch=_getch();

    while (ch!=13)
    {
        pass.push_back(ch);
        cout<<'*';
        ch=_getch();
    }
    if (pass=="Nebiyu")
    {
        cout<<endl<<"Access granted Press any key to continue.";
        getch();
        return 1;
    }
    else
    {
        return 0;
    }

}


void mainInterface()
{
	int d=0;
    cout << "*****************************************" << endl;
    cout<<endl;
    cout << "   Welcome to Patient Management System" << endl;
    cout<<endl;
    cout << "*****************************************" << endl;
    cout<<endl;
    cout << "*****************************************" << endl;
    cout<<endl;
    cout << "   1. REGISTRAL SECTION" << endl;
    cout << "   2. NURSES SECTION FOR PRE-TESTS " << endl;
    cout << "   3. PHYSICIANS SECTION" << endl;
    cout << "   4. LABORAORY SECTION" << endl;
    cout << "   5. Exit" << endl;
    cout<<endl;
    cout << "*****************************************" << endl;
    cout<<endl;


    cout << "Please enter your choice:";
    cin>>d;


    	if(d==1)
        {
        	system("cls");
            registral();
        }

        else if(d==2)
        {
        	system("cls");
            Nurses();
            system("cls");
            mainInterface();
        }

        else if(d==3)
        {
           system("cls");
           Physician();
           system("cls");
           mainInterface();
        }

        else if(d==4)
        {
        	system("cls");
            Laboratory();
            system("cls");
            mainInterface();
        }

        else if(d==5)
        {
        	system("cls");
        	saveToFile();
		}
		else
		{
			system("cls");
			cout<<" Wrong choice try again " <<endl;
			mainInterface();
		}
}



void addNewPatientR()
{

	int Id;
	string name;
	int age;
	char gender;
	string address;

	cout<<"Enter Patient Id: ";
    cin>>Id;

    cout<<"Enter Patient name: ";
    cin>>name;

    cout<<"Enter Patient Age: ";
    cin>>age;

    cout<<"Enter Patient gender: ";
    cin>>gender;

    cout<<"Enter Patient address: ";
    cin>>address;

    Patient *newNode=new Patient;
    newNode->Id=Id;
    newNode->name=name;
    newNode->age=age;
	newNode->gender=gender;
    newNode->address=address;

    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }

    else
    {
        newNode->next=head;
        head=newNode;
    }

    cout<<"New Patient information added successfully!"<<endl;
    getch();
}




void deletePatient()
{
    system("cls");

    cout<<"Delete Patient Informaton"<<endl;

    int Id;
    cout<<"Enter login Id:";
    cin>>Id;

    if(head==NULL)
    {
        cout<<"No Patient information found, try again!"<<endl;
    }

    else
    {
        int check=0;
        Patient *temp1=head;
        Patient *temp2;

        while(temp1->next!=NULL && temp1->Id!=Id)
        {
            temp2=temp1;
            temp1=temp1->next;
        }

        if(head->next==NULL)
        {
            if(head->Id==Id)
            {
                head=NULL;
                check=1;
            }

            else
            {
                check=0;
            }
        }

        else if(temp1==head)
        {
            head=head->next;
        }

        else if(temp1->next==NULL)
        {
            if(temp1->Id==Id)
            {
                temp2->next=NULL;
                check=1;
            }

            else
            {
                check=0;
            }
        }

        else
        {
            if(temp1->Id==Id)
            {
                temp2->next=temp1->next;
                check=1;
            }

            else
            {
                check=0;
            }
        }

        delete temp1;

        if(check==1)
        {
            cout<<"Patient information deleted successfully!"<<endl;
        }

        else
        {
            cout<<"Unknown Id, try again!"<<endl;
        }

    }
    getch();
}



void searchPatient()
{
    system("cls");

    cout<<"Search a Patient information"<<endl;

    int Id;
    cout<<"Enter Patient Id:";
    cin>>Id;

    if(head==NULL)
    {
        cout<<"No Patient information found, try again!"<<endl;
    }

    else
    {
        Patient *temp=head;
        while(temp->next!=NULL && temp->Id!=Id)
        {
            temp=temp->next;
        }
        if(temp->next==NULL && temp->Id!=Id)
        {
            cout<<"Search was not found, try again!"<<endl;
        }
        else
        {
            cout<<"Login Id: "<<temp->Id<<endl;
            cout<<"Name: "<<temp->name<<endl;
            cout<<"Age: "<<temp->age<<endl;
        }
    }

    getch();
}



void displayPatient()
{
    system("cls");
    mainInterface();

    cout<<"All Patient Information"<<endl;
    cout<<"Patient Id    \t Name   \t Age"<<endl;

    if(head==NULL)
    {
        cout<<"No Patient information found, try again!"<<endl;
    }

    else
    {
        Patient *temp=head;

        while(temp->next!=NULL)
        {
            cout<<temp->Id<<"\t\t"<<temp->name<<"\t\t"<<temp->age<<endl;
            temp=temp->next;
        }
        cout<<temp->Id<<"\t\t"<<temp->name<<"\t   \t"<<temp->age<<endl;
    }
    getch();
}



void registral()
{

	system("cls");
	password();
    system("cls");


    cout<<endl;
	cout << "***************************************************************" << endl;
    cout<<endl;
    cout << "\t \tRegistral:: New Patient Registration Form" << endl;
    cout<<endl;
    cout << "***************************************************************" << endl;
    cout<<endl;

    int c=0;
    cout << "***************************************************************" << endl;
    cout<<endl;
    cout << "\t \t1.INSERT NEW PATIENT INFORMATON" << endl;
    cout << "\t \t2. DELETE PATIENT INFORMATION " << endl;
    cout << "\t \t3. SEARCH A SPECIFIC PATIENT" << endl;
    cout << "\t \t4. DISPLAY ALL PATIENTS" << endl;
    cout << "\t \t5. Exit" << endl;
    cout<<endl;
    cout << "***************************************************************" << endl;
    cout<<endl;

    cout << "Please enter your choice:";
    cin>>c;

    cout << "press any key to continue..." << endl;
    getch();


        system("cls");

		if(c==1)
        {
            addNewPatientR();
            system("cls");
            registral();
        }

        else if(c==2)
        {
            deletePatient();
            system("cls");
            registral();
        }

        else if(c==3)
        {
            searchPatient();
            system("cls");
            registral();
        }

        else if(c==4)
        {
            displayPatient();
            system("cls");
            registral();
        }

        else if(c==5)
        {
         	mainInterface();
		}

		else
		{
			mainInterface();
		}


	   }




void Nurses()
{

	system("cls");
	password();


	string name;
    int Id;
    int age;
    char gender;
	int blood_presure_systoloc;
	int blood_presure_diastolic;
	string blood_type;
	float tempreture;
	string HIV_Test;


	cout << "***************************************************************" << endl;
    cout<<endl;
    cout << "\t \tPre-Investigations for Patients" << endl;
    cout<<endl;
    cout << "***************************************************************" << endl;
    cout<<endl;


    cout<<"Enter Patient Id: ";
    cin>>Id;

    cout<<"Enter Patient name: ";
    cin>>name;

    cout<<"Enter Patient Age: ";
    cin>>age;

    cout<<"Enter Patient gender: ";
    cin>>gender;

    cout<<"Enter Patient systolic blood pressure: ";
    cin>>blood_presure_systoloc;

    cout<<"Enter Patient diastolic blood pressure: ";
    cin>>blood_presure_diastolic;

    cout<<"Enter Patient Blood type: ";
    cin>>blood_type;

    cout<<"Enter Patient Tempreture: ";
    cin>>tempreture;

    cout<<"Is the Patient HIV postive or negative? ";
    cin>>HIV_Test;

	Patient *newNode=new Patient;
    newNode->Id=Id;
    newNode->name=name;
    newNode->age=age;
	newNode->gender=gender;
    newNode->blood_presure_systoloc=blood_presure_systoloc;
	newNode->blood_presure_diastolic=blood_presure_diastolic;
    newNode->blood_type=blood_type;
    newNode->tempreture=tempreture;
	newNode->HIV_Test=HIV_Test;


    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }

    else
    {
        newNode->next=head;
        head=newNode;
    }
    cout<<"New Patient Prelimenary-Investigation added successfully!"<<endl;
    getch();

}



void Physician()
{
	system("cls");
	password();

	cout << "***************************************************************" << endl;
    cout<<endl;
    cout << "\t \tPhysician:: New Patient treatment record" << endl;
    cout<<endl;
    cout << "***************************************************************" << endl;
    cout<<endl;

	int Id;
    string name;
    int age;
    char gender;
    string treatment;
    string drugs_priscribed;

	cout<<"Enter Patient Id: ";
    cin>>Id;

    cout<<"Enter Patient name: ";
    cin>>name;

    cout<<"Enter Patient Age: ";
    cin>>age;

    cout<<"Enter Patient gender: ";
    cin>>gender;

    cout<<"Enter the treatment you gave the Patient: ";
    cin>>treatment;

    cout<<"Enter the drugs you priscribed to the Patient: ";
    cin>>drugs_priscribed;

    Patient *newNode=new Patient;
    newNode->Id=Id;
    newNode->name=name;
    newNode->age=age;
	newNode->gender=gender;
    newNode->treatment=treatment;
    newNode->drugs_priscribed=drugs_priscribed;


    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }

    else
    {
        newNode->next=head;
        head=newNode;
    }

    cout<<"Treatments given to the Patient has been recorded successfully!"<<endl;
    getch();
}



void Laboratory()
{
	system("cls");
	password();

	cout << "***************************************************************" << endl;
    cout<<endl;
    cout << "\t \tLaboratory:: Patient Lab-Test " << endl;
    cout<<endl;
    cout << "***************************************************************" << endl;
    cout<<endl;

	int Id;
    string name;
    int age;
    char gender;
    string stool_investigation;
    string blood_test;


	cout<<"Enter Patient Id: ";
    cin>>Id;

    cout<<"Enter Patient name: ";
    cin>>name;

    cout<<"Enter Patient Age: ";
    cin>>age;

    cout<<"Enter Patient gender: ";
    cin>>gender;

    cout<<"Enter Patient stool test result: ";
    cin>>stool_investigation;

    cout<<"Enter Patient blood test: ";
    cin>>blood_test;


	Patient *newNode=new Patient;
    newNode->Id=Id;
    newNode->name=name;
    newNode->age=age;
	newNode->gender=gender;
    newNode->stool_investigation=stool_investigation;
    newNode->blood_test=blood_test;

    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }

    else
    {
        newNode->next=head;
        head=newNode;
    }

    cout<<"Patient's LAB-TEST information added successfully!"<<endl;
    getch();

}




void saveToFile()
{
    ofstream Pat("Patient.txt", ios::trunc);
    Patient *temp=head;

    while(temp!=NULL)
    {
            if(temp->next==NULL)
            {
                Pat<<temp->Id<<"\n";
                Pat<<temp->name<<"\n";
                Pat<<temp->age<<"\n";
                Pat<<temp->gender<<"\n";
                Pat<<temp->blood_presure_systoloc<<"\n";
                Pat<<temp->blood_presure_diastolic<<"\n";
                Pat<<temp->blood_type<<"\n";
                Pat<<temp->tempreture<<"\n";
                Pat<<temp->HIV_Test<<"\n";
                Pat<<temp->treatment<<"\n";
                Pat<<temp->drugs_priscribed<<"\n";
                Pat<<temp->stool_investigation<<"\n";
                Pat<<temp->blood_test<<"\n";
            }

            else
            {
            	Pat<<temp->Id<<"\n";
                Pat<<temp->name<<"\n";
                Pat<<temp->age<<"\n";
                Pat<<temp->gender<<"\n";
                Pat<<temp->blood_presure_systoloc<<"\n";
                Pat<<temp->blood_presure_diastolic<<"\n";
                Pat<<temp->blood_type<<"\n";
                Pat<<temp->tempreture<<"\n";
                Pat<<temp->HIV_Test<<"\n";
                Pat<<temp->treatment<<"\n";
                Pat<<temp->drugs_priscribed<<"\n";
                Pat<<temp->stool_investigation<<"\n";
                Pat<<temp->blood_test<<"\n";
			}
			temp=temp->next;
        }
        // close the opened file.
        Pat.close();
        cout<<"Data saved successfully!";
    }





/*
void loadFromFile()
{
	cout<<"F i l e     i s      l o a d i n g. . . . . . . . . ."<<endl;

    ifstream Pat ("Patient.txt", ios::in);

    if(Pat.fail())
    {
    	 system("cls");
    	 cout<<"No file is loaded"<<endl;
    }

    else
    {
    int counter=0;
    string name;
	int Id;
	int age;
	char gender;
	string address;
    int blood_presure_systoloc;
    int blood_presure_diastolic;
    string blood_type;
    float tempreture;
    string HIV_Test;
    string treatment;
    string drugs_priscribed;
    string stool_investigation;
    string blood_test;
    string line;

        while(!Pat.eof())
        {
        	Patient * newPatient = new Patient;

        	getline(Pat,line);
        	stringstream s;

        	s<<line;
        	s>>newPatient->Id;

        	Id=newPatient->Id;
            Pat.getline(Id);

        	name=newPatient->name;
        	Pat.getline(name);

        	name=newPatient->age;
        	Pat.getline(age);

    	    name=newPatient->gender;
        	Pat.getline(gender);

            name=newPatient->address;
        	Pat.getline(address);

            name=newPatient->blood_presure_systoloc;
        	Pat.getline(blood_presure_systoloc);

        	name=newPatient->blood_presure_diastolic;
        	Pat.getline(blood_presure_diastolic);

       	    blood_type=newPatient->blood_type;
        	Pat.getline(blood_type);

        	tempreture=newPatient->tempreture;
        	Pat.getline(tempreture);

            HIV_Test=newPatient->HIV_Test;
        	Pat.getline(HIV_Test);

        	treatment=newPatient->treatment;
        	Pat.getline(treatment);

            drugs_priscribed=newPatient->drugs_priscribed;
        	Pat.getline(drugs_priscribed);

   			stool_investigation=newPatient->stool_investigation;
        	Pat.getline(stool_investigation);

            blood_test=newPatient->blood_test;
        	Pat.getline(blood_test);


        if(head==NULL)
        {
        	newPatient->next=NULL;
            head=newPatient;
		}
		else
		{
			 Patient *temp=head;

                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newPatient;
		}
		Patient_id_key=++Id;
        }
        Pat.close();
    }

    	system("cls");
        cout<<"Data has loaded successfully!"<<endl;
        getch();
}
*/
