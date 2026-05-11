#include "campus_nav.h"

// 5. 找路径功能实现：队列BFS找最短路径，栈回溯路径
vector<Point> CampusNav::findShortestPath(int startId, int endId) {
    vector<Point> path;
    // 合法性校验
    if (!pointMap.count(startId) || !pointMap.count(endId)) {
        cout << "[错误] 起点或终点不存在" << endl;
        return path;
    }
    if (startId == endId) {
        path.push_back(pointMap[startId]);
        cout << "[提示] 起点与终点相同" << endl;
        return path;
    }

    queue<int> bfsQueue;
    unordered_map<int, int> preMap; // 前驱节点映射，用于回溯
    unordered_map<int, bool> visited;
    bool findFlag = false;

    // BFS初始化
    bfsQueue.push(startId);
    visited[startId] = true;
    preMap[startId] = -1;

    // BFS核心逻辑
    while (!bfsQueue.empty()) {
        int curId = bfsQueue.front();
        bfsQueue.pop();

        for (int adjId : pointMap[curId].adj) {
            if (!visited[adjId]) {
                visited[adjId] = true;
                preMap[adjId] = curId;
                bfsQueue.push(adjId);

                if (adjId == endId) {
                    findFlag = true;
                    break;
                }
            }
        }
        if (findFlag) break;
    }

    if (!findFlag) {
        cout << "[错误] 起点到终点无可用路径" << endl;
        return path;
    }

    // 栈回溯路径
    stack<int> pathStack;
    int cur = endId;
    while (cur != -1) {
        pathStack.push(cur);
        cur = preMap[cur];
    }

    // 生成正序路径
    while (!pathStack.empty()) {
        path.push_back(pointMap[pathStack.top()]);
        pathStack.pop();
    }

    // 输出路径
    cout << "[成功] 找到最短路径：";
    for (int i = 0; i < path.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << path[i].name;
    }
    cout << endl;

    return path;
}