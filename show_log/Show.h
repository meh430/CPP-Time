#ifndef SHOW_H
#define SHOW_H
#include <string>
#include <vector>
class Show {
    public:
        Show(std::string name);
        void set_fav_char(std::string char_name);
        void set_char_rank(int r, std::vector<Show> &data_list);
        void set_ep_watched(int e);
        bool set_rating(int r);
        void set_rank(int r, std::vector<Show> &data_list);
        void set_char_rank(int r);
        void set_rank(int r);
        int get_char_rank();
        std::string get_show_name();
        std::string get_fav_char();
        int get_ep_watched();
        double get_rating();
        int get_rank();

    private:
        std::string show_name;
        std::string fav_char;
        int char_rank ;
        int ep_watched;
        double rating;
        int rank;
};
#endif
