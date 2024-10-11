class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and compute indegree of each node
        for (auto& prereq : prerequisites) {
            int u = prereq[1]; // Course to be completed first
            int v = prereq[0]; // Course depending on the previous course
            graph[u].push_back(v);
            indegree[v]++;
        }

        // Initialize queue with all courses having no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        // Kahn's algorithm for topological sorting (BFS)
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the number of courses in the order is less than numCourses, a
        // cycle exists
        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};