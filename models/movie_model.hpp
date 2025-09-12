#ifndef MOVIE_REPOSITORY_HPP_INCLUDED
#define MOVIE_REPOSITORY_HPP_INCLUDED

#include <string>

struct movies {
  std::string id;
  std::string movie_banner;
  std::string movie_rating;
  std::string movie_name;
  int movie_year;
  std::string movie_genre;
};

#endif