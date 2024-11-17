#pragma once
#include <string>
#include "Page.h"

class Page
{
private:
  std::string status;
  std::string posts;

public:
  void init();
  std::string getStatus() const;
  std::string getPosts() const;
  void setStatus(const std::string &newStatus);
  void setPosts(const std::string &newPost);
  void clearPage();
  void addLineToPosts(std::string new_Line);
};