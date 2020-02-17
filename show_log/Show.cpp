#include "Show.h"
#include <algorithm>
 Show::Show(std::string name) {
    this->show_name = name;
    this->fav_char = "";
    this->char_rank = 0;
    this->ep_watched = 0;
    this->rating = 0.0;
    this->rank = 0;
 }

void Show::set_fav_char(std::string char_name) {
    this->fav_char = char_name;
}

void Show::set_char_rank(int r, std::vector<Show> &data_list) {
    this->char_rank = r;
    std::sort(data_list.begin(), data_list.end(), [](const Show& lhs, const Show& rhs) { return lhs.char_rank < rhs.char_rank; });
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

    std::sort(data_list.begin(), data_list.end(), [](const Show& lhs, const Show& rhs) { return lhs.rank < rhs.rank; });
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

bool Show::set_rating(int r) {
    if(r < 0 || r > 10)
        return false;

    
    this->rating = r;
    return true;
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