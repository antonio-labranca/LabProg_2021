#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct file_error {
    string message;
};

struct format_error {
    string message;
};

class Date {
    public:
        Date(int d, int m, int y) {
            year = y;
            month = m;
            day = d;
        }

        Date(string v) {
            istringstream s{v};
            int y, m, d;
            char delim1, delim2;

            s >> y >> delim1 >> m >> delim2 >> d;

            if(! s.eof())
                throw format_error{"String "+v+" is not a date"};
            if(delim1!='-' || delim2!='-')
                throw format_error{"String "+v+" is not a date"};
            if(y < 1900 || y > 2023)
                throw format_error{"String "+v+" is not a date"};
            if(m > 12 || m < 1)
                throw format_error{"String "+v+" is not a date"};
            if(d < 1 || d > 31)
                throw format_error{"String "+v+" is not a date"};
            year = y;
            month = m;
            day = d;
        }

    private:
        int day, month, year;
};

class Table {
    public:
        Table(string filepath) {
            ifstream file{filepath};

            if(file.good()) {
                string headers_row;
                getline(file, headers_row, '\n');
                headers = parse_line(headers_row);
            }
            else throw new file_error{"Unable to read properly "+filepath};
            data = vector<vector<string>>{headers.size()};
            while(file.good()) {
                string s;
                getline(file, s, '\n');
                vector<string> line_values = parse_line(s);
                for(int i = 0; i < line_values.size(); i++)
                    data.at(i).push_back(line_values.at(i));
            }
            if(! file.eof())
                throw new file_error{"Error while reading file "+filepath};

            for(int i = 0; i < data.size(); i++) {
                vector<string> v = data.at(i);
                if(isDate(v))
                    date_columns.push_back(transform_to_dates(v));
                /*else if(isNumerical(v))
                    numerical_columns.push_back(transform_to_numerical(v));
                else string_columns.push_back(v); */
            }
        }

    private:
        vector<string> headers;
        vector<vector<string>> data;

        vector<vector<Date>> date_columns;
        vector<vector<double>> numerical_columns;
        vector<vector<string>> string_columns;

        vector<string> parse_line(string row) {
                istringstream single_header{row};
                vector<string> result;
                string value;
                while(single_header.good()) {
                    getline(single_header, value, ',');
                    result.push_back(value);
                }
                return result;
        }

        bool isDate(vector<string> v) {
            string value = v.at(0);
            try {
                Date{value};
                return true;
            }
            catch(format_error e) {
                return false;
            }
        }

        vector<Date> transform_to_dates(vector<string> values) {
            vector<Date> result;
            for(string v : values)
                result.push_back(transform_value_to_date(v));
            return result;
        }
        Date transform_value_to_date(string v) {
            return Date{v};
        }

};

int main() {
    Table table{"/home/prog2021/labprog/LabProg_2021/Lezione17_CsvReader/somministrazioni-vaccini-summary-latest.csv"};    return 0;
}