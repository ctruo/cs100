#ifndef __SELECT_NOT_TEST_HPP
#define __SELECT_NOT_TEST_HPP

#include "gtest/gtest.h"

#include "select.hpp"
#include "spreadsheet.hpp"

TEST(Select_Not_Test, DoesntContainString) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* select = new Select_Not(new Select_Contains(&sheet, "Last", "drews"));

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 1);
}

TEST(Select_Not_Test, DoesContainString) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* select = new Select_Not(new Select_Contains(&sheet, "Last", "drews"));

    bool selectBool = select->select(&sheet, 0);
    EXPECT_EQ(selectBool, 0);
}

TEST(Select_Not_Test, DoesntContainEmptyString) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* select = new Select_Not(new Select_Contains(&sheet, "Last", ""));

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 0);
}

TEST(Select_Not_Test, DoesntContainStringOr) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* select = new Select_Not(new Select_Or(new Select_Contains(&sheet, "Last", "drews"), new Select_Contains(&sheet, "First", "Bri")));

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 0);
}

TEST(Select_Not_Test, DoesntContainStringAnd) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* select = new Select_Not(new Select_And(new Select_Contains(&sheet, "Last", "drews"), new Select_Contains(&sheet, "First", "Bri")));

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 1);
}

TEST(Select_Not_Test, DoesntContainStringNot) {
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* select = new Select_Not(new Select_Not(new Select_Contains(&sheet, "Last", "drews")));

    bool selectBool = select->select(&sheet, 1);
    EXPECT_EQ(selectBool, 0);
}

#endif
