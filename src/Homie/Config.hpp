#pragma once

#include "Arduino.h"

#include <ArduinoJson.h>
#include "FS.h"
#include "Datatypes/Interface.hpp"
#include "Datatypes/ConfigStruct.hpp"
#include "Utils/DeviceId.hpp"
#include "Utils/Validation.hpp"
#include "Limits.hpp"
#include "../HomieSetting.hpp"
#include "../StreamingOperator.hpp"

namespace HomieInternals {
class Config {
 public:
  Config();
  bool load();
  inline const ConfigStruct& get() const;
  char* getSafeConfigFile() const;
  void erase();
  void bypassStandalone();
  bool canBypassStandalone();
  void write(const JsonObject& config);
  bool patch(const char* patch);
  BootMode getBootMode() const;
  void log() const;  // print the current config to log output

 private:
  BootMode _bootMode;
  ConfigStruct _configStruct;
  bool _spiffsBegan;

  bool _spiffsBegin();
};

const ConfigStruct& Config::get() const {
  return _configStruct;
}
}  // namespace HomieInternals
