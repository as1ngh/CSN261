import sys
import pickle
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import numpy as np
from fibheap import Node, Fheap


if len(sys.argv) < 2:
	print(f'Usage : python3 {sys.argv[0]} inputFileName')
	exit(0)

with open(sys.argv[1],'rb') as f:
	maze = pickle.load(f)

n = len(maze)
m = len(maze[0])

def out_format(points):
	res = ""
	for point in points:
		res += str(point) + "->"

	res = res[:(-1)*len("->")]
	return res



print('''
Heuristic For A* Algorithm:
1:Manhattan Distance
2:Diagonal Distance
3:Euclidean Distance
''')

opt = input()[0]

if opt == '1':
	pass
elif opt == '2':
	pass
elif opt == '3':
	pass
else:
	print("ERROR:)")
	exit(0)

def check(point):
    if point[0] >= 0 and point[0] < m and point[1] >= 0 and point[1] < n:
        if maze[point[1]][point[0]] == 1:
            return True
    return False

src = input("Enter source coordinates: ")
src = src.split('-')
src = (int(src[0]),int(src[1]))

if check(src) != True:
	print("ERROR")

dest = input("Enter destination coordinates separated by a space : ")
dest = dest.split('-')
dest = (int(dest[0]),int(dest[1]))

if check(dest) != True:
	print("Invalid point for destination")

infinity = 2**32 - 1




def get_adjacency(node):
    adj = []
    x = node.x
    y = node.y

    if check(((x,y+1))):
        adj.append(((x,y+1)))
    if check(((x,y-1))):
        adj.append(((x,y-1)))

    if check(((x+1,y))):
        adj.append(((x+1,y)))
    if check(((x+1,y+1))):
        adj.append(((x+1,y+1)))
    if check(((x+1,y-1))):
        adj.append(((x+1,y-1)))

    
    if check(((x-1,y))):
        adj.append(((x-1,y)))
    if check(((x-1,y+1))):
        adj.append(((x-1,y+1)))
    if check(((x-1,y-1))):
        adj.append(((x-1,y-1)))

    return adj

queue = Fheap()

node_dict = {}

for y in range(n):
	for x in range(m):
		if y == src[1] and x == src[0]:
			node = Node(dest[1],dest[0],x,y,0,opt)
			node.val = 0
			queue.insert(node)
			node_dict.update({(x,y):node})

		elif maze[y][x] != 0:
			node = Node(dest[1],dest[0],x,y,infinity,opt)
			queue.insert(node)
			node_dict.update({(x,y):node})

is_visited = [[False for x in range(m)] for y in range(n)]

while True:
	node = queue.extract_min()
	is_visited[node.y][node.x] = True
	if node == node_dict[(m-1,n-1)]:
		break

	adj = get_adjacency(node)

	for point in adj:
		if is_visited[point[1]][point[0]]:
			continue

		p = node_dict[point]
		if node.val + 1 < p.val:
			p.parent = node
			p.val = node.val + 1
			queue.decrease_key(p, p.val + p.distance)

arr = []
node = node_dict[dest]
while True:
	if node == None:
		break
	arr.append(node)
	node = node.parent

arr.reverse()
print("Steps : {}".format(len(arr)-1))
print(out_format(arr))

maze[src[1]][src[0]] = 0.25
maze[dest[1]][dest[0]] = 0.75
arr = arr[1:-1]
for p in arr:
	maze[p.y][p.x] = 0.5

colors = [(0,"black"),(0.25,"green"),(0.5,"blue"),(0.75,"red"),(1,"white")]
mycmap = mcolors.LinearSegmentedColormap.from_list("my_colormap", colors)



plt.imshow(maze, cmap = mycmap)

ax = plt.gca();

# Major ticks
ax.set_xticks(np.arange(0, m, 1));
ax.set_yticks(np.arange(0, n, 1));

# Labels for major ticks
ax.set_xticklabels(np.arange(0, m, 1));
ax.set_yticklabels(np.arange(0, n, 1));

# Minor ticks
ax.set_xticks(np.arange(-0.5, m, 1), minor=True);
ax.set_yticks(np.arange(-0.5, n, 1), minor=True);

# Gridlines based on minor ticks
ax.grid(which='minor', color='grey', linestyle='-', linewidth=2)
ax.invert_yaxis()
plt.show()
