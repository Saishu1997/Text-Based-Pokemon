## Polymorphism & Virtual Dispatch  
## Game: Text-Based Pokémon-Style Battle (C++)

A C++ text-based Pokémon-style battle system built to **master runtime polymorphism and virtual dispatch** through clean, extensible game architecture.

This project is part of a **7-day C++ Game Development curriculum**, with each day focusing on one or two advanced C++ concepts applied through a small but complete game.

---

## 🎮 Game Overview

- Turn-based party combat
- Player vs Enemy, each with a fixed team of creatures
- Creature types: **Fire, Water, Grass**
- No switching during battle
- When a creature faints, the next one automatically enters
- Battle ends when all creatures on one side are defeated

---

## 🧠 Core C++ Concepts

- Virtual functions
- `override` / `final`
- Base-class pointers
- Virtual destructors
- Dynamic binding (runtime polymorphism)
- Ownership via `std::unique_ptr`

---

## 🏗️ Architecture

- **Creature (base class)**
  - Defines the combat interface
  - Owns health, attack flow, and damage application

- **Derived Creatures**
  - `FireCreature`
  - `WaterCreature`
  - `GrassCreature`
  - Each implements type-specific combat behavior

- **Party**
  - Holds creatures in a fixed order
  - Automatically advances when the active creature faints
  - No type awareness

- **Battle**
  - Controls turn flow
  - Completely type-agnostic
  - Relies purely on polymorphism

---

## ⚔️ Combat System

- Polymorphic `Attack()` calls
- Type effectiveness handled via **double dispatch**
- Effectiveness rules:
  - Fire > Grass
  - Grass > Water
  - Water > Fire
- Console output clearly displays:
  - Damage dealt
  - Effectiveness feedback
  - HP changes
  - Fainting events

---

## ❌ Mandatory Constraints

- All creatures stored as:
  ```cpp
  std::vector<std::unique_ptr<Creature>>
