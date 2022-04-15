import cgi
from re import S


class Node():
	def __init__(self, parent=None, position=None):
		self.parent = parent
		self.position = position
		
		self.g = 0
		self.h = 0
		self.f = 0

	def __eq__(self,other):
		return self.position == other.position


def astar(map, start, end):
	start_node = Node(None, start)
	start_node.g = start_node.h = start_node.f = 0
	end_node = Node(None, end)
	end_node.g = end_node.h = end_node.f = 0

	open_list = []
	closed_list = []

	open_list.append(start_node)

	while len(open_list) > 0 :         # 오픈리스트에 노드가 없으면 종료
		current_node = open_list[0]
		current_index = 0
		# 오픈리스트중 최소비용 f 노드 탐색
		for index, item in enumerate(open_list):
			if item.f < current_node.f:
				current_node = item
				current_index = index
				
		open_list.pop(current_index) 
		closed_list.pop(current_node)

		if current_node == end_node: # 도착노드까지 탐색 완료
			path = []
			current = current_node
			while current is not None:
				path.append(current.position)
				current = current.parent
			return path[::-1] # 역순출력

		children = []
		for new_position in [(0,-1), (0,1), (-1,0), (1,0),]:
			node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])

			if node_position[0] > (len(map) - 1) or node_position[0] < 0 or node_position[1] > (len(map[len(map) - 1]) - 1) or node_position[1] < 0:
				continue

			if map[node_position[0]][node_position[1]] == 1: #이동될 지점이벽
				continue 
			elif node_position[1] == start[1] - 1 and current_node.position == start_node.position:
				continue

			new_node = Node(current_node, node_position)
			children.append(new_node)

		for child in children:
			check = False
			for closed_child in closed_list:
				if child == closed_child:
					check = True

			if check == False:
				child.g = current_node.g + 1 
				child.h = ((child.position[0]- end_node.position[1]) ** 2) + ((child.position[1] - end_node.position[0]) ** 2)
				child.f = child.g + child.h

				open_list.append(child)

	def main(map, start, end):
		path = astar(map, start, end)
		return path

