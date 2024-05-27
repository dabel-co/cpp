#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : database()
{
    load_database();
    oldest_date = database.begin()->first;
    newest_date = database.rbegin()->first;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    (void) obj;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    (void) obj;
	return *this;
}

bool BitcoinExchange::checkDate(std::string date, MODE type) {
    if (date.length() != 10)
        return (false);
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return (false);
        } else if (!std::isdigit(date[i]))
            return (false);
    }
    if (type == INPUT && date < oldest_date)
        return (false);
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (month == 2 && day > 29))
        return (false);
    return (true);
}

bool BitcoinExchange::checkValue(std::string value, MODE type) {
    bool dot = false;

    for (size_t i = 0; i < value.length(); i++) {
        if (value[i] == '.') {
            if (dot)
                return (false);
            dot = true;
        }
        else if (!std::isdigit(value[i]))
            return (false);
    }
    if (type == INPUT && (std::atof(value.c_str()) > 1000 || std::atof(value.c_str()) < 0))
        return (false);
    return (true);
}
void BitcoinExchange::checkLine(std::string line, MODE type) {
    char    delimiter = type == DATABASE ? ',' : '|';

    int delimiter_count = std::count(line.begin(), line.end(), delimiter);
    if (delimiter_count != 1)
        throw BadInputException();
    std::string date = line.substr(0, line.find(delimiter));
    std::string value = line.substr(line.find(delimiter) + 1);
    date.erase(remove_if(date.begin(), date.end(), isspace), date.end());
    value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
    if (!date.length() || !value.length())
        throw BadInputException();
    else if (!checkDate(date, type))
        throw CustomException("Bad date => " + date);
    else if (!checkValue(value, type)) {
        if (std::atof(value.c_str()) < 0)
            throw CustomException("not a positive number.");
        else if (std::atof(value.c_str()) > 1000)
            throw CustomException("too large a number.");
        else
            throw CustomException("illegal value => " + value);
    }
    return ;
}
void    BitcoinExchange::load_database()
{
    std::ifstream file("./data.csv");
    std::string line;
    std::string date;
    std::string value;
    float       fvalue;

    if (!file.is_open())
        throw BadFileException();
    std::getline(file, line);
    while (std::getline(file, line)) {
        try {
            checkLine(line, DATABASE);
        }
        catch (std::exception &e) {
            throw DatabaseException();
        }
        date = line.substr(0, line.find(','));
        value = line.substr(line.find(',') + 1);
        fvalue = std::atof(value.c_str());
        database[date] = fvalue;
    }
    file.close();
    return ;
}
void    BitcoinExchange::print_result(std::string date, float value)
{
    std::map<std::string, float>::iterator it = database.find(date);
    std::string last_date;
    float last_value;
    for (it = database.begin(); it != database.end(); it++) {
            if (it->first > date)
                break ;
            last_date = it->first;
            last_value = it->second;
        }
        std::cout << date << " => " << value << " = " << value * last_value << std::endl;
}
void    BitcoinExchange::main_routine(char *argv)
{
    std::ifstream file(argv);
    std::string line;
    std::string date;
    std::string value;
    float       fvalue;

    if (!file.is_open())
        throw BadFileException();
    std::getline(file, line);
    while (std::getline(file, line))
    {
        try {
            checkLine(line, INPUT);
        }
        catch (std::exception &e) {
            std::cout << "Error : " << e.what() << std::endl;
            continue;
        }
        date = line.substr(0, line.find('|'));
        value = line.substr(line.find('|') + 1);
        fvalue = std::atof(value.c_str());
        print_result(date, fvalue);
    }
    file.close();
    return ;
}
