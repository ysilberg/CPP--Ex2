#include "Profile.h"
#include "UserList.h"
#include "User.h"
#include "Page.h"
#include <iostream>
#include <sstream>
#include <algorithm>

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
User Profile::getOwner() const
{
  return user;
}

// Sets the status for the Profile
void Profile::setStatus(const std::string &new_status)
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

// Gets the content of the Profile page
std::string Profile::getPage() const
{
  std::stringstream pageContent;

  // Get the current status
  std::string status = page.getStatus();

  // If the status is empty, use the default pattern
  if (status.empty())
  {
    status = "\n*******************\n*******************\n";
  }

  pageContent << "Status: " << status;

  // Only add posts if there are any
  std::string posts = page.getPosts();
  if (!posts.empty())
  {
    pageContent << "\n*******************\n*******************\n"
                << posts;
  }

  return pageContent.str() + "\n";
}

// Returns a list of all friends
std::string Profile::getFriends() const
{
  std::stringstream friendsStream;
  UserNode *current = userList.get_first();

  // Concatenate usernames with a comma
  while (current != nullptr)
  {
    friendsStream << current->get_data().getUserName();
    current = current->get_next();
    if (current != nullptr)
    {
      friendsStream << ",";
    }
  }

  return friendsStream.str();
}

// Returns friends with the same username length as the profile owner
std::string Profile::getFriendsWithSameNameLength() const
{
  unsigned int ownerNameLength = user.getUserName().length();
  std::stringstream filteredFriends;
  UserNode *current = userList.get_first();
  bool first = true;

  while (current != nullptr)
  {
    // Check if the friend's username length matches the owner's
    if (current->get_data().getUserName().length() == ownerNameLength)
    {
      if (!first)
      {
        filteredFriends << ",";
      }
      filteredFriends << current->get_data().getUserName();
      first = false;
    }
    current = current->get_next();
  }

  return filteredFriends.str();
}

// Changes a single word in the status
void Profile::changeWordInStatus(const std::string &oldWord, const std::string &newWord)
{
  std::string status = page.getStatus();
  size_t pos = status.find(oldWord);
  if (pos != std::string::npos)
  {
    status.replace(pos, oldWord.length(), newWord);
    page.setStatus(status);
  }
}

// Removes all occurrences of a word in the status
void Profile::changeAllWordsInStatus(const std::string &wordToRemove)
{
  std::string status = page.getStatus();
  size_t pos = status.find(wordToRemove);

  // Loop to find and remove all occurrences of the word
  while (pos != std::string::npos)
  {
    status.erase(pos, wordToRemove.length());

    // Remove any extra spaces that may be left after erasing the word
    if (pos < status.length() && status[pos] == ' ')
    {
      status.erase(pos, 1);
    }

    pos = status.find(wordToRemove, pos);
  }
  page.setStatus(status);
}