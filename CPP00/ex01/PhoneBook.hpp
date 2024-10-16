#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int index;

    public:
        PhoneBook() : index(0) {}
        void    AddContact(Contact& element);
        void    SearchContact();

        int     GetIndex() const;
        Contact GetContact(int i) const;

        void    SetContact(int i, Contact& NewUser);
        void    SetIndex(int i);
};

#endif