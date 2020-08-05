#include <iostream>
#include <memory>

class Date{
private:
    unsigned m_day;
    unsigned m_mounth;
    unsigned m_year;
public:
    Date() : m_day(1), m_mounth(1), m_year(1970) {};
    Date(unsigned d,
         unsigned m,
         unsigned y) : m_day(d), m_mounth(m), m_year(y) {};
    Date& set_day(const unsigned& d){ m_day = d; return *this;}
    Date& set_mounth(const unsigned& m){ m_mounth = m; return *this;}
    Date& set_year(const unsigned& y){ m_year = y; return *this;}
    unsigned get_day() const {return m_day;}
    unsigned get_mounth() const {return m_mounth;}
    unsigned get_year() const {return m_year;}
    friend std::ostream& operator<<(std::ostream& stream, const Date& date);
};

std::ostream& operator <<(std::ostream& stream, const Date& date){

    if (date.m_day < 10) {stream << "0" << date.m_day << "-";}
    else {stream << date.m_day << "-";}

    if (date.m_mounth < 10) {stream << "0" << date.m_mounth << "-";}
    else {stream << date.m_mounth << "-";}

    stream << date.m_year << std::endl;

    return stream;
}

Date& min_date(std::unique_ptr<Date> const& date1, std::unique_ptr<Date> const& date2) {
    if (date1->get_year() > date2->get_year()) {return *date1;}
    else if (date1->get_year() < date2->get_year()) {return *date2;}
    else{
        if (date1->get_mounth() > date2->get_mounth()) {return *date1;}
        else if (date1->get_mounth() < date2->get_mounth()) {return *date2;}
        else {
            if (date1->get_day() > date2->get_day()) {return *date1;}
            else if (date1->get_day() < date2->get_day()) {return *date2;}
        }
    }
    return *date1;
}

void swap_unique_ptr(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2){
    std::unique_ptr<Date> tmp;
    tmp = std::move(date1);
    date1 = std::move(date2);
    date2 = std::move(tmp);
}

int main()
{
    std::unique_ptr<Date> today = std::make_unique<Date>();
    std::unique_ptr<Date> date;

    today->set_day(2);
    today->set_mounth(8);
    today->set_year(2020);
    std::cout << "today: " << *today;

    date = std::move(today);

    if (!date) {std::cout << "day is a nullptr\n";}
    else { std::cout << "day is not a nullptr\n";}

    if (!today) {std::cout << "today is a nullptr\n";}
    else { std::cout << "today is `not a nullptr\n";}

    std::cout << "date: " << *date;

    ////////////////////////////////////////////////////////

    std::unique_ptr<Date> date1 = std::make_unique<Date>(2,8,2020);
    std::unique_ptr<Date> date2 = std::make_unique<Date>(1,7,2018);

    std::cout << min_date(date1, date2);

    ////////////////////////////////////////////////////////
    std::cout << "--Before swap functin usage--\n";
    std::cout << "date1: " << *date1;
    std::cout << "date2: " << *date2;

    swap_unique_ptr(date1, date2);
    std::cout << "--After swap functin usage--\n";
    std::cout << "date1: " << *date1;
    std::cout << "date2: " << *date2;

    return 0;
}
