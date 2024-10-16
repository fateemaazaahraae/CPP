#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        //getters
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetNickName() const;
        std::string GetPhoneNumber() const;
        std::string GetDarkestSecret() const;

        //setters
        void        SetFirstName(std::string& First);
        void        SetLastName(std::string& Last);
        void        SetNickName(std::string& Nick);
        void        SetPhoneNumber(std::string& Number);
        void        SetDarkestSecret(std::string& Dark);
};

void    GetInputFirstName(Contact& NewUser);
void    GetInputLastName(Contact& NewUser);
void    GetInputNickName(Contact& NewUser);
void    GetInputPhoneNumber(Contact& NewUser);
void    GetInputDarkestSecret(Contact& NewUser);


#endif