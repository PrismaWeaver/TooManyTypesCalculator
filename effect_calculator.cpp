#include<array>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath> 

class effect_calculator {
private:
    double atkChart[60][60] = {
        //normal
        {1, 1, 1, 1, 1, 0.5, 1, 0, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 0}, 
        //fighting
        {2, 1, 0.5, 0.5, 1, 2, 0.5, 0, 2, 1, 1, 1, 1, 1, 0.5, 2, 1, 2, 0.5, 0.5, 2, 2, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 0.5, 1, 1, 0, 1, 0.5, 1, 2, 2, 0.5, 2, 2, 1, 1, 0}, 
        //flying
        {1, 2, 1, 1, 1, 0.5, 2, 1, 0.5, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 2, 2, 1, 0.5, 1, 0}, 
        //poison
        {1, 1, 1, 0.5, 0.5, 0.5, 1, 0.5, 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 1, 0.5, 1, 0.5, 1, 1, 1, 2, 0.5, 1, 2, 2, 1, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 0.5, 0.5, 1, 0.5, 1, 0.5, 1, 1, 2, 1, 1, 1, 0}, 
        //ground
        {1, 1, 0, 2, 1, 2, 0.5, 1, 2, 1, 2, 1, 0.5, 2, 1, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0.5, 1, 2, 0.5, 1, 0.5, 0.5, 1, 2, 1, 0}, 
        //rock
        {1, 0.5, 2, 1, 0.5, 1, 2, 1, 0.5, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 0}, 
        //bug
        {1, 0.5, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 0.5, 1, 2, 1, 2, 1, 1, 2, 0.5, 1, 1, 2, 1, 1, 1, 0.5, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0}, 
        //ghost
        {0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 0.5, 0, 1, 0, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 0.5, 0.5, 1, 1, 0.5, 1, 0, 1, 1, 1, 1, 1, 2}, 
        //steel
        {1, 1, 1, 1, 1, 2, 1, 1, 0.5, 1, 0.5, 0.5, 1, 0.5, 1, 2, 1, 1, 2, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 0.5, 2, 1, 1, 1, 1, 0.5, 1, 2}, 
        //mystery
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}, 
        //fire
        {1, 1, 1, 1, 1, 0.5, 2, 1, 2, 1, 0.5, 0.5, 2, 1, 1, 2, 0.5, 1, 1, 2, 2, 2, 1, 1, 0.5, 1, 0.5, 1, 2, 1, 2, 0.5, 2, 1, 2, 1, 0.5, 1, 1, 2, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 1, 0.5, 0, 2, 1, 1, 0.5, 2, 1, 0.5, 0}, 
        //water
        {1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 0.5, 1, 1, 2, 1, 2, 1, 1, 0.5, 0.5, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 2, 0.5, 2, 2, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 2, 1, 1, 0}, 
        //grass
        {1, 1, 0.5, 0.5, 2, 2, 0.5, 1, 0.5, 1, 0.5, 2, 0.5, 1, 1, 1, 0.5, 1, 1, 2, 0.5, 2, 1, 1, 2, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 1, 1, 1, 1, 0}, 
        //electric
        {1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 0.5, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 0, 0.5, 1, 1, 2, 1, 0.5, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 0, 0.5, 0.5, 2, 1, 2, 0.5, 2, 0.5, 1, 1, 1, 0.5, 1, 0.5, 0.5, 0}, 
        //psychic
        {1, 2, 1, 2, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 0.5, 1, 1, 0, 1, 1, 2, 2, 0.5, 0.5, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 0.5, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0}, 
        //ice
        {1, 1, 2, 1, 2, 1, 1, 1, 0.5, 1, 0.5, 0.5, 2, 1, 1, 0.5, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 1, 0.5, 0, 1, 0.5, 0.5, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 0}, 
        //dragon
        {1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 0.5, 1, 1, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 2, 2, 1, 1, 2, 2, 0.5, 0.5, 0}, 
        //dark
        {1, 0.5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 0.5, 0.5, 1, 2, 0, 1, 1, 2, 1, 0, 1, 0.5, 2, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 0, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 2}, 
        //fairy
        {1, 2, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 2, 2, 2, 0.5, 2, 1, 1, 1, 0.5, 1, 1, 2, 0.5, 1, 1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 0}, 
        //monkey
        {2, 2, 0.5, 0.5, 1, 1, 2, 0.5, 0.5, 1, 0.5, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 0.5, 0.5, 2, 1, 2, 1, 2, 1, 1, 1, 0.5, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 2, 2, 1, 2, 0.5, 1, 0}, 
        //angry
        {1, 0.5, 0.5, 2, 2, 2, 2, 0.5, 0.5, 1, 2, 0.5, 1, 2, 2, 2, 1, 2, 0.5, 1, 2, 2, 1, 2, 0.5, 2, 0.5, 1, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 1, 1, 1, 2, 0.5, 2, 2, 2, 0.5, 2, 1, 1, 2, 0.5, 2, 1, 1, 0.5, 1, 0.5, 2, 1, 2}, 
        //baby
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0}, 
        //friend
        {1, 2, 1, 0.5, 1, 0.5, 2, 2, 0.5, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 0.5, 2, 2, 2, 2, 0.5, 1, 0.5, 1, 1, 0.5, 0.5, 1, 1, 2, 0.5, 1, 2, 0.5, 1, 2, 1, 0, 1, 2, 0.5, 1, 0.5, 0.5, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 2, 2}, 
        //guys
        {1, 2, 1, 0.5, 1, 1, 1, 0, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 0.5, 0.5, 1, 2, 2, 0, 0.5, 2, 2, 1, 1, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2}, 
        //liquid
        {1, 2, 2, 0, 2, 2, 2, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 0, 1, 2, 1, 0.5, 0.5, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 0}, 
        //vibe
        {2, 0.5, 1, 0.5, 1, 1, 2, 2, 2, 1, 1, 2, 2, 1, 0.5, 1, 1, 1, 0.5, 1, 0.5, 2, 2, 2, 1, 0.5, 0.5, 2, 1, 0.5, 0.5, 2, 1, 2, 0.5, 0.5, 0.5, 0, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 0.5, 1, 2, 0.5, 0.5, 2, 1, 1, 0.5, 1, 0.5, 0}, 
        //song
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5, 0.5, 1, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 0.5, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 0}, 
        //space
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 0.5, 2, 1, 2, 1, 2, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 2, 0.5, 1, 1, 0.5, 1, 0}, 
        //fluffy
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
        //sus
        {2, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 2, 1, 2, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 2, 1, 1, 1, 1, 0.5, 2}, 
        //furry
        {0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 0.5, 2, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 2, 0.5, 2, 1, 1, 1, 1, 1, 2, 2, 0.5, 1, 2, 1, 1, 0.5, 0}, 
        //bad
        {2, 0.5, 1, 0.5, 1, 0.5, 1, 1, 0.5, 1, 2, 1, 2, 2, 0.5, 1, 1, 2, 0.5, 1, 1, 2, 0.5, 1, 1, 2, 1, 1, 1, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 0.5, 2, 1, 2, 1, 2, 1, 2}, 
        //ancient
        {1, 2, 1, 1, 2, 2, 1, 2, 2, 1, 1, 1, 0.5, 0.5, 1, 0.5, 2, 1, 1, 2, 1, 2, 1, 1, 1, 2, 0.5, 2, 1, 1, 1, 1, 0.5, 1, 2, 2, 2, 1, 1, 0, 0.5, 1, 1, 0, 1, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 0.5, 1, 0}, 
        //silly 
        {1, 1, 1, 2, 1, 0.5, 0.5, 0.5, 1, 1, 1, 2, 2, 1, 0.5, 1, 2, 2, 1, 2, 2, 2, 0.5, 0, 2, 1, 2, 1, 0.5, 0.5, 0.5, 1, 0.5, 2, 2, 0.5, 1, 2, 1, 1, 2, 1, 1, 0.5, 1, 1, 2, 1, 0.5, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 0}, 
        //stinky
        {1, 1, 2, 0.5, 0.5, 0.5, 1, 0.5, 0, 1, 1, 1, 1, 1, 2, 1, 2, 1, 0.5, 0, 2, 2, 2, 2, 1, 2, 1, 2, 0.5, 0.5, 0, 0.5, 2, 2, 0.5, 0.5, 1, 2, 1, 0.5, 1, 2, 1, 2, 0, 0.5, 0.5, 2, 1, 1, 2, 0.5, 2, 1, 1, 1, 2, 1, 1, 0}, 
        //sharp
        {2, 1, 2, 1, 1, 0.5, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 0.5, 1, 1, 0.5, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 0.5, 1, 1, 0.5, 1, 2, 0.5, 1, 1, 1, 1, 2}, 
        //magic
        {2, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 0.5, 1, 2, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 2, 0.5, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 1, 2, 2, 1, 0.5, 2, 1, 0, 0.5, 2, 2, 2, 1, 2, 1, 0}, 
        //gender
        {2, 0.5, 1, 0.5, 1, 1, 2, 2, 0.5, 1, 0.5, 2, 2, 1, 0.5, 1, 2, 2, 0.5, 2, 1, 2, 0.5, 1, 2, 2, 0.5, 1, 0.5, 0.5, 1, 2, 2, 2, 0.5, 1, 2, 2, 1, 1, 1, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 2, 0.5, 2, 1, 1, 1, 1, 1, 0}, 
        //little
        {1, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0.5, 1, 0, 1, 2, 0}, 
        //crab
        {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 2, 2, 2, 1, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 0}, 
        //dream
        {1, 1, 1, 1, 1, 0.5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 0.5, 0.5, 0.5, 1, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 0},
         //right
        {2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 4, 0.5, 2, 1, 0.5, 1, 1, 1, 1, 0.5, 0.5, 1, 0.5, 1, 1, 0.5, 2, 1, 1, 0.5, 1, 0.5, 1, 0.5, 1, 1, 2, 0.5, 0.5, 1, 2, 2, 2, 1, 2, 1, 0.5, 1, 0},
         //left
        {1, 0.5, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 0.5, 1, 1, 1, 2, 0.5, 2, 1, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 0.5, 2, 1, 1, 0.5, 0.5, 1, 0.5, 1, 1, 1, 1, 1, 2, 1, 0.5, 2, 1, 0.5, 0.5, 0.5, 1, 1, 0},
         //zoomer
        {1, 0.5, 1, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 0.5, 2, 0.5, 2, 2, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 0.5, 2, 1, 0.5, 0.5, 2, 1, 2, 1, 0.5, 2, 2, 2, 0.5, 1, 2, 1, 2, 1, 2, 0.5, 0.5, 1, 1, 2, 1, 1, 1, 2},
         //gamer
        {0.5, 0.5, 1, 2, 1, 1, 2, 1, 1, 1, 1, 0.5, 0, 0.5, 1, 1, 1, 2, 0.5, 1, 2, 2, 0.5, 2, 0.5, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 0.5, 1, 1, 0.5, 1, 1, 1, 2, 1, 2, 2, 1, 1, 1, 1, 0.5, 2, 1, 0.5, 0.5, 1, 2, 1, 0.5, 1, 2},
         //dance
        {1, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 1, 1, 0.5, 0.5, 1, 0.5, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 0.5, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 1, 2, 1, 1, 2, 0},
         //boring
        {1, 0.5, 1, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 2, 0.5, 0.5, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 0.5, 1, 1, 0},
         //ugly
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 2, 1, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 2, 2, 1, 0.5, 0.5, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 0.5, 1, 1, 0},
         //gun
        {1, 2, 0.5, 1, 1, 0.5, 1, 0.5, 0.5, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 1, 0.5, 1, 2, 0.5, 1, 2, 1, 1, 0.5, 1, 0.5, 1, 1, 0, 2, 1, 1, 1, 2, 1, 1, 1, 1, 0.5, 2, 1, 0.5, 1, 1, 1, 1, 0},
         //pikachu
        {1, 1, 0, 1, 2, 1, 1, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 0.5, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 0, 0.5, 1, 1, 2, 1, 0.5, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 0, 0.5, 0.5, 2, 1, 2, 0.5, 2, 0.5, 1, 1, 1, 0.5, 1, 0.5, 0.5, 0},
         //prime
        {1, 0.5, 1, 1, 2, 1, 1, 1, 0.5, 1, 1, 2, 1, 2, 1, 1, 1, 0.5, 2, 1, 1, 2, 2, 2, 0.5, 2, 1, 1, 1, 0.5, 1, 1, 0, 2, 1, 1, 0.5, 1, 1, 2, 1, 1, 1, 2, 2, 1, 2, 2, 0.5, 2, 2, 1, 0.5, 1, 1, 1, 1, 1, 1, 2},
         //ohio
        {2, 1, 0.5, 2, 1, 1, 1, 2, 1, 1, 0.5, 1, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0.5, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 0},
         //deez nuts
        {1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 2, 1, 2, 1, 1, 1, 1, 0.5, 1, 0.5, 0.5, 1, 1, 0.5, 0.5, 1, 0.5, 1, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 0.5, 1, 2, 1, 1, 2, 1, 1, 1, 0},
         //normal 2
        {2, 1, 1, 1, 1, 0.5, 1, 0, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 2},
         //bean
        {1, 1, 1, 2, 2, 2, 1, 1, 0.5, 1, 0.5, 1, 2, 1, 1, 0.5, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 0.5, 0.5, 1, 0.5, 1, 0.5, 2, 0.5, 1, 1, 2, 1, 0.5, 1, 1, 1, 1, 2, 1, 0.5, 0.5, 1, 1, 1, 2, 2, 1, 1, 0, 0.5, 1, 1, 1, 0},
         //boomer
        {1, 0.5, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 0.5, 1, 0.5, 1, 0.5, 1, 1, 2, 1, 1, 1, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 0.5, 1, 0.5, 0.5, 1, 1, 1, 2, 0.5, 0.5, 0.5, 2, 2, 2, 2, 1, 0.5, 1, 1, 1, 2, 1, 0.5, 1, 1, 0},
         //smash
        {1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 2, 0.5, 0.5, 0.5, 0.5, 1, 1, 0.5, 0, 1, 1, 0.5, 1, 1, 0.5, 1, 0.5, 0.5, 1, 1, 1, 1, 2, 1, 0.5, 1, 1, 1, 2, 2},
         //OU
        {1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 0},
         //ball
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 0.5, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 0.5, 1, 1, 2, 1, 1, 2, 0},
         //sans
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}
    };
    double defChart[60][60];

public:
    effect_calculator() {
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                defChart[j][i] = atkChart[i][j];
            }
        }
    }

    std::array<double, 60> offense(int type) {
        std::array<double, 60> result;
        if (type == 60 || type == 61) {
            std::fill(begin(result), end(result), 1);
            return result;
        }
        for (int i = 0; i < 60; i++) result[i] = atkChart[type][i];
        return result;
    }

    std::array<double, 60> monoType(int type) {
        std::array<double, 60> result;
        if (type == 60 || type == 61) {
            std::fill(begin(result), end(result), 1);
            return result;
        }
        for (int i = 0; i < 60; i++) result[i] = defChart[type][i];
        return result;
    }

    std::array<double, 60> dualType(int type1, int type2) {
        std::array<double, 60> result;
        if (type1 == 60 || type2 == 60) {
            if (type1 == 60) for (int i = 0; i < 60; i++) result[i] = 1 / defChart[type2][i];
            else for (int i = 0; i < 60; i++) result[i] = 1 / defChart[type1][i];
        }
        else if (type1 == 61 || type2 == 61) {
            if (type1 == 61) for (int i = 0; i < 60; i++) result[i] = pow(defChart[type2][i], 2);
            else for (int i = 0; i < 60; i++) result[i] = pow(defChart[type1][i], 2);
        }
        else {
            for (int i = 0; i < 60; i++) result[i] = defChart[type1][i] * defChart[type2][i];
        }
        return result;
    }

    std::array<double, 60> tripleType(int type1, int type2, int type3) {
        std::array<double, 60> result;
        if (type1 == 60 || type2 == 60 || type3 == 60) {
            if (type1 == 60) for (int i = 0; i < 60; i++) result[i] = defChart[type2][i] / defChart[type3][i];
            else if (type2 ==60) for (int i = 0; i < 60; i++) result[i] = defChart[type1][i] / defChart[type3][i];
            else for (int i = 0; i < 60; i++) result[i] = defChart[type1][i] / defChart[type2][i];
        }
        else if (type1 == 61 || type2 == 61 || type3 == 61) {
            if (type1 == 61) for (int i = 0; i < 60; i++) result[i] = pow(defChart[type2][i] * defChart[type3][i], 2);
            else if (type2 ==61) for (int i = 0; i < 60; i++) result[i] = pow(defChart[type1][i] * defChart[type3][i], 2);
            else for (int i = 0; i < 60; i++) result[i] = pow(defChart[type1][i] * defChart[type2][i], 2);
        }
        else {
            for (int i = 0; i < 60; i++) result[i] = defChart[type1][i] * defChart[type2][i] * defChart[type3][i];
        }
        return result;
    }
};

int typeToInt(std::string type) {
    std::string types[62] = {"NORMAL", "FIGHTING", "FLYING", "POISON", "GROUND", "ROCK", "BUG", "GHOST", "STEEL", "MYSTERY", "FIRE", "WATER", "GRASS", "ELECTRIC", "PSYCHIC", "ICE", "DRAGON", "DARK", "FAIRY", "MONKEY", "ANGRY", "BABY", "FRIEND", "GUYS", "LIQUID", "VIBE", "SONG", "SPACE", "FLUFFY", "SUS", "FURRY", "BAD", "ANCIENT", "SILLY", "STINKY", "SHARP", "MAGIC", "GENDER", "LITTLE", "CRAB", "DREAM", "RIGHT", "LEFT", "ZOOMER", "GAMER", "DANCE", "BORING", "UGLY", "GUN", "PIKACHU", "PRIME", "OHIO", "DEEZNUTS", "NORMAL2", "BEAN", "BOOMER", "SMASH", "OU", "BALL", "SANS", "REVERSE", "TYPE"};
    transform(type.begin(), type.end(), type.begin(), ::toupper);
    for (int i = 0; i < 62; i++) {
        if (type == types[i]) return i;
    }
    return -1;
}

template<typename C, typename T>
bool contains(C&& c, T e) { 
    return std::find(std::begin(c), std::end(c), e) != std::end(c);
};

void display(std::array<double, 60> effectiveness) {
    std::string types[62] = {"NORMAL", "FIGHTING", "FLYING", "POISON", "GROUND", "ROCK", "BUG", "GHOST", "STEEL", "MYSTERY", "FIRE", "WATER", "GRASS", "ELECTRIC", "PSYCHIC", "ICE", "DRAGON", "DARK", "FAIRY", "MONKEY", "ANGRY", "BABY", "FRIEND", "GUYS", "LIQUID", "VIBE", "SONG", "SPACE", "FLUFFY", "SUS", "FURRY", "BAD", "ANCIENT", "SILLY", "STINKY", "SHARP", "MAGIC", "GENDER", "LITTLE", "CRAB", "DREAM", "RIGHT", "LEFT", "ZOOMER", "GAMER", "DANCE", "BORING", "UGLY", "GUN", "PIKACHU", "PRIME", "OHIO", "DEEZNUTS", "NORMAL2", "BEAN", "BOOMER", "SMASH", "OU", "BALL", "SANS", "REVERSE", "TYPE"};
    if (contains(effectiveness, 16)) {
        std::cout << "x16 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 16) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 8)) {
        std::cout << "x8 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 8) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 4)) {
        std::cout << "x4 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 4) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 2)) {
        std::cout << "x2 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 2) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 0.5)) {
        std::cout << "x0.5 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 0.5) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 0.25)) {
        std::cout << "x0.25 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 0.25) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 0.125)) {
        std::cout << "x0.125 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 0.125) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 0.0625)) {
        std::cout << "x0.0625 effectiveness:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 0.0625) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    if (contains(effectiveness, 0)) {
        std::cout << "Immunity to:" << std::endl;
        for (int i = 0; i < 60; i++) if (effectiveness[i] == 0) std::cout << types[i] << ", ";
        std::cout << "\n" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

main(int argc, char* argv[]) {
    effect_calculator calc;
    bool cont = true;
    std::string response;
    int type1, type2, type3;
    while(cont) {
        std::cout << "Welcome to the 'Too Many Types' type-effectiveness calculator \n" <<
        "Please select one of the following options:\n" <<
        "1.) Determine what types an attack is strong/weak against\n" <<
        "2.) Determine the weakness of a mono-type pokemon\n" <<
        "3.) Determine the weakness of a dual-type pokemon\n" <<
        "4.) Determine the weakness of a triple-type pokemon\n" << 
        "5.) Exit the program\n" << std::endl;
        std::cin >> response;
        switch(stoi(response)){
            case 1:
                type1 = -1;
                while(type1 == -1) {
                    std::cout << "Please enter the type: " << std::endl;
                    std::cin >> response;
                    type1 = typeToInt(response);
                    if (type1 == -1) std::cout << "Please enter a valid type\n" << std::endl;
                }
                display(calc.offense(type1));
                break;
            case 2:
                type1 = -1;
                while(type1 == -1) {
                    std::cout << "Please enter the type: " << std::endl;
                    std::cin >> response;
                    type1 = typeToInt(response);
                    if (type1 == -1) std::cout << "Please enter a valid type\n" << std::endl;
                }
                display(calc.monoType(type1));
                break;
            case 3:
                type1 = type2 = -1;
                while(type1 == -1) {
                    std::cout << "Please enter the first type: " << std::endl;
                    std::cin >> response;
                    type1 = typeToInt(response);
                    if (type1 == -1) std::cout << "Please enter a valid type\n" << std::endl;
                }
                while(type2 == -1) {
                    std::cout << "Please enter the second type: " << std::endl;
                    std::cin >> response;
                    type2 = typeToInt(response);
                    if (type2 == -1) std::cout << "Please enter a valid type\n" << std::endl;
                }
                display(calc.dualType(type1, type2));
                break;
            case 4:
                type1 = type2 = type3 = -1;
                while(type1 == -1) {
                    std::cout << "Please enter the first type: " << std::endl;
                    std::cin >> response;
                    type1 = typeToInt(response);
                    if (type1 == -1) std::cout << "Please enter a valid type\n" << std::endl;
                }
                while(type2 == -1) {
                    std::cout << "Please enter the second type: " << std::endl;
                    std::cin >> response;
                    type2 = typeToInt(response);
                    if (type2 == -1) std::cout << "Please enter a valid type\n" << std::endl;
                }
                while(type3 == -1) {
                    std::cout << "Please enter the third type: " << std::endl;
                    std::cin >> response;
                    type3 = typeToInt(response);
                    if (type3 == -1) std::cout << "Please enter a valid type\n" << std::endl;
                }
                display(calc.tripleType(type1, type2, type3));
                break;
            case 5:
                cont = false;
                break;
            default:
                std::cout << "Please enter a valid option\n\n" << std::endl;
        }
    }
};
