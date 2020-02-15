#include "FileEnDec.h"
#include <iostream>
#include <sstream> 
bool FileEnDec::find_file(std::string name) {
    std::string dec;
    for(char &c : name) {
        dec.append(this->cipher.at(c));
    }
    dec.append(".txt");
    this->curr_file.open(dec);
    if(this->curr_file.is_open()) {
        this->f_name = dec;
        this->curr_file.close();
        return true;
    } else {
        std::cout << "Error opening file, enter name properly or create new entry\n";
        this->curr_file.close();
        return false;
    }
}

bool FileEnDec::access_file(std::string pass) {
    std::string file_key;
    std::getline(this->curr_file, file_key);
    std::string dec;
    for(char &c : pass) {
        dec.append(this->cipher.at(c));
    }
    if(dec == file_key) {
        this->curr_file.close();
        this->f_pass = dec;
        return true;
    } else {
        std::cout << "Error opening file, enter key properly\n";
        this->curr_file.close();
        return false;
    }
}

void FileEnDec::load_data(std::vector<Show> &data_list) {
    std::string line;
    std::stringstream stream;
    this->curr_file.open(this->f_name);
    data_list.clear();

    while(getline(this->curr_file, line)) {
        getline(this->curr_file, line);
        Show show(line);
        getline(this->curr_file, line);
        stream << line;
        double rating = 0;
        stream >> rating;
        show.set_rating(rating);
        getline(this->curr_file, line);
        stream << line;
        int ep = 0;
        stream >> ep;
        show.set_ep_watched(ep);
        getline(this->curr_file, line);
        stream << line;
        int rank = 0;
        stream >> rank;
        show.set_rank(rank);
        getline(this->curr_file, line);
        show.set_fav_char(line);
        getline(this->curr_file, line);
        stream << line;
        int char_rank = 0;
        stream >> char_rank;
        show.set_char_rank(char_rank);
        data_list.push_back(show);
    }
}

void FileEnDec::save_data(std::vector<Show> &data_list) {
    std::ofstream ofs;
    ofs.open(this->f_name, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    this->curr_file.open(this->f_name);
    this->curr_file << this->f_pass;
    for(auto &val : data_list) {
        std::cout << val.get_show_name() << "\n";
        std::cout << val.get_rating() << "\n";
        std::cout << val.get_ep_watched() << "\n";
        std::cout << val.get_rank() << "\n";
        std::cout << val.get_fav_char() << "\n";
        std::cout << val.get_char_rank() << "\n";
        std::cout << "\n";
    }
}
