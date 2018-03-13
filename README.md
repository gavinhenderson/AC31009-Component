### Contents

* [Aims of the Design Pattern](#aims-of-the-design-pattern)
* [The Problem](#the-problem)
* [The Solution](#the-solution)
* [Code Along](#code-along)

## Aim of the Design Pattern

The aim of the 'Component' design pattern is to allows for the decoupling of domains from their entities allowing them to span multiple domains. Decoupling allows for code reusability and allows developers to work on different sections of the code at the same time.

## The Problem

Say we developed a 'character' who moves on player input, is animated on screen and interacts with the environment. Naturally we want to put everything that involves our character into one class so its all contained. This sounds like a good idea but this will end up in us having to duplicate lots of code between characters. It also means if we want to change one part of a character we have to touch lots of other code that exposes you to lots more possible errors.

## The Solution

We are going to show how to overcome this problem using the 'Component' design pattern. The 'Component' design pattern works by using a combination of abstract classes and inheritance

<div style="text-align:center">
  <img src="diagrams/general.png">
</div>

## Code along

<div style="text-align:center">
  <img src="diagrams/example.png">
</div>
