#include <iostream>
using namespace std;
class Date
{
public:
	bool CheckLeap(int year);
	// 获取某年某月的天数
	int GetMonthDay(int year, int month);
	// 打印年月日
	void PrintYearMonthDay()
	{
		printf("%d.%d.%d\n", _year, _month, _day);
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1);

	// 拷贝构造函数
	Date(const Date& d);

	// 赋值运算符重载
	Date& operator=(const Date& d);

	// 析构函数
	~Date();

	// 日期+=天数
	Date& operator+=(int day);

	// 日期+天数
	Date operator+(int day);

	// 日期-天数
	Date operator-(int day);

	// 日期-=天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);

	// 后置--
	Date operator--(int);

	// 前置--
	Date& operator--();

	// >运算符重载
	bool operator>(const Date& d);

	// ==运算符重载
	bool operator==(const Date& d);

	// >=运算符重载
	inline bool operator >= (const Date& d);

	// <运算符重载
	bool operator < (const Date& d);

	// <=运算符重载
	bool operator <= (const Date& d);

	// !=运算符重载
	bool operator != (const Date& d);

	// 日期-日期 返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
bool Date::CheckLeap(int year)
{
	if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
		return true;
	return false;
}
// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	if (1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month)
		return 31;
	else if (2 == month)
	{
		if (CheckLeap(year))
			return 29;
		else
			return 28;
	}
	else
		return 30;
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

// 拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}


// 赋值运算符重载
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// 析构函数
Date::~Date()
{
	
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month++);
		if (_month > 12)
		{
			_year += _month / 12;
			_month %= 12;
		}
	}
	return *this;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date temp(*this);
	temp._day += day;
	while (temp._day > GetMonthDay(temp._year, temp._month))
	{
		temp._day -= GetMonthDay(temp._year, temp._month++);
		if (temp._month > 12)
		{
			temp._year += temp._month / 12;
			temp._month %= 12;
		}
	}
	return temp;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date temp(*this);
	temp._day -= day;
	while (temp._day <= 0)
	{
		if (1 == temp._month)
		{
			temp._year = temp._year - 1;
			temp._month = temp._month + 12;
		}
		temp._month = temp._month - 1;
		temp._day = temp._day + GetMonthDay(temp._year, temp._month + 1);
	}
	return temp;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		if (1 == _month)
		{
			_year = _year - 1;
			_month = _month + 12;
		}
		_month = _month - 1;
		_day = _day + GetMonthDay(_year, _month + 1);
	}
	return *this;
}

// 前置++
Date& Date::operator++()
{
	int carry = 0;
	_day += 1;
	carry = _day / GetMonthDay(_year, _month);
	if (carry > 0)
	{
		_day %= GetMonthDay(_year, _month);
		_month += carry;
		carry = _month / 12;
		if (carry > 0)
		{
			_month %= 12;
			_year += carry;
		}
	}
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date temp(*this);
	int carry = 0;
	_day += 1;
	carry = _day / GetMonthDay(_year, _month);
	if (carry > 0)
	{
		_day %= GetMonthDay(_year, _month);
		_month += carry;
		carry = _month / 12;
		if (carry > 0)
		{
			_month %= 12;
			_year += carry;
		}
	}
	return temp;
}

// 后置--
Date Date::operator--(int)
{
	Date temp(*this);
	if (1 == _day)
	{
		if (1 == _month)
		{
			_year = _year - 1;
			_month = _month + 12;
		}
		_month = _month - 1;
		_day = _day + GetMonthDay(_year, _month + 1);
	}
	_day = _day - 1;
	return temp;
}

// 前置--
Date& Date::operator--()
{
	if (1 == _day)
	{
		if (1 == _month)
		{
			_year = _year - 1;
			_month = _month + 12;
		}
		_month = _month - 1;
		_day = _day + GetMonthDay(_year, _month + 1);
	}
	_day = _day - 1;
	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if (_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day <= d._day))
		return false;
	return true;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	return false;
}

// >=运算符重载
inline bool Date::operator >= (const Date& d)
{
	if (_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day))
		return false;
	return true;
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	if (_year > d._year || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day >= d._day))
		return false;
	return true;
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	if (_year > d._year || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day > d._day))
		return false;
	return true;
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	if (_year != d._year || _month != d._month || _day != d._day)
		return true;
	return false;
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	int s1 = 0;
	int s2 = 0;
	for (int i = 0; i < _year; i++)
	{
		if (CheckLeap(i))
			s1++;
	}
	for (int i = 0; i < _month; i++)
	{
		s1 += GetMonthDay(_year, i);
	}
	s1 += _day + _year * 365;
	for (int i = 0; i < d._year; i++)
	{
		if (CheckLeap(i))
			s2++;
	}
	for (int i = 0; i < d._month; i++)
	{
		s2 += GetMonthDay(d._year, i);
	}
	s2 += d._day + d._year * 365;
	return (s1 - s2 > 0) ? s1 - s2 + 1 : s2 - s1 + 1;
}

int main()
{
	Date a(2021, 1, 1);
	a.PrintYearMonthDay();
	++a;
	a.PrintYearMonthDay();
	a++;
	a.PrintYearMonthDay();
	--a;
	a.PrintYearMonthDay();
	a--;
	a.PrintYearMonthDay();
	return 0;
}