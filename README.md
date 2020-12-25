# lem_in
_________________ 

Each ant may move one room per turn

Only one ant may occupy a room at a time except for start and end

Minimize the number of turns required to move all ants from start to end

## lem-in
_________________ 
### Algorithm
I used an [Edmonds-Karp](https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm) like breadth-first search ([BFS](https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/#:~:text=BFS%20is%20a%20traversing%20algorithm,the%20next%2Dlevel%20neighbour%20nodes.)) and reconstructed a list of potential paths based on the residual graph

### Dependencies
make

### Installation
`make`
This will create the lem-in executable

### Usage
`./lem-in < maps/bouchon`

## Matplotlib Visualizer
_________________ 

Built with python3

### Dependencies:
[NetworkX](https://networkx.org/)
[matplotlib](https://matplotlib.org/)

Read from stdin:
`./lem-in < test_maps/gen-flow-thousand-00 | python3 draw_graph.py`
