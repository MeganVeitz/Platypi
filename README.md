# Platypi
Final Project consisting of Platypi evolving, mutating, and fighting off predators in their own world, for FRCC CSC_160 C++


## Foreground
This assignment is a continuation of Lab 8.
In Lab 8, you developed a class called platypus and tested it to ensure that it functions properly. 
In this lab, you will use that class in an environmental simulation.  

## Background
Mr. Burns does not care about almost anything ... but himself and his money. 
So, when his power plant leaked radioactive gooo that caused several species of wildlife to go extinct, he was only concerned with the public perception as it might affect his income and possible jail time. 
After the appearance of the three-eyed fish, Blinky, other rumors surfaced around the Springfield Nuclear Power Plant. 
One of them is high concern over the mutation rate of the rare Springfield molted platypus. 
With barely more than 50 left in the wild, the word "extinction" has been tossed around. 
So, to quell the media, Mr. Burns had 30 of them captured, dissected, and analysed to check for signs of mutation. 
(Incidentally, Burns had 10 more caputured for dinner and to make hats out of. It turns out that Platypuses indeed make good hats.)
He found that the mutation rate is 2% each month, but when they do mutate, they become sterile and cannot reproduce. 
With this information, he wants to create one of those newfangled computer simulations that the press loves so much. 
That's where you come in!

## Here's the general idea: 
Your main function will instantiate a world object by representing a 10 by 10 environment with an initial population of 25 platypuses1 and 2 predators. To ensure that the world is functioning properly, you will print the world map. Then, you will tell it to run through a single month, reporting all actions that happen. Finally, you will print the world map again.Now, after the above (making sure the world works), your program (main) will run a simulation of the world several times using differing mutation rates in order to determine the rate that will ensure the survivability of platypuses at least 36 months. You will call the world's simulation function 100 times. This function will use a mutation rate of 2% and calculate the average number of months to platypus extinction. It will then do the same with rate of 3%, then 4%, and so on. The ultimate goal of this whole simulation is to report the greatest mutation rate that still ensures the population survives at st 36 months. (What this tells Burns is how much goo he can dump while keeping the critters alive at least 36 months!) 

## Overall
Your program (main) will go through two very distinct phases of operation. First, it will create a world object and initialize it. Then, it will print the world. It will tell the world to step through one month of operation. It will print the world again to show the changes. This phase is simply to show that the world is functioning properly. The second phase will be the simulation phase from which Burns learns valuable information about platypuses, the Springfield city council, federal law, how to lie to the public, and most of all statistics. Beginning with a mutation rate of 2%, your program will call the simulate function (as described above) 100 times and average the number of months to extinction. It will repeat this process with rate 3%, then again 4%, .... until the average months to extinction is less than 36. It then prints the highest mutation rate that resulted in an average time to extinction greater than or equal to 36 months. This is what Burns needs to know so that he can maximize his goo dumping protocol and keep the feds, town council, and local vocals off his back. Note: the max number of months to extinction should be set to 60. Your program should not print anything in this second phase except the final Burns-desirable mutation rate!!!!! Do not have it print the world or anything else!! Notes: 
- Predators do not hunt eggs. 
- If a predator lands on the other predator and a platypus, the predator hunts the other predator only. 
- The order of things happening is hatch, do stuff, predators hunt, age 
- A predator hunts only after stepping onto a platypus. In fact, predators follow this order of motion: 
  - Move 
  - Hunt predator 
  - If no predator, hunt platypus 
  - If no platypus, do nothing 
