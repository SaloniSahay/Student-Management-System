#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Student
{
    private:
      string fname,lname,roll_no,branch,email_id,contact;
    public:
      void menu();
      void insert();
      void display();
      void modify();
      void search();
      void remove1();
};
void Student::menu()
{
    menustart:
    int choice;
    char ch;
    system("cls");
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t\tSTUDENT MANAGEMENT SYSTEM"<<endl;
    cout<<"\t\t\t---------------------------------------"<<endl;
    cout<<"\t\t\t\t1. Enter new record"<<endl;
    cout<<"\t\t\t\t2. Display record"<<endl;
    cout<<"\t\t\t\t3. Modify record"<<endl;
    cout<<"\t\t\t\t4. Search record"<<endl;
    cout<<"\t\t\t\t5. Delete record"<<endl;
    cout<<"\t\t\t\t6. Exit"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch(choice){
      case 1:
       do{
        insert();
        cout<<"Do you want to enter another student's detail(Y/N)";
        cin>>ch;
       }while(ch=='Y' || ch=='y');
       break;
      
      case 2:
        display();
        break;
      case 3:
        modify();
        break;
      case 4:
        search();
        break;
      case 5:
        remove1();
        break;
      case 6:
        exit(0);
        break;
      default:
        cout<<"you have entered wrong choice";
    }
  getch();
  goto menustart;
}
void Student::insert()
{
  system("cls");
  ofstream details;
  cout<<"---------Add student details---------"<<endl;
  cout<<"Enter the first name of Student"<<endl;
  cin>>fname;
  cout<<"Enter the last name of Student"<<endl;
  cin>>lname;
  cout<<"Enter the roll of Student"<<endl;
  cin>>roll_no;
  cout<<"Enter branch"<<endl; 
  cin>>branch;
  cout<<"Enter email id"<<endl;
  cin>>email_id;
  cout<<"Enter contact no"<<endl;
  cin>>contact;
  details.open("prj.txt",ios::app | ios::out);
  details<<fname<<" "<<lname<<" "<<roll_no<<" "<<branch<<" "<<email_id<<" "<<contact<<"\n";
  details.close();
}
void Student::display()
{
  int count=1;
  system("cls");
  ifstream details;
  details.open("prj.txt",ios::app | ios::out);
  if(!details)
  {
    cout<<"No records found!!";
    details.close();
  }
  else
  {
    details>>fname>>lname>>roll_no>>branch>>email_id>>contact;
    cout<<"\t\t\t---------STUDENT DETAILS--------"<<endl;
    while (!details.eof())
    {
      cout<<"\n"<<"Details of Student "<<count++<<endl;
      cout<<"Name : "<<fname<<endl;
      cout<<"Last Name : "<<lname<<endl;
      cout<<"Roll No. : "<<roll_no<<endl;
      cout<<"Branch : "<<branch<<endl;
      cout<<"Email Id : "<<email_id<<endl;
      cout<<"Contact No. : "<<contact<<endl;
      details>>fname>>lname>>roll_no>>branch>>email_id>>contact;
    }
    
  }
  details.close();
}
void Student::modify()
{
  system("cls");
  int found=0;
  fstream details,details1;
  string rollno;
  cout<<"---------------STUDENT MODIFY DETAILS-----------------"<<endl;
  details.open("prj.txt",ios::in);
  if(!details)
  {
    cout<<"\n\t\t\t No data is present";
    details.close();
  }
  else
  {
    cout<<"\n Enter roll no. of student that you want to modify: ";
    cin>>rollno;
    details1.open("prj1.txt",ios::app | ios::out);
    details>>fname>>lname>>roll_no>>branch>>email_id>>contact;
    while (!details.eof())
    {
      if(rollno!=roll_no)
      {
        details1<<fname<<lname<<" "<<roll_no<<" "<<branch<<" "<<email_id<<" "<<contact<<"\n";
      }
      else
      {
         cout<<"Enter the first name of Student"<<endl;
         cin>>fname;
         cout<<"Enter the last name of Student"<<endl;
         cin>>lname;
         cout<<"Enter the roll of Student"<<endl;
         cin>>roll_no;
         cout<<"Enter branch"<<endl;
         cin>>branch;
         cout<<"Enter email id"<<endl;
         cin>>email_id;
         cout<<"Enter contact no"<<endl;
         cin>>contact;
         details1<<fname<<" "<<lname<<" "<<roll_no<<" "<<branch<<" "<<email_id<<" "<<contact<<"\n";
         found++;
      }
      details>>fname>>lname>>roll_no>>branch>>email_id>>contact;
      if (found==0)
      {
        cout<<"\n\tStudent roll no. not found...";
      }
    }
    details1.close();
    details.close();
    remove("prj.txt");
    rename("prj1.txt","prj.txt");
  }
}
void Student::search()
{
  string rollno;
  int found=0;
  system("cls");
  fstream details;
  details.open("prj.txt",ios::in);
  if(!details)
  {
    cout<<"Records not found\n";
    details.close();
  }
  cout<<"\nEnter the roll no. you want to search";
  cin>>rollno;
  while (!details.eof())
  {
    if(rollno == roll_no)
    {
      cout<<"First Name : "<<fname<<endl;
      cout<<"Last Name : "<<lname<<endl;
      cout<<"Roll No. : "<<roll_no<<endl;
      cout<<"Branch : "<<branch<<endl;
      cout<<"Email Id : "<<email_id<<endl;
      cout<<"Contact No. : "<<contact<<endl;
      found++;
    }
    details>>fname>>lname>>roll_no>>branch>>email_id>>contact;
  }
  if (found==0)
  {
    cout<<"\n Student roll no. not found";
  }
details.close();
}
void Student::remove1()
{
  system("cls");
  int found=0;
  fstream details,details1;
  string rollno;
  details.open("prj.txt",ios::in);
  if(!details)
  {
    cout<<"\n\t\t\t No data is present";
    details.close();
  }
  else
  {
    cout<<"\n Enter roll no. of student that you want to delete: ";
    cin>>rollno;
    details1.open("prj1.txt",ios::app | ios::out);
    details>>fname>>lname>>roll_no>>branch>>email_id>>contact;
    while (!details.eof())
    {
      if(rollno!=roll_no)
      {
        details1<<fname<<lname<<" "<<roll_no<<" "<<branch<<" "<<email_id<<" "<<contact<<"\n";
      }
      else
      {
        found++;
        cout<<"\n\t\tSuccessfully deleted";
      }
      details>>fname>>lname>>roll_no>>branch>>email_id>>contact;
    }
    if (found==0)
    {
      cout<<"\n\tStudent roll no. not found...";
    }
    details1.close();
    details.close();
    remove("prj.txt");
    rename("prj1.txt","prj.txt");
  }
}
int main()
{
  Student std;
  std.menu();
  return 0;
}