#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include <stdexcept>

enum MODE {
    DATABASE,
    INPUT
};
class BitcoinExchange
{
	private:
		std::map<std::string, float>	database;
		std::string	oldest_date;
		std::string newest_date;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange & operator=(const BitcoinExchange& obj);
		~BitcoinExchange();

		void load_database();
		void main_routine(char *argv);
		void print_result(std::string date, float value);
		void checkLine(std::string line, MODE type);
		bool checkValue(std::string value, MODE type);
		bool checkDate(std::string date, MODE type);
		class GradeTooHighException : public std::exception {
		  public :
				virtual const char* what() const throw()
				{ return "test" ;}
		};
		class DatabaseException : public std::exception {
		  public :
				virtual const char* what() const throw()
				{return "Error: database format is invalid";}
		};
		class BadFileException : public std::exception {
		  public :
				virtual const char* what() const throw()
				{return "Error : can't open file";}
		};
		class BadInputException : public std::exception {
		  public :
				virtual const char* what() const throw()
				{ return "Error: bad input" ;}
		};

		class CustomException : public std::exception {
        public:
            CustomException(std::string value) : error_message(value) {
                return ; }
            virtual ~CustomException(void) throw() {};
            virtual const char *what() const throw() {
                return (error_message.c_str());
            }
        private:
            std::string error_message;
    };


};


#endif
