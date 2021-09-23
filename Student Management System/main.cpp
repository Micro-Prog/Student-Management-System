#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>



using namespace std;



//Student structure of 100 Members
struct student {
string name;
int id;
int math;
} s[100];


//Load Function to Load Data File Into Structure
int load ()
{
     int i = 1, x, y;
     string name;

     ifstream inFile;
     inFile.open("data.dat");

     if (inFile.fail())
      {
         cerr << "Error Opening File." << endl;
         exit(1);
      }

      while (!inFile.eof())
      {
          inFile >> s[i].name >> s[i].id >> s[i].math;
          i++;
      }

      inFile.close();

      return i-2;
}


//Function to Add New Student Data
void AddStudent ()
{
    int o = 0;
    string a;
    int b;
    int kk = load();
    int l=kk+1;
    int oo = l;

    cout << "How Many Students Do You want to Add? Enter a Number Between 1-100" << endl;
    cin >> b;


    while ((b < 1) || (b > 100)){
        cin >> b;
       }


    do {
        cout << "Enter Name:" << endl;
        cin >> s[l].name;
        cout << "Enter ID:" << endl;
        cin >> s[l].id;
        cout << "Enter Math:" << endl;
        cin >> s[l].math;
        l++;
        } while (l <= (b+kk));



        ofstream out("data.dat", ios::app);


        for (int r = oo ; r <= (b+kk) ; r++)
        {
            out << s[r].name << " " << s[r].id << " " << s[r].math << "\n";
        }

        out.close();

}



//Function to Show Tables
void ShowTables()
{

    int k;
    int i = load()+2;


    for (k = 1 ; k < (i-1) ; k++)
    cout << k << ":" << "   Name:  " << s[k].name << "     ID:  " << s[k].id << "     Math:  " << s[k].math << endl;

}



//Function to Search
int SearchByTable()
{
    int i;

    load();

    cout << "Enter Search Method:\n'1' by Table\n'2' by ID\n'3' by Name\n" << endl;
    cin >> i;


    switch (i) {
        case 1:
        {
            int l;
            int nn = load();

            cout << "Number of Tables: " << nn << endl;
            cout << "Search by Table\nEnter Table Number: \n" << endl;
            cin >> l;


              if ((l <= nn) && (l > 0))
              {
              cout << "Found." << endl;
              cout << "ID: " << s[l].id << "   Name: " << s[l].name << "   Math: " <<s[l].math << endl;
              }
              else
              cout << "You Entered Wrong Table Number." << endl;


        }
        break;

        case 2:
        {
            int k,m,ll;
            cout << "Search by ID\nEnter the Student ID: \n" << endl;
            cin >> k;


            for (ll = 1 ; ll <= 100 ; ll++)
            {
                if (s[ll].id == k)
                break;

                else if ((s[ll].id != k) && ll==100)
                cout << "Error Not Found." << endl;
            }



            for(m = 1 ; m < 100 ; m ++)
            {

                if (s[m].id == k)
                {
                    cout << "Found." << endl;
                    cout << "ID: " << s[m].id << "   Name: " << s[m].name << "   Math: "<< s[m].math << endl;
                }
            }


      }

      break;

      case 3:
      {

          int pp,mm;
          string namee;

          cout << "Enter Name: \n";
          cin >> namee;


          for (mm = 1 ; mm <= 100 ; mm++)
          {

              if (s[mm].name == namee)
              break;

              else if ((s[mm].name != namee) && mm==100)
              cout << "Error Not Found." << endl;
          }


          for(pp = 1 ; pp <= 100 ; pp ++)
          {

              if (s[pp].name == namee)
              {
              cout << "Found\n";
              cout << "ID: " << s[pp].id << "   Name: " << s[pp].name << "   Math: "<< s[pp].math << endl;
              }

          }

      }
      break;


      default:
      cout << "Error. Wrong Command\n";

}

}


//Function to Delete Tables
void Delete ()
{

    int n, line=1;
    char c;

    load();
    ShowTables();


    cout << "Enter Table Num to Delete:\n";

    cin >> n;

    ifstream inputdata("data.dat");
    ofstream outwrite;
    outwrite.open("demo.dat", ios::out);


    while(inputdata.get(c))
    {
        if(c == '\n')
        line++;

        if(line != n)
        outwrite<<c;
    }


  outwrite.close();
  inputdata.close();


  remove("data.dat");
  rename("demo.dat", "data.dat");


  load();

}




//Main Function
int main()
{

    int k,com;


    while(1)
    {


        cout << "Enter Command: '1', '2', '3', '4' : \n1: Add Student.\n2: Show All Tables.\n3: Search by Table.\n4: Delete\n";
        cin >> com;


        switch (com)
        {

            case 1:
            AddStudent();
            break;

            case 2:
            ShowTables();
            break;

            case 3:
            SearchByTable();
            break;

            case 4:
            Delete();
            break;

            default:
            cout << "Comman Fail.\n";

        }

    }



    return 0;


}
