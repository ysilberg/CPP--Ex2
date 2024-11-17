#include "Profile.h"
#include "User.h"
#include <iostream>

int main()
{
  // Create a profile owner
  User owner;
  owner.init(1, "JohnDoe", 30);

  // Initialize the profile
  Profile profile;
  profile.init(owner);

  // Set a status and add posts
  profile.setStatus("Hello, World!");
  profile.addPostToProfilePage("This is my first post.");
  profile.addPostToProfilePage("Learning C++ is fun!");

  // Create friends and add them to the profile
  User friend1;
  friend1.init(2, "Alice", 28);
  profile.addFriend(friend1);

  User friend2;
  friend2.init(3, "Bob", 25);
  profile.addFriend(friend2);

  User friend3;
  friend3.init(4, "Charlie", 32);
  profile.addFriend(friend3);

  // Display profile details
  std::cout << "Profile Page:\n"
            << profile.getPage() << std::endl;
  std::cout << "\nFriends:\n"
            << profile.getFriends() << std::endl;

  // Display friends with the same username length as the owner
  std::cout << "\nFriends with same username length as owner:\n";
  std::cout << profile.getFriendsWithSameNameLength() << std::endl;

  return 0;
}
