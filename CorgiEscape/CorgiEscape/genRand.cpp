//
//  genRand.cpp
//  Graphics Example
//
//  Created by ben jurenka on 7/8/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include "Control.h"

std::vector<int> Control::make_normal_random(std::size_t number,
                                       std::uint_fast32_t seed, const int MAX) {
    std::normal_distribution<double> normalDistr(0,1);
    std::minstd_rand generator(seed);
    std::vector<int> randNums;
    randNums.reserve(number);
    int n = 0;
    
    while(number--){
        n = normalDistr(generator) * 100;
        n = n % ( MAX  );
        if(n < 0){
            n *= -1;
        }
        randNums.push_back(n);
    }
  //  printf("Size of random = %d , Maz = %d ", number, MAX);
  //  for(int i = 0; i < 100; i++)
  //      printf(" %d ",randNums.at(i));
    
    return randNums;
}
