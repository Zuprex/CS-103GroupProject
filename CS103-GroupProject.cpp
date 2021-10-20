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

int loginAttempts = 0;

// Global/Field Variables *****************************************************************

void donorMenu() {

    int choice;

    std::cout << "\n\nPlease select a choice by entering the coresponding number. ";
    std::cin >> choice;

    switch (choice)
    {

        // Procedure to donate blood:

    case 1:

        std::cout << "\nA blood donation can take up to 60 minutes (includes registration, donation and recovery).\n";
        std::cout << "The blood is collected in a sterile bag, and time on the bed can take about 5 to 10 minutes.\n";
        std::cout << "A unit of blood(around 470 ml) will be collected.The needle is then removed and a bandage is applied.\n";


        //Benefits of blood donations

    case 2:

        std::cout << "\nDonating blood has benefits for your emotional and physical health.\n";
        std::cout << "A 2017 studyTrusted Source suggests that regular blood donations are associated with increased risk of heart disease possibly due to unfavorable cholesterol levels\n";
        std::cout << "Blood donation is safe for healthy adults. There’s no risk of contracting disease. New, sterile equipment is used for each donor.\n";

    case 3:




    default:
        break;
    }

}

void resMenu() {



}

void adminMenu() {



}

// Introduction

void introduction() {

    std::cout << "\n\t    The Blood Bank of New Zealand\n\n";

    std::cout << "*****************************************************\n";
    std::cout << "*                      About Us:                    *\n";
    std::cout << "* We are a New Zealand organisation that is aimming *\n";
    std::cout << "* to help get people who are in need of blood. Any  *\n";
    std::cout << "* donations we recieve is given to people in need!  *\n";
    std::cout << "*                                                   *\n";
    std::cout << "*                     Contact                       *\n";
    std::cout << "*           Phone Number: 022 196 9532              *\n";
    std::cout << "*           Address: 68 Mohaka Street               *\n";
    std::cout << "*           Open: Saturdays - Sundays               *\n";
    std::cout << "*                                                   *\n";
    std::cout << "*****************************************************\n";

}

bool recipientLogin() {

    std::string username;
    std::string password;

    std::cout << "\nPlease enter your Username: ";
    std::cin >> username;

    std::cout << "\nPlease enter your Password: ";
    std::cin >> password;

    for (int i = 0; i < size; i++) {

        if (resList[i].username == username) {

            if (resList[i].password == password) {

                currentRes = resList[i];
                currentDonor = userDonor();
                recipientLogin();

            }

        }

    }

    loginAttempts++;

    if (loginAttempts >= 3) {

        std::cout << "\n\nToo many incorrect attempts. You have been returned to the Initial Menu ";
        loginAttempts = 0;
        return false;

    }
    else {

        recipientLogin();

    }

    return false;
}

bool donorLogin() {

    std::string username;
    std::string password;

    std::cout << "\nPlease enter your Username: ";
    std::cin >> username;

    std::cout << "\nPlease enter your Password: ";
    std::cin >> password;


    for (int i = 0; i < size; i++) {

        if (donorList[i].username == username) {

            if (donorList[i].password == password) {

                currentDonor = donorList[i];
                currentRes = userRes();
                donorMenu();

            }


        }

    }

    loginAttempts++;

    if (loginAttempts >= 3) {

        std::cout << "\n\nToo many incorrect attempts. You have been returned to the Initial Menu ";
        loginAttempts = 0;
        return false;

    }
    else {

        donorLogin();

    }

    return false;

}

bool adminLogin() {

    return false;

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

    userRes newUser = userRes(recipient, physAddress, email, contactNum, validationStatus, username, password);

    resList[registeredRes] = newUser;

    registeredRes++;

}


// First Choice for user

void initialMenu() {

    std::cout << "\n\n";

    std::cout << "*****************************************************\n\n";
    std::cout << "*                     Menu                          *\n\n";
    std::cout << "*                Enter 1 to Login                   *\n\n";
    std::cout << "*               Enter 2 to Register                 *\n\n";
    std::cout << "*****************************************************\n\n";

    int firstChoice;

    std::cin >> firstChoice;

    std::cout << std::endl;

    switch (firstChoice)
    {

    case 1: // Login

        std::cout << "\n\t    Please Select your user type\n\n";

        std::cout << "*****************************************************\n";
        std::cout << "*                  1.)Recipient                     *\n";
        std::cout << "*                  2.)Donor                         *\n";
        std::cout << "*                  3.)AdminRecipient                *\n";
        std::cout << "*****************************************************\n";

        int loginTypeChoice;

        std::cin >> loginTypeChoice;

        switch (loginTypeChoice)
        {

        case 1:

            if (recipientLogin() == true) {

                resMenu();

            }
            else {

                initialMenu();

            }

        case 2:

            if (donorLogin() == true) {

                donorMenu();

            }
            else {

                initialMenu();

            }

        case 3:

            if (adminLogin() == true) {

                adminMenu();

            }
            else {

                initialMenu();

            }

        default:
            break;
        }

        // Registration
    case 2:

        std::cout << "\n";

        std::cout << "           Are you a Donor or Recipient?\n";
        std::cout << "*****************************************************\n\n";
        std::cout << "*                Enter 1 for Donor                  *\n\n";
        std::cout << "*               Enter 2 for Recipient               *\n\n";
        std::cout << "*****************************************************\n\n";

        int registrationTypeChoice;

        std::cin >> registrationTypeChoice;

        std::cout << "\n\n";

        switch (registrationTypeChoice)
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