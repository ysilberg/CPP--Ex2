#include "User.h"

// Initializes a new user object
void User::init(unsigned int id, std::string username, unsigned int age)
{
  this->id = id;
  this->username = username;
  this->age = age;
  devices.init();
}

// Clears the user object and the associated device list
void User::clear()
{
  devices.clear();
  id = 0;
  username.clear();
  age = 0;
}

// Getters
unsigned int User::getID() const
{
  return id;
}

std::string User::getUserName() const
{
  return username;
}

unsigned int User::getAge() const
{
  return age;
}

DevicesList &User::getDevices()
{
  return devices;
}

// Adds a device to the user's list of devices
void User::addDevice(Device newDevice)
{
  devices.add(newDevice);
}

// Checks if all devices are on
bool User::checkIfDevicesAreOn() const
{
  DeviceNode *current = devices.get_first();
  while (current != nullptr)
  {
    if (!current->get_data().isActive())
    {
      return false;
    }
    current = current->get_next();
  }
  return true;
}
