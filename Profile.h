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

  void setStatus(const std::string& newStatus);
  void addPostToProfilePage(std::string post);
  void addFriend(User friend_to_add);

  User getOwner() const;
  std::string getStatus() const;
  std::string getPage() const;
  std::string getFriends() const;
  std::string getFriendsWithSameNameLength() const;
  std::string getPosts() const;

  void changeWordInStatus(const std::string &oldWord, const std::string &newWord);

  // New method: removes all occurrences of a word in the status
  void changeAllWordsInStatus(const std::string &wordToRemove);
};
