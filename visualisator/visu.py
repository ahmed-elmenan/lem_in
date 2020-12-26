import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict
import numpy as np
from matplotlib import animation
from ant_class import ants
import fileinput

rgbColors = [
    'maroon',
    'red',
    'salmon',
    'orange',
    'gold',
    'peru',
    'blue',
    'green',
    'cyan',
    'navy',
    'purple',
    'violet',
    'chocolate',
]
w = 0
finded = False

def detect_none(item):
    global finded
    if (item == ''):
        finded = True
    return True

lines = []
for line in fileinput.input():
    if 'ERROR' in line:
        exit(); 
    lines.append(line.rstrip())

# storing start and end
for i in range(len(lines)):
    if '##start' in lines[i]:
        start = lines[i + 1].split(' ')
    elif '##end' in lines[i]:
        end = lines[i + 1].split(' ')

# ignoring cmd and comment
lines = [item for item in lines if '#' not in item]

# storing ants number
antsNumber = lines.pop(0)

# storing verteces
verteces = [item.split(' ')
            for item in lines if '-' not in item and item != '']

# storing edges

relations = [item.split('-') for item in lines if (finded ==
                                                   False and detect_none(item) and '-' in item)]

# storing paths
lst = []
tab = []
l = 10000
flag = False
for i in lines:
    if (i == '' or flag):
        lst.append(i.split(' '))
        flag = True
lst.pop(0)

g = nx.Graph()
fig = plt.figure(1, figsize=(40, 40))


for vertex in verteces:
    g.add_node(vertex[0], pos=(int(vertex[1]), int(vertex[2])))

for item in relations:
    g.add_edge(item[0], item[1], color='black', weight=3)

# create ant's map:
diffuseNumber = len(lst[0])
arr = [[]for i in range(l)]

antsPath = defaultdict(list)
for item in lst:
    for ant in item:
        vertex = ant.split('-')[1]
        antNb = int(ant[1:ant.index('-')])
        antsPath[antNb].append(vertex)

# coloring paths
# remove deplicates paths
result = {}
tab = [[]for i in range(l)]
for key, value in antsPath.items():
    if value not in result.values():
        result[key] = value
    result[key].insert(0, start[0])
for key in result:
    color = rgbColors[w % len(rgbColors)]
    for i in range(len(result[key])):
        if (i >= len(result[key]) - 1):
            break
        g.add_edge(result[key][i], result[key][i + 1], color=color, weight=3)
    w += 1
color_map = []
for vertex in g:
    if vertex == start[0] or vertex == end[0]:
        color_map.append('green')
    else:
        color_map.append('blue')

colors = nx.get_edge_attributes(g, 'color').values()
weights = nx.get_edge_attributes(g, 'weight').values()
pos = nx.get_node_attributes(g, 'pos')
plt.close('all')
fig_animate, ax = plt.subplots(figsize=(20,15))

pathCoordPerAnts = [[]for i in range(len(result))]
i = 0
for key in result:
    for item in result[key]:
        for y in range(len(verteces)):
            if (verteces[y][0] == item):
                pathCoordPerAnts[i].append([verteces[y][1], verteces[y][2]])
    i += 1
starting = pathCoordPerAnts[0]

# Animation
i = 0
for i in range(diffuseNumber):
    tab[i] = ants(pathCoordPerAnts, fig_animate, i, np.linspace(int(starting[0][0]), int(
        starting[1][0]), 100), np.linspace(int(starting[0][1]), int(starting[1][1]), 100), end)
    arr[i] = tab[i].animate_ant(10)
    i += 1
 
nx.draw(g,
        pos,
        node_color=color_map,
        edge_color=colors,
        width=list(weights),
        with_labels=True,
        node_size=[900]
    )
plt.show()
