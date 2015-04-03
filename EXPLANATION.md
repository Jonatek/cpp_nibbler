//
// EXPLANATION.md
// version 3.1
//

=================================================================
=== QUESTION 1 ==================================================
=== How the program works ? =====================================
=================================================================

Basically :
    Nibbler -> Game -> Event/Snake/Map -> IGui

    -> Nibbler initialize our program (you can add more details)
    -> Game is our main class for our program

=================================================================
=== QUESTION 2 ==================================================
=== What is the Game class ? ====================================
=================================================================

- Game draw the map at the beginning and set Snake attributs x and y for
  his HEAD position (cf. QUESTION 4)

- Game modifies the Snake direction when modifying Event (move Event to
  Snake ?) when pressing ENTER first then LEFT or RIGHT

- When moving, Game will look at the future position of the Snake :
  Snake already know his HEAD position and his direction so he will also
  know where he is going to be (cf. QUESTION 5)

=================================================================
=== QUESTION 3 ==================================================
=== Why don't we need to know where each position (x, y) is ? ===
=================================================================

Here is a simple Map (caseX = 3, caseY = 3) and his corresponding case
for Map AND for Game (with Snake + IGui) :

     Map =  0 1 2    	   Game =  0,0 1,0 2,0
     	    3 4 5	   	   0,1 1,1 2,1
	    6 7 8		   0,2 1,2 2,2

Game doesn't need to know the if the position (1, 1) corresponds to the case 4.
Game will simply use the variable _map (of type Map) and call

      	  _map.getObject(x, y)

	  Prototype : ObjectType getObjectType(int x, int y)

For the position (1, 1) : _map.getObject(1, 1).

=================================================================
=== QUESTION 4 ==================================================
=== How can I display the Map ? =================================
=================================================================

Since Game know caseX and caseY (maximums for X and Y), we simply use a loop in
another loop where we will increment int x and int y then call the function
getObject(x, y) of Map to know what Game needs to draw.

     while (y < caseY)
     	   {
		while (x < caseX)
		{
			if (getObject(x, y) == WALL)
			   /* draw a wall */
			++x;
		}
		++y;
	   }

=================================================================
=== QUESTION 5 ==================================================
=== When will I add/remove a square from the window ? ===========
=================================================================

* Snake direction has been set;
* Snake know the position of his head (attributs x and y);

So Snake will try to move to a new position but he needs to check what is
on this future position :
    - if NOTHING = remove a BODY from his tail and move his HEAD
    - if FOOD = just move his HEAD (you can _snake_size++ too)
    - if BODY/WALL = then he is done...

NB : moving his HEAD includes to add HEAD to his new position and add BODY to
   his old position then modify his attributs x and y (Snake HEAD position)