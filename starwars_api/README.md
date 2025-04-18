# Star Wars API

A Node.js script that interacts with the Star Wars API (SWAPI) to print all characters from a specific Star Wars movie.

## Description

This project contains a script that takes a Star Wars movie ID as a command-line argument and prints all characters that appear in that movie. The characters are printed in the same order as they appear in the API's `/films/` endpoint.

## Requirements

- Node.js (version 10.14.x)
- Request module

## Installation

1. Install Node.js 10:
```
curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
sudo apt-get install -y nodejs
```

2. Install the request module:
```
sudo npm install request --global
export NODE_PATH=/usr/lib/node_modules
```

3. Install semistandard for code style:
```
sudo npm install semistandard --global
```

## Usage

Run the script with a Star Wars movie ID as an argument:

```
./0-starwars_characters.js <Movie ID>
```

Example:
```
./0-starwars_characters.js 3
```

This will print all characters from "Return of the Jedi" (Movie ID 3).

## File Description

- `0-starwars_characters.js`: Script that fetches and prints Star Wars character names for a given movie ID.