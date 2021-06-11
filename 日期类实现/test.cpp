#include <iostream>
using namespace std;
class Date
{
public:
	bool CheckLeap(int year);
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);
	// ��ӡ������
	void PrintYearMonthDay()
	{
		printf("%d.%d.%d\n", _year, _month, _day);
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1);

	// �������캯��
	Date(const Date& d);

	// ��ֵ���������
	Date& operator=(const Date& d);

	// ��������
	~Date();

	// ����+=����
	Date& operator+=(int day);

	// ����+����
	Date operator+(int day);

	// ����-����
	Date operator-(int day);

	// ����-=����
	Date& operator-=(int day);

	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);

	// ����--
	Date operator--(int);

	// ǰ��--
	Date& operator--();

	// >���������
	bool operator>(const Date& d);

	// ==���������
	bool operator==(const Date& d);

	// >=���������
	inline bool operator >= (const Date& d);

	// <���������
	bool operator < (const Date& d);

	// <=���������
	bool operator <= (const Date& d);

	// !=���������
	bool operator != (const Date& d);

	// ����-���� ��������
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
// ��ȡĳ��ĳ�µ�����
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

// ȫȱʡ�Ĺ��캯��
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

// �������캯��
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}


// ��ֵ���������
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

// ��������
Date::~Date()
{
	
}

// ����+=����
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

// ����+����
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

// ����-����
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

// ����-=����
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

// ǰ��++
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

// ����++
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

// ����--
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

// ǰ��--
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

// >���������
bool Date::operator>(const Date& d)
{
	if (_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day <= d._day))
		return false;
	return true;
}

// ==���������
bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	return false;
}

// >=���������
inline bool Date::operator >= (const Date& d)
{
	if (_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day))
		return false;
	return true;
}

// <���������
bool Date::operator < (const Date& d)
{
	if (_year > d._year || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day >= d._day))
		return false;
	return true;
}

// <=���������
bool Date::operator <= (const Date& d)
{
	if (_year > d._year || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day > d._day))
		return false;
	return true;
}

// !=���������
bool Date::operator != (const Date& d)
{
	if (_year != d._year || _month != d._month || _day != d._day)
		return true;
	return false;
}

// ����-���� ��������
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