#ifndef __SELECT_CONTAINS_TEST_HPP
#define __SELECT_CONTAINS_TEST_HPP

#include "gtest/gtest.h"

#include "spreadsheet.hpp"
#include "select.hpp"
//#include "spreadsheet.cpp"

TEST(selectTest, ContainsString) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    
    Select* select = new Select_Contains(&sheet, "Last", "drews");	

    bool selectBool = select->select(&sheet, 0);
    EXPECT_EQ(selectBool, 1);
}

TEST(selectTest, DoesNotContainString) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});

    Select* select = new Select_Contains(&sheet, "Last", "drews");

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 0);
}

TEST(selectTest, DoesNotContainStringCapitalized) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","AnDREWS","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});

    Select* select = new Select_Contains(&sheet, "Last", "drews");

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 0);
}

TEST(selectTest, MatchesEmptyString) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","AnDREWS","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});

    Select* select = new Select_Contains(&sheet, "Last", "");

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 1);
}

TEST(selectTest, EmptyStringInSpreadsheetMatches) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});

    Select* select = new Select_Contains(&sheet, "Last", "cat");

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 0);
}
#endif
