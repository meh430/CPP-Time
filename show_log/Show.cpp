#include "Show.h"
#include <algorithm>
Show::Show(std::string name) : show_name(name) {}

void Show::set_fav_char(std::string char_name) {
    this->fav_char = char_name;
}

void Show::set_char_rank(int r, std::vector<Show> &data_list) {
    this->char_rank = r;
    std::sort(data_list.begin(), data_list.end(), [](const Show &ls, const Show &rs) { return ls.char_rank < rs.char_rank; });
    for (int i = 0; i < data_list.size(); i++) {
        if(data_list.at(i).char_rank == r) {
            this->char_rank = i;
        }
    }
}

void Show::set_char_rank(int r) {
    this->char_rank = r;
}

void Show::set_rank(int r, std::vector<Show> &data_list) {
    this->rank = r;

    std::sort(data_list.begin(), data_list.end(), [](const Show &ls, const Show &rs) { return ls.rank < rs.rank; });
    for (int i = 0; i < data_list.size(); i++) {
        if(data_list.at(i).rank == r) {
            this->rank = i;
        }
    }
}

void Show::set_rank(int r) {
    this->rank = r;
}

void Show::set_ep_watched(int e) {
    this->ep_watched = e;
}

void Show::set_rating(int r) {
    this->rating = r;
}

int Show::get_char_rank() {
    return this->char_rank;
}

std::string Show::get_show_name() {
    return this->show_name;
}

std::string Show::get_fav_char() {
    return this->fav_char;
}

int Show::get_ep_watched() {
    return this->ep_watched;
}

double Show::get_rating() {
    return this->rating;
}

int Show::get_rank() {
    return this->rank;
}