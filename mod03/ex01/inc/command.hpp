#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct Article {
    std::string article;
    int units;
    float price;

    Article(const std::string& article, int units, float price) :
    article(article), units(units), price(price) {

    }
};

# define COMMAND_DATE_FORMAT "%Y-%m-%d"

class Command {

    public:

        Command(const std::string& client) : 
            _id(_unique_id++), _date(_get_current_date()), _client(client) {
                std::cout << "[COMMAND] - string constructor called\n";
                std::cout << *this;
        }

        Command(const std::string& client, struct tm* t) : 
            _id(_unique_id++), _date(t), _client(client) {
                std::cout << "[COMMAND] - string and date constructor called\n";
                std::cout << *this;
        }

        ~Command() {
            std::cout << "[COMMAND] - destructor called\n";
        }

        float get_total_price() const {
            std::vector<Article>::const_iterator cit;
            float total;

            cit = this->_articles.begin();
            total = 0;

            for (; cit != this->_articles.end(); cit++) {
                total += (*cit).price * (*cit).units;
            }
            return total;
        }

        void add_article(const std::string& article, int units, float price) {
            Article new_article(article, units, price);

            this->_articles.push_back(new_article);
        }

        struct tm* _get_current_date() {
            time_t t;
            struct tm* now;

            t = time(0);
            now = localtime(&t);
            return now;
        }

        friend std::ostream& operator << (std::ostream& os, const Command& c) {
            char buff[11];

            strftime(buff, sizeof(buff), COMMAND_DATE_FORMAT, c._date);
            os << "[COMMAND]:";
            os << "\n   + client name: " << c._client;
            os << "\n   + total price: " << c.get_total_price();
            os << "\n   + current date: " << buff << std::endl;

            return os;
        }

    protected:
        static int _unique_id;
        int _id;
        struct tm* _date;
        std::string _client;
        std::vector<Article> _articles;

        Command() {};
};

int Command::_unique_id = 0;