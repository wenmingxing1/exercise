#include "message_folder.h"

int main()
{
    Message firstMail("Hello");
    Message signInMail("Welcome to cppprimer");
    Folder mailBox;

    firstMail.print_debug();
    firstMail.save(mailBox);
    mailBox.print_debug();

    signInMail.print_debug();
    signInMail.save(mailBox);
    mailBox.print_debug();

    firstMail = firstMail;  //×Ô¸³Öµ
    firstMail.print_debug();
    mailBox.print_debug();

    return 0;
}
