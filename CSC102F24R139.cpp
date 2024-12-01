#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;

void gotoxy(int x, int y);

void clearArea(int j);
void splashCat();
bool flag = false;

int findPet(string petNames[], int n);
void subMenu1();
void subMenu2();
void subMenu3();
void mainMenu();
void submenu4();
void showPets();
bool checkupfee(int);
string toLowerCase(string X);
void printHeader();
int appointment();
int intValidation();
string replace(string mainStr, string replaceStr, string newStr);
void loadVacNPresNQuiz(string vac[], string pres[], string arr[]);

void petSchedule(string petNames[], int n, string arr[][3]);
void petGrooming(string petNames[], int n, string groom[][3]);
void feedQuiz(string petNames[], string quiz[], int n);
void vacPres(string petNames[], int n, string vac[], string pres[]);
void addDst( string diseases[][3], string symptoms[][3], string treatment[][3], int n);
void updateDst(string petNames[], string diseases[][3], string symptoms[][3], string treatment[][3], int n);
void deleteDst(string petNames[], string diseases[][3], string symptoms[][3], string treatment[][3], int n);
void petCheckup(string petNames[], string diseases[][3], string symptoms[][3], string treatment[][3], int n);
string * donors(char amount[][10], int &count);
bool saveDonorData(string *donors, char amount[][10], int count);
bool loadSchedule(string schedule[][3], int n);
bool loadGroomData(string groom[][3], int n);
// bool loadDonorData(string *donors, char amount[][10]);

int main()
{
    system("chcp 65001");
   
    


    int count = 0;
    int op = -1;
    int amount=0, choice;
    string id = "", pwd = "";
    const int MAX_PETS = 5;

    string schedule[MAX_PETS][3];

    string grooming[MAX_PETS][3]; // Grooming suggestion array for pets of particular type

    string petNames[MAX_PETS] = {"dog", "cat", "goat", "rabbit", "parrot"};
    string pets[MAX_PETS] = {"▼ ᴥ ▼", " =^.^= ", "\\ᐠ-ꞈ-ᐟ/", "₍ᐢ.w.ᐢ₎", "⋆.˚(\\(o/\\o)/)"};

    string vaccinations[MAX_PETS];
    string prescription[MAX_PETS];

    string diseases[MAX_PETS][3];
    string symptoms[MAX_PETS][3];
    string treatment[MAX_PETS][3];
    string quiz[3];
    char donAmount[10][10];
    for (int i = 0; i < MAX_PETS; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            diseases[i][j] = "";
            symptoms[i][j] = "";
            treatment[i][j] = "";
        }
    }
   
    addDst( diseases, symptoms, treatment, MAX_PETS);
    loadVacNPresNQuiz(vaccinations, prescription, quiz);
    loadSchedule(schedule, MAX_PETS);
    loadGroomData(grooming, MAX_PETS);
   
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
                            updateDst(petNames, diseases, symptoms, treatment, MAX_PETS);
                            
                            break;
                        }
                        case 3:
                        {
                            deleteDst(petNames, diseases, symptoms, treatment, MAX_PETS);
                          
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

                            Sleep(3000); 
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
                            petCheckup(petNames, diseases, symptoms, treatment, MAX_PETS);
                            
                            break;
                        }
                        case 2:
                        {
                            vacPres(petNames, MAX_PETS, vaccinations, prescription);
                          
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
                    feedQuiz(petNames, quiz, MAX_PETS);
               
                    break;
                }
                case 2:
                {
                    petGrooming(petNames, MAX_PETS, grooming);
                    
                    break;
                }
                case 3:
                {
                    petSchedule(petNames, MAX_PETS, schedule);
                   
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    cout << "Invalid choice ";
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
                    int index = findPet(petNames, 5);
                    gotoxy(45, 72);
                    cout << "Here is your " << petNames[index] << " " << pets[index] << endl;
                    getch();
                    break;
                }
                case 2:
                {
                    string *arr = donors(donAmount, count);
                    saveDonorData(arr, donAmount, count);
                }
                
                    
                default:
                  {  break;}
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
   //Displays the cta on start of screen for few seconds
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
    Sleep(3500); // uncomment when done fhandling
    system("cls");
}



void loadVacNPresNQuiz(string vaccinations[], string prescription[], string arr[])
{    //Loads Vaccination ,prescripton and pet quiz data from file
    ifstream fin("VacnPres.txt");
    if (!fin)
    {
        cout << "The file of pet vaccination prescription data does not exist ";
    }
    for (int i = 0; i < 5; i++)
    {
        getline(fin, vaccinations[i], ',');
        getline(fin, prescription[i]);
    }
    fin.ignore(256, '\n');

    for (int i = 0; i < 3; i++)
        getline(fin, arr[i], ',');
    fin.close();
}



string *donors(char amount[][10], int &count)
{
    string *donors = new string[40];
    for (int i = 0; i < 40; i++)
        donors[i] = "";

    cin.ignore(256, '\n');
    cout << "Enter your name: ";
    getline(cin, donors[count]);
    cout << "Enter the amount(RS) you want to donate to  Pet Care Management System: ";
    cin >> amount[count];
    count++;

    return donors;
}



bool saveDonorData(string *donors, char amount[][10], int count)
{
    ofstream fout("donor.txt",ios::app);

    if (!fout)
        return false;
    
    for (int i = 0; i < count; i++)
    {   if(donors[i]!="")
        fout << "Donor: " << donors[i] << "  amount: " << amount[i] <<"  RS"<< endl;
    }

    fout.close();
    return true;
}





bool loadGroomData(string groom[][3], int n)
{
    fstream fin("Groom.txt");
    if (!fin)
    {
        cout << "Groom file can't be opened  ";
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                getline(fin, groom[i][2]);
            }
            else
                getline(fin, groom[i][j], ',');
        }
    }

    fin.close();
    return true;
}



bool loadSchedule(string schedule[][3], int n)
{
    fstream fin("Schedule.txt");
    if (!fin)
    {
        cout << "Schedule file can't be opened  ";
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 2)
            {
                getline(fin, schedule[i][2]);
            }
            else
                getline(fin, schedule[i][j], ',');
        }
    }

    fin.close();
    return true;
}



int findPet(string petNames[], int n)
{
    string x;
    cout << "Enter pet name ";
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (toLowerCase(x) == petNames[i])
        {
            return i;
        }
    }
    return -1;
}



void addDst( string diseases[][3], string symptoms[][3], string treatment[][3], int n)
{      // DST=diseses-symptoms-treatments                  
      // function to add diseases
    ifstream fin;
    fin.open("DST.txt");
    if (!fin)
    {
        cout << "could not open  DST file ";
     
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            
            getline(fin, diseases[j][i], ':');
       
            getline(fin, symptoms[j][i], ':');

            getline(fin, treatment[j][i]);

            cout << endl;
        }
    }
   
    fin.close();
}



void updateDst(string petNames[], string diseases[][3], string symptoms[][3], string treatment[][3], int n)
{ // DST=diseses-symptoms-treatments   
 // function to update diseases
    string dis;
    int index = findPet(petNames, n);
    if (index != -1)
    {    cout << "Enter the name of disease to update ";

    cin.ignore(256, '\n');
    getline(cin, dis);
    bool flag = false;

    for (int i = 0; i < 3; i++)
    {
        if (dis == diseases[index][i])
        {
            flag = true;
            cout << "Enter the name of new disease to be updated for " << petNames[index] << " : ";
            getline(cin, diseases[index][i]);

            cout << "Enter corresponding symptom of " << diseases[index][i] << " : ";
            getline(cin, symptoms[index][i]);

            cout << "Enter corresponding treatment of " << diseases[index][i] << " : ";

            getline(cin, treatment[index][i]);
            cout << endl;
            cout << "Disease: " << diseases[index][i] << ", Symptom: " << symptoms[index][i] << ", Treatment: " << treatment[index][i] << endl;
        }
    }
     if (!flag)
      {  cout << "This disease is not found ";}

    }
    else
    cout<<"This pet does not exist in system.";
   
    getch();
}



void deleteDst(string petNames[], string diseases[][3], string symptoms[][3], string treatment[][3], int n)
{
    bool flag = false;
    string dis;
    int index = findPet(petNames, n);
    if (index != -1)
  {      
    cout << "Enter the name of disease to delete ";
    cin.ignore(256, '\n');
    getline(cin, dis);
    for (int i = 0; i < 3; i++)
    {
        if (dis == diseases[index][i])
        {
            flag = true;

            diseases[index][i] = "";
            symptoms[index][i] = "";
            treatment[index][i] = "";

            cout << "Information deleted successfully ";
        }
    }
    if (!flag)
    {   cout << "Disease not found ";}
 else
  {  cout<<"This pet does not exist in system.";}
}
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

       
        while(true)

        { gotoxy(45, 62);
        cout << "Enter your appointment fee ";
        cin >> x;
            if (x >= fee)
        {
         
           
            cout << "You can have your pet's checkup.";
           
              return true;
          break;
        }
        else
        {
          
            cout << "You can't have your pet checkup.Please enter the exact appointment fee.\n ";
            Sleep(2000);
            // clearArea(62);
}
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



void vacPres(string petNames[], int n, string vac[], string pres[])
{
    int index = findPet(petNames, n);
    if (index != -1)
    {
        cout << "Vaccination: " << vac[index] << endl;
        cout << "Prescription: " << pres[index] << endl;
    }
    else
  {      cout << "Pet not found! \n";}
  getch();
}



void petGrooming(string petNames[], int n, string groom[][3])
{
    int index = findPet(petNames, n);
    if (index != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << groom[index][i] << endl;
        }
    }
    getch();
}



void petSchedule(string petNames[], int n, string arr[][3])
{
    int index = findPet(petNames, n);
    if (index != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << arr[index][i] << endl;
        }
    }
    getch();
}




void feedQuiz(string petNames[], string quiz[], int n)
{

    int count = 0;
    string x;
    int index = findPet(petNames, n);
    if (index != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << replace(quiz[i], "pet", petNames[index]) << " (Yes/No):  \n";
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
           { cout << "Your " << petNames[index] << " feeding is perfect.Good job!";}

        else if (count == 2)
          {  cout << "Your " << petNames[index] << " feeding is well.A slight improvemnt will do the work";}
        else if (count == 1)
          {   cout << "Poor feeding";}
        else
          {   cout << "You want your " << petNames[index] << " to die ?Dont you?";}
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
    string emp = "";
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




void petCheckup(string petNames[], string diseases[][3], string symptoms[][3], string treatment[][3], int n)
{
    int index = findPet(petNames, n);

    if (index != -1 && diseases[index][0] != "")
    {
        cout << "Choose a symptom you observe in your " << petNames[index] << " \n";
        for (int i = 0; i < 3; i++)
            cout << i + 1 << "." << symptoms[index][i] << endl;
        int smp;
        cin >> smp;
        smp = smp - 1;

        cout << "Your " << petNames[index] << " suuffers from " << diseases[index][smp] << endl;
        cout << "treatment for your" << petNames[index] << "is " << treatment[index][smp] << endl;
    }

    else if (diseases[index][0] == "")
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
        cout << string(120, ' ');
    }
}
