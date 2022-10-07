#ifndef __SELECT_AND_TEST_HPP__
#define __SELECT_AND_TEST_HPP__


#include "gtest/gtest.h"

#include "select.hpp"
#include "spreadsheet.hpp"

TEST(SelectAnd_Test, TwoContains){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    sheet.add_row({"Joe","Jackson","21","mathematics"});
    sheet.add_row({"Sarah","Summers","21","computer science"});
    sheet.add_row({"Diane","Dole","20","computer engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"David","Dole","22","electrical engineering"});
    sheet.add_row({"Dominick","Dole","22","communications"});
    sheet.add_row({"George","Genius","9","astrophysics"});

    Select* select = new Select_And(new Select_Contains(&sheet, "Last", "le"), new Select_Contains(&sheet, "First", "vid"));
    
    bool row6 = select->select(&sheet, 6);
    bool row7 = select->select(&sheet, 7);
    bool row8 = select->select(&sheet, 8);

    bool finalBoolean = (row6 && row7 && row8);

    //bool booleanVal = select->select(&sheet, 6);
    EXPECT_EQ(finalBoolean, true);

}

TEST(SelectAnd_Test, TwoContains_different_rows){
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

    Select* select = new Select_And(new Select_Contains(&sheet, "Last", "le"), new Select_Contains(&sheet, "First", "vid"));

    bool row0 = select->select(&sheet, 0);
    bool row1 = select->select(&sheet, 1);
    bool row2 = select->select(&sheet, 2);
    bool row3 = select->select(&sheet, 3);
    bool row4 = select->select(&sheet, 4);
    bool row5 = select->select(&sheet, 5);
    bool row7 = select->select(&sheet, 7);
    bool row8 = select->select(&sheet, 8);
    
    bool finalBoolean = (row0 || row1 || row2 || row3 || row4 || row5 || row7 || row8);
    EXPECT_EQ(finalBoolean, false);

}

TEST(SelectAnd_Test, TwoContains_empty_strings){
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

    Select* select = new Select_And(new Select_Contains(&sheet, "Last", ""), new Select_Contains(&sheet, "First", ""));

    bool row0 = select->select(&sheet, 0);
    bool row1 = select->select(&sheet, 1);
    bool row2 = select->select(&sheet, 2);
    bool row3 = select->select(&sheet, 3);
    bool row4 = select->select(&sheet, 4);
    bool row5 = select->select(&sheet, 5);
    bool row6 = select->select(&sheet, 6);
    bool row7 = select->select(&sheet, 7);
    bool row8 = select->select(&sheet, 8);

    bool finalBoolean = (row0 && row1 && row2 && row3 && row4 && row5 && row6 && row7 && row8);
    EXPECT_EQ(finalBoolean, true);

}

TEST(SelectAnd_Test, Contains_And){
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
    sheet.add_row({"","","",""});    

    Select* select = new Select_And(
	                 new Select_Contains(&sheet,"Age","21"),
       		         new Select_And(
            	             new Select_Contains(&sheet,"Major","science"),
		             new Select_Contains(&sheet,"First","h")));

    bool row4 = select->select(&sheet, 4);

    bool finalBoolean = (row4);
    EXPECT_EQ(finalBoolean, true);

}

TEST(SelectAnd_Test, Contains_Or){
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

    Select* select = new Select_And(
                         new Select_Contains(&sheet,"Last","Dole"),
                         new Select_Or(
                             new Select_Contains(&sheet,"Major","business"),
                             new Select_Contains(&sheet,"Age","22")));

    bool row6 = select->select(&sheet, 6);
    bool row7 = select->select(&sheet, 7);

    bool finalBoolean = (row6 && row7);
    EXPECT_EQ(finalBoolean, true);

}

TEST(SelectAnd_Test, Contains_Not){
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

    Select* select = new Select_And(
                         new Select_Contains(&sheet,"Age","21"),
                         new Select_Not(
                             new Select_Contains(&sheet,"Major","business")));

    bool row1 = select->select(&sheet, 1);
    bool row2 = select->select(&sheet, 2);
    bool row3 = select->select(&sheet, 3);
    bool row4 = select->select(&sheet, 4);

    bool finalBoolean = (row1 && row2 && row3 && row4);
    EXPECT_EQ(finalBoolean, true);

}



#endif
