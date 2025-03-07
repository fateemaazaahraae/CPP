# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

int main()
{
    Base* p = generate();
    identify(p);
    identify(*p);
}