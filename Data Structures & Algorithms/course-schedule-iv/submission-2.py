class CourseNode:
    def __init__(self, val):
        self.id = val
        self.children = []

    def add(self, val):
        self.children.append(val)

class Solution:
    def checkIfPrerequisite(
        self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]
    ) -> List[bool]:

        courses = [CourseNode(i) for i in range(numCourses)]
        ans = []
        for takethis, forthis in prerequisites:
            courses[forthis].add(courses[takethis])

        visited = set()
        preq = [set() for _ in range(numCourses)]

        def dfs(course):
            if course.id in visited:
                return
            
            for child in course.children:
                preq[course.id].add(child.id)
                dfs(child)
                for dep in preq[child.id]:
                    preq[course.id].add(dep)
            
            visited.add(course.id)


        for c in courses:
            dfs(c)
        
        for u,v in queries:
            ans.append(u in preq[v])
        
        return ans
                
                  

            
            
        
    
