#include "Page.h"
#include <iostream>

int main()
{
  Page myPage;

  // Initialize the page
  myPage.init();

  // Set a status and a post
  myPage.setStatus("Welcome to my Page!");
  myPage.setPosts("This is my first post.");

  // Display the status and posts
  std::cout << "Status: " << myPage.getStatus() << std::endl;
  std::cout << "Posts:\n"
            << myPage.getPosts() << std::endl;

  // Add more lines to the posts
  myPage.addLineToPosts("Here's a new update.");
  myPage.addLineToPosts("Thank you for visiting!");

  // Display the updated posts
  std::cout << "\nUpdated Posts:\n"
            << myPage.getPosts() << std::endl;

  // Clear the posts
  myPage.clearPage();
  std::cout << "\nPosts after clearing:\n"
            << myPage.getPosts() << std::endl;

  return 0;
}
