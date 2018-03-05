# Micro Examples

This repository is serving as a cheatsheet of sorts, taking from many sources and transposing into a collection of runnable examples using [platform.io](https://platformio.org) and mostly targetting esp8266 dev boards, although with platformio should be easily adaptable.

# Compiling / Running
1. Copy `_config/secrets.template.h` as `_config/secrets.h` and fill in with your credentials as needed.
  * _NOTE: `secrets.h` is gitignored so this shouldn't be a problem if you fork the repo, just noting here as an FYI_
2. Each sub directory is a standalone platformio project, refer to the platformio docs for details (I'll add info around this here when I get a chance)

# Hardware
As mentioned most of the examples target the esp8266 type development boards.  More specifically I tend to use the Witty Cloud boards like the [one found here](http://bit.ly/witty-esp8266) as they are cheap and convenient for prototyping.

# PlatformIO CLI Commands
* `pio run` will build the project (run from within a sub directory)

# References
* [PlatformIO Docs](http://docs.platformio.org/en/latest/)

