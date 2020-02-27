#ifndef FIL_H
#define FIL_H
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Show.h"
class FileEnDec {
    public:
        std::map<char, std::string> cipher;
        bool find_file(std::string name);
        bool access_file(std::string pass);
        void load_data(std::vector<Show> &data_list);
        void save_data(std::vector<Show> &data_list);
        FileEnDec();
        ~FileEnDec();

    private:
        std::fstream curr_file;
        std::string f_name;
        std::string f_pass;
};
#endif