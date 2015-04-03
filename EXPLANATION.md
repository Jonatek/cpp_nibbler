//
// EXPLANATION.md
// version 2.0
//

=== How the program works ? ===

Basically :
    Nibbler -> Game -> Event/Snake/Map -> IGui

    -> Nibbler initialize our program (you can add more details)

    -> Game is our main class for our program
    -> Game modifies the Snake direction when modifying Event (move Event to
       Snake ?)
    -> Snake direction is now set, Snake will try to move to a new position
       but he needs to check what is on this future position :
       	   - if NOTHING = remove a BODY from his tail and move his HEAD
	   - if FOOD = just move his HEAD (you can _snake_size++ too)
	   - if BODY/WALL = then he is done...

=== Why don't we need to know where each position (x, y) is ? ===

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

=== How can I display the Map ? ===

Since we know caseX and caseY (maximums for X and Y), we simply use a loop in
another loop where we will increment int x and int y then call the function
getObject(x, y) of Map.

     while (y < caseY)
     	   {
		while (x < caseX)
		{
			/* something */
			++x;
		}
		++y;
	   }
