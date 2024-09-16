# lem_in

Each ant may move one room per turn

Only one ant may occupy a room at a time except for start and end

Minimize the number of turns required to move all ants from start to end

## lem-in
 
### Algorithm
using [Edmonds-Karp](https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm) algorithm for managing the flow,  breadth-first search ([BFS](https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/#:~:text=BFS%20is%20a%20traversing%20algorithm,the%20next%2Dlevel%20neighbour%20nodes.)) for getting the shortest path and reconstructed a list of potential paths based on the residual graph

### Dependencies
make

### Installation
```make```<br/>
This will create the lem-in executable

### Usage
```./lem-in < maps/bouchon```

## Matplotlib Visualizer
 

Built with python3

### Dependencies:
[NetworkX](https://networkx.org/)<br/>
[matplotlib](https://matplotlib.org/)

Read from stdin:<br/>
```./lem-in < test_maps/gen-flow-thousand-00 | python3 visualisator/draw_graph.py```

![plot](https://github.com/ahel-men/lem_in/blob/main/screenshots/Screen%20Shot%202020-12-25%20at%2010.31.18%20AM.png)
Other projects will be published soon.
