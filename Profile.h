#pragma once
#include <string>
#include "UserList.h"
#include "User.h"
#include "Page.h"

enum ProfileType
{
  USER,
  PAGE,
  USER_LIST
};

class Profile
{
  private:
    User user;
    Page page;
    UserList userList;

  public:
    void init(User owner);
    void clear();
    User getOwner();
    void setStatus(std::string new_status);
    void addPostToProfilePage(std::string post);
    void addFriend(User friend_to_add);
    std::string getPage();
    std::string getFriends();
    std::string getFriendsWithSameNameLength();

};