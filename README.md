# Prismforce-coding-assesment

## Problem statement 

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by
different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11
circles to reach Pandavas army back.
Given:
Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11
powers
Abhmanyu start from the innermost circle with p power
Abhimanyu has a boon to skip fighting enemy a times
Abhmanyu can recharge himself with power b times
Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. If
Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
k3 and k7 enemies are endured with power to regenerate themselves once with half of their
initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle
Write an algorithm to find if Abhimanyu can cross the Chakravyuh and test it with two sets of
test cases.

## Solution 

```sh
Inputs: 
- abhimanyuPower = initial power of abhimanyu
- skips = no of skips allowed for abhimanyu
- regenerates = no of times abhimanyu is allowed to regenerate his power to initial
- monster = an array of integers that contains power of the monsters in chakravyuh
```

- Used Dynamic programming approach to manage 3 states: the current monster, no of skips, no of regenerates.
- The 3d dp array will store the maximum power abhimanyu has left with him after fighting the current monster with number of skips and regenerates left.
- Base case: Will check if abhimanyuh crossed the last circle then return true.
- Logic:
  - if current monsters power is strictly greater than current abhimanyuh's power, then there are two cases
    - abhimanyu skips the monster, again there we will be handling k3 and k7 monsters
    - abhimanyu regenerates himself to initial power
  - else we will fight the monster and update the states of dp accordingly
- return the power left with him after fighting last monster

## Output
If power left is positive then we will output `YES` else output `NO`.

## Testcases
There are 4 testcases tc1.txt, tc2.txt, tc3.txt, tc4.txt and the answers for respective testcases is in the commit message.
