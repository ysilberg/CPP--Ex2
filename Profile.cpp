#include "Profile.h"
#include "UserList.h"
#include "User.h"
#include "Page.h"
#include <iostream>
#include <sstream>

// Initializes the profile with an owner (User)
void Profile::init(User owner)
{
  this->user = owner;
  page.init();
  userList.init();
}

// Clears the profile (user, page, and friend list)
void Profile::clear()
{
  user.clear();
  page.clearPage();
  userList.clear();
}

// Returns the owner of the profile
User Profile::getOwner()
{
  return user;
}

// Sets the status on the profile page
void Profile::setStatus(std::string new_status)
{
  page.setStatus(new_status);
}

// Adds a post to the profile page
void Profile::addPostToProfilePage(std::string post)
{
  page.addLineToPosts(post);
}

// Adds a friend to the user's friend list
void Profile::addFriend(User friend_to_add)
{
  userList.add(friend_to_add);
}

// Returns the content of the profile page (status + posts)
std::string Profile::getPage()
{
  std::stringstream pageContent;
  pageContent << "Status: " << page.getStatus() << "\nPosts:\n"
              << page.getPosts();
  return pageContent.str();
}

// Returns a list of all friends
std::string Profile::getFriends()
{
  std::stringstream friendsStream;
  UserNode *current = userList.get_first();

  while (current != nullptr)
  {
    friendsStream << current->get_data().getUserName() << "\n";
    current = current->get_next();
  }
  return friendsStream.str();
}

// Returns friends with the same username length as the profile owner
std::string Profile::getFriendsWithSameNameLength()
{
  unsigned int ownerNameLength = user.getUserName().length();
  std::stringstream filteredFriends;
  UserNode *current = userList.get_first();

  while (current != nullptr)
  {
    if (current->get_data().getUserName().length() == ownerNameLength)
    {
      filteredFriends << current->get_data().getUserName() << "\n";
    }
    current = current->get_next();
  }
  return filteredFriends.str();
}
