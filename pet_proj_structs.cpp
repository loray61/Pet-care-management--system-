#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;




struct systemPetData{
string petNames[5]={"dog", "cat", "goat", "rabbit", "parrot"};
string petArt[5] = {"▼ ᴥ ▼", " =^.^= ", "\\ᐠ-ꞈ-ᐟ/", "₍ᐢ.w.ᐢ₎", "⋆.˚(\\(o/\\o)/)"};
string vaccinations[5];
string prescription[5];
string quiz[3];

};

struct petHealth{
        string diseases[3];
        string symptoms[3];
        string treatment[3];
        string schedule[3];
        string grooming[3];
        
    };

struct donation{
   char amount[10];
   string* arr;
};



void gotoxy(int x, int y);
void clearArea(int j);
void splashCat();
bool flag = false;


void printHeader();
void subMenu1();
void subMenu2();
void subMenu3();
void mainMenu();
void submenu4();
void showPets();


string toLowerCase(string X);
int findPet(string []);
int appointment();
int intValidation();
bool checkupfee(int);

string replace(string mainStr, string replaceStr, string newStr);
bool saveData(petHealth( & pet)[5]);
void loadVacNPresNQuiz(systemPetData & p);
void petCheckup( petHealth (&p)[5], systemPetData & x);
void petSchedule(petHealth (sch)[5],systemPetData pet);
void petGrooming(petHealth( & v)[5],systemPetData & u);
void feedQuiz(systemPetData pet);
void vacPres(systemPetData & y);
void addDst( petHealth(&p)[5]);
void vacPres(systemPetData & y);
void updateDst( petHealth(&p)[5],systemPetData &data );
void deleteDst( petHealth(&p)[5], systemPetData(&data));
string *donors(donation don,int &count);
bool saveDonorData(donation don , int count);
bool loadSchedule(petHealth (& sch)[5]);
bool loadGroomData(petHealth (& gr)[5]);










int main()
{
    system("chcp 65001");
   
    int count = 0;
    int op = -1;
    int amount=0, choice;
    string id = "", pwd = "";

    systemPetData newPet;    
    petHealth pets[5];
    donation don;   

    addDst(pets);
    loadVacNPresNQuiz(newPet);
    printHeader();
    splashCat();
   
    cout << endl;
    do
    {
        system("CLS");
        cout << endl;
        printHeader();

        gotoxy(45, 57);
        mainMenu();
        choice=intValidation();
        do
        {
            system("cls");
            if (choice == 1)
            {
                printHeader();
                gotoxy(45, 66);
                cout << "Enter ID: ";
                cin >> id;
                gotoxy(45, 67);
                cout << "Enter Password: ";
                cin >> pwd;
                gotoxy(45, 68);
                cout << "Loading.......";
                Sleep(3000);
                clearArea(65);
                if (id == "1" && pwd == "1")
                {
                    bool loggedIn = true;
                    cout << endl;
                
                    while (loggedIn)
                    {
                        system("cls");
                        subMenu1();
                        op=intValidation();
                        switch (op)
                        {
                        case 1:
                        {
                            showPets();

                            break;
                        }

                        case 2:
                        {
                             updateDst(pets,newPet);
                            
                            break;
                        }
                        case 3:
                        {
                           deleteDst(pets,newPet);
                          
                            break;
                        }
                        case 4:
                        {
                            amount = appointment();
                       
                            break;
                        }
                        case 0:
                        {

                            cout << " Administrator is logged out" << endl;
                            cout << " Loading back.......";

                           // Sleep(3000); uncomment after fixing issues 
                            clearArea(65);
                            loggedIn = false;
                            break;
                        }
                        default:
                        {
                            
                            break;
                        }
                        }
                      
                    }
                }
                else
                {
                cout<<"Invalid credentials.Try Again!!! ";
                Sleep(3000);
                }
            }
            else if (choice == 2)
            {
                cout << endl;
                if (amount <= 0)
                {
                    gotoxy(45, 62);
                    cout << "Admin has not set the appointment fee yet";
                    Sleep(2000);
                    clearArea(62);
                    break;
                }

                bool loggedIn = false;

                if (checkupfee(amount))
                {
                    loggedIn = true;
                    while (loggedIn)
                    {   system("cls");
                        subMenu2();
                        op=intValidation();
                        switch (op)
                        {
                        case 1:
                        {
                             petCheckup(pets ,newPet);
                            
                            break;
                        }
                        case 2:
                        {
                       vacPres(newPet);
                          
                            break;
                        }
                        case 0:
                        {
                            loggedIn = false;
                            break;
                        }
                        default:
                        {
                        
                            break;
                        }
                        }
                    }
                }
            }
            else if (choice == 3)
            {

                cout << endl;
                subMenu3();
                op=intValidation();
                switch (op)
                {
                case 1:
                {
                    feedQuiz(newPet);
               
                    break;
                }
                case 2:
                {
                    petGrooming(pets,newPet);
                    
                    break;
                }
                case 3:
                {
                     petSchedule(pets,newPet);
                   
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    // cout << "Invalid choice ";
                    break;
                }
                }
            }
            else if (choice == 4)
            {
                submenu4();
                op=intValidation();
                switch (op)
                {
                case 1:
                {
                    showPets();
                    gotoxy(45, 70);
                    cout << "Select your desired pet then \n";
                    int index = findPet(newPet.petNames);
                    gotoxy(45, 72);
                    cout << "Here is your " << newPet.petNames[index] << " " << newPet.petArt[index] << endl;
                    getch();
                    break;
                }
                case 2:
                {
                    don.arr = donors(don,count);
                    saveDonorData(don, count);
                }
                
                    
                default:
                  {  
                    break;
                  }
                }
            }
            else
            {
                cout << "Choose a valid option";
                break;
            }
        } while (op != 0);
        op = -1;
    } while (choice != 0);
    choice = -1;
    saveData(pets);
    
    return 0;
}


     


void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}


void mainMenu()
{

    printHeader();
    gotoxy(45, 60);
    cout << "       MAIN MENU   " << endl;

    gotoxy(45, 61);
    cout << "1.Administrator Login " << endl;
    gotoxy(45, 62);
    cout << "2.Pet Checkup " << endl;
    gotoxy(45, 63);
    cout << "3.Pet Health and Care" << endl;
    gotoxy(45, 64);
    cout << "4.Save Pets";
   cout<<endl;
   gotoxy(45,65);
}



void subMenu1()
{

    printHeader();
    cout << endl
         << endl;
    gotoxy(45, 58);
    cout << "1.Display pet list " << endl;
    gotoxy(45, 59);
    cout << "2.Update Pet diseases corressponding symptoms and treatments\n";
    gotoxy(45, 60);
    cout << "3.Delete Pet diseases corressponding symptoms and treatments\n";
    gotoxy(45, 61);
    cout << "4.Manage Appointments" << setw(10) << "0.Exit: ";
    gotoxy(45, 62);
    cout << endl;
    gotoxy(45, 63);
  
    
}



void subMenu2()
{
    int j = 61;
    printHeader();
    gotoxy(45, 58);
    cout << "1.Match symptoms to get Treatment " << endl;
    gotoxy(45, 59);
    cout << "2.Get Vaccination  and prescriptions " << endl;
    gotoxy(45, 60);
    cout << "0.Exit: ";
    cout << endl;
    gotoxy(45, j);
  
}



void subMenu3()
{
    printHeader();
    gotoxy(45, 58);
    cout << "1.Get feeding details of your pet  " << endl;
    gotoxy(45, 59);
    cout << "2.Get Grooming suggestions by vet  " << endl;
    gotoxy(45, 60);
    cout << "3.Get exercise schedule of pet by vet " << endl;
    gotoxy(45, 61);
    cout << "0.Exit ";
    cout << endl;
    gotoxy(45, 62);
 
}



void submenu4()
{
    printHeader();
    gotoxy(45, 58);
    cout << "1.Take Abandoned pets home " << endl;
    gotoxy(45, 59);
    cout << "2.Donate for pets.";
    gotoxy(45, 60);
    cout << "0.Exit ";
    cout << endl;
    gotoxy(45, 61);
 
}


 int intValidation(){


     int input;
  
while(true)
   { 
      cout<<"Choose the option(integer): ";
      cin>>input;
        if(!cin)
    {

            cin.clear();
            cin.ignore(256,'\n');
    }
    else 
    break;
    }
    return input;
}



void printHeader()
{
    
    gotoxy(45, 45);
    cout << "██████████████████████████████████████████████████████████████████" << endl;
    gotoxy(45, 46);
    cout << "██                                                              ██" << endl;
    gotoxy(45, 47);
    cout << "██                 Pet Care Management System                   ██" << endl;
    gotoxy(45, 48);
    cout << "██                                                              ██" << endl;
    gotoxy(45, 49);
    cout << "██████████████████████████████████████████████████████████████████" << endl;

    cout << endl
         << endl;
}



void splashCat()
{
   //Displays the cat on start of screen for few seconds
    gotoxy(45, 58);
    cout << "              :● :':         ;': ●  : " << endl;
    gotoxy(45, 59);
    cout << "            `. `-' .'.       .'. `-' .'" << endl;
    gotoxy(45, 60);
    cout << "              `---'             `---'" << endl;
    gotoxy(45, 61);
    cout << "                                      " << endl;
    gotoxy(45, 62);
    cout << "    _...----...      ...   ...      ...----..._" << endl;
    gotoxy(45, 63);
    cout << " .-'__..-◄◄◄----    `.  `▲`  .'    ----►►►-..__ `-." << endl;
    gotoxy(45, 64);
    cout << "'.-   _.--◄◄◄         `-._.-'         ►►►-_     `-.`" << endl;
    gotoxy(45, 65);
    cout << "  .-                     :                  '.  `" << endl;
    gotoxy(45, 66);
    cout << "  '   `.              _.' '._              ;." << endl;
    gotoxy(45, 67);
    cout << "        `.     \\ ,.-'        '-.,/        ;" << endl;
    gotoxy(45, 68);
    cout << "          `.                           .'" << endl;
    gotoxy(45, 69);
    cout << "            `-._                 __.-'" << endl;
    gotoxy(45, 70);
    cout << "                ` --...___...--`" << endl;
    cout << endl;
    gotoxy(49, 72);
    cout << "Loading.......";
    cout.flush();
   // Sleep(3500); // uncomment when done fhandling
    system("cls");
}



void loadVacNPresNQuiz(systemPetData (& p))
{    //Loads Vaccination ,prescripton and pet quiz data from file
    ifstream fin("VacnPres.txt");
    if (!fin)
    {
        cout << "The file of pet vaccination prescription data does not exist ";
    }
    for (int i = 0; i < 5; i++)
    {
        getline(fin, p.vaccinations[i], ',');
        getline(fin, p.prescription[i]);
    }
    fin.ignore(256, '\n');

    for (int i = 0; i < 3; i++)
        getline(fin, p.quiz[i], ',');
    fin.close();
}



string *donors(donation don,int &count)
{
    string *donors = new string[40];
    for (int i = 0; i < 40; i++)
        donors[i] = "";

    cin.ignore(256, '\n');
    cout << "Enter your name: ";
    getline(cin, donors[count]);
    cout << "Enter the amount(RS) you want to donate to  Pet Care Management System: ";
    cin >>don.amount ;
    count++;

    return donors;
}



bool saveDonorData(donation don , int count)
{
    ofstream fout("donor.txt",ios::app);

    if (!fout)
        return false;
    
    for (int i = 0; i < count; i++)
    {   if(don.arr[i]!="")
        fout << "Donor: " << don.arr[i] << "  amount: " << don.amount[i] <<"  RS"<< endl;
    }

    fout.close();
    return true;
}





bool loadGroomData(petHealth (& gr)[5])
{

    fstream fin("Groom.txt");
    if (!fin)
    {
        cout << "Groom file can't be opened  ";
        return false;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                getline(fin, gr[i].grooming[2]);
            }
            else
                getline(fin, gr[i].grooming[j], ',');
        }
    }

    fin.close();
    return true;
}



bool loadSchedule(petHealth (& sch)[5])
{
    fstream fin("Schedule.txt");
    if (!fin)
    {
        cout << "Schedule file can't be opened  ";
        return false; 
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                getline(fin, sch[i].schedule[2]);
            }
            else
                getline(fin, sch[i].schedule[j], ',');
        }
    }

    fin.close();
    return true;
}



int findPet(string arr[])
{
    string x;
    cout << "Enter pet name ";
    cin >> x;

    for (int i = 0; i < 5; i++)
    {
        if (toLowerCase(x) == arr[i])
        {
            return i;
        }
    }
    return -1;
}



void addDst( petHealth(&p)[5])
{       // DST=diseses-symptoms-treatments                  
       // function to add diseases
    ifstream fin;
    fin.open("DST.txt");
    if (!fin)
    {
        cout << "could not open  DST file ";
     
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            
            getline(fin, p[j].diseases[i], ':');
       
            getline(fin, p[j].symptoms[i], ':');

            getline(fin, p[j].treatment[i]);

            cout << endl;
        }
    }
   

   for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            
            cout<<p[i].diseases[j]<<" ";
       
            cout<<p[i].symptoms[j]<<" ";

            cout<<p[i].treatment[j]<<" ";

            cout << endl;
        }
    }




    fin.close();
}
 


void updateDst( petHealth(&p)[5], systemPetData & z)
{
// DST=diseses-symptoms-treatments   
// function to update diseases

    string dis;
    int index = findPet(z.petNames);
    if (index != -1)
    {    cout << "Enter the name of disease to update ";

    cin.ignore(256, '\n');
    getline(cin, dis);
    bool flag = false;

    for (int i = 0; i < 3; i++)
    {
        if (dis == p[index].diseases[i])
        {
            flag = true;
            cout << "Enter the name of new disease to be updated for " <<z.petNames[index] << " : ";
            getline(cin,  p[index].diseases[i]);

            cout << "Enter corresponding symptom of " <<  p[index].diseases[i] << " : ";
            getline(cin, p[index].symptoms[i]);

            cout << "Enter corresponding treatment of " << p[index].diseases[i] << " : ";

            getline(cin, p[index].treatment[i]);
            cout << endl;
            cout << "Disease: " << p[index].diseases[i] << ", Symptom: " << p[index].symptoms[i] << ", Treatment: " << p[index].treatment[i] << endl;
        }
    }
     if (!flag)
      {  cout << "This disease is not found ";}

    }
    else
    cout<<"This pet does not exist in system.";
   
    getch();
}



void deleteDst( petHealth(&p)[5], systemPetData(&data))
{
    bool flag = false;
    string dis;
    int index = findPet(data.petNames);
    if (index != -1)
  {      
    cout << "Enter the name of disease to delete ";
    cin.ignore(256, '\n');
    getline(cin, dis);
    for (int i = 0; i < 3; i++)
    {
        if (dis ==p[index].diseases[i])
        {
            flag = true;

            p[index].diseases[i] = "";
            p[index].symptoms[i] = "";
            p[index].treatment[i] = "";
            
            cout <<"Information deleted successfully ";
        }
    }
    if (!flag)
    {   cout << "Disease not found ";}}
 else
  {  cout<<"This pet does not exist in system.";}


getch();
}


int appointment()
{
    int apFee;
    gotoxy(45, 66);
    cout << "Enter appointment fee to be paid by user: ";
    cin >> apFee;
    return apFee;
}



bool checkupfee(int fee)
{
    int x;

       
        
            gotoxy(45, 62);
        cout << "Enter your appointment fee ";
        cin >> x;
            if (x >= fee)
        {
              cout << "You can have your pet's checkup.";
              return true;
        }
        else
        {
          
            cout << "You can't have your pet checkup.Please enter the exact appointment fee.\n ";
            Sleep(2000);
            clearArea(62);
            checkupfee(fee);
            getch();
}
        
    }




void showPets()
{

    gotoxy(45, 67);
    cout << "1.Dog" << right << setw(35) << "2.cat\n";
    gotoxy(45, 68);
    cout << "3.Goat" << right << setw(37) << "4.Rabbit\n";
    gotoxy(45, 69);
    cout << "5.Parrot";
    getch(); 
}



void vacPres(systemPetData & y)
{
    int index = findPet(y.petNames);
    if (index != -1)
    {
        cout << "Vaccination: " << y.vaccinations[index]<< endl;
        cout << "Prescription: " << y.prescription[index] << endl;
    }
    else
  {      cout << "Pet not found! \n";}
  getch();
}



void petGrooming(petHealth( & v)[5],systemPetData & u)
{
    int index = findPet(u.petNames);
    if (index != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << " . " << v[index].grooming[i] << endl;
        }
    }
    getch();
}



void petSchedule(petHealth ( sch)[5],systemPetData pet)

{
    int index = findPet(pet.petNames);
    if (index != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << sch[index].schedule[i] << endl;
        }
    }
    getch();
}



void feedQuiz(systemPetData pet)
{

    int count = 0;
    string x;
    int index = findPet(pet.petNames);
    if (index != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << replace(pet.quiz[i], "pet", pet.petNames[index]) << " (Yes/No):  \n";
              cin >> x;
            while (true)
            {
              
                toLowerCase(x);
                if (x == "yes")
                {
                    count++;
                    break;
                }
                else if (x == "no")
                {
                    break;
                }
                else
                {
                    cout << "invalid answer.Choose again \n";
                }
                cin >> x;
            }
        }

        if (count == 3)
           { cout << "Your " << pet.petNames[index] << " feeding is perfect.Good job!";}

        else if (count == 2)
          {  cout << "Your " << pet.petNames[index] << " feeding is well.A slight improvemnt will do the work";}
        else if (count == 1)
          {   cout << "Poor feeding";}
        else
          {   cout << "You want your " << pet.petNames[index] << " to die ?Dont you?";}
    }
    else
         { cout << "Pet not found";}
         getch();
}



string toLowerCase(string X)
{

    for (size_t i = 0; i < X.length(); i++)
    {
        if (X[i] >= 'A' && X[i] <= 'Z')
            X[i] = X[i] + 32;
    }
    return X;
}



string replace(string mainStr, string replaceStr, string newStr)
{
    string emp ="";
    size_t i = 0;
    while (i < mainStr.length())
    {
        size_t k;
        for (k = 0; k < replaceStr.length(); k++)
        {
            if (mainStr[i + k] != replaceStr[k])
            {
                break;
            }
        }
        if (k == replaceStr.length())
        {
            emp += newStr;
            i += replaceStr.length();
        }
        else
        {
            emp += mainStr[i + k];
            i++;
        }
    }
    return emp;
}




void petCheckup( petHealth (&p)[5],systemPetData & x)
{
    int index = findPet(x.petNames);
    int no=0;
    bool flag=false;
    if (index != -1 )
    {   
        int indices[3];
        cout << "Choose a symptom you observe in your " << x.petNames[index] << " \n";
        for (int i = 0; i < 3; i++)
            {if(p[index].symptoms[i]!="")
              {flag=true;
              indices[no]=i;
            cout << no+1 << "." << p[index].symptoms[i] << endl;
            no++;
            }
            }
        int choice;
        cin >> choice;
        choice = indices[choice - 1];

        cout << "Your " << x.petNames[index] << " suffers from "  << p[index].diseases[choice] << endl;
        cout << "Treatment for your " << x.petNames[index] << " is " << p[index].treatment[choice] << endl;
    }

    else if (!flag)
    {
        cout << "Admin has not yet added medical information ";
    }

    else
    {
        cout << "Pet not found \n";
    }
    getch();
}


void clearArea(int j)
{
    for (int i = j; i < (j + 20); i++)
    {
        gotoxy(0, i);
         for(int i=0;i<120;i++){
            cout<<' ';
         }
    }
}


bool saveData(petHealth( & pet)[5]){
    ofstream fout("DST.txt");
    if (!fout)
    {
    cout<<"File not opened: error ";
    return false;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            if(!(pet[i].diseases[j]==""))
            {
            fout<<pet[i].diseases[j]<<":";
            fout<<pet[i].symptoms[j]<<":";
            fout<<pet[i].treatment[j]<<endl;
            } 
            else if((pet[i].diseases[j]==""))
            {fout<<pet[i].diseases[j]<<":";
            fout<<pet[i].symptoms[j]<<":";
            fout<<pet[i].treatment[j]<<endl;
}
        }
    }
    fout.close();
    return true;
}



 int moneyValidation(){

    int input;   
    
    while(true)
    { 
        cout<<"Enter amount: ";
        cin>>input;
            if(!cin)
        {

                cin.clear();
                cin.ignore(256,'\n');
        }
        else 
        {  break;}
        }
        return input;
}
