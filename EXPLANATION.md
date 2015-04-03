=== How the program works ? ===

Basically : Nibbler -> Game -> Map/Snake/IGui (not very important)

=== Why don't we need to know where each position (x, y) is ? ===

Here is a simple Map (3, 3) and his corresponding case
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