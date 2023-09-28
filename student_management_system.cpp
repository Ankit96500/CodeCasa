#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main();
void show_data(int searchkey);     //function used to show data to the user.
void get_data(int i);           //function used to get data from the user.
void search_student(int searchkey);
void add_student();      //function is used to add record of new student.
void edit_student(int idnumber);   //function is used to edit existing record.   
void fullscreen();
int total_student;

struct student    //Structure student is made to store student attributes.
{ 
  int rollno; 
  string name;
  string fname;
  string phone_no;
  string dob;
  string address;
};

student rec[50];  //This is basic array of defined structure to sore data.
int main()
{
  // system("CLS");
  // system("color 8");
  int choice;   //int variable used to determine which operation user want to do.
  int idnumber;   //int variable used to record ID number whih user want to edit.
  int searchkey;  //int variable to store student roll_no by which user can search.
  
  cout<<"How Many Students Want to Enter In Database(atleast 2 or maximum 50):  ";
  cin>>total_student;

 while(total_student=total_student-1)
 {
  cout<<"\nfollowing action you can do it?"<<endl;
  cout<<"----------------------"<<endl;
  cout<<"1-Add student"<<endl;
  cout<<"2-Edit student"<<endl;
  cout<<"3-Search student"<<endl;
  cout<<"4-Quit Program"<<endl;
  cout<<"----------------------"<<endl;
  cout<<"Enter your choice: ";

  cin>>choice;
  switch(choice)
 {
   case 1:       
    add_student();
    break;
   case 2:         //it is used to enter the first record in the array
    if(rec[0].rollno==0)
   {
     cout<<"Please Add students first."<<endl;
     system("pause");
    main();
   }
    else         //if record is present it show data
   { 
     cout<<endl;
     cout<<"=========================================================================================="<<endl;
     cout<<"________________________________Student record Table______________________________"<<endl;
     cout<<"==============================================================================="<<endl; 
     cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tPhone no.      "<<"DOB          "<<"Address\n\n";
     cout<<"======================================================================================="<<endl; 

     for(int i=0;i<=total_student;i++)
    {
      show_data(i);     //funtion is called with index value to show data
     }

     cout<<"============================================================================"<<endl;
     cout<<"Enter ID number your want to edit: ";
   
     cin>>idnumber;            //Asking user Id who want to change it.

    if(idnumber>total_student || idnumber<0)  //Validating the ID number.
    {      
          cout<<"\nInvalid ID Number."<<endl;
       }
       else
    {
          edit_student(idnumber);    //Passing ID number to Edit Function.
       }
   }
   break;
   
  case 3:
    if(rec[0].rollno==0)     //If no record exist then ask the user o enter records first.
   {   
     cout<<"Please Add students first."<<endl;
     system("pause");
     main();         //Return to main so user can input new record.
    }
    else
   {
     cout<<"Enter roll_no of student you want to search: ";
     cin>>searchkey;     //here rollno is the search key.
     search_student(searchkey);}
     break;
   case 4:
    cout<<"PROGRAM END :)";
    return 0;        //Terminating the records.
    break;
   default:       
    cout<<"Invalid number."<<endl;
    system("pause");
  main();
  }
 }
  return 0;
}

  
void get_data(int i)        //Function for receiving data from user and add the variables with values.
{   
  cout<<"Enter student roll number in  format(1XXX): ";
  cin>>rec[i].rollno;
  cout<<"Enter student name: ";
  cin>>rec[i].name;
  cout<<"Enter student's Father name: ";
  cin>>rec[i].fname;
  cout<<"Enter student's phone_no phone number: ";
  cin>>rec[i].phone_no;
  cout<<"Enter student's Date of Birth(dd/mm/yyyy): ";
  cin>>rec[i].dob;
  cout<<"Enter student's Address: ";
  cin>>rec[i].address;
  cout<<endl;
}

void show_data(int searchkey)      //Function for showing data on the screen.
{    
  int i=searchkey;
  cout<<i<<"    ";
  cout<<rec[i].rollno<<"   ";
  cout<<rec[i].name<<"     ";
  cout<<rec[i].fname<<"\t";
  cout<<rec[i].phone_no<<"   ";
  cout<<rec[i].dob<<"   ";
  cout<<rec[i].address<<"\n\n";
}

void search_student(int searchkey)
{
  for(int i=0;i<=total_student;i++)  
 { 
   if(rec[i].rollno==searchkey)    //If roll number matches to search term.
  {   
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tPhone no.      "<<"DOB          "<<"Address\n\n";
    show_data(i);       //A function is used inside another function.
   }
  } 
}

void add_student()         //This function is used to add record of new student.
{    
  for(int i=0;i<=total_student;i++)
 {
    get_data(i);          //Loop was processed 5 times to get input for 5 students.
  }
  // system("CLS");
  cout<<endl;
  cout<<"========================================================================="<<endl;
  cout<<"________________________________Student record Table___________________________________"<<endl;
  cout<<"================================================================================="<<endl;
  cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tPhone no.      "<<"DOB          "<<"Address\n\n";
  cout<<"============================================================="<<endl;

  for(int i=0;i<=total_student;i++)
 {
    show_data(i);        //Loop was processed for n times to show obtained records.
  }
  cout<<"================================================================================"<<endl;
  cout<<"================================FINISH=========================================="<<endl;
  cout<<"================================================================================"<<endl;
  system("pause");

  main();          //Return to main function to again show menu.
}

void edit_student(int idnumber)     //function is used to edit existing record.
{  
  for(int i=0;i<=total_student;i++)       //Loop is started.
 {  
   if(idnumber==i)       //Through loop every value is compared with search term.
  {         
    cout<<"\nExisted information about this record.\n\n";
    cout<<"=============================================================================="<<endl;
    cout<<"ID   "<<"Roll   "<<"Name      "<<"Father\tPhone no.      "<<"DOB          "<<"Address\n\n";
    cout<<"=============================================================================="<<endl;
    show_data(i);       //Load information for existing record.
    cout<<"\n\nEnter new data for above shown record.\n\n";
    get_data(i);         //Inputing data for that specific record.
    cout<<"\n\nRecord updated successfully."<<endl;
    system("pause");
    main();           //Return to main function.
   }
  }
}