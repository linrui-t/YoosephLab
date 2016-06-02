#ifndef _SCORING_PROT_
#define _SCORING_PROT_

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define MAX 999999

static int ch_[256] = {
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, 24, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, 0, 20, 4, 3, 6,
      13, 7, 8, 9, 21, 11, 10, 12, 2, -1,
      14, 5, 1, 15, 16, -1, 19, 17, 23, 18,
      22, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
      -1, -1, -1, -1, -1, -1
};


static int sc_[8][25][25] = 
{
  // BLOSUM62 matrix
  {
    { 4, -1, -2, -2,  0, -1, -1,  0, -2, -1, -1, -1, -1, -2, -1,  1,  0, -3, -2,  0, -2, -1, -1, -1, -4}, 
    {-1,  5,  0, -2, -3,  1,  0, -2,  0, -3, -2,  2, -1, -3, -2, -1, -1, -3, -2, -3, -1, -2,  0, -1, -4}, 
    {-2,  0,  6,  1, -3,  0,  0,  0,  1, -3, -3,  0, -2, -3, -2,  1,  0, -4, -2, -3,  4, -3,  0, -1, -4}, 
    {-2, -2,  1,  6, -3,  0,  2, -1, -1, -3, -4, -1, -3, -3, -1,  0, -1, -4, -3, -3,  4, -3,  1, -1, -4}, 
    { 0, -3, -3, -3,  9, -3, -4, -3, -3, -1, -1, -3, -1, -2, -3, -1, -1, -2, -2, -1, -3, -1, -3, -1, -4}, 
    {-1,  1,  0,  0, -3,  5,  2, -2,  0, -3, -2,  1,  0, -3, -1,  0, -1, -2, -1, -2,  0, -2,  4, -1, -4}, 
    {-1,  0,  0,  2, -4,  2,  5, -2,  0, -3, -3,  1, -2, -3, -1,  0, -1, -3, -2, -2,  1, -3,  4, -1, -4}, 
    { 0, -2,  0, -1, -3, -2, -2,  6, -2, -4, -4, -2, -3, -3, -2,  0, -2, -2, -3, -3, -1, -4, -2, -1, -4}, 
    {-2,  0,  1, -1, -3,  0,  0, -2,  8, -3, -3, -1, -2, -1, -2, -1, -2, -2,  2, -3,  0, -3,  0, -1, -4}, 
    {-1, -3, -3, -3, -1, -3, -3, -4, -3,  4,  2, -3,  1,  0, -3, -2, -1, -3, -1,  3, -3,  3, -3, -1, -4}, 
    {-1, -2, -3, -4, -1, -2, -3, -4, -3,  2,  4, -2,  2,  0, -3, -2, -1, -2, -1,  1, -4,  3, -3, -1, -4}, 
    {-1,  2,  0, -1, -3,  1,  1, -2, -1, -3, -2,  5, -1, -3, -1,  0, -1, -3, -2, -2,  0, -3,  1, -1, -4}, 
    {-1, -1, -2, -3, -1,  0, -2, -3, -2,  1,  2, -1,  5,  0, -2, -1, -1, -1, -1,  1, -3,  2, -1, -1, -4}, 
    {-2, -3, -3, -3, -2, -3, -3, -3, -1,  0,  0, -3,  0,  6, -4, -2, -2,  1,  3, -1, -3,  0, -3, -1, -4}, 
    {-1, -2, -2, -1, -3, -1, -1, -2, -2, -3, -3, -1, -2, -4,  7, -1, -1, -4, -3, -2, -2, -3, -1, -1, -4}, 
    { 1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -2,  0, -1, -2, -1,  4,  1, -3, -2, -2,  0, -2,  0, -1, -4}, 
    { 0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1,  1,  5, -2, -2,  0, -1, -1, -1, -1, -4}, 
    {-3, -3, -4, -4, -2, -2, -3, -2, -2, -3, -2, -3, -1,  1, -4, -3, -2, 11,  2, -3, -4, -2, -2, -1, -4}, 
    {-2, -2, -2, -3, -2, -1, -2, -3,  2, -1, -1, -2, -1,  3, -3, -2, -2,  2,  7, -1, -3, -1, -2, -1, -4}, 
    { 0, -3, -3, -3, -1, -2, -2, -3, -3,  3,  1, -2,  1, -1, -2, -2,  0, -3, -1,  4, -3,  2, -2, -1, -4}, 
    {-2, -1,  4,  4, -3,  0,  1, -1,  0, -3, -4,  0, -3, -3, -2,  0, -1, -4, -3, -3,  4, -3,  0, -1, -4}, 
    {-1, -2, -3, -3, -1, -2, -3, -4, -3,  3,  3, -3,  2,  0, -3, -2, -1, -2, -1,  2, -3,  3, -3, -1, -4}, 
    {-1,  0,  0,  1, -3,  4,  4, -2,  0, -3, -3,  1, -1, -3, -1,  0, -1, -2, -2, -2,  0, -3,  4, -1, -4}, 
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -4}, 
    {-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,  1}
  },
  // BLOSUM80 matrix
  {
    { 5, -2, -2, -2, -1, -1, -1,  0, -2, -2, -2, -1, -1, -3, -1,  1,  0, -3, -2,  0, -2, -2, -1, -1, -6},
    {-2,  6, -1, -2, -4,  1, -1, -3,  0, -3, -3,  2, -2, -4, -2, -1, -1, -4, -3, -3, -1, -3,  0, -1, -6},
    {-2, -1,  6,  1, -3,  0, -1, -1,  0, -4, -4,  0, -3, -4, -3,  0,  0, -4, -3, -4,  5, -4,  0, -1, -6},
    {-2, -2,  1,  6, -4, -1,  1, -2, -2, -4, -5, -1, -4, -4, -2, -1, -1, -6, -4, -4,  5, -5,  1, -1, -6},
    {-1, -4, -3, -4,  9, -4, -5, -4, -4, -2, -2, -4, -2, -3, -4, -2, -1, -3, -3, -1, -4, -2, -4, -1, -6},
    {-1,  1,  0, -1, -4,  6,  2, -2,  1, -3, -3,  1,  0, -4, -2,  0, -1, -3, -2, -3,  0, -3,  4, -1, -6},
    {-1, -1, -1,  1, -5,  2,  6, -3,  0, -4, -4,  1, -2, -4, -2,  0, -1, -4, -3, -3,  1, -4,  5, -1, -6},
    { 0, -3, -1, -2, -4, -2, -3,  6, -3, -5, -4, -2, -4, -4, -3, -1, -2, -4, -4, -4, -1, -5, -3, -1, -6},
    {-2,  0,  0, -2, -4,  1,  0, -3,  8, -4, -3, -1, -2, -2, -3, -1, -2, -3,  2, -4, -1, -4,  0, -1, -6},
    {-2, -3, -4, -4, -2, -3, -4, -5, -4,  5,  1, -3,  1, -1, -4, -3, -1, -3, -2,  3, -4,  3, -4, -1, -6},
    {-2, -3, -4, -5, -2, -3, -4, -4, -3,  1,  4, -3,  2,  0, -3, -3, -2, -2, -2,  1, -4,  3, -3, -1, -6},
    {-1,  2,  0, -1, -4,  1,  1, -2, -1, -3, -3,  5, -2, -4, -1, -1, -1, -4, -3, -3, -1, -3,  1, -1, -6},
    {-1, -2, -3, -4, -2,  0, -2, -4, -2,  1,  2, -2,  6,  0, -3, -2, -1, -2, -2,  1, -3,  2, -1, -1, -6},
    {-3, -4, -4, -4, -3, -4, -4, -4, -2, -1,  0, -4,  0,  6, -4, -3, -2,  0,  3, -1, -4,  0, -4, -1, -6},
    {-1, -2, -3, -2, -4, -2, -2, -3, -3, -4, -3, -1, -3, -4,  8, -1, -2, -5, -4, -3, -2, -4, -2, -1, -6},
    { 1, -1,  0, -1, -2,  0,  0, -1, -1, -3, -3, -1, -2, -3, -1,  5,  1, -4, -2, -2,  0, -3,  0, -1, -6},
    { 0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -2, -1, -1, -2, -2,  1,  5, -4, -2,  0, -1, -1, -1, -1, -6},
    {-3, -4, -4, -6, -3, -3, -4, -4, -3, -3, -2, -4, -2,  0, -5, -4, -4, 11,  2, -3, -5, -3, -3, -1, -6},
    {-2, -3, -3, -4, -3, -2, -3, -4,  2, -2, -2, -3, -2,  3, -4, -2, -2,  2,  7, -2, -3, -2, -3, -1, -6},
    { 0, -3, -4, -4, -1, -3, -3, -4, -4,  3,  1, -3,  1, -1, -3, -2,  0, -3, -2,  4, -4,  2, -3, -1, -6},
    {-2, -1,  5,  5, -4,  0,  1, -1, -1, -4, -4, -1, -3, -4, -2,  0, -1, -5, -3, -4,  5, -4,  0, -1, -6},
    {-2, -3, -4, -5, -2, -3, -4, -5, -4,  3,  3, -3,  2,  0, -4, -3, -1, -3, -2,  2, -4,  3, -3, -1, -6},
    {-1,  0,  0,  1, -4,  4,  5, -3,  0, -4, -3,  1, -1, -4, -2,  0, -1, -3, -3, -3,  0, -3,  5, -1, -6},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -6},
    {-6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  1}
  },
  // BLOSUM90 matrix
  {
    { 5, -2, -2, -3, -1, -1, -1,  0, -2, -2, -2, -1, -2, -3, -1,  1,  0, -4, -3, -1, -2, -2, -1, -1, -6},
    {-2,  6, -1, -3, -5,  1, -1, -3,  0, -4, -3,  2, -2, -4, -3, -1, -2, -4, -3, -3, -2, -3,  0, -1, -6},
    {-2, -1,  7,  1, -4,  0, -1, -1,  0, -4, -4,  0, -3, -4, -3,  0,  0, -5, -3, -4,  5, -4, -1, -1, -6},
    {-3, -3,  1,  7, -5, -1,  1, -2, -2, -5, -5, -1, -4, -5, -3, -1, -2, -6, -4, -5,  5, -5,  1, -1, -6},
    {-1, -5, -4, -5,  9, -4, -6, -4, -5, -2, -2, -4, -2, -3, -4, -2, -2, -4, -4, -2, -4, -2, -5, -1, -6},
    {-1,  1,  0, -1, -4,  7,  2, -3,  1, -4, -3,  1,  0, -4, -2, -1, -1, -3, -3, -3, -1, -3,  5, -1, -6},
    {-1, -1, -1,  1, -6,  2,  6, -3, -1, -4, -4,  0, -3, -5, -2, -1, -1, -5, -4, -3,  1, -4,  5, -1, -6},
    { 0, -3, -1, -2, -4, -3, -3,  6, -3, -5, -5, -2, -4, -5, -3, -1, -3, -4, -5, -5, -2, -5, -3, -1, -6},
    {-2,  0,  0, -2, -5,  1, -1, -3,  8, -4, -4, -1, -3, -2, -3, -2, -2, -3,  1, -4, -1, -4,  0, -1, -6},
    {-2, -4, -4, -5, -2, -4, -4, -5, -4,  5,  1, -4,  1, -1, -4, -3, -1, -4, -2,  3, -5,  3, -4, -1, -6},
    {-2, -3, -4, -5, -2, -3, -4, -5, -4,  1,  5, -3,  2,  0, -4, -3, -2, -3, -2,  0, -5,  4, -4, -1, -6},
    {-1,  2,  0, -1, -4,  1,  0, -2, -1, -4, -3,  6, -2, -4, -2, -1, -1, -5, -3, -3, -1, -3,  1, -1, -6},
    {-2, -2, -3, -4, -2,  0, -3, -4, -3,  1,  2, -2,  7, -1, -3, -2, -1, -2, -2,  0, -4,  2, -2, -1, -6},
    {-3, -4, -4, -5, -3, -4, -5, -5, -2, -1,  0, -4, -1,  7, -4, -3, -3,  0,  3, -2, -4,  0, -4, -1, -6},
    {-1, -3, -3, -3, -4, -2, -2, -3, -3, -4, -4, -2, -3, -4,  8, -2, -2, -5, -4, -3, -3, -4, -2, -1, -6},
    { 1, -1,  0, -1, -2, -1, -1, -1, -2, -3, -3, -1, -2, -3, -2,  5,  1, -4, -3, -2,  0, -3, -1, -1, -6},
    { 0, -2,  0, -2, -2, -1, -1, -3, -2, -1, -2, -1, -1, -3, -2,  1,  6, -4, -2, -1, -1, -2, -1, -1, -6},
    {-4, -4, -5, -6, -4, -3, -5, -4, -3, -4, -3, -5, -2,  0, -5, -4, -4, 11,  2, -3, -6, -3, -4, -1, -6},
    {-3, -3, -3, -4, -4, -3, -4, -5,  1, -2, -2, -3, -2,  3, -4, -3, -2,  2,  8, -3, -4, -2, -3, -1, -6},
    {-1, -3, -4, -5, -2, -3, -3, -5, -4,  3,  0, -3,  0, -2, -3, -2, -1, -3, -3,  5, -4,  1, -3, -1, -6},
    {-2, -2,  5,  5, -4, -1,  1, -2, -1, -5, -5, -1, -4, -4, -3,  0, -1, -6, -4, -4,  5, -5,  0, -1, -6},
    {-2, -3, -4, -5, -2, -3, -4, -5, -4,  3,  4, -3,  2,  0, -4, -3, -2, -3, -2,  1, -5,  4, -4, -1, -6},
    {-1,  0, -1,  1, -5,  5,  5, -3,  0, -4, -4,  1, -2, -4, -2, -1, -1, -4, -3, -3,  0, -4,  5, -1, -6},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -6},
    {-6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  1}
  },
  // BLOSUM50 matrix
  {
    { 5, -2, -1, -2, -1, -1, -1,  0, -2, -1, -2, -1, -1, -3, -1,  1,  0, -3, -2,  0, -2, -2, -1, -1, -5},
    {-2,  7, -1, -2, -4,  1,  0, -3,  0, -4, -3,  3, -2, -3, -3, -1, -1, -3, -1, -3, -1, -3,  0, -1, -5},
    {-1, -1,  7,  2, -2,  0,  0,  0,  1, -3, -4,  0, -2, -4, -2,  1,  0, -4, -2, -3,  5, -4,  0, -1, -5},
    {-2, -2,  2,  8, -4,  0,  2, -1, -1, -4, -4, -1, -4, -5, -1,  0, -1, -5, -3, -4,  6, -4,  1, -1, -5},
    {-1, -4, -2, -4, 13, -3, -3, -3, -3, -2, -2, -3, -2, -2, -4, -1, -1, -5, -3, -1, -3, -2, -3, -1, -5},
    {-1,  1,  0,  0, -3,  7,  2, -2,  1, -3, -2,  2,  0, -4, -1,  0, -1, -1, -1, -3,  0, -3,  4, -1, -5},
    {-1,  0,  0,  2, -3,  2,  6, -3,  0, -4, -3,  1, -2, -3, -1, -1, -1, -3, -2, -3,  1, -3,  5, -1, -5},
    { 0, -3,  0, -1, -3, -2, -3,  8, -2, -4, -4, -2, -3, -4, -2,  0, -2, -3, -3, -4, -1, -4, -2, -1, -5},
    {-2,  0,  1, -1, -3,  1,  0, -2, 10, -4, -3,  0, -1, -1, -2, -1, -2, -3,  2, -4,  0, -3,  0, -1, -5},
    {-1, -4, -3, -4, -2, -3, -4, -4, -4,  5,  2, -3,  2,  0, -3, -3, -1, -3, -1,  4, -4,  4, -3, -1, -5},
    {-2, -3, -4, -4, -2, -2, -3, -4, -3,  2,  5, -3,  3,  1, -4, -3, -1, -2, -1,  1, -4,  4, -3, -1, -5},
    {-1,  3,  0, -1, -3,  2,  1, -2,  0, -3, -3,  6, -2, -4, -1,  0, -1, -3, -2, -3,  0, -3,  1, -1, -5},
    {-1, -2, -2, -4, -2,  0, -2, -3, -1,  2,  3, -2,  7,  0, -3, -2, -1, -1,  0,  1, -3,  2, -1, -1, -5},
    {-3, -3, -4, -5, -2, -4, -3, -4, -1,  0,  1, -4,  0,  8, -4, -3, -2,  1,  4, -1, -4,  1, -4, -1, -5},
    {-1, -3, -2, -1, -4, -1, -1, -2, -2, -3, -4, -1, -3, -4, 10, -1, -1, -4, -3, -3, -2, -3, -1, -1, -5},
    { 1, -1,  1,  0, -1,  0, -1,  0, -1, -3, -3,  0, -2, -3, -1,  5,  2, -4, -2, -2,  0, -3,  0, -1, -5},
    { 0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1,  2,  5, -3, -2,  0,  0, -1, -1, -1, -5},
    {-3, -3, -4, -5, -5, -1, -3, -3, -3, -3, -2, -3, -1,  1, -4, -4, -3, 15,  2, -3, -5, -2, -2, -1, -5},
    {-2, -1, -2, -3, -3, -1, -2, -3,  2, -1, -1, -2,  0,  4, -3, -2, -2,  2,  8, -1, -3, -1, -2, -1, -5},
    { 0, -3, -3, -4, -1, -3, -3, -4, -4,  4,  1, -3,  1, -1, -3, -2,  0, -3, -1,  5, -3,  2, -3, -1, -5},
    {-2, -1,  5,  6, -3,  0,  1, -1,  0, -4, -4,  0, -3, -4, -2,  0,  0, -5, -3, -3,  6, -4,  1, -1, -5},
    {-2, -3, -4, -4, -2, -3, -3, -4, -3,  4,  4, -3,  2,  1, -3, -3, -1, -2, -1,  2, -4,  4, -3, -1, -5},
    {-1,  0,  0,  1, -3,  4,  5, -2,  0, -3, -3,  1, -1, -4, -1,  0, -1, -2, -2, -3,  1, -3,  5, -1, -5},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -5},
    {-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  1}
  },
  // BLOSUM45 matrix
  {
    { 5, -2, -1, -2, -1, -1, -1,  0, -2, -1, -1, -1, -1, -2, -1,  1,  0, -2, -2,  0, -1, -1, -1, -1, -5},
    {-2,  7,  0, -1, -3,  1,  0, -2,  0, -3, -2,  3, -1, -2, -2, -1, -1, -2, -1, -2, -1, -3,  1, -1, -5},
    {-1,  0,  6,  2, -2,  0,  0,  0,  1, -2, -3,  0, -2, -2, -2,  1,  0, -4, -2, -3,  5, -3,  0, -1, -5},
    {-2, -1,  2,  7, -3,  0,  2, -1,  0, -4, -3,  0, -3, -4, -1,  0, -1, -4, -2, -3,  6, -3,  1, -1, -5},
    {-1, -3, -2, -3, 12, -3, -3, -3, -3, -3, -2, -3, -2, -2, -4, -1, -1, -5, -3, -1, -2, -2, -3, -1, -5},
    {-1,  1,  0,  0, -3,  6,  2, -2,  1, -2, -2,  1,  0, -4, -1,  0, -1, -2, -1, -3,  0, -2,  4, -1, -5},
    {-1,  0,  0,  2, -3,  2,  6, -2,  0, -3, -2,  1, -2, -3,  0,  0, -1, -3, -2, -3,  1, -3,  5, -1, -5},
    { 0, -2,  0, -1, -3, -2, -2,  7, -2, -4, -3, -2, -2, -3, -2,  0, -2, -2, -3, -3, -1, -4, -2, -1, -5},
    {-2,  0,  1,  0, -3,  1,  0, -2, 10, -3, -2, -1,  0, -2, -2, -1, -2, -3,  2, -3,  0, -2,  0, -1, -5},
    {-1, -3, -2, -4, -3, -2, -3, -4, -3,  5,  2, -3,  2,  0, -2, -2, -1, -2,  0,  3, -3,  4, -3, -1, -5},
    {-1, -2, -3, -3, -2, -2, -2, -3, -2,  2,  5, -3,  2,  1, -3, -3, -1, -2,  0,  1, -3,  4, -2, -1, -5},
    {-1,  3,  0,  0, -3,  1,  1, -2, -1, -3, -3,  5, -1, -3, -1, -1, -1, -2, -1, -2,  0, -3,  1, -1, -5},
    {-1, -1, -2, -3, -2,  0, -2, -2,  0,  2,  2, -1,  6,  0, -2, -2, -1, -2,  0,  1, -2,  2, -1, -1, -5},
    {-2, -2, -2, -4, -2, -4, -3, -3, -2,  0,  1, -3,  0,  8, -3, -2, -1,  1,  3,  0, -3,  1, -3, -1, -5},
    {-1, -2, -2, -1, -4, -1,  0, -2, -2, -2, -3, -1, -2, -3,  9, -1, -1, -3, -3, -3, -2, -3, -1, -1, -5},
    { 1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -3, -1, -2, -2, -1,  4,  2, -4, -2, -1,  0, -2,  0, -1, -5},
    { 0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1, -1,  2,  5, -3, -1,  0,  0, -1, -1, -1, -5},
    {-2, -2, -4, -4, -5, -2, -3, -2, -3, -2, -2, -2, -2,  1, -3, -4, -3, 15,  3, -3, -4, -2, -2, -1, -5},
    {-2, -1, -2, -2, -3, -1, -2, -3,  2,  0,  0, -1,  0,  3, -3, -2, -1,  3,  8, -1, -2,  0, -2, -1, -5},
    { 0, -2, -3, -3, -1, -3, -3, -3, -3,  3,  1, -2,  1,  0, -3, -1,  0, -3, -1,  5, -3,  2, -3, -1, -5},
    {-1, -1,  5,  6, -2,  0,  1, -1,  0, -3, -3,  0, -2, -3, -2,  0,  0, -4, -2, -3,  5, -3,  1, -1, -5},
    {-1, -3, -3, -3, -2, -2, -3, -4, -2,  4,  4, -3,  2,  1, -3, -2, -1, -2,  0,  2, -3,  4, -2, -1, -5},
    {-1,  1,  0,  1, -3,  4,  5, -2,  0, -3, -2,  1, -1, -3, -1,  0, -1, -2, -2, -3,  1, -2,  5, -1, -5},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -5},
    {-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  1}
  },
  // PAM250 matrix
  {
    { 2, -2,  0,  0, -2,  0,  0,  1, -1, -1, -2, -1, -1, -3,  1,  1,  1, -6, -3,  0,  0, -1,  0, -1, -8},
    {-2,  6,  0, -1, -4,  1, -1, -3,  2, -2, -3,  3,  0, -4,  0,  0, -1,  2, -4, -2, -1, -3,  0, -1, -8},
    { 0,  0,  2,  2, -4,  1,  1,  0,  2, -2, -3,  1, -2, -3,  0,  1,  0, -4, -2, -2,  2, -3,  1, -1, -8},
    { 0, -1,  2,  4, -5,  2,  3,  1,  1, -2, -4,  0, -3, -6, -1,  0,  0, -7, -4, -2,  3, -3,  3, -1, -8},
    {-2, -4, -4, -5, 12, -5, -5, -3, -3, -2, -6, -5, -5, -4, -3,  0, -2, -8,  0, -2, -4, -5, -5, -1, -8},
    { 0,  1,  1,  2, -5,  4,  2, -1,  3, -2, -2,  1, -1, -5,  0, -1, -1, -5, -4, -2,  1, -2,  3, -1, -8},
    { 0, -1,  1,  3, -5,  2,  4,  0,  1, -2, -3,  0, -2, -5, -1,  0,  0, -7, -4, -2,  3, -3,  3, -1, -8},
    { 1, -3,  0,  1, -3, -1,  0,  5, -2, -3, -4, -2, -3, -5,  0,  1,  0, -7, -5, -1,  0, -4,  0, -1, -8},
    {-1,  2,  2,  1, -3,  3,  1, -2,  6, -2, -2,  0, -2, -2,  0, -1, -1, -3,  0, -2,  1, -2,  2, -1, -8},
    {-1, -2, -2, -2, -2, -2, -2, -3, -2,  5,  2, -2,  2,  1, -2, -1,  0, -5, -1,  4, -2,  3, -2, -1, -8},
    {-2, -3, -3, -4, -6, -2, -3, -4, -2,  2,  6, -3,  4,  2, -3, -3, -2, -2, -1,  2, -3,  5, -3, -1, -8},
    {-1,  3,  1,  0, -5,  1,  0, -2,  0, -2, -3,  5,  0, -5, -1,  0,  0, -3, -4, -2,  1, -3,  0, -1, -8},
    {-1,  0, -2, -3, -5, -1, -2, -3, -2,  2,  4,  0,  6,  0, -2, -2, -1, -4, -2,  2, -2,  3, -2, -1, -8},
    {-3, -4, -3, -6, -4, -5, -5, -5, -2,  1,  2, -5,  0,  9, -5, -3, -3,  0,  7, -1, -4,  2, -5, -1, -8},
    { 1,  0,  0, -1, -3,  0, -1,  0,  0, -2, -3, -1, -2, -5,  6,  1,  0, -6, -5, -1, -1, -2,  0, -1, -8},
    { 1,  0,  1,  0,  0, -1,  0,  1, -1, -1, -3,  0, -2, -3,  1,  2,  1, -2, -3, -1,  0, -2,  0, -1, -8},
    { 1, -1,  0,  0, -2, -1,  0,  0, -1,  0, -2,  0, -1, -3,  0,  1,  3, -5, -3,  0,  0, -1, -1, -1, -8},
    {-6,  2, -4, -7, -8, -5, -7, -7, -3, -5, -2, -3, -4,  0, -6, -2, -5, 17,  0, -6, -5, -3, -6, -1, -8},
    {-3, -4, -2, -4,  0, -4, -4, -5,  0, -1, -1, -4, -2,  7, -5, -3, -3,  0, 10, -2, -3, -1, -4, -1, -8},
    { 0, -2, -2, -2, -2, -2, -2, -1, -2,  4,  2, -2,  2, -1, -1, -1,  0, -6, -2,  4, -2,  2, -2, -1, -8},
    { 0, -1,  2,  3, -4,  1,  3,  0,  1, -2, -3,  1, -2, -4, -1,  0,  0, -5, -3, -2,  3, -3,  2, -1, -8},
    {-1, -3, -3, -3, -5, -2, -3, -4, -2,  3,  5, -3,  3,  2, -2, -2, -1, -3, -1,  2, -3,  5, -2, -1, -8},
    { 0,  0,  1,  3, -5,  3,  3,  0,  2, -2, -3,  0, -2, -5,  0,  0, -1, -6, -4, -2,  2, -2,  3, -1, -8},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -8},
    {-8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,  1}
  },
  // PAM70 matrix
  {
    {  5, -4, -2, -1, -4, -2, -1,  0, -4, -2, -4, -4, -3, -6,  0,  1,  1, -9, -5, -1, -1, -3, -1, -1,-11},
    { -4,  8, -3, -6, -5,  0, -5, -6,  0, -3, -6,  2, -2, -7, -2, -1, -4,  0, -7, -5, -4, -5, -2, -1,-11},
    { -2, -3,  6,  3, -7, -1,  0, -1,  1, -3, -5,  0, -5, -6, -3,  1,  0, -6, -3, -5,  5, -4, -1, -1,-11},
    { -1, -6,  3,  6, -9,  0,  3, -1, -1, -5, -8, -2, -7,-10, -4, -1, -2,-10, -7, -5,  5, -7,  2, -1,-11},
    { -4, -5, -7, -9,  9, -9, -9, -6, -5, -4,-10, -9, -9, -8, -5, -1, -5,-11, -2, -4, -8, -7, -9, -1,-11},
    { -2,  0, -1,  0, -9,  7,  2, -4,  2, -5, -3, -1, -2, -9, -1, -3, -3, -8, -8, -4, -1, -3,  5, -1,-11},
    { -1, -5,  0,  3, -9,  2,  6, -2, -2, -4, -6, -2, -4, -9, -3, -2, -3,-11, -6, -4,  2, -5,  5, -1,-11},
    {  0, -6, -1, -1, -6, -4, -2,  6, -6, -6, -7, -5, -6, -7, -3,  0, -3,-10, -9, -3, -1, -7, -3, -1,-11},
    { -4,  0,  1, -1, -5,  2, -2, -6,  8, -6, -4, -3, -6, -4, -2, -3, -4, -5, -1, -4,  0, -4,  1, -1,-11},
    { -2, -3, -3, -5, -4, -5, -4, -6, -6,  7,  1, -4,  1,  0, -5, -4, -1, -9, -4,  3, -4,  4, -4, -1,-11},
    { -4, -6, -5, -8,-10, -3, -6, -7, -4,  1,  6, -5,  2, -1, -5, -6, -4, -4, -4,  0, -6,  5, -4, -1,-11},
    { -4,  2,  0, -2, -9, -1, -2, -5, -3, -4, -5,  6,  0, -9, -4, -2, -1, -7, -7, -6, -1, -5, -2, -1,-11},
    { -3, -2, -5, -7, -9, -2, -4, -6, -6,  1,  2,  0, 10, -2, -5, -3, -2, -8, -7,  0, -6,  2, -3, -1,-11},
    { -6, -7, -6,-10, -8, -9, -9, -7, -4,  0, -1, -9, -2,  8, -7, -4, -6, -2,  4, -5, -7, -1, -9, -1,-11},
    {  0, -2, -3, -4, -5, -1, -3, -3, -2, -5, -5, -4, -5, -7,  7,  0, -2, -9, -9, -3, -4, -5, -2, -1,-11},
    {  1, -1,  1, -1, -1, -3, -2,  0, -3, -4, -6, -2, -3, -4,  0,  5,  2, -3, -5, -3,  0, -5, -2, -1,-11},
    {  1, -4,  0, -2, -5, -3, -3, -3, -4, -1, -4, -1, -2, -6, -2,  2,  6, -8, -4, -1, -1, -3, -3, -1,-11},
    { -9,  0, -6,-10,-11, -8,-11,-10, -5, -9, -4, -7, -8, -2, -9, -3, -8, 13, -3,-10, -7, -5,-10, -1,-11},
    { -5, -7, -3, -7, -2, -8, -6, -9, -1, -4, -4, -7, -7,  4, -9, -5, -4, -3,  9, -5, -4, -4, -7, -1,-11},
    { -1, -5, -5, -5, -4, -4, -4, -3, -4,  3,  0, -6,  0, -5, -3, -3, -1,-10, -5,  6, -5,  1, -4, -1,-11},
    { -1, -4,  5,  5, -8, -1,  2, -1,  0, -4, -6, -1, -6, -7, -4,  0, -1, -7, -4, -5,  5, -5,  1, -1,-11},
    { -3, -5, -4, -7, -7, -3, -5, -7, -4,  4,  5, -5,  2, -1, -5, -5, -3, -5, -4,  1, -5,  5, -4, -1,-11},
    { -1, -2, -1,  2, -9,  5,  5, -3,  1, -4, -4, -2, -3, -9, -2, -2, -3,-10, -7, -4,  1, -4,  5, -1,-11},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-11},
    {-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,  1}
  },
  // PAM30 matrix
  {
    {  6, -7, -4, -3, -6, -4, -2, -2, -7, -5, -6, -7, -5, -8, -2,  0, -1,-13, -8, -2, -3, -6, -3, -1,-17},
    { -7,  8, -6,-10, -8, -2, -9, -9, -2, -5, -8,  0, -4, -9, -4, -3, -6, -2,-10, -8, -7, -7, -4, -1,-17},
    { -4, -6,  8,  2,-11, -3, -2, -3,  0, -5, -7, -1, -9, -9, -6,  0, -2, -8, -4, -8,  6, -6, -3, -1,-17},
    { -3,-10,  2,  8,-14, -2,  2, -3, -4, -7,-12, -4,-11,-15, -8, -4, -5,-15,-11, -8,  6,-10,  1, -1,-17},
    { -6, -8,-11,-14, 10,-14,-14, -9, -7, -6,-15,-14,-13,-13, -8, -3, -8,-15, -4, -6,-12, -9,-14, -1,-17},
    { -4, -2, -3, -2,-14,  8,  1, -7,  1, -8, -5, -3, -4,-13, -3, -5, -5,-13,-12, -7, -3, -5,  6, -1,-17},
    { -2, -9, -2,  2,-14,  1,  8, -4, -5, -5, -9, -4, -7,-14, -5, -4, -6,-17, -8, -6,  1, -7,  6, -1,-17},
    { -2, -9, -3, -3, -9, -7, -4,  6, -9,-11,-10, -7, -8, -9, -6, -2, -6,-15,-14, -5, -3,-10, -5, -1,-17},
    { -7, -2,  0, -4, -7,  1, -5, -9,  9, -9, -6, -6,-10, -6, -4, -6, -7, -7, -3, -6, -1, -7, -1, -1,-17},
    { -5, -5, -5, -7, -6, -8, -5,-11, -9,  8, -1, -6, -1, -2, -8, -7, -2,-14, -6,  2, -6,  5, -6, -1,-17},
    { -6, -8, -7,-12,-15, -5, -9,-10, -6, -1,  7, -8,  1, -3, -7, -8, -7, -6, -7, -2, -9,  6, -7, -1,-17},
    { -7,  0, -1, -4,-14, -3, -4, -7, -6, -6, -8,  7, -2,-14, -6, -4, -3,-12, -9, -9, -2, -7, -4, -1,-17},
    { -5, -4, -9,-11,-13, -4, -7, -8,-10, -1,  1, -2, 11, -4, -8, -5, -4,-13,-11, -1,-10,  0, -5, -1,-17},
    { -8, -9, -9,-15,-13,-13,-14, -9, -6, -2, -3,-14, -4,  9,-10, -6, -9, -4,  2, -8,-10, -2,-13, -1,-17},
    { -2, -4, -6, -8, -8, -3, -5, -6, -4, -8, -7, -6, -8,-10,  8, -2, -4,-14,-13, -6, -7, -7, -4, -1,-17},
    {  0, -3,  0, -4, -3, -5, -4, -2, -6, -7, -8, -4, -5, -6, -2,  6,  0, -5, -7, -6, -1, -8, -5, -1,-17},
    { -1, -6, -2, -5, -8, -5, -6, -6, -7, -2, -7, -3, -4, -9, -4,  0,  7,-13, -6, -3, -3, -5, -6, -1,-17},
    {-13, -2, -8,-15,-15,-13,-17,-15, -7,-14, -6,-12,-13, -4,-14, -5,-13, 13, -5,-15,-10, -7,-14, -1,-17},
    { -8,-10, -4,-11, -4,-12, -8,-14, -3, -6, -7, -9,-11,  2,-13, -7, -6, -5, 10, -7, -6, -7, -9, -1,-17},
    { -2, -8, -8, -8, -6, -7, -6, -5, -6,  2, -2, -9, -1, -8, -6, -6, -3,-15, -7,  7, -8,  0, -6, -1,-17},
    { -3, -7,  6,  6,-12, -3,  1, -3, -1, -6, -9, -2,-10,-10, -7, -1, -3,-10, -6, -8,  6, -8,  0, -1,-17},
    { -6, -7, -6,-10, -9, -5, -7,-10, -7,  5,  6, -7,  0, -2, -7, -8, -5, -7, -7,  0, -8,  6, -6, -1,-17},
    { -3, -4, -3,  1,-14,  6,  6, -5, -1, -6, -7, -4, -5,-13, -4, -5, -6,-14, -9, -6,  0, -6,  6, -1,-17},
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-17},
    {-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,  1}
  }
};

static double kls_[8][16][5] = 
{
  // BLOSUM62 Karlin statistics
  {
    {11,  2,  0.297,  0.082,  0.27},
    {10,  2,  0.291,  0.075,  0.23},
    {12,  1,  0.283,  0.059,  0.19},
    {9,  2,  0.279,  0.058,  0.19},
    {8,  2,  0.264,  0.045,  0.15},
    {11,  1,  0.267,  0.041,  0.14},
    {10,  1,  0.243,  0.024,  0.10},
    {7,  2,  0.239,  0.027,  0.10},
    {6,  2,  0.201,  0.012,  0.061},
    {9,  1,  0.206,  0.010,  0.052},
    {MAX,  MAX,  0.318,  0.134,  0.401},
    {MAX,  MAX,  0.318,  0.134,  0.401},
    {MAX,  MAX,  0.318,  0.134,  0.401},
    {MAX,  MAX,  0.318,  0.134,  0.401},
    {MAX,  MAX,  0.318,  0.134,  0.401},
    {MAX,  MAX,  0.318,  0.134,  0.401}
  },
  // BLOSUM80 Karlin statistics
  {
    {25,  2,  0.342,  0.17,  0.66},
    {13,  2,  0.336,  0.15,  0.57},
    {9,  2,  0.319,  0.11,  0.42},
    {11,  1,  0.314,  0.095,  0.35},
    {8,  2,  0.308,  0.090,  0.35},
    {10,  1,  0.299,  0.071,  0.27},
    {7,  2,  0.293,  0.070,  0.27},
    {9,  1,  0.279,  0.048,  0.20},
    {6,  2,  0.268,  0.045,  0.19},
    {MAX,  MAX,  0.343,  0.177,  0.657},
    {MAX,  MAX,  0.343,  0.177,  0.657},
    {MAX,  MAX,  0.343,  0.177,  0.657},
    {MAX,  MAX,  0.343,  0.177,  0.657},
    {MAX,  MAX,  0.343,  0.177,  0.657},
    {MAX,  MAX,  0.343,  0.177,  0.657},
    {MAX,  MAX,  0.343,  0.177,  0.657}
  },
  // BLOSUM90 Karlin statistics
  {
    {9,  2,  0.310,  0.12,  0.46},
    {11,  1,  0.302,  0.093,  0.39},
    {8,  2,  0.300,  0.099,  0.39},
    {7,  2,  0.283,  0.072,  0.30},
    {10,  1,  0.290,  0.075,  0.28},
    {6,  2,  0.259,  0.048,  0.22},
    {9,  1,  0.265,  0.044,  0.20},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755},
    {MAX,  MAX,  0.335,  0.190,  0.755}
  },
  // BLOSUM50 Karlin statistics
  {
    {16,  2,  0.215,  0.066,  0.20},
    {13,  3,  0.212,  0.063,  0.19},
    {19,  1,  0.212,  0.57,  0.18},
    {15,  2,  0.210,  0.058,  0.17},
    {12,  3,  0.206,  0.055,  0.17},
    {18,  1,  0.207,  0.050,  0.15},
    {14,  2,  0.202,  0.045,  0.14},
    {11,  3,  0.197,  0.042,  0.14},
    {17,  1,  0.198,  0.037,  0.12},
    {13,  2,  0.193,  0.035,  0.12},
    {10,  3,  0.186,  0.031,  0.11},
    {16,  1,  0.186,  0.025,  0.10},
    {12,  2,  0.181,  0.025,  0.095},
    {9,  3,  0.172,  0.022,  0.082},
    {15,  1,  0.171,  0.015,  0.063},
    {MAX,  MAX,  0.232,  0.112,  0.336}
  },
  // BLOSUM45 Karlin statistics
  {
    {13,  3,  0.207,  0.049,  0.14},
    {16,  2,  0.210,  0.051,  0.14},
    {15,  2,  0.203,  0.041,  0.12},
    {19,  1,  0.205,  0.040,  0.11},
    {12,  3,  0.199,  0.039,  0.11},
    {18,  1,  0.198,  0.032,  0.10},
    {14,  2,  0.195,  0.032,  0.10},
    {11,  3,  0.190,  0.031,  0.095},
    {13,  2,  0.185,  0.024,  0.084},
    {17,  1,  0.189,  0.024,  0.078},
    {10,  3,  0.179,  0.023,  0.075},
    {16,  1,  0.176,  0.016,  0.063},
    {12,  2,  0.171,  0.016,  0.061},
    {MAX,  MAX,  0.229,  0.092,  0.251},
    {MAX,  MAX,  0.229,  0.092,  0.251},
    {MAX,  MAX,  0.229,  0.092,  0.251} 
  },
  // PAM250 Karlin statistics
  {
    {15,  3,  0.205,  0.049,  0.13},
    {17,  2,  0.204,  0.047,  0.12},
    {14,  3,  0.200,  0.043,  0.12},
    {21,  1,  0.204,  0.045,  0.11},
    {16,  2,  0.198,  0.038,  0.11},
    {20,  1,  0.199,  0.037,  0.10},
    {13,  3,  0.194,  0.036,  0.10},
    {15,  2,  0.191,  0.031,  0.087},
    {12,  3,  0.186,  0.029,  0.085},
    {19,  1,  0.192,  0.029,  0.083},
    {14,  2,  0.182,  0.024,  0.073},
    {18,  1,  0.183,  0.021,  0.070},
    {11,  3,  0.174,  0.020,  0.070},
    {13,  2,  0.171,  0.017,  0.059},
    {17,  1,  0.171,  0.014,  0.052},
    {MAX,  MAX,  0.218,  0.0877,  0.287}
  },
  // PAM70 Karlin statistics
  {
    {10,  1,  0.309,  0.15,  0.88},
    {7,  2,  0.305,  0.15,  0.87},
    {6,  2,  0.287,  0.11,  0.68},
    {9,  1,  0.294,  0.11,  0.61},
    {5,  2,  0.264,  0.079,  0.45},
    {8,  1,  0.270,  0.072,  0.40},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82},
    {MAX,  MAX,  0.336,  0.277,  1.82}
  },
  // PAM30 Karlin statistics
  {
    {8,  2,  0.301,  0.12,  0.54},
    {11,  1,  0.305,  0.12,  0.52},
    {7,  2,  0.286,  0.093,  0.43},
    {10,  1,  0.291,  0.91,  0.41},
    {6,  2,  0.264,  0.064,  0.29},
    {9,  1,  0.270,  0.060,  0.28},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11},
    {MAX,  MAX,  0.328,  0.222, 1.11}
  }
};

enum MatrixName {BLOSUM62, BLOSUM80, BLOSUM90, BLOSUM50, BLOSUM45, PAM250, PAM70, PAM30}; 

class ScoringProt {
 public:
  friend class AlignBatch;
  friend class SequenceSearch;
  explicit ScoringProt(const enum MatrixName mx, const int gap_open, const int gap_ext) {
    switch(mx)  {
      case BLOSUM62: mx_idx_ = 0; break;
      case BLOSUM80: mx_idx_ = 1; break;
      case BLOSUM90: mx_idx_ = 2; break;
      case BLOSUM50: mx_idx_ = 3; break;
      case BLOSUM45: mx_idx_ = 4; break;
      case PAM250: mx_idx_ = 5; break;
      case PAM70: mx_idx_ = 6; break;
      case PAM30: mx_idx_ = 7; break;
      default: std::cout << "Error: ScoringProt::ScoringProt: Unsupported scoring matrix, abort." << std::endl; exit(1);
    }
    gap_open_ = gap_open;
    gap_ext_ = gap_ext;
    GetKarlinStat();
  }
  ~ScoringProt(void) {}
  
  void GetKarlinStat(void)  {
    int i;
    for(i = 1; i < 16; ++ i)  {
      if(gap_open_ == -kls_[mx_idx_][i][0] && gap_ext_ == -kls_[mx_idx_][i][1])  {
        kls_k_ = kls_[mx_idx_][i][3];
        kls_lambda_ = kls_[mx_idx_][i][2];
        return;
      }
    }
    std::cout << "Error: ScoringProt::GetKarlinStat: gap open and extension parameter combination not supported, supported are" << std::endl;
    std::cout << "(gap_open,gap_extension)" << std::endl;
    for(i = 1; i < 16; ++ i)  { 
      std::cout << "(" << -kls_[mx_idx_][i][0] << "," << -kls_[mx_idx_][i][1] << ")" << std::endl;
    }
    std::cout << "Please re-run Search by choosing one of the allowed combinations. Abort." << std::endl;
    exit(1);
    return;
  }
  
  inline int GetMatchScore(const char a, const char b) {
    if(ch_[a] >= 0 && ch_[b] >= 0) return sc_[mx_idx_][ch_[a]][ch_[b]];
    return -MAX;
  }
  
  inline double GetAveDiagScore(void) {
    int sum = 0;
    for(int i = 0; i < 25; ++ i) {
      sum += sc_[mx_idx_][i][i];
    }
    return sum / 25;
  }
  
  inline double GetMaxScore(const std::string &s) {
    int sum = 0;
    for(int i = 0; i < s.length(); ++ i) {
      if(ch_[s[i]] >= 0 )  sum += sc_[mx_idx_][ch_[s[i]]][ch_[s[i]]];
      else {
        std::cout << "Error: ScoringProt::ComputeMaxScore: unrecognized character found in string: \'" << s[i] << "\', abort."  << std::endl;
        exit(0);
      }
    }
    return sum;
  }
  
  inline double GetMaxScore(const std::string &s, const std::string &t) {
    std::string m = s.length() < t.length() ? s : t;
    int sum = 0;
    for(int i = 0; i < m.length(); ++ i) {
      if(ch_[s[i]] >= 0 )  sum += sc_[mx_idx_][ch_[m[i]]][ch_[m[i]]];
      else {
        std::cout << "Error: ScoringProt::ComputeMaxScore: unrecognized character found in string: \'" << s[i] << "\', abort."  << std::endl;
        exit(0);
      }
    }
    return sum;
  }
  
  int ComputeMatchingScore(const std::string &s1, const std::string &s2)  {
    if(s1.length() != s2.length()) {
      std::cout << "Warning: ScoringProt::ComputeMatchingScore: strings have different lengths!" << std::endl;
      return 0;
    }
    int sum = 0;
    for(int i = 0; i < s1.length(); ++ i) {
      if(ch_[s1[i]] >= 0 && ch_[s2[i]] >= 0)  sum += sc_[mx_idx_][ch_[s1[i]]][ch_[s2[i]]];
      else return -MAX;
    }
    return sum;
  }
  
  int ComputeMatchingScore(
      const std::string &s1, const int i1, 
      const std::string &s2, const int i2, 
      const int len
  )  {
    if(i1 + len > s1.length() || i2 + len > s2.length())  {
      std::cout << "Error: ScoringProt::ComputeMatchingScore: index out of boundary!" << std::endl;
      std::cout << s1.length() << "   " << i1 << " " << s1.length() << " " << i2 << std::endl;
      exit(1);
    }
    int sum = 0;
    for(int i = 0; i < len; ++ i) {
      if(ch_[s1[i1 + i]] >= 0 && ch_[s2[i2 + i]] >= 0)  
        sum += sc_[mx_idx_][ch_[s1[i1 + i]]][ch_[s2[i2 + i]]];
      else return -MAX;
    }
    return sum;
  } 
  
  int ComputeMatchingScoreExtend(
      const std::string &s1, const std::string &s2,
      const int drop_off, int &q1, int &q2, int &t1, int &t2
  )  {
    if(q2 >= s1.length() || t2 >= s2.length() || q2 - q1 != t2 - t1)  {
      std::cout << "Error: ScoringProt::ComputeMatchingScoreExtend: index out of boundary!" << std::endl;
      exit(1);
    }
    
    while(sc_[mx_idx_][ch_[s1[q1]]][ch_[s2[t1]]] < 0) {
      ++ q1; ++ t1;
      if(q1 > q2) break; 
    }
    while(sc_[mx_idx_][ch_[s1[q2]]][ch_[s2[t2]]] < 0) {
      -- q2; --t2;
      if(q2 < q1) break; 
    }
    int sum = 0;
    for(int i = 0; i <= q2 - q1; ++ i) {
      sum += sc_[mx_idx_][ch_[s1[q1 + i]]][ch_[s2[t1 + i]]];
    }
    
    int max_score = sum;
    int max_q1 = q1, max_t1 = t1, max_q2 = q2, max_t2 = t2;
    // extend to the left
    --q1; --t1;
    while(q1 >= 0 && t1 >= 0 && sum + drop_off >= max_score) {
      //std::cout << "!2: " << sc_[mx_idx_][ch_[s1[q1]]][ch_[s2[t1]]] << std::endl;
      sum += sc_[mx_idx_][ch_[s1[q1]]][ch_[s2[t1]]];
      if(sum >= max_score)  {
        max_score = sum; max_q1 = q1; max_t1 = t1;
      }
      -- q1; -- t1;
    }
    sum = max_score; q1 = max_q1; t1 = max_t1;
    // extend to the right
    ++ q2; ++ t2;
    while(q2 < s1.length() && t2 < s2.length() && sum + drop_off >= max_score) {
      //std::cout << "!3: " << sc_[mx_idx_][ch_[s1[q2]]][ch_[s2[t2]]] << std::endl;
      sum += sc_[mx_idx_][ch_[s1[q2]]][ch_[s2[t2]]];
      if(sum >= max_score)  {
        max_score = sum; max_q2 = q2; max_t2 = t2;
      }
      ++ q2; ++ t2;
    }
    sum = max_score; q2 = max_q2; t2 = max_t2;
    return sum;
  } 
  
  int ComputeCutoff(const long int m, const long int n, const double e_value) {
    if(m <= 0 || n <= 0) {
      std::cout << "Error: ScoringProt::ComputeCutoff: input database sizes are negative! Abort" << std::endl;
      exit(1);
    }
    return static_cast<int>((log(kls_k_) + log(m) + log (n) - log(e_value)) / kls_lambda_);
  }
  

  double ComputeBitScore(const int s)  {
    double bit_s = (kls_lambda_ * (double) s - log(kls_k_)) / log(2);
    return bit_s;
  }


  double ComputeEValue(const int m, const int n, const int s) {
    double e_value = kls_k_ * m * n * exp(-kls_lambda_ * s);
    return e_value;
  }

  
 private:
  int mx_idx_;
  int gap_open_;
  int gap_ext_;
  double kls_k_;
  double kls_lambda_;
};

#endif