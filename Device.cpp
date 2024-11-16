#include "Device.h"

// Constructor to initialize default values
Device::Device() : id(0), type(PC), os("Unknown"), active(false) {}

// Method to initialize the device
void Device::init(unsigned int id, DeviceType type, std::string os)
{
  this->id = id;
  this->type = type;
  this->os = os;
  this->active = true;
}

// Getters - mark them as const
unsigned int Device::getID() const
{
  return id;
}

DeviceType Device::getType() const
{
  return type;
}

std::string Device::getOS() const
{
  return os;
}

bool Device::isActive() const
{
  return active;
}

// Methods to change device state
void Device::activate()
{
  active = true;
}

void Device::deactivate()
{
  active = false;
}
