import sys
import networkx

if len(sys.argv) < 2:
	exit(0)

grp = networkx.read_gpickle(sys.argv[1])

st = []
vis = {}
for node in grp.nodes:
	vis.update({node:False})

def check(val):
	if vis[val] == False:
		vis.update({val:True})
		st.append(val)
		for neighbour in grp.adj[val]:
			if check(neighbour):
				return True
		st.pop()

	else:
		if val in st:
			return True
	
	return False

for node in grp.nodes:
	if check(node):
		print("The given input is a not a DAG")
		exit(0)

st = []
vis = {}
for node in grp.nodes:
	vis.update({node:False})

def topological_sort(val):
	if vis[val] == True:
		return
	else:
		vis.update({val:True})
		for neighbour in grp.adj[val]:
				topological_sort(neighbour)
		st.append(val)

for node in grp.nodes:
	topological_sort(node)

output = ""
while st:
	output += str(st.pop()) + ","

output = output[:-1]
print(f"Topological Sorting :\n{output}")