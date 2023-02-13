#pragma once

#include <bitset>
#include <cstdint>

// An entity is just an integer ID
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;   // This is to avoid overflow

using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;


// Events
using EventId = std::uint32_t;
using ParamId = std::uint32_t;