#include <iostream>
#include <string>

int main()
{
    //Screen Number
    std::string opt;

    //Used to return to Selection Screen
    int ret = 0;

    //Is the account created?
    int isAcc = 0;

    //Screen Selection
    std::string contLog;

    //Self Explanitory
    std::string origusername, origpassword, confirmpassword;
    
    // Selection Screen
    while (ret == 0) {
        std::cout << "-----------------------------\n\n";
        std::cout << "What would you like to do?\n\n" << "01. Create Account\n" << "02. Login\n\n";
        std::cout << "Please select your option <1-2> "; std::cin >> opt;
        while (opt != "1" && opt != "2") {
            std::cout << "Please try again: "; std::cin >> opt;
        }

        // Creating An Account or Logging In
        if (opt == "1" || opt == "2") {

            // Creating Account
            if (opt == "1" && isAcc == 0) {

                std::cout << "\n-----------------------------\n\n" << "Create a Username and Password-\n\n";
                std::cout << "Username: "; std::cin >> origusername;
                while (origusername.length() < 8) {
                    std::cout << "Your username must be 8 characters or longer - Please try again: "; std::cin >> origusername;
                }
                std::cout << "Password: "; std::cin >> origpassword;
                while (origpassword.length() < 8) {
                    std::cout << "Your password must be 8 characters or longer - Please try again: "; std::cin >> origpassword;
                }
                while (origusername == origpassword) {
                    std::cout << "Your password cannot be the same as your username - Please try again: "; std::cin >> origpassword;
                }
                std::cout << "Confirm Password: "; std::cin >> confirmpassword;
                while (confirmpassword != origpassword) {
                    std::cout << "This does not match your origional password - Please try again: "; std::cin >> confirmpassword;
                }

                // Going to Login Screen or Selection Screen
                isAcc++;
                std::cout << "\n" << "Account Created --- Type and Enter 'L' to continue to Login Screen or 'S' for the Selection Screen | "; std::cin >> contLog;
                while (contLog != "L" && contLog != "S") {
                    std::cout << "Please try again: "; std::cin >> contLog;
                }
                if (contLog == "L") {
                    ret++;
                }
                else if (contLog == "S") {
                    std::cout << "\n";
                }
            }

            //Stops account from being overrided
            else if (opt == "1" && isAcc == 1) {
                std::cout << "\nYou have already created an account - Type and Enter 'L' to continue to Login Screen or 'S' for the Selection Screen | "; std::cin >> contLog;
                while (contLog != "L" && contLog != "S") {
                    std::cout << "Please try again: "; std::cin >> contLog;
                }
                if (contLog == "L") {
                    ret++;
                }
                else if (contLog == "S") {
                    std::cout << "\n";
                }
            }

            else {
                //Login Screen with No Account Made
                if (isAcc == 0) {
                    std::cout << "\n" << "You must first create an Account to Login.\n\n";
                    std::cout << "Type and Enter 'S' to return to the Selection Screen | "; std::cin >> contLog;
                    while (contLog != "S") {
                        std::cout << "Please try again: "; std::cin >> contLog;
                    }
                    if (contLog == "S") {
                        std::cout << "\n";
                    }
                }
                //Direct towards login screen with account made
                else if (isAcc == 1) {
                    ret++;
                    contLog = "L";
                }
            }
        }
    }

    //Login Screen
    std::string usernamecheck, passwordcheck;
    if (isAcc == 1 && contLog == "L") {
        std::cout << "\n-----------------------------";
        
        //Validating Username and Password
        std::cout << "\n\nLog Into Your Account-\n\n" << "Username: "; std::cin >> usernamecheck;
        while (origusername != usernamecheck) {
            std::cout << "\n" << "This does not match the created Username - Please try again: "; std::cin >> usernamecheck;
        }
        std::cout << "Password: "; std::cin >> passwordcheck;
        while (origpassword != passwordcheck) {
            std::cout << "\n" << "This does not match the created Password - Please try again: "; std::cin >> passwordcheck;
        }
        std::cout << "\n-----------------------------\n\nAccess Granted!\n";
    }
}
