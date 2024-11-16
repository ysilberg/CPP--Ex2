#pragma once
#include <string>
#include "DeviceList.h"

class User
{
private:
  unsigned int id;
  std::string username;
  unsigned int age;
  DevicesList devices;

public:
  // Initializes a new user object
  void init(unsigned int id, std::string username, unsigned int age);

  // Clears the object and deletes allocated memory
  void clear();

  // Getters - mark them as const
  unsigned int getID() const;
  std::string getUserName() const;
  unsigned int getAge() const;
  DevicesList &getDevices();

  // Adds a device to the user's list of devices
  void addDevice(Device newDevice);

  // Checks if all devices are "on" - mark as const
  bool checkIfDevicesAreOn() const;
};
