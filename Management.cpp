#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Employee {
private:
    string Name;
    int age;
    double salary;
    int id;
    string phone_number;
    string gender;
    string email;
    string start_date;

public:
    Employee();
    void Outp() const; 
    void Inp(vector<int>& em_id);
    int GetID() const; 
    string getName() const; 
    void Outfile(ofstream &output) const; 
    void Infile(ifstream &input); 
};


int Employee::GetID() const {
    return id;
}

string Employee::getName() const {
    return Name;
}

Employee::Employee() {
    id = 0;
    Name = "";
    age = 0;
    salary = 0.0;
    string phone_number="";
    string gender="";
    string email="";   
    start_date = "";
}
void Employee::Outp() const {
    cout << "_______________________________" << endl;
    cout << "|___Employee ID: "<<id<< endl;
    string upperName=Name;
    for(char &c:upperName)
    {
        c=toupper(c);
    }
    cout << "|___Name: "<<upperName<< endl;
    cout << "|___Age: "<<age<< endl;
    cout << "|___Salary: "<<salary<<"$"<< endl;
    cout << "|___Phone Number: "<<phone_number<< endl;
    string upperGender=gender;
    for(char &x:upperGender)
    {
        x=toupper(x);
    }
    cout << "|___Gender: "<<upperGender<< endl;
    cout << "|___Email: "<<email<<endl;
    cout << "|___Day started "<<start_date<<endl;
    cout << "_______________________________" << endl;
}
void Employee::Inp(vector<int>& em_id) {
    do{
        cout << "Employee ID: ";
        cin>>id;
        if(cin.fail()||id<0||find(em_id.begin(),em_id.end(),id) !=em_id.end())
        {
            cout<<"*Wrong input(must be number or unique ID)*"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            id=-1;
        }
    }while(cin.fail()||id<0);

    cin.ignore();

    do 
    {
        cout << "Name: ";
        getline(cin, Name);
        if (Name.empty() || any_of(Name.begin(), Name.end(), ::isdigit)) 
        {
            cout << "*Invalid name. Name should not contain numbers.*" << endl;
        }
    }while (Name.empty() || any_of(Name.begin(), Name.end(), ::isdigit));


    do{
        cout << "Age: ";
        cin >> age;
        if(age<16||cin.fail())
        {
            cout<<"*Wrong input(age must >16)*"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(age<16||cin.fail());

    
    cin.ignore();
    do{
        cout << "Salary: ";
        cin >> salary;
        if(cin.fail()||salary<0)
        {
            cout<<"*Wrong input*"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            salary=-1;
        }
    }while(cin.fail()||salary<0);
    cin.ignore();
    do
    {
        cout<<"Phone Number:";
        getline(cin,phone_number);
        if(phone_number.empty())
        {
            cout<<"*Please enter*"<<endl;
        }

    }while(phone_number.empty());
    do
    {
        cout<<"Gender(M or F):";
        getline(cin,gender);
        if(gender.empty())
        {
            cout<<"*Please enter*"<<endl;
        }

    }while(gender.empty());
    do
    {
        cout<<"Email: ";
        getline(cin,email);
        if(email.empty())
        {
            cout<<"*Please enter*"<<endl;
        }

    }while(email.empty());
    
    do
    {
        cout << "Start Work at: ";
        getline(cin, start_date);
        if(start_date.empty())
        {
            cout<<"*Please enter*"<<endl;
        }

    }while(start_date.empty());
    

    
}

void Employee::Outfile(ofstream &output) const {
    output << endl;
    output << "_____________________________" << endl;
    output << "|__Employee ID: "<<id<< endl;
    string upperName=Name;
    for(char &c:upperName)
    {
        c=toupper(c);
    }
    output << "|__Name: "<<upperName<< endl;
    output << "|__Age: "<<age<< endl;
    output << "|__Salary: "<<salary<<"$"<< endl;
    output << "|__Day Started:"<<start_date<< endl;
    output << "|_____________________________" << endl;
}

int main() {
    const string Correct_Password = "admin123";
    vector<Employee> employees;
    vector<int>em_id;
    for(auto i:employees)
    {
        em_id.push_back(i.GetID());
    }

    for (int i = 0; i < 3; i++) {
        string Password;
        cout << "\n______________________________________________" << endl;
        cout << "Please enter the Password (only 3 times): ";
        getline(cin,Password);

        if (Password == Correct_Password) {
            while (true) 
			{
                cout << "_______________________MAIN MENU____________________________________|" << endl;
                cout << "|-1-----------> Show all info employee <----------------------------|" << endl;
                cout << "|-2-----------> Search employee <-----------------------------------|" << endl;
                cout << "|-3-----------> Add employee <--------------------------------------|" << endl;
                cout << "|-4-----------> Delete exact employee <-----------------------------|" << endl;
                cout << "|-5-----------> Delete all employee <-------------------------------|" << endl;
                cout << "|-6-----------> Update info employee <------------------------------|" << endl;
                cout << "|-7-----------> Save File (important after close terminal) <--------|" << endl;
                cout << "|-8-----------> Save all employee to history database file<---------|" << endl;
                cout << "|-9-----------> Load File(Read file) <------------------------------|" << endl;
                cout << "|-0-----------> EXIT <----------------------------------------------|" << endl;
                cout << "|___________________________________________________________________|" << endl;
                cout << "|----------File log auto creat if you want to check operation-------|" <<endl;
                cout << "|___________________________________________________________________|" << endl;
                
                int choice;
                
                do{
                    cout << "Please enter the number: ";
                    cin >> choice;
                    if(cin.fail())
                    {
                        cout<<"*Wrong input*"<<endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        
                    }
                }while(cin.fail());        
                switch (choice) {
                    case 1:
                        if (employees.empty()) {
                            cout << "~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "No things to show" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~" << endl;
                        } else {
                            for (const auto &x : employees) {
                                x.Outp();
                            }
                        }
                        break;
                    case 2: {
                        cout << "______1.Search for name___" << endl;
                        cout << "______2.Search for ID_____" << endl;
                        cout << "______0.Back_____________"<<endl;
                        cout<<"Your choice:";
                        int choice2;
                        cin >> choice2;
                        cin.ignore();
                        if (choice2 == 1) {
                            bool found = false;
                            string check_name;
                            do
                            {
                                cout << "Nhap Ten: ";
                                getline(cin, check_name);
                                if(check_name.empty()||any_of(check_name.begin(),check_name.end(),::isdigit))
                                {
                                    cout<<"*Wrong input*"<<endl;
                                }
                            }while(check_name.empty()||any_of(check_name.begin(),check_name.end(),::isdigit));
                            for (const auto &x : employees) {
                                if (x.getName() == check_name) {
                                    x.Outp();
                                    found = true;
                                }
                            }
                            if (!found) {
                                cout<<"________________"<<endl;
                                cout << "Not found" << endl;
                                cout<<"_________________"<<endl;
                                cout<<endl;
                            }
                        } else if (choice2 == 2) {
                            int check_id;
                            do
                            {
                                cout << "Nhap ID: ";
                                cin >> check_id;
                                if(cin.fail()||check_id<0)
                                {
                                    cout<<"*Wrong input*"<<endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    check_id=-1;
                                }
                            }while(cin.fail()||check_id<0);
                            
                            bool found = false;
                            for (const auto &x : employees) {
                                if (x.GetID() == check_id) {
                                    x.Outp();
                                    found = true;
                                    
                                }
                            }
                            if (!found) {
                                cout << "Not found" << endl;
                            }
                        }
                        else if(choice2==0)
                        {
                            cout<<"<--Back"<<endl;
                            break;
                        }
                        else{
                            cout<<"Wrong input"<<endl;
                        }
                        break;
                    }
                    case 3: {
                        int num_emp;
                        do{
                            cout << "Number of employees you want to add: ";
                            cin >> num_emp;
                            if(cin.fail())
                            {
                                cout<<"*Wrong input"<<endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }
                        }while(cin.fail());

                        for (int i = 0; i < num_emp; i++) {
                            Employee emp;
                            emp.Inp(em_id);
                            employees.push_back(emp);
                            em_id.push_back(emp.GetID());
                        }
                        break;
                    }
                    case 4: {
                        int del_id;
                        do
                        {
                            cout << "Enter ID you want to remove: ";
                            cin >> del_id;
                            if(cin.fail()||del_id<0)
                            {
                                cout<<"*Wrong input*"<<endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                del_id=-1;
                            }
                            
                        }while(cin.fail()||del_id<0);
                        bool found=false;
                        for(int i=0;i<employees.size();i++)
                        {
                            if(employees[i].GetID()==del_id)
                            {
                                employees.erase(employees.begin()+i);
                                em_id.erase(remove(em_id.begin(),em_id.end(),del_id),em_id.end());
                                found=true;
                                cout<<"Delete Success"<<endl;
                                break;
                            }
                            
                        }
                        if(!found)
                        {
                            cout<<"Not Found"<<endl;
                        }
                        break;
                    }
                    case 5: {
                        employees.clear();
                        cout << "**All employees cleared**" << endl;
                        break;
                    }
                    case 6: {
                        
                        int upd_id;
                        do
                        {
                            cout << "Enter ID you want to update: ";
                            cin>>upd_id;
                            if(cin.fail()||upd_id<0)
                            {
                            cout<<"*Wrong input*"<<endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            upd_id=-1;
                            }
                        }while(upd_id<0);
                        bool found = false;
                        for (auto &x : employees) {
                            if (x.GetID() == upd_id) {
                                cout << "Updating Employee:" << endl;
                                x.Inp(em_id);
                                em_id.erase(remove(em_id.begin(),em_id.end(),upd_id),em_id.end());
                                em_id.push_back(upd_id);
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "Employee not found" << endl;
                        }
                        break;
                    }
                    case 7: {
                        string filename="Employees.txt";
                        ofstream output(filename,ios::app);
                        if(employees.empty())
                        {
                            cout<<"EMPTY"<<endl;
                        }
                        else
                        {
                            cout<<"Load 25%"<<endl;
                            Sleep(500);
                            cout<<"Load 50%"<<endl;
                            Sleep(500);
                            cout<<"Load 75%"<<endl;
                            Sleep(500);
                            cout<<"Load 90%"<<endl;
                            Sleep(500);
                            char time[]=__TIME__;
                            char date[]=__DATE__;
                            output<<"Date added: "<<date<<endl;
                            output<<"Time added: "<<time<<endl;
                            for (const auto &x : employees) 
                            {
                                x.Outfile(output);
                            }
                            cout<<"Load 100%"<<endl;
                            cout << "SAVE FILE SUCCESSFULLY" << endl;
                            output.close();    
                        }
                        break;
                    }
                    case 8: {
                        
                        string filenamehis = "History File.txt";
                        if(employees.empty())
                        {
                            cout<<"EMPTY"<<endl;
                        }
                        else
                        {
                            ofstream output(filenamehis, ios::app);
                            char date[]=__DATE__;
                            char time[]=__TIME__;
                            output<<"Date: "<<date<<endl;
                            output<<"Time: "<<time<<endl;
                            cout<<"Load 25%"<<endl;
                            Sleep(500);
                            cout<<"Load 50%"<<endl;
                            Sleep(500);
                            cout<<"Load 75%"<<endl;
                            Sleep(500);
                            cout<<"Load 90%"<<endl;
                            Sleep(500);
                            for (const auto &x : employees) {
                                x.Outfile(output);
                            }
                            output<<"__________________________________"<<endl;
                            output.close();
                            cout<<"Load 100%"<<endl;
                            cout << "History saved." << endl;
                            
                        }
                        break;
                        
                    }
                    case 9:{
                        string filename ="Employees.txt";
                        ifstream input(filename);
                        string line;
                        
                        while(getline(input,line))
                        {
                            cout<<line<<endl;
                        }
                        break;
                    }    
                    case 0:
                        cout << "Exiting the program." << endl;
                        return 0;
                    default:
                        cout << "Wrong syntax" << endl;
                }

                string Filelogname="FileLog.txt";
                ofstream output(Filelogname,ios::app);
                char date[]=__DATE__;
                char time[]=__TIME__;
                output<<"Date: "<<date<<endl;
                output<<"Time: "<<time<<endl;
                output<<"Your Last Operation :";
                switch(choice)
                {
                	case 2:
                		output<<"You Searched employee"<<endl;
                        output<<"___________________"<<endl;
                        break;
                	case 3:
                		output<<"You added employee"<<endl;
                        output<<"___________________"<<endl;
                        break;
                	case 4:
                		output<<"You deleted an employee"<<endl;
                        output<<"___________________"<<endl;
                        break;
                	case 5:
                		output<<"You deleted all employee"<<endl;
                        output<<"___________________"<<endl;
                        break;
                	case 6:
                		output<<"You updated employee"<<endl;
                        output<<"___________________"<<endl;
                        break;
                	case 7:
                		output<<"You saved the file"<<endl;
                        output<<"___________________"<<endl;
                        break;
                	case 8:
                		output<<"You saved the file to his-database"<<endl;
                        output<<"___________________"<<endl;
                        break;
                    case 0:
                        output<<"Exiting"<<endl;
                        output<<"___________________"<<endl;
                        break;                  
				}
                
                output.close();
            }
        } else 
		{
            cout << "Wrong Password" << endl;
        }
    }
}
