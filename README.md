# Entity Component System (ECS) Library

This is a simple Entity Component System (ECS) library implemented in C++. ECS is a design pattern commonly used in game development to manage game objects and their behaviors in a flexible and efficient way. This library provides basic functionalities to create and manipulate entities, components, and systems within an ECS framework.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
  - [Creating Entities](#creating-entities)
  - [Defining Components](#defining-components)
  - [Adding and Removing Components](#adding-and-removing-components)
  - [Running Systems](#running-systems)
  - [Deleting Entities](#deleting-entities)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Overview

This ECS library provides a simple way to implement the Entity Component System pattern in C++. It includes functions to create entities, define and manage components, run systems, and delete entities from the system.

## Usage

### Creating Entities

To create a new entity, you can use the `new_entity` function, which returns an identifier for the newly created entity.

´´´ cpp
size_t entity = new_entity();

# Defining Components

Components represent the data and behaviors associated with entities. Components are defined as structs with specific functions. For example:
