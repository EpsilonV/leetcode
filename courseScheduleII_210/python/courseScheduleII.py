class Solution:
	def findOrder(self, numCourses, prerequisites):
		edges = collections.defaultdict(list)
		visited = [0 for i in range(numCourses)]
		result = list()
		invalid = False

		for node in prerequisites:
			edges[node[1]].aapend(edges[0])

		def dfs(u):
			nonlocal invalid
			if invalid:
				return
			visited[u] = 1
			for v in edges[u]:
				if visited[v] == 0:
					dfs(v)
					if invalid:
						return
				elif visited[v] == 1:
					invalid = True
					return

			visited[u] = 2
			result.append(u)

		for i in range(numCourses):
			if not invalid and not visited[i]:
				dfs(i)

		if invalid:
			return []

		return result[::-1]