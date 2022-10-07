#include "spreadsheet.hpp"
#include "select.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

    sheet.print_selection(std::cout);
    std::cout << std::endl;

    sheet.set_selection(new Select_Not(new Select_Or(new Select_Contains(&sheet, "Major", "computer"), new Select_Contains(&sheet, "Age", "21"))));
    sheet.print_selection(std::cout);  //No computer science/engineering majors and no 21 year olds
    std::cout << std::endl;

    
    sheet.set_selection(new Select_And(new Select_Contains(&sheet, "First", "Sarah"), new Select_And(new Select_Contains(&sheet, "Last", "Summers"), new Select_And(new Select_Contains(&sheet, "Age", "21"), new Select_Contains(&sheet, "Major", "computer science")))));
    sheet.print_selection(std::cout);  //Selecting specifically Sarah Summers only
    std::cout << std::endl;

    sheet.set_selection(new Select_Or(new Select_And(new Select_Contains(&sheet, "Age", "2"), new Select_Contains(&sheet, "First", "D")), new Select_Not(new Select_Contains(&sheet, "Age", "2"))));
    sheet.print_selection(std::cout);  //Over 20 with names starting with D, or George
    std::cout << std::endl;

    return 0;
}
