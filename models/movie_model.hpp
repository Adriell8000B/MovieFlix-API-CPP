#ifndef MOVIE_MODEL_HPP_INCLUDED
#define MOVIE_MODEL_HPP_INCLUDED

#include <string>

struct Movies {
  std::string id;
  std::string movie_banner;
  std::string movie_rating;
  std::string movie_name;
  int movie_year;
  std::string movie_genre;
};

#endif