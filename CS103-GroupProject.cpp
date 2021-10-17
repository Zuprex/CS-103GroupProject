// The Group Project will be based on the NZ Blood Bank System.


#include <iostream>

// Objects

struct userDonor
{

    // User Attributes

    std::string firstName;
    std::string lastName;
    std::string dob;
    std::string nationality;
    std::string ethnicity;
    std::string gender;
    std::string healthConditions; // This needs to be a dynamic array.
    std::string bloodGroup;
    std::string contactNum;
    std::string email;
    std::string physAddress;

    // Donator Only
    std::string prevDonate;

    // Login Details

    std::string username;
    std::string password;

    //Constructor

    userDonor() {};

    userDonor(std::string fName, std::string lName, std::string date, std::string nat, std::string eth, std::string gen, std::string healthCon, std::string bloodG, std::string contactN, std::string em, std::string physAdd, std::string prevD, std::string user, std::string pass) {
    
        firstName = fName;
        lastName = lName;
        dob = date;
        nationality = nat;
        ethnicity = eth;
        gender = gen;
        healthConditions = healthCon;
        bloodGroup = bloodG;
        contactNum = contactN;
        email = em;
        physAddress = physAdd;
        prevDonate = prevD;
        username = user;
        password = pass;
    
    }

};

struct userRes
{

    // Attributes

    std::string recipient;
    std::string physAddress;
    std::string email;
    std::string contactNum;
    std::string validationStatus;

    // Login Details

    std::string username;
    std::string password;

    //Constructor

    userRes() {}

    userRes(std::string recip, std::string physAdd, std::string em, std::string contactN, std::string val, std::string user, std::string pass) {
    
        recipient = recip;
        physAddress = physAdd;
        email = em;
        contactNum = contactN;
        validationStatus = val;
        username = user;
        password = pass;
    
    }

};

// Global/Field Variables *****************************************************************

const int size = 5;
userDonor donorList[size];
userRes resList[size];
int registeredDonors = 0;
int registeredRes = 0;

userDonor currentDonor;
userRes currentRes;

// Global/Field Variables *****************************************************************

// Introduction

void blank() {

    

}

void introduction() {

    std::cout << "\n\t    The Blood Bank of New Zealand\n\n";

    std::cout << "*****************************************************\n\n";
    std::cout << "*                      About Us                     *\n\n";
    std::cout << "* We are a New Zealand organisation that is aimming *\n\n";
    std::cout << "* to help get people who are in need of blood. Any  *\n\n";
    std::cout << "* donations we recieve is given to people in need!  *\n\n";
    std::cout << "*                                                   *\n\n";
    std::cout << "*****************************************************\n\n";

    std::cout << "*****************************************************\n\n";
    std::cout << "*                     Contact                       *\n\n";
    std::cout << "*           Phone Number: 022 196 9532              *\n\n";
    std::cout << "*           Address: 68 Mohaka Street               *\n\n";
    std::cout << "*           Open: Saturdays - Sundays               *\n\n";
    std::cout << "*                                                   *\n\n";
    std::cout << "*****************************************************\n\n";


}

int loginAttempts = 0;

void login() {

    std::string username;
    std::string password;

    std::cout << "\nPlease enter your Username: ";
    std::cin >> username;

    std::cout << "\nPlease enter your Password: ";
    std::cin >> password;


    for (int i = 0; i < size;i++) {
    
        if (donorList[i].username == username) {
            
            if (donorList[i].password == password) {
            
                currentDonor = donorList[i];
                currentRes = userRes();
            
            }

        
        }
    
    }

    for (int i = 0; i < size; i++) {

        if (resList[i].username == username) {

            if (resList[i].password == password) {

                currentRes = resList[i];
                currentDonor = userDonor();

            }

        }

    }

    if (loginAttempts > 3) {
    
        std::cout << "\n\nToo many incorrect attempts. Please exit the console. ";
        loginAttempts++;
        exit;
        abort();
    
    }
    else {
    
        login();
    
    }

    loginAttempts++;

}

void donorRegistration() {

    std::string firstName;
    std::string lastName;
    std::string dob;
    std::string nationality;
    std::string ethnicity;
    std::string gender;
    std::string healthConditions;
    std::string bloodGroup;
    std::string contactNum;
    std::string email;
    std::string physAddress;
    std::string prevDonate;
    std::string username;
    std::string password;

    std::cout << "\nWhats is your first name? ";
    std::cin >> firstName;

    std::cout << "\nWhats is your last name? ";
    std::cin >> lastName;

    std::cout << "\nWhats is your Date of birth? (Use '00/00/00' Format ) ";
    std::cin >> dob;

    std::cout << "\nWhats is your Nationality? ";
    std::cin >> nationality;

    std::cout << "\nWhats is your Ethnicity? ";
    std::cin >> ethnicity;

    std::cout << "\nWhats is your Gender? ";
    std::cin >> gender;

    std::cout << "\nDo you have any current health conditions? ";
    std::cin >> healthConditions;

    std::cout << "\nWhats is your Blood Group? ";
    std::cin >> bloodGroup;

    std::cout << "\nWhats is your contact email? ";
    std::cin >> email;

    std::cout << "\nWhats is your Physical Address? ";
    std::cin >> physAddress;

    std::cout << "\nWhats is the last date of your Blood donation? (Use '00/00/00' Format or Enter 'None' if you haven't) ";
    std::cin >> prevDonate;

    std::cout << "\nEnter your desired Username ";
    std::cin >> username;

    std::cout << "\nEnter your desired Password ";
    std::cin >> password;

    userDonor newUser = userDonor(firstName, lastName, dob, nationality, ethnicity, gender, healthConditions, bloodGroup, contactNum, email, physAddress, prevDonate, username, password);

    donorList[registeredDonors] = newUser;

    registeredDonors++;


}

void recipientRegistration() {

    std::string recipient;
    std::string physAddress;
    std::string email;
    std::string contactNum;
    std::string validationStatus;
    std::string username;
    std::string password;

    std::cout << "\nEnter the Name of the Hostpital OR Name of the Blood Bank OR Patient Name ";
    std::cin >> recipient;

    std::cout << "\nEnter your physical address ";
    std::cin >> physAddress;

    std::cout << "\nEnter your email ";
    std::cin >> email;

    std::cout << "\nEnter your Contact Number ";
    std::cin >> contactNum;

    std::cout << "\nEnter your Validation Status ";
    std::cin >> validationStatus;

    std::cout << "\nEnter your desired Username ";
    std::cin >> username;

    std::cout << "\nEnter your desired Password ";
    std::cin >> password;

    userRes newUser = userRes(recipient,physAddress,email,contactNum,validationStatus,username,password);

    resList[registeredRes] = newUser;

    registeredRes++;

}


// First Choice for user

void initialMenu() {

    std::cout << "*****************************************************\n\n";
    std::cout << "*                     Menu                          *\n\n";
    std::cout << "*                Enter 1 to Login                   *\n\n";
    std::cout << "*               Enter 2 to Register                 *\n\n";
    std::cout << "*****************************************************\n\n";

    int choice;

    std::cin >> choice;

    std::cout << std::endl;

    switch (choice)
    {

    case 1: // Login

        login();

    case 2: // Registration

        std::cout << "           Are you a Donor or Recipient?\n";
        std::cout << "*****************************************************\n\n";
        std::cout << "*                Enter 1 for Donor                  *\n\n";
        std::cout << "*               Enter 2 for Recipient               *\n\n";
        std::cout << "*****************************************************\n\n";

        int choice;

        std::cin >> choice;

        std::cout << "\n\n";

        switch (choice)
        {

        case 1:

            donorRegistration();
            initialMenu();

        case 2:

            recipientRegistration();
            initialMenu();

        default:
            break;
        }

    default:
        break;
    }



}

int main()
{

    introduction();
    initialMenu();

}