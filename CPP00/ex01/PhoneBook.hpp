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
        void    SetIndex(const int i);
};

#endif