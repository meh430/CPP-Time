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

FileEnDec::FileEnDec() {
    cipher.insert({'0', "asfq"});
    cipher.insert({'1', "dgwg"});
    cipher.insert({'2', "erht"});
    cipher.insert({'3', "ascf"});
    cipher.insert({'4', "kuym"});
    cipher.insert({'5', "kuyv"});
    cipher.insert({'6', "zxvv"});
    cipher.insert({'7', "bdwf"});
    cipher.insert({'8', "ksfg"});
    cipher.insert({'9', "afgr"});
    cipher.insert({'a', "ayjv"});
    cipher.insert({'b', "kuyt"});
    cipher.insert({'c', "wege"});
    cipher.insert({'d', "trjr"});
    cipher.insert({'e', "mhxc"});
    cipher.insert({'f', "cwed"});
    cipher.insert({'g', "bfsx"});
    cipher.insert({'h', "dfsf"});
    cipher.insert({'i', "fgvc"});
    cipher.insert({'g', "tjsx"});
    cipher.insert({'k', "utrx"});
    cipher.insert({'l', "cyug"});
    cipher.insert({'m', "cjyj"});
    cipher.insert({'n', "acca"});
    cipher.insert({'o', "cytv"});
    cipher.insert({'p', "cohg"});
    cipher.insert({'q', "casr"});
    cipher.insert({'r', "cast"});
    cipher.insert({'s', "rasd"});
    cipher.insert({'t', "rasc"});
    cipher.insert({'u', "egcc"});
    cipher.insert({'v', "forl"});
    cipher.insert({'w', "lorn"});
    cipher.insert({'x', "asca"});
    cipher.insert({'y', "lass"});
    cipher.insert({'z', "fass"});
    cipher.insert({'A', "foss"});
    cipher.insert({'B', "efcx"});
    cipher.insert({'C', "caew"});
    cipher.insert({'D', "bruh"});
    cipher.insert({'E', "moni"});
    cipher.insert({'F', "iums"});
    cipher.insert({'G', "mygo"});
    cipher.insert({'H', "ddam"});
    cipher.insert({'I', "gast"});
    cipher.insert({'G', "afsa"});
    cipher.insert({'K', "cktf"});
    cipher.insert({'L', "ruhf"});
    cipher.insert({'M', "eruh"});
    cipher.insert({'N', "wygv"});
    cipher.insert({'O', "dvbh"});
    cipher.insert({'P', "kyhg"});
    cipher.insert({'Q', "cyrb"});
    cipher.insert({'R', "xbxv"});
    cipher.insert({'S', "vvvv"});
    cipher.insert({'T', "qadd"});
    cipher.insert({'U', "bdxx"});
    cipher.insert({'V', "xxxx"});
    cipher.insert({'W', "qdsa"});
    cipher.insert({'X', "tuty"});
    cipher.insert({'Y', "turd"});
    cipher.insert({'Z', "czvc"});
}
