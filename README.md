# CNIT 315 Project
This is our CNIT 315 project. To get started:
1. download and set up github desktop. You are going to need a github account https://desktop.github.com
2. go to github desktop app file->clone repository
3. select CNIT 315 under your projects
4. It will show you a list of projects you are added to. click CNIT 315
5. a folder containing the code should be downloaded to '<some folder>/Github/CNIT 315'
6. Open up the CNIT 315 folder. Do not move the Github or CNIT 315 folder!
7.  **Make sure you press 'fetch origin' before you make any edits to the code! This downloads any of your teammate's changes and prevents code conflicts!!!**
8. **Now any time any file is changed within the CNIT 315 folder, those changes will show up on the desktop app.**
9. **simply type in a description for those changes and press 'commit to master' each time you make changes to your project.**
10. **Make sure you also have to press 'publish' at the black bar to publish your changes to the cloud!!!**

# Game Plan
* We are programming Conway's game of Life 
* links: https://www.youtube.com/watch?v=ouipbDkwHWA   https://gamedevelopment.tutsplus.com/tutorials/creating-life-conways-game-of-life--gamedev-558
* The software will contain a multi dimensional array / Matrix to represent a grid. 
```c
     int grid[10][10] = {
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0,0,0}
     }
```
* We are using a random number generator for our api https://www.random.org/clients/http/
* We will store random number from the api into a linked list
* The random number generator will generate random starting positions
# Divison of Labor
The following positions are available but can change at any time
* api work: making a GET request to the api (easy)
* technical writing: writing all the papers and reports (easy)
* performance measuring: generating graphs about our software's performance (medium)
* backend logic: writing the logic for the program (hard)
* displaying: displaying the results from the backend (hard)