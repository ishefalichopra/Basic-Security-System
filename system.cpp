#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1, age1;
    string creds[2], cp[2] ={"",""};
    bool password_changed = false;

    cout << "        Security System" << endl;
    cout << "______________________________" << endl
         << endl;
    cout << "|        1. Register         |" << endl;
    cout << "|        2. Login            |" << endl;
    cout << "|        3. Change Password  |" << endl;
    cout << "|________4. End Program______|" << endl
         << endl;

    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice.";
        cin >> a;
        switch (a)
        {

        case 1:
        {
            cout << "________________________" << endl
                 << endl;
            cout << "|-------Register-------|" << endl;
            cout << "|______________________|" << endl
                 << endl;
            cout << "Please enter your username:";
            cin >> name;
            cout << "Please enter the password:";
            cin >> password0;
            cout << "Please enter you age:";
            cin >> age;

            ofstream of1; // writing purpose uses ofstream and for reading we use ifstream
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0 << "\n";
                of1 << age <<"\n";
                cout << "Registration successful" << endl;
                of1.close();
                
            }
            else{
                cout<<"Error opening file"<<endl;
            }

            break;
        }
      case 2:
{
    cout << "__________________________" << endl << endl;
    cout << "|---------Login----------|" << endl;
    cout << "|________________________|" << endl << endl;

    ifstream file;
    file.open("file.txt");
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        break;
    }

    cout << "Please enter the username:";
    cin >> user;
    cout << "Please enter the password:";
    cin >> pass;
    cout << "Please enter the age:";
    cin >> age1;

    bool found = false;
    while (getline(file, name))
    {
        getline(file, password0);
        getline(file, age);

        if (user == name && pass == password0 && age == age1)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "---Login successful---" << endl << endl;
        cout << "Details:" << endl;
        cout << "Username: " << name << endl;
        cout << "Password: " << password0 << endl;
        cout << "Age: " << age << endl;
        file.close();
    }
    else
    {
        cout << endl << endl;
        cout << "Incorrect username, password or age" << endl;
        file.close();
    }
    break;
}



        case 3:
{
    i = 0;
    cout << "-------Change Password-------" << endl;

    ifstream of0;
    of0.open("file.txt");
    cout << "Enter the old password:";
    cin >> old;
    if (of0.is_open())
    {
        
            while (getline(of0, text))
            {
                istringstream iss(text);
                iss >> word1;
                cp[i] = word1;
                i++;
            }

            if (old == cp[1])
            {
                of0.close();

                ofstream of1;
                of1.open("file.txt");
                if (of1.is_open())
                {
                    cout << "Enter your new password:" << endl;
                    cin >> password1;
                    cout << "Enter your password again:" << endl;
                    cin >> password2;

                    if (password1 == password2)
                    {
                        of1 << cp[0] << "\n";
                        of1 << password1;
                        cout << "Password changed successfully" << endl;
                    }
                    else
                    {
                        of1 << cp[0] << "\n";
                        of1 << old;
                        cout << "Password do not match" << endl;
                    }

                    of1.close();
                    break; // break out of the outer while loop once password is changed
                }
            }
            else
            {
                cout << "Please enter a valid password" << endl;
                break;
            }
        

        break;
    }
}


        case 4:
        {
            cout << "_______ThankYou !_______";
            return 0;
        }

        default:
            cout << "Enter a valid choice" << endl;
        }
    } while (a != 4);

    return 0;
}
