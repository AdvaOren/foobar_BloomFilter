# Bloom Filter Project

## Overview

A Bloom filter is a space-efficient probabilistic data structure used to test whether an element is a member of a set. Unlike a traditional hash table, Bloom filters are designed to provide fast insert and query operations with a trade-off: they allow false positives but no false negatives. This means that while the filter can tell you that an element might be in the set when it's not (false positive), it will never falsely tell you that an element is not in the set when it is.

## Features

- **Space Efficiency:** Uses a bit array and multiple hash functions to represent the set.
- **Probabilistic Nature:** Allows for a tunable rate of false positives.
- **Fast Operations:** Provides O(1) time complexity for both insert and query operations.

## Use Cases

- **Web Caching:** Quickly check if a URL is cached.
- **Databases:** Determine if a value might be present in the database.
- **Network Security:** Filter out malicious URLs or IP addresses.
- **Distributed Systems:** Efficiently synchronize state across systems.

## How It Works

1. **Initialization:**
   - The Bloom filter is initialized with a specified size and number of hash functions.
   
2. **Insertion:**
   - When inserting an element, it is hashed by each hash function, and the corresponding bits in the bit array are set to 1.
   
3. **Query:**
   - To check if an element is in the set, it is hashed by each hash function, and the corresponding bits in the bit array are checked. If all bits are 1, the element might be in the set. If any bit is 0, the element is definitely not in the set.

## Installation

### Prerequisites

- Node.js
- MongoDB

### Clone the Repository

```sh
git clone https://github.com/yourusername/bloom-filter-project.git
cd bloom-filter-project/cd
```
### Install Dependencies

```sh
cmake -S . -B build

cmake --build build
```

## Configuration

Create a `.env` file in the root directory with the following content:

```env
PORT=8080
CONNECTION_STRING=localhost
NODE_ENV=development
BLOOM_INIT="32 1 2"
BLACKLIST="example.com,example.net,example.org"
```

- `PORT`: The port on which the server will run.
- `CONNECTION_STRING`: The connection string for the Bloom filter server.
- `NODE_ENV`: The environment (development, production, etc.).
- `BLOOM_INIT`: Initialization parameters for the Bloom filter.
- `BLACKLIST`: A comma-separated list of URLs to initialize in the Bloom filter.

## Usage

### Start the Server

```sh
./build/project_main
```

### API Endpoints

- **Initialize Bloom Filter:**
  - `POST /initialize`
  - Initializes the Bloom filter with the given blacklist.
  
- **Check URL:**
  - `POST /check`
  - Body: `{ "url": "example.com" }`
  - Checks if the URL is blacklisted.

### Example Scripts

#### Initialize the Bloom Filter

```javascript
const bf = require('./bloom_filter/socket');

(async () => {
    await bf.init();
})();
```

#### Check if a URL is Blacklisted

```javascript
const bf = require('./bloom_filter/socket');

(async () => {
    const isBlacklisted = await bf.checkBlackListed("http://example.com");
    console.log(isBlacklisted); // true or false
})();
```
