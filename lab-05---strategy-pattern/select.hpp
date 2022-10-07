#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <cstring>
#include <iostream>
class Select
{
public:
    virtual ~Select() = default;

    // Return true if the specified row should be selected.
    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

// A common type of criterion for selection is to perform a comparison based on
// the contents of one column.  This class contains contains the logic needed
// for dealing with columns. Note that this class is also an abstract base
// class, derived from Select.  It introduces a new select function (taking just
// a string) and implements the original interface in terms of this.  Derived
// classes need only implement the new select function.  You may choose to
// derive from Select or Select_Column at your convenience.
class Select_Column: public Select
{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* sheet, const std::string& name)
    {
        column = sheet->get_column_by_name(name);
    }

    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        return select(sheet->cell_data(row, column));
    }

    // Derived classes can instead implement this simpler interface.
    virtual bool select(const std::string& s) const = 0;
};

class Select_Contains: public Select_Column 
{
   private:
   std::string criteria;
   const Spreadsheet* spreadsheet;
   std::string columnPosition;
   
   public:
   Select_Contains(const Spreadsheet* sheet, const std::string& columnPos, const std::string& criteria) : Select_Column(sheet, columnPos)
   {
    this->criteria = criteria;
    spreadsheet = sheet;
    columnPosition = columnPos;
   } 
 
   ~Select_Contains() {
     //  delete spreadsheet;
   }

   bool select(const std::string& s) const {
      if (s.find(criteria) != std::string::npos) {
	   return 1;
	}
      return 0;
    }

};


class Select_And: public Select
{

    private:
	const Select* select1;
	const Select* select2;

    public:
	Select_And(const Select* select1, const Select* select2): Select()
	{
	    this->select1 = select1;
	    this->select2 = select2;
	}

	~Select_And()
	{
	    delete select1;
	    delete select2;
	}

	bool select(const Spreadsheet* sheet, int row) const {
	    if(select1->select(sheet, row) && select2->select(sheet, row)){
		return true;
	    }else{
		return false;
	    }	    
	}

};

class Select_Not: public Select
{
	private: 
	   const Select* selectPtr;
	public:
	   Select_Not(const Select* selection)
 	   {
            selectPtr = selection;	  	
  	   }

	   ~Select_Not()
	   {
	     delete selectPtr;
	   }

	   bool select(const Spreadsheet* sheet, int row) const {
	      if (!selectPtr->select(sheet, row)) {
	         return true;	
	      }
	      return false;
	   }
};

class Select_Or: public Select
{
    private:
	const Select* select1;
	const Select* select2;

    public:
	Select_Or(const Select* select1, const Select* select2): Select()
        {
            this->select1 = select1;
            this->select2 = select2;
        }

        ~Select_Or()
        {
            delete select1;
            delete select2;
        }
	
	bool select(const Spreadsheet* sheet, int row) const {
            if(select1->select(sheet, row) || select2->select(sheet, row)){
                return true;
            }else{
                return false;
            }
        }

};


#endif //__SELECT_HPP__
