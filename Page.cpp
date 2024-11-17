#include "Page.h"

void Page::init()
{
  status.clear();
  posts.clear();
}

std::string Page::getStatus() const
{
  return status;
}

std::string Page::getPosts() const
{
  return posts;
}

void Page::setStatus(const std::string &newStatus)
{
  status = newStatus;
}

void Page::setPosts(const std::string &newPost)
{
  posts = newPost;
}

void Page::clearPage()
{
  posts = "";
}

void Page::addLineToPosts(std::string new_Line)
{
  posts += new_Line;
}
