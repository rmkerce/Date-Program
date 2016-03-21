#include "date.h"

using namespace std;

//*********************************************************************************************
//*********************************************************************************************
//	D A T E  . C P P


//This stub (for now) should be implemented in date.cpp
//*************************************************************************************
//Name: Ryan K  Date: 1/21/16
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to today's date
//Description:  This is the default constructor which will be called automatically when 
//an object is declared.  It will initialize the state of the class.
//
//*************************************************************************************
Date::Date()

	: myMonth (01), myDay(01), myYear(0001)

{

	cout << "The default constructor has been called" << endl;
	cout << setfill('0') << setw(2) << myMonth << "/" << setfill('0') << setw(2) << myDay << "/" << setfill('0') << setw(4) << myYear << endl<<endl;
	//the code for the default constructor goes here, can output easier or harder


}


//*************************************************************************************
//Name: Ryan K  Date: 1/21/16
//Precondition: State of the object has not beeen initialized
//Postcondition: State of the object has been initialized to a specific value 
//Description:  Explicit value constructor is called whenever you explicitly declare a specific value. The function 
// designates a restriction to follow based on the values passed in as arguments.
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "The explicit-value constructor has been called" <<endl;
	// Check class invariant
	if (y >= 0001 && y <= 9999)
	{

		if(m == 1 || m == 3 || m == 5|| m == 7 || m == 8 || m == 10 || m == 12)
		{
			if(d == 31)
			{
				myMonth = m;
				myDay = d;
				myYear = y;

				cout << endl << myMonth << "/" << myDay << "/" << myYear << endl << endl;
				cout << "Your month has 31 days." << endl << endl;

				if (y % 4 == 0 && y != 0)
				cout << myYear << " is a leap year." << endl << endl;
			}
		}


		if(m == 4 || m == 6 || m == 9 || m == 11)
		{
			if(d == 30)
			{
				myMonth = m;
				myDay = d;
				myYear = y;

				cout << endl << myMonth << "/" << myDay << "/" << myYear << endl << endl;
				cout << "Your month has 30 days." << endl << endl;

				if (y % 4 == 0 && y != 0)
				cout << myYear << " is a leap year." << endl << endl;
			}
		}


		if(m == 2)
		{
			if (y % 4 == 0 && y != 0 && d != 30)
			{
				cout<<"Your month has 29 days, because it is a leap year."<< endl << endl;
				myMonth = m;
				myDay = d;
				myYear = y;

				cout << endl << myMonth << "/" << myDay << "/" << myYear << endl << endl;
			}
			else if(d == 28)
			{
				myMonth = m;
				myDay = d;
				myYear = y;

				cout << endl << myMonth << "/" << myDay << "/" << myYear << endl << endl;
			}
		}
	}


	else
		cerr << "*** Invalid initial arguments ***\n\n";

	if (m < 1 || m > 12)
		cout << "Month = " << m << " is incorrect" << endl << endl;
	if ( m == 2 && d > 29)
		cout << "February doesn't have 30 days!" << endl << endl;
	if (d < 1 || d > 32)
		cout << "Day = " << d << " is incorrect" << endl << endl;

	if (y < 0001 || y > 9999)
		cout << "Year = " << setfill('0') << setw(4) << y << " is incorrect" << endl << endl;



}

//*************************************************************************************
//Name: Display
//Precondition: Data is not displayed
//Postcondition: Displays data containing the month, day, and year.
//Description:  Called whenever the arguments need to printed to the screen.
//
//
//*************************************************************************************
void Date::display()
{

	cout << myMonth << '/' << myDay << '/' << myYear << endl;

}

//*************************************************************************************
//Name: getMonth
//Precondition: Information for month has not been initialized.
//Postcondition: Gets and returns data for month.
//Description:  Called whenever you need to get and return the data for the month.
//
//
//*************************************************************************************	
int Date::getMonth()
{
	

	return myMonth;

}

//*************************************************************************************
//Name: getDay
//Precondition: Information for month is not currently available.
//Postcondition: Data for day is retrieved
//Description:  Called whenever you need to get the day-ta. Get it?
//
//
//*************************************************************************************
int Date::getDay()
{
	
	return myDay;

}

//*************************************************************************************
//Name: getYear
//Precondition: Information for year is not currently available.
//Postcondition: Data for the day is retrieved
//Description:  Called whenever you need to get the year data.
//
//
//*************************************************************************************
int Date::getYear()
{

	return myYear;

}

//*************************************************************************************
//Name: setMonth
//Precondition: Information for month is not currently set.
//Postcondition: Sets the data for the month.
//Description:  Called whenever an explicit value for the month needs to be set
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{

	if (myMonth >= 1 && myMonth <= 12)
	{
		myMonth = m; 
	}

	else
		cerr << "*** Can't set month with these values ***\n";
	// Object's data members remain unchanged

}

//*************************************************************************************
//Name:  setDay
//Precondition: Information for day is not currently set.
//Postcondition: Set the data for day to a specific value
//Description:  Called whenever you need to set the day
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	if (myDay >= 1 && myDay <= 31)
	{
		myDay = d;
	}

	else
		cerr << "*** Can't set the day with these values ***\n";
	// Object's data members remain unchanged
}

//*************************************************************************************
//Name:  getYear
//Precondition: Information for year is not currently set.
//Postcondition: Sets year to a specific data value
//Description:  Called whenever you need to set the year.
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{

	if (myYear >= 0001 && myYear <= 9999)
	{
		myYear = y;
	}

	else
		cerr << "*** Can't set the year with these values ***\n";
	// Object's data members remain unchanged


}

ostream & operator<<(ostream & out, const Date & dateObj)
{
	out << dateObj.myMonth << '/' << dateObj.myDay << '/' << dateObj.myYear;

	return out;

}
