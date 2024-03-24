/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;


void Game::moveStack(Stack & stack, unsigned stack_pos, unsigned target_position, unsigned other_position) {

  cout << *this << "Moving stack " << stack << "\t\t to pos " << target_position << endl;

  // if size == 1, move directly

  // if size >1, move stuff on top first, to other position
  // create stack to represent stuff on top of target block

  // std::cout << "stack size being moved: " << stack.size() << std::endl;
  if (stack.size() > 1) {
    // Create topStack
    Stack tempStack;
    unsigned iters = stack.size()-1;
    for (unsigned i=0; i < iters; i++){
      tempStack.push_back(stack.removeTop());      
    }
    std::cout << "\ttempStack: " << tempStack << std::endl;
    // reverse
    Stack topStack;
    for (unsigned i=0; i < iters; i++){
      // std::cout << tempStack.removeTop().getLength() << std::endl; // DEBUG
      topStack.push_back(tempStack.removeTop());
    }
    std::cout << "\ttopStack: " << topStack << std::endl;

    // move top stack off base block
    moveStack(topStack, stack_pos, other_position, target_position);

    // move base block
    // Stack singleStack;
    // singleStack.push_back(stack.removeTop());
    // moveStack(singleStack, target_position, other_position);
    cout << *this << "Moving cube " << stack.peekTop().getLength() << "\t\t to pos " << target_position << endl;
    Cube movingCube = stack.removeTop();
    stacks_[target_position].push_back(movingCube);

    // move top stack back onto base block
    
    // topStack showing up empty after call to removeTop() // DEV      
    moveStack(topStack, other_position, target_position, stack_pos);
    std::cout << "\n\ttopstack " << topStack << "size:" << std::endl; // DEBUG
    std::cout << topStack.size() << std::endl;
    if (topStack.size() == 1) {
      topStack.removeTop();
      std::cout << "\t\t\t\tdid this" << std::endl;
    }
    // moveStack(stacks_[other_position], other_position, target_position, stack_pos);

  }
  else if (stack.size() == 1) {
    Cube movingCube = stack.peekTop();
    stacks_[target_position].push_back(movingCube);
  }

  // for (unsigned i = stack.size()-1; i > 0 ; i--) {
  //   // make a loop I can run w/ a stack of size 0. (base case) // DEV    
  //   std::cout << "i: " << i << std::endl;
  //   // topStack.push_back();
  // }
  // std::cout << "\n\tmoveStack target stack:" << std::endl; // DEBUG
  // std::cout << "\t" << topStack << std::endl; // DEBUG

  // then move bottom-most block to target position
  // then move top stack to target position
  // moveStack(Stack & stack, unsigned target_position, unsigned other_position)
}


// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  // Prints out the state of the game:
  cout << *this << endl;

  // std::cout << "top of stack 0: " << ((stacks_[0].size() > 1) ? stacks_[0].peekTop().getLength() : 0) << std::endl; // DEBUG
  // std::cout << "top of stack 1: " << ((stacks_[1].size() > 1) ? stacks_[1].peekTop().getLength() : 0) << std::endl; // DEBUG
  // std::cout << "top of stack 2: " << ((stacks_[2].size() > 1) ? stacks_[2].peekTop().getLength() : 0) << std::endl; // DEBUG

  // move all 4 to pos 2
  moveStack(stacks_[0], 0, 2, 1);
    // move top 3 to pos 1
      // move top 2 to pos 2
        // move top 1 to pos 1
        // move bottom 1 to pos 2
        // move top 1 to pos 2

      // move bottom 1 to pos 1
      // move top 2 to pos 1

    // move bottom 1 to pos 2
    // move top 3 to pos 2

  // @TODO -- Finish solving the game!
  std::cout << std::endl; // DEBUG
}



// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }

  // Create the four cubes, placing each on stack 0:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
